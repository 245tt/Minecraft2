#version 330 core
out vec4 FragColor;

in vec2 textureCoord;

uniform sampler2D texture0;

void main()
{
	
   //FragColor = vec4(color, 1.0f);
   
   FragColor = texture(texture0, textureCoord);
}