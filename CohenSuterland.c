#include<GL/glut.h>
#include<stdio.h>

int xmin, ymin, xmax, ymax;
int xvmin, yvmin, xvmax, yvmax;
int xt0, yt0, xt1, yt1;
int x0, y0, x1, y1;
int RIGHT=8;
int LEFT=2;
int TOP=4;
int BOTTOM=1;

int checkb(int x, int y)
{
int code=0;
if(y>ymax) code|=TOP;
if(y<ymin) code|=BOTTOM;
if(x>xmax) code|=RIGHT;
if(x<xmin) code|=LEFT;

return code;
}

void compute(int *x, int *y)
{
int code, tx, ty;
tx=*x;
ty=*y;
code=checkb(tx, ty);

if(code!=0)
{
if(code&TOP)
{
tx=x0+(x1-x0)*(ymax-y0)/(y1-y0);
ty=ymax;
}
if(code&BOTTOM)
{
tx=x0+(x1-x0)*(ymin-y0)/(y1-y0);
ty=ymin;
}
if(code&RIGHT)
{
ty=y0+(y1-y0)*(xmax-x0)/(x1-x0);
tx=xmax;
}
if(code&LEFT)
{
ty=y0+(y1-y0)*(xmin-x0)/(x1-x0);
tx=xmin;
}
*x=tx;
*y=ty;
}
}

void cohen()
{
compute(&x0,&y0);
compute(&x1,&y1);

int sx=(xvmax-xvmin)/(xmax-xmin);
int sy=(yvmax-yvmin)/(ymax-ymin);
int vx0=xvmin+(x0-xmin)*sx;
int vy0=yvmin+(y0-ymin)*sy;
int vx1=xvmin+(x1-xmin)*sx;
int vy1=yvmin+(y1-ymin)*sy;

glColor3f(1,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(xvmin,yvmin);
glVertex2f(xvmax,yvmin);
glVertex2f(xvmax,yvmax);
glVertex2f(xvmin,yvmax);
glEnd();

glColor3f(0,0,1);
glBegin(GL_LINES);
glVertex2d(vx0,vy0);
glVertex2d(vx1,vy1);
glEnd();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
glBegin(GL_LINES);
glVertex2d(xt0,yt0);
glVertex2d(xt1,yt1);
glEnd();

glColor3f(0,0,1);
glBegin(GL_LINE_LOOP);
glVertex2f(xmin,ymin);
glVertex2f(xmax,ymin);
glVertex2f(xmax,ymax);
glVertex2f(xmin,ymax);
glEnd();
cohen();
glFlush();
}

void init()
{
glClearColor(1,1,1,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,500,0,500);
}

int main(int argc, char** argv)
{
printf("Enter Clipping Window Co-ordinates\n");
scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
printf("Enter Line Co-ordinates\n");
scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
xt0=x0; yt0=y0; xt1=x1; yt1=y1;
printf("Enter Viewport Co-ordinates\n");
scanf("%d%d%d%d",&xvmin,&yvmin,&xvmax,&yvmax);

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("CS Line Clipping");
init();
glutDisplayFunc(display);
glutMainLoop();
}