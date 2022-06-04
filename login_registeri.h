
//----------------------------------------------------------------------------
using namespace sf;
using namespace std;
//std::ofstream fout("login.txt", std::ios::in | std::ios::out);
///-------------------------------------------global initializations
int s = 1;
int i = 0;
class accounti
{

public:
    string email = "";
    string password = "";
    long long money = 0LL;
    string id = "";
    string toAdd="";
    bool added = 0;
    short chatBoxInd = -1;
    string nickName = "";

    accounti() {};

    ~accounti() {};
    accounti(string em, string pass, long long mon, string Id) {
        this->email = em;
        this->password = pass;
        this->money = mon;
        this->id = Id;
    }
    //

};

struct chatInfo {
    string nm="";
    string mess="";
    short chatBoxInd = -1;
};
Vector <chatInfo>glopalChat;
Vector <chatInfo>adminChat;

Vector <accounti>arr_acc;
//
struct scn
{
    bool email = false;
    bool password = false;
};  

scn sc1, sc2;
object alert;
void assgni(accounti to, accounti from) {
    to.email = from.email;
    to.id = from.id;
    to.money = from.money;
    to.password = from.password;
}
bool toGo = 1;
/////////////////////////////////////////////////////////////////////
Texture t1, t2, t3, t4, t5;

Textbox textRegisterPassword(30, Color::White, false);
Textbox textRegisterEmail(30, Color::White, false);
Textbox textLoginPassword(30, Color::White, false); 
Textbox textLoginEmail(30, Color::White, false); 
Text  Password; Text  Email; Font arial; 
Sprite Submit;
Sprite registerr;
Sprite backg;
Sprite backbutton;
Sprite login;

void initial_accounts() {
    //------------------------------------------admins accounts
    accounti ad("bahnasy@admin.com", "admin123", 10000000 + 1, "admin");
    arr_acc.push_back(ad);
    ad = { "ali@admin.com", "admin123", 10000000 + 1, "admin" };
    arr_acc.push_back(ad);
    ad = { "elofy@admin.com", "admin123", 10000000 + 1, "admin" };
    arr_acc.push_back(ad);
    ad = { "hisham@admin.com", "admin123", 10000000 + 1, "admin" };
    arr_acc.push_back(ad);
    ad = { "swilim@admin.com", "admin123", 10000000 + 1, "admin" };
    arr_acc.push_back(ad);
    ad = { "omar@admin.com", "admin123", 10000000 + 1, "admin" };
    arr_acc.push_back(ad);
    ad = { "marcus@admin.com", "admin123", 10000000 + 1, "admin" };
    arr_acc.push_back(ad);
    //-----------------------------------------------------------
    alert.make_text("MorningRainbow.ttf", "Enter(8 - 20) for password\nEnter(@dragons.com) as a domain for Email");
    alert.shape_text(46, Color::Red);
    alert.text_pos(1920 / 2, 1080 / 2);
}
struct ret_state {
    int ind = -1;
    int re = -1;
    ret_state() {};
};
int ind = -1, re = -1;
void check_ex(string em,string pass) {
    //-----------
    /*
    this func returns 1 if both password and email are right, and 0 if neither of them, and 2 if email exists only
    */
    re = -1;
    for (int i = 0; i < arr_acc.size();i++) {
        if (arr_acc[i].email == em && arr_acc[i].password == pass) {
            ind=i,re=1; break;
        }
        else if (arr_acc[i].email == em) { ind = -1, re = 2; break; }
    
    }
if (re == -1)
ind = arr_acc.size(), re = 0;
    
    
}

void initialLoginWindow() {
    t1.loadFromFile("assets\\login\\login button black_5236751.png");
    t2.loadFromFile("assets\\login\\register.png");
    t3.loadFromFile("assets\\login\\4k-goku-2020-t1-1920x1080.jpg");
    t4.loadFromFile("assets\\option\\return but.png");
    t5.loadFromFile("assets\\login\\icons8-submit-64.png");
    Submit.setTexture(t5);
    registerr.setTexture(t2);
    backg.setTexture(t3);
    backbutton.setTexture(t4);
    login.setTexture(t1);

    login.setScale(0.25f, 0.25f);
    backbutton.scale(-0.5, 0.5);
    
    Submit.setScale(2.f, 2.f);
    
    arial.loadFromFile("alfont_com_arial-1.ttf");

    
    Email.setFont(arial);
    Email.setString("EMAIL :");
    Email.setCharacterSize(40);
    Email.setStyle(Text::Style::Underlined);
    

    
    Password.setFont(arial);
    Password.setString("PASSWORD :");
    Password.setCharacterSize(40);
    Password.setStyle(Text::Style::Underlined);

    
    textLoginEmail.setFont(arial);
    textLoginEmail.setLimit(1, 30);
    
    textLoginPassword.setFont(arial);
    textLoginPassword.setLimit(1, 20);
    
    textRegisterEmail.setFont(arial);
    textRegisterEmail.setLimit(1, 30);
    
    textRegisterPassword.setFont(arial);
    textRegisterPassword.setLimit(1, 20);
    //---------------------------------------------------
    

}
//------------------------
void to_run_logini()
{
    //-----------------------------------------------------------
        ///////get event
     Event closeEv;
     while (win.isOpen()) {

         while (win.pollEvent(closeEv))
         {
             if (closeEv.type == sf::Event::Closed) {
                 alertTxt.alert(win, "THANK YOU! \n DR.ESRAA SAIED", Color::Red, 820, 450);

                 win.close();
             }
             if (closeEv.type == Event::MouseButtonPressed) {
                 if (closeEv.key.code == Mouse::Left) {

                     if (s == 1) {
                         if (mouse_intersects(win, Email))
                         {
                             // click on email
                             sc1.email = true;
                             cout << "e";
                             textLoginEmail.setSelected(true);
                         }
                         if (mouse_intersects(win, Password))
                         {
                             //click on password
                             sc1.password = true;
                             cout << "p";
                             textLoginPassword.setSelected(true);
                         }

                         if (mouse_intersects(win, login) && mouse_l())
                         {
                             cout << "lo";
                             std::string e, p, u, q;
                             e = textLoginEmail.getText();
                             p = textLoginPassword.getText();
                             /*ifstream input("login.txt");
                             int c = 0;
                             if (e.empty() == false && p.empty() == false)
                             {
                                 while (input >> u >> q)
                                 {
                                     if (u == e && q == p)

                                     {
                                         c = 1;

                                     }
                                 }
                                 input.close();*/
                             if (e.empty() || p.empty())goto parti;
                             check_ex(e, p);
                             if (re == 1) {
                                 window = -1;
                                 //clear

                                 textLoginPassword.clear_text();

                                 textLoginEmail.clear_text();
                                 //
                                 Sleep(200);
                                 return;
                             }
                             else {
                                 // alert 
                                 alert.text_str("Enter Valid Mail Or Password");
                                 win.clear();
                                 win.draw(alert.text);
                                 win.display();
                                 Sleep(4000);
                                 continue;
                             }
                         }
                     parti:
                         if (mouse_intersects(win, registerr)) {
                             s = 2;
                         }
                     }

                     else if (s == 2) {
                         if (mouse_intersects(win, Email))
                         {
                             // click on email
                             textRegisterEmail.setSelected(true);
                             sc2.email = true;
                             cout << "e";

                         }
                         if (mouse_intersects(win, Password))
                         {
                             //click on password
                             textRegisterPassword.setSelected(true);
                             sc2.password = true;
                             cout << "p";

                         }
                         if (mouse_intersects(win, backbutton))
                         {
                             //click on back

                             cout << "back";
                             s = 1;

                         }
                         if (mouse_intersects(win, Submit) && mouse_l()) {
                             std::string e, p;
                             e = textRegisterEmail.getText();
                             p = textRegisterPassword.getText();
                             /* ofstream fout("login.txt", std::ios::in | std::ios::out| ios::app);

                                if (e.empty() == false && p.empty() == false)
                                {

                                    fout << e << ' ' << p << endl;

                                }
                                fout.close();*/

                                // check if valid mail first://
                             if (p.size() < 8 || p.size() > 20 || e.size() < 14) {
                                 // alert 
                                 alert.text_str("Enter(8 - 20) for password\nEnter(@dragons.com) as a domain for Email");
                                 win.clear();
                                 win.draw(alert.text);
                                 win.display();
                                 Sleep(4000);
                                 continue;
                             }
                             // then check domain(@dragons.com)
                             string domain = "@dragons.com";
                             bool right_domain = 1;
                             for (int i = e.size() - 1, j = 11; j > -1; i--, j--) {
                                 if (domain[j] != e[i])right_domain = 0;
                             }
                             if (!right_domain) {
                                 // alert 
                                 alert.text_str("Enter(8 - 20) for password\nEnter(@dragons.com) as a domain for Email");
                                 win.clear();
                                 win.draw(alert.text);
                                 win.display();
                                 Sleep(4000);

                                 continue;
                             }
                             //---------------------------
                             if (e.empty() || p.empty())continue;
                             check_ex(e, p);
                             if (re == 0) {
                                 string id = make_unique_id();
                                 accounti temp(e, p, 1000, id);
                                 arr_acc.push_back(temp);
                                 window = 1;
                                 // clear
                                 textRegisterPassword.clear_text();

                                 textRegisterEmail.clear_text();
                                 //
                                 Sleep(200);
                                return ;
                             }
                         }

                     }
                 }
             }
             if (closeEv.type == Event::TextEntered) {
                 if (s == 1)
                 {
                     if (sc1.password == true)
                     {
                         if (Keyboard::isKeyPressed(Keyboard::Return))
                         {

                             textLoginPassword.setSelected(false);
                             sc1.password = false;
                         }
                         else
                         {
                             textLoginPassword.typedOn(closeEv);
                         }
                     }
                     else if (sc1.email == true)
                     {
                         if (Keyboard::isKeyPressed(Keyboard::Return))
                         {
                             textLoginEmail.setSelected(false);
                             sc1.email = false;
                         }
                         else
                         {
                             textLoginEmail.typedOn(closeEv);
                         }
                     }


                 }
                 if (s == 2) {
                     if (sc2.password == true)
                     {
                         if (Keyboard::isKeyPressed(Keyboard::Return))
                         {
                             textRegisterPassword.setSelected(false);
                             sc2.password = false;
                         }
                         else
                         {
                             textRegisterPassword.typedOn(closeEv);
                         }
                     }
                     else if (sc2.email == true)
                     {
                         if (Keyboard::isKeyPressed(Keyboard::Return))
                         {
                             textRegisterEmail.setSelected(false);
                             sc2.email = false;
                         }
                         else
                         {
                             textRegisterEmail.typedOn(closeEv);
                         }
                     }

                 }
             }

         }
         
        //////////////////////////////drawings
        win.clear();
        win.draw(backg);
        if (s == 1) {
            // login.setPosition(143, 405);
            login.setPosition(180, 300);
            win.draw(login);
            Password.setPosition(50, 235);
            win.draw(Password);
            Email.setPosition(50, 75);
            win.draw(Email);
            //registerr.setPosition(233, 530);
            registerr.setPosition(180, 500);
            win.draw(registerr);
            textLoginEmail.setPosition({ 210,76 });
            textLoginEmail.drawTo(win);
            // textLoginPassword.setPosition({ 269,237 });
            textLoginPassword.setPosition({ 325,237 });
            textLoginPassword.drawTo(win);
        }

        if (s == 2) {


            //Back.setPosition(233, 530);
            //window.draw(Back);
            Email.setPosition(15, 34);
            win.draw(Email);

            Password.setPosition(15, 198);
            win.draw(Password);

            backbutton.setPosition(1700, 100);
            win.draw(backbutton);

            Submit.setPosition(180, 500);
            win.draw(Submit);

            textRegisterEmail.setPosition({ 175, 35 });
            textRegisterEmail.drawTo(win);

            textRegisterPassword.setPosition({ 280,199 });
            textRegisterPassword.drawTo(win);

        }


        win.display();
    
        ///////////////////////////////////////////
        //reinitialize

    
      }
}