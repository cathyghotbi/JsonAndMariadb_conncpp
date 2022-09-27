#include <iostream>
#include <fstream>

#include "json2.hpp"

void JsonFile::createJsonFile()
{
  std::cout << " ------------------- JsonFile::createJsonFile() ------------------- " << std::endl;
  std::ofstream newFile("oneJsonFile2.json");

  nlohmann::json employees =
  {
  { "employees" , {
 
    { "employee1" , {
    {"id", 69},
    {"name", "Eli"},
    {"age", 25},
    {"children", {"Ben", "Kimberly", "Jack"}},
    {
      "salary", {
        {"currency", "USD"},
        {"value", 1000}
      }
    },
    {"title", "dev"},
    {
      "address", {
        {"street", "Jeferson"},
        {"number", 22},
        {"city", "Prague"}
      }
    }  

    }, },

    { "employee2" , {
    {"id", 55},
    {"name", "Angela"},
    {"age", 35},
    {"children", {"Robin", "Kevin", "Adrian"}},
    {
      "salary", {
        {"currency", "USD"},
        {"value", 2000}
      }
    },
    {"title", "dev"},
    {
      "address", {
        {"street", "Oak"},
        {"number", 33},
        {"city", "Istanbul"}
      }
    }  

    }, },

    { "employee3" , {
    {"id", 101},
    {"name", "Tom"},
    {"age", 45},
    {"children", {"Emma", "Eva", "Eli"}},
    {
      "salary", {
        {"currency", "USD"},
        {"value", 3000}
      }
    },
    {"title", "dev"},
    {
      "address", {
        {"street", "Riverside"},
        {"number", 101},
        {"city", "Venice"}
      }
    }

    }, },

    { "employee4" , {    
    {"id", 77},
    {"name", "Jerry"},
    {"age", 55},
    {"children", {"Oliver", "Emily", "Olivia", "Sara"}},
    {
      "salary", {
        {"currency", "USD"},
        {"value", 4000}
      }
    },
    {"title", "dev"},
    {
      "address", {
        {"street", "Montgomery"},
        {"number", 88},
        {"city", "Athens"}
      }
    } 
   
    }, },
   
   } }
  };

  newFile << std::setw(4) << employees << std::endl;
}

void JsonFile::addJsonFileToDataBase()
{
  std::cout << " ------------------- JsonFile::addJsonFileToDataBase() ------------------- " << std::endl;
  std::ifstream fileToRead("oneJsonFile2.json");
  fileToRead >> m_jsonObjectFromFile;
 
  std::string eachEmployee = "employee";
  for(int i = 0; i < m_jsonObjectFromFile["employees"].size(); i++)
  {
    std::string eachEmployee = "employee";
    eachEmployee += std::to_string(i+1);
  
    int id = *(m_jsonObjectFromFile["employees"][eachEmployee].find("id"));
    std::string name = *(m_jsonObjectFromFile["employees"][eachEmployee].find("name"));
    std::string title = *(m_jsonObjectFromFile["employees"][eachEmployee].find("title"));
    int age = *(m_jsonObjectFromFile["employees"][eachEmployee].find("age"));
    std::string city = *(m_jsonObjectFromFile["employees"][eachEmployee]["address"].find("city"));
    int salary = *(m_jsonObjectFromFile["employees"][eachEmployee]["salary"].find("value"));
    std::string currency = *(m_jsonObjectFromFile["employees"][eachEmployee]["salary"].find("currency"));

    std::string command = "INSERT INTO person (id, name, title, age, city, salary, currency) VALUES ('";
    std::string idAsString = std::to_string(id);
    command.append(idAsString);
    command.append("', '");
    command.append(name);
    command.append("', '");
    command.append(title);
    command.append("', '");
    std::string ageAsString = std::to_string(age);
    command.append(ageAsString);
    command.append("', '");
    command.append(city);
    command.append("', '");
    std::string salaryAsString = std::to_string(salary);
    command.append(salaryAsString);
    command.append("', '");
    command.append(currency);
    command.append("');");

    m_database.mysqlExecuteQuery(command); //TODO: check conenction
  }
}

void JsonFile::readJsonFile()
{
  std::cout << " ------------------- JsonFile::readJsonFile() ------------------- " << std::endl;
  std::ifstream fileToRead("oneJsonFile2.json");
  std::ostringstream tmp;
  tmp << fileToRead.rdbuf();
  std::string fileIntoStringFormat = tmp.str();
  nlohmann::json fileRead = nlohmann::json::parse(fileIntoStringFormat);
  std::cout << std::setw(4) << fileRead << std::endl;
}
