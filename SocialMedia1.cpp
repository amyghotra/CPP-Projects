/*
    amy ghotra
    social media 1/3
*/

#include <iostream>
using namespace std;

// create class profile which will store basic user information
class Profile{
private:
    string username; // store username
    string displayname; // store displayname / user's actual name
public:
    Profile(string usrn, string dspn);
    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
};

// assign and save username and displayname
Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname = dspn;
}

// defauly member function
// resets everything to null / empty
Profile::Profile()
{
    username = "";
    displayname = "";
}

// simply returns the username
string Profile::getUsername()
{
    return username;
}

void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}

string Profile::getFullName()
{
    string name = displayname + "(@" +username + ")";
    return name;
}


int main()
{
    Profile p1("marco", "Marco");
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)
    
    p1.setDisplayName("Marco Rossi");
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
    
}

