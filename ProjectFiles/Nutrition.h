#ifndef NUTRITION_H
#define NUTRITION_H

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"


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

class NutritionalRequirements
{

};

//Get Macronutritional information
void Macros::get_macros(unsigned p, unsigned c, unsigned f)
{
    protein = p;
    carbs = c;
    fat = f;
}

//Store Recommended Micronutrient Data
void Micros::calculate_micros(char gender)
{
    if (gender == 'M') {
    /*---VITAMINS---*/  A = 900/*mcg*/;
                        B1 = 1.2/*mg*/; 
                        B2 = 1.3/*mg*/; 
                        B3 = 16/*mg*/; 
                        B5 = 5/*mg*/; 
                        B6 = 1.3/*mg*/; 
                        B9 = 400/*mcg*/; 
                        B12 = 2.4/*mcg*/; 
                        Biotin = 30/*mcg*/; 
                        C = 90/*mg*/; 
                        Choline = 550/*mg*/; 
                        D = 15/*mcg*/; 
                        E = 15/*mg*/; 
                        K = 120/*mcg*/;
    /*---MINERALS---*/  Calcium = 1000/*mg*/; 
                        Chromium = 35/*mcg*/; 
                        Copper = 0.9/*mg*/; 
                        Fluoride = 4000/*mcg*/; 
                        Iodine = 150/*mcg*/; 
                        Iron = 8/*mg*/; 
                        Magnesium = 420/*mg*/; 
                        Manganese = 2.3/*mg*/; 
                        Molybdenum = 45/*mcg*/; 
                        Phosphorus = 700/*mg*/; 
                        Potassium = 4700/*mg*/; 
                        Selenium = 55/*mcg*/; 
                        Sodium = 2300/*mg*/; 
                        Sulfur = 0/*Unknown*/; 
                        Zinc = 11/*mg*/;
    } else if (gender == 'F') {
    /*---VITAMINS---*/  A = 700/*mcg*/; 
                        B1 = 1.1/*mg*/; 
                        B2 = 1.1/*mg*/; 
                        B3 = 14/*mg*/; 
                        B5 = 5/*mg*/; 
                        B6 = 1.3/*mg*/; 
                        B9 = 400/*mcg*/;
                        B12 = 2.4/*mcg*/; 
                        Biotin = 30/*mcg*/; 
                        C = 75/*mg*/; 
                        Choline = 425/*mg*/; 
                        D = 15/*mcg*/; 
                        E = 15/*mg*/; 
                        K = 90/*mcg*/;
    /*---MINERALS---*/  Calcium = 1000/*mg*/; 
                        Chromium = 25/*mcg*/; 
                        Copper = 0.9/*mg*/; 
                        Fluoride = 3000/*mcg*/; 
                        Iodine = 150/*mcg*/; 
                        Iron = 8/*mg*/; 
                        Magnesium = 320/*mg*/; 
                        Manganese = 1.8/*mg*/; 
                        Molybdenum = 45/*mcg*/; 
                        Phosphorus = 700/*mg*/; 
                        Potassium = 4700/*mg*/; 
                        Selenium = 55/*mcg*/; 
                        Sodium = 2300/*mg*/; 
                        Sulfur = 0/*Unknown*/; 
                        Zinc = 8/*mg*/;
    } else {
        std::cerr << "Invalid user gender!?" << std::endl;
    }
}
//------
//Add micronutritional limits
void Micros::calculate_micros_max()
{
    /*---VITAMINS---*/  A = 3000/*mcg*/; 
                        B3 = 35/*mg*/; 
                        B6 = 100/*mg*/; 
                        B9 = 1000/*mcg*/;
                        C = 2000/*mg*/; 
                        Choline = 3500/*mg*/; 
                        D = 50/*mcg*/; 
                        E = 1000/*mg*/; 
    /*---MINERALS---*/  Calcium = 2500/*mg*/; 
                        Copper = 10/*mg*/; 
                        Fluoride = 10000/*mcg*/; 
                        Iodine = 1100/*mcg*/; 
                        Iron = 45/*mg(vegetarian double this*/; 
                        Manganese = 11/*mg*/; 
                        Molybdenum = 2000/*mcg*/; 
                        Phosphorus = 4000/*mg*/; 
                        Selenium = 400/*mcg*/; 
                        Zinc = 40/*mg(vegetarian double this)*/;
}
//------
//Add protein values
void Macros::add_values(std::vector<int> food_macros)
{
    protein += food_macros[0];
    carbs += food_macros[1];
    fat += food_macros[2];
}
//------
//Get values from input
void Micros::add_values(std::vector<double> food_micros)
{
        //---VITAMINS---
    A += food_micros[0];
    B1 += food_micros[1];
    B2 += food_micros[2];
    B3 += food_micros[3];
    B5 += food_micros[4];
    B6 += food_micros[5];
    B12 += food_micros[6];
    Biotin += food_micros[7];
    C += food_micros[8];
    Choline += food_micros[9];
    D += food_micros[10];
    E += food_micros[11];
    B9 += food_micros[12];
    K += food_micros[13];
    //---MINERALS---
    Calcium  += food_micros[14];
    Chromium += food_micros[15];
    Copper += food_micros[16];
    Fluoride += food_micros[17];
    Iodine += food_micros[18];
    Iron += food_micros[19];
    Magnesium += food_micros[20];
    Manganese += food_micros[21];
    Molybdenum += food_micros[22];
    Phosphorus += food_micros[23];
    Potassium += food_micros[24];
    Selenium += food_micros[25];
    Sodium += food_micros[26];
    Sulfur += food_micros[27];
    Zinc += food_micros[28];
}
//------
void Macros::subtract_values(std::vector<int> food_macros)
{
    protein -= food_macros[0];
    carbs -= food_macros[1];
    fat -= food_macros[2];
}
//Get values from input
void Micros::subtract_values(std::vector<double> food_micros)
{
        //---VITAMINS---
    A -= food_micros[0];
    B1 -= food_micros[1];
    B2 -= food_micros[2];
    B3 -= food_micros[3];
    B5 -= food_micros[4];
    B6 -= food_micros[5];
    B12 -= food_micros[6];
    Biotin -= food_micros[7];
    C -= food_micros[8];
    Choline -= food_micros[9];
    D -= food_micros[10];
    E -= food_micros[11];
    B9 -= food_micros[12];
    K -= food_micros[13];
    //---MINERALS---
    Calcium  -= food_micros[14];
    Chromium -= food_micros[15];
    Copper -= food_micros[16];
    Fluoride -= food_micros[17];
    Iodine -= food_micros[18];
    Iron -= food_micros[19];
    Magnesium -= food_micros[20];
    Manganese -= food_micros[21];
    Molybdenum -= food_micros[22];
    Phosphorus -= food_micros[23];
    Potassium -= food_micros[24];
    Selenium -= food_micros[25];
    Sodium -= food_micros[26];
    Sulfur -= food_micros[27];
    Zinc -= food_micros[28];
}
//------
// Print Macronutrient data
inline void Macros::prnt_macros()
{
    std::cout << "Recommended\n\n" << "Macronutrients:\n" << "Carbohydrates: " << carbs << "g" << "\n"
              << "Fat: " << fat << "g" << "\n"
              << "Protein: " << protein << "g" << "\n" << std::endl;
}
//------
// Print Micronutrient data
inline void Micros::prnt_micros(Micros& max, Micros& intake)
{
    std::cout << "Micronutrients: \n" <<
                "---VITAMINS---\n" << 
                    "A \tmin:" << A << "mcg\tmax:" << max.A << "mcg\tintake:" << intake.A << "mcg" <<
                    "\nB1 \tmin:" << B1 << "mg\tmax:Unknown" /*max.B1*/ << "\tintake:" << intake.B1 << "mg" <<
                    "\nB2 \tmin:" << B2 << "mg\tmax:Unknown" /*max.B2*/ << "\tintake:" << intake.B2 << "mg" <<
                    "\nB3 \tmin:" << B3 << "mg\tmax:" << max.B3 << "mg\tintake:" << intake.B3 << "mg" <<
                    "\nB5 \tmin:" << B5 << "mg\t\tmax:Unknown" << /*max.B5 <<*/ "\tintake:" << intake.B5 << "mg" <<
                    "\nB6 \tmin:" << B6 << "mg\tmax:" << max.B6 << "mg\tintake:" << intake.B6 <<
                    "mg\nB9 \tmin:" << B9 << "mcg\tmax:" << max.B9 << "mcg\tintake:" << intake.B9 <<
                    "mcg\nB12 \tmin:" << B12 << "mcg\tmax:Unknown" << /*max.B12 <<*/ "\tintake:" << intake.B12 << "mcg" <<
                    "\nBiotin\tmin:" << Biotin << "mcg\tmax:Unknown" << /*max.Biotin << */ "\tintake:" << intake.Biotin << "mcg" <<
                    "\nC \tmin:" << C << "mg\tmax:" << max.C << "mg\tintake:" << intake.C <<
                    "mg\nCholine\tmin:" << Choline << "mg\tmax:" << max.Choline << "mg\tintake:" << intake.Choline <<
                    "mg\nD \tmin:" << D << "mcg\tmax:" << max.D << "mcg\tintake:" << intake.D <<
                    "mcg\nE \tmin:" << E << "mg\tmax:" << max.E << "mg\tintake:" << intake.E <<
                    "mg\nK \tmin:" << K << "mcg\tmax:Unknown" << /*max.K << "mcg\n" <<*/ "\tintake:" << intake.K << "mg" <<
                "\n---MINERALS---\n" << 
                    "Calcium \tmin:" << Calcium << "mg\tmax:" << max.Calcium << "mg\tintake:" << intake.Calcium <<
                    "mg\nChromium\tmin:" << Chromium << "mcg\tmax:Unknown" << /*max.Chromium << */"\tintake:" << intake.Chromium << "mcg" <<
                    "\nCopper\t\tmin:" << Copper << "mg\tmax:" << max.Copper << "mg\tintake:" << intake.Copper <<
                    "mg\nFlouride\tmin:" << Fluoride << "mcg\tmax:" << max.Fluoride << "mcg\tintake:" << intake.Fluoride <<
                    "mcg\nIodine\t\tmin:" << Iodine << "mcg\tmax:" << max.Iodine << "mcg\tintake:" << intake.Iodine <<
                    "mcg\nIron\t\tmin:" << Iron << "mg\t\tmax:" << max.Iron << "mg\tintake:" << intake.Iron <<
                    "mg\nMagnesium\tmin:" << Magnesium << "mg\tmax:Unknown" << /*max.Magnesium <<*/ "\tintake:" << intake.Magnesium << "mg" <<
                    "\nManganese\tmin:" << Manganese << "mg\tmax:" << max.Manganese << "mg\tintake:" << intake.Manganese <<
                    "mg\nMolybdenum\tmin:" << Molybdenum << "mcg\tmax:" << max.Molybdenum << "mcg\tintake:" << intake.Molybdenum <<
                    "mcg\nPhosphorus\tmin:" << Phosphorus << "mg\tmax:" << max.Phosphorus << "mg\tintake:" << intake.Phosphorus <<
                    "mg\nPotassium\tmin:" << Potassium << "mg\tmax:Unknown" << /*max.Potassium <<*/ "\tintake:" << intake.Potassium <<
                    "mg\nSelenium\tmin:" << Selenium << "mcg\tmax:" << max.Selenium << "mcg\tintake:" << intake.Selenium <<
                    "mcg\nSodium\t\tmin:" << Sodium << "mg\tmax:Unknown" << /*max.Sodium <<*/ "\tintake:" << intake.Sodium << "mg" <<
                    "\nSulfur\t\tmin:" << /*Sulfur <<*/ "Unknown\tmax:Unknown" << /*max.Sulfur <<*/ "\tintake:" << intake.Sulfur << "mg" <<
                    "\nZinc\t\tmin:" << Zinc << "mg  \tmax:" << max.Zinc << "mg\tintake:" << intake.Zinc << "mg" <<  std::endl;
}
//------
void Macros::compare_values(Macros& min)
{
    if (protein < min.protein) {
        std::cout << "Low in Protein\n"
                  << "Try getting " << min.protein - protein << "g more protein\n";
    }
    if (carbs < min.carbs) {
        std::cout << "Low in Carbohydrates\n"
                  << "Try getting " << min.carbs - carbs << "g more carbohydrates\n";
    }
    if (fat < min.fat) {
        std::cout << "Low in Fats\n"
                  << "Try getting " << min.fat - fat << "g more fats\n";
    }
    std::cout << std::endl;
}
//Function compares user intake to micronutritional requirements
std::vector<std::string> Micros::compare(Micros& min)
{
    std::vector<std::string> deficient;
    if (A < min.A){
        std::cout << "Low in Vitamin A\n";
        deficient.push_back("A");
    }
    if (B1 < min.B1) {
        std::cout << "Low in Vitamin B1\n";
        deficient.push_back("B1");
    }
    if (B2 < min.B2) {
        std::cout << "Low in Vitamin B2\n";
        deficient.push_back("B2");
    }
    if (B3 < min.B3) {
        std::cout << "Low in Vitamin B3\n";
        deficient.push_back("B3");
    }
    if (B5 < min.B5) {
        std::cout << "Low in Vitamin B5\n";
        deficient.push_back("B5");
    }
    if (B6 < min.B6) {
        std::cout << "Low in Vitamin B6\n";
        deficient.push_back("B6");
    }
    if (Biotin < min.Biotin) {
        std::cout << "Low in Vitamin Biotin\n";
        deficient.push_back("B7");
    }
    if (B9 < min.B9) {
        std::cout << "Low in Vitamin B9\n";
        deficient.push_back("B9");
    }
    if (B12 < min.B12) {
        std::cout << "Low in Vitamin B12\n";
        deficient.push_back("B12");
    }
    if (C < min.C) {
        std::cout << "Low in Vitamin C\n";
        deficient.push_back("C");
    }
    if (Choline < min.Choline) {
        std::cout << "Low in Vitamin Choline\n";
        deficient.push_back("Choline");
    }
    if (D < min.D) {
        std::cout << "Low in Vitamin D\n";
        deficient.push_back("D");
    }
    if (E < min.E) {
        std::cout << "Low in Vitamin E\n";
        deficient.push_back("E");
    }
    if (K < min.K) {
        std::cout << "Low in Vitamin K\n";
        deficient.push_back("K");
    }
    //---MINERALS---
    if (Calcium < min.Calcium) {
        std::cout << "Low in Calcium\n";
        deficient.push_back("Ca");
    }
    if (Chromium < min.Chromium) {
        std::cout << "Low in Chromium\n";
        deficient.push_back("Cr");
    }
    if (Copper < min.Copper) {
        std::cout << "Low in Copper\n";
        deficient.push_back("Cu");
    }
    if (Fluoride < min.Fluoride) {
        std::cout << "Low in Flouride\n";
        deficient.push_back("F");
    }
    if (Iodine < min.Iodine) {
        std::cout << "Low in Iodine\n";
        deficient.push_back("I");
    }
    if (Iron < min.Iron) {
        std::cout << "Low in Iron\n";
        deficient.push_back("Fe");
    }
    if (Magnesium < min.Magnesium) {
        std::cout << "Low in Magnesium\n";
        deficient.push_back("Mg");
    }
    if (Manganese < min.Manganese) {
        std::cout << "Low in Manganese\n";
        deficient.push_back("Mn");
    }
    if (Molybdenum < min.Molybdenum) {
        std::cout << "Low in Molybdenum\n";
        deficient.push_back("Mo");
    }
    if (Phosphorus < min.Phosphorus) {
        std::cout << "Low in Phosphorus\n";
        deficient.push_back("P"); 
    }
    if (Potassium < min.Potassium) {
        std::cout << "Low in Potassium\n";
        deficient.push_back("K");
    }
    if (Selenium < min.Selenium) {
        std::cout << "Low in Selenium\n";
        deficient.push_back("Se"); 
    }
    if (Sodium < min.Sodium) {
        std::cout << "Low in Sodium\n";
        deficient.push_back("Na");
    }
    if (Sulfur < min.Sulfur) {
        std::cout << "Low in Sulfur\n";
        deficient.push_back("S");
    }
    if (Zinc < min.Zinc) {
        std::cout << "Low in Zinc\n";
        deficient.push_back("Zn");
    }
    
    return deficient;
}

#endif