#include "csv.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void CSV::read(std::string fileName) 
{
	std::vector<std::string> row;
	std::string line, word;
	std::ifstream file(fileName);

	
	if (file.is_open())
	{
		while (getline(file, line))
		{
			// Remove new line char
			// line.pop_back();

			row.clear();

			std::stringstream str(line);

			while (getline(str, word, ','))
			{
				// Add processing to handle ' characters and empty space 
				word.erase(remove(word.begin(), word.end(), '\''), word.end());

				if (word == "" || word.size() < 2 && std::isspace(word[0]))
					word = "NULL";
				row.push_back(word);
			}
			if (word == "" || word.size() < 2 && std::isspace(word[0]))
				word = "NULL";
			row.push_back(word);
			content.push_back(row);
		}
	}
	else
		std::cout << "Could not open the file\n";

	/* Print data
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			std::cout << content[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/
}
