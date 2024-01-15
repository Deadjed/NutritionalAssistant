#include <string>
#include <iostream>
#include "csv.h"
#include "sqlite3.h"
#include "importQueries.h"


const char* DATABASE = "dataset-Climate/climate.db";
std::string CSV_GLOBAL = "dataset-Climate/GlobalYearlyTemp.csv";
std::string CSV_COUNTRY = "dataset-Climate/GlobalYearlyLandTempByCountry.csv";
std::string CSV_STATE = "dataset-Climate/GlobalYearlyLandTempByState.csv";
std::string CSV_CITY = "dataset-Climate/GlobalYearlyLandTempByCity.csv";
std::string CSV_POPULATION = "dataset-Climate/Population.csv";


int main() {
	CSV Global;
	CSV Country;
	CSV State;
	CSV City;
	CSV Population;

	// Read CSV files
	Global.read(CSV_GLOBAL);
	Country.read(CSV_COUNTRY);
	State.read(CSV_STATE);
	City.read(CSV_CITY);
	Population.read(CSV_POPULATION);

	// Populate data
	importQueries::importGlobal(DATABASE, Global);
	importQueries::importCountry(DATABASE, Population);
	importQueries::importState(DATABASE, State);
	importQueries::importCity(DATABASE, City);
	importQueries::importPopulation(DATABASE, Population);
	importQueries::importCountryTemp(DATABASE, Country);
	importQueries::importStateTemp(DATABASE, State);
	importQueries::importCityTemp(DATABASE, City);

	std::cout << "SQL data population COMPLETE!" << std::endl;

	return 0;
}