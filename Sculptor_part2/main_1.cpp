#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sculptor.h"
#include "PutVoxel.h"
#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"
#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"
#include "FiguraGeometrica.h"
#include "Interpretador.h"

int main(){
    int larg, alt, prof;

    Sculptor *sc;
    std::vector<FiguraGeometrica*> figs;
    std::vector<FiguraGeometrica*>::iterator it;
    float r,g,b,a;
    Interpretador inter("info.txt");
    inter.run(figs);
    larg = inter.get_larg();
    alt = inter.get_alt();
    prof = inter.get_prof();
    sc = new Sculptor(larg,alt,prof);
    
    for(it = figs.begin(); it!=figs.end();it++){
        (*it)->draw(*sc);
    }
    sc->writeOFF("testes.off");	

    return 0;
}
