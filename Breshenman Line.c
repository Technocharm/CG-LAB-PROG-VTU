#include <GL/glut.h>
#include <stdio.h>

float x0,y0,x1,y1;
void display(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    float dx,dy,x,y,df,incrx,incry;
    int i;

    dy= abs(y1-y0);
    dx= abs(x1-x0);

    x=x0;
    y=y0;

    incrx = 1;
    if(x1<x0)
        incrx = -1;

    incry = 1;
    if(y1<y0)
        incry = -1;

    if(dx>dy){
        df = (2*dy)-dx;
        glColor3f(1,0,0);
        glBegin(GL_POINTS);
        for(i=0;i<dx;i++){
            if(df>0){
                x=x+incrx;
                y=y+incry;
                df = df + (2*dy)-(2*dx);
            }
            else{
                x=x+incrx;
                df=df+(2*dy);
            }
            printf("%f %f\n",x,y);
            glVertex2f(x,y);
        }
        glEnd();
    }
    else{
        df = (2*dx)-dy;
        glColor3f(1,0,0);
        glBegin(GL_POINTS);
        for(i=0;i<dy;i++){
            if(df>0){
                x=x+incrx;
                y=y+incry;
                df = df + (2*dx)-(2*dy);
            }
            else{
                y=y+incry;
                df=df+(2*dx);
            }
            printf("%f %f\n",x,y);
            glVertex2f(x,y);
        }
        glEnd();
    }
    glFlush();
}

void myinit(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char **argv){
    printf("Enter the line vertex values\n");
    scanf("%f %f %f %f", &x0,&y0,&x1,&y1);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham's line drawing algorithm_1CR20CS109");

    myinit();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}


