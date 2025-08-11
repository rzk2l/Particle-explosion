#ifndef SWARM_H_
#define SWARM_H_

#include "Particles.h"

class Swarm{
public:
    const static int N_PARTICLES = 2500;
private:
    Particles* m_pParticle;

public:
    Swarm();
    ~Swarm();
    void update();
    const Particles* const getParticles(){  return m_pParticle; }
};

#endif 