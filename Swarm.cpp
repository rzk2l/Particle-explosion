#include "Swarm.h"

Swarm::Swarm(): lastTime(0) {
    m_pParticle = new Particles[N_PARTICLES];
}

Swarm::~Swarm(){
    delete [] m_pParticle;
}

void Swarm::update(int elapsedTime){

    int interval = elapsedTime - lastTime;

    for(int i = 0; i < N_PARTICLES; ++i){
        m_pParticle[i].update(interval);
    }

    lastTime = elapsedTime;
}
