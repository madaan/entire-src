<%@ Page Language="C#" AutoEventWireup="true" CodeFile="schedule.aspx.cs" Inherits="schedule" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
     <style type="text/css">
     #b1
        {
        background-image: url('images/sch.jpg');
       
            height: 255px;
            width: 1129px;
        }
        </style>
</head>
<body id="b1">
    <form id="form1" runat="server">
    <div>
    
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;
        <a href="home.aspx"><asp:Label ID="Label1" runat="server" BackColor="White" BorderColor="#6600CC" 
            Font-Bold="True" Font-Italic="True" Font-Names="Ravie" Font-Overline="True" 
            Font-Size="XX-Large" Font-Underline="True" ForeColor="#0033CC" 
            Text="FiveBooks:"></asp:Label></a>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;
        <asp:Label ID="Label2" runat="server" BackColor="#FFFFCC" BorderColor="#FFFFCC" 
            Font-Bold="True" Font-Names="Andalus" Font-Size="X-Large" ForeColor="#666699" 
            Text="This Week's Meetup Schedule"></asp:Label>
    
        </div>
    <p>
        &nbsp;</p>
    <p>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        &nbsp; 
        
    </p>
    <p>
        &nbsp;</p>
    <p>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        &nbsp;</p>
    <p>
        
    </p>
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
        BackColor="White" BorderColor="#999999" BorderStyle="None" BorderWidth="1px" 
        CellPadding="3" GridLines="Vertical" style="margin-left: 134px" 
        Width="1026px" Caption="This Week's Schedule" 
        onrowcommand="GridView1_RowCommand">
        <AlternatingRowStyle BackColor="#DCDCDC" />
        <FooterStyle BackColor="#CCCCCC" ForeColor="Black" />
        <HeaderStyle BackColor="#000084" Font-Bold="True" ForeColor="White" />
        <PagerStyle BackColor="#999999" ForeColor="Black" HorizontalAlign="Center" />
        <RowStyle BackColor="#EEEEEE" ForeColor="Black" />
        <SelectedRowStyle BackColor="#008A8C" Font-Bold="True" ForeColor="White" />
        <SortedAscendingCellStyle BackColor="#F1F1F1" />
        <SortedAscendingHeaderStyle BackColor="#0000A9" />
        <SortedDescendingCellStyle BackColor="#CAC9C9" />
        <SortedDescendingHeaderStyle BackColor="#000065" />
    <Columns>
    <asp:TemplateField>
    <ItemTemplate>
       <asp:HiddenField ID="HiddenField1" runat="server" Value='<%#Eval("uname") %>'>
       </asp:HiddenField>
          <asp:HiddenField ID="HiddenField2" runat="server"  Value=' <%#Eval("bname") %>'>
       </asp:HiddenField>
    <asp:Label ID="Label3" runat="server" BackColor="#CCFFFF" Font-Bold="True" 
    
            Font-Italic="False" Font-Names="Goudy Stout" Font-Size="X-Large" 
            ForeColor="Black" Text='  <%#Eval("uname") %>'></asp:Label>
  
    </ItemTemplate>
    
    </asp:TemplateField>
    <asp:TemplateField>
    <ItemTemplate>
    <asp:Label ID="Label4" runat="server" BackColor="#CCFFCC" Font-Bold="True" 
            Font-Italic="True" Font-Names="Snap ITC" Font-Size="XX-Large" 
            ForeColor="#000066" Text="  Shares"></asp:Label>
  
</ItemTemplate>
      </asp:TemplateField>
   <asp:TemplateField>
    
   <ItemTemplate>
   <asp:Button ID="Button1" runat="server" Text=' <%#Eval("bname") %>'  CommandName="bookget" 
      CommandArgument="<%# ((GridViewRow) Container).RowIndex %>"/>
  
   </ItemTemplate>
   </asp:TemplateField>
   <asp:TemplateField>
   <ItemTemplate>
   <asp:Label ID="Label5" runat="server" BackColor="#CCFFCC" Font-Bold="True" 
            Font-Italic="True" Font-Names="Snap ITC" Font-Size="XX-Large" 
            ForeColor="#000066" Text="With"></asp:Label>
  </ItemTemplate>
   </asp:TemplateField> 
    <asp:TemplateField>
    <ItemTemplate>
    <%#Eval("u1") %>
    </ItemTemplate>
    </asp:TemplateField>
    </Columns>
    </asp:GridView>
    </form>
</body>
</html>
