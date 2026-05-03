#include "Texture.h"
#include <glad/glad.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const char* path) {
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    // Wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Flip image (important for OpenGL coords)
    stbi_set_flip_vertically_on_load(true);

    unsigned char* data = stbi_load(path, &width, &height, &channels, 0);

    if (!data) {
        std::cout << "ERROR: Failed to load texture: " << path << std::endl;
        return;
    }

    GLenum format;

    if (channels == 1)
        format = GL_RED;     // grayscale (medical images)
    else if (channels == 3)
        format = GL_RGB;
    else if (channels == 4)
        format = GL_RGBA;
    else {
        std::cout << "Unknown texture format!" << std::endl;
        return;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    // ?? VERY IMPORTANT for grayscale visualization
    if (format == GL_RED) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_R, GL_RED);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_G, GL_RED);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_B, GL_RED);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_A, GL_ONE);
    }

    stbi_image_free(data);
}

void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, ID);
}