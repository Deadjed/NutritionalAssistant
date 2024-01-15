#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Database.hpp"

//FEATURE LIST
    //Add dietry recommendations
    //Add User database

int main() 
{   
    //Load csv file
    Food food;
    std::string csvFile("FoodNutrientDatabase.csv");
    food.loadDatabase(csvFile);

    //Check if (E)xisting user or (N)ew user *TO BE ADDED*
    
    //Create User
    Person user;
    user.get_data();
    
    //Main menu
    std::cout << "\nWhat would you like to do?\n" 
              << "(C)eck your diet\n"
              << "(R)emove foods you saved\n"
              << "(S)earch for foods\n"
              << "(V)iew user information\n"
              << "(E)xit the program\n";
    char c;
    while (std::cin >> c) 
    {
        c = std::toupper(c);
        switch (c) 
        {
            case 'C' :
                user.check_diet(food);
                break;
            case 'R' :
                user.remove_food(food);
                break;
            case 'S' :
                food.searchDatabase();
                std::cout << "\nWould you like to add one of these to your diet(Y/N)?\n";
                while (std::cin >> c) 
                {
                    c = std::toupper(c);
                    if (c == 'Y') 
                    {
                        std::cout << "Please enter the food id number: \n";
                        int i;
                        std::cin >> i;
                        if (i > 0)
                            user.add_food(food, i);
                        break;
                    } 
                    else if (c == 'N') 
                    {
                        break;
                    }
                    std::cout << "Please enter 'Y' for yes or 'N' for no: \n";
                }
                break;
            case 'V' :
                user.prnt_user();
                break;
            case 'E' :
                return 0;
        }
        std::cout << "\nAnything Else?\n" 
                  << "(C)eck your diet\n"
                  << "(R)emove foods you saved\n"
                  << "(S)earch for foods\n"
                  << "(V)iew user information\n"
                  << "(E)xit the program\n";
    }
    return 0;
}
