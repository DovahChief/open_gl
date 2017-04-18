#include "texture.h"
#include "stb_image.h"
#include <cassert>
#include <iostream>

texture::texture(const std::string& file_name){
    int ancho, alto, num_comp;
    unsigned char * img_data = stbi_load((file_name).c_str(), &ancho, &alto, &num_comp, 4);

    if(img_data == NULL) std::cerr<<"Error al cargar textura : "<< file_name <<std::endl;

    glGenTextures(1, &m_textura);
    glBindTexture(GL_TEXTURE_2D, m_textura);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ancho, alto, 0, GL_RGBA, GL_UNSIGNED_BYTE, img_data);

    stbi_image_free(img_data);

}

texture::~texture(){
    glDeleteTextures(1, &m_textura);
}

void texture::Bind(unsigned int unit){
    assert(unit >= 0 && unit <= 31);
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_textura);
    //glBindTexture(GL_TEXTURE_2D, m_textura);
}
