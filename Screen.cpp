#include "Screen.h"



Screen::Screen(): m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_buffer(nullptr), color(0){

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
    memset(m_buffer, 0x00, SCREEN_WIDTH*SCREEN_HEIGHT*4); //COPY 255 TO THE MEMORY STARTING AT ADDRESS POINTED BY BUFFER AND ENDING AT BUFFER + LAST ARGUMENT

    for (int i = 0; i<SCREEN_WIDTH*SCREEN_HEIGHT; ++i ){
        m_buffer[i] = 0x000000FF;
    }

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
    
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;

    m_buffer[(y*SCREEN_WIDTH) + x] = color;

}

void Screen::update(){
    SDL_UpdateTexture(m_texture, nullptr, m_buffer, SCREEN_WIDTH*4);
    SDL_RenderClear(m_renderer);
    SDL_RenderTexture(m_renderer, m_texture, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
}

void Screen::clear(){
    memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*4);
}

void Screen::close(){
    delete [] m_buffer;
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

Screen::~Screen(){

}