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
    GRANT,
    WRITE,
    WRITE_GRANT,
    READ,
    READ_GRANT,
    READ_WRITE,
    FULL_ACCESS
};

class AccessTable
{
public:
    AccessTable(void);
    AccessTable(int userC, int objectC);
    std::string getPermissionString(const int user, const int object) const;
	int getPermissionId(const int user, const int object) const;
    int getPermissionId(const std::string perm) const;
	void setPermissionForUserObject(const int user, const int object, const int permission);
    bool containsUser(const std::string userName);
    int getUserId(const std::string userName);
    ~AccessTable(void);

private:
    int userCount;
    int objectCount;
	std::vector<std::vector<int> > table;
    std::vector<std::string> users;
    std::vector<std::string> permissions;

    void init();
};

#endif // ACCESSTABLE_H