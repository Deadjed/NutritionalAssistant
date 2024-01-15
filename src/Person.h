#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdlib>
#include "Nutrition.hpp"
#include "Database.hpp"

class Person {
public:
    //Constructors
    Person() = default;
    Person(std::string &s) : name(s) { }
    
    //Public functions
    inline void get_data();
    inline void prnt_user();
    void add_food(Food& foodDatabase, int id);
    void check_diet(Food& foodDatabase);
    void remove_food(Food& foodDatabase);
private:
    //Private functions
    void calculate_macros(Macros& macros);
    //Private objects
    std::string name;
    char gender;
    unsigned age;
    double weight;
    double height;
    double bmr;
    double tdee;
    int calories;
    std::vector<std::tuple<std::string,double>> food_list;
    Macros macros_recommended;
    Macros macros_intake;
    Micros micros_min;
    Micros micros_max;
    Micros micros_intake;

    Person *next;
};

//Get user data
void Person::get_data()
{
    //ADD INPUT CHECKS (isdigit etc)
    while (name.empty()) {
        std::cout << "What is your name: ";
        getline(std::cin, name);
    } 
    std::cout << "\n \nHello " << name << "!\n\n";  
    std::cout << "Are you Male or Female(M/F): ";
    while (std::cin >> gender) {
        gender = toupper(gender);
        if (gender == 'M' || gender == 'F')
            break;
        std::cerr << "Please enter 'M' or 'F':\n";
    }
    std::cout << "How old are you: ";
    while (std::cin >> age) {
        if (age < 150) {
            break;
        } else {
            std::cerr << "You can't be that old..\n";
        }
    }
    std::cout << "How tall are you(cm): ";
    while (std::cin >> height) {
        if (height > 0 && height < 270) {
            break;
        } else if (height < 0) {
            std::cerr << "Height doesn't work like that.. try again:\n";
        } else {
            std::cerr << "Why isn't your name in the guinness book of records then? try again:\n";
        }
    }
    std::cout << "How much do you weigh(Kg): ";
    while (std::cin >> weight) {
        if (weight > 0 && weight < 500) {
            break;
        } else if (weight < 0) {
            std::cerr << "You have violated one or more energy conditions.. try again:\n";
        } else if (weight > 500) {
            std::cerr << "Why isn't your name in the guinness book of records then? try again:\n";
        }
    }
    std::cout << "\nWhat is your activity level:\n" <<
    "1.2  - Desk job no training\n" <<
    "1.37 - Exercise 1-3 days/week\n" <<
    "1.55 - Train 3-5 days/week\n" <<
    "1.72 - Train 6-7 days/week\n" <<
    "1.9  - Train 2x day" << std::endl;
    while (std::cin >> tdee) {
        if (tdee > 1 && tdee < 2) {
            break;
        } else {
            std::cerr << "Please enter a value within range:\n";
        }
    }
    
    this->calculate_macros(macros_recommended);
    micros_min.calculate_micros(gender);
    micros_max.calculate_micros_max();  
}
//------
// Calculate user macros etc
/*
 *protein = 1.8 * bodyweight * (program - 0.63);
 *fat = (calories * 0.31) / 9;
 *carb = (calories - (protein * 4) - (fat * 9)) / 4;
 *
 *Carbohydrates have four calories per gram
 *Proteins have four calories per gram
 *Fats have nine calories per gram
 */
void Person::calculate_macros(Macros& macros)
{
    bmr = (0.0481 * weight + 0.0234 * height - 0.0138 * age - 0.4235) * 1000 / 4.186;
    calories = bmr * tdee;

    unsigned protein = 1.8 * weight * (tdee - 0.45);
	unsigned fat = (calories * 0.31) / 9;
	unsigned carbs = (calories - (protein * 4) - (fat * 9)) / 4;
    macros.get_macros(protein, carbs, fat);
}
//------
//Print user data to console
inline void Person::prnt_user()
{
    std::cout << "\nAge:" << age << " Heigh:" << height << "cm Weight:" << weight << "kg BMR:" << bmr << std::endl;
    std::cout << "Your estimated daily maintenance calories are: " << calories << "\n" << std::endl;
    macros_recommended.prnt_macros();
    micros_min.prnt_micros(micros_max, micros_intake);
}
//------
//Add food to users intake
void Person::add_food(Food& foodDatabase, int id)
{
    std::cout << "How much " << foodDatabase.returnName(id) << " will you consume in a day? (grams)\n";
    double grams;
    std::cin >> grams;
    std::tuple<std::string,double> food_item(foodDatabase.returnName(id), grams);
    //Add food item to user list
    food_list.push_back(food_item);
    //Add food nutritional information to user intake
    macros_intake.add_values(foodDatabase.return_macros(foodDatabase, id, grams));
    micros_intake.add_values(foodDatabase.return_micros(foodDatabase, id, grams));
}
//------
//Remove foods from user
void Person::remove_food(Food& foodDatabase)
{
    std::cout << "\nID\n";
    for (int i = 0; i < food_list.size(); ++i) {
        std::cout << i << ": " << std::get<0>(food_list.at(i)) << " " << std::get<1>(food_list.at(i)) << "g" << std::endl;
    }
    std::cout << "\nWhich food item (ID) would you like to remove from your diet?\n";
    int id;
    std::cin >> id;
    std::string foodName = std::get<0>(food_list.at(id));
    double grams = std::get<1>(food_list.at(id));
    std::cout << "Food ID: " << foodDatabase.returnId(foodName) << std::endl;
    macros_intake.subtract_values(foodDatabase.return_macros(foodDatabase, foodDatabase.returnId(foodName), grams));
    micros_intake.subtract_values(foodDatabase.return_micros(foodDatabase, foodDatabase.returnId(foodName), grams));
    food_list.erase(food_list.begin()+id);
}
//------
//Compare users foods to nutrient requirements
void Person::check_diet(Food& foodDatabase)
{
    if (food_list.empty()) {
        std::cout << "\nYou haven't added any foods to your diet yet\n";
        return;
    }
    std::cout << "\nDIET:\n";
    for (int i = 0; i < food_list.size(); ++i) {
        std::cout << std::get<0>(food_list.at(i)) << " " << std::get<1>(food_list.at(i)) << "g" << std::endl;
    }
    std::cout << "\n";
    std::vector<std::string> deficient;
    macros_intake.compare_values(macros_recommended);
    deficient = micros_intake.compare(micros_min);
    std::cout << "Would you like recommendations on foods high in these nutrients(Y/N)?\n";
    char c;
    while (std::cin >> c) {
        c = std::toupper(c);
        if (c == 'Y') {
            foodDatabase.recommend_foods(deficient);
            std::cout << "\nWould you like to add one of these to your diet(Y/N)?\n";
            char v;
            while (std::cin >> v) {
                v = std::toupper(v);
                if (v == 'Y') {
                    std::cout << "Please enter the food id number: \n";
                    int i;
                    std::cin >> i;
                    if (i > 0)
                        add_food(foodDatabase, i);
                    break;
                } else if (v == 'N') {
                    break;
                }
                std::cout << "Please enter 'Y' for yes or 'N' for no: \n";
            }
            return;
        } else if ( c == 'N') {
            return;
        }
        std::cout << "Please enter 'Y' for yes or 'N' for no: \n";
    }
}
//------
#endif