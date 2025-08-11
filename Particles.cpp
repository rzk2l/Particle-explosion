#include "Particles.h"
#include <stdlib.h>
using namespace std;

Particles::Particles() : m_x(0), m_y(0) {
    m_x = ((2.0*rand())/RAND_MAX) - 1;
    m_y = ((2.0*rand())/RAND_MAX) - 1;

    m_xSpeed = 0.0005*((2.0*rand())/RAND_MAX - 1);
    m_ySpeed = 0.0005*((2.0*rand())/RAND_MAX - 1);
}

void Particles::update(){
    m_x += m_xSpeed;
    m_y += m_ySpeed;

    if (m_x < -1.0 || m_x >= 1.0){
        m_xSpeed = -m_xSpeed;
    }
    if (m_y <= -1.0 || m_y >= 1.0){
        m_ySpeed = -m_ySpeed;
    }
}

