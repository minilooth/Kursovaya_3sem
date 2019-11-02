#include "UserCredentials.h"

UserCredentials::UserCredentials() = default;

UserCredentials::UserCredentials(string username, string password, bool adminAccess)
{
    username_ = username;
    password_ = password;
    adminAccess_ = adminAccess;
}

void UserCredentials::setUsername(string username)
{
    username_ = username;
};

void UserCredentials::setPassword(string password)
{
    password_ = password;
}

void UserCredentials::setAdminAccess(bool adminAccess)
{
    adminAccess_ = adminAccess;
}

string UserCredentials::getUsername()
{
    return username_;
}

string UserCredentials::getPassword()
{
    return password_;
}

bool UserCredentials::getAdminAccess()
{
    return adminAccess_;
}

UserCredentials::~UserCredentials() = default;