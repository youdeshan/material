#version 430 core
layout (location = 0) in vec3 aPos;

out vec4 vetexColor;

void main() {
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	vetexColor = vec4(0.5, 0.0, 0.0, 1.0);
}
