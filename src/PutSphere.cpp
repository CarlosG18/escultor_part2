#include "PutSphere.h"
#include "sculptor.h"

PutSphere::~PutSphere()
{
    //dtor
}

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutSphere::draw(Sculptor& s)
{
    int i,j,k;

    s.setColor(r,g,b,a);

    for(k=0; k<s.get_nz(); k++){
        for(j=0; j<s.get_ny(); j++){
            for(i=0; i<s.get_nx(); i++){
                if((((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter))) <= ((radius)*(radius))){
                    s.putVoxel(i,j,k);
                }
            }
        }
    }
}
