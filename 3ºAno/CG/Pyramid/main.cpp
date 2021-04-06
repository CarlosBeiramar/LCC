#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

float angle = 0.0f;
float x = 0.0f;
float y = 1.0f;
float z = 0.0f;
float x_position = 0.0f;
float y_position = 0.0f;
float z_position = 0.0f;

float radius = 2.0f;
int vertices = 16;
float height= 4.0f;
float two_pi = 2.0 * M_PI;


void rotate(int key, int x, int y);
void axis_rotate (unsigned char key, int x, int y);

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

	gluLookAt(20.0,20.0,20.0,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

// put the geometric transformations here
    glRotatef(angle,x,y,z);

// put drawing instructions here
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

    glTranslatef(x_position,y_position,z_position);


    float prevX = 0.0f;
    float prevZ = 0.0f - radius;

    for (int i = 0; i <= vertices; i++) {

        if (i % 2 == 1){
            glColor3f(1.0f,0.0f,0.0f);
        }else{
            glColor3f(1.0f,1.0f,1.0f);
        }

        float x = radius * sin((i * two_pi) / vertices);
        float z = radius * cos((i * two_pi) / vertices);

        glBegin(GL_TRIANGLES);

        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(prevX,0.0f,prevZ);
        glVertex3f(x,0.0f,z);
        glEnd();


        


        prevX = x;
        prevZ = z;
    }

    prevX = radius * sin((0 * two_pi) / vertices);
    prevZ = radius * cos((0 * two_pi) / vertices);

    for (int i = 1; i <= vertices; i++){

        float x = radius * sin((i * two_pi) / vertices);
        float z = radius * cos((i * two_pi) / vertices );


        if (i % 2 == 1){
            glColor3f(1.0f,0.0f,0.0f);
        }else{
            glColor3f(1.0f,1.0f,1.0f);
        }

        glBegin(GL_TRIANGLES);

        glVertex3f(0.0f,height,0.0f);
        glVertex3f(prevX,0.0f,prevZ);
        glVertex3f(x,0.0f,z);

        glEnd();

        prevX = x;
        prevZ = z;

    }

/*    glBegin( GL_TRIANGLES );

    // Base
    glColor4f(1.0f,0.0f,0.0f,0.65f);
    glVertex3f(1.0f,0.0f,-1.0f);  //v4
    glVertex3f(1.0f,0.0f,1.0f); //v1
    glVertex3f(-1.0f,0.0f,-1.0f); //v2

    glColor4f(1.0f,1.0f,1.0f,0.65f);
    glVertex3f(1.0f,0.0f,1.0f); //v1
    glVertex3f(-1.0f,0.0f,1.0f);  //v3
    glVertex3f(-1.0f,0.0f,-1.0f); //v2


    //pyramid
    glColor4f(1.0f, 1.0f, 1.0f,0.65f);
    glVertex3f(0.0f,2.5f,0.0f); //v5
    glVertex3f(-1.0f,0.0f,1.0f);  //v3
    glVertex3f(1.0f,0.0f,1.0f); //v1

    glColor4f(1.0f, 0.0f, 0.0f,0.65f);
    glVertex3f(0.0f,2.5f,0.0f); //v5
    glVertex3f(1.0f,0.0f,1.0f); //v1
    glVertex3f(1.0f,0.0f,-1.0f);  //v4

    glColor4f(1.0f, 1.0f, 1.0f,0.65f);
    glVertex3f(0.0f,2.5f,0.0f); //v5
    glVertex3f(-1.0f,0.0f,-1.0f); //v2
    glVertex3f(-1.0f,0.0f,1.0f);  //v3

    glColor4f(1.0f, 0.0f, 0.0f,0.65f);
    glVertex3f(0.0f,2.5f,0.0f); //v5
    glVertex3f(1.0f,0.0f,-1.0f);  //v4
    glVertex3f(-1.0f,0.0f,-1.0f); //v2

    glEnd();*/


	// End of frame
	glutSwapBuffers();
}

// write function to process keyboard events
void rotate(int key, int x, int y){
    switch (key) {
        case GLUT_KEY_LEFT:
            angle += 7.5;
            break;
        case GLUT_KEY_RIGHT:
            angle -=7.5;
            break;
    }
    glutPostRedisplay();
}


void axis_rotate (unsigned char key, int eixox, int eixoy){
    switch (key) {
        case 'd':
            if (x_position < 5.0)
            x_position += 0.2;
            break;
        case 'a':
            if (x_position > -5.0) x_position -=0.2;
            break;
        case 'w':
            if (y_position < 5.0) y_position += 0.2;
            break;
        case 's':
            if (y_position > -5.0) y_position -=0.2;
            break;
        case 'q':
            if (z_position < 5.0) z_position += 0.2;
            break;
        case 'e':
            if (z_position > -5.0) z_position -= 0.2;
            break;
        case 'r':
            x_position = 0.0f;
            y_position = 0.0f;
            z_position = 0.0f;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}




int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("Pyramid");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	
// put here the registration of the keyboard callbacks
    glutSpecialFunc(rotate);
    glutKeyboardFunc(axis_rotate);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
