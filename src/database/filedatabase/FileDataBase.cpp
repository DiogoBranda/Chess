/**
 * Author: Diogo Silva
 * Email: diogoa.brandao5@gmail.com
 *
 * File DataBase class
 * @brief This class stores the user information on a .txt file
 *
 */

// System includes
#include <algorithm>
#include <iostream>
#include <fstream>
// Project includes
#include "FileDataBase.h"

namespace chess::database
{

    bool FileDataBase::initDataBase(const std::string &pathDataBase)
    {
        m_pathDataBase = pathDataBase;
        m_initted = loadFromFile();
        return m_initted;
    }

    bool FileDataBase::addUser(const User &newUser)
    {
        if (!m_initted)
        {
            return false;
        }

        if (std::find_if(m_users.begin(), m_users.end(), [&newUser](const User &user)
                         { return newUser.userId == user.userId; }) != m_users.end())
        {
            std::cout << "UserId already used" << std::endl;
            return false;
        }

        m_users.push_back(newUser);
        return saveToFile();
    }

    bool FileDataBase::removeUser(const std::string &userId)
    {
        if (!m_initted)
        {
            return false;
        }

        auto userItr = std::find_if(m_users.begin(), m_users.end(), [&userId](const User &user)
                                    { return userId == user.userId; });

        if (userItr == m_users.end())
        {
            std::cout << "UserId does not existe" << std::endl;
            return false;
        }

        m_users.erase(userItr);
        return saveToFile();
    }

    // Private
    bool FileDataBase::saveToFile()
    {
        std::ofstream file(m_pathDataBase);

        if (!file.is_open())
        {
            std::cerr << "Error: Unable to open file for writing." << std::endl;
            return false;
        }

        for (const auto &user : m_users)
        {
            file << user.userId << '\n';
        }
        file.close();
        return true;
    }

    bool FileDataBase::loadFromFile()
    {
        std::ifstream file(m_pathDataBase);
        if (!file.is_open())
        {
            std::cerr << "Warning: File doesn't exist yet." << std::endl;
            return false;
        }

        std::string userId;
        while (file >> userId)
        {
            m_users.push_back({userId});
        }
        file.close();
        return true;
    }

}
