#include <gtest/gtest.h>
#include "../../src/database/filedatabase/FileDataBase.h"
#include <memory>

namespace chess::database::ut
{
    class FileDataBaseTest : public testing::Test
    {

        void SetUp() override
        {
            m_pathDataBase = "/home/diogo/repos/Chess/tests/database/TestDataBase.txt";
            m_db = std::make_shared<FileDataBase>();
        }

    public:
        std::shared_ptr<FileDataBase> m_db;
        std::string m_pathDataBase;
    };

    /**
     * @brief Test if a user can be added and removed from the database
     */
    TEST_F(FileDataBaseTest, addRemoveUser)
    {
        // Checks that the database is initted successful
        EXPECT_TRUE(m_db->initDataBase(m_pathDataBase));

        // Checks that a user can be added to the database
        EXPECT_TRUE(m_db->addUser({"User1"}));

        // Not possible to add the same user 2 times
        EXPECT_FALSE(m_db->addUser({"User1"}));

        // Not possible to remove a user that is not on the database
        EXPECT_FALSE(m_db->removeUser({"User2"}));

        // Remove User1
        EXPECT_TRUE(m_db->removeUser({"User1"}));

        // Not possible to remove User1 2 times
        EXPECT_FALSE(m_db->removeUser({"User1"}));

        // Not possible to init an invalid database
        EXPECT_FALSE(m_db->initDataBase("NOT_A_DB"));

        // Not possible to add a user when there is no database
        EXPECT_FALSE(m_db->addUser({"User1"}));

        // Not possible to remove a user when there is no database
        EXPECT_FALSE(m_db->removeUser({"User1"}));

    }
}