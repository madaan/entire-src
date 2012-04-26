//sg
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using  System.Data.SqlClient;
public partial class reconfigure : System.Web.UI.Page
{
    
    string constrUDB=@"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|UsersDatabase.mdf;Integrated Security=True;User Instance=True";
    string constr = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|LoginDatabase.mdf;Integrated Security=True;User Instance=True";
     string constrBDB=@"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|BooksDatabase.mdf;Integrated Security=True;User Instance=True";
     string path = "";
     string filename = "";
    protected void Page_Load(object sender, EventArgs e)
     {

         if (Session["name"] == null)
         {
             Response.Redirect("login.aspx");
         }
     }
    
    protected void btnuploadpic_Click(object sender, EventArgs e)
    {
        if (FileUpload6.HasFile == true)
        {
            string fn = FileUpload6.FileName;
            string ext = fn.Split('.')[1];
             filename = Session["name"].ToString()+"."+ext;
             path = @"~/profilepics/";
            FileUpload6.SaveAs(Server.MapPath(path + filename));
            Label l = new Label();
            l.Text = Server.MapPath(path + filename);
            ViewState["imgpath"] = path+filename;
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        //______ADDING DATA TO UsersDatabase.bmdf ,THIS DATA WILL BE USED TO CREATE HOME PAGE__________
        string bpath = "~/bookpics/";
        string b1 = FileUpload1.FileName;
        string b2 = FileUpload2.FileName;
        string b3 = FileUpload3.FileName;
        string b4 = FileUpload4.FileName;
        string b5 = FileUpload5.FileName;
        FileUpload1.SaveAs(Server.MapPath(bpath+b1));
        FileUpload2.SaveAs(Server.MapPath(bpath+b2));
        FileUpload3.SaveAs(Server.MapPath(bpath+b3));
        FileUpload4.SaveAs(Server.MapPath(bpath+b4));
        FileUpload5.SaveAs(Server.MapPath(bpath+b5));
        string query = "insert into usertable values('" + Session["name"].ToString() + "','" +
            txtname.Text + "','" + TextBoxAboutYourself.Text + "','" + ViewState["imgpath"].ToString() +"','"+
              txtbookname.Text + "','" + (bpath + b1) + "','" + txtb1abt.Text + "','" +
              txtbookname0.Text + "','" + (bpath + b2) + "','" + txtb2abt.Text + "','" +
              txtbookname1.Text + "','" + (bpath + b3) + "','" + txtb3abt.Text + "','" +
              txtbookname2.Text + "','" + (bpath + b4) + "','" + txtb4abt.Text + "','" +
              txtbookname3.Text + "','" + (bpath + b5) + "','" + txtb5abt.Text + "')";
        //_____________________NOW DELETING EXISTING RECORD__________________________
        string querydel="deleter from usertable where uname='"+Session["name"].ToString();
        //_____________________UPDATING RECORDS TO NOTE THAT ACCOUNT HAS BEEN CONFIGURED__________________
        SqlConnection conn = new SqlConnection(constrUDB);
        SqlCommand cmd = new SqlCommand(querydel,conn);
        conn.Open();
        cmd.ExecuteNonQuery(); //first delete existing record
        cmd.CommandText=query;
        cmd.ExecuteNonQuery(); //next update records
        conn.Close();
        SqlConnection conn1 = new SqlConnection(constr);
        SqlCommand cmd1 = new SqlCommand();
        cmd1.Connection = conn1;
        cmd1.CommandText = "update logininfo set config=1 where uname='"+Session["name"] +"'";
        conn1.Open();
        cmd1.ExecuteNonQuery();
        conn1.Close();
        //_____________________FIRST DELETE THE EXISTING RECORD_____________________________________________________
          SqlConnection conn3 = new SqlConnection(constrBDB);
        SqlCommand cmd3 = new SqlCommand();
        cmd3.Connection = conn3;
        cmd3.CommandText ="delete from bookrecord where uname='"+Session["name"].ToString();
        conn3.Open();
        cmd3.ExecuteNonQuery();
        conn3.Close();
        //____________UPDATING BOOK RECORDS TO SET UP LIBRARY______________________________________________
        string q1 = "insert into bookrecord (uname,bname,picurl,about,nrequest) values('" + Session["name"].ToString() + "','" +
            txtbookname.Text + "','" + (bpath + b1) + "','" +
            txtb1abt.Text + "',0)";
      
        string q2 = "insert into bookrecord (uname,bname,picurl,about,nrequest) values('" + Session["name"].ToString() + "','" +
            txtbookname0.Text + "','" + (bpath + b2) + "','" +
            txtb2abt.Text + "',0)";
        string q3 = "insert into bookrecord (uname,bname,picurl,about,nrequest) values('" + Session["name"].ToString() + "','" +
            txtbookname1.Text + "','" + (bpath + b3) + "','" +
            txtb3abt.Text + "',0)";
        string q4 = "insert into bookrecord (uname,bname,picurl,about,nrequest) values('" + Session["name"].ToString() + "','" +
            txtbookname2.Text + "','" + (bpath + b4) + "','" +
            txtb4abt.Text + "',0)";
        string q5 = "insert into bookrecord (uname,bname,picurl,about,nrequest) values('" + Session["name"].ToString() + "','" +
            txtbookname3.Text + "','" + (bpath + b5) + "','" +
            txtb5abt.Text + "',0)";
        
        SqlConnection conn2 = new SqlConnection(constrBDB);
        SqlCommand cmd2 = new SqlCommand();
        cmd2.Connection = conn2;
        cmd2.CommandText = q1 +";" + q2 + ";" + q3 + ";" + q4 + ";" + q5 + ";";
        conn2.Open();
        int count=cmd2.ExecuteNonQuery();
       conn2.Close();
       Response.Redirect("home.aspx");
    }
    
}
