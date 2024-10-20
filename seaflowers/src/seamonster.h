#pragma once
#include "ofMain.h"
class Seamonster {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    float radius;
    float opacity;
    std::vector<glm::vec2> trail;
    Seamonster(glm::vec2 pos, glm::vec2 vel, float rad) {
        position = pos;
        velocity = vel;
        radius = rad;
        opacity = (radius < 10) ? 50 : ofRandom(100, 255); // กำหนด opacity ตามขนาด
    }

    void setup();
    void update();
    void draw();
    void checkCollision(Seamonster& other);

    
};

