#include <GL/glut.h>
#include <stdio.h>
float v[8][3] = {{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};
int view[3] = {0,0,5};

void draw(int a,int b,int c, int d){
	glBegin(GL_QUADS);
		glVertex3f(v[a][0],v[a][1],v[a][2]);
		glVertex3f(v[b][0],v[b][1],v[b][2]);
		glVertex3f(v[c][0],v[c][1],v[c][2]);
		glVertex3f(v[d][0],v[d][1],v[d][2]);
	glEnd();
}

void cube(){
	glColor3f(1,0,0);
	draw(0,1,2,3);
	glColor3f(0,1,0);
	draw(4,5,6,7);
	glColor3f(0,0,1);
	draw(0,1,5,4);
	glColor3f(1,1,0);
	draw(3,2,6,7);
	glColor3f(1,0,1);
	draw(0,4,7,3);
	glColor3f(0,1,1);
	draw(1,5,6,2);
}

void keyboard(unsigned char ch, int x,int y){
	if(ch=='x')
		view[0]-=1;
	if(ch=='X')
		view[0]+=1;
	if(ch=='y')
		view[1]-=1;
	if(ch=='Y')
		view[1]+=1;
	if(ch=='z')
		view[2]-=1;
	if(ch=='Z')
		view[2]+=1;
	glutPostRedisplay();
}

void display(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(view[0],view[1],view[2],0,0,0,0,1,0);
	cube();
	glutSwapBuffers();
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glFrustum(-2,2,-2,2,2,20);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutCreateWindow("Camera cube");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	myinit();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}