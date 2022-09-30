#pragma once

#include <vector>
#include <nlohmann/json.hpp>

#include "database.hpp"

struct Address
{
  std::string city;
  int number;
  std::string street;
};

struct Salary
{
  std::string currency;
  int value;
};

struct Employee
{
  int id;
  std::string name;
  int age;
  Address address;
  std::vector<std::string> children;
  Salary salary;
  std::string title;
};

class JsonFile
{
public:
  JsonFile(DataBase& db)
    : m_database(db)
  {
    std::cout << " ------------------- JsonFile(const DataBase& db) ------------------- " << std::endl;
  }
  
  std::vector<Employee> parseJsonFile(const std::string& inputFilePath); 
  void addJsonFileToDataBase(const std::vector<Employee>& employees);

private:
  DataBase& m_database;
  nlohmann::json m_jsonObjectFromFile;
};
