#ifndef MAP_H
#define MAP_H
#include <string>
#include <iostream>

class Map
{
	private:
		std::string *words;
		bool classification;
		bool *present;

	public:
		static const int size = 82;
		Map()
    {
			words = new std::string[size] {
				"DATA",
				"RESEARCHERS",
				"IMAGES",
				"COMPUTER",
				"ERROR",
				"KEY",
				"INFORMATION",
				"NEW",
				"PEOPLE",
				"PROGRAM",
				"DEVICES",
				"AUTOMATICALLY",
				"SOURCE",
				"SYSTEM",
				"WIRELESS",
				"REDUCE",
				"TASK",
				"MATERIALS",
				"IMAGENET",
				"SYSTEMS",
				"COMPUTATION",
				"TYPES",
				"PROCESS",
				"PRODUCE",
				"LARGE",
				"OBJECT",
				"USER",
				"LOGICAL",
				"PRACTICE",
				"HUMAN",
				"DESIGNED",
				"ALGORITHMS",
				"ENERGY",
				"NETWORK",
				"ARCHITECTURES",
				"RANDOM",
				"ELECTRONIC",
				"ELECTRICITY",
				"YEARS",
				"ACTIVE",
				"UNITED",
				"STATES",
				"SET",
				"SEASON",
				"POETRY",
				"LAND",
				"FOOD",
				"AREA",
				"WROTE",
				"WORKED",
				"WAR",
				"WALLS",
				"VOICE",
				"UKRAINIAN",
				"STEALS",
				"SMALL",
				"SINGLE",
				"SHELL",
				"SERVED",
				"SECOND",
				"SCIENTISTS",
				"RECORDED",
				"PLANT",
				"ORGANISATIONS",
				"NAME",
				"MEMBERS",
				"LIFE",
				"FILM",
				"FAMILY",
				"EVIL",
				"EQUIPMENT",
				"EPISCOPAL",
				"DEVELOPMENT",
				"DAY",
				"DAIRY",
				"CULTURAL",
				"CULTIVATED",
				"COMMUNITY",
				"BIORDERED",
				"AUSTRALIA",
				"AUDIENCE",
				"ARAB"
			};
			present = new bool[size] {0};
		}

		void set(std::string);
		void print();
		void classify(bool);
		bool get(std::string);
		bool get(int);
		bool getclass();
};

void Map::set(std::string word)
{
	for (int i = 0; i < size; i++)
  {
		if (words[i] == word)
    {
			present[i] = 1;
			return;
		}
	}
}

void Map::print()
{
	for (int i = 0; i < size; i++)
  {
		std::cout << present[i];
	}
	std::cout << "\n";
}

void Map::classify(bool type)
{
	classification = type;
}

bool Map::get(std::string word)
{
	for (int i = 0; i < size; i++)
  {
		if (words[i] == word)
    {
			return present[i];
		}
	}

	return 0;
}

bool Map::get(int index)
{
	if (index >= 0 && index < size)
  {
		return present[index];
	}

	return 0;
}

bool Map::getclass()
{
	return classification;
}

#endif
