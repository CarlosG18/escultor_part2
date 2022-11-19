#include "Interpretador.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "PutVoxel.h"
#include "FiguraGeometrica.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"
#include "Sculptor.h"

Interpretador::Interpretador(const char* file){
	fin.open(file);

	if(!fin.is_open()){
		std::cout << "ERRO!" << std::endl;
	}else{
		std::cout << "leitura do arquivo bem sucedida!" << std::endl;
	}
}
Interpretador::~Interpretador(){

}

int Interpretador::get_larg(){
	return larg;
}

int Interpretador::get_alt(){
        return alt;
}

int Interpretador::get_prof(){
        return prof;
}

void Interpretador::run(std::vector<FiguraGeometrica*> &figs)
{
	float r,g,b,a;

	while(fin.good()){
        fin >> s;
	if(s.compare("dim") == 0){
         fin >> this->larg; fin >> this->alt; fin >> this->prof;
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

}
