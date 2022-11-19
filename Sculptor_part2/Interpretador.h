#ifndef Interpretador_H
#define Interpretador_H
#include <fstream>
#include <string>
#include <vector>
#include "FiguraGeometrica.h"

class Interpretador{
   private:
	   std::string s;
	   std::ifstream fin;
	   int larg, alt, prof;
  public:
   Interpretador(const char* file);
   ~Interpretador();
   int get_larg();
   int get_alt();
   int get_prof();
   void run(std::vector<FiguraGeometrica*> &figs);
};
#endif
