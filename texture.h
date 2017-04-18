#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>

class texture{
    public:
        texture(const std::string& file_name);
        void Bind(unsigned int unit);
        virtual ~texture();

    protected:

    private:
        texture(const texture& other){}
        void operator=(const texture& other){}

        GLuint m_textura;

};

#endif // TEXTURE_H
