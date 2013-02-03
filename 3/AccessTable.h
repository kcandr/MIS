#ifndef ACCESSTABLE_H
#define ACCESSTABLE_H

#include <string>
#include <vector>

enum level_t {
    NONCONFIDENTIAL, 
    CONFIDENTIAL, 
    SECRET, 
    TOP_SECRET
};

class AccessTable
{
public:
    AccessTable(void);
    AccessTable(int userC, int objectC);
    const int getUserPermissionId(const int userId) const;
    const int getObjectPermissionId(const int objectId) const;
    const int getPermissionId(const std::string level) const;
	void changePermissionTo(const int user, const int permission);
    bool containsUser(const std::string userName);
    int getUserId(const std::string userName);
    void printInfo();
    ~AccessTable(void);

private:
    int userCount;
    int objectCount;
	std::vector<int> usersLevel;
    std::vector<int> objectsLevel;
    std::vector<std::string> users;
    std::vector<std::string> permissions;

    void init();
};

#endif // ACCESSTABLE_H