#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
                                     "Classification  INTEGER, "
                                     "Name            TEXT        NOT NULL, "
                                     "Energy_Fibre   INTEGER, "
                                     "Energy          INTEGER, "
                                     "Protein         REAL, "
                                     "Fat             REAL, "
                                     "Carbohydrate    REAL, "
                                     "PRIMARY KEY (PFK) "
                                 ");";

    rc = sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully" << std::endl;
    }

    
    // Specify the file name
    std::string fileName = "../database/FoodNutrientDatabase.csv";

    // Create an input file stream
    std::ifstream inputFile(fileName);

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return 1; // Return an error code
    }

    // Read and print the contents line by line
    std::string line;
    std::getline(inputFile, line);
    std::getline(inputFile, line);

    // Parse CSV line
    int id = 0;

    // Get lines from csv
    while (std::getline(inputFile, line)) {
        char* c = &line[0];
        std::vector<std::string> parsedLine;
        int counter = 0;

        // Get words in line
        while (*c != '\n' && counter != 252)
        {
            std::string word = "";
            bool insideString = false;

            while ((*c != ',' || insideString) && *c != '\n') {
                if (*c == '"') insideString = !insideString;
                if (*c != '"' && *c != ' ') word += *c;
                c++;
            }
            if (*c == ',') {
                parsedLine.push_back(word);
                c++;
                counter++;
            }
        }
        
        // Insert data
        const std::string insertFoodDataSQL = "INSERT INTO FOOD (PFK, Name, Protein, Fat, Carbohydrate) "
                                        "VALUES ('" + parsedLine.at(0) + "', '" + parsedLine.at(2) + "', " + parsedLine.at(6) + ", " + parsedLine.at(8) + ", " + parsedLine.at(35) + ");";

        rc = sqlite3_exec(db, insertFoodDataSQL.c_str(), 0, 0, &errMsg);

        if (rc != SQLITE_OK) {
            std::cerr << "SQL error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        } else {
            std::cout << parsedLine.at(2) << " Records created successfully" << std::endl;
        }
    }

    // Close the file
    inputFile.close();



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