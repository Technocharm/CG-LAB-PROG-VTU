#include <GL/glut.h>
#include <stdio.h>
int flag = 0;
int theta = 0;

int fact(int n)
{
    int i, num = 1;
    for (i = n; i > 1; i--)
    {
        num *= i;
    }
    return num;
}

int combination(float i, float n)
{
    float c;
    c = fact(n) / (fact(i) * fact(n - i));
    return c;
}

void curve(float cp[4][2])
{
    int i;
    float t, x, y, z;
    int n = 3;
    glBegin(GL_LINE_STRIP);
    for (t = 0; t <= 1; t += 0.001)
    {
        x = 0, y = 0;
        for (i = 0; i < 4; i++)
        {
            x += cp[i][0] * combination(i, n) * pow(t, i) * pow(1 - t, n - i);
            y += cp[i][1] * combination(i, n) * pow(t, i) * pow(1 - t, n - i);
        }
        glVertex2f(x, y);
    }
    glEnd();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    int i;
    float cp[4][2] = {{100, 400}, {150, 450}, {200, 350}, {250, 400}};

    if (flag == 1)
    {
        cp[1][0] += 10 * sin((theta * 3.14) / 180);
        cp[1][1] += 10 * sin((theta * 3.14) / 180);
        cp[2][0] += 10 * sin((theta * 3.14) / 180);
        cp[2][1] += 10 * sin((theta * 3.14) / 180);
        cp[3][0] += 10 * sin((theta * 3.14) / 180);
        cp[3][1] += 10 * sin((theta * 3.14) / 180);
        theta += 5;
    }

    glPushMatrix();
    for (i = 0; i < 20; i++)
    {
        glColor3f(1, 0.5, 0);
        glTranslatef(0, -1, 0);
        curve(cp);
    }
    for (i = 0; i < 20; i++)
    {
        glColor3f(1, 1, 1);
        glTranslatef(0, -1, 0);
        curve(cp);
    }
    for (i = 0; i < 20; i++)
    {
        glColor3f(0, 1, 0);
        glTranslatef(0, -1, 0);
        curve(cp);
    }
    glPopMatrix();
    glLineWidth(5.0);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(100, 400);
    glVertex2f(100, 200);
    glEnd();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}

void menu(int id)
{
    if (id == 1)
        flag = 1;
    if (id == 2)
        flag = 0;
    if (id == 3)
        exit(0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("1CR20CS109 Flag");
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    myinit();
    glutDisplayFunc(display);
    glutCreateMenu(menu);
    glutAddMenuEntry("Start", 1);
    glutAddMenuEntry("Stop", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
