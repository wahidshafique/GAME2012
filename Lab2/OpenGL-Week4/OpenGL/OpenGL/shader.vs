#version 330 //GLSL language version

layout (location = 0) in vec3 Position;

uniform float gScale;
uniform float gScaleX;
uniform float gScaleY;

uniform mat4 gWorld;

void main()
{
	/*gl_Position = gWorld * vec4(gScale * Position.x,
		gScale * Position.y,
		Position.z,
		1.0);*/
	gl_Position = gWorld * vec4(gScaleX * gScale * Position.x, gScaleY * gScale * Position.y, Position.z, 1.0);
}