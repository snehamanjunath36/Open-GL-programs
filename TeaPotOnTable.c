#include<glut.h>

void tableLeg()
{	
	glPushMatrix();
	glTranslated(0,-3.5,0);
	glScaled(0.05,1,0.05);
	glutSolidCube(5);
	glPopMatrix();
}

void table()
{	
	glPushMatrix();
	glTranslated(0,-1,0);
	glScaled(1,0.05,1);
	glutSolidCube(10);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-4,0,4);
	tableLeg();

	glTranslated(0,0,-8);
	tableLeg();

	glTranslated(8,0,0);
	tableLeg();
	
	glTranslated(0,0,8);
	tableLeg();
	glPopMatrix();
}
void init()
{     
    GLfloat mat_diffuse[] = {0.8, 0.8, 0.7, 1.0};
    GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0}; 
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {10.0};

    GLfloat light_ambient[]={0.0,0.0,0.0,1.0};
    GLfloat light_diffuse[]={1.0,1.0,1.0,1.0};
    GLfloat light_specular[]={1.0,1.0,1.0,1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0);  
    glEnable(GL_DEPTH_TEST);  
    
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glColor3f(0.1, 0.1, 0.1);
  
    GLfloat lightIntensity[] = {0.6, 0.6, 0.5, 1.0};
    GLfloat light_position[] = {3.0, 7.0, 3.0, 0.0};
	
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void display(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-10,10,-10,10,-10,10);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(4,0,0,-5,-2,-5,0,1,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glutSolidTeapot(1);
	glPopMatrix();
		
	glPushMatrix();
	table();
	glPopMatrix();	
	
	glFlush();
}

void main(int argc, char ** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Shaded scene consisting of a tea pot on a table");
	glClearColor(0.1, 0.1, 0.1, 1.0);
	
	init();
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutMainLoop();
}

