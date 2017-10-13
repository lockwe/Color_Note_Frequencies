#include "ofApp.h"

void ofInitPart(vector<Particle> &particles) {
    Particle p = Particle(ofColor::blue,
                          ofVec3f(1),
                          ofVec3f(0, 0, 0),
                          ofVec3f(ofRandom(-1, 1),
                                  ofRandom(10, 0),
                                  ofRandom(-1, 1)),
                          ofVec3f(ofRandom(-1, 1),
                                  ofRandom(10, 0),
                                  ofRandom(-1, 1)));
    particles.push_back(p);
    
}


void ofDrawPartMult(int imagenum, int xval, vector<Particle> particles, ofImage images[12]) {
    for (int i = 0; i < particles.size(); ++i) {
        ofPushMatrix();
        particles[i].draw();
        ofSetColor(ofColor::white);
        images[imagenum].draw(xval,500);
        ofPopMatrix();
    }
    
    Particle p = Particle(ofColor::blue,
                          ofVec3f(1),
                          ofVec3f(0, 0, 0),
                          ofVec3f(ofRandom(-1, 1),
                                  ofRandom(10,0),
                                  ofRandom(-1, 1)),
                          ofVec3f(ofRandom(-1, 1),
                                  ofRandom(10, 0),
                                  ofRandom(-1, 1)));
    particles.push_back(p);
}


    


//--------------------------------------------------------------
void ofApp::setup(){
    
    images[0].load("Red-C.png");
    images[1].load("Orange-C#.png");
    images[2].load("Orange-D.png");
    images[3].load("Yellow-D#.png");
    images[4].load("Lime-E.png");
    images[5].load("Green-F.png");
    images[6].load("Teal-F#.png");
    images[7].load("Cyan-G.png");
    images[8].load("Blue-G#.png");
    images[9].load("Navy-A.png");
    images[10].load("Purple-A#.png");
    images[11].load("Magenta-A.png");
    images[12].load("keyboard3.png");
    
    int sampleRate = 44100;
    int bufferSize = 512;
    int outChannels = 0;
    int inChannels = 2;
    
    ofSetFrameRate(30);
    
    // setup the sound stream
    soundStream.setup(this, outChannels, inChannels, sampleRate, bufferSize, 3);
    
    //setup ofxAudioAnalyzer with the SAME PARAMETERS
    audioAnalyzer.setup(sampleRate, bufferSize, inChannels);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    smooth = ofClamp(ofGetMouseX() / (float)ofGetWidth(), 0.0, 1.0); //sets smooth value smooth = 1
    
    //get the analysis values
    rms_l = audioAnalyzer.getValue(RMS, 0, smooth);
    rms_r = audioAnalyzer.getValue(RMS, 1, smooth);
    pitchFreq = audioAnalyzer.getValue(PITCH_FREQ, 0, smooth);
    
    for (int i = 0; i < particles.size(); ++i) {
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cout << particles.size() << endl;
    ofBackground(ofColor::black);
    
    string frequency = ofToString(pitchFreq);
    string words = "Frequency:";
    ofDrawBitmapString(words+frequency, 20, 20);
    
    rms_l = audioAnalyzer.getValue(RMS, 0, smooth);
    rms_r = audioAnalyzer.getValue(RMS, 1, smooth);
    
    images[12].draw(0,0);

    
    if (rms_l > .7 && rms_r > .71){
        
        if (31.7< pitchFreq && pitchFreq < 33.7) {
            ofInitPart(particles);
            ofDrawPartMult(0, 15, particles, images);
            
        }
        
        else if (33.7< pitchFreq && pitchFreq < 35.7) {
            ofInitPart(particles);
            ofDrawPartMult(1, 45, particles, images);
            
        }
        
        else if (35.7< pitchFreq && pitchFreq < 37.8) {
            ofInitPart(particles);
            ofDrawPartMult(2, 75, particles, images);
            
        }
        
        else if (37.8< pitchFreq && pitchFreq < 40) {
            ofInitPart(particles);
            ofDrawPartMult(3, 105, particles, images);
            
        }
        
        else if (40< pitchFreq && pitchFreq < 42.4) {
            ofInitPart(particles);
            ofDrawPartMult(4, 135, particles, images);
            
        }
        
        else if (42.4< pitchFreq && pitchFreq < 44.8) {
            ofInitPart(particles);
            ofDrawPartMult(5, 165, particles, images);
            
        }
        
        else if (44.8< pitchFreq && pitchFreq < 47.5) {
            ofInitPart(particles);
            ofDrawPartMult(6, 195, particles, images);
            
        }
        
        else if (47.5< pitchFreq && pitchFreq < 50.5) {
            ofInitPart(particles);
            ofDrawPartMult(7, 225, particles, images);
            
        }
        
        else if (50.5< pitchFreq && pitchFreq < 53.4) {
            ofInitPart(particles);
            ofDrawPartMult(8, 255, particles, images);
            
        }
        
        else if (53.4< pitchFreq && pitchFreq < 56.6)  {
            ofInitPart(particles);
            ofDrawPartMult(9, 285, particles, images);
            
        }
        
        else if (56.6< pitchFreq && pitchFreq < 60) {
            ofInitPart(particles);
            ofDrawPartMult(10, 315, particles, images);
            
        }
        
        else if (60< pitchFreq && pitchFreq < 63.4) {
            ofInitPart(particles);
            ofDrawPartMult(11, 345, particles, images);
            
        }
        
        else if (63.4< pitchFreq && pitchFreq < 67.4) {
            ofInitPart(particles);
            ofDrawPartMult(0, 375, particles, images);
            
        }
        
        else if (67.4 < pitchFreq && pitchFreq < 71.4) {
            ofInitPart(particles);
            ofDrawPartMult(1, 405, particles, images);
            
        }
        
        else if (71.4 < pitchFreq && pitchFreq < 75.4){
            ofInitPart(particles);
            ofDrawPartMult(2, 435, particles, images);
            
        }
        
        else if(75.4 < pitchFreq && pitchFreq < 80) {
            ofInitPart(particles);
            ofDrawPartMult(3, 465, particles, images);
            
        }
        
        else if (80 < pitchFreq && pitchFreq < 84.8)  {
            ofInitPart(particles);
            ofDrawPartMult(4, 495, particles, images);
            
        }
        
        else if  (84.8 < pitchFreq && pitchFreq < 90) {
            ofInitPart(particles);
            ofDrawPartMult(5, 525, particles, images);
            
        }
        
        else if  (90 < pitchFreq && pitchFreq < 95) {
            ofInitPart(particles);
            ofDrawPartMult(6, 555, particles, images);
            
        }
        
        else if (95 < pitchFreq && pitchFreq < 101) {
            ofInitPart(particles);
            ofDrawPartMult(7, 585, particles, images);
            
        }
        
        else if(101 < pitchFreq && pitchFreq < 106.5) {
            ofInitPart(particles);
            ofDrawPartMult(8, 615, particles, images);
            
        }
        
        else if (106.5 < pitchFreq && pitchFreq < 113.5) {
            ofInitPart(particles);
            ofDrawPartMult(9, 645, particles, images);
            
        }
        
        else if (113.5 < pitchFreq && pitchFreq < 119.5) {
            ofInitPart(particles);
            ofDrawPartMult(10, 675, particles, images);
            
        }
        
        else if (119.5 < pitchFreq && pitchFreq < 127) {
            ofInitPart(particles);
            ofDrawPartMult(11, 695, particles, images);
            
        }
        
        else if (127< pitchFreq && pitchFreq < 134.5) {
            ofInitPart(particles);
            ofDrawPartMult(0, 725, particles, images);
            
        }
        
        else if (134.5 < pitchFreq && pitchFreq < 142.5) {
            ofInitPart(particles);
            ofDrawPartMult(1, 755, particles, images);
            
        }
        
        else if (142.5 < pitchFreq && pitchFreq < 151) {
            ofInitPart(particles);
            ofDrawPartMult(2, 785, particles, images);
            
        }
        
        else if (151 < pitchFreq && pitchFreq < 160) {
            ofInitPart(particles);
            ofDrawPartMult(3, 815, particles, images);
            
        }
        
        else if (160 < pitchFreq && pitchFreq < 170)  {
            ofInitPart(particles);
            ofDrawPartMult(4, 845, particles, images);
            
        }
        
        else if (170 < pitchFreq && pitchFreq < 179.2) {
            ofInitPart(particles);
            ofDrawPartMult(5, 875, particles, images);
            
        }
        
        else if(179.2 < pitchFreq && pitchFreq < 191) {
            ofInitPart(particles);
            ofDrawPartMult(6, 805, particles, images);
            
        }
        
        else if  (191 < pitchFreq && pitchFreq < 201) {
            ofInitPart(particles);
            ofDrawPartMult(7, 835, particles, images);
            
        }
        
        else if (201 < pitchFreq && pitchFreq < 214) {
            ofInitPart(particles);
            ofDrawPartMult(8, 865, particles, images);
            
        }
        
        else if (214 < pitchFreq && pitchFreq < 226) {
            ofInitPart(particles);
            ofDrawPartMult(9, 895, particles, images);
            
        }
        
        else if (226 < pitchFreq && pitchFreq < 240) {
            ofInitPart(particles);
            ofDrawPartMult(10, 925, particles, images);
            
        }
        
        else if  (240 < pitchFreq && pitchFreq < 254) {
            ofInitPart(particles);
            ofDrawPartMult(11, 955, particles, images);
            
        }
        
        if  (254< pitchFreq && pitchFreq < 269) {
            ofInitPart(particles);
            ofDrawPartMult(0, 985, particles, images);
            
        }
        
        else if (269 < pitchFreq && pitchFreq < 285) {
            ofInitPart(particles);
            ofDrawPartMult(1, 1015, particles, images);
            
        }
        
        else if  (285 < pitchFreq && pitchFreq < 303) {
            ofInitPart(particles);
            ofDrawPartMult(2, 1045, particles, images);
            
        }
        
        else if  (303 < pitchFreq && pitchFreq < 319){
            ofInitPart(particles);
            ofDrawPartMult(3, 1075, particles, images);
            
        }
        
        else if (319 < pitchFreq && pitchFreq < 341) {
            ofInitPart(particles);
            ofDrawPartMult(4, 1105, particles, images);
            
        }
        
        else if (341 < pitchFreq && pitchFreq < 360)  {
            ofInitPart(particles);
            ofDrawPartMult(5, 1135, particles, images);
            
        }
        
        else if (360 < pitchFreq && pitchFreq < 380) {
            ofInitPart(particles);
            ofDrawPartMult(6, 1165, particles, images);
            
        }
        
        else if (380 < pitchFreq && pitchFreq < 403) {
            ofInitPart(particles);
            ofDrawPartMult(7, 1195, particles, images);
            
        }
        
        else if (403 < pitchFreq && pitchFreq < 428) {
            ofInitPart(particles);
            ofDrawPartMult(8, 1225, particles, images);
            
        }
        
        else if  (428 < pitchFreq && pitchFreq < 452) {
            ofInitPart(particles);
            ofDrawPartMult(9, 1255, particles, images);
            
        }
        
        else if (452 < pitchFreq && pitchFreq < 480) {
            ofInitPart(particles);
            ofDrawPartMult(10, 1285, particles, images);
            
        }
        
        else if (480 < pitchFreq && pitchFreq < 508) {
            ofInitPart(particles);
            ofDrawPartMult(11, 1315, particles, images);
            
        }
        
        else if (508< pitchFreq && pitchFreq < 538) {
            ofInitPart(particles);
            ofDrawPartMult(0, 1345, particles, images);
            
        }
        
        else if (538 < pitchFreq && pitchFreq < 570) {
            ofInitPart(particles);
            ofDrawPartMult(1, 1375, particles, images);
            
        }
        
        else if (570 < pitchFreq && pitchFreq < 604) {
            ofInitPart(particles);
            ofDrawPartMult(2, 1405, particles, images);
            
        }
        
        else if  (604 < pitchFreq && pitchFreq < 640) {
            ofInitPart(particles);
            ofDrawPartMult(3, 1435, particles, images);
            
        }
        
        else if  (640 < pitchFreq && pitchFreq < 678.5) {
            ofInitPart(particles);
            ofDrawPartMult(4, 1465, particles, images);
            
        }
        
        else if  (678.5 < pitchFreq && pitchFreq < 718.5) {
            ofInitPart(particles);
            ofDrawPartMult(5, 1495, particles, images);
            
        }
        
        else if  (718.5 < pitchFreq && pitchFreq < 761)  {
            ofInitPart(particles);
            ofDrawPartMult(6, 1525, particles, images);
            
        }
        
        else if  (761 < pitchFreq && pitchFreq < 807)  {
            ofInitPart(particles);
            ofDrawPartMult(7, 1555, particles, images);
            
        }
        
        else if (807 < pitchFreq && pitchFreq < 854) {
            ofInitPart(particles);
            ofDrawPartMult(8, 1585, particles, images);
            
        }
        
        else if (854 < pitchFreq && pitchFreq < 916) {
            ofInitPart(particles);
            ofDrawPartMult(9, 1615, particles, images);
            
        }
        
        else if  (916 < pitchFreq && pitchFreq < 948.4) {
            ofInitPart(particles);
            ofDrawPartMult(10, 1645, particles, images);
            
        }
        
        else if  (948.4 < pitchFreq && pitchFreq < 1018) {
            ofInitPart(particles);
            ofDrawPartMult(11, 1675, particles, images);
            
        }
        
        else if (1018< pitchFreq && pitchFreq < 1076) {
            ofInitPart(particles);
            ofDrawPartMult(0, 1705, particles, images);
            
        }
        
        else if(1076 < pitchFreq && pitchFreq < 1139) {
            ofInitPart(particles);
            ofDrawPartMult(1, 1735, particles, images);
            
        }
        
        else if (1139 < pitchFreq && pitchFreq < 1210) {
            ofInitPart(particles);
            ofDrawPartMult(2, 1765, particles, images);
            
        }
        
        else if (1210 < pitchFreq && pitchFreq < 1279) {
            ofInitPart(particles);
            ofDrawPartMult(3, 1795, particles, images);
            
        }
        
        else if (1279 < pitchFreq && pitchFreq < 1357) {
            ofInitPart(particles);
            ofDrawPartMult(4, 1825, particles, images);
            
        }
        
        else if (1357 < pitchFreq && pitchFreq < 1438) {
            ofInitPart(particles);
            ofDrawPartMult(5, 1855, particles, images);
            
        }
        
        else if (1438 < pitchFreq && pitchFreq < 1521) {
            ofInitPart(particles);
            ofDrawPartMult(6, 1885, particles, images);
            
        }
        
        else if (1521 < pitchFreq && pitchFreq < 1615) {
            ofInitPart(particles);
            ofDrawPartMult(7, 1915, particles, images);
            
        }
        
        else if (1615 < pitchFreq && pitchFreq < 1706) {
            ofInitPart(particles);
            ofDrawPartMult(8, 1945, particles, images);
            
        }
        
        else if  (1706 < pitchFreq && pitchFreq < 1814) {
            ofInitPart(particles);
            ofDrawPartMult(9, 1975, particles, images);
            
        }
        
        else if (1814 < pitchFreq && pitchFreq < 1915) {
            ofInitPart(particles);
            ofDrawPartMult(10, 2005, particles, images);
            
        }
        
        else if  (1915 < pitchFreq && pitchFreq < 2036) {
            ofInitPart(particles);
            ofDrawPartMult(11, 2035, particles, images);
            
        }
    }
    
    
    
    
    //p.draw();
    //ofPushMatrix();
    //ofTranslate(0, 0);
    //ofSetColor(0);
    //ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer &inBuffer){
    //ANALYZE SOUNDBUFFER:
    audioAnalyzer.analyze(inBuffer);
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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

//--------------------------------------------------------------
//void ofApp::exit(){ //turns off sound stream and quits stuff
//    ofSoundStreamStop();
//    audioAnalyzer.exit();
//}

