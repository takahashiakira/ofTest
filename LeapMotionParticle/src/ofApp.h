#pragma once

#include "ofMain.h"
#include "ofxLeapMotion2.h"
#include "ParticleVec3.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxLeapMotion leap; // Instanciation Leap Motion
    ofEasyCam cam; // Camera
    ofLight light; // Lighting
    vector <ofVec3f> fingerPos;     // Array finger pos
    vector <ofVec3f> spherePos;     // Array sphere pos
    vector <float> sphereSize;      // Array sphere size
    ofVboMesh mesh;                 // Mesh
    static const int NUM = 50000;   // Number of perticles
    ParticleVec3 particles[NUM];    // Array Prticles
};
