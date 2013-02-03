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
		cout << "������� �����: ";
		cin >> login;
        int userId = accessTable.getUserId(login);
    
		if ( accessTable.containsUser(login) ) {
			do {
                int obj;
				cout << "������� �������� (read, write, change): ";
				cin >> operation;
				if ( operation == "read" ) {
					cout << "������: ";
					cin >> obj;
					int up = accessTable.getUserPermissionId(userId);
                    int op = accessTable.getObjectPermissionId(--obj);
					if ( up >= op )
						cout << "�������" << endl;
					else
						cout << "������ ��������" << endl;
				} else if ( operation == "write" ) {
					cout << "������: ";
					cin >> obj;
                    int up = accessTable.getUserPermissionId(userId);
                    int op = accessTable.getObjectPermissionId(--obj);
					if ( up <= op ) {
						cout << "�������" << endl;
					} else {
						cout << "������ ��������" << endl;
					}
				} else if ( operation == "change" ) {
					std::string permission;
					cout << "������� �������: ";
					cin >> permission;

					int levelId = accessTable.getPermissionId(permission);
					accessTable.changePermissionTo(userId, levelId);
					cout << "�������" << endl;
				} else if ( operation == "quit" ) {
					break;
				}
			} while (1);
		} 
	} while(1);

    return 1;
}