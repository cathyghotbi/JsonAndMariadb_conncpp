
#include <string>
#include <iostream>
#include <fstream>

#include "database2.hpp"
#include "json2.hpp"

int main()
{
  const sql::SQLString& url = "jdbc:mariadb://localhost:3306/test";
  const sql::Properties& prop  {{"user", "root2"}, {"password", ""}} ; // 'root' cannot be user in C++ API but in C API!
  DataBase testDatabase(url, prop);

  std::cout << "--------------- opening conenction to database: ---------------" << std::endl;
  testDatabase.mysqlConnectionSetup();

  std::cout << "--------------- creating json file: ---------------" << std::endl;
  JsonFile jsonFile(testDatabase); 
  jsonFile.createJsonFile();

  //std::cout << "--------------- reading json file: ---------------" << std::endl;
  //jsonFile.readJsonFile();

  std::cout << "--------------- adding the content of json file to database: ---------------" << std::endl;
  jsonFile.addJsonFileToDataBase();

  std::cout << "--------------- closing conenction to database: ---------------" << std::endl;

  return 0;
}
