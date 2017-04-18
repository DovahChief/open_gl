#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <SDL2/SDL.h>


class display{
    public:
        display(int ancho, int alto, const std::string& titulo);
        virtual ~display();
        void update();
        void _clear(float r, float g, float b, float a);
        bool is_closed();
    protected:

    private:
        bool cerrado;
        display(const display& other){};
        void operator=(const display& other){ };
        SDL_Window * m_ventana;
        SDL_GLContext m_glcontext;
};

#endif // DISPLAY_H
