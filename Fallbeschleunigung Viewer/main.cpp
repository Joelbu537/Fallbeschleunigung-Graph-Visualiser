#include <SFML/Graphics.hpp>
#include <random>
#include <cmath>
#include <iostream>

int xSpan = 0;
int ySpan = 0;

sf::Vertex* fillDecoX(float graphMargin, float xInterval, float sizeY, int decoLength) {
	sf::Vertex* vertexArray = new sf::Vertex[18];
    for (int i = 0; i < 9; i++)
    {
        vertexArray[i * 2 + 0] = sf::Vertex{ { graphMargin + xInterval * (i + 1), sizeY - graphMargin - decoLength }, sf::Color::White, { 0.f, 0.f } };
        vertexArray[i * 2 + 1] = sf::Vertex{ { graphMargin + xInterval * (i + 1), sizeY - graphMargin + decoLength }, sf::Color::White, { 0.f, 0.f } };
    }
	return vertexArray;
}
sf::Vertex* fillDecoY(float graphMargin, float yInterval, float sizeY, int decoLength) {
    sf::Vertex* vertexArray = new sf::Vertex[18];
    for (int i = 0; i < 9; i++)
    {
        vertexArray[i * 2 + 0] = sf::Vertex{ { graphMargin - decoLength, graphMargin + yInterval * (i + 1)}, sf::Color::White, { 0.f, 0.f } };
        vertexArray[i * 2 + 1] = sf::Vertex{ { graphMargin + decoLength, graphMargin + yInterval * (i + 1)}, sf::Color::White, { 0.f, 0.f } };
    }
    return vertexArray;
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
    {
		std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 5) {
        std::cout << "Ungültige Parameteranzahl!" << std::endl;
        return -1;
    }
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Fallbeschleunigung", sf::Style::None);
    window.setVerticalSyncEnabled(true);

    sf::Vector2u size = window.getSize();
    std::cout << "Size X: " << size.x << std::endl << "Size Y: " << size.y << std::endl;

	float graphMargin = std::round(size.x / 50.f / 10) * 10; // Runden um Kommazahlen für die Größe der Fläche im Graphen zu vermeiden
	constexpr int arrowSize = 20;
	constexpr int decoLength = 20;
    sf::Vertex lineX[] =
    {
        { { graphMargin - graphMargin / 3, size.y - graphMargin }, sf::Color::White, { 0.f,  0.f } },
        { { size.x - graphMargin,   size.y - graphMargin}, sf::Color::White, { 0.f,  0.f } },
        { { size.x - graphMargin - arrowSize * 2, size.y - graphMargin - arrowSize}, sf::Color::White, { 0.f, 0.f } },
		{ { size.x - graphMargin - arrowSize * 2, size.y - graphMargin + arrowSize}, sf::Color::White, { 0.f, 0.f } },
        { { size.x - graphMargin, size.y - graphMargin}, sf::Color::White, { 0.f,  0.f } }
    };
    sf::Vertex lineY[] =
    {
        { { graphMargin, size.y + graphMargin / 3 - graphMargin }, sf::Color::White, { 0.0f,  0.0f } },
        { { graphMargin, graphMargin }, sf::Color::White, { 0.0f,  0.0f } },
		{ { graphMargin - arrowSize, graphMargin + arrowSize * 2}, sf::Color::White, { 0.0f,  0.0f } },
        { { graphMargin + arrowSize, graphMargin + arrowSize * 2}, sf::Color::White, { 0.0f,  0.0f } },
        { { graphMargin, graphMargin }, sf::Color::White, { 0.0f,  0.0f } }
    };

    xSpan = size.x - 2 * graphMargin;
	ySpan = size.y - 2 * graphMargin;
	std::cout << "xSpan: " << xSpan << std::endl << "ySpan: " << ySpan << std::endl;
    float xInterval = xSpan / 10;
	float yInterval = ySpan / 10;

	sf::Vertex* lineXdeco = fillDecoX(graphMargin, xInterval, size.y, decoLength);
	sf::Vertex* lineYdeco = fillDecoY(graphMargin, yInterval, size.y, decoLength);

    window.draw(lineX, 5, sf::PrimitiveType::LineStrip);
    window.draw(lineY, 5, sf::PrimitiveType::LineStrip);
    window.draw(lineXdeco, 18, sf::PrimitiveType::Lines);
    window.draw(lineYdeco, 18, sf::PrimitiveType::Lines);
    window.display();

	float interval = std::stof(argv[1]);
	float height = std::stof(argv[2]);
	float velocity = std::stof(argv[3]);
	float gravity = std::stof(argv[4]);
	std::cout << "Intervall: " << interval << ", Hoehe: " << height << ", Anfangsgeschwindigkeit: " << velocity << ", Fallbeschleunigung: " << gravity << std::endl;

    std::vector<int> dataY(xSpan);

	dataY[0] = height;
    std::cout << "0 Y: " << height << std::endl;

    for (int i = 1; i < xSpan; i++)
    {
		velocity += gravity * interval;
		height += velocity * interval;
        dataY[i] = height;
		std::cout << i * interval << " Y: " << height << std::endl;
    }

    float min = 0;
    float max = 0;
    if (dataY[0] > dataY[xSpan - 1])
    {
		max = dataY[0];
        min = dataY[xSpan - 1];
    }
    else{
		min = dataY[0];
		max = dataY[xSpan - 1];
    }
	std::cout << std::endl << "Min: " << min << ", Max: " << max << std::endl;

	std::vector<sf::Vertex> graphVertices(xSpan);

    float diff = max - min;

    for (int i = 0; i < xSpan - 1; i++)
    {
        graphVertices[i] = sf::Vertex{ { 

        	graphMargin + i,
        	graphMargin + ySpan - (dataY[i] / diff)},

        	sf::Color::Blue, 
        	{ 0.f, 0.f } };

		std::cout << "Graph Vertex " << i << ": (" << graphVertices[i].position.x << ", " << graphVertices[i].position.y << ")" << std::endl;
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }
        window.clear();
        
        window.draw(graphVertices.data(), xSpan, sf::PrimitiveType::LineStrip);
        window.draw(lineXdeco, 18, sf::PrimitiveType::Lines);
        window.draw(lineYdeco, 18, sf::PrimitiveType::Lines);
		window.draw(lineX, 5, sf::PrimitiveType::LineStrip);
		window.draw(lineY, 5, sf::PrimitiveType::LineStrip);

        window.display();
    }
}