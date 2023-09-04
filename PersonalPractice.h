#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <fstream>
class Sprite
{
public:
	std::string n;
	int x;
	int y;
	int w;
	int h;
};

void LoadXML(const char* filename, std::vector<Sprite>& sprites)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit);
	std::string line;
	
	std::regex pattern("\"([^\"]*)\"");

	while (!ifs.eof())
	{
		std::getline(ifs, line);
		size_t result = line.find("<sprite");

		std::sregex_iterator current(line.begin(), line.end(), pattern);
		if (result != std::string::npos)
		{
			Sprite s;
			s.n = (*current)[1];
			current++;
			s.h = std::stoi((*current)[1]);
			current++;
			s.w = std::stoi((*current)[1]);
			current++;
			s.x = std::stoi((*current)[1]);
			current++;
			s.y = std::stoi((*current)[1]);
			current++;

			sprites.push_back(s);
		}
	}
	ifs.close();
}

void LoadXML(const char* filename, std::vector<Sprite>& sprites)
{
	std::ifstream ifs;

	ifs.exceptions(std::ifstream::badbit);
	std::string line;


}