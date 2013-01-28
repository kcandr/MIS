#include "AccessTable.h"
#include <cstdlib>
#include <algorithm>

AccessTable::AccessTable(void) :
    userCount(0), objectCount(0)
{
}

AccessTable::AccessTable(int userC, int objectC) : 
    userCount(userC), objectCount(objectC)
{
    table = new int(userCount * objectCount);
    init();
}

void AccessTable::init()
{
    users.push_back("admin");
    users.push_back("user_1");
    users.push_back("user_2");
    users.push_back("user_3");
    users.push_back("user_4");
    users.push_back("guest");

    permissions.push_back("FULL PROHIBITION");
    permissions.push_back("TRANSFER");
    permissions.push_back("WRITE");
    permissions.push_back("WRITE, TRANSFER");
    permissions.push_back("READ");
    permissions.push_back("READ, TRANSFER");
    permissions.push_back("READ, WRITE");
    permissions.push_back("FULL ACCESS");

    for (int col = 0; col < objectCount; ++col) {
        table[ADMIN * objectCount + col] = FULL_ACCESS;
    }

    for (int row = 1; row < userCount - 1; ++row)
        for (int col = 0; col < objectCount; ++col) {
            table[row * objectCount + col] = rand() % userCount + 1 ;
        }

    for (int col = 0; col < objectCount; ++col) {
        if ( rand() % 2 == FULL_PROHIBITION ) {
            table[GUEST * objectCount + col] = FULL_PROHIBITION;
        } else {
            table[GUEST * objectCount + col] = READ;
        }
    }
}

const std::string AccessTable::getPermissionForUserObject(const int user, const int object) const
{
    return permissions.at( table[user * objectCount + object] );
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

AccessTable::~AccessTable(void)
{
}
