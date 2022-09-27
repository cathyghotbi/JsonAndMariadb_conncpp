
This repository is using C++, nlohmann::json file and mariadb.
It is developed on Ubuntu 22.04.1 LTS which is installed on virtual box.
File created by nlohmann::json is read to fill the database.

* To login to database and see the table with name 'test':
  $ sudo mysql -u root
  MariaDB [(none)]> use test;
  MariaDB [test]> SELECT * FROM person;

* Command to compile:
  $ g++ database2.cpp json2.cpp readJsonWithCppInsertIntoDB2.cpp -o readJsonWithCppInsertIntoDB2 -L/usr/include/mariadb/mysql -L/usr/include/mariadb -lmariadbclient -lmariadbcpp -lmysqlcppconn
  
* Command to run:
  $ sudo ./readJsonWithCppInsertIntoDB2
 
* References:
 - https://mariadb.com/docs/connect/programming-languages/cpp/
 - https://mariadb.com/downloads/connectors/
 - https://stackoverflow.com/questions/16710047/usr-bin-ld-cannot-find-lnameofthelibrary
 - https://stackoverflow.com/questions/36679189/how-to-find-mysql-ip-on-localhost 
 - https://mariadb.com/resources/blog/how-to-connect-c-programs-to-mariadb/

