#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel{
    float r, g, b; // cores: vermelho, verde e azul
    float a; //transparencia
    bool isOn; // "aparecer"
};

class Sculptor
{
    private:
      Voxel ***v; // 3D matrix
      int nx,ny,nz; // Dimensions
      float r,g,b,a; // Current drawing color
    public:
      Sculptor(int _nx, int _ny, int _nz);
      ~Sculptor();
      void setColor(float r, float g, float b, float a);
      void putVoxel(int x, int y, int z);
      void cutVoxel(int x, int y, int z);
      void writeOFF(const char* filename);
      int get_nz();
      int get_ny();
      int get_nx();
};

#endif // SCULPTOR_H
