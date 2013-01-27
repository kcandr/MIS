#ifndef ACCESSTABLE_H
#define ACCESSTABLE_H

enum users_t {
    ADMIN,
    USER_1,
    USER_2,
    USER_3,
    USER_4,
    GUEST
};

enum permission_t {
    FULL_PROHIBITION = 0000,
    TRANSFER = 0001,
    WRITE = 0010,
    WRITE_TRANSFER= 0011,
    READ = 0100,
    READ_TRANSFER = 0101,
    READ_WRITE = 0110,
    FULL_ACCESS = 0111
};

class AccessTable
{
public:
    AccessTable(void);
    AccessTable(int userC, int objectC);
    int getPermissionForUserObject(const int user, const int object) const;
    void setPermissionForUserObject(const int user, const int object, const int permission);
    ~AccessTable(void);

private:
    int userCount;
    int objectCount;
    int* table;

    void init();
};

#endif // ACCESSTABLE_H