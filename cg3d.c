#include "cg3d.h"
#include<math.h>

void SetWorld3d(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax) {
 XWMax = xmax;
 XWMin = xmin;
 YWMax = ymax;
 YWMin = ymin;
 ZWMax = zmax;
 ZWMin = zmin;
 }

point3 * SetPoint3(float x, float y, float z, int color) {
  point3 * pnt;
  
  pnt = (point3 *) malloc(sizeof(point3)); 
  pnt->x = x;
  pnt->y = y;
  pnt->z = z;
  pnt->color = color;
  
  return pnt;
  }

face * CreateFace(int numbers_of_points) {
  face * ob;
 
  ob = (face *) malloc(sizeof(face));
  ob->numbers_of_points = 0;
  ob->points = (point3 *) malloc(numbers_of_points*sizeof(point3));
 
  return ob;
  }

face * SetFace(point3 * pt, face * fc) {
	fc->points[fc->numbers_of_points] = *pt;
	fc->numbers_of_points = fc->numbers_of_points + 1;
}

object3 * CreateObject3(int numbers_of_faces) {
  object3 * ob;
 
  ob = (object3 *) malloc(sizeof(object3));
  ob->numbers_of_faces = 0;
  ob->faces = (face *) malloc(numbers_of_faces*sizeof(face));
 
  return ob;
  }

int SetObject3(face * fc, object3 * ob) {
  ob->faces[ob->numbers_of_faces] = *fc;
  ob->numbers_of_faces = ob->numbers_of_faces + 1;

  return 0;
  }

 


int SetProjCenter(float x, float y, float z) {
  xCp = x;
  yCp = y;
  zCp = z;
  return 1;
}


int SetObsPlane(float x, float y, float z) {
  float size = sqrt((x * x) + (y * y) + (z * z));
  nX = x/size;
  nY = y/size;
  nZ = z/size;
  return 1;
}

int SetViewPlane(float x, float y, float z) {
  float size = sqrt((x * x) + (y * y) + (z * z));
  vupX = x/size;
  vupY = y/size;
  vupZ = z/size;
  return 1;
}

int SetProjPlane(float x, float y, float z) {
  xVp = x;
  yVp = y;
  zVp = z;
  return 1;
}

point * getPointProjection(point3  p) {
  point * p1;

  float planeDistance = zCp - zVp;

  float h = (zCp - p.z)/planeDistance; 

  float vector[1][4] = {{p.x, p.y, p.z , 1.0f}};

  float projectionMatrix[4][4] = {{1.0f, 0.0f, 0.0f,0.0f},
                                  {0.0f, 1.0f, 0.0f,0.0f},
                                  {0.0f, 0.0f, -zVp/planeDistance ,-zVp*(zCp/planeDistance)},
                                  {0.0f, 0.0f, -1.0f/planeDistance, -zCp/planeDistance}};

  float awnserVector[1][4];


  int lin;
  int col;
  int k;
  int soma;
  for (lin = 0; lin < 1; lin++) {
     for (col = 0; col < 4; col++) {
         
        soma = 0;
        for (k = 0; k<4; k++) 
            soma = soma + vector[lin][k]*projectionMatrix[k][col];
        awnserVector[lin][col] = soma;
     }
  }

  p1 = SetPoint(awnserVector[0][0]/h,awnserVector[0][1]/h, p.color);

  return p1;
}

point3 * getPointInSCV(point3 p){

  point3 * novoPonto;

  float uX, uY, uZ;
  float vX, vY, vZ;

  uX = (vupY * nZ) - (vupZ * nY);
  uY = (vupZ * nX) - (vupX * nZ);
  uZ = (vupX * nY) - (vupY * nX);

  float size = sqrt((uX * uX) + (uY * uY) + (uZ * uZ));

  vX = (nY * uZ) - (nZ * uY);
  vY = (nZ * uX) - (nX * uZ);
  vZ = (nX * uY) - (nY * uX);  

  float matrizTransformacao[4][4] = {{uX, uY, uZ, -xCp},
                                    {vX, vY, vZ, -yCp},
                                    {nX, nY, nZ, -zCp},
                                     {0.0f , 0.0f, 0.0f, 1.0f}};

  float vetor[1][4] = {p.x,p.y,p.z, 1.0f};

  float resultado[1][4];

  int lin;
  int col;
  int k;
  int soma;
  for (lin = 0; lin < 1; lin++) {
     for (col = 0; col < 4; col++) {
       
        soma = 0;
        for (k = 0; k<4; k++) 
            soma = soma + vetor[lin][k]*matrizTransformacao[k][col];
        resultado[lin][col] = soma;
     }
  }


  novoPonto = SetPoint3(resultado[0][0],resultado[0][1],resultado[0][2], p.color);
  return novoPonto;
}


int DrawObject3D(object3 * ob, window * win, bufferdevice * dev) {
  int i,j;
  float aux;
  point3 * p1;
  point * p2;

  for (i=0; i<ob->numbers_of_faces; i++) {

    object * object1 = CreateObject(ob->faces[i].numbers_of_points);

    for (j=0; j<ob->faces[i].numbers_of_points; j++) {
      
      p1 = getPointInSCV(ob->faces[i].points[j]);
      p2 = getPointProjection(*p1);

      SetObject(p2, object1);


    }

    DrawObject(object1, win, dev);
  }

  return 0;
}




  
  
