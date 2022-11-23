#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sculptor.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"
#include "figurageometrica.h"
#include "Interpretador.h"

int main(){
    int larg, alt, prof;

    Sculptor *sc;
    std::vector<FiguraGeometrica*> figs;
    std::vector<FiguraGeometrica*>::iterator it;
    Interpretador inter("../files_config/info.txt");
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
