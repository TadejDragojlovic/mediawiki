#include "../include/dbconnector.h"

DBConnector::DBConnector(std::string host, std::string username, std::string password, std::string mysql_schema) {
  m_driver = get_driver_instance();
  m_conn = m_driver->connect(host, username, password);
  m_conn->setSchema(mysql_schema);
}

DBConnector::~DBConnector() {
  m_conn->close();
  delete m_conn;
}

sql::Connection* DBConnector::get_conn() {
  return m_conn;
}

std::string DBConnector::current_db() {
  return m_conn->getSchema();
}

void DBConnector::execute_prepared_statement(std::string query, std::vector<std::variant<int, double, std::string>> params) {
  sql::PreparedStatement* p_stmt;

  p_stmt = m_conn->prepareStatement(query);

  /* TODO: currently only implemented parameters of type [int], [double] and [string] */
  for(int i=0;i<params.size();i++) {

    if(std::holds_alternative<std::string>(params[i])) {
      p_stmt->setString(i+1, std::get<std::string>(params[i]));
    } else if(std::holds_alternative<double>(params[i])) {
      p_stmt->setDouble(i+1, std::get<double>(params[i]));
    } else if(std::holds_alternative<int>(params[i])) {
      p_stmt->setInt(i+1, std::get<int>(params[i]));
    }
  }

  p_stmt->execute();
}