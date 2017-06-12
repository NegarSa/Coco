#include "login.h"

#include <Wt/WLabel>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WLengthValidator>
#include <Wt/WMessageBox>
#include <Wt/WCheckBox>

login::login(userList ul)
{
    Wt::WLineEdit *unamele = new Wt::WLineEdit();
    unamele->setPlaceholderText("your username");

    Wt::WLineEdit *passle = new Wt::WLineEdit();
    passle->setPlaceholderText("your password");

    Wt::WPushButton *submit = new Wt::WPushButton("submit");

    submit->clicked().connect(std::bind([=] ()
    {
        if(validateUN(ul ,unamele->text()))
        {
            if(validatelogin(ul ,unamele->text().toUTF8() , passle->text().toUTF8()))
            {
                //go to page....... Mahya
            }
            else{
                Wt::WMessageBox::show("error","your password is incorrect, try again",Wt::Ok);
            }
        }
        else Wt::WMessageBox::show("error","<p>there is no member with this username</p> "
                                           "<p>if you are new here, make a new acount</p>" ,Wt::Ok);
    }));
}

