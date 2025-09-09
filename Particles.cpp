#include "Particles.h"
#include <math.h>
#include <stdlib.h>
using namespace std;

Particles::Particles() : m_x(0), m_y(0) {
    init();
}

void Particles::init(){
    m_x = 0;
    m_y = 0;
    m_direction = (2*M_PI*rand())/RAND_MAX;
    m_speed = (0.03*rand())/RAND_MAX;

    m_speed *= m_speed;
}

void Particles::update(int timeInterval){

    m_direction += timeInterval*0.0001;

    double xSpeed = m_speed*cos(m_direction);
    double ySpeed = m_speed*sin(m_direction);

    m_x += xSpeed * timeInterval;
    m_y += ySpeed * timeInterval;

    if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1){
        init();
    }

    if(rand() < RAND_MAX/100){
        init();
    }
}

