namespace Fallbeschleunigung
{
    partial class MainForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tableLayoutPanel = new TableLayoutPanel();
            textBoxAcceleration = new TextBox();
            labelAcceleration = new Label();
            textBoxVelocity = new TextBox();
            labelVelocity = new Label();
            textBoxHeight = new TextBox();
            labelHeight = new Label();
            textBoxInterval = new TextBox();
            labelInterval = new Label();
            button = new Button();
            tableLayoutPanel.SuspendLayout();
            SuspendLayout();
            // 
            // tableLayoutPanel
            // 
            tableLayoutPanel.ColumnCount = 2;
            tableLayoutPanel.ColumnStyles.Add(new ColumnStyle());
            tableLayoutPanel.ColumnStyles.Add(new ColumnStyle());
            tableLayoutPanel.Controls.Add(textBoxAcceleration, 1, 3);
            tableLayoutPanel.Controls.Add(labelAcceleration, 0, 3);
            tableLayoutPanel.Controls.Add(textBoxVelocity, 1, 2);
            tableLayoutPanel.Controls.Add(labelVelocity, 0, 2);
            tableLayoutPanel.Controls.Add(textBoxHeight, 1, 1);
            tableLayoutPanel.Controls.Add(labelHeight, 0, 1);
            tableLayoutPanel.Controls.Add(textBoxInterval, 1, 0);
            tableLayoutPanel.Controls.Add(labelInterval, 0, 0);
            tableLayoutPanel.Controls.Add(button, 1, 4);
            tableLayoutPanel.Dock = DockStyle.Fill;
            tableLayoutPanel.Location = new Point(0, 0);
            tableLayoutPanel.Name = "tableLayoutPanel";
            tableLayoutPanel.RowCount = 5;
            tableLayoutPanel.RowStyles.Add(new RowStyle());
            tableLayoutPanel.RowStyles.Add(new RowStyle());
            tableLayoutPanel.RowStyles.Add(new RowStyle());
            tableLayoutPanel.RowStyles.Add(new RowStyle());
            tableLayoutPanel.RowStyles.Add(new RowStyle());
            tableLayoutPanel.Size = new Size(637, 306);
            tableLayoutPanel.TabIndex = 0;
            // 
            // textBoxAcceleration
            // 
            textBoxAcceleration.Location = new Point(392, 174);
            textBoxAcceleration.Name = "textBoxAcceleration";
            textBoxAcceleration.Size = new Size(225, 47);
            textBoxAcceleration.TabIndex = 7;
            textBoxAcceleration.Text = "9,81";
            // 
            // labelAcceleration
            // 
            labelAcceleration.AutoSize = true;
            labelAcceleration.Location = new Point(8, 179);
            labelAcceleration.Margin = new Padding(8);
            labelAcceleration.Name = "labelAcceleration";
            labelAcceleration.Size = new Size(343, 41);
            labelAcceleration.TabIndex = 6;
            labelAcceleration.Text = "Beschleunigung (m/s^2)";
            // 
            // textBoxVelocity
            // 
            textBoxVelocity.Location = new Point(392, 117);
            textBoxVelocity.Name = "textBoxVelocity";
            textBoxVelocity.Size = new Size(225, 47);
            textBoxVelocity.TabIndex = 5;
            textBoxVelocity.Text = "0";
            // 
            // labelVelocity
            // 
            labelVelocity.AutoSize = true;
            labelVelocity.Location = new Point(8, 122);
            labelVelocity.Margin = new Padding(8);
            labelVelocity.Name = "labelVelocity";
            labelVelocity.Size = new Size(370, 41);
            labelVelocity.TabIndex = 4;
            labelVelocity.Text = "Startgeschwindigkeit (m/s)";
            // 
            // textBoxHeight
            // 
            textBoxHeight.Location = new Point(392, 60);
            textBoxHeight.Name = "textBoxHeight";
            textBoxHeight.Size = new Size(225, 47);
            textBoxHeight.TabIndex = 3;
            textBoxHeight.Text = "25";
            // 
            // labelHeight
            // 
            labelHeight.AutoSize = true;
            labelHeight.Location = new Point(8, 65);
            labelHeight.Margin = new Padding(8);
            labelHeight.Name = "labelHeight";
            labelHeight.Size = new Size(198, 41);
            labelHeight.TabIndex = 2;
            labelHeight.Text = "Starthöhe (m)";
            // 
            // textBoxInterval
            // 
            textBoxInterval.Location = new Point(392, 3);
            textBoxInterval.Name = "textBoxInterval";
            textBoxInterval.Size = new Size(225, 47);
            textBoxInterval.TabIndex = 0;
            textBoxInterval.Text = "1";
            // 
            // labelInterval
            // 
            labelInterval.AutoSize = true;
            labelInterval.Location = new Point(8, 8);
            labelInterval.Margin = new Padding(8);
            labelInterval.Name = "labelInterval";
            labelInterval.Size = new Size(373, 41);
            labelInterval.TabIndex = 1;
            labelInterval.Text = "Schrittweite/Pixel/Sekunde";
            // 
            // button
            // 
            button.AutoSize = true;
            button.Location = new Point(399, 238);
            button.Margin = new Padding(10);
            button.Name = "button";
            button.Size = new Size(218, 51);
            button.TabIndex = 8;
            button.Text = "Berechnen";
            button.UseVisualStyleBackColor = true;
            button.Click += button_Click;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(17F, 41F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(637, 306);
            Controls.Add(tableLayoutPanel);
            Margin = new Padding(5, 4, 5, 4);
            MaximizeBox = false;
            Name = "MainForm";
            ShowIcon = false;
            Text = "Fallbeschleunigung Kontrolle";
            tableLayoutPanel.ResumeLayout(false);
            tableLayoutPanel.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private TableLayoutPanel tableLayoutPanel;
        private TextBox textBoxInterval;
        private Label labelInterval;
        private TextBox textBoxHeight;
        private Label labelHeight;
        private TextBox textBoxAcceleration;
        private Label labelAcceleration;
        private TextBox textBoxVelocity;
        private Label labelVelocity;
        private Button button;
    }
}
