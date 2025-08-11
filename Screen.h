#ifndef SCREEN_H_
#define SCREEN_H_
#include <SDL3/SDL.h>

class Screen{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
    SDL_Event m_event;
    Uint32 color;

public:
    Screen();
    bool init();
    bool processEvents();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void update();
    void clear();
    void close();

    ~Screen();
};

#endif