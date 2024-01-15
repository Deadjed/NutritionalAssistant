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

    // Create a table
    const char* createTableSQL = "PRAGMA foreign_keys = OFF; "
                                 "drop table if exists Food; "
                                 "drop table if exists Nutrition; "
                                 "PRAGMA foreign_keys = ON; "
                                 "CREATE TABLE Food ( "
                                     "PFK             CHAR(7)     NOT NULL, "
                                     "ID              INTEGER     NOT NULL, "
                                     "Derivation      TEXT, "
                                     "Name            TEXT        NOT NULL, "
                                     "Description     TEXT, "
                                     "Sampling        TEXT, "
                                     "Nitrogen        REAL, "
                                     "Fat             REAL, "
                                     "Gravity         REAL, "
                                     "Analysed        TEXT, "
                                     "Unanalysed      TEXT, "
                                     "Classification  INTEGER, "
                                     "ClassName       TEXT, "
                                     "PRIMARY KEY (PFK) "
                                 "); "
                                 "CREATE TABLE Nutrition ( "
                                     "PFK             CHAR(7)     NOT NULL, "
                                     "Classification  INTEGER, "
                                     "Name            TEXT        NOT NULL, "
                                     "Energy_Fibre   INTEGER, "
                                     "Energy          INTEGER, "
                                     "Protein         REAL, "
                                     "Fat             REAL, "
                                     "Carbohydrate    REAL, "
                                     "PRIMARY KEY (PFK), "
                                     "FOREIGN KEY (PFK) REFERENCES Food (PFK) "
                                 ");";

    rc = sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully" << std::endl;
    }

    // Insert data
    const char* insertDataSQL = "INSERT INTO FOOD (PFK, ID, Name) "
                                "VALUES (1, 1, 'Rice');";

    rc = sqlite3_exec(db, insertDataSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Records created successfully" << std::endl;
    }

/*
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