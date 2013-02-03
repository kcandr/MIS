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
        int userId = accessTable.getUserId(login);
    
		if ( accessTable.containsUser(login) ) {
			do {
                int obj;
				cout << "Введите операцию (read, write, change): ";
				cin >> operation;
				if ( operation == "read" ) {
					cout << "Объект: ";
					cin >> obj;
					int up = accessTable.getUserPermissionId(userId);
                    int op = accessTable.getObjectPermissionId(--obj);
					if ( up >= op )
						cout << "Отлично" << endl;
					else
						cout << "Доступ запрещён" << endl;
				} else if ( operation == "write" ) {
					cout << "Объект: ";
					cin >> obj;
                    int up = accessTable.getUserPermissionId(userId);
                    int op = accessTable.getObjectPermissionId(--obj);
					if ( up <= op ) {
						cout << "Отлично" << endl;
					} else {
						cout << "Доступ запрещён" << endl;
					}
				} else if ( operation == "change" ) {
					std::string permission;
					cout << "Уровень доступа: ";
					cin >> permission;

					int levelId = accessTable.getPermissionId(permission);
					accessTable.changePermissionTo(userId, levelId);
					cout << "Отлично" << endl;
				} else if ( operation == "quit" ) {
					break;
				}
			} while (1);
		} 
	} while(1);

    return 1;
}