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

int main(){
	std::string s;
	std::ifstream fin;
	std::vector<FigurasGeometricas*> figs;
	float r,g,b,a;

	fin.open("./file_config/infos.txt");

	if(!fin.is_open()){
		std::cout << "ERRO!" << std::endl;
	}

	while(fin.good()){
		fin >> s;
		if(s.compare("dim") == 0){
			int larg, alt, prof;
			fin >> larg; fin >> alt; fin >> prof;
			Sculptor s(larg,alt,prof);
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
			figs.push_back(new cutVoxel(x0,y0,z0));
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
			int x0, y0, z0, raio; 
			fin >> x0; fin >> y0; fin >> z0; fin >> raio; 
			fin >> r; fin >> g; fin >> b; fin >> a;
			figs.push_back(new PutEllipsoid(x0,y0,z0,raio,r,g,b,a));
		}
		if(s.compare("cutellipsoid") == 0){
			int x0, y0, z0, raio; 
			fin >> x0; fin >> y0; fin >> z0; fin >> raio; 
			figs.push_back(new PutEllipsoid(x0,y0,z0,raio,r,g,b,a));
		}
	}

	return 0;
}
