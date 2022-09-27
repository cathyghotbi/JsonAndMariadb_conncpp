#pragma once

#include <memory>

#include <mariadb/conncpp.hpp>
#include <mariadb/conncpp/Driver.hpp>

class DataBase
{
public:
  DataBase(const sql::SQLString& url, const sql::Properties& properties)
    : m_url(url), m_properties(properties)
  {
  }
 
  void mysqlConnectionSetup();
  void mysqlExecuteQuery(std::string& sqlQuery);
  void isThereConnection();

  ~DataBase()
  {
  }

private:
  std::unique_ptr<sql::Connection> m_connection; 
  sql::SQLString m_url;
  sql::Properties m_properties;
};
