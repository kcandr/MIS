#include "AccessTable.h"
#include <cstdlib>
#include <iostream>
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

    permissions.push_back("NONCONFIDENTIAL");
    permissions.push_back("CONFIDENTIAL");
    permissions.push_back("SECRET");
    permissions.push_back("TOP_SECRET");
	
    usersLevel.push_back(TOP_SECRET);
    for (int col = 1; col < userCount; ++col) {
		usersLevel.push_back(rand() % 4);
    }
    for (int col = 0; col < objectCount; ++col) {
        objectsLevel.push_back(rand() % 4);
    }
}

void AccessTable::printInfo()
{
    std::cout << "Users:\n";
    for (int i = 0; i < userCount; ++i) {
        std::cout << users[i] << " - " << permissions.at(usersLevel[i]) << std::endl;
    }
    std::cout << "\nObjects:\n";
    for (int i = 0; i < objectCount; ++i) {
        std::cout << "Object " << i + 1 << " - " << permissions.at(objectsLevel[i]) << std::endl;
    }
}

const int AccessTable::getUserPermissionId(const int userId) const
{
    return usersLevel.at(userId);
}

const int AccessTable::getObjectPermissionId(const int objectId) const
{
    return objectsLevel.at(objectId);
}

const int AccessTable::getPermissionId(const std::string level) const
{
    for (int i = 0; i < permissions.size(); ++i)
        if ( permissions.at(i) == level)
            return i;
    return -1;
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

void AccessTable::changePermissionTo(const int user, const int permission)
{
	usersLevel[user] = permission;
}

AccessTable::~AccessTable(void)
{
}
