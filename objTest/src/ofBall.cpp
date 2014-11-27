#include "ofBall.h"

ofBall::ofBall(float _x, float _y, int _dim, float _speedX, float _speedY, unsigned char _colorR, unsigned char _colorG, unsigned char _colorB) {
  
  x = _x;
  y = _y;
  dim = _dim;
  speedX = _speedX;
  speedY = _speedY;
  colorR = _colorR;
  colorG = _colorG;
  colorB = _colorB;

}

void ofBall::update(){
  
  if(x < 0 ){
    x = 0;
    speedX *= -1;
  } else if(x > ofGetWidth()){
    x = ofGetWidth();
    speedX *= -1;
  }
  if(y < 0 ){
    y = 0;
    speedY *= -1;
  } else if(y > ofGetHeight()){
    y = ofGetHeight();
    speedY *= -1;
  }
  x+=speedX;
  y+=speedY;
  
}

void ofBall::draw(){
  
  ofCircle(x, y, dim);
  ofSetColor(colorR, colorG, colorB);
  
}