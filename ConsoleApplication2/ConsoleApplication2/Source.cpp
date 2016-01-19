#define GLUE_STATIC
#pragma comment(lib, "glew32s.lib")
#include <GL\glew.h>
#include  <GL\freeglut.h>
#include "graphicsmath.h"

static void RenderSceneCallback(){
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);


	glutSwapBuffers();
}
static void InitializeGlutCallback(){
	glutDisplayFunc(RenderSceneCallback);
}

static void CreateVertexBuffers(){
	Vector3f vertices[3];
	vertices[0] = Vector3f(1.f, -1.f, 0.f);
	vertices[1] = Vector3f(1.f, -1.f, 0.f);
	vertices[2] = Vector3f(0.f, 1.f, 0.f);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("week 2");
	InitializeGlutCallback();

	GLenum res = glewInit();
	if (res != GLEW_OK){
		fprintf(stderr, "Error : %s \n", glewGetErrorString(res));
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	CreateVertexBuffers();
	glutMainLoop();
	return 0;
}




//#include <stdlib.h> 
//#include <stdio.h> 
//#include <math.h> 
//#include <GL/freeglut.h>
//#define KEY_ESC 27 /* GLUT doesn't supply this */
//int myrandom(int m) {
//
//	return rand() % m;
//
//}
//
//GLvoid display(GLvoid) {
//	/* Do all your OpenGL rendering here */
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//
//	switch (key)
//	{
//	case 27:             // ESCAPE key
//		exit(0);
//		break;
//	case 32:
//
//		glClearColor((double)myrandom(255) / 255, (double)myrandom(255) / 255, (double)myrandom(255) / 255, (double)myrandom(255) / 255);
//		glutPostRedisplay();
//		break;
//	}
//}
//
//void init(){
//	glClearColor(1.0, 1.0, 0.0, 1.0);
//}
//
//int main(int argc, char* argv[]) {
//	GLint width;
//	GLint height;
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	width = glutGet(GLUT_SCREEN_WIDTH);
//	height = glutGet(GLUT_SCREEN_HEIGHT);
//	glutInitWindowPosition(width / 4, height / 4);
//	glutInitWindowSize(width / 2, height / 2);
//	glutCreateWindow(argv[0]);
//	glutDisplayFunc(display);
//	glutKeyboardFunc(keyboard);
//	init();
//	glutMainLoop();
//	return 0;
//}
