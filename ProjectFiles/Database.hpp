#pragma once

#include <string>
#include <vector>
//#include <cstdlib>
//#include <cctype>

class Food
{
public:
    /*
     * Loads file into memory
     */
    void loadDatabase(std::string& csvFile);
    
    /*
     * Outputs foods conataining string to console
     */
    void searchDatabase();
    
    /*
     * Returns a vector containing all micronutritional data in order 
     */
    std::vector<double> return_micros(Food& food, int id, double grams);
      
    /*
     * Returns a vector containing all macronutritional data in order (protein, carbs, fats)
     */
    std::vector<int> return_macros(Food& food, int id, double grams);
      
    /*
     * Returns name of food using ID input
     */
    std::string returnName(int id);
      
    /*
     * Returns ID of food using name input
     */
    int returnId(std::string name);
      
    /*
     * Prints list of foods high in input nutrients
     */
    void recommend_foods(std::vector<std::string>& deficient);
  
private:
    
    /*
     * Maps macro/micro database values 
     */
    std::vector<int> mapNutrients(std::vector<std::string>& symbols);
      
    /*
     *
     */
    std::vector<std::vector<std::string>> database;
  
};
