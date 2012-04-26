//sg
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
public partial class bookstatus : System.Web.UI.Page
{
    string constrUDB = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|UsersDatabase.mdf;Integrated Security=True;User Instance=True";
    string constr = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|LoginDatabase.mdf;Integrated Security=True;User Instance=True";
    string constrBDB = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|BooksDatabase.mdf;Integrated Security=True;User Instance=True";

    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["name"] == null)
        {
            Response.Redirect("login.aspx");
        }
        string uname = Request.QueryString["name"].ToString();
        string bname = Request.QueryString["bname"].ToString();
        int count = 0;
        SqlConnection conn = new SqlConnection(constrBDB);
        string query = "select * from bookrecord where uname='" + uname + "' and bname='" + bname+"'";
        SqlCommand cmd = new SqlCommand();
        cmd.CommandText = query;
        cmd.Connection = conn;
        conn.Open();
        SqlDataReader dr = cmd.ExecuteReader();
        dr.Read();
        imgbook.ImageUrl = dr["picurl"].ToString();

        string queryToUsertable = "";
        if (dr["u1"].ToString()=="")
        {
            imguser1.ImageUrl = "~/images/null.jpg";

            imguser2.ImageUrl = "~/images/null.jpg";

            imguser3.ImageUrl = "~/images/null.jpg";
            imguser4.ImageUrl = "~/images/null.jpg";
            imguser5.ImageUrl = "~/images/null.jpg";


        }

        else if (dr["u2"].ToString() == "")
        {
            queryToUsertable += "'" + dr["u1"].ToString() + "',";

            imguser2.ImageUrl = "~/images/null.jpg";
            imguser3.ImageUrl = "~/images/null.jpg";
            imguser4.ImageUrl = "~/images/null.jpg";
            imguser5.ImageUrl = "~/images/null.jpg";

        }
        else if (dr["u3"].ToString() == "")
        {
            queryToUsertable += "'" + dr["u1"].ToString() + "',";
            queryToUsertable += "'" + dr["u2"].ToString() + "',";

            imguser3.ImageUrl = "~/images/null.jpg";
            imguser4.ImageUrl = "~/images/null.jpg";
            imguser5.ImageUrl = "~/images/null.jpg";

        }
        else if (dr["u4"].ToString() == "")
        {
            queryToUsertable += "'" + dr["u1"].ToString() + "',";
            queryToUsertable += "'" + dr["u2"].ToString() + "',";
            queryToUsertable += "'" + dr["u3"].ToString() + "',";

            imguser4.ImageUrl = "~/images/null.jpg";
            imguser5.ImageUrl = "~/images/null.jpg";

        }
        else if (dr["u5"].ToString() == "")
        {
            queryToUsertable += "'" + dr["u1"].ToString() + "',";
            queryToUsertable += "'" + dr["u2"].ToString() + "',";
            queryToUsertable += "'" + dr["u3"].ToString() + "',";
            queryToUsertable += "'" + dr["u4"].ToString() + "',";

            imguser5.ImageUrl = "~/images/null.jpg";

        }
        else
        {
            queryToUsertable += "'" + dr["u1"].ToString() + "',";
            queryToUsertable += "'" + dr["u2"].ToString() + "',";
            queryToUsertable += "'" + dr["u3"].ToString() + "',";
            queryToUsertable += "'" + dr["u4"].ToString() + "',";
            queryToUsertable += "'" + dr["u5"].ToString() + "',";
        }

        //************
        
        //************
        //###########CONNECTING TO USERINFO FOR USER PICS##############
        SqlConnection conn1 = new SqlConnection(constrUDB);
        string query1 = "select picurl,uname from usertable where uname IN(" + queryToUsertable + "'')";
        SqlCommand cmd1 = new SqlCommand();
        cmd1.CommandText = query1;
        cmd1.Connection = conn1;
        conn1.Open();
        SqlDataReader dr1 = cmd1.ExecuteReader();
        int i = 0;
        while (dr1.Read())
        {
            if (dr["u1"].ToString()==dr1["uname"].ToString())
            {
                imguser1.ImageUrl = dr1["picurl"].ToString();
            }
            else if (dr["u2"].ToString() == dr1["uname"].ToString())
            {
                imguser2.ImageUrl = dr1["picurl"].ToString();
            }
            else if (dr["u3"].ToString() == dr1["uname"].ToString())
            {
                imguser3.ImageUrl = dr1["picurl"].ToString();
            }
            else if (dr["u4"].ToString() == dr1["uname"].ToString())
            {
                imguser4.ImageUrl = dr1["picurl"].ToString();
            }
            else 
            {
                imguser5.ImageUrl = dr1["picurl"].ToString();
            }
            i++;
        }
        conn.Close();
        conn1.Close();


    }
}