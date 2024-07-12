using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Loteria1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
private void button1_Click(object sender, EventArgs e)
        {

        }            namespace loteria
    {
        public partial class Form1 : Form
        {
            public Form1()
            {
                InitializeComponent();
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

            private void button3_Click(object sender, EventArgs e)
            {
                Application.Exit();
            }
        }
    }
}
    }
}


using System.Reflection.Emit; 
using System.Windows.Forms; 
using static loteria.estandar_desig; 
using LiteDB; 
namespace loteria
{
    public partial class normal_desig : Form
    {
        private int[] numerosAlazar;
        public normal_desig()
        {
        }
        InitializeComponent();
        numerosAzar = new int[3]; 
private void button1_Click(object sender, EventArgs e)
        {
            int num = Convert.ToInt32(textBox1.Text);
            int dinero = Convert.ToInt32(textBox2.Text);
            if (num > 40)
            {
            }
            MessageBox.Show("Recordar que estos son números entre 0 y 40.");
            for (Int32 i = 0; i < 3;)
            {
            }
            Random rnd = new Random();
            numerosAlazar[i] = rnd.Next(0, 41);
            i++;
            textBox2.Clear();
            BD_Program();
            label8.Text = numerosAlazar[0].ToString() + " - " + numerosAlazar[1].ToString() + " - " +
            numerosAleatorios[2].ToString();
            if (num == numerosAlazar[0])
            {
            }
            dinero *= 15;
            label5.Text = dinero.ToString() + "$RD";
            label4.Visible = true;
            label5.Visible = true;
else if (num == numerosAlazar[1])
            {
            }
            dinero *= 3;
            label5.Text = dinero.ToString() + "$RD";
            label4.Visible = true;
            label5.Visible = true;
else if (num == numerosAlazar[2])
            {
                dinero *= 1;
                label5.Text = dinero.ToString() + "$RD";
                label4.Visible = true;
                label5.Visible = true;
            }
            else
            {
            }
        }
        label6.Visible = true; 
private void button2_Click(object sender, EventArgs e)
        {
        }
        Form1 form1 = new Form1();
        form1.Show(); 
this.Hide(); ; 
// Create your POCO class entity 
private class NLotery
        {
        }
        public int Id { get; set; }
        public DateTime Fecha { get; set; }
        public int Primera { get; set; }
        public int Segunda { get; set; }
        public int Tercera { get; set; }
        private void BD_Program()
        {
            // Open database (or create if doesn't exist) 
            using (var db = new
            LiteDatabase(@"C:\Users\Velaz\Documents\liteDB\Program.Loteria.db"))
            {
            }
        }
    }
}
// Get a collection (or create, if doesn't exist) 
var col = db.GetCollection<NLotery>("NLotery");
// Create your new customer instance 
var L_Normal = new NLotery
{
};
Fecha = DateTime.Now, 
Primera = numerosAlazar[0], 
Segunda = numerosAlazar[1], 
Tercera = numerosAlazar[2]
// Insert new customer document (Id will be auto-incremented) 
col.Insert(L_Normal);
col.EnsureIndex(x => x.Fecha);

using LiteDB; 
using System; 
using System.Collections.Generic; 
using System.ComponentModel; 
using System.Data; 
using System.Drawing; 
using System.Linq; 
using System.Text; 
using System.Threading.Tasks; 
using System.Windows.Forms; 
namespace loteria
{
    public partial class Pale : Form
    {
        private int[] numerosAlazar;
        public Pale()
        {
        }
        InitializeComponent();
        numerosAlazar = new int[3]; 
private void button1_Click(object sender, EventArgs e)
        {
            int num1 = Convert.ToInt32(textBox1.Text);
            int num2 = Convert.ToInt32(textBox3.Text);
            int dinero = Convert.ToInt32(textBox2.Text);

            if (dinero < 10)
            {
                num1 = 0;
                num2 = 0;
                dinero = 0;
                MessageBox.Show("El mínimo para participar es de 10 $RD ");
                MessageBox.Show("Completar nuevamente los campos ");
                return;
            }
            for (global::System.Int32 i = 0; i < 3;)
            {
                Random rnd = new Random();
                numerosAlazar[i] = rnd.Next(0, 41);


                MessageBox.Show($"números premiados: {numerosAlazar[i]}");
                i++;
            }
            label9.Text = numerosAlazar[0].ToString() + " - " +
numerosAlazars[1].ToString() + " - " + numerosAlazar[2].ToString();

            textBox2.Clear();

            BD_Program();

            if (num1 == numerosAlazar[0] && num2 == numerosAlazar[1])
            {
                dinero *= 1000;
                label5.Text = dinero.ToString() + "$RD";
                label4.Visible = true;
                label5.Visible = true;
            }
            else if (num1 == numerosAlazar[0] && num2 ==
 numerosAleatorios[2])
            {
                dinero *= 100;
                label5.Text = dinero.ToString() + "$RD";
                label4.Visible = true;
                label5.Visible = true;
            }

            else if (num1 == numerosAlazar[1] && num2 ==
numerosAleatorios[2])
            {
                dinero *= 10;
                label5.Text = dinero.ToString() + "$RD";
                label4.Visible = true;
                label5.Visible = true;
            }
            else
            {
            }
        }
        label6.Visible = true; 
private void button2_Click(object sender, EventArgs e)
        {
        }
        Form1 form1 = new Form1();
        form1.Show(); 
this.Hide(); ; 
// Create your POCO class entity 
private class NLotery
        {
            public int Id { get; set; }
            public DateTime Fecha { get; set; }
            public int Primera { get; set; }
            public int Segunda { get; set; }
            public int Tercera { get; set; }
        }

        private void BD_Program()
        {
            // Open database (or create if doesn't exist) 
            using (var db = new
LiteDatabase(@"C:\Users\Velaz\Documents\liteDB\Pale.db"))
            {
                // Get a collection (or create, if doesn't exist) 
                var col = db.GetCollection<NLotery>("NLotery");

                // Create your new customer instance 
                var L_Normal = new NLotery
                {
                    Fecha = DateTime.Now,
                    Primera = numerosAlazar[0],
                    Segunda = numerosAlazar[1],
                    Tercera = numerosAlazar[2]
                };
                // Insert new customer document (Id will be auto-incremented) 
                col.Insert(L_Normal);
                col.EnsureIndex(x => x.Fecha);


            }
        }
    }
}
PALE: