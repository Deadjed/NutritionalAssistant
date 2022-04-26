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
     *
     */
    void searchDatabase();
    
    /*
     *
     */
    std::vector<double> return_micros(Food& food, int id, double grams);
      
    /*
     *
     */
    std::vector<int> return_macros(Food& food, int id, double grams);
      
    /*
     *
     */
    std::string returnName(int id);
      
    /*
     *
     */
    int returnId(std::string name);
      
    /*
     *
     */
    void recommend_foods(std::vector<std::string>& deficient);
  
private:
    
    /*
     *
     */
    std::vector<int> map(std::vector<std::string>& symbols);
      
    /*
     *
     */
    std::vector<std::vector<std::string>> database;
  
};
