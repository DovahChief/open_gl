#ifndef SHADER_H
#define SHADER_H

#include "transform.h"
#include "camara.h"
#include <string>
#include <GL/glew.h>

class shader
{
    public:
        shader( const std::string& file_name);
        virtual ~shader();
        void Bind();
        void Update(const transform& tr, const camara& cam);
        void Update(const transform& tr);
    protected:

    private:
        static const unsigned int NUM_SHADERS = 2;

        shader(const shader& other){}
        void operator=(const shader& other) {}

        enum {
            TRANSFORM_U,
            NUM_UNIFORMS
        };

        GLuint m_programa;
        GLuint m_shaders[NUM_SHADERS];
        GLuint m_uniforms[NUM_UNIFORMS];
};

#endif // SHADER_H
