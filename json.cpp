#include <iostream>
#include <fstream>

#include "json.hpp"


std::vector<Employee> JsonFile::parseJsonFile(const std::string& inputFilePath)
{
  std::cout << " ------------------- JsonFile::readJsonFile(path) ------------------- " << std::endl;
  std::ifstream fileToRead(inputFilePath);
  fileToRead >> m_jsonObjectFromFile;
  
  std::vector<Employee> employees;
  for(std::size_t i = 0; i < m_jsonObjectFromFile["employees"].size(); i++)
  {
    const auto eachEmployee = "employee" + std::to_string(i+1);
    
    Employee employee;
    employee.id = *(m_jsonObjectFromFile["employees"][eachEmployee].find("id"));
    employee.name = *(m_jsonObjectFromFile["employees"][eachEmployee].find("name"));
    employee.title = *(m_jsonObjectFromFile["employees"][eachEmployee].find("title"));
    employee.age = *(m_jsonObjectFromFile["employees"][eachEmployee].find("age"));
    employee.address.city = *(m_jsonObjectFromFile["employees"][eachEmployee]["address"].find("city"));
    employee.salary.value = *(m_jsonObjectFromFile["employees"][eachEmployee]["salary"].find("value"));
    employee.salary.currency = *(m_jsonObjectFromFile["employees"][eachEmployee]["salary"].find("currency"));
    
    employees.push_back(employee);
  }
  
  return employees;
}

void JsonFile::addJsonFileToDataBase(const std::vector<Employee>& employees)
{
  std::cout << " ------------------- JsonFile::addJsonFileToDataBase() ------------------- " << std::endl;
 
  for(const auto& employee: employees)
  {
    std::string command = "INSERT INTO person (id, name, title, age, city, salary, currency) VALUES ('";
    std::string idAsString = std::to_string(employee.id);
    std::string ageAsString = std::to_string(employee.age);
    std::string salaryAsString = std::to_string(employee.salary.value);
    command += idAsString + "', '"
            + employee.name + "', '"
            + employee.title + "', '"
            + ageAsString + "', '"
            + employee.address.city + "', '"
            + salaryAsString + "', '"
            + employee.salary.currency + "');";

    if(m_database.isThereConnection())
    {
      m_database.mysqlExecuteQuery(command); 
    }
    else
    {
      std::cout << "there is no connection to the database.." << std::endl;
      return;
    }
  }
}

