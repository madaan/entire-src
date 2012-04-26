using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
public partial class home : System.Web.UI.Page
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
        if (!IsPostBack)
        {
           Button1_Click(sender, e);
        }
        
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        MultiView1.ActiveViewIndex = 0;
        MultiView2.ActiveViewIndex = 0;
        if (ViewState["getdata"] == null)
        {
            SqlConnection conn = new SqlConnection(constrUDB);
            string query = "select * from usertable  where uname='" + Session["name"].ToString() + "'";
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = query;
            cmd.Connection = conn;
            conn.Open();
            SqlDataReader dr = cmd.ExecuteReader();
            if (dr.HasRows)
            {
                dr.Read();
                lblname.Text = dr["fname"].ToString();
                lblabout.Text = dr["about"].ToString();
                lblun.Text = dr["uname"].ToString();
                lblabtname.Text = (dr["fname"].ToString()).Split(' ')[0];
              
               // Label1.Text = (dr["fname"].ToString()).Split(' ')[0];
                ImageButton1.ImageUrl = dr["picurl"].ToString();
               /*
                Image1.ImageUrl = dr["b1imgurl"].ToString();
                Image2.ImageUrl = dr["b2imgurl"].ToString();
                Image3.ImageUrl = dr["b3imgurl"].ToString();
                Image4.ImageUrl = dr["b4imgurl"].ToString();
                Image5.ImageUrl = dr["b5imgurl"].ToString();
                lblbookname.Text = dr["b1name"].ToString();
                lblbookname0.Text = dr["b2name"].ToString();
                lblbookname1.Text = dr["b3name"].ToString();
                lblbookname2.Text = dr["b4name"].ToString();
                lblbookname3.Text = dr["b5name"].ToString();
                lblbabt.Text = dr["b1abt"].ToString();
                lblbabt0.Text = dr["b2abt"].ToString();
                lblbabt1.Text = dr["b3abt"].ToString();
                lblbabt2.Text = dr["b4abt"].ToString();
                lblbabt3.Text = dr["b5abt"].ToString();*/
                dr.Close();
                //make connection only if required
                SqlConnection conn1 = new SqlConnection(constrBDB);
                cmd.Connection = conn1;
                cmd.CommandText = "select * from bookrecord  where uname='" + Session["name"].ToString() + "'";
                conn1.Open(); 
                SqlDataReader dr1 = cmd.ExecuteReader();
                GridView3.DataSource = dr1;
                GridView3.DataBind();
                conn1.Close();
               }
            else
            {
                lblname.Text = "NO RECORD FOUND!";
                lblabout.Text = Session["name"].ToString();
            }
            conn.Close();
            ViewState["getdata"] = "I Have Done It Already";
        }
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        MultiView1.ActiveViewIndex = 1;
        MultiView2.ActiveViewIndex = -1;
       
    }
    protected void Button5_Click(object sender, EventArgs e)
    {
        MultiView1.ActiveViewIndex = 2;
        MultiView2.ActiveViewIndex = -1;
        SqlConnection conn = new SqlConnection(constrBDB);
        string query = "select bname from bookrecord  where uname='" + Session["name"].ToString() + "' and u1 is not null";
        SqlCommand cmd = new SqlCommand();
        cmd.CommandText = query;
        cmd.Connection = conn;
        conn.Open();
        SqlDataReader dr = cmd.ExecuteReader();
        GridView1.DataSource = dr;
        GridView1.DataBind();
        string un = Session["name"].ToString();
        cmd.CommandText = " select bname from bookrecord  where u1='" + un + "' or u2='" + un + "' or u3='" + un + "' or u4='" + un + "' or u5='" + un+"'";
        dr.Close();
        dr = cmd.ExecuteReader();
        GridView2.DataSource = dr;
        GridView2.DataBind();
    }
    protected void Button4_Click(object sender, EventArgs e)
    {
        Session["name"] = null;
        Response.Redirect("login.aspx");
    }
    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        Response.Redirect("reconfigure.aspx");
    }
}