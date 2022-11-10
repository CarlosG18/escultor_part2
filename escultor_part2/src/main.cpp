#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "Sculptor.h"
//#include "PutVoxel.h"
//#include "PutBox.h"
//#include "PutSphere.h"
//#include "PutEllipsoid.h"
//#include "CutVoxel.h"
//#include "CutBox.h"
//#include "CutSphere.h"
//#include "CutEllipsoid.h"


int main(){

	std::string s;
	std::ifstream fin;
	//std::vector<FigurasGeometricas> figs;
	//Sculptor *sp;
	std::vector<int> numeros;

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
			//sp = new Sculptor(larg,alt,prof);
			std::cout << "dim " << larg << " " << alt << " " << prof << "\n";
		}
		if(s.compare("putvoxel") == 0){
			int x0, y0, z0;
			fin >> x0; fin >> y0; fin >> z0; 
			fin >> r; fin >> g; fin >> b; fin >> a;
			//sp.setColor(r,g,b);
			//figs.push_back(new PutVoxel(x0,y0,z0));
			std::cout << "putvoxel(" << x0 << "," << y0 << "," << z0 << "," << r << "," << g << "," << b << "," << a << ")\n";
		}
		if(s.compare("cutvoxel") == 0){
			int x0, y0, z0;
			fin >> x0; fin >> y0; fin >> z0; 
			//figs.push_back(new cutVoxel(x0,y0,z0));
			std::cout << "cutvoxel(" << x0 << "," << y0 << "," << z0 << ")\n";
		}
		if(s.compare("putbox") == 0){
			int x0, x1, y0, y1, z0, z1; 
			fin >> x0; fin >> x1; fin >> y0; fin >> y1; fin >> z0; fin >> z1; 
			fin >> r; fin >> g; fin >> b; fin >> a;
			//sp.setColor(r,g,b);
			//figs.push_back(new PutBox(x0,x1,y0,y1,z0,z1));
			std::cout << "putbox(" << x0 << "," << x1 << "," << y0 << "," << y1 << "," << z0 << "," << z1 << "," << r << "," << g << "," << b << "," << a << ")\n";
		}
		if(s.compare("cutbox") == 0){
			int x0, x1, y0, y1, z0, z1; 
			fin >> x0; fin >> x1; fin >> y0; fin >> y1; fin >> z0; fin >> z1;
			//figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1)); 
			std::cout << "cutbox(" << x0 << "," << x1 << "," << y0 << "," << y1 << "," << z0 << "," << z1 << ")\n";
		}
		if(s.compare("putsphere") == 0){
			int x0, y0, z0, raio; 
			fin >> x0; fin >> y0; fin >> z0; fin >> raio; 
			fin >> r; fin >> g; fin >> b; fin >> a;
			//sp.setColor(r,g,b);
			//figs.push_back(new PutSphere(x0,y0,z0,raio));
			std::cout << "putsphere(" << x0 << "," << y0 << "," << z0 << "," << raio << "," << r << "," << g << "," << b << "," << a << ")\n";
		}
		if(s.compare("cutsphere") == 0){
			int x0, y0, z0, raio; 
			fin >> x0; fin >> y0; fin >> z0; fin >> raio; 
			//figs.push_back(new CutSphere(x0,y0,z0,raio));
			std::cout << "cutsphere(" << x0 << "," << y0 << "," << z0 << "," << raio << ")\n";
		}
		if(s.compare("putellipsoid") == 0){
			int x0, y0, z0, raio; 
			fin >> x0; fin >> y0; fin >> z0; fin >> raio; 
			fin >> r; fin >> g; fin >> b; fin >> a;
			//sp.setColor(r,g,b);
			//figs.push_back(new PutEllipsoid(x0,y0,z0,raio));
			std::cout << "putellipsoid(" << x0 << "," << y0 << "," << z0 << "," << raio << "," << r << "," << g << "," << b << "," << a << ")\n";
		}
		if(s.compare("cutellipsoid") == 0){
			int x0, y0, z0, raio; 
			fin >> x0; fin >> y0; fin >> z0; fin >> raio; 
			//figs.push_back(new PutEllipsoid(x0,y0,z0,raio));
			std::cout << "cutellipsoid(" << x0 << "," << y0 << "," << z0 << "," << raio << ")\n";
		}
	}

	return 0;
}
