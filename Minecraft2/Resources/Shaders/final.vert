#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in float aBri;

out vec2 textureCoord;
out float brightness;

uniform mat4 mvp;

void main()
{
   brightness = aBri;
   textureCoord = aTex;
   gl_Position = mvp * vec4(aPos,1.0);
}