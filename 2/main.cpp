#include <iostream>
using namespace std;

#include "AccessTable.h"

int main()
{
    AccessTable accessTable(6, 5);
    string login;
    string operation;
	do {
		cout << "Enter login: ";
		cin >> login;
    
		if ( accessTable.containsUser(login) ) {
			int userId = accessTable.getUserId(login);
			cout << "Success. Your permissions: " << endl;
			for (int obj = 0; obj < 5; ++obj) {
				string perm = accessTable.getPermissionString(userId, obj);
				cout << "Object " << obj + 1 << ": " << perm << endl;
			}
			do 
			{
				int obj;
				cout << "Enter operation: ";
				cin >> operation;
				if ( operation == "read" ) {
					cout << "Object: ";
					cin >> obj;
					int k = accessTable.getPermissionId(userId, --obj);
					if ( k >= READ && k <= FULL_ACCESS )
						cout << "Success" << endl;
					else
						cout << "Access denied" << endl;
				} else if ( operation == "write" ) {
					cout << "Object: ";
					cin >> obj;
					int k = accessTable.getPermissionId(userId, --obj);
					if ( k == WRITE || k == WRITE_GRANT || k == READ_WRITE || k == FULL_ACCESS) {
						cout << "Success" << endl;
					} else {
						cout << "Access denied" << endl;
					}
				} else if ( operation == "grant" ) {
					cout << "Object: ";
					cin >> obj;
					int k = accessTable.getPermissionId(userId, --obj);
					if ( k == GRANT || k == WRITE_GRANT || k == READ_GRANT || k == FULL_ACCESS) {
						std::string user;
						std::string permission;
						cout << "Permission: ";
						cin >> permission;
						int permissionId = accessTable.getPermissionId(permission);
						cout << "User: ";
						cin >> user;
						int userId = accessTable.getUserId(user);

						accessTable.setPermissionForUserObject(userId, obj, permissionId);
						cout << "Success" << endl;
					} else {
						cout << "Access denied" << endl;
					}
				} else if ( operation == "quit" ) {
					break;
				}
			} while (1);
		} 
	} while(1);

    return 1;
}