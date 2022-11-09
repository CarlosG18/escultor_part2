#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include <FiguraGeometrica.h>


class CutEllipsoid : public FiguraGeometrica
{
    private:
        int xcenter, ycenter, zcenter, rx, ry, rz;
    public:
        CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz));
        virtual ~CutEllipsoid();
        void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H
