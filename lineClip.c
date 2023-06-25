#include <GL/glut.h>
#include <stdio.h>
float x0=120,y0=10,x1=40,y1=130;
float xmin=50,xmax=100,ymin=50,ymax=100;
int left=8,right=4,bottom=2,top=1;
float m;

void drawline(int x0,int y0, int x1,int y1){
	glColor3d(1,0,0);
	glBegin(GL_LINES);
		glVertex2d(x0,y0);
		glVertex2d(x1,y1);
	glEnd();
}

void drawwindow(int xmin,int ymin,int xmax,int ymax){
	glColor3d(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2d(xmin,ymin);
		glVertex2d(xmax,ymin);
		glVertex2d(xmax,ymax);
		glVertex2d(xmin,ymax);
	glEnd();
}

int outcode(float x, float y){
	int code=0;
	if(x<xmin)
		code = code | left;
	if(x>xmax)
		code = code | right;
	if(y<ymin)
		code = code | bottom;
	if(y>ymax)
		code = code | top;
	return code;
}

void lineClip(int x0,int y0, int x1,int y1){
	float x,y;
	int outcode0, outcode1, outcodeout;
	int accept=0,done=0;

	outcode0=outcode(x0,y0);
	outcode1=outcode(x1,y1);

	do{
		if((outcode0|outcode1)==0){
			done=1;
			accept=1;
		}
		else if((outcode0&outcode1)!=0){
			done=1;
		}
		else{
			if(outcode0!=0){
				outcodeout=outcode0;
			}
			else{
				outcodeout=outcode1;
			}
			if(outcodeout&top){
				y=ymax;
				x=x0+(ymax-y0)/m;
			}
			else if(outcodeout&bottom){
				y=ymin;
				x=x0+(ymin-y0)/m;
			}
			else if(outcodeout&right){
				x=xmax;
				y=y0+(xmax-x0)*m;
			}
			else if(outcodeout&left){
				x=xmin;
				y=y0+(xmin-x0)*m;
			}
			if(outcodeout==outcode0){
				x0=x;
				y0=y;
				outcode0 = outcode(x0,y0);
			}
			else{
				x1=x;
				y1=y;
				outcode1 = outcode(x1,y1);
			}
		}

	}while(done==0);

	if(accept){
		glPushMatrix();
		glTranslated(150,150,0);
		drawwindow(xmin,ymin,xmax,ymax);
		drawline(x0,y0,x1,y1);
		glPopMatrix();
	}
}

void myinit(){
	gluOrtho2D(0,500,0,500);
}

void display(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	drawwindow(xmin,ymin,xmax,ymax);
	drawline(x0,y0,x1,y1);
	lineClip(x0,y0,x1,y1);
	glFlush();
}

int main(int argc , char** argv){
	m=(y1-y0)/(x1-x0);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("Line Clipping Algorithm");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}