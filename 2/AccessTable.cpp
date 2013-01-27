#include "AccessTable.h"
#include <cstdlib>

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
    for (int col = 0; col < objectCount; ++col) {
        table[ADMIN * objectCount + col] = 0111;
    }

    for (int row = 1; row < userCount; ++row)
        for (int col = 0; col < objectCount - 1; ++col) {
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

int AccessTable::getPermissionForUserObject(const int user, const int object) const
{
    return table[user * objectCount + object];
}

AccessTable::~AccessTable(void)
{
}
