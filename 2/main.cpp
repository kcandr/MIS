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
    
		if ( accessTable.containsUser(login) ) {
			int userId = accessTable.getUserId(login);
			cout << "�������. ���� �����: " << endl;
			for (int obj = 0; obj < 5; ++obj) {
				string perm = accessTable.getPermissionString(userId, obj);
				cout << "Object " << obj + 1 << ": " << perm << endl;
			}
			do 
			{
				int obj;
				cout << "������� �������� (read, write, grant): ";
				cin >> operation;
				if ( operation == "read" ) {
					cout << "������: ";
					cin >> obj;
					int k = accessTable.getPermissionId(userId, --obj);
					if ( k >= READ && k <= FULL_ACCESS )
						cout << "�������" << endl;
					else
						cout << "������ ��������" << endl;
				} else if ( operation == "write" ) {
					cout << "������: ";
					cin >> obj;
					int k = accessTable.getPermissionId(userId, --obj);
					if ( k == WRITE || k == WRITE_GRANT || k == READ_WRITE || k == FULL_ACCESS) {
						cout << "�������" << endl;
					} else {
						cout << "������ ��������" << endl;
					}
				} else if ( operation == "grant" ) {
					cout << "������: ";
					cin >> obj;
					int k = accessTable.getPermissionId(userId, --obj);
					if ( k == GRANT || k == WRITE_GRANT || k == READ_GRANT || k == FULL_ACCESS) {
						std::string user;
						std::string permission;
						cout << "�����: ";
						cin >> permission;
						int permissionId = accessTable.getPermissionId(permission);
						cout << "������������: ";
						cin >> user;
						int userId = accessTable.getUserId(user);

						accessTable.setPermissionForUserObject(userId, obj, permissionId);
						cout << "�������" << endl;
					} else {
						cout << "������ ��������" << endl;
					}
				} else if ( operation == "quit" ) {
					break;
				}
			} while (1);
		} 
	} while(1);

    return 1;
}