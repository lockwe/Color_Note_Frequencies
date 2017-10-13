#pragma once

#include "ofMain.h"

#include "Particle.hpp"

#include "ofxAudioAnalyzer.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void audioIn(ofSoundBuffer &inBuffer);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    

    
    void plot(vector<float>& buffer, float scale);
    
    ofImage images[13];
    
    vector<Particle> particles;
    
    ofxAudioAnalyzer audioAnalyzer;
    ofSoundStream soundStream;
    float rms_l, rms_r; //not used
    float smooth;
    float pitchFreq;
    

};

