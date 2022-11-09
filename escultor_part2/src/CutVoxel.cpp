#include "CutVoxel.h"
#include "Sculptor.h"


CutVoxel::~CutVoxel()
{
    //dtor
}

CutVoxel::CutVoxel(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void CutVoxel::draw(Sculptor& s)
{
    s->v[z][y][x].isOn = false;
}
