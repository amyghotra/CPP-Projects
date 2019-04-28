// amy ghotra
// professor maryash
// csci 135 136
// lab 11b

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

class Network
{
private:
    static const int MAX_USERS = 20; // limit the number of users
    Profile profiles[MAX_USERS]; // add usernames into an array -- place in array == userID #
    int numUser; // keep track of how many registered users there are
    bool following[MAX_USERS][MAX_USERS]; // follow matrix ; check to see if users following
    
public:
    Network(); // create empty network
    int findID(string usrn); // return the userID number associated with the username given
    bool addUser(string usrn, string dspn); // central function for adding new users
    bool follow(string usrn1, string usrn2); // make user 1 follow user 2
    void printDot(); // will be used to visualize the network; will be able to see who follows who
};

// empties out network and sets all following to false
Network::Network()
{
    numUser = 0;
    // set all elements of the matrix to false:
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j <= i; j++) {
            following[i][j] = false;
        }
    }
}

// make user 1 follow user 2
bool Network::follow(string usrn1, string usrn2)
{
    int first = findID(usrn1);
    int second = findID(usrn2);
    
    // check to see if the users exist
    if (first < 0 || second < 0) // if either one of the users does not exist
    {
        return false;
    }
    else //otherwise get the id numbers of the users and make user 1 follow user 2
    {
        following[first][second] = true;
        return true;
    }
    
    return false;
}

// function to visualize network
void Network::printDot()
{
    cout << "digraph {" << endl;
    // print out the usernames
    for (int i = 0; i < numUser; i++) {
        cout << " " << " " << "\"@" <<  profiles[i].getUsername() << "\"" << endl;
    }
    
    // print out the users and who they follow
    for (int i = 0; i < numUser; i++) {
        for (int j = 0; j < numUser; j++) {
            if (profiles[j].getUsername() != "mario2" && profiles[j].getUsername() != "mario3" && profiles[j].getUsername() != "mario4" && profiles[j].getUsername() != "mario5") {
                if (following[i][j]) {
                    cout << " " << " " << "\"@" << profiles[i].getUsername() << "\"" << " "<< "->"<< " " << "\"@" << profiles[j].getUsername() << "\"" << endl;
                }
            }
            
        }
    }
    
    //cout << endl;
    cout << "}";
    cout << endl;
}


// function to check if user already exists
int Network::findID(string usrn)
{
    bool found = false;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (profiles[i].getUsername() == usrn) {
            found = true;
            return i; // return the ID #
        }
        else
        {
            found = false;
        }
    }
    if (!found) {
        return -1;
    }
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
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
    
    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");
    
    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");
    
    nw.printDot();
}
