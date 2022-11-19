#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "sculptor.h"
#include <figurageometrica.h>


class CutVoxel : public FiguraGeometrica
{
    private:
        int x, y, z;
    public:
        CutVoxel(int x, int y, int z);
        virtual ~CutVoxel();
        void draw(Sculptor &s);
};

#endif // CUTVOXEL_H
