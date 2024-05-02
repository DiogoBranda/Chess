/**
 * Author: Diogo Silva
 * Email: diogoa.brandao5@gmail.com
 *
 * DataBase Interface
 *
 */

// System includes
#include <string>
// Project includes

namespace chess::database
{

    /**
     * @brief Representes the user data
     * @param userId user identifier
     */
    struct User
    {
        std::string userId;
    };

    class IDataBase
    {

    public:
        virtual ~IDataBase() = default;

        /**
         * @brief Loads the database and initialize all dependencies
         *  @param pathDataBase string that contains the path to the database
         */
        virtual bool initDataBase(const std::string &pathDataBase) = 0;

        /**
         * @brief Adds a user to the database
         * @param User user to be added to the data base
         */
        virtual bool addUser(const User &user) = 0;

        /**
         * @brief Removes a user from the database
         * @param userId user identifiar that should be removed
         */
        virtual bool removeUser(const std::string &userId) = 0;
    };

}
