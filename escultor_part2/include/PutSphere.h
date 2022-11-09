#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include <FiguraGeometrica.h>


class PutSphere : public FiguraGeometrica
{
    private:
        int xcenter, ycenter, zcenter, radius;
    public:
        PutSphere(int xcenter, int ycenter, int zcenter, int radius);
        virtual ~PutSphere();
        void draw(Sculptor &s);
};

#endif // PUTSPHERE_H
