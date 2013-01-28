#ifndef ACCESSTABLE_H
#define ACCESSTABLE_H

#include <string>
#include <vector>

enum users_t {
    ADMIN,
    USER_1,
    USER_2,
    USER_3,
    USER_4,
    GUEST
};

enum permission_t {
    FULL_PROHIBITION,
    TRANSFER,
    WRITE,
    WRITE_TRANSFER,
    READ,
    READ_TRANSFER,
    READ_WRITE,
    FULL_ACCESS
};

class AccessTable
{
public:
    AccessTable(void);
    AccessTable(int userC, int objectC);
    const std::string getPermissionForUserObject(const int user, const int object) const;
    void setPermissionForUserObject(const int user, const int object, const int permission);
    bool containsUser(const std::string userName);
    int getUserId(const std::string userName);
    ~AccessTable(void);

private:
    int userCount;
    int objectCount;
    int* table;
    std::vector<std::string> users;
    std::vector<std::string> permissions;

    void init();
};

#endif // ACCESSTABLE_H