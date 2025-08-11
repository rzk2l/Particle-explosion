#include "Particles.h"
#include <math.h>
#include <stdlib.h>
using namespace std;

Particles::Particles() : m_x(0), m_y(0) {
    m_direction = (2*M_PI*rand())/RAND_MAX;
    m_speed = (0.0003*rand())/RAND_MAX;
}

void Particles::update(){
    double xSpeed = m_speed*cos(m_direction);
    double ySpeed = m_speed*sin(m_direction);

    m_x += xSpeed;
    m_y += ySpeed;
}

