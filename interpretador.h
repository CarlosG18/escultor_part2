#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <string>
#include <fstream>
#include "sculptor.h"
#include <vector>
#include "figurageometrica.h"

class Interpretador
{
private:
    int larg, alt, prof;
    std::string s;
    std::ifstream fin;
    std::vector<FiguraGeometrica*> figs;
    std::vector<FiguraGeometrica*>::iterator it;
public:
    Interpretador(const char* file);
    ~Interpretador();
    void get_dim();
    int get_x();
    int get_y();
    int get_z();
    void run();
    void draw(Sculptor* sc);
};

#endif // INTERPRETADOR_H
