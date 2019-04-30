/*
    amy ghotra
    social media 2/3
*/

#include <iostream>
using namespace std;

// create class to store basic user information (see SocialMedia1.cpp)
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

// create class to store all users
class Network
{
private:
    static const int MAX_USERS = 20; // set a limit of # users
    Profile profiles[MAX_USERS]; // add usernames into an array
    int numUser; // keep track of how many registered users there are
    
public:
    Network(); // create empty network
    int findID(string usrn); // return the userID associated with the username given
    bool addUser(string usrn, string dspn); // central function for adding new users
};

// makes empty network
Network::Network()
{
    numUser = 0;
}


// function to check if user already exists
int Network::findID(string usrn)
{
    //cout << "Find id called" << endl;
    bool found = false;
    for (int i = 0; i < MAX_USERS; i++)
    {
        //cout << "i: " << i << endl;
        if (profiles[i].getUsername() == usrn) {
            //cout << "inside if" << endl;
            found = true;
            return i; // return the ID #
        }
        else
            //cout << "inside else" << endl;
        {
            found = false;
        }
    }
    if (!found) {
        //cout << "not found" << endl;
        return -1;
    }
    //cout << "at final section" << endl;
    return -1;
}

// function for adding users to array
bool Network::addUser(string usrn, string dspn)
{
    
    int exist = findID(usrn);
    //bool exists = false;
    bool signedUp = false;
    bool passable = false;
    if (usrn.length() == 0) // if the username is empty
    {
        return false;
    }
    else
    {
        // if the user does not already exist
        if (exist < 0) {
            //cout << "Exist < 0" << endl;
            // check to see if username containts only alphabetic and numeric charcters
            for (int i = 0;  i < usrn.length(); i++)
            {
                // if the username contains acceptable characters
                if ((int(usrn[i]) > 47 && int(usrn[i]) < 58) || (int(usrn[i]) > 64 && int(usrn[i]) < 91) || (int(usrn[i]) > 96 && int(usrn[i]) < 123))
                {
                    passable = true; // containts acceptable characters
                }
                // if the username does not contain acceptable chars
                else
                {
                    passable = false; // does not contain acceptable characters
                    return false;
                }
            }
        }
        // if the user already exists
        else if (exist >= 0)
        {
            return false;
        }
    }
    // if username contains appropriate characters
    if (passable) {
        // if array is not full
        if (numUser <= 19)
        {
            Profile new_user(usrn, dspn); // add user name and displayname to Profile
            profiles[numUser] = new_user; // add username to the array of registered users
            numUser++; // keep track of how many users there are
            signedUp = true;
            return true;
        }
        // if there is no more space in the array then the user cannot sign up
        else if (numUser > 19)
        {
            signedUp = false;
            return false;
        }
    }
    return true;
}



int main()
{
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)
    
    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)
    
    for(int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i),
                           "Mario" + to_string(i)) << endl;   // true (1)
    
    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
