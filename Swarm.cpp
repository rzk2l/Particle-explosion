#include "Swarm.h"

Swarm::Swarm(){
    m_pParticle = new Particles[N_PARTICLES];
}

Swarm::~Swarm(){
    delete [] m_pParticle;
}

void Swarm::update(){
    for(int i = 0; i < N_PARTICLES; ++i){
        m_pParticle[i].update();
    }
}
