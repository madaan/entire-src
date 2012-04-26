//sg
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Net.Mail;
using System.Data.SqlClient;
public partial class RecoverPassword : System.Web.UI.Page
{

    string constrUDB = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|UsersDatabase.mdf;Integrated Security=True;User Instance=True";
    string constr = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|LoginDatabase.mdf;Integrated Security=True;User Instance=True";
    string constrBDB = @"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|BooksDatabase.mdf;Integrated Security=True;User Instance=True";
           

        ///<summary>
        /// Sends an mail message
        ///</summary>
        ///<param name="from">Sender address</param>
        ///<param name="to">Recepient address</param>
        ///<param name="bcc">Bcc recepient</param>
        ///<param name="cc">Cc recepient</param>
        ///<param name="subject">Subject of mail message</param>
        ///<param name="body">Body of mail message</param>
        public static void SendMailMessage(string from, string to, string bcc, string cc, string subject, string body)
        {
            // Instantiate a new instance of MailMessage
            MailMessage mMailMessage = new MailMessage();
            // Set the sender address of the mail message
            mMailMessage.From = new MailAddress(from);
            // Set the recepient address of the mail message
            mMailMessage.To.Add(new MailAddress(to));

            // Check if the bcc value is null or an empty string
            if ((bcc != null) && (bcc != string.Empty))
            {
                // Set the Bcc address of the mail message
                mMailMessage.Bcc.Add(new MailAddress(bcc));
            }
            // Check if the cc value is null or an empty value
            if ((cc != null) && (cc != string.Empty))
            {
                // Set the CC address of the mail message
                mMailMessage.CC.Add(new MailAddress(cc));
            }       // Set the subject of the mail message
            mMailMessage.Subject = subject;
            // Set the body of the mail message
            mMailMessage.Body = body;

            // Set the format of the mail message body as HTML
            mMailMessage.IsBodyHtml = true;
            // Set the priority of the mail message to normal
            mMailMessage.Priority = MailPriority.Normal;

            // Instantiate a new instance of SmtpClient
            SmtpClient mSmtpClient = new SmtpClient();
            // Send the mail message
            mSmtpClient.Send(mMailMessage);
        }
    
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["login"] == null)
            {
                Response.Redirect("login.aspx");
            }
        }
    
    protected void Button1_Click(object sender, EventArgs e)
    {
            SqlConnection conn = new SqlConnection(constr);
            string query = "select * from logininfo  where uname='" +txtun.Text + "'";
            ViewState["uname"] = txtun.Text;    
        SqlCommand cmd = new SqlCommand();
            cmd.CommandText = query;
            cmd.Connection = conn;
            conn.Open();
            SqlDataReader dr = cmd.ExecuteReader();
            if (dr.HasRows)
            {
                dr.Read();
                Label1.Text = dr["securityquestion"].ToString();

            }
            else
            {
                lblwarning.Text = "RECORD NOT FOUND!"; 
            }

            conn.Close();
    }
    protected void Button2_Click(object sender, EventArgs e)
    {

        SqlConnection conn = new SqlConnection(constr);
        string query = "select * from logininfo  where uname='" + ViewState["uname"].ToString() + "'";
        SqlCommand cmd = new SqlCommand();
        cmd.CommandText = query;
        cmd.Connection = conn;
        conn.Open();
        SqlDataReader dr = cmd.ExecuteReader();
        if (dr.HasRows)
        {
            dr.Read();
            if (txtans.Text == dr["answer"].ToString())
            { 
                SendMailMessage("aman.madaan007@gmail.com",dr["email"].ToString(),"aman.madaan007@gmail.com","ankur_dewan@hotmail.com","YOUR PASSWORD","Your Password is :"+dr["password"].ToString());
                Label1.ForeColor = System.Drawing.Color.Gray;
                Label1.Text = "YOUR PASSWORD HAS BEEN MAILED TO " + dr["email"].ToString();
            }
            else
            {
            lblwarning.Text="WRONG ANSWER!";
            }
        }
        
        conn.Close();
    }
}