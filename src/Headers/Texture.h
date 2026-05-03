#pragma once

class Texture {
public:
    unsigned int ID;
    int width, height, channels;

    Texture(const char* path);
    void bind();
};