#include "PutEllipsoid.h"
#include "Sculptor.h"

PutEllipsoid::~PutEllipsoid()
{
    //dtor
}

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutEllipsoid::draw(Sculptor& s)
{
    int i,j,k;

    s.setColor(r,g,b,a);

    for(k=0; k<s.get_nz(); k++){
        for(j=0; j<s.get_ny(); j++){
            for(i=0; i<s.get_nx(); i++){
                if(((((float(i-xcenter)/rx))*(float(i-xcenter)/rx))+((float(j-ycenter)/ry)*(float(j-ycenter)/ry))+(((float(k-zcenter)/rz))*((float(k-zcenter)/rz)))) <= 1.0 ){
                    s.putVoxel(i,j,k);
                }
            }
        }
    }
}
