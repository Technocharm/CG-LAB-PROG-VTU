#include <stdio.h>
#include <GL/glut.h>

float light_pos[] = {27,80,2,3};
float ambient[] = {1,1,1,1};

void align(){
    glRotatef(50,0,1,0);
    glRotatef(10,-1,0,0);
    glRotatef(11.7,0,0,-1);
}

void obj(float tx,float ty,float tz,float sx, float sy, float sz){
    align();
    glTranslatef(tx,ty,tz);
    glScalef(sx,sy,sz);
    glutSolidCube(1);
    glLoadIdentity();
}

void display(){
    glViewport(0,0,700,700);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    obj(0,0,0.5,1,1,0.04);
    obj(0,-0.5,0,1,0.04,1);
    obj(-0.5,0,0,0.04,1,1);

    obj(0,-0.3,0,0.02,0.2,0.02);
    obj(0,-0.3,-0.4,0.02,0.2,0.02);
    obj(0.4,-0.3,0,0.02,0.2,0.02);
    obj(0.4,-0.3,-0.4,0.02,0.2,0.02);

    obj(0.2,-0.18,-0.2,0.6,0.02,0.6);

    glPushMatrix();
    align();
    glTranslatef(0.3,-0.1,-0.3);
    glutSolidTeapot(0.10);
    glPopMatrix();

    glFlush();
    glLoadIdentity();
}

int main(int argc, char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_SINGLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(700,700);
    glutCreateWindow("Teapot");
    glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
    glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
