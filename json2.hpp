#pragma once

#include <nlohmann/json.hpp>
#include "database2.hpp"

class JsonFile
{
public:
  JsonFile(DataBase& db)
    : m_database(db)
  {
    std::cout << " ------------------- JsonFile(const DataBase& db) ------------------- " << std::endl;
  }

  void createJsonFile();
  void addJsonFileToDataBase();
  void readJsonFile();

private:
  DataBase& m_database;
  nlohmann::json m_jsonObjectFromFile;
};
