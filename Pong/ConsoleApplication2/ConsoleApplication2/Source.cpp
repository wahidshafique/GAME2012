#define GLUE_STATIC
#pragma comment(lib, "glew32s.lib")
#include <GL\glew.h>
#include  <GL\freeglut.h>
#include "graphicsmath.h"

static void RenderSceneCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glRectf(-0.001f,1.75f, 0.5f, -0.75f);
	glRectf(-0.9f, 0.75f, 0.05f, -1.75f);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

static void InitializeGlutCallback()
{
	glutDisplayFunc(RenderSceneCallback);
}

static void CreateVertexBuffers()
{
	//Vector3f vertices[3];
	//vertices[0] = Vector3f(-1.f, -1.f, 0.f);
	//vertices[1] = Vector3f(1.f, -1.f, 0.f);
	//vertices[2] = Vector3f(0.f, 1.f, 0.f);



	//glGenBuffers(1, &VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Pong");

	InitializeGlutCallback();

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(res));
		return 1;
	}

	glClearColor(0.f, 0.f, 0.f, 0.f);

	//CreateVertexBuffers();

	glutMainLoop();
	return 0;
}