#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
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

int main(){
    std::string s;
    std::ifstream fin;
    Sculptor *sc;
    std::vector<FiguraGeometrica*> figs;
    std::vector<FiguraGeometrica*>::iterator it;
    float r,g,b,a;

    fin.open("../files_config/info.txt");

    if(!fin.is_open()){
        std::cout << "ERRO!" << std::endl;
    }

    while(fin.good()){
        fin >> s;
        if(s.compare("dim") == 0){
            int larg, alt, prof;
            fin >> larg; fin >> alt; fin >> prof;
            sc = new Sculptor(larg,alt,prof);
        }
        if(s.compare("putvoxel") == 0){
            int x0, y0, z0;
            fin >> x0; fin >> y0; fin >> z0;
            fin >> r; fin >> g; fin >> b; fin >> a;
            figs.push_back(new PutVoxel(x0,y0,z0,r,g,b,a));
        }
        if(s.compare("cutvoxel") == 0){
            int x0, y0, z0;
            fin >> x0; fin >> y0; fin >> z0;
            figs.push_back(new CutVoxel(x0,y0,z0));
        }
        if(s.compare("putbox") == 0){
            int x0, x1, y0, y1, z0, z1;
            fin >> x0; fin >> x1; fin >> y0; fin >> y1; fin >> z0; fin >> z1;
            fin >> r; fin >> g; fin >> b; fin >> a;
            figs.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        }
        if(s.compare("cutbox") == 0){
            int x0, x1, y0, y1, z0, z1;
            fin >> x0; fin >> x1; fin >> y0; fin >> y1; fin >> z0; fin >> z1;
            figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
        }
        if(s.compare("putsphere") == 0){
            int x0, y0, z0, raio;
            fin >> x0; fin >> y0; fin >> z0; fin >> raio;
            fin >> r; fin >> g; fin >> b; fin >> a;
            figs.push_back(new PutSphere(x0,y0,z0,raio,r,g,b,a));
        }
        if(s.compare("cutsphere") == 0){
            int x0, y0, z0, raio;
            fin >> x0; fin >> y0; fin >> z0; fin >> raio;
            figs.push_back(new CutSphere(x0,y0,z0,raio));
        }
        if(s.compare("putellipsoid") == 0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            fin >> xcenter; fin >> ycenter; fin >> zcenter; fin >> rx; fin >> ry; fin >> rz;
            fin >> r; fin >> g; fin >> b; fin >> a;
            figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz,r,g,b,a));
        }
        if(s.compare("cutellipsoid") == 0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            fin >> xcenter; fin >> ycenter; fin >> zcenter; fin >> rx; fin >> ry; fin >> rz;
            figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
        }
    }

    for(it = figs.begin(); it!=figs.end();it++){
        (*it)->draw(*sc);
    }

    sc->writeOFF("testes.off");

    return 0;
}
