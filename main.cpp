#include <iostream>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    
    Screen screen;

    if (screen.init() == false){
        cout << "Initialization failed." << endl;
    }
    
    Swarm swarm;
    

    while(true){

        int elapsed = SDL_GetTicks();
        unsigned char red = (1 + sin(elapsed*0.0001))*127.5;
        unsigned char green = (1 + sin(elapsed*0.0002))*127.5;
        unsigned char blue = (1 + sin(elapsed*0.0003))*127.5;

        screen.clear();
        swarm.update();
        const Particles* const pParticles = swarm.getParticles();

        for(int i = 0; i < Swarm::N_PARTICLES; ++i){
            Particles particle = pParticles[i];

            int x = (particle.m_x + 1)*(Screen::SCREEN_WIDTH/2);
            int y = (particle.m_y + 1)*(Screen::SCREEN_HEIGHT/2);

            screen.setPixel(x,y, red, green, blue);
        }

        // Update particles
        screen.update();
        // Check for events
        if (screen.processEvents() == false){
            break;
        }
        
    }

    screen.close();

    return 0;
}