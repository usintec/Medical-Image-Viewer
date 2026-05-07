#version 330 core

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D u_image;

void main() {
    float intensity = texture(u_image, TexCoord).r;
    // increase contrast
    //intensity = pow(intensity, 0.5);
    FragColor = vec4(vec3(intensity), 1.0);
}