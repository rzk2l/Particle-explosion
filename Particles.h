#ifndef PARTICLES_H_
#define PARTICLES_H_

struct Particles{
    double m_x;
    double m_y;
    double m_xSpeed;
    double m_ySpeed;
public:
    Particles();
    void update();
    //~Particles();
};

#endif 