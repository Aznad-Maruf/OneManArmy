#include <GL/glut.h>

//void shapes(void) {
//
//	/*glColor3f(1.0, 1.0, 1.0); //this will set a color of the square.
//	glBegin(GL_LINES); // write shape u want to create
//	glVertex3f(-0.5, -0.5, 0.0);
//	glVertex3f(-0.5, 0.5, 0.0);
//	glVertex3f(0.5, 0.5, 0.0);
//	glVertex3f(0.5, -0.5, 0.0);*/
//
//	/*glBegin(GL_POINTS);
//	glVertex3f(.5,.5,0);
//	glVertex3f(-.5,-.5,0);
//	glVertex3f(0,.5,0);
//	glVertex3f(.5,0,0);
//	glVertex3f(0,0,0);*/
//
//	/*glBegin(GL_LINE_STRIP);
//	  glVertex3f(0,0,0);
//	  glVertex3f(-.5,0,0);
//	  glVertex3f(.5,.5,0);
//	  glVertex3f(-.5,.5,0);
//	  glVertex3f(.5,0,0);*/
//
//	  /*glBegin(GL_POLYGON);
//	  glColor3f(1, 0, 0);
//	  glVertex3f(-0.6, -0.75, 0);
//	  glColor3f(0, 1, 0);
//	  glVertex3f(0.6, -0.75, 0);
//	  glColor3f(0, 0, 1);
//	  glVertex3f(0, 0.75, 0);*/
//
//	  /*glBegin(GL_TRIANGLES);
//	  glColor3f(0.5, 0.5, 0.5);
//	  glVertex3f(0, 0, 0);
//	  glVertex3f(1, .2, 1);
//	  glVertex3f(-.5, .5, 2);*/
//
//
//	  glBegin(GL_QUADS);
//	  glVertex3f(-0.5, -0.5, 0.0);
//	  glVertex3f(-0.5, 0.5, 0.0);
//	  glVertex3f(0.5, 0.5, 0.0);
//	  glVertex3f(0.5, -0.5, 0.0);
//
//	  /*glBegin(GL_TRIANGLE_FAN);
//		   glColor3f(1,0,0);
//		   glVertex2f(0,0.5);
//		   glVertex2f(-0.4,0);
//		   glVertex2f(0.4,0);
//		   glVertex2f(0,-0.5);*/
//	  
//
//	glEnd();
//}
//
//void display(void) {
//
//	// clearing the window with black color, 1st 3 parameter are for R,G,B. last one for opacity
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glLoadIdentity();
//	//viewing transformation
////glulookat() positions the camera towards the object 
////camera position, camera target, upvector
//	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//	shapes();
//	glFlush();
//}
//
//void reshape(int w, int h) {
//
//	// 1st 2 parameters for lower left corner of the viewport rectangle. the default is 0,0
//	// the next coordinates are width and hight of the viewport
////Set the viewport to be the entire window
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//
//	// setting the camera
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	//perspective transform
//	//gluPerspective (30, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
//	gluPerspective(30, 1, 1.0, 100.0);
//	glMatrixMode(GL_MODELVIEW); //switch back the the model editing mode.
//
//}

int window_width = 1100, window_height = 750;

void display();
void reshape(int, int);
void draw();

void init(int *argc, char** argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(window_width, window_height);

	glutCreateWindow("!Game ON!");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glClearColor(0, 0, 0, 1); //background
}

int main(int argc, char** argv) {
	init(&argc, argv);
	glutMainLoop();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity(); // reset coordinate

	draw();

	glFlush();
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 0, window_width, window_height);
	glMatrixMode(GL_MODELVIEW);
}

void draw() {
	glBegin(GL_POINTS);
	glPointSize(10.0);
	glVertex2d(550, 375);
	glEnd();
}