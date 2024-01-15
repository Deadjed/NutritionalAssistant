#include <iostream>
#include <string>
#include "importQueries.h"


struct UserData
{
	int num_columns;
	std::string result;
};

// Error handling
static int callback(void* NotUsed, int argc, char** argv, char** azColName) 
{
		int i;
		for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

// Return select statements
static int return_value_callback(void* userdata, int argc, char** argv, char** azColName) 
{
	struct UserData* data = (struct UserData*)(userdata);

	data->num_columns = argc;
	data->result = argv[0];
	return 0;
}

// Execute sql statement
void execute(sqlite3* db, std::string &query, int &rc)
{
	char* zErrMsg;
	rc = sqlite3_exec(db, query.c_str(), callback, 0, &zErrMsg);

	// Print error message with sql statement
	if (rc != SQLITE_OK) 
	{
		std::cout << query << std::endl;
		fprintf(stderr, "SQL error: %s\n\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
}


// Import global table
void importQueries::importGlobal(const char* DATABASE, CSV& data)
{
	// Open database
	sqlite3* db;
	int rc = sqlite3_open(DATABASE, &db);

	// Error checking
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	for (int i = 1; i < data.content.size(); i++)
	{
		int id = i - 1;
		// Create query
		std::string query = "INSERT INTO GlobalTemperature VALUES("
			+ std::to_string(id) + ", "
			+ data.content[i][0] + ", "
			+ data.content[i][1] + ", "
			+ data.content[i][2] + ", "
			+ data.content[i][3] + ", "
			+ data.content[i][4] + ", "
			+ data.content[i][5] + ", "
			+ data.content[i][6] + ");";

		// Execute query
		execute(db, query, rc);
	}

	// Close database
	sqlite3_close(db);
}


// Import Country table
void importQueries::importCountry(const char* DATABASE, CSV& data)
{
	// Open database
	sqlite3* db;
	int rc = sqlite3_open(DATABASE, &db);
	char* zErrMsg = 0;

	// Error checking
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	for (int i = 1; i < data.content.size(); i++)
	{
		// Create query
		std::string query = "INSERT INTO Country VALUES('"
			+ data.content[i][1] + "', '"
			+ data.content[i][0] + "');";

		// Execute query
		execute(db, query, rc);
	}

	// Close database
	sqlite3_close(db);
}


void importQueries::importState(const char* DATABASE, CSV& data)
{
	// Open database
	sqlite3* db;
	int rc = sqlite3_open(DATABASE, &db);
	char* zErrMsg = 0;

	// Error checking
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	for (int i = 1; i < data.content.size(); i++)
	{
		// Get country code
		std::string select = "SELECT code FROM COUNTRY WHERE name = '" + data.content[i][5] + "';";
		UserData out_data;
		sqlite3_exec(db, select.c_str(), return_value_callback, &out_data, &zErrMsg);

		// Create query
		std::string query = "INSERT INTO State VALUES('"
			+ data.content[i][4] + "', '"
			+ out_data.result + "');";

		// Execute query
		execute(db, query, rc);
	}

	// Close database
	sqlite3_close(db);
}


void importQueries::importCity(const char* DATABASE, CSV& data)
{
	// Open database
	sqlite3* db;
	int rc = sqlite3_open(DATABASE, &db);
	char* zErrMsg = 0;

	// Error checking
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	for (int i = 1; i < data.content.size(); i++)
	{
		// Get country code
		std::string select = "SELECT code FROM COUNTRY WHERE name = '" + data.content[i][5] + "';";
		UserData out_data;
		sqlite3_exec(db, select.c_str(), return_value_callback, &out_data, &zErrMsg);

		// Create query
		std::string query = "INSERT INTO City VALUES('"
			+ data.content[i][4] + "', '"
			+ data.content[i][6] + "', '"
			+ data.content[i][7] + "', '"
			+ out_data.result + "');";

		// Execute query
		execute(db, query, rc);
	}

	// Close database
	sqlite3_close(db);
}


void importQueries::importPopulation(const char* DATABASE, CSV& data)
{
	// Open database
	sqlite3* db;
	int rc = sqlite3_open(DATABASE, &db);
	char* zErrMsg = 0;

	// Error checking
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	for (int i = 1; i < data.content.size(); i++)
	{
		for (int j = 2; j < data.content[i].size(); j++)
		{
			// Create query
			std::string query = "INSERT INTO Population VALUES('"
				+ data.content[i][1] + "', "
				+ data.content[0][j] + ", "
				+ data.content[i][j] + ");";

			// Execute query
			execute(db, query, rc);
		}
	}

	// Close database
	sqlite3_close(db);
}


void importQueries::importCountryTemp(const char* DATABASE, CSV& data)
{
	// Open database
	sqlite3* db;
	int rc = sqlite3_open(DATABASE, &db);
	char* zErrMsg = 0;

	// Error checking
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	for (int i = 1; i < data.content.size(); i++)
	{
		// Get country code
		std::string select = "SELECT code FROM COUNTRY WHERE name = '" + data.content[i][4] + "';";
		UserData out_data;
		sqlite3_exec(db, select.c_str(), return_value_callback, &out_data, &zErrMsg);

		// Create query
		std::string query = "INSERT INTO CountryTemperature VALUES('"
			+ out_data.result + "', "
			+ data.content[i][0] + ", "
			+ data.content[i][1] + ", "
			+ data.content[i][2] + ", "
			+ data.content[i][3] + ");";

		// Execute query
		execute(db, query, rc);
	}

	// Close database
	sqlite3_close(db);
}


void importQueries::importStateTemp(const char* DATABASE, CSV& data)
{
	// Open database
	sqlite3* db;
	int rc = sqlite3_open(DATABASE, &db);
	char* zErrMsg = 0;

	// Error checking
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	for (int i = 1; i < data.content.size(); i++)
	{
		// Create query
		std::string query = "INSERT INTO StateTemperature VALUES('"
			+ data.content[i][4] + "', "
			+ data.content[i][0] + ", "
			+ data.content[i][1] + ", "
			+ data.content[i][2] + ", "
			+ data.content[i][3] + ");";

		// Execute query
		execute(db, query, rc);
	}

	// Close database
	sqlite3_close(db);
}


void importQueries::importCityTemp(const char* DATABASE, CSV& data)
{
	// Open database
	sqlite3* db;
	int rc = sqlite3_open(DATABASE, &db);
	char* zErrMsg = 0;

	// Error checking
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	for (int i = 1; i < data.content.size(); i++)
	{
		// Create query
		std::string query = "INSERT INTO CityTemperature VALUES('"
			+ data.content[i][4] + "', "
			+ data.content[i][0] + ", "
			+ data.content[i][1] + ", "
			+ data.content[i][2] + ", "
			+ data.content[i][3] + ");";

		// Execute query
		execute(db, query, rc);
	}

	// Close database
	sqlite3_close(db);
}
