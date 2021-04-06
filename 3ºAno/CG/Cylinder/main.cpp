#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

float alfa = 0.0f, beta = 0.5f, radius = 4.0f;
float camX, camY, camZ;

float r = 0.4f;
int v = 40;
float h = 1.0f;
float two_pi = 2.0 * M_PI;

float frame;
int timebase;

void sphericalCam(){
    camX = radius * cos(beta) * sin(alfa);
    camY = radius * sin(beta);
    camZ = radius * cos(beta) * cos(alfa);
}

// draw functions

void drawCylinder(float radius, float height,int vertices){

    // bases
    float prevX = 0.0f;
    float prevZ = 0.0f - radius;

    for (int i = 0; i <= vertices; i++) {

        if (i % 2 == 1){
            glColor3f(1.0f,0.0f,0.0f);
        }else{
            glColor3f(1.0f,1.0f,1.0f);
        }

        float x = radius * sin((i * two_pi) / v);
        float z = radius * cos((i * two_pi) / v);

        glBegin(GL_TRIANGLES);

        glVertex3f(prevX,0.0f,prevZ);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(x,0.0f,z);

        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f,height,0.0f);
        glVertex3f(prevX,height,prevZ);
        glVertex3f(x,height,z);
        glEnd();

       prevX = x;
       prevZ = z;
    }

    prevX = radius * sin((0 * two_pi) / v);
    prevZ = radius * cos((0 * two_pi) / v);

    for (int i = 1; i <= vertices; i++){

        float x = radius * sin((i * two_pi) / v);
        float z = radius * cos((i * two_pi) / v);

        if (i % 2 == 1){
            glColor3f(1.0f,0.0f,0.0f);
        }else{
            glColor3f(1.0f,1.0f,1.0f);
        }
        glBegin(GL_TRIANGLES);

        glVertex3f(prevX,0.0f,prevZ);
        glVertex3f(x,0.0f,z);
        glVertex3f(x,height,z);

        glEnd();

        if (i % 2 == 1){
            glColor3f(1.0f,0.0f,0.0f);
        }else{
            glColor3f(1.0f,1.0f,1.0f);
        }
        glBegin(GL_TRIANGLES);

        glVertex3f(x,height,z);
        glVertex3f(prevX,height,prevZ);
        glVertex3f(prevX,0.0f,prevZ);
        glEnd();

        prevX = x;
        prevZ = z;
    }
}



// axis
void draw_axis(){
    glBegin(GL_LINES);
    // X axis in red
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(100.0f,0.0f,0.0f);
    // Y Axis in green
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,100.0f,0.0f);
    // z Axis on Blue
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,100.0f);
    glEnd();
}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(camX,camY,camZ,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

// put the geometric transformations here
    draw_axis();
    drawCylinder(r,h,v);

// put drawing instructions here
	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events
void specialkeys(int key, int x, int y){

    switch (key) {
        case GLUT_KEY_RIGHT:
            alfa -= 0.1;
            break;
        case GLUT_KEY_LEFT:
            alfa += 0.1; break;
        case GLUT_KEY_UP:
            beta += 0.1f;
            if (beta > 1.5f)
                beta = 1.5f;
            break;
        case GLUT_KEY_DOWN:
            beta -= 0.1f;
            if (beta < -1.5f)
                beta = -1.5f;
            break;
    }
    sphericalCam();
    glutPostRedisplay();
}





int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("Cylinder");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	
// put here the registration of the keyboard callbacks
    glutSpecialFunc(specialkeys);
    timebase = glutGet(GLUT_ELAPSED_TIME);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
    sphericalCam();
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
