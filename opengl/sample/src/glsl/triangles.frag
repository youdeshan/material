#version 430 core
out vec4 FragColor;

//uniform vec4 ourColor;
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture0;
uniform sampler2D texture1;

void main() {
    //FragColor = texture(texture0, TexCoord);
    //FragColor = texture(texture0, TexCoord) * vec4(ourColor, 1.0f);
    FragColor = mix(texture(texture0, TexCoord), texture(texture1, TexCoord), 0.2);
}
