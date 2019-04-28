// amy ghotra
// professor maryash
// csci 135 136
// lab 11a

#include <iostream>
using namespace std;

class Profile{
private:
    string username;
    string displayname;
public:
    Profile(string usrn, string dspn);
    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
};

Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname = dspn;
}

Profile::Profile()
{
    username = "";
    displayname = "";
}

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
    
    //return 0;
}

