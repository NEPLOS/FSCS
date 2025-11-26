
#include "../include/MySql.h"


MySQLConnection::MySQLConnection(std::string server , std::string user , std::string password , std::string database)
{
    this->server = server;
    this->user = user;
    this->password = password;
    this->database = database;

    mysqlConnectionSetUp();

}

void MySQLConnection::mysqlConnectionSetUp()
{
    con = mysql_init(NULL);

    if (!mysql_real_connect(con , server.c_str() , user.c_str() , password.c_str() , database.c_str() , 0 , NULL , 0))
    {
        std::cout << "connection failed : " << mysql_error(con) << '\n';
        exit(EXIT_FAILURE);
        //return nullptr;
    }

}

MYSQL_RES* MySQLConnection::mysqlExecuteQuery(std::string query)
{
    MYSQL_RES *res;
    std::cout << "something 1\n";

    if (mysql_query(con , query.c_str()))
    {
        std::cout << "MYSQL ERROR : " << mysql_error(con) << '\n';
       // exit(EXIT_FAILURE);

    }

    unsigned int num_fields = mysql_num_fields(res);

    std::cout << "something 2\n";
    
    res =  mysql_use_result(con);

}

void mysqlFreeResultFromMemory(MYSQL_RES* res)
{
    mysql_free_result(res);
}

