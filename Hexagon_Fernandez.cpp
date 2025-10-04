#include<GL/glut.h>
using namespace std;
void display(){

glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glVertex3f(0.5, 0.0, 0.0);
glVertex3f(0.25, 0.5, 0.0);
glVertex3f(-0.25, 0.5, 0.0);
glVertex3f(-0.5, 0.0, 0.0);
glVertex3f(-0.25, -0.5, 0.0);
glVertex3f(0.25, -0.5, 0.0);
glEnd();
glFlush();
}


int main(int argc, char** argv){
glutInit(&argc, argv);
glutCreateWindow("simple");
glutDisplayFunc(display);
glutMainLoop();
}
