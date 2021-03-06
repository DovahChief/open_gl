#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

/*
         GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY,
         GL_LINES_ADJACENCY, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES,
         GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
*/

enum modo_dibujo {punto         = GL_POINTS,
                  line_strip    = GL_LINE_STRIP,
                  line_loop     = GL_LINE_LOOP,
                  lines         = GL_LINES,
                  line_strip_a  = GL_LINE_STRIP_ADJACENCY,
                  lines_a       = GL_LINES_ADJACENCY,
                  triangle_strip= GL_TRIANGLE_STRIP,
                  triangle_fan  = GL_TRIANGLE_FAN,
                  triangles     = GL_TRIANGLES,
                  triangle_str_a= GL_TRIANGLE_STRIP_ADJACENCY,
                  triangle_a    = GL_TRIANGLES_ADJACENCY,
                  patches       = GL_PATCHES,
                  polygon       = GL_POLYGON,
                  quad          = GL_QUADS};

//data vertex class
class vertex {
public:
    vertex(const glm::vec3& _pos, const glm::vec2 _textCoord){
        this->pos = _pos;
        this->textCoord = _textCoord;
    }
//private:
    glm::vec3 pos;
    glm::vec2 textCoord;
protected:

};

class mesh{

    public:
        mesh(vertex* vertices, unsigned int num_vertices);
        virtual ~mesh();
        void draw(modo_dibujo m_dib = triangles);

    protected:

    private:
        mesh(const mesh& other);
        void operator=(const mesh& other);

        enum {POSITION_VB, NUM_BUFFERS, TEXT_COORD_VB };

        GLuint m_vertexArrayObj;
        GLuint m_vertexArrayBuff[NUM_BUFFERS];
        unsigned int m_draw_count;

};

#endif // MESH_H
