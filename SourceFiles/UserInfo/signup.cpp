#include "login.h"

#include <Wt/WLabel>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WLengthValidator>
#include <Wt/WMessageBox>
#include <Wt/WCheckBox>

bool badchars (string a)
{
    for(int i = 0 ; i < a.size() ; i++)
    {
        if(a[i] == '*'|| a[i] == '/' || a[i] == '\\' || a[i] == '"' || a[i] == '?' || a[i] == '|' ||
                a[i] == '!' ||a[i] == '>' || a[i] == '<' || a[i] == ' ')
        {
            return true;
        }
    }
    return false;
}

signup::signup(userList ul)
{
    Wt::WLengthValidator *nvalidator = new Wt::WLengthValidator(3,50);
    Wt::WLengthValidator *pvalidator = new Wt::WLengthValidator(3,20);
    Wt::WLineEdit *namele = new Wt::WLineEdit();
    namele->setPlaceholderText("your name");
    namele->setValidator(nvalidator);

    Wt::WLineEdit *unamele = new Wt::WLineEdit();
    unamele->setPlaceholderText("your username");
    unamele->setValidator(nvalidator);

    Wt::WLineEdit *passle = new Wt::WLineEdit();
    passle->setPlaceholderText("your password");
    passle->setValidator(pvalidator);

    Wt::WLineEdit *emaille = new Wt::WLineEdit();
    emaille->setPlaceholderText("your name");

    Wt::WCheckBox *accept = new Wt::WCheckBox("I accept the agreement");

    Wt::WPushButton *submit = new Wt::WPushButton("submit");
    //Wt::WMessageBox *msg = new Wt::WMessageBox();

    submit->clicked().connect(std::bind([=]()
    {
        if(namele->validate() != Wt::WValidator::Valid)
        {
            Wt::WMessageBox::show("error","your name should be between 3-50 characters",Wt::Ok |Wt::Cancel);
            //msg->show;
        }
        else if(unamele->validate() != Wt::WValidator::Valid && badchars(unamele->text().toUTF8()))
        {
            Wt::WMessageBox::show("error","your username should be between 3-50 characters"
                                          "and you must not use space ,*,/,<,',? and ! in your username",Wt::Ok);
        }
        else if(validateUN(ul ,unamele->text()))
        {
            Wt::WMessageBox::show("error","this username is used before",Wt::Ok);
        }
        else if(passle->validate() != Wt::WValidator::Valid)
        {
            Wt::WMessageBox::show("error","your name should be between 3-50 characters",Wt::Ok);
        }
        else if(emaille->text().empty())
        {
             Wt::WMessageBox::show("error","email address requierd",Wt::Ok);
        }
        else if(!accept->isChecked())
        {
            Wt::WMessageBox::show("error","you must accept the agreement",Wt::Ok);
        }
        else
        {
            addUser(ul ,namele->text(), unamele->text(), passle->text(), emaille->text());
            Wt::WMessageBox::show("success","you registered successfully now sign in to your acount",Wt::Ok);

        }
    }));
}
