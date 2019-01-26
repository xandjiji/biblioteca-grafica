
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include "cg2d.h"

#define EventMask (KeyPressMask | ExposureMask)

#define PI 3.1415926535



float XWMax, XWMin, YWMax, YWMin, ZWMax, ZWMin;

float xCp, yCp, zCp, xVp, yVp, zVp, zVp;

float vupX , vupY, vupZ;

float nX, nY, nZ;



struct Point3D {
  float x,
        y,
        z;
  int   color;
  };
      
typedef struct Point3D point3;

struct Face3D {
  int numbers_of_points;
  point3 * points;
  };

typedef struct Face3D face; 

struct Object3D {
  int numbers_of_faces;
  face * faces;
  };

typedef struct Object3D object3; 




//  limites do mundo
void SetWorld3d(float, float, float, float, float, float);

//  pontos e objetos no mundo 
point3 * SetPoint3(float, float, float, int);
face * CreateFace(int);
object3 * CreateObject3(int);
int SetObject3(face *, object3 *);
face * SetFace(point3 *, face *);

int SetProjCenter(float, float, float);
int SetObsPlane(float, float, float);
int SetViewPlane(float, float, float);
int SetProjPlane(float, float, float);


int DrawObject3D(object3 *, window *, bufferdevice *);



