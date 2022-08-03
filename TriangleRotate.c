#include<stdio.h>
#include<GL/glut.h>

float tri[5][2]={{200,100},{400,100},{300,300}};
float h=200,k=100;
float theta;
 
void drawtriangle()
{
 glBegin(GL_LINE_LOOP);
 glVertex2fv(tri[0]);
 glVertex2fv(tri[1]);
 glVertex2fv(tri[2]);
 glEnd();
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 drawtriangle();
 glTranslatef(h,k,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-h,-k,0);
 drawtriangle();
 glFlush();
}

void Init()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0,0,1);
gluOrtho2D(-700,700,-700,700);
}
int main(int argc,char **argv)
{
printf("enter the rotaion angle\n");
scanf("%f",&theta);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);

glutInitWindowSize(600,600);
glutCreateWindow("Triangle");
glutDisplayFunc(display);
Init();
glutMainLoop();
}
