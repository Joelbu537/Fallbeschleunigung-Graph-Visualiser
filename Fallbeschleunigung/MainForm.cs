using System.Diagnostics;
using System.Globalization;

namespace Fallbeschleunigung
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, EventArgs e)
        {
            float interval = 1;
            float height = 25;
            float velocity = 0;
            float acceleration = 9.81f;
            try
            {
                interval = float.Parse(textBoxInterval.Text);
                height = float.Parse(textBoxHeight.Text); 
                velocity = float.Parse(textBoxVelocity.Text);
                acceleration = float.Parse(textBoxAcceleration.Text);
                if (interval <= 0)
                {
                    throw new Exception();
                }
            }
            catch
            {
                MessageBox.Show("Bitte gültige Werte eingeben.", "Fehler", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Process p = new Process();
            p.StartInfo.FileName = "Fallbeschleunigung Viewer.exe";
            p.StartInfo.Arguments = string.Format(CultureInfo.InvariantCulture,
                "{0} {1} {2} {3}",
                interval, height, velocity, acceleration);
            File.WriteAllText("debug.txt", "Args: " + p.StartInfo.Arguments);
            p.Start();
        }
    }
}
