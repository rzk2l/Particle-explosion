#ifndef PARTICLES_H_
#define PARTICLES_H_

struct Particles{
    double m_x;
    double m_y;
    double m_speed;
    double m_direction;
private:
    void init();
public:
    Particles();
    void update(int timeInterval);
    //~Particles();
};

#endif 