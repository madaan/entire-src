//sg
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
public partial class signup : System.Web.UI.Page
{
    
    string constr =@"Data Source=.\SQLEXPRESS;AttachDbFilename=|datadirectory|LoginDatabase.mdf;Integrated Security=True;User Instance=True";
   protected void Page_Load(object sender, EventArgs e)
   {
       if (!IsPostBack)
       {
           MakeCaptcha();
           string[] months = { "Select Month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
           foreach (string month in months)
               DropDownListMonth.Items.Add(month);
           DropDownListYear.Items.Add("Select Year");
           for (int i = 1900; i < 2007; i++)
               DropDownListYear.Items.Add(i.ToString());
           DropDownDay.Items.Add("Select Day");

           for (int i = 1; i < 32; i++)
               DropDownDay.Items.Add(i.ToString());
       }

   }
   protected void MakeCaptcha()
   { 
    string[] src={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string captcha = "";
   
       Random r=new Random();
       for (int i = 0; i < 8; i++)
    {
        captcha += src[r.Next() % 36];
    
       }
      string captcha1 = captcha.ToLower();
       Image1.ImageUrl="~/captcha/"+captcha1[0]+".jpg";
       Image2.ImageUrl="~/captcha/"+captcha1[1]+".jpg";
       Image3.ImageUrl="~/captcha/"+captcha1[2]+".jpg";
       Image4.ImageUrl="~/captcha/"+captcha1[3]+".jpg";
       Image5.ImageUrl="~/captcha/"+captcha1[4]+".jpg";
       Image6.ImageUrl="~/captcha/"+captcha1[5]+".jpg";
       Image7.ImageUrl="~/captcha/"+captcha1[6]+".jpg";
       Image8.ImageUrl="~/captcha/"+captcha1[7]+".jpg";
       ViewState["captcha"] = captcha1;
    //   lblcaptcha.Text = ViewState["captcha"].ToString();
   }

    
   
   protected void Page_PreLoad(object source, ServerValidateEventArgs args)
   {
   }
    protected void CustomValidator1_ServerValidate(object source, ServerValidateEventArgs args)
    {
        args.IsValid = false;
        bool len=false,alpha=false;

        if (args.Value.Length > 7)
        {
            len=true; 
        }
        string s = args.Value;
        foreach (char c in s)
        {
          
            if(((c>'z')||(c<'a'))&&(c>'Z')||(c<'A'))
            {
            alpha=true;
            break;
            }
        }
        if((alpha==true)&&(len==true))
        {
        args.IsValid=true;
        }
    }
    protected void DropDownListMonth_SelectedIndexChanged(object sender, EventArgs e)
    {
        if (DropDownListMonth.Text == "February")
        {
            if (DropDownListYear.Text != "Select Year")
            { 
               int year = Convert.ToInt32(DropDownListYear.Text);
        if(!(year%4==0))
            {
                DropDownDay.Items.Remove("29");
               
                    DropDownDay.Text = "28";
         
            }
       
            }
        }
     DropDownDay_SelectedIndexChanged(sender, e);
    }
    protected void DropDownDay_SelectedIndexChanged(object sender, EventArgs e)
    {
        
        int days=0;
        DropDownDay.Items.Clear();
       
        switch (DropDownListMonth.Text)
        { 
                case  "January":case "March":case "May":case "July":case "August":case "October":case "December":     
                days=31;
                break;
                case "April":case "June":case "September":case "November":
                days=30;
                break;
            case "February":
                days = 29;
                break;
        }
        for (int i = 1; i <= days; i++)
        {
            DropDownDay.Items.Add(i.ToString());

        }
       

    }
    protected void DropDownListYear_SelectedIndexChanged(object sender, EventArgs e)
    {
        
       
        int year = Convert.ToInt32(DropDownListYear.Text);
        string month = DropDownListMonth.Text;
        int day = int.Parse(DropDownDay.Text);
        if (month == "February")
        {
            ListItem li = new ListItem("29");

        if(!(year%4==0))
            {
                DropDownDay.Items.Remove("29");
                if (day == 29)
                    DropDownDay.Text = "28";
         
            }
            
        else if (!DropDownListMonth.Items.Contains(li))
        {
            DropDownDay.Items.Add(li);
        
        }
        }
        
      
        }
    protected  bool CheckUsername()
    {
        SqlConnection conn = new SqlConnection(constr);
        SqlCommand cmd = new SqlCommand();
        cmd.Connection = conn;
        cmd.CommandText = "select password from logininfo where uname='" + TextName.Text.Trim() +"'";
        conn.Open();
        SqlDataReader dr = cmd.ExecuteReader();
        bool rows =dr.HasRows;
        conn.Close();
        if (rows)
        {
            Label1.ForeColor = System.Drawing.Color.Red;
            Label1.Text = "USER NAME IS NOT AVAILABLE";
            return false;
        }
        else
        {
            Label1.ForeColor = System.Drawing.Color.Green;
            Label1.Text = "USER NAME IS AVAILABLE";
            return true;
        }
        
        
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        bool usernamevalid=CheckUsername();//check if username already exists
       
        if ((Page.IsValid)&&(usernamevalid)&&(txtcaptcha.Text==ViewState["captcha"].ToString())) //if page is valid and the username is available
        {
            string name=TextName.Text;
            string pass=TextPass.Text;
            string mm = DropDownListMonth.Text.Substring(0, 3);
            string mm1 = mm.ToLower();
            string [] months = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
            int i=1;
            foreach(string month in months)
            {
                if (mm1== month)
                {
                    break;
                }
                i++;
            }
            string dob = DropDownDay.Text + "-" + i.ToString() +"-" + DropDownListYear.Text;
            string email = txtemail.Text.Trim(); ;
            string phone=TextBoxPh.Text.Trim();
            string sq = TextBoxSecurityQuestion.Text.Trim(); ;
            string ans = TextBoxAnswer.Text.Trim(); ;

            Session["name"] = TextName.Text; //set up the session
            SqlConnection conn=new SqlConnection(constr);
            SqlCommand cmd=new SqlCommand();
            cmd.Connection=conn;
            cmd.CommandText="insert into logininfo values ('"+name+"','"+pass+"',"+dob+","+phone+",'"+email+"','"+sq+"','"+ans+"',0)";
            conn.Open();
            cmd.ExecuteNonQuery();
            conn.Close();
            Response.Redirect("login.aspx");
        }
        else if(txtcaptcha.Text!=ViewState["captcha"].ToString())
        {
        lblcaptcha.Text="PLEASE LOOK AT THE IMAGE CAREFULLY AND THEN TYPE";
        MakeCaptcha();
        }
       }
    protected void Button1_Click(object sender, EventArgs e)
    {
       
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        SqlConnection conn = new SqlConnection(constr);
        SqlCommand cmd = new SqlCommand();
        cmd.Connection = conn;
        cmd.CommandText = "select password from logininfo where uname='" + TextName.Text.Trim() +"'";
        conn.Open();
        SqlDataReader dr = cmd.ExecuteReader();
        if (dr.HasRows)
        {
            Label1.ForeColor = System.Drawing.Color.Red;
            Label1.Text = "USER NAME IS NOT AVAILABLE";

        }
        else
        {
            Label1.ForeColor = System.Drawing.Color.Green;
            Label1.Text = "USER NAME IS AVAILABLE";

        }
        conn.Close();
        
    }
}
