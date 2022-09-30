#include <iostream>
#include <fstream>

#include "json.hpp"


std::vector<Employee> JsonFile::parseJsonFile(const std::string& inputFilePath)
{
  std::cout << " ------------------- JsonFile::readJsonFile(path) ------------------- " << std::endl;
  std::ifstream fileToRead(inputFilePath);
  fileToRead >> m_jsonObjectFromFile;
  
  std::vector<Employee> employees;

  for(const auto& emp : m_jsonObjectFromFile["employees"])
  {
    Employee employee;
    employee.id = emp["id"];
    employee.name = emp["name"];
    employee.title = emp["title"];
    employee.age = emp["age"];
    employee.address.city = emp["address"]["city"];
    employee.salary.value = emp["salary"]["value"];
    employee.salary.currency = emp["salary"]["currency"];
    employees.push_back(employee);
  }

  return employees;
}

void JsonFile::addJsonFileToDataBase(const std::vector<Employee>& employees)
{
  std::cout << " ------------------- JsonFile::addJsonFileToDataBase() ------------------- " << std::endl;
  if(! m_database.isThereConnection())
  {
    std::cout << "there is no connection to the database.. no command to be sent" << std::endl;
    return;
  }
 
  for(const auto& employee: employees)
  {
    std::string command = "INSERT INTO person (id, name, title, age, city, salary, currency) VALUES ('";
    command += std::to_string(employee.id) + "', '"
            + employee.name + "', '"
            + employee.title + "', '"
            + std::to_string(employee.age) + "', '"
            + employee.address.city + "', '"
            + std::to_string(employee.salary.value) + "', '"
            + employee.salary.currency + "');";


    m_database.mysqlExecuteQuery(command);
  }
}

