
// $ g++ database2.cpp json2.cpp main.cpp -o readJsonWithCppInsertIntoDB2 -L/usr/include/mariadb/mysql -L/usr/include/mariadb -lmariadbclient -lmariadbcpp -lmysqlcppconn
// $ sudo ./readJsonWithCppInsertIntoDB2
#include <string>
#include <iostream>
#include <fstream>

#include "database2.hpp"
#include "json2.hpp"

int main()
{
  std::cout << "--------------- opening conenction to database: ---------------" << std::endl;
  const sql::SQLString& url = "jdbc:mariadb://localhost:3306/test";
  sql::SQLString user = "root2";
  sql::SQLString password = "";
  sql::Properties prop  {{"user", user}, {"password", password}};
  
  DataBase testDatabase(url, prop);

  
  testDatabase.isThereConnection();

  JsonFile jsonFile(testDatabase); 
  std::cout << "--------------- reading json file: ---------------" << std::endl;
  const std::string& filePath = "input.json";
  jsonFile.parseJsonFile(filePath);

  std::cout << "--------------- adding the content of json file to database: ---------------" << std::endl;
  jsonFile.addJsonFileToDataBase();

  std::cout << "--------------- closing conenction to database: ---------------" << std::endl;

  return 0;
}

