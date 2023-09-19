#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;

out vec2 textureCoord;

uniform mat4 mvp;

void main()
{

   textureCoord = aTex;
   gl_Position = mvp * vec4(aPos,1.0);
}