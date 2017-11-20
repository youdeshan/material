#version 430 core
out vec4 FragColor;

//uniform vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D texture0;
uniform sampler2D texture1;

uniform float mixValue;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main() {
    //FragColor = texture(texture1, TexCoord);
    //FragColor = texture(texture0, TexCoord) * vec4(ourColor, 1.0f);
    //FragColor = mix(texture(texture0, TexCoord), texture(texture1, TexCoord), 0.2);
    //FragColor = mix(texture(texture0, TexCoord), texture(texture1, vec2(1.0 - TexCoord.x, TexCoord.y)), 0.2);
    //FragColor = mix(texture(texture0, TexCoord), texture(texture1, vec2(1.0 - TexCoord.x, TexCoord.y)), mixValue);
    FragColor = vec4(lightColor * objectColor, 1); 
}
