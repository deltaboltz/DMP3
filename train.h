
#ifndef TRAIN_H
#define TRAIN_H
#include <iostream>
#include <sstream>
#include <string>
#include "map.h"

class Data
{
private:
  Map *vectors;
  int initialized;
  int maxsize;

public:
  Data(int size)
  {
    vectors = new Map[size];
    maxsize = size;
    initialized = 0;
  }
  void train(std::string, bool);
  double pgiven(int, bool, bool);
  double ptype(bool);
  double naivebayes_num(Map, bool);
  Map vectorize(std::string);
};

void Data::train(std::string sentence, bool type) {
  if (initialized < maxsize)
  {
    std::istringstream iss (sentence);
    std::string word;
    while (iss >> word)
    {
      vectors[initialized].set(word);
    }
  vectors[initialized].classify(type);
  initialized++;
  return;
}
std::cout << "All training vectors have been filled!\n";
}

double Data::pgiven(int index, bool value, bool type)
{
  int count_atr = 0;
  int count_tot = 0;

  for (int i = 0; i < maxsize; i++)
  {
    if (vectors[i].getclass() == type)
    {
      count_tot++;

      if (vectors[i].get(index) == value)
      {
        count_atr++;
      }
    }
  }

  return (double)count_atr / (double)count_tot;
}

double Data::ptype(bool type)
{
  int count = 0;

  for (int i = 0; i < maxsize; i++)
  {
    if (vectors[i].getclass() == type)
    {
      count ++;
    }
  }
  return (double)count / (double)maxsize;
}

double Data::naivebayes_num(Map m, bool type)
{
  double numerator = 1;

  for (int index = 0; index < m.size; index++)
  {
    bool atr = m.get(index);
    double p = pgiven(index, atr, type);
    //std::cout << "P(X_" << index << "=" << atr << " | Y=" << type << ") =" << p << "\n";
    numerator *= p;
  }

  return numerator * ptype(type);
}

Map Data::vectorize(std::string sentence)
{
  Map m;
  std::istringstream iss (sentence);
  std::string word;

  while (iss >> word)
  {
    m.set(word);
  }

  return m;
}
#endif
