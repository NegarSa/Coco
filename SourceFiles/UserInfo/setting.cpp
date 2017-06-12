
#include "user.h"

#include <Wt/WPushButton>
#include <Wt/WString>
#include <Wt/WMessageBox>

bool badchars (string a);

class settingWidget
{
public:
    settingWidget(userList ul, string un)
    {
        Wt::WPushButton *changeN = new Wt::WPushButton();
        changeN->clicked().connect(std::bind([=]
        {
            // get newn wstring
            Wt::WString newn;
            if(newn.toUTF8().size() < 50 &&newn.toUTF8().size() > 2)
            {
                if(!changeName(ul ,un , newn.toUTF8()))
                {
                    Wt::WMessageBox::show("error","an error accured while changeing name,please try again",Wt::Ok);
                }
                else
                {
                    Wt::WMessageBox::show("success","your name changed successfully",Wt::Ok);
                }
            }
            else
            {
                Wt::WMessageBox::show("error","your new name is invalid ,please try again",Wt::Ok);
            }
        }));

        Wt::WPushButton *changePa = new Wt::WPushButton();
        changePa->clicked().connect(std::bind([=]
        {
            // get newun wstring
            Wt::WString newun;
            if(newun.toUTF8().size() < 50 && newun.toUTF8().size() > 2 && !badchars(newun.toUTF8()))
            {
                if(validateUN(ul ,newun))
                {
                    if(!changeUName(ul ,un , newun.toUTF8()))
                    {
                        Wt::WMessageBox::show("error","an error accured while changeing username"
                                                      ",please try again",Wt::Ok);
                    }
                    else
                    {
                        Wt::WMessageBox::show("success","your username changed successfully",Wt::Ok);
                    }
                }
                else
                {
                    Wt::WMessageBox::show("error","this username is used before",Wt::Ok);
                }
            }
            else
            {
                Wt::WMessageBox::show("error","<p>your new username is invalid ,please try again</p>"
                                              "<p>your username should be between 3-50 characters and "
                                              "you must not use space ,*,/,<,',? and ! in your username</p>",Wt::Ok);
            }
        }));

        Wt::WPushButton *changeUN = new Wt::WPushButton();
        changeUN->clicked().connect(std::bind([=]
        {
            Wt::WString newpa;
            if(newpa.toUTF8().size() < 50 &&newpa.toUTF8().size() > 2)
            {
                if(!changePass(ul ,un , newpa.toUTF8()))
                {
                    Wt::WMessageBox::show("error","an error accured while changeing password"
                                                  ",please try again",Wt::Ok);
                }
                else
                {
                    Wt::WMessageBox::show("success","your password changed successfully",Wt::Ok);
                }
            }
            else
            {
                Wt::WMessageBox::show("error","your new pass is invalid ,please try again",Wt::Ok);
            }
        }));

        Wt::WPushButton *deleteAc = new Wt::WPushButton();
        deleteAc->clicked().connect(std::bind([=]
        {
            // chejoori begam motameni?????????? khodet dorostesh koooon ... Mahya
            if(!deleteAcount(ul ,un))
            {
                Wt::WMessageBox::show("error","an error accured while deleting acount"
                                              ",please try again",Wt::Ok);
            }
            else
            {
                Wt::WMessageBox::show("success","your password changed successfully",Wt::Ok);

                // boro be safe avaaaaal ... Mahya
            }
        }));
    }
};
