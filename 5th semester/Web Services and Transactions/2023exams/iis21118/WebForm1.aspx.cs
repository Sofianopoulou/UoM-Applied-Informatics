using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace iis21118
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        eu.dataaccess.footballpool.ws.Info fbWS = new
                       eu.dataaccess.footballpool.ws.Info();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                DropDownList1.Items.Add("-Select-");

                eu.dataaccess.footballpool.ws.tTeamCoachName[] coachNames =
                    fbWS.AllTeamCoachNames();

                for(int i=0; i<coachNames.Length; i++)
                {
                    DropDownList1.Items.Add(coachNames[i].sCoachName);
                }
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string coachName = DropDownList1.Text;
            eu.dataaccess.footballpool.ws.tTeamCoachName[] coachNames =
                    fbWS.AllTeamCoachNames();

            eu.dataaccess.footballpool.ws.tPlayerName[] playerNames =
                fbWS.AllPlayerNames(true);

            string teamName="";
            for (int i = 0; i < coachNames.Length; i++)
            {
                if (coachNames[i].sCoachName == coachName)
                {
                    Label1.Text = coachNames[i].sTeamName;
                    teamName = coachNames[i].sTeamName;
                }
            }

            for (int i = 0; i < playerNames.Length; i++)
            {
                if (playerNames[i].sCountryName == teamName)
                    Image1.ImageUrl = playerNames[i].sCountryFlag;
            }    
        }
     }
}