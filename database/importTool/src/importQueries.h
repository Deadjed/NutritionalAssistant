#ifndef IMPORTQUERIES_H
#define IMPORTQUERIES_H

#include "csv.h"
#include "sqlite3.h"

class importQueries
{
public:
	static void importGlobal(const char* DATABASE, CSV& data);
	static void importCountry(const char* DATABASE, CSV& data);
	static void importState(const char* DATABASE, CSV& data);
	static void importCity(const char* DATABASE, CSV& data);
	static void importPopulation(const char* DATABASE, CSV& data);
	static void importCountryTemp(const char* DATABASE, CSV& data);
	static void importStateTemp(const char* DATABASE, CSV& data);
	static void importCityTemp(const char* DATABASE, CSV& data);
};

#endif
