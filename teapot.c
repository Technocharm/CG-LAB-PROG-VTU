#include <GL/glut.h>
#include <stdio.h>
float light_pos[]={2,2,2,1};
float ambient[]={1,1,1,1};

void align(){
	glRotatef(50,0,1,0);
	glRotatef(10,-1,0,0);
	glRotatef(10,0,0,-1);
}

void obj(float tx,float ty, float tz, float sx, float sy, float sz){
	align();
	glTranslatef(tx,ty,tz);
	glScalef(sx,sy,sz);
	glutSolidCube(1);
	glLoadIdentity();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//wall
	obj(0,0,0.5,1,1,0.04);
	obj(-0.5,0,0,0.04,1,1);
	obj(0,-0.5,0,1,0.04,1);

	//leg
	obj(-0.2,-0.5,0.2,0.02,0.2,0.02);
    obj(0.5,-0.3,0,0.02,0.2,0.02);
    obj(0,-0.3,-0.5,0.02,0.2,0.02);
    obj(0.5,-0.3,-0.5,0.02,0.2,0.02);

    //top
	obj(0,-0.228,0,0.9,0.04,0.9);

	glPushMatrix();
    glTranslatef(-0.02,-0.1,0.02);
    glutSolidTeapot(0.10);
    glPopMatrix();
	glFlush();
}

int main(int argc,char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
	glutCreateWindow("1CR20CS109 Teapot");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
	glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
