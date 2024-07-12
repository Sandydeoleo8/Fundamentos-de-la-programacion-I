using System;
using System.Drawing;
using System.Reflection.Emit;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace loteria
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            CrearBotones();
        }

        private void CrearBotones()
        {
            // Crear botón para "normal_desig"
            Button button1 = new Button();
            button1.Text = "Normal Desig";
            button1.Location = new Point(20, 20); // Ajustar la ubicación según tus necesidades
            button1.Click += new EventHandler(button1_Click);
            this.Controls.Add(button1);

            // Crear botón para "Pale"
            Button button2 = new Button();
            button2.Text = "Pale";
            button2.Location = new Point(20, 60); // Ajustar la ubicación según tus necesidades
            button2.Click += new EventHandler(button2_Click);
            this.Controls.Add(button2);

            // Crear botón para salir
            Button button3 = new Button();
            button3.Text = "Salir";
            button3.Location = new Point(20, 100); // Ajustar la ubicación según tus necesidades
            button3.Click += new EventHandler(button3_Click);
            this.Controls.Add(button3);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            normal_desig form2 = new normal_desig();
            form2.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Pale form3 = new Pale();
            form3.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e) => Application.Exit();

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void InitializeComponent()
        {
            this.SuspendLayout();
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(404, 335);
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load_1);
            this.ResumeLayout(false);

        }

        private void Form1_Load_1(object sender, EventArgs e)
        {

        }
    }
}

using System;
using System.Windows.Forms;
using LiteDB;

namespace loteria
{
    public partial class normal_desig : Form
    {
        private int[] numerosAlazar;
        public normal_desig()
        {
            InitializeComponent();
            numerosAlazar = new int[3];
            CrearBotones();
        }

        private void CrearBotones()
        {
            // Crear botón de acción
            Button button1 = new Button();
            button1.Text = "Generar Números";
            button1.Location = new Point(20, 20); // Ajustar la ubicación según tus necesidades
            button1.Click += new EventHandler(button1_Click);
            this.Controls.Add(button1);

            // Crear botón para regresar al formulario principal
            Button button2 = new Button();
            button2.Text = "Regresar";
            button2.Location = new Point(20, 60); // Ajustar la ubicación según tus necesidades
            button2.Click += new EventHandler(button2_Click);
            this.Controls.Add(button2);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int num = Convert.ToInt32(textBox1.Text);
            int dinero = Convert.ToInt32(textBox2.Text);
            if (num > 40)
            {
                MessageBox.Show("Recordar que estos son números entre 0 y 40.");
                return;
            }

            Random rnd = new Random();
            for (int i = 0; i < 3; i++)
            {
                numerosAlazar[i] = rnd.Next(0, 41);
            }

            textBox2.Clear();
            BD_Program();

            label8.Text = $"{numerosAlazar[0]} - {numerosAlazar[1]} - {numerosAlazar[2]}";

            if (num == numerosAlazar[0])
            {
                dinero *= 15;
            }
            else if (num == numerosAlazar[1])
            {
                dinero *= 3;
            }
            else if (num == numerosAlazar[2])
            {
                dinero *= 1;
            }
            else
            {
                label6.Visible = true;
                return;
            }

            label5.Text = $"{dinero}$RD";
            label4.Visible = true;
            label5.Visible = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
            this.Hide();
        }

        private void BD_Program()
        {
            using (var db = new LiteDatabase(@"C:\Users\Velaz\Documents\liteDB\Program.Loteria.db"))
            {
                var col = db.GetCollection<NLotery>("NLotery");
                var L_Normal = new NLotery
                {
                    Fecha = DateTime.Now,
                    Primera = numerosAlazar[0],
                    Segunda = numerosAlazar[1],
                    Tercera = numerosAlazar[2]
                };
                col.Insert(L_Normal);
                col.EnsureIndex(x => x.Fecha);
            }
        }

        private class NLotery
        {
            public int Id { get; set; }
            public DateTime Fecha { get; set; }
            public int Primera { get; set; }
            public int Segunda { get; set; }
            public int Tercera { get; set; }
        }
    }
}

using System;
using System.Windows.Forms;
using LiteDB;

namespace loteria
{
    public partial class Pale : Form
    {
        private int[] numerosAlazar;

        public Pale()
        {
            InitializeComponent();
            numerosAlazar = new int[3];
            CrearBotones();
        }

        private void CrearBotones()
        {
            // Crear botón de acción
            Button button1 = new Button();
            button1.Text = "Generar Números";
            button1.Location = new Point(20, 20); // Ajustar la ubicación según tus necesidades
            button1.Click += new EventHandler(button1_Click);
            this.Controls.Add(button1);

            // Crear botón para regresar al formulario principal
            Button button2 = new Button();
            button2.Text = "Regresar";
            button2.Location = new Point(20, 60); // Ajustar la ubicación según tus necesidades
            button2.Click += new EventHandler(button2_Click);
            this.Controls.Add(button2);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int num1 = Convert.ToInt32(textBox1.Text);
            int num2 = Convert.ToInt32(textBox3.Text);
            int dinero = Convert.ToInt32(textBox2.Text);

            if (dinero < 10)
            {
                MessageBox.Show("El mínimo para participar es de 10 $RD ");
                MessageBox.Show("Completar nuevamente los campos ");
                return;
            }

            Random rnd = new Random();
            for (int i = 0; i < 3; i++)
            {
                numerosAlazar[i] = rnd.Next(0, 41);
            }

            MessageBox.Show($"Números premiados: {numerosAlazar[0]}, {numerosAlazar[1]}, {numerosAlazar[2]}");
            label9.Text = $"{numerosAlazar[0]} - {numerosAlazar[1]} - {numerosAlazar[2]}";

            textBox2.Clear();
            BD_Program();

            if (num1 == numerosAlazar[0] && num2 == numerosAlazar[1])
            {
                dinero *= 1000;
            }
            else if (num1 == numerosAlazar[0] && num2 == numerosAlazar[2])
            {
                dinero *= 100;
            }
            else if (num1 == numerosAlazar[1] && num2 == numerosAlazar[2])
            {
                dinero *= 10;
            }
            else
            {
                label6.Visible = true;
                return;
            }

            label5.Text = $"{dinero}$RD";
            label4.Visible = true;
            label5.Visible = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
            this.Hide();
        }

        private void BD_Program()
        {
            using (var db = new LiteDatabase(@"C:\Users\Velaz\Documents\liteDB\Pale.db"))
            {
                var col = db.GetCollection<NLotery>("NLotery");
                var L_Normal = new NLotery
                {
                    Fecha = DateTime.Now,
                    Primera = numerosAlazar[0],
                    Segunda = numerosAlazar[1],
                    Tercera = numerosAlazar[2]
                };
                col.Insert(L_Normal);
                col.EnsureIndex(x => x.Fecha);
            }
        }

        private class NLotery
        {
            public int Id { get; set; }
            public DateTime Fecha { get; set; }
            public int Primera { get; set; }
            public int Segunda { get; set; }
            public int Tercera { get; set; }
        }
    }
}