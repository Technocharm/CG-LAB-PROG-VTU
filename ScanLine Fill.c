#include<GL/glut.h>
float x1=200, y1=200, x2=100, y2=300,x3=200,y3=400,x4=300,y4=300;
float m;
int le[500], re[500],i, flag=0;
void edgedetect(float x1, float y1, float x2,float y2)
{
	float x;
	if((y2-y1)!=0)
		m=(x2-x1)/(y2-y1);
	x=x1;
	for(i=y1;i<=y2;i++)
	{
		if(x<le[i])
			le[i]=(int)x;
		if(x>re[i])
			re[i]=(int)x;
		x=x+m;
	}
}

void scanfill()
{
	int x,y;
	for(i=0;i<500;i++)
	{
		le[i]=500;
		re[i]=0;
	}
	edgedetect(x1,y1,x2,y2);
	edgedetect(x1,y1,x4,y4);
	edgedetect(x2,y2,x3,y3);
	edgedetect(x4,y4,x3,y3);
	for(y=0;y<=500;y++)
	{
		for(x=le[y];x<re[y];x++)
		{
			glBegin(GL_POINTS);
				glVertex2d(x,y);
			glEnd();
			glFlush();
		}
	}
}
void myinit()
{
	gluOrtho2D(0,500,0,500);
}


void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	if(flag==1){
		glColor3f(0,1,0);
		scanfill();
	}

	if(flag==2){
		glColor3f(0,1,1);
		scanfill();
	}
	glEnd();
	scanfill();
	glFlush();
}

void menu (int id)
{
	if(id==1)
		flag=1;
	if(id==2)
		flag=2;
	if(id==3)
		exit(0);

	display();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("ScanLine Fill 1CR20CS109");

	glutCreateMenu(menu);
	glutAddMenuEntry("color1",1);
	glutAddMenuEntry("color2",2);
	glutAddMenuEntry("Exit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	myinit();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
