
This repository is using C++, nlohmann::json file and mariadb.
It is developed on Ubuntu 22.04.1 LTS which is installed on virtual box.
File created by nlohmann::json is read to fill the database using C++ connector for mariadb (mariadb/conncpp.hpp).

Note: User may not be 'root' using C++ connector but if you use mariadb C connector (mariadb/mysql.h), user may be 'root'!

* To login to database and see the table with named 'person' inside database named 'test':
  $ sudo mysql -u root
  MariaDB [(none)]> use test;
  MariaDB [test]> SELECT * FROM person;

* Command to compile:
  $ g++ database.cpp json.cpp main.cpp -o readJsonWithCppInsertIntoDB  -lmariadbcpp -lmysqlcppconn
  
* Command to run:
  $ ./readJsonWithCppInsertIntoDB
 
* References:
 - https://github.com/nlohmann/json/blob/develop/docs/examples/README.cpp
 - https://mariadb.com/docs/connect/programming-languages/cpp/
 - https://mariadb.com/downloads/connectors/
 - https://stackoverflow.com/questions/16710047/usr-bin-ld-cannot-find-lnameofthelibrary
 - https://stackoverflow.com/questions/36679189/how-to-find-mysql-ip-on-localhost 
 - https://mariadb.com/resources/blog/how-to-connect-c-programs-to-mariadb/
