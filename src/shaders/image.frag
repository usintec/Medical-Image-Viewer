#version 330 core

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D u_image;

void main() {
    float intensity = texture(u_image, TexCoord).r;
    FragColor = vec4(vec3(intensity), 1.0);
}