#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutVoxel : public FiguraGeometrica
{
    private:
        int x, y, z;
        float r, g, b, a;
    public:
        PutVoxel(int x, int y, int z,float r, float g, float b, float a);
        virtual ~PutVoxel();
        void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
