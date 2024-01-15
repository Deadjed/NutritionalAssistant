#include <iostream>
#include <sqlite3.h>

int main()
{
    sqlite3* db;
    char* errMsg = 0;

    // Open a database file (if it doesn't exist, it will be created)
    int rc = sqlite3_open("../database/database.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    } else {
        std::cout << "Opened database successfully" << std::endl;
    }

/*
    // Create a table
    const char* createTableSQL = "CREATE TABLE COMPANY("
                                 "ID INT PRIMARY KEY     NOT NULL,"
                                 "NAME           TEXT    NOT NULL,"
                                 "AGE            INT     NOT NULL,"
                                 "ADDRESS        CHAR(50));";

    rc = sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully" << std::endl;
    }

    // Insert data
    const char* insertDataSQL = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS) "
                                "VALUES (1, 'John Doe', 30, '123 Main St');";

    rc = sqlite3_exec(db, insertDataSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Records created successfully" << std::endl;
    }

    // Retrieve data
    const char* selectDataSQL = "SELECT * FROM COMPANY";

    rc = sqlite3_exec(db, selectDataSQL, [](void* data, int argc, char** argv, char** colName) -> int {
        for (int i = 0; i < argc; i++) {
            std::cout << colName[i] << " = " << (argv[i] ? argv[i] : "NULL") << ", ";
        }
        std::cout << std::endl;
        return 0;
    }, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

*/
    // Close the database
    sqlite3_close(db);

    return 0;
}