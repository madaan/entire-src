//sg
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Media;
public partial class login : System.Web.UI.Page
{
    string constr = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|LoginDatabase.mdf;Integrated Security=True;User Instance=True";
    protected void Page_Load(object sender, EventArgs e)
    {
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        int f = 0;
        SqlConnection conn = new SqlConnection(constr);
        SqlCommand cmd = new SqlCommand();
        cmd.Connection = conn;
        cmd.CommandText = "select * from logininfo where uname='" + txtuname.Text.Trim() + "'";
        conn.Open();
        SqlDataReader dr = cmd.ExecuteReader();
        if (dr.HasRows)
        {
            dr.Read();
            if (dr["password"].ToString() == txtpass.Text)
            {
                f = 1;
                Label1.ForeColor = System.Drawing.Color.Green;
                Label1.Text = "USER NAME IS NOT AVAILABLE";
                Session["name"] = txtuname.Text.Trim();
                if (int.Parse(dr["config"].ToString()) == 0)
                {
                    Response.Redirect("configure.aspx");
                }
                else
                {

                    Response.Redirect("home.aspx");

                }
            }
        }
        if (f == 0)
        {
            Label1.ForeColor = System.Drawing.Color.Red;
            Label1.Text = "<br>LOGIN UNSUCCESSFUL<br>Check Username and Password<br><u>(Password is case sensitive)</u>";

        }
        conn.Close();
    }
    protected void Timer1_Tick(object sender, EventArgs e)
    {
        string[] s = { "~/images/login.jpg", "~/images/login1.jpg", "~/images/login2.jpg", "~/images/login3.png", "~/images/login4.jpg" };
        Random r=new Random();
        Image1.ImageUrl=s[r.Next()%5];
    }
    protected void LinkButton1_Click(object sender, EventArgs e)
    {
        Session["login"] = "sdsd";
        Response.Redirect("RecoverPassword.aspx");
    }
}