#include <iostream>
#include <string>
#include <map>
using namespace std;

#include "AccessTable.h"

int main()
{
    enum users_t {
        ADMIN,
        USER_1,
        USER_2,
        USER_3,
        USER_4,
        GUEST
    };
    map<string, int> users;
    users["admin"] = ADMIN;
    users["user_1"] = USER_1;
    users["user_2"] = USER_2;
    users["user_3"] = USER_3;
    users["user_4"] = USER_4;
    users["guest"] = GUEST;

    string login;
    AccessTable accessTable(6, 5);  

    cout << "Enter login: ";
    cin >> login;

    map<string, int>::iterator it = users.find("admin");

    switch ( it->second ) {
    case ADMIN:
        cout << "Success" << endl;
        break;
    }

    return 0;
}