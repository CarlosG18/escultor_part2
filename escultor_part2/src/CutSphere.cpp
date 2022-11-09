#include "CutSphere.h"

CutSphere::~CutSphere()
{
    //dtor
}

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
}

void CutSphere::draw(Sculptor& s)
{
    int i,j,k;

    for(k=0; k<nz; k++){
        for(j=0; j<ny; j++){
            for(i=0; i<nx; i++){
                if((((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter))) <= ((radius)*(radius))){
                    s->cutVoxel(i,j,k);
                }
            }
        }
    }
}
