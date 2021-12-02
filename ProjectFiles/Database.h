#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

class Food
{
public:
    //Public functions
    void loadDatabase(std::string& csvFile);
    void searchDatabase();
    std::vector<double> return_micros(Food& food, int id, double grams);
    std::vector<int> return_macros(Food& food, int id, double grams);
    std::string returnName(int id);
    int returnId(std::string name);
    void recommend_foods(std::vector<std::string>& deficient);
private:
    //Private functions
    std::vector<int> map(std::vector<std::string>& symbols);
    //Private objects
    std::vector<std::vector<std::string>> database;
};

void Food::loadDatabase(std::string& csvFile)
{    
    std::string temp, word, sline;
    std::vector<std::string> vLine;

    std::ifstream rawDatabase(csvFile);
    
    //Function to store values within csv that some idiot put commas in
    while (std::getline(rawDatabase, sline)){
        bool quote = false;
        for (auto c : sline) {
            if (c != '"') {
                if (c != ',') {
                    word += c;
                } else {
                    if (!quote) {
                        vLine.push_back(word);
                        word.clear();
                    } else 
                        word += c;
                }
            } else {
                quote = (quote) ? false : true;
            }
        }
        database.push_back(vLine);
        vLine.clear();
    }
}
//------
//Function maps macro/micro database values 
std::vector<int> mapNutrients(std::vector<std::string>& symbols)
{
    std::vector<int> locations;
    for (std::string i : symbols) {
            if (i == "Protein") {
                locations.push_back(6); //Database location for Protein
                continue;
            }
            if (i == "Carb") {
                locations.push_back(35); //Database location for Carbohydrates
                continue;
            }
            if (i == "Fat") {
                locations.push_back(8); //Database location for Fats
                continue;
            }
            //---Minerals---
            if (i == "Ca") {
                locations.push_back(50); //Database location for Calcium (Ca)
                continue;
            }
            if (i == "Cr") {
                locations.push_back(51); //Database location for Chromium(Cr)
                continue;
            }
            if (i == "Cu") {
                locations.push_back(54); //Database location for Copper (Cu)
                continue;
            }
            if (i == "F") {
                locations.push_back(55); //Database location for Flouride (F)
                continue;
            }
            if (i == "I") {
                locations.push_back(56); //Database location for Iodine (I)
                continue;
            }
            if (i == "Fe") {
                locations.push_back(57); //Database location for Iron (Fe)
                continue;
            }
            if (i == "Mg") {
                locations.push_back(59); //Database location for Magnesium (Mg)
                continue;
            }
            if (i == "Mn") {
                locations.push_back(60); //Database location for Manganese (Mn)
                continue;
            }
            if (i == "Mo") {
                locations.push_back(62); //Database location for Molybdenum (Mo)
                continue;
            }
            if (i == "P") {
                locations.push_back(64); //Database location for Phosphorus (P)
                continue;
            }
            if (i == "K") {
                locations.push_back(65); //Database location for Potassium (K)
                continue;
            }
            if (i == "Se") {
                locations.push_back(66); //Database location for Selenium (Se)
                continue;
            }
            if (i == "Na") {
                locations.push_back(67); //Database location for Sodium (Na)
                continue;
            }
            if (i == "S") {
                locations.push_back(68); //Database location for Sulphur (S)
                continue;
            }
            if (i == "Zn") {
                locations.push_back(70); //Database location for Zinc (Zn)
                continue;
            }
            //---Vitamins---
            if (i == "A") {
                locations.push_back(71); //Database location for Retinol (preformed vitamin A)
                continue;
            }
            if (i == "B1") {
                locations.push_back(80); //Database location for Thiamin (B1)
                continue;
            }
            if (i == "B2") {
                locations.push_back(81); //Database location for Riboflavin (B2)
                continue;
            }
            if (i == "B3") {
                locations.push_back(82); //Database location for Niacin (B3)
                continue;
            }
            if (i == "B5") {
                locations.push_back(85); //Database location for Pantothenic acid (B5)
                continue;
            }
            if (i == "B6") {
                locations.push_back(86); //Database location for Pyridoxine (B6)
                continue;
            }
            if (i == "B7") {
                locations.push_back(87); //Database location for Biotin (B7)
                continue;
            }
            if (i == "B9") {
                locations.push_back(90); //Database location for Folic acid (B9)
                continue;
            }
            if (i == "B12") {
                locations.push_back(88); //Database location for Cobalamin (B12)
                continue;
            }
            if (i == "C") {
                locations.push_back(93); //Database location for Vitamin C
                continue;
            }
            if (i == "Choline") {
                locations.push_back(94); //Database location for Choline (not in current database)
                continue;
            }
            if (i == "D") {
                locations.push_back(94); //Database location for Cholecalciferol (D3)
                continue;
            }
            if (i == "E") {
                locations.push_back(107); //Database location for Vitamin E
                continue;
            }
            if (i == "K") {
                locations.push_back(56); //Database location for Vitamin K (not in current database)
                continue;
            }
        //10: fibre
        //19: sugar 
        }
    return locations;
}
//------
//Function returns name of food with ID input
std::string Food::returnName(int id)
{
    return database[id][2];
}
//------
//Function returns ID of food with name input
int Food::returnId(std::string name)
{
    for (size_t i = 0; i < database.size(); ++i) {
        if (database[i][2].find(name) != std::string::npos) {
            return i;
        }
    }
    std::cerr << "Food item name invalid!" << std::endl;
    return 1;
}
//------
//Function outputs foods conataining string to console
void Food::searchDatabase()
{
    std::cout << "\nPlease enter a food item: \n";
    std::string search;
    std::string s;
    bool found = false;
    while (std::cin >> search) {
        if (!search.empty()) {
            s = search;
            s[0] = (isupper(s[0])) ? tolower(s[0]) : toupper(s[0]);
            //std::cout << "\nFood ID: Name\n";
            for (size_t i = 0; i < database.size(); ++i) {
                if (database[i][2].find(search) != std::string::npos || database[i][2].find(s) != std::string::npos) {
                    std::cout << i << ": " << database[i][2] << std::endl;
                    found = (found) ? found : true;
                }
            }
            if (!found) {
                std::cout << "\nNo foods with that name found, please type something else:\n";
                continue;
            }
        } else {
            std::cerr << "\nPlease enter a valid food item: " << std::endl;
            continue;
        }
        return;
    }
}
//------
//Function returns a vector containing all macronutritional data in order (protein, carbs, fats)
std::vector<int> Food::return_macros(Food& food, int id, double grams)
{
    std::vector<int> nutrition;
    std::vector<int> databaseMacroLocations{6, 35, 8};
    for (auto i : databaseMacroLocations) {
        if (!database[id][i].empty()) {
            nutrition.push_back((std::stoi(database[id][i]) * (grams / 100)));
        } else {
            nutrition.push_back(0);
        }
    }
    return nutrition;
}
//------
//Function returns a vector containing all micronutritional data in order 
std::vector<double> Food::return_micros(Food& food, int id, double grams)
{
    std::vector<double> nutrition;
    std::vector<int> databaseMicros{71, 80, 81, 82, 85, 86, 88, 87, 93, 94, 95, 107, 90, 56/*not vitamin K*/, 50, 51, 54, 55, 56, 57, 59, 60, 62, 64, 65, 66, 67, 68, 70};
    for (auto i : databaseMicros) {
        if (!database[id][i].empty()) {
            nutrition.push_back((std::stod(database[id][i]) * (grams / 100)));
        } else {
            nutrition.push_back(0.0);
        }
    }
    return nutrition;
}
//Function prints list of foods high in nutrients inputted
void Food::recommend_foods(std::vector<std::string>& deficient)
{
    std::vector<int> locations;
    locations = mapNutrients(deficient);
    //Loop through database holding values for heighest 5 values in each deficient location
    std::vector<std::vector<int>> ids;
    
    for (auto i : locations) {

        std::vector<int> a;
        double currentLargest = 0;
        double current = 0;


        for (int x = 2; x < database.size(); ++x) {
            if (!database[x][i].empty()) {
                if (a.empty()) a.push_back(x);
                currentLargest = std::stod(database[a.at(a.size() - 1)][i]);
                current = std::stod(database[x][i]);
                
                if (current > currentLargest) {
                    a.push_back(x);
                    currentLargest = std::stod(database[a[0]][i]);
                }
            } 
        }
        if (a.size() > 5) {
            a.erase(a.begin() + 5, a.end());
        }
        ids.push_back(a);
    }
    //Output Food ID, Name, Nutrient high in, Nutrient value 
    for (int idsIter = 0; idsIter < ids.size(); ++idsIter) {
        for (auto id : ids[idsIter]) {
            std::cout << id << ": " << database[id][2] << "\tContains " << database[0][locations[idsIter]] << ": " << database[id][locations[idsIter]] << std::endl;
        }
        std::cout << std::endl;
    }

}
//------

#endif


//DATABASE IMPORTANT VALUES
/*
    A, B1, B2, B3, B5, B6, B12, B7, C, Choline, D, E, B9, K, Ca, Cr, Cu, F, I, Fe, Mg, Mn, Mo, P, K, Se, Na, S, Zn
*/