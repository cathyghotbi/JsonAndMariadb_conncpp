
// $ g++ database.cpp json.cpp main.cpp -o readJsonWithCppInsertIntoDB  -lmariadbcpp -lmysqlcppconn
// $ sudo ./readJsonWithCppInsertIntoDB
// git push -u origin
#include <string>
#include <iostream>
#include <fstream>

#include "database.hpp"
#include "json.hpp"

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

