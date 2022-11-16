#include "CutEllipsoid.h"
#include "Sculptor.h"

CutEllipsoid::~CutEllipsoid()
{
    //dtor
}

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

void CutEllipsoid::draw(Sculptor& s)
{
    int i,j,k;

    for(k=0; k<s.get_nz(); k++){
        for(j=0; j<s.get_ny(); j++){
            for(i=0; i<s.get_nx(); i++){
                if(((((float(i-xcenter)/rx))*(float(i-xcenter)/rx))+((float(j-ycenter)/ry)*(float(j-ycenter)/ry))+(((float(k-zcenter)/rz))*((float(k-zcenter)/rz)))) <= 1.0 ){
                    s.cutVoxel(i,j,k);
                }
            }
        }
    }
}
