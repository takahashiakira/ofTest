#ifndef _OF_BALL // if this class hasn't been defined, the program can define it
#define _OF_BALL // by using this if statement you prevent the class to be called more

// than once which would confuse the compiler

#include "ofMain.h"


class ofBall {
  
  public:
    void update();
    void draw();
  
    // variables
    float x;
    float y;
    int dim;
    float speedY;
    float speedX;
    unsigned char colorR;
    unsigned char colorG;
    unsigned char colorB;
  
    ofBall(float x, float y, int dim, float speedX, float speedY, unsigned char colorR, unsigned char colorG, unsigned char colorB);
  
  private:
    
};

#endif