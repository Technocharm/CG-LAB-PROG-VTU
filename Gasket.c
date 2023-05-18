#include <GL/glut.h>
#include <stdio.h>

float v[4][3] = {{0,0,1},{0,1,0},{-1,-1,0},{1,-1,0}};
int m,i;

void triangle(float a[3],float b[3], float c[3]){

	glBegin(GL_TRIANGLES);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
	glEnd();

}


void div_triangle(float a[3],float b[3], float c[3], int m){

	float v1[3],v2[3],v3[3];
	if(m>0){
		for(i=0;i<3;i++){
			v1[i]=(a[i]+b[i])/2;
			v2[i]=(b[i]+c[i])/2;
			v3[i]=(a[i]+c[i])/2;
		}
		div_triangle(a,v1,v3,m-1);
		div_triangle(b,v1,v2,m-1);
		div_triangle(c,v2,v3,m-1);
	}
	else{
		triangle(a,b,c);
	}

}


void tetrahedron(int m){
	glColor3f(1,0,0);
	div_triangle(v[0],v[1],v[2],m);

	glColor3f(0,1,0);
	div_triangle(v[0],v[1],v[3],m);

	glColor3f(0,0,1);
	div_triangle(v[0],v[2],v[3],m);

	glColor3f(0,0,0);
	div_triangle(v[1],v[2],v[3],m);
}



void display(){

	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	tetrahedron(m);
	glFlush();

}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2,2,-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char**argv){

	printf("Enter the no of division\n");
	scanf("%d",&m);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Sierpinski Gasket 1CR20CS109");


	myinit();
	glutDisplayFunc(display);

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
