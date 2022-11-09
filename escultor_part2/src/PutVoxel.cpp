#include "PutVoxel.h"
#include "Sculptor.h"

PutVoxel::~PutVoxel()
{
    //dtor
}

PutVoxel::PutVoxel(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void PutVoxel::draw(Sculptor& s)
{
    s->v[z][y][x].isOn = true;
    s->v[z][y][x].r = r;
    s->v[z][y][x].g = g;
    s->v[z][y][x].b = b;
    s->v[z][y][x].a = a;
}
