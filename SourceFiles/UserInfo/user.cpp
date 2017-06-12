//#include <iostream>
#include "user.h"
#include <algorithm>

User::User(int post, string n , string un , string pa, string em)
{
    name = n;
   // name.resize(50);
    userName = un;
   // userName.resize(50);
    pass = pa;
   // pass.resize(30);
    //image = 0;
    email = em;
   // email.resize(100);
    posts = post;
    active = true;
}

User::User(const User &x)
{

    name = x.name;
    userName  = x.userName;
    pass = x.pass;
    //image.setResource( x.image.resource());
    email = x.email;
    followers = x.followers;
    followings = x.followings;
    active = x.active;
    posts = x.posts;
}

User::User()
{
    posts = 0;
  name = "";
  userName = "";
  pass = "";
  email = "";
}


bool userList::validateUN(string un)
{
    try{
      for (auto i : userList::users)
      {
        if (i.userName == un) return false;
      }
      return true;
    }
    catch(...)
    {
        return false;
    }
}


bool validateUN(const userList ul ,Wt::WString un)
{
    string a= un.toUTF8();
    userList ul2 = ul;
    return ul2.validateUN(a);
}


bool userList::validatelogin(string un, string pass)
{
    try{
        for(auto i: userList::users)
        {
            if(i.userName == un)
            {
                if(i.pass == pass) return true;
                else return false;
            }
        }
        return false;
    }
    catch(...)
    {
        return false;
    }
}

bool validatelogin(const userList ul ,Wt::WString un, Wt::WString pass)
{
    userList &ul2 = const_cast<userList&>(ul);
    return ul2.validatelogin(un.toUTF8() , pass.toUTF8());
}

bool userList::addUser(string n, string un, string pa , string em, int post)
{
    try
    {
        if(validateUN(un))
        {
            User *x = new User(post ,n , un , pa , em);
            userList::users.push_back(*x);
            update();
            return true;
        }
        else return false;
    }
    catch(...)
    {
        return false;
    }
}

bool addUser(const userList &ul , Wt::WString n, Wt::WString un, Wt::WString pa, Wt::WString em, int post)
{
    userList &ul2 = const_cast<userList&>(ul);
    return ul2.addUser(n.toUTF8(), un.toUTF8() , pa.toUTF8() , em.toUTF8() ,post);
}

User * userList::findByUName(string un)
{
    for (int i = 0 ; i < users.size() ; i++)
    {
      if (users[i].userName == un) return &users[i];
    }
  User *x = new User;
  return x;
}

bool userList::addfollower(string follower, string following)
{
  if (!validateUN(follower) && !validateUN(following))
  {
    if (follower == following) return false;
    if (findFollow(follower , following)) return false;
    User *x = findByUName(follower);
    User *y = findByUName(following);
    x->followings.push_back(following);
    y->followers.push_back(follower);
    update();
    return true;
  }
  return false;
}

bool userList::findFollow(string follower, string following)
{
  User *x = findByUName(follower);
  for (auto i : x->followings)
  {
    if (i == following) return true;
  }
  return false;
}

bool userList::unfollow(string follower, string following)
{
    if(findFollow(follower, following))
    {
        if (!validateUN(follower) && !validateUN(following))
        {
           User *x = findByUName(follower);
           User *y = findByUName(following);
           for (int i = 0 ; i < x->followings.size() ; i++)
           {
             if (x->followings[i] == following)
                 x->followings.erase(x->followings.begin()+i , x->followings.begin()+i+1);
           }
           for (int i = 0 ; i < y->followers.size() ; i++)
           {
               if (y->followers[i] == follower)
                   y->followers.erase(y->followers.begin()+i , y->followers.begin()+i+1);
           }
        }
    }
}

bool userList::changePass(string un, string newpass)
{
    User *x = findByUName(un);    //try catch benevis age nashod false bede
    x->pass = newpass;
    update();
    return true;
}

bool userList::changeName(string un, string newname)
{
    User *x = findByUName(un);    //try catch benevis age nashod false bede
    x->name = newname;
    update();
    return true;
}

bool userList::changeUName(string un, string newun)
{
    User *x = findByUName(un);      //try catch benevis age nashod false bede
    x->pass = newun;
    update();
    return true;
}

bool userList::deleteAcount(string un)
{
    for(int i = 0 ; i < users.size() ; i++)
    {
        if(users[i].userName == un)
        {
            for(auto j: users[i].followers)
            {
                unfollow(j,users[i].userName);
            }
            for(auto j: users[i].followings)
            {
                unfollow(users[i].userName , j);
            }
            users.erase(users.begin()+i , users.begin()+i +1);
            update();
            return true;
        }
    }
    return false;
}

vector<string> userList::Usearch(string key)
{
    vector<string> ulist;
    for(auto i:users)
    {
        string a = i.userName;
        a.resize(key.size());
        if(a == key) ulist.push_back(i.userName);
    }
    sort(ulist.begin(),ulist.end());
    return ulist;
}





bool changePass(const userList &ul, string un, string newpass)
{
    userList &ul2 = const_cast<userList&>(ul);
    return ul2.changePass(un , newpass);
}

bool changeName(const userList &ul, string un, string newname)
{
    userList &ul2 = const_cast<userList&>(ul);
    return ul2.changeName(un , newname);
}

bool changeUName(const userList &ul, string un, string newun)
{
    userList &ul2 = const_cast<userList&>(ul);
    return ul2.changeUName(un , newun);
}

bool deleteAcount(const userList &ul, string un)
{
    userList &ul2 = const_cast<userList&>(ul);
    return ul2.deleteAcount(un);
}
