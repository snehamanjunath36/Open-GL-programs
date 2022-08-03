#include<glut.h>

float x1=200,y1=200,x2=100,y2=300,x3=200,y3=400,x4=300,y4=300;
float le[500],re[500];
int filled = 0;

void edgedetect(float x1,float y1,float x2,float y2) 
{
float mx,x,temp;
int y;
if(y2<y1)
{
temp=y1;  y1=y2;  y2=temp; 
temp=x1;  x1=x2;  x2=temp; 
}
if(y2>y1)
{
mx=(x2-x1)/(y2-y1); 
}
else
{
mx=x2-x1; 
}
x=x1;
for(y=y1;y<=y2;y++)
{
if(x<le[y])
{
le[y]=x;
}

if(x>re[y])
{
re[y]=x;
}
x = x + mx;
}
}

void scanfill()
{ 
int x,y;

for(y=0;y<500;y++) 
{
le[y]=500;
re[y]=0;
}
edgedetect(x1,y1,x2,y2); 
edgedetect(x2,y2,x3,y3); 
edgedetect(x3,y3,x4,y4);
edgedetect(x4,y4,x1,y1); 
glColor3f(1,0,0);
glPointSize(1); //Vary Point Size
glBegin(GL_POINTS); 
for(y=0;y<500;y++)
{
for(x=le[y];x<=re[y];x++)
{
glVertex2f(x,y);
}
}
glEnd();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT); 
glClearColor(1,1,1,0); 
if(filled==0)
{
glColor3f(0,0,1); 
glBegin(GL_LINE_LOOP);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glVertex2f(x4,y4); 
glEnd();
}
else
{
scanfill();
}
glFlush();
}

void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,500,0,500); 
}

void menu(int num)
{
if(num == 0)
{
filled = 1;
}
else
{
filled = 0;
}
glutPostRedisplay();
}

void createMenu()
{   
glutCreateMenu(menu); 
    	glutAddMenuEntry("Filled Polygon", 0);
glutAddMenuEntry("Un-Filled Polygon", 1);
  	glutAttachMenu(GLUT_RIGHT_BUTTON);
} 


void main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB |GLUT_SINGLE);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("Scan Line");
glutDisplayFunc(display);
createMenu();
init();
glutMainLoop();
}
