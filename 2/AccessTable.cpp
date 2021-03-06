#include "AccessTable.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>

AccessTable::AccessTable(void) :
    userCount(0), objectCount(0)
{
}

AccessTable::AccessTable(int userC, int objectC) : 
    userCount(userC), objectCount(objectC)
{
	users.reserve(userCount);
	permissions.reserve(objectCount);
	table.reserve(userCount);
    init();
}

void AccessTable::init()
{
    users.push_back("admin");
    users.push_back("user1");
    users.push_back("user2");
    users.push_back("user3");
    users.push_back("user4");
    users.push_back("guest");

    permissions.push_back("FULL PROHIBITION");
    permissions.push_back("GRANT");
    permissions.push_back("WRITE");
    permissions.push_back("WRITE, GRANT");
    permissions.push_back("READ");
    permissions.push_back("READ, GRANT");
    permissions.push_back("READ, WRITE");
    permissions.push_back("FULL ACCESS");
	
	std::vector<int> tmp;
    for (int col = 0; col < objectCount; ++col) {
		tmp.push_back(FULL_ACCESS);
    }
	table.push_back(tmp);
	tmp.clear();

    for (int row = 1; row < userCount - 1; ++row) {
        for (int col = 0; col < objectCount; ++col) {
            tmp.push_back(rand() % (FULL_ACCESS + 1));
        }
		table.push_back(tmp);
		tmp.clear();
	}
	tmp.clear();

    for (int col = 0; col < objectCount; ++col) {
        if ( rand() % 2 == FULL_PROHIBITION ) {
            tmp.push_back(FULL_PROHIBITION);
        } else {
            tmp.push_back(READ);
        }
    }
	table.push_back(tmp);
}

std::string AccessTable::getPermissionString(const int user, const int object) const
{
    return permissions.at( table.at(user).at(object) );
}

int AccessTable::getPermissionId(const int user, const int object) const
{
	return table.at(user).at(object);
}

int AccessTable::getPermissionId(const std::string perm) const
{
	for (int i = 0; i < 8; ++i) {
		if ( permissions.at(i).compare(perm) == 0)
			return i;
	}
    return 0;
}

bool AccessTable::containsUser(const std::string userName)
{
    if( std::find(users.begin(), users.end(), userName) != users.end() ) {
        return true;
    } else {
        return false;
   } 
}

int AccessTable::getUserId(const std::string userName)
{
    for (int i = 0; i < userCount; ++i)
        if ( users.at(i) == userName)
            return i;
    return -1;
}

void AccessTable::setPermissionForUserObject(const int user, const int object, const int permission)
{
	table[user][object] |= permission;
}

void AccessTable::printInfo()
{
    std::cout << "       |  Object 1  |    Object 2   |   Object 3    |    Object 4   | Object 5 " << std::endl;
    for (int us = 0; us < userCount; ++us) {
        std::cout << users[us] << " ";
        for (int ob = 0; ob < objectCount; ++ob) {
            std::cout << std::setw(13) << getPermissionString(us, ob) << " | ";
        }
        std::cout << std::endl;
    }
}

bool AccessTable::havePermission(const int user, const int object, const int perm)
{
    int currentPerm = table.at(user).at(object);
    if ( perm == WRITE && (currentPerm == WRITE || currentPerm == WRITE_GRANT 
        || currentPerm == READ_WRITE || currentPerm == FULL_ACCESS) ) {
            return true;
    }
    if ( perm == READ && (currentPerm == READ || currentPerm == READ_GRANT 
        || currentPerm == READ_WRITE || currentPerm == FULL_ACCESS) ) {
            return true;
    }
    return false;
}

AccessTable::~AccessTable(void)
{
}
