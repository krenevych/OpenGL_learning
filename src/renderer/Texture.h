//
// Created by Andrii Krenevych on 21.04.2025.
//

#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

namespace Renderer {

class Texture {
public:
    explicit Texture(const std::string& fileName);
    ~Texture();

    void bind(unsigned int shaderProgram) const;
    void unbind();

private:
    unsigned int mTextureId;

    static unsigned int load(const std::string& fileName);

};

} // Renderer

#endif //TEXTURE_H
