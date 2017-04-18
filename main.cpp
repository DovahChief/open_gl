/*
    "motor" opengl
*/

#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "camara.h"
#include "transform.h"
#include <GL/glew.h>

#define ancho 800
#define alto 600

using namespace std;

int main(){
    float cont = 0.0f;
    display disp(ancho, alto, "OPEN_GL");

    vertex vertices[] = { vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0,0)),
                          vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5,1.0)),
                          vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0,0.0))};

    mesh m_mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    shader shd("./shader/basicShader");
    texture tx("./texture/stones.bmp");
    camara cam( glm::vec3(0,0,-2), 80.0f, float(ancho)/float(alto), 0.5f, 100.0f );
    transform tr;

    while(!disp.is_closed()){
        disp._clear(0.0f,0.15f, 0.3f, 1.0f);

        tr.set_pos(glm::vec3(tr.get_pos().x, tr.get_pos().y, sinf(cont) * 3));
        tr.set_rot(glm::vec3(0,0,cont));
        tr.set_scale(glm::vec3(cosf(cont),cosf(cont),cosf(cont)));

        shd.Bind(); //empezamos a dibujar con el shader
        shd.Update(tr, cam);
        tx.Bind(0);
        m_mesh.draw(); //por default es triangles
        disp.update();
        cont += 0.05f;
    }
    return 0;
}
