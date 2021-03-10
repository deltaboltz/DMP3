#include <stdio.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include "map.h"
#include "training.h"
#include "data.h"

int main (int argc, char *argv[]) 
{
	std::string sentence;
	int i;
	char c;
	Data d(104);

	for (i = 0; i < 52; i++) 
	{
		d.train(cs_yes[i], 1);
		d.train(cs_no[i], 0);
	}

	for (i = 1; i < argc; i++) 
	{
		sentence += argv[i];
		sentence += " ";
	}
	
	i = 0;
	while (sentence[i]) 
	{
		sentence[i] = toupper(sentence[i]);
		i++;
	}

	for (i = 0; i < 52; i++) 
	{
		Map m = d.vectorize(cs_no[i]);
		//m.print();
		double yes = d.naivebayes_num(m, 1);
		double no = d.naivebayes_num(m, 0);
		double both = yes + no;

		std::cout << cs_yes[i] << "\n";
		std::cout << "    CS: " << yes << "\t(" << (yes / both)*100 << " %)\n";
		std::cout << "NOT CS: " << no << "\t(" << (no / both)*100 << " %)\n\n";
		std::cout << "Class:  " << ((yes > no) ? "    CS\n" : "NOT CS\n\n");
	}
}
