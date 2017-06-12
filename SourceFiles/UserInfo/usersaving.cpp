
#include "user.h"
#include <fstream>
#include <sstream>

userList::userList()
{
  ifstream in;
  in.open("users.txt", std::ios::in);
  int m = 0, n = 0, q = 0;
  //stringstream ss;
  string a;
  while (getline(in , a))
  {
    User *x = new User;
    x->name = a;
    getline(in ,a);
    x->userName = a;
    getline(in ,a);
    x->pass = a;
    getline(in ,a);
    x->email =a;
    getline(in ,a);
    stringstream ss;
    ss << a;
    ss >> x->posts >> q >> m >> n;
    x->active = q;
    for (int i = 0; i < m; i++)
    {
        getline(in ,a);
        x->followers.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        getline(in ,a);
      x->followings.push_back(a);
    }
    users.push_back(*x);
  }
  in.close();
}
void userList::update()
{
  ofstream out;
  out.open("users.txt", std::ios::out);
  //out.write((char*)&users, sizeof(users));
  //User &x = users[users.size() - 1];
  for (auto x : users) {
    out << x.getName() << "\n" << x.getUName() << "\n" << x.getPass() << "\n";
    out << x.email << "\n" << x.posts << " " << (bool)x.active <<" " ;
    out << x.followers.size() << " " << x.followings.size();
    for (auto i : x.followers)
    {
      out <<"\n"<< i;
    }
    for (auto i : x.followings)
    {
      out << "\n" << i ;
    }
    out << "\n";
  }

  out.close();
}


