#include "Screen.h"



Screen::Screen(): m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_buffer(nullptr), m_blurBuffer(nullptr){

}

bool Screen::init(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return false;
    }

    m_window = SDL_CreateWindow("Particle Explosion",SCREEN_WIDTH, SCREEN_HEIGHT, 0 ); //

    if(m_window == nullptr){
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, NULL);  //
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);    //

    if(m_renderer ==  nullptr){
        SDL_DestroyWindow(m_window);
        SDL_Quit(); 
        return false;
    }
    if(m_texture ==  nullptr){
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];    //
    m_blurBuffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

    memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*4); //COPY 255 TO THE MEMORY STARTING AT ADDRESS POINTED BY BUFFER AND ENDING AT BUFFER + LAST ARGUMENT
    memset(m_blurBuffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*4);

    return true;
}

bool Screen::processEvents(){
    while (SDL_PollEvent(&m_event)){ //Returns true if there's an event in the queue, stores info about the event in the variable passed as argument
            if(m_event.type == SDL_EVENT_QUIT){ // SDL_EVENT_QUIT is true if the close widnow button is clicked
               return false; // Set quit to true to terminate the window
            }
        }
    return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){

    if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT){
        return;
    }
    Uint32 color = 0;
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;

    m_buffer[(y*SCREEN_WIDTH) + x] = color;

}

void Screen::boxBlur(){
    Uint32* temp = m_buffer;
    m_buffer = m_blurBuffer;
    m_blurBuffer = temp;

    for(int y=0; y < SCREEN_HEIGHT ; ++y){
        for(int x=0; x < SCREEN_WIDTH; ++x){

            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;
            /* 
            
            0   0   0
            0   1   0
            0   0   0  
            
            */
            for(int row = -1; row <= 1; ++row){
                for(int col = -1; col <= 1; ++col){
                    int currentX = x + col;
                    int currentY = y + row;

                    if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT){
                        Uint32 color = m_blurBuffer[(currentY*SCREEN_WIDTH) + currentX];

                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;

                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                    }
                }
           }
           Uint8 red = redTotal/9;
           Uint8 green = greenTotal/9;
           Uint8 blue = blueTotal/9;

           setPixel(x, y, red, green, blue);
        }
    }
} 

void Screen::update(){
    SDL_UpdateTexture(m_texture, nullptr, m_buffer, SCREEN_WIDTH*4);
    SDL_RenderClear(m_renderer);
    SDL_RenderTexture(m_renderer, m_texture, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
}


void Screen::close(){
    delete [] m_buffer;
    delete [] m_blurBuffer;
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}


Screen::~Screen(){

}