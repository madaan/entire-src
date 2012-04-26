using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
public partial class schedule : System.Web.UI.Page
{
    string constrUDB = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|UsersDatabase.mdf;Integrated Security=True;User Instance=True";
    string constr = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|LoginDatabase.mdf;Integrated Security=True;User Instance=True";
    string constrBDB = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|BooksDatabase.mdf;Integrated Security=True;User Instance=True";

    protected void Page_Load(object sender, EventArgs e)
    {
        //0:normal select all
        //1:order by uname
        //2:order by bnmae
        //3:order by nrequest
        if (Session["name"] == null)
        {
            Response.Redirect("login.aspx");
        }
        if (!IsPostBack)
        {
            string query = "select uname,bname,u1 from bookrecord where u1 is not null";
            SqlConnection conn = new SqlConnection(constrBDB);



            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = query;
            cmd.Connection = conn;
            conn.Open();
            SqlDataReader dr = cmd.ExecuteReader();// new SqlDataAdapter(cmd);

            GridView1.DataSource = dr;
            GridView1.DataBind();
        }
    }

    protected void GridView1_RowCommand(object sender, GridViewCommandEventArgs e)
    {
        // Label3.Text = "HERE!!!!!!!!!!!!!!!!!!!!!";
        if (e.CommandName == "bookget")
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
            string url = "bookstatus.aspx?";
            url += "name=" + un + "&bname=" + bn;
            Response.Redirect(url);
        }
    }
}
