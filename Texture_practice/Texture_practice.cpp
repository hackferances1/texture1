//youtube learning unit3 
#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define convert(x) x/256 

void display();
void reshape(int,int);

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(512,512);
	glutCreateWindow("title");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	glutMainLoop();
	return 0;
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	int x=512,y=512,n=3;
	unsigned char* image_data = stbi_load("container.jpg", &x, &y, &n, 0);
	
	glBegin(GL_POINTS);
	
	for (int i=0;i<=512;i++){
		for (int j=0;j<=512;j++){
			float r=image_data[(i * x + j) * n];
			float g=image_data[(i * x + j) * n + 1];
			float b=image_data[(i * x + j) * n + 2];
			glColor3f(convert(r),convert(g),convert(b));
			glVertex2f(j-256,i-256);
		}
	}
	
	glEnd();
	
	stbi_image_free(image_data);
	
	glFlush();
}

void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-256,256,-256,256);
	glMatrixMode(GL_MODELVIEW);
	
}
