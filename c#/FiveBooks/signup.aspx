<!--sg--->
<%@ Page Language="C#" AutoEventWireup="true" CodeFile="signup.aspx.cs" Inherits="signup" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Five Books-Signup</title>
    <script type="text/javascript">
        function validateLength(oSrc, args) {

            args.IsValid = false;
            if (args.Value.length>7)
                args.IsValid = true;
            else
                args.IsValid = false;
        }
</script>
  
    <style type="text/css">
       	.style122 {
	background-image: url(images/page.gif);
	margin: 0;
}

        .style1
        {
        	
            width: 73%;
            background-color:White;
            margin-left:165px;
            margin-top:65px;
            
            margin-right:50px;
        }
       
        .style6
        {
            width: 225px;
        }
        .style7
        {
            width: 225px;
            height: 81px;
        }
        .style43
        {
            width: 225px;
            height: 30px;
        }
        .style44
        {
            width: 676px;
            height: 30px;
        }
        .style45
        {
            width: 100%;
        }
        .style46
        {
            width: 676px;
        }
        </style>
</head>
<body class="style122">
    <form id="form1" runat="server">
    <div>
    
        //sg<br />
        <br />
                    <asp:ScriptManager ID="ScriptManager1" runat="server">
                    </asp:ScriptManager>
                
        <br />
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="Label2" runat="server" Font-Bold="True" Font-Names="Mistral" 
            Font-Size="XX-Large" ForeColor="#0066FF" 
            Text="Before You Start Sharing,We'd Like To Know You Better&amp;nbsp;,So &lt;br&gt;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;Fill In The Form To Get Started!"></asp:Label>
        <br/><table class="style1" bgcolor="#FFFFCC">
            <tr>
                <td class="style43">
                    Username&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
                <td class="style44">
                    <asp:TextBox ID="TextName" runat="server" Width="183px" MaxLength="50"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                        ControlToValidate="Textname" 
                        ErrorMessage="Username Field Cannot Be Left Blank" ForeColor="Red" 
                        ValidationGroup="name">*</asp:RequiredFieldValidator>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<asp:UpdatePanel ID="UpdatePanel3" runat="server">
                        <ContentTemplate>
                            <asp:UpdatePanel ID="UpdatePanel2" runat="server">
                                <ContentTemplate>
                                    <asp:UpdatePanel ID="UpdatePanel4" runat="server">
                                        <ContentTemplate>
                                            <asp:Button ID="Button3" runat="server" onclick="Button3_Click" 
                                                Text="Check Availability" ValidationGroup="name" />
                                            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                                            <asp:Label ID="Label1" runat="server"></asp:Label>
                                        </ContentTemplate>
                                    </asp:UpdatePanel>
                                </ContentTemplate>
                            </asp:UpdatePanel>
                        </ContentTemplate>
                    </asp:UpdatePanel>
                </td>
            </tr>
            <tr>
                <td class="style6">
                    Password<br />
                </td>
                <td class="style46">
                    <asp:TextBox ID="TextPass" runat="server" TextMode="Password" Width="180px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                        ControlToValidate="Textpass" Display="Dynamic" 
                        ErrorMessage="Password Field Cannot Be Left Blank" ForeColor="Red">*</asp:RequiredFieldValidator>
                    <asp:CustomValidator ID="CustomValidator1" runat="server" 
                        ClientValidationFunction="checktext" Display="Dynamic" 
                        ErrorMessage="Min Password Length-7 with atleast one Non-Alphanumeric character "  
                        EnableClientScript="False" ControlToValidate="TextPass" 
                        ValidateEmptyText="True" ForeColor="Red" 
                        onservervalidate="CustomValidator1_ServerValidate">*</asp:CustomValidator>
                </td>
            </tr>
            <tr>
                <td class="style43">
                    Confirm&nbsp; Password<br />
                </td>
                <td class="style44">
                    <asp:TextBox ID="TextConfpass" runat="server" TextMode="Password" Width="180px"></asp:TextBox>
                    <asp:CompareValidator ID="CompareValidator1" runat="server" 
                        ControlToCompare="Textpass" ControlToValidate="TextConfpass" Display="Dynamic" 
                        ErrorMessage="Passwords Do Not Match" ForeColor="Red">*</asp:CompareValidator>
                
                </td>
            </tr>
            <tr>
                <td class="style7">
                    Date Of Birth :</td>
                <td class="style46">
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<asp:UpdatePanel ID="UpdatePanel1" runat="server">
                        <ContentTemplate>
                            <asp:DropDownList ID="DropDownListMonth" runat="server" AutoPostBack="True" 
                                Height="18px" onselectedindexchanged="DropDownListMonth_SelectedIndexChanged" 
                                Width="107px">
                            </asp:DropDownList>
                            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                            <asp:DropDownList ID="DropDownListYear" runat="server" AutoPostBack="True" 
                                Height="16px" onselectedindexchanged="DropDownListYear_SelectedIndexChanged" 
                                Width="100px">
                            </asp:DropDownList>
                            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                            <asp:DropDownList ID="DropDownDay" runat="server" Height="24px" 
                                onselectedindexchanged="DropDownDay_SelectedIndexChanged" Width="108px">
                            </asp:DropDownList>
                        </ContentTemplate>
                    </asp:UpdatePanel>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </td>
            </tr>
            <tr>
                <td class="style43">
                    Email Address</td>
                <td class="style44">
                    <asp:TextBox ID="txtemail" runat="server" Width="178px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator5" runat="server" 
                        ControlToValidate="txtemail" Display="Dynamic" 
                        ErrorMessage="Email Id field cannot be left blank" ForeColor="Red">*</asp:RequiredFieldValidator>
                    <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" 
                        ControlToValidate="txtemail" Display="Dynamic" 
                        ErrorMessage="Email Address Format Not Correct" ForeColor="Red" 
                        ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*">*</asp:RegularExpressionValidator>
                </td>
            </tr>
            <tr>
                <td class="style6">
                    Contact Number:</td>
                <td class="style46">
                    <asp:TextBox ID="TextBoxPh" runat="server" Width="181px" MaxLength="10"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="style43">
                    Security Question:</td>
                <td class="style44">
                    <asp:TextBox ID="TextBoxSecurityQuestion" runat="server" Width="428px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" 
                        ControlToValidate="TextBoxSecurityQuestion" 
                        ErrorMessage="Security Question Field Cannot Be Left Blank" ForeColor="Red">*</asp:RequiredFieldValidator>
                    <br />
                </td>
            </tr>
            <tr>
                <td class="style6">
                    Answer</td>
                <td class="style46">
                    <asp:TextBox ID="TextBoxAnswer" runat="server" Width="192px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" 
                        ControlToValidate="TextBoxAnswer" 
                        ErrorMessage="Security Answer Field Cannot Be Left Blank" ForeColor="Red">*</asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="style6">
                    Enter The Text Seen in
                    <br />
                    The Picture in the Text Box Below</td>
                <td class="style46">
                    <asp:Image ID="Image1" runat="server" Height="72px" Width="73px" />
                    <asp:Image ID="Image2" runat="server" Height="72px" Width="73px" />
                    <asp:Image ID="Image3" runat="server" Height="72px" Width="73px" />
                    <asp:Image ID="Image4" runat="server" Height="72px" Width="73px" />
                    <asp:Image ID="Image5" runat="server" Height="72px" Width="73px" />
                    <asp:Image ID="Image6" runat="server" Height="72px" Width="73px" />
                    <asp:Image ID="Image7" runat="server" Height="72px" Width="73px" />
                    <asp:Image ID="Image8" runat="server" Height="72px" Width="73px" />
&nbsp;
                    <asp:Label ID="lblcaptcha" runat="server"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="style6">
                    &nbsp;</td>
                <td class="style46">
                    <asp:TextBox ID="txtcaptcha" runat="server" Width="191px"></asp:TextBox>
                </td>
            </tr>
            </table>
    
    </div>
    <table class="style45">
        <tr>
            <td>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:ValidationSummary ID="ValidationSummary1" runat="server" Width="255px" />
                </td>
            <br />
            <br />
        </tr>
        <tr>
            <td>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <asp:Button ID="Button2" runat="server" onclick="Button2_Click" 
                    Text="Register Now!" BackColor="Black" BorderStyle="Ridge" Font-Bold="True" 
                    Font-Names="Andalus" Font-Size="Medium" ForeColor="White" />
                &nbsp;</td>
        </tr>
        <tr>
            <td>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </td>
        </tr>
    </table>
    </form>
</body>
</html>
