//
//  Particle.cpp
//  ParticleSoundSystem
//
//  Created by Emily Lockwood on 9/25/17.
//


#include "Particle.hpp"

Particle::Particle(){
    Particle(ofColor::blueViolet,
             ofVec3f(20,20,20),
             ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0),
             ofVec3f(0, 0, 0),
             ofVec3f(0, 0, 0));
}

Particle::Particle(ofColor c,
                   ofVec3f s,
                   ofVec3f p,
                   ofVec3f v,
                   ofVec3f a){
    color = c;
    scale = s;
    position = p;
    velocity = v;
    acceleration = a;
    
}

void Particle::update(){
    velocity += acceleration;
    velocity.limit(30);
    position += velocity;
}

void Particle::draw(){
    ofTranslate(position);
    //would like to rotate!!
    ofSetColor(color);
    ofScale(.3, .3);
}







