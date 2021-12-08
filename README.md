# Nutritional Assistant
#### Video Demo: https://youtu.be/xk9OZazwo7g
#### Description: Nutritional Assistant is a text based program designed to calculate the users nutritional requirements and suggest dietry improvements based on that information.

#  Usage  
Launching the executable file will run through a series of questions to set up your user data.
From there you will have to option to View your user data, Search for foods (and add them to your diet), Check your diet and how it compares to your recommended nutritional intakes, and Remove foods from your diet.

##### DISCLAIMER
Please keep in mind all information is just a suggestion, I am not a doctor nor a nutritional expert. This program was developed to improve my skills as a programmer and assist in looking after my own health.
For medical advice consult with a doctor.

#  Design  
I decided to learn a new lagnuage on my own and as I enjoyed the C component of the CS50 course the most I settled on C++. This is my first major project written in the language so it may not be the most efficient but I have enjoyed learning how this language works. The choice of program for my final project wasn't one I made until I had most of my program written. I was originally developing this program for myself as I enjoy working out which seems to be an even split of physical exercise and diet and I also was getting a serious case of 'brain fog' which I assumed my diet was playing a role in. Overall there were a lot of inneficiencies in my life I believed a healthy diet would improve. The skills I learnt within programming from CS50 were a perfect fit to solve this kind of problem, and I wanted to push myself by applying a solution with this new language I was learning on my own (C++). I downloaded the `FoodNutrientDatabase.csv` database file from my local governments website (https://www.foodstandards.gov.au/science/monitoringnutrients/afcd/pages/default.aspx).

There have been many design implementations I have made to improve the program over all. For instance, 
I found myself grouping data visually in regards to what they represented (Users data, macronutritional data, micronutritional data) as I originally had them all stored under one object. Due to the effort I was putting into seperating the groups of data visually within the same object I decided to create a class containing each groups data and storing all of that in an object of a class reffering to each group. This has made not only storing data but calling functions reffering to each group of data much more organised and accessable as the programmer.
A negative side effect of this data segregation was that information used from one class to calculate another was now copied to that classes function for calculations. I resolved this by, where possible, sending data (within the program) via reference to it's location in memory rather than copy it's values to improve on memory usage efficiency. I also added #include guards on my header files (containing the classes) to avoid double declaration of any identifiers.

Looking ahead there are many improvements I will work towards implementing that include:
- storing the users data to file in an encrypted secure method, and allow for multiple users
- ammend program with a more comprehensive nutritional database (current database doesn't have food item information including vitamin K, or Choline)
- the ability to add/edit food data within the database
- dietry requirement information within users data (for instance if user is vegetarian than foods flagged as non-vegetarian will not show up in users searches)


#### Beta0.cpp
Is the main file that loops over the 'main menu' selection of functions that make up the project. I decided to split the different groups of information into classes to hold functions that make working with their respective data much easier.

#### FoodNutrientDatabase.csv
Is a coma seperated value file containing nutritional information on common foods and beverages, this raw data is what the program uses to search, calculate, and suggest all food information you see during usage.

#### Database.h
Is the header file containing the 'Food' Class which stores and queries information from `FoodNutrientDatabase.csv`. The Food class has functions to load a database into memory, search the stored database, return micronutritional information from the database, return macronutritional information from the database, return a food items name based on it's location in the database, return a food items location in the database based on it's name, recommend foods based on a vector of symbols reffering to nutritional values needed. Calling functions using an object of this class makes working with the information within the database much easier. For example when an object of class Person wishes to suggest food items to the user based on thier macronutritional deficiencies, the object of class Person calls the object of databases (that currently has the `FoodNutrientDatabase.csv` data stored in memory) function recommend_foods. This function only requires that a vector of symbols reffering to the nutrient it wishes to suggest as the Food class handles the mapping of where each nutrients data is stored within the csv file.

#### Person.h
Is the header file storing the Person class which holds all the users data. This class also contains functions to get user data, print user data, calculate the users macronutritional requirements, add food items to the users diet, check the users diet, and remove foods from the users diet.

#### Nutrition.h
Is the header containing the Macros and Micros classes. These classes are used to keep track of the data for minimum, maximum, and intake values. The Macros class has functions to get macronutritional data to store, print the macronutritional data, compare two sets of macronutritional data. 
The Micros class has functions to calculate a users maximum intake, calculate a users minimum intake, print all micronutritional data, add micronutritional data to an object of it's type, subtract micronutritional data from an object of it's type, and compare micronutritional data with an object of it's type.
