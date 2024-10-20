#include "seamonster.h"
void Seamonster::setup()
{

}

void Seamonster::update() {
    position += velocity;

    // ตรวจสอบการชนขอบหน้าจอ
    if (position.x < radius || position.x > ofGetWidth() - radius) {
        velocity.x *= -1;
    }
    if (position.y < radius || position.y > ofGetHeight() - radius) {
        velocity.y *= -1;
    }

    // เก็บตำแหน่งล่าสุดสำหรับ trail
    trail.push_back(position);
    if (trail.size() > 10) { // กำหนดความยาวของ trail (50 จุด)
        trail.erase(trail.begin());
    }

}

void Seamonster::draw() {
    ofSetColor(255, opacity); // กำหนดสีขาวและ opacity
    // วาด trail
    for (int i = 1; i < trail.size(); i++) {
        float trailOpacity = ofMap(i, 1, trail.size(), opacity, 0); // ปรับ opacity ให้จางลงเมื่อไกลออกไป
        ofSetColor(255, trailOpacity);

        // ปรับขนาด trail ให้ใหญ่ไปเล็ก
        float trailRadius = ofMap(i, 1, trail.size(), radius * 0.1, radius * 0.5); // ปรับขนาดให้เล็กลงเมื่อไกลออกไป

        // คำนวณตำแหน่ง trail ให้มีมุมโค้ง
        glm::vec2 trailPosition = trail[i] + glm::vec2(ofRandom(-5, 2), ofRandom(-2, 5)); // เพิ่มความเบี่ยงเบนเล็กน้อย

        ofDrawCircle(trailPosition, trailRadius);
    }
    ofDrawCircle(position, radius);

}

void Seamonster::checkCollision(Seamonster& other) {
    float distance = glm::distance(position, other.position);
    if (distance < radius + other.radius) {
        // คำนวณเวกเตอร์ปกติและสัมผัส
        glm::vec2 normal = glm::normalize(position - other.position);
        glm::vec2 tangent = glm::vec2(-normal.y, normal.x);

        // คำนวณองค์ประกอบความเร็วใหม่
        float v1n = glm::dot(velocity, normal);
        float v1t = glm::dot(velocity, tangent);
        float v2n = glm::dot(other.velocity, normal);
        float v2t = glm::dot(other.velocity, tangent);

        // แลกเปลี่ยนองค์ประกอบความเร็วปกติ
        float newV1n = v2n;
        float newV2n = v1n;

        // คำนวณเวกเตอร์ความเร็วใหม่
        glm::vec2 newV1 = newV1n * normal + v1t * tangent;
        glm::vec2 newV2 = newV2n * normal + v2t * tangent;

        // อัพเดตความเร็ว
        velocity = newV1;
        other.velocity = newV2;

        // ปรับตำแหน่งเพื่อป้องกันการซ้อนทับ
        float overlap = radius + other.radius - distance;
        position += normal * overlap / 2.0f;
        other.position -= normal * overlap / 2.0f;
    }
}