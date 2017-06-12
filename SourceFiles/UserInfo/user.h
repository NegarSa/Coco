#pragma once
#ifndef USER_H
#define USER_H

#endif // USER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Wt/WImage>
//#include <Wt/WResource>
#include <Wt/WFileResource>
#include <vector>

#include <boost/filesystem.hpp>


using namespace std;

class User
{
    string name;     //size 50
    string userName; //size 50
    string pass;     //size 20
    string email;    //size 100
   // Wt::WFileResource image;
    int posts;
    vector<string> followers;
    vector<string> followings;
    bool active;


public:
    friend class userList;
    friend class followersListWidget;
    friend class followingsListWidget;

    void setName (string a) { name = a;}
    string getName () {return name;}
    void setUname (string a) { userName = a;} //validate before
    string getUName () {return userName;}
    void setPass (string a) {pass = a;}
    string getPass () {return pass;}

   // void setImage (Wt::WResource a) {image.setResource(a);}

//    User* find(int )
    User(int post , string name, string username, string pass, string email);
    User(const User &x);
    User();

};

class userList
{
    vector<User> users;

public:
    userList();
    bool validateUN (string un);
    bool validatelogin(string un , string pass);
    bool addUser(string , string , string , string em,int id = 0);

    User* findByUName(string un);
    void update();
    bool addfollower(string follower ,string following);
    bool findFollow(string follower, string following);
    bool unfollow(string follower , string following);

    bool changePass(string un ,string newpass);
    bool changeName(string un , string newname);
    bool changeUName(string un , string newun);
    bool deleteAcount(string un);

    userList constcast();

    vector<string> Usearch(string key);
};


bool validateUN (const userList ul, Wt::WString un);
bool validatelogin(userList ul, Wt::WString un, Wt::WString pass);
bool addUser(const userList &ul, Wt::WString , Wt::WString , Wt::WString , Wt::WString em, int id = 0);
bool changePass(const userList &ul ,string un ,string newpass);
bool changeName(const userList &ul ,string un , string newname);
bool changeUName(const userList &ul ,string un , string newun);
bool deleteAcount(const userList &ul , string un);

