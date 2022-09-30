#pragma once

#include <memory>

#include <mariadb/conncpp.hpp>
#include <mariadb/conncpp/Driver.hpp>

class DataBase
{
public:
  DataBase(const sql::SQLString& url,  sql::Properties& properties)
  {
    sql::Driver* driver = sql::mariadb::get_driver_instance();
    if(driver == nullptr)
    {
      std::cout << "driver is null" << std::endl;
      return;
    }

    auto* connection = driver->connect(url, properties);
    if(connection == nullptr)
    {
      std::cout << "connection is null" << std::endl;
      return;
    }
  
    m_connection.reset(connection);
  }

  void mysqlExecuteQuery(std::string& sqlQuery);
  bool isThereConnection();

private:
  std::unique_ptr<sql::Connection> m_connection; 
};
