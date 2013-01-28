#include <iostream>
using namespace std;

#include "AccessTable.h"

int main()
{
    AccessTable accessTable(6, 5);
    string login;
    string operation;

    cout << "Enter login: ";
    cin >> login;
    
    if ( accessTable.containsUser(login) ) {
        int userId = accessTable.getUserId(login);
        cout << "Success. Your permissions: " << endl;
        for (int obj = 0; obj < 5; ++obj) {
            string perm = accessTable.getPermissionForUserObject(userId, obj);
            cout << "Object " << obj + 1 << ": " << perm << endl;
        }
        do 
        {
            cout << "Enter operation: ";
            cin >> operation;
            if ( operation == "read" ) {
                //
            } else if ( operation == "write" ) {
                //
            } else if ( operation == "grant" ) {
                //
            } else if ( operation == "quit" ) {
                //
            }
        } while (1);
    }

    return 1;
}