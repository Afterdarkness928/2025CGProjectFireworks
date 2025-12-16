#include "particle.h"
#include "utils.h"   // 里面定义了 Phys::dragFactor / Phys::gravity
#include<iostream>

Particle::Particle(float x, float y, float z, float vx, float vy, float vz, float life, float r, float g, float b, float a,float size)
    : position(glm::vec3(x, y, z)),
  velocity(glm::vec3(vx, vy, vz)),
  life(life),
  maxLife(life),
  color(glm::vec4(r, g, b, a)),
	size(size)
{
	this->position = glm::vec3(x, y, z);

}

Particle::Particle(glm::vec3 pos, glm::vec3 vel, float life, glm::vec4 color,float size )
    :position(pos),velocity(vel),life(life),maxLife(life),color(color), size(size){

}

Particle::Particle(glm::vec3 pos, glm::vec3 vel, float life, glm::vec4 color, bool isTrail, bool isPhysicsEnabled,float size)
	: position(pos), velocity(vel), life(life), maxLife(life), color(color),size(size), isTrail(isTrail), isPhysicsEnabled(isPhysicsEnabled)
{
}





void Particle::update(float dt, float sway)
{
    life -= dt ;
    if (isPhysicsEnabled) {
       velocity.y -= gravity * dt;
       velocity -= air_drag * glm::length(velocity) * velocity * dt;
    } 
    position += velocity * dt;
}

bool Particle::isAlive() const {

    return life > 0.0f;

}
