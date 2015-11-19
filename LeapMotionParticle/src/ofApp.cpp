#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Window Setting
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(31);
    // Lighting, Camera
    ofEnableLighting();
    light.setPosition(200, 300, 50);
    light.enable();
    cam.setOrientation(ofPoint(-20, 0, 0));
    // Start Leap Motion
    leap.open();
    // Init Peticle
    for (int i = 0; i < NUM; i++) {
        particles[i].position.set(ofRandom(-ofGetWidth()/2.0, ofGetWidth()/2.0),
                                  ofRandom(-ofGetHeight()/2.0, ofGetHeight()/2.0),
                                  ofRandom(-ofGetHeight()/2.0, ofGetHeight()/2.0));
        particles[i].friction = 0.005;
        particles[i].minx = -ofGetWidth()/2.0;
        particles[i].maxx = ofGetWidth()/2.0;
        particles[i].miny = -ofGetWidth()/2.0;
        particles[i].maxy = ofGetWidth()/2.0;
        particles[i].minz = -ofGetWidth()/2.0;
        particles[i].maxz = ofGetWidth()/2.0;
    }
    // Init Mesh
    mesh.setMode(OF_PRIMITIVE_POINTS);
    static GLfloat distance[] = { 0.0, 0.0, 1.0 };
    glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
    glPointSize(3000);
}

//--------------------------------------------------------------
void ofApp::update(){
    // Get hand in Leap Motion SDK to vactor array
    vector <Hand> hands = leap.getLeapHands();
    
    // When detect hand
    if( leap.isFrameNew() && hands.size() ){
        // Clear pos in vector array
        fingerPos.clear();
        spherePos.clear();
        sphereSize.clear();
        
        // Mapping scale when changing window size
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        for(int i = 0; i < hands.size(); i++){
            // Get finger pos
            for(int j = 0; j < hands[i].fingers().count(); j++){
                ofVec3f pt;
                const Finger & finger = hands[i].fingers()[j];
                pt = leap.getMappedofPoint( finger.tipPosition() );
                fingerPos.push_back(pt);
            }
        }
    }
    
    // notive old frame to ofxLeapMotion2
    leap.markFrameAsOld();
    
    // Update Perticle, Mesh
    mesh.clear();
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < fingerPos.size(); j++) {
            particles[i].addAttractionForce(fingerPos[j].x, fingerPos[j].y, fingerPos[j].z, ofGetWidth(), 0.1);
        }
        particles[i].update();
        particles[i].throughOffWalls();
        mesh.addVertex(particles[i].position);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    // Start camera
    cam.begin();
    // Repeat fingers number times
    ofSetColor(255, 127, 0, 127);
    for(int i = 0; i < fingerPos.size(); i++){
        // Render sphere at finger pos
        ofSpherePrimitive sphere;
        sphere.setPosition(fingerPos[i].x, fingerPos[i].y, fingerPos[i].z);
        sphere.draw();
    }
    // Render mesh
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(255);
    mesh.draw();
    ofDisableBlendMode();
    // Stop camera
    cam.end();
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
