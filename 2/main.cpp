#include <iostream>
using namespace std;

#include "AccessTable.h"

int main()
{
	setlocale(LC_ALL, "Russian");
    AccessTable accessTable(6, 5);
    string login;
    string operation;
    accessTable.printInfo();

	do {
		cout << "Введите логин: ";
		cin >> login;
    
		if ( accessTable.containsUser(login) ) {
			int userId = accessTable.getUserId(login);
			cout << "Отлично. Ваши права: " << endl;
			for (int obj = 0; obj < 5; ++obj) {
				string perm = accessTable.getPermissionString(userId, obj);
				cout << "Object " << obj + 1 << ": " << perm << endl;
			}
			do 
			{
				int obj;
				cout << "Введите операцию (read, write, grant): ";
				cin >> operation;
				if ( operation == "read" ) {
					cout << "Объект: ";
					cin >> obj;
					int k = accessTable.getPermissionId(userId, --obj);
					if ( k >= READ && k <= FULL_ACCESS )
						cout << "Отлично" << endl;
					else
						cout << "Доступ запрещён" << endl;
				} else if ( operation == "write" ) {
					cout << "Объект: ";
					cin >> obj;
					int k = accessTable.getPermissionId(userId, --obj);
					if ( k == WRITE || k == WRITE_GRANT || k == READ_WRITE || k == FULL_ACCESS) {
						cout << "Отлично" << endl;
					} else {
						cout << "Доступ запрещён" << endl;
					}
				} else if ( operation == "grant" ) {
					cout << "Объект: ";
					cin >> obj;
					int k = accessTable.getPermissionId(userId, --obj);
					if ( k == GRANT || k == WRITE_GRANT || k == READ_GRANT || k == FULL_ACCESS) {
						std::string user;
						std::string permission;
						cout << "Право: ";
						cin >> permission;
						int permissionId = accessTable.getPermissionId(permission);
						cout << "Пользователь: ";
						cin >> user;
						int userId = accessTable.getUserId(user);

						accessTable.setPermissionForUserObject(userId, obj, permissionId);
						cout << "Отлично" << endl;
					} else {
						cout << "Доступ запрещён" << endl;
					}
				} else if ( operation == "quit" ) {
					break;
				}
			} while (1);
		} 
	} while(1);

    return 1;
}