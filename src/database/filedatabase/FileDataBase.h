/**
 * Author: Diogo Silva
 * Email: diogoa.brandao5@gmail.com
 *
 * File DataBase class
 * @brief This class stores the user information on a .txt file
 *
 */

// System includes
#include <string>
#include <vector>
// Project includes
#include "../IDataBase.h"

namespace chess::database
{

    class FileDataBase : public IDataBase
    {
    public:

        bool initDataBase(const std::string &pathDataBase) override;

        bool addUser(const User &user) override;

        bool removeUser(const std::string &userId) override;

    private:
        // Methods
        /**
         * @brief Loads the user information from the file
         *
         */
        bool loadFromFile();

        /**
         * @brief Saves the user information on the file
         *
         */
        bool saveToFile();

        // Member Variables
        // Name of the file tha contains the user information
        std::string m_pathDataBase;
        // Vector that contains the user information in runtime
        std::vector<User> m_users;
        // Database initted
        bool m_initted{false};
    };

}
