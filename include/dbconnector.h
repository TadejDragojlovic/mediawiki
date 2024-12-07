#include <iostream>
#include <stdlib.h>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


class DBConnector {
  private:
    sql::Driver* _driver;
    sql::Connection* _conn;
  public:
    DBConnector(std::string host, std::string username, std::string password, std::string mysql_schema);
    ~DBConnector();

    std::string current_db();
};