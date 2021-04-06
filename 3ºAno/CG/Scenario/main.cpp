#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <tuple>
#include <iostream>

#define Num_Trees 300
using namespace std;


float alfa = 0.0f, beta = 0.5f, radius = 100.0f;
float camX, camY, camZ;
float two_pi = 2.0 * M_PI;

float r = 50;  // circulo exterior
float ri = 35;
float rc = 15;


float inner_slices = 10;
float outter_slices = 20;

float inner_angle = 2* M_PI / inner_slices; // inner teapots angle
float outter_angle = 2* M_PI / outter_slices; // outter teapots angle

float animation_outter = 0.0f;
float animation_inner = 0.0f;


class Tree{
public:
    float trans_x = 0.0f;
    float trans_y = 0.0f;
    float trans_z = 0.0f;

    Tree(float x, float y, float z){
        trans_x = x;
        trans_y = y;
        trans_z = z;
    }
    void set(float x, float y, float z){
        trans_x = x;
        trans_y = y;
        trans_z = z;
    }
};

class Tree_color{
public:
    float colour_R = 0.0f;
    float colour_G = 0.0f;
    float colour_B = 0.0f;

    Tree_color(float r, float g, float b){
         colour_R = r;
         colour_G = g;
         colour_B = b;
    }

    void set(float r, float g, float b){
        colour_R = r;
        colour_G = g;
        colour_B = b;
    }

};

std::vector<Tree> trees;
std::vector<Tree_color> tree_color;


void spherical2Cartesian() {

	camX = radius * cos(beta) * sin(alfa);
	camY = radius * sin(beta);
	camZ = radius * cos(beta) * cos(alfa);
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


//draw inner Teapots

void inner_teapot(){

    for (int i=0 ; i < 10; i++){

        if (i % 2 == 0){
            glColor3f(1.0f,0.0f,0.0f);
        }else{
            glColor3f(1.0f,1.0f,1.0f);
        }

        glPushMatrix();
            float ang = (i * inner_angle) + animation_inner;
            glTranslatef(sin(ang) * rc , 4.0f, cos(ang) * rc);
            glRotatef(ang,0.0f,1.0f,0.0f);
            //glRotatef( 90 + i * 360/inner_slices,0,1,0);
            glutSolidTeapot(2.5);
        glPopMatrix();
    }
}


//draw outter Teapots

void outter_teapot(){
    for (int i=0 ; i < 20; i++){
        if (i % 2 == 1){
            glColor3f(1.0f,0.0f,0.0f);
        }else{
            glColor3f(1.0f,1.0f,1.0f);
        }
        glPushMatrix();
            float ang = (i* outter_angle) - animation_outter;
            glTranslatef(sin(ang) * ri, 4.0f, cos(ang) * ri);
            glRotatef(ang,0.0f,1.0f,0.0f);
            glutSolidTeapot(2.5);
        glPopMatrix();
    }
}

//draw Torus
void torus(){
    glColor3f(0.0f,0.0f,1.0f);

    glPushMatrix();
        glTranslatef( 0.0f,2.0f,0.0f);
        glRotatef(90,1.0f,0.0f,0.0f);
        glutSolidTorus(1,6.5,40,40);
    glPopMatrix();
}


float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}



// Create random trees

void generate_trees(){
    Tree t(r,0.0f,0.0f);
    trees.push_back(t);
    for (int i = 0; i < 50; i++){
        t.set(RandomFloat(r,99.0f),0,RandomFloat(0.0f,99.0f)); // ( 50 < x < 100,0.0,0 < z < 99)
        trees.push_back(t);
        t.set(RandomFloat(r,99.0f),0,-RandomFloat(0,99.f)); // ( 50 < x < 100,0.0,-99 < z < 0)
        trees.push_back(t);

        t.set(-RandomFloat(r,99.0f),0,RandomFloat(0.0f,99.f)); // ( -50 < x < 100,0.0,0 < z < 99)
        trees.push_back(t);
        t.set(-RandomFloat(r,99.0f),0,-RandomFloat(0.0f,99.f)); // ( -50 < x < 100,0.0,-99 < z < 0)
        trees.push_back(t);

        t.set(RandomFloat(-r,r),0,RandomFloat(r,99.0f)); //(-50< x < 50, 0 ,50 < z < 99)
        trees.push_back(t);
        t.set(RandomFloat(-r,r),0,-RandomFloat(r,99.0f)); //(-50< x < 50, 0 ,-99 < z < -50)
        trees.push_back(t);
    }
}
// create colours for trees
void insert_colour(){
    Tree_color c(0.13f,0.55f,0.13f);
    tree_color.push_back(c);
    c.set(0.1960f,0.8f,0.1960f);
    tree_color.push_back(c);
    c.set(0.13f,0.545f,0.13f);
    tree_color.push_back(c);
    c.set(0.0f,0.39f,0.0f);
    tree_color.push_back(c);
    c.set(0.678f,1.0f,0.18f);
    tree_color.push_back(c);
}

//Draw all trees

void draw_trees(){
    for (int i = 0; i < Num_Trees; i++){
        //int random height
        int height = rand()%(20-15 + 1) + 15;
        // random color
        //int color = rand() % (tree_color.size() - 0 + 1) + 0;
        // tronco

        glColor3f(0.55f, 0.27f, 0.07f);

        glPushMatrix();
            glTranslatef(trees[i].trans_x,trees[i].trans_y,trees[i].trans_z);
            glRotatef(-90,1.0f,0,0);
            glutSolidCone(2,5,40,40);
            // como não se dá pop, o translate só precisa de subir em altura, sobe no z porque foi feito um rotate de 90 graus.
            glTranslatef(0.0f,0.0f,4);

            glColor3f(0.13f,0.55f,0.13f);
            //glColor3f(0.0, 0.39, 0.0f);
            glutSolidCone(5,height,40,40);
        glPopMatrix();
    }

}

//draw hat
void draw_hat() {

    //draw circle
    float prevX = 0.0f;
    float prevZ = 0.0f - 8;
    glPushMatrix();
        glTranslatef(0.0f,23,0);
        glColor3f(0.6f,0.6f,0.0f);
        for (int i = 0; i <= 40; i++) {

            float x = 8 * sin((i * two_pi) / 40);
            float z = 8 * cos((i * two_pi) / 40);

            glBegin(GL_TRIANGLES);
                glVertex3f(prevX,0.0f,prevZ);
                glVertex3f(0.0f,0.0f,0.0f);
                glVertex3f(x,0.0f,z);
            glEnd();
            prevX = x;
            prevZ = z;
        }
    glPopMatrix();

    //draw cylinder
    glPushMatrix();
        glColor3f(0.6f,0.6f,0.0f);
        glTranslatef(0.0f,23,0);
        prevX = 4 * sin((0 * two_pi) / 40);
        prevZ = 4 * cos((0 * two_pi) / 40);

        for (int i = 1; i <= 40; i++){

            float x = 4 * sin((i * two_pi) / 40);
            float z = 4 * cos((i * two_pi) / 40);

            glBegin(GL_TRIANGLES);

            glVertex3f(prevX,0.0f,prevZ);
            glVertex3f(x,0.0f,z);
            glVertex3f(x,7,z);
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(x,7,z);
            glVertex3f(prevX,7,prevZ);
            glVertex3f(prevX,0.0f,prevZ);
            glEnd();

            prevX = x;
            prevZ = z;
        }
    glPopMatrix();

    // draw up circle
    prevX = 0.0f;
    prevZ = 0.0f - 4;
    glPushMatrix();
        glTranslatef(0.0f,30,0);
        glColor3f(0.6f,0.6f,0.0f);
        for (int i = 0; i <= 40; i++) {

            float x = 4 * sin((i * two_pi) / 40);
            float z = 4 * cos((i * two_pi) / 40);

            glBegin(GL_TRIANGLES);
            glVertex3f(prevX,0.0f,prevZ);
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(x,0.0f,z);
            glEnd();

            prevX = x;
            prevZ = z;
        }
    glPopMatrix();
}

//draw buttons
void draw_buttons(){
    glColor3f(0,0,0);
    glPushMatrix();
        glTranslatef(0.0f,5.0,7.5f);
        glutSolidSphere(0.5,40,40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f,8.0,7.9f);
        glutSolidSphere(0.5,40,40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f,11.0,7.2f);
        glutSolidSphere(0.5,40,40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f,14.0,4.9f);
        glutSolidSphere(0.5,40,40);
    glPopMatrix();
}

void draw_arms(){

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(5.0f,11,4);
    glRotatef(-45,0.0f,0.0,1);

    float prevX = 0.5 * sin((0 * two_pi) / 40);
    float prevZ = 0.5 * cos((0 * two_pi) / 40);

    for (int i = 1; i <= 40; i++){

        float x = 0.5 * sin((i * two_pi) / 40);
        float z = 0.5 * cos((i * two_pi) / 40);

        glBegin(GL_TRIANGLES);

        glVertex3f(prevX,0.0f,prevZ);
        glVertex3f(x,0.0f,z);
        glVertex3f(x,7,z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(x,7,z);
        glVertex3f(prevX,7,prevZ);
        glVertex3f(prevX,0.0f,prevZ);
        glEnd();

        prevX = x;
        prevZ = z;
    }
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-5.0f,11,4);
        glRotatef(45,0.0f,0.0,1);
        prevX = 0.5 * sin((0 * two_pi) / 40);
        prevZ = 0.5 * cos((0 * two_pi) / 40);

        for (int i = 1; i <= 40; i++){

            float x = 0.5 * sin((i * two_pi) / 40);
            float z = 0.5 * cos((i * two_pi) / 40);

            glBegin(GL_TRIANGLES);

            glVertex3f(prevX,0.0f,prevZ);
            glVertex3f(x,0.0f,z);
            glVertex3f(x,7,z);
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(x,7,z);
            glVertex3f(prevX,7,prevZ);
            glVertex3f(prevX,0.0f,prevZ);
            glEnd();

            prevX = x;
            prevZ = z;
        }
    glPopMatrix();
}

//draw snowman
void snowman(){

    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
        //first sphere
        glTranslatef(0.0f,7.5f,0.0f);
        glutSolidSphere(8,40,40);
        //second sphere
        glTranslatef(0.0f,4+7.5f,0.0f);
        glutSolidSphere(5,40,40);

        //nose
        glColor3f(1.0f,0.27f,0.0f);
        glTranslatef(0.0f,0.0f,4.5f);
        glutSolidCone(1,3,40,40);

        //eyes
        glColor3f(0.0f,0.0f,0.0f);

        glPushMatrix();
            glTranslatef(2.0f,2.0f,0.f);
            glutSolidSphere(0.5,40,40);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-2.0f,2.0f,0.f);
            glutSolidSphere(0.5,40,40);
        glPopMatrix();
    glPopMatrix();
    draw_buttons();
}

// Draw underground
void underground(){

    glColor3f(0.36f, 0.18f, 0.0f);

    glBegin(GL_TRIANGLES);
        glVertex3f(100.0f, -30, -100.0f);
        glVertex3f(-100.0f, -30, -100.0f);
        glVertex3f(-100.0f, -30, 100.0f);

        glVertex3f(100.0f, -30, -100.0f);
        glVertex3f(-100.0f, -30, 100.0f);
        glVertex3f(100.0f, -30, 100.0f);

        glVertex3f(100.0f,0, 100.0f);
        glVertex3f(-100.0f, -30, 100.0f);
        glVertex3f(100.0f,-30,100.0f);

        glVertex3f(100.0f,0, 100.0f);
        glVertex3f(-100.0f, 0, 100.0f);
        glVertex3f(-100.0f, -30, 100.0f);

        glVertex3f(100,0,100);
        glVertex3f(100,-30,100);
        glVertex3f(100,0,-100);

        glVertex3f(100,-30,100);
        glVertex3f(100,-30,-100);
        glVertex3f(100,0,-100);

        glVertex3f(100,0,-100);
        glVertex3f(100,-30,-100);
        glVertex3f(-100,-30,-100);

        glVertex3f(100,0,-100);
        glVertex3f(-100,-30,-100);
        glVertex3f(-100,0,-100);

        glVertex3f(-100,0,100);
        glVertex3f(-100,-30,100);
        glVertex3f(-100,-30,-100);

        glVertex3f(-100,0,100);
        glVertex3f(-100,0,-100);
        glVertex3f(-100,-30,-100);
    glEnd();
}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(camX, camY, camZ,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	glColor3f(0.2f, 0.8f, 0.2f);

	glBegin(GL_TRIANGLES);
		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);

		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);
		glVertex3f(100.0f, 0, 100.0f);
	glEnd();
	// End of frame
	
	
	// put code to draw scene in here
    underground();
    inner_teapot();
    outter_teapot();
    torus();
    generate_trees();
    insert_colour();
    srand(42);
    draw_trees();
    snowman();
    draw_hat();
    draw_arms();
	glutSwapBuffers();
}

void timer(int){
    animation_outter += 0.02;
    animation_inner += 0.02;
    glutPostRedisplay();
    glutTimerFunc(25,timer,0);
}


void processKeys(unsigned char c, int xx, int yy) {

    switch (c) {
        case 'r':
            animation_outter += 0.08;
            animation_inner += 0.08,
            glutPostRedisplay();
            break;
        default:
            break;
    }
}


void processSpecialKeys(int key, int xx, int yy) {

	switch (key) {

	case GLUT_KEY_RIGHT:
		alfa -= 0.1; break;

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

	case GLUT_KEY_PAGE_DOWN: radius -= 3.0f;
		if (radius < 1.0f)
			radius = 1.0f;
		break;

	case GLUT_KEY_PAGE_UP: radius += 3.0f; break;
	}
	spherical2Cartesian();
	glutPostRedisplay();
}


void printInfo() {

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));

	printf("\nUse Arrows to move the camera up/down and left/right\n");
	printf("Home and End control the distance from the camera to the origin");
}


int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("cenário");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	
// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	spherical2Cartesian();

	printInfo();

// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
