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

    const sf::Vector2u size = window.getSize();
    std::cout << "Size X: " << size.x << std::endl << "Size Y: " << size.y << std::endl;

    sf::Font font("Consolas.ttf");

	const float graphMargin = std::round(size.x / 50.f / 10) * 10; // Runden um Kommazahlen für die Größe der Fläche im Graphen zu vermeiden
	std::cout << "Graph Margin: " << graphMargin << std::endl;
	constexpr int arrowSize = 20;
	constexpr int decoLength = 20;
    const sf::Vertex lineX[] =
    {
        { { graphMargin, size.y - graphMargin }, sf::Color::White, { 0.f,  0.f } },
        { { size.x - graphMargin,   size.y - graphMargin}, sf::Color::White, { 0.f,  0.f } },
        { { size.x - graphMargin - arrowSize * 2, size.y - graphMargin - arrowSize}, sf::Color::White, { 0.f, 0.f } },
		{ { size.x - graphMargin - arrowSize * 2, size.y - graphMargin + arrowSize}, sf::Color::White, { 0.f, 0.f } },
        { { size.x - graphMargin, size.y - graphMargin}, sf::Color::White, { 0.f,  0.f } }
    };
    const sf::Vertex lineY[] =
    {
        { { graphMargin, size.y - graphMargin }, sf::Color::White, { 0.0f,  0.0f } },
        { { graphMargin, graphMargin }, sf::Color::White, { 0.0f,  0.0f } },
		{ { graphMargin - arrowSize, graphMargin + arrowSize * 2}, sf::Color::White, { 0.0f,  0.0f } },
        { { graphMargin + arrowSize, graphMargin + arrowSize * 2}, sf::Color::White, { 0.0f,  0.0f } },
        { { graphMargin, graphMargin }, sf::Color::White, { 0.0f,  0.0f } }
    };

    xSpan = size.x - 2 * graphMargin;
	ySpan = size.y - 2 * graphMargin;
	std::cout << "xSpan: " << xSpan << std::endl << "ySpan: " << ySpan << std::endl;
    const float xInterval = xSpan / 10;
	const float yInterval = ySpan / 10;

	const sf::Vertex* lineXdeco = fillDecoX(graphMargin, xInterval, size.y, decoLength);
	const sf::Vertex* lineYdeco = fillDecoY(graphMargin, yInterval, size.y, decoLength);

    window.draw(lineX, 5, sf::PrimitiveType::LineStrip);
    window.draw(lineY, 5, sf::PrimitiveType::LineStrip);
    window.draw(lineXdeco, 18, sf::PrimitiveType::Lines);
    window.draw(lineYdeco, 18, sf::PrimitiveType::Lines);
    window.display();

	const float interval = std::stof(argv[1]);
    float height = std::stof(argv[2]);
    float velocity = std::stof(argv[3]);
    float gravity = std::stof(argv[4]);
	std::cout << "Intervall: " << interval << ", Hoehe: " << height << ", Anfangsgeschwindigkeit: " << velocity << ", Fallbeschleunigung: " << gravity << std::endl;

    std::vector<float> dataY(xSpan);

	dataY[0] = height;
    std::cout << "0 Y: " << height << std::endl;

    float max = height;
    float min = 0;

    for (int i = 1; i < xSpan; i++)
    {
		velocity += gravity * interval;
		height += velocity * interval;
        dataY[i] = height;
		std::cout << i * interval << " Y: " << height << std::endl;

        if (height < min)
			min = height;
        else if (height > max)
			max = height;
    }

    const float zPercentage = (1 / ((max - min) / std::abs(min)));
    const float zeroHeight = ySpan + graphMargin - (ySpan * zPercentage);
	std::cout << std::endl << "Zero percentage: " << zPercentage << ", Zero Height: " << zeroHeight << std::endl;

    const sf::Vertex lineZero[] =
    {
        { { graphMargin, zeroHeight }, sf::Color::Red, { 0.f,  0.f } },
        { { size.x - graphMargin, zeroHeight}, sf::Color::Red, { 0.f,  0.f } }
	};
    sf::Text zeroText(font);
    zeroText.setString("0");
    zeroText.setCharacterSize(30);
    zeroText.setFillColor(sf::Color::Red);
    zeroText.setPosition({ graphMargin * 0.5f, zeroHeight });

    sf::Text xText(font);
    xText.setString(std::to_string(xSpan * interval));
    xText.setCharacterSize(30);
    xText.setFillColor(sf::Color::White);
    xText.setPosition({ (float)xSpan - graphMargin * 0.5f, ySpan + (graphMargin * 1.5f) });

    sf::Text yTextMax(font);
    yTextMax.setString(std::to_string(max));
    yTextMax.setCharacterSize(30);
    yTextMax.setFillColor(sf::Color::White);
    yTextMax.setPosition({ graphMargin * 1.5f, graphMargin });

    sf::Text yTextMin(font);
    yTextMin.setString(std::to_string(min));
    yTextMin.setCharacterSize(30);
    yTextMin.setFillColor(sf::Color::White);
    yTextMin.setPosition({ graphMargin * 1.5f, ySpan - graphMargin });

	window.draw(lineZero, 2, sf::PrimitiveType::LineStrip);
	window.draw(zeroText);
	window.draw(xText);
	window.draw(yTextMax);
	window.draw(yTextMin);
	window.display();

	std::vector<sf::Vertex> graphVertices(xSpan);

    std::cout << "xSpan: " << xSpan << ", ySpan: " << ySpan << std::endl;
    std::cout << "Min: " << min << ", Max: " << max << "  Total: " << max - min << std::endl;

    const float scale = ySpan / (std::abs(max) + std::abs(min));
	std::cout << "Scale: " << scale << std::endl << std::endl;

    for (int i = 0; i < xSpan; i++)
    {
        graphVertices[i] = sf::Vertex{ { 

        	graphMargin + i,
        	graphMargin * 1.5f - (dataY[i] * scale)},

        	sf::Color::Green, 
        	{ 0.f, 0.f } };

		std::cout << "Graph Vertex " << i << ": Value: " << dataY[i] << "(" << graphVertices[i].position.x << ", " << graphVertices[i].position.y << ")" << std::endl;
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

        window.clear(sf::Color::Black);

        window.draw(lineXdeco, 18, sf::PrimitiveType::Lines);
        window.draw(lineYdeco, 18, sf::PrimitiveType::Lines);
		window.draw(lineX, 5, sf::PrimitiveType::LineStrip);
		window.draw(lineY, 5, sf::PrimitiveType::LineStrip);
		window.draw(lineZero, 2, sf::PrimitiveType::LineStrip);
        window.draw(graphVertices.data(), xSpan, sf::PrimitiveType::LineStrip);
        window.draw(xText);
        window.draw(yTextMax);
        window.draw(yTextMin);
		window.draw(zeroText);

        window.display();
    }
}