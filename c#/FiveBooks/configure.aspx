<%@ Page Language="C#" AutoEventWireup="true" CodeFile="configure.aspx.cs" Inherits="configure" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .style1
        {
            width: 100%;
        }
        .style2
        {
        	background-color:InfoBackground;
        	color:Navy;
        	font-size:large;
            
        	border-bottom-style:double;
        }
        .style3
        {
            background-color:InfoBackground;
        	color:Navy;
        	border-bottom-style:double;
            font-size:large;
            width: 142px;
            height: 45px;
        }
        .style4
        {
            height: 45px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" enctype="multipart/form-data">
    <div>
    
        <br />
    
        <table class="style1">
            <tr>
                <td class="style2" colspan="2">
                    <asp:Label ID="Label1" runat="server" Font-Names="Arabic Typesetting" 
                        Font-Size="XX-Large" 
                        Text="Welcome To FiveBooks,This is second and final step before your profile is ready,please fill in the details to proceed.&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"></asp:Label>
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </td>
            </tr>
            <tr>
                <td class="style2">
                    Full Name:</td>
                <td>
                    <asp:TextBox ID="txtname" runat="server" Width="258px"></asp:TextBox>
                    &nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator6" runat="server" 
                        ControlToValidate="txtname" ErrorMessage="Field Cannot be left blank" 
                        ForeColor="Red"></asp:RequiredFieldValidator>
                    <br />
                </td>
            </tr>
            <tr>
                <td class="style2" rowspan="2">
                    About You:</td>
                <td>
                    <asp:TextBox ID="TextBoxAboutYourself" runat="server" Height="77px" 
                        TextMode="MultiLine" Width="265px"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    Your Picture</td>
                <td>
                    <asp:FileUpload ID="FileUpload6" runat="server" Width="222px" />
&nbsp;&nbsp;<asp:RequiredFieldValidator ID="RequiredFieldValidator7" runat="server" 
                        ControlToValidate="FileUpload6" ErrorMessage="Field cannot be left blank" 
                        ForeColor="Red" ValidationGroup="pp">*</asp:RequiredFieldValidator>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:Button ID="btnuploadpic" runat="server" onclick="btnuploadpic_Click" 
                        Text="Upload" ValidationGroup="pp" BackColor="#0033CC" 
                        BorderStyle="Outset" ForeColor="White" />
                </td>
            </tr>
            <tr>
                <td class="style2" colspan="2">
                    <br />
                    The Next Step is to Fill In Some Information about the books you want to share.<br />
                    Upload Cover Page Pictures of Books You Want To Share (please Use 
                    Amazon,flipkart,google books etc.&nbsp; in case a scanner or camera is not 
                    available)<br />
                    <br />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    <br />
                    BOOK 1<br />
                </td>
                <td>
                    <asp:FileUpload ID="FileUpload1" runat="server" Width="242px" 
                        ToolTip="Browse To The Location Where  Picture of the cover page is stored" />
&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                        ControlToValidate="FileUpload1" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtbookname" runat="server" Width="214px" ForeColor="#0066FF" 
                        ToolTip="BOOK NAME">YOUR BOOK NAME HERE</asp:TextBox>
&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator8" runat="server" 
                        ControlToValidate="txtbookname" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtb1abt" runat="server" Height="72px" TextMode="MultiLine" 
                        Width="215px" ToolTip="Write a few lines about the Book"></asp:TextBox>
                    <br />
                </td>
            </tr>
            <tr>
                <td class="style3">
                    BOOK 2</td>
                <td class="style4">
                    <br />
                    <asp:FileUpload ID="FileUpload2" runat="server" 
                        ToolTip="Browse To The Location Where  Picture of the cover page is stored" />
&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                        ControlToValidate="FileUpload2" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtbookname0" runat="server" Width="214px" ToolTip="BOOK NAME"></asp:TextBox>
&nbsp;&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator9" runat="server" 
                        ControlToValidate="txtbookname0" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtb2abt" runat="server" Height="72px" TextMode="MultiLine" 
                        Width="215px" ToolTip="Write a few lines about the Book"></asp:TextBox>
                    <br />
                    <br />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    BOOK 3</td>
                <td>
                    <br />
                    <asp:FileUpload ID="FileUpload3" runat="server" 
                        ToolTip="Browse To The Location Where  Picture of the cover page is stored" />
&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" 
                        ControlToValidate="FileUpload3" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtbookname1" runat="server" Width="214px" ToolTip="BOOK NAME"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator10" runat="server" 
                        ControlToValidate="txtbookname1" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtb3abt" runat="server" Height="72px" TextMode="MultiLine" 
                        Width="215px" ToolTip="Write a few lines about the Book"></asp:TextBox>
                    <br />
                    <br />
                    <br />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    BOOK 4</td>
                <td>
                    <asp:FileUpload ID="FileUpload4" runat="server" 
                        ToolTip="Browse To The Location Where  Picture of the cover page is stored" />
&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" 
                        ControlToValidate="FileUpload4" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtbookname2" runat="server" Width="214px" ToolTip="BOOK NAME"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator11" runat="server" 
                        ControlToValidate="txtbookname2" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtb4abt" runat="server" Height="72px" TextMode="MultiLine" 
                        Width="215px" ToolTip="Write a few lines about the Book"></asp:TextBox>
                    <br />
                    <br />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    BOOK 5</td>
                <td>
                    <asp:FileUpload ID="FileUpload5" runat="server" 
                        ToolTip="Browse To The Location Where  Picture of the cover page is stored" />
&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator5" runat="server" 
                        ControlToValidate="FileUpload5" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtbookname3" runat="server" Width="214px" ToolTip="BOOK NAME"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator12" runat="server" 
                        ControlToValidate="txtbookname3" ErrorMessage="select a picture" 
                        ForeColor="Red" ValidationGroup="bp">*</asp:RequiredFieldValidator>
                    <br />
                    <br />
                    <asp:TextBox ID="txtb5abt" runat="server" Height="72px" TextMode="MultiLine" 
                        Width="215px" ToolTip="Write a few lines about the Book"></asp:TextBox>
                    <br />
                    <br />
                </td>
            </tr>
            <tr>
                <td class="style2" rowspan="2">
                    &nbsp;</td>
                <td>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:Button ID="Button1" runat="server" Text="Finish" ValidationGroup="bp" 
                        onclick="Button1_Click" BackColor="#0033CC" BorderStyle="Outset" 
                        ForeColor="White" />
                    &nbsp;</td>
            </tr>
            <tr>
                <td>
                    <br />
                </td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>
