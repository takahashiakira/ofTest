#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  nBalls = 1500; // the number of ball objects we want to create
  myBall = new ofBall*[nBalls];   // an array of pointers for the objects
  
  for (int i = 0; i < nBalls; i++) {
    float x = ofRandom(0, ofGetWidth());
    float y = ofRandom(0, ofGetHeight());
    int dim = ofRandom(1,20);
    float speedX = ofRandom(-5, 5);
    float speedY = ofRandom(-5, 5);
    unsigned char colorR = ofRandom(30, 255);
    unsigned char colorG = ofRandom(30, 255);
    unsigned char colorB = ofRandom(30, 255);
    
    myBall[i] = new ofBall(x,y,dim,speedX,speedY,colorR,colorG,colorB);  //create each object from the array
  }

}

//--------------------------------------------------------------
void ofApp::update(){

  for (int i = 0; i < nBalls; i++){
    myBall[i]->update();
  }
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  
  for (int i = 0; i < nBalls; i++){
    myBall[i]->draw();
  }
}







//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
