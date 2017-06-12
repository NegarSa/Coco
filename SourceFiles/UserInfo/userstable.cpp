#include "user.h"

#include <Wt/WPushButton>
#include <Wt/WVBoxLayout>
#include <Wt/WContainerWidget>

class followersListWidget
{
public:
    followersListWidget(userList ul , string un)
    {
        Wt::WContainerWidget *container = new Wt::WContainerWidget();
        Wt::WVBoxLayout *lay = new Wt::WVBoxLayout();
        User *x = ul.findByUName(un);
        int size = x->followers.size();
        Wt::WPushButton *followers = new Wt::WPushButton[size];
        for(int i = 0; i < size; i++)
        {
            followers[i].setText(x->followers[i]);
        }
        for(int i = 0; i < size; i++)
        {
            container->addWidget(&followers[i]);
        }
        lay->addWidget(container);
        for(int i = 0; i < size; i++)
        {
            followers[i].clicked().connect(std::bind([=]
            {
                // go to followers page .... Mahya
            }));
        }
    }
};

class followingsListWidget
{
public:
    followingsListWidget(userList ul , string un)
    {
        Wt::WContainerWidget *container = new Wt::WContainerWidget();
        Wt::WVBoxLayout *lay = new Wt::WVBoxLayout();
        User *x = ul.findByUName(un);
        int size = x->followings.size();
        Wt::WPushButton *followings = new Wt::WPushButton[size];
        for(int i = 0; i < size; i++)
        {
            followings[i].setText(x->followings[i]);
        }
        for(int i = 0; i < size; i++)
        {
            container->addWidget(&followings[i]);
        }
        lay->addWidget(container);
        for(int i = 0; i < size; i++)
        {
            followings[i].clicked().connect(std::bind([=]
            {
                // go to followings page .... Mahya
            }));
        }
    }
};
