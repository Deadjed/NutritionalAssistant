#pragma once

#include <vector>
#include <string>

class Macros
{
public:
    void get_macros(unsigned protein, unsigned carbs, unsigned fat);
    inline void prnt_macros();
    void add_values(std::vector<int> food_macros);
    void subtract_values(std::vector<int> food_macros);
    void compare_values(Macros& min);
private:
    unsigned protein = 0;
    unsigned carbs = 0;
    unsigned fat = 0;
};

class Micros
{
public:
    void calculate_micros_max();
    void calculate_micros(char gender);
    inline void prnt_micros(Micros& max, Micros& intake);
    void add_values(std::vector<double> food_micros);
    void subtract_values(std::vector<double> food_micros);
    std::vector<std::string> compare(Micros& min);
private:
    //---VITAMINS---
    double A = 0;
    double B1 = 0;
    double B2 = 0;
    double B3 = 0;
    double B5 = 0;
    double B6 = 0;
    double B12 = 0;
    double Biotin = 0;
    double C = 0;
    double Choline = 0;
    double D = 0;
    double E = 0;
    double B9 = 0;
    double K = 0;
    //---MINERALS---
    double Calcium = 0;
    double Chromium = 0;
    double Copper = 0;
    double Fluoride = 0;
    double Iodine = 0;
    double Iron = 0;
    double Magnesium = 0;
    double Manganese = 0;
    double Molybdenum = 0;
    double Phosphorus = 0;
    double Potassium = 0;
    double Selenium = 0;
    double Sodium = 0;
    double Sulfur = 0;
    double Zinc = 0;
};
