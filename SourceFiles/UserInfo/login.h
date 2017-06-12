#ifndef LOGIN_H
#define LOGIN_H
#include <Wt/WContainerWidget>
#include "user.h"


class login : public Wt::WContainerWidget
{
public:
    login(userList ul);
};

class signup : public Wt::WContainerWidget
{
public:
    signup(userList ul);


};
#endif // LOGIN_H
