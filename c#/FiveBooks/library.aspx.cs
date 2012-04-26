//sg
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
public partial class library : System.Web.UI.Page
{
    string constrUDB = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|UsersDatabase.mdf;Integrated Security=True;User Instance=True";
    string constr = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|LoginDatabase.mdf;Integrated Security=True;User Instance=True";
    string constrBDB = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|BooksDatabase.mdf;Integrated Security=True;User Instance=True";
    int i = 1;
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["name"] == null)
        {
            Response.Redirect("login.aspx");
        }
    if(!IsPostBack)
            BindToGrid(0);
        
    }
    protected void BindToGrid(int op)
    {
        string query = "";
        SqlConnection conn = new SqlConnection(constrBDB);
        switch(op)
        {
            case 0:
            query = "select * from bookrecord";//  where uname='" + Session["name"].ToString() + "'";
            break;
            case 1:
             query = "select * from bookrecord order by uname";
            break;
            case 2:
           query = "select * from bookrecord order by bname";
            break;
            case 3:
            query = "select * from bookrecord order by nrequest";
            break;
            
        }
        SqlCommand cmd = new SqlCommand();
        cmd.CommandText = query;
        cmd.Connection = conn;
        conn.Open();
        SqlDataReader dr = cmd.ExecuteReader();// new SqlDataAdapter(cmd);
       
        GridView1.DataSource = dr;
        GridView1.DataBind();
       }

    protected void GridView1_PageIndexChanging(object sender, GridViewPageEventArgs e)
    {
        GridView1.PageIndex = e.NewPageIndex;
    }
    protected void GridView1_SelectedIndexChanged(object sender, GridViewPageEventArgs e)
    {
        i = GridView1.SelectedIndex;
       }
   
    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        string un = ((HiddenField)(GridView1.Rows[i].Cells[0].FindControl("HiddenField1"))).Value;
        string bn = ((HiddenField)(GridView1.Rows[i].Cells[0].FindControl("HiddenField2"))).Value;
        string url = "bookstatus.aspx?";
        url += "name=" + un + "&bname=" + bn;
        Response.Redirect(url);

    }
    protected void GridView1_SelectedIndexChanging(object sender, GridViewSelectEventArgs e)
    {
        i = e.NewSelectedIndex;
        string un = ((HiddenField)(GridView1.Rows[i].Cells[0].FindControl("HiddenField1"))).Value;
        string bn = ((HiddenField)(GridView1.Rows[i].Cells[0].FindControl("HiddenField2"))).Value;
        string url = "bookstatus.aspx?";
        url += "name=" + un + "&bname=" + bn;
        Response.Redirect(url);

    }
    protected void GridView1_RowCommand(object sender, GridViewCommandEventArgs e)
    {
       // Label3.Text = "HERE!!!!!!!!!!!!!!!!!!!!!";
        if (e.CommandName=="request")
  {
          // Retrieve the row index stored in the 
    // CommandArgument property.
    int index = Convert.ToInt32(e.CommandArgument);

    // Retrieve the row that contains the button 
    // from the Rows collection.
    GridViewRow row = GridView1.Rows[index];
            
    // Add code here to add the item to the shopping cart.
         string un = ((HiddenField)(row.Cells[0].FindControl("HiddenField1"))).Value;
        string bn = ((HiddenField)(row.Cells[0].FindControl("HiddenField2"))).Value;
        SqlConnection conn = new SqlConnection(constrBDB);
        string query = "select * from bookrecord where bname='" + bn + "' and uname='" + un + "'";
        SqlCommand cmd = new SqlCommand();
        cmd.CommandText = query;
        cmd.Connection = conn;
        conn.Open();
        SqlDataReader dr = cmd.ExecuteReader();
        dr.Read();
        
        int user_count = int.Parse(dr["nrequest"].ToString());
        if (user_count == 5)
        {
            Label3.ForeColor = System.Drawing.Color.Red;
            Label3.Text="IT'S FIVEBOOKS<br>a book can be requested by atmost 5 users at a time! <br>Do Check Book Status After next bookmeet";
        }
        else if(dr["uname"].ToString()==Session["name"].ToString())
        {
        Label3.ForeColor = System.Drawing.Color.Red;
            Label3.Text="WHY ON MARS DO YOU WANT TO REQUEST YOUR OWN BOOK?";
        }
        else
        {

            string user=Session["name"].ToString();
            if ((dr["u1"].ToString() == user) || (dr["u2"].ToString() == user) || (dr["u3"].ToString() == user) || (dr["u4"].ToString() == user) || (dr["u5"].ToString() == user))
            {
                Response.Write("YOU HAVE ALREADY REQUESTED THIS BOOK ONCE!");
            }
            else
                user_count++;
                string coltoinput = "u" + user_count.ToString();

                dr.Close();
                cmd.CommandText = "update bookrecord set nrequest=" + user_count + "," + coltoinput + "='" + Session["name"].ToString() + "' where bname='"+bn+"'" ;
                cmd.ExecuteNonQuery();
            }
        
        
        conn.Close();
        BindToGrid(0);
        }}


    protected void Button2_Click(object sender, EventArgs e)
    {
        BindToGrid(1);
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        BindToGrid(2);

    }
    protected void Button4_Click(object sender, EventArgs e)
    {
        BindToGrid(3);
    }
    protected void LinkButton1_Click(object sender, EventArgs e)
    {
        Session["name"] = null;
        Response.Redirect("login.aspx");
    }

}