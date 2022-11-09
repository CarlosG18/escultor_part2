#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include <FiguraGeometrica.h>
#include "Sculptor.h"

class PutVoxel : public FiguraGeometrica
{
    private:
        int x, y, z;
    public:
        PutVoxel(int x, int y, int z);
        virtual ~PutVoxel();
        void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
