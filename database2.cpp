#include <string>
#include <memory>
#include <iostream>

#include "database2.hpp"

void DataBase::mysqlExecuteQuery(std::string& sqlQuery)
{
  std::unique_ptr<sql::PreparedStatement> statement(m_connection->prepareStatement(sqlQuery));
  statement->executeQuery();
}

bool DataBase::isThereConnection()
{
  return m_connection != nullptr;
}
