#include<stdio.h>
#include<GL/glut.h>

typedef float point[3];
point v[]={{0,0,1},{0,1,0},{-1,-0.5,0},{1,-0.5,0}};
int n;
void triangle(point a,point b,point c)
{
glBegin(GL_POLYGON);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}

void drawtetra(point a,point b,point c,point d)
{
glColor3f(1,0,0);
triangle(a,b,c);

glColor3f(0,1,0);
triangle(a,c,d);

glColor3f(0,0,1);
triangle(a,d,b);

glColor3f(0,0,0);
triangle(b,d,c);
}

void dt(point a,point b,point c,point d,int m)
{
point v1,v2,v3,v4,v5,v6;
int j;
if(m>0)
{
for(j=0;j<3;j++)v1[j]=(a[j]+b[j])/2;
for(j=0;j<3;j++)v2[j]=(a[j]+c[j])/2;
for(j=0;j<3;j++)v3[j]=(a[j]+d[j])/2;
for(j=0;j<3;j++)v4[j]=(b[j]+c[j])/2;
for(j=0;j<3;j++)v5[j]=(c[j]+d[j])/2;
for(j=0;j<3;j++)v6[j]=(b[j]+d[j])/2;

dt(a,v1,v2,v3,m-1);
dt(v1,b,v4,v6,m-1);
dt(v2,v4,c,v5,m-1);
dt(v3,v6,v5,d,m-1);
}
else
drawtetra(a,b,c,d);
}

void display(void)
{
glClearColor(1,1,1,0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
dt(v[0],v[1],v[2],v[3],n);
glFlush();
}

void myReshape(int w,int h)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2,2,-2,2,-2,2);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glutPostRedisplay();
}

int main(int argc,char **argv)
{
printf("N0. of Divisions?\n");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("3D Gasket");
glutDisplayFunc(display);
glutReshapeFunc(myReshape);

glEnable(GL_DEPTH_TEST);
glutMainLoop();
}
