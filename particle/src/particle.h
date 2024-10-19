#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "ofPolyline.h"
class Particle {
public:
    Particle(float radius, float angle, float distance);
    void update();
    void draw();

    float radius;
    float angle;
    float distance;
    ofVec2f pos;
    ofColor color;
    ofPolyline trail; //add trail for particle
};

#endif // PARTICLE_H