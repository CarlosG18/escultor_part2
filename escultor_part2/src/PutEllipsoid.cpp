#include "PutEllipsoid.h"

PutEllipsoid::~PutEllipsoid()
{
    //dtor
}

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

void PutEllipsoid::draw(Sculptor& s)
{
    int i,j,k;

    for(k=0; k<nz; k++){
        for(j=0; j<ny; j++){
            for(i=0; i<nx; i++){
                if(((((float(i-xcenter)/rx))*(float(i-xcenter)/rx))+((float(j-ycenter)/ry)*(float(j-ycenter)/ry))+(((float(k-zcenter)/rz))*((float(k-zcenter)/rz)))) <= 1.0 ){
                    s->putVoxel(i,j,k);
                }
            }
        }
    }
}

