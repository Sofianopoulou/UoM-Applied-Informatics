<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="iis21118.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            color: #CC66FF;
            text-decoration: underline;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <span class="auto-style1"><strong>iis21118</strong></span><br />
            <br />
            Coach Names: <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" Width="192px">
            </asp:DropDownList>
            <br />
            <br />
            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Κλήση Υπηρεσίας" />
            <br />
            <br />
            Team Name:
            <asp:Label ID="Label1" runat="server"></asp:Label>
            <br />
            <br />
            Country Flag:<br />
            <asp:Image ID="Image1" runat="server" />
        </div>
    </form>
</body>
</html>
