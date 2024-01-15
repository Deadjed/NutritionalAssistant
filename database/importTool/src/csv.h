#ifndef CSV_H
#define CSV_H
// #pragma once

#include <vector>
#include <string>

class CSV
{
private:
public:
	std::vector<std::vector<std::string>> content;
	void read(std::string fileName);
};

#endif
