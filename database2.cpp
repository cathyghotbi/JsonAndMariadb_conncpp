#include <string>
#include <memory>
#include <iostream>

#include "database2.hpp"

void DataBase::mysqlConnectionSetup()
{
  sql::Driver* driver = sql::mariadb::get_driver_instance();
  if(driver)
  {
    std::cout << "driver not null" << std::endl;
  }

  std::unique_ptr<sql::Connection> connection(driver->connect(m_url, m_properties));
  m_connection = std::move(connection);
  isThereConnection();
}

void DataBase::mysqlExecuteQuery(std::string& sqlQuery)
{
  std::unique_ptr<sql::PreparedStatement> statement(m_connection->prepareStatement(sqlQuery));
  statement->executeQuery();
}

void DataBase::isThereConnection()
{
  if(!m_connection)
  {
    std::cout << "no connection to sql" << std::endl;
  }

  return;
}
