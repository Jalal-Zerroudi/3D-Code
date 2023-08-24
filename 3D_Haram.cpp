#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float angle = 0.0f;
int turns = 0;
char turnsString[100];

void up_Turns(){
    turns++;
}

void Turns(){
   glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(10, 580);
    sprintf(turnsString, "Call update function after 25 milliseconds -- >> Turns: %d ", turns);
    int length= strlen(turnsString);

    for (int i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, turnsString[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

void JALAL(float A, float B, float c){
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    glRasterPos3f(A,B,c); // Set the position for rendering
    char text = '*'; // Text to render
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text);
}

void JALAL_SWIT(){
	float k=-1.3;
	while(k<=1.3){
		k+=0.02;
		JALAL(k,0.30,0);
    		JALAL(k,0.25,0.1);
    		JALAL(k,0.20,0.2);
    		JALAL(k,0.15,0.3);
    		JALAL(k,0.10,0.35);
    		JALAL(k,0.05,0.35);

    		JALAL(k,0.00,0.35);

    		JALAL(k,-0.05,0.35);
    		JALAL(k,-0.10,0.35);
    		JALAL(k,-0.15,0.3);
    		JALAL(k,-0.20,0.2);
    		JALAL(k,-0.25,0.1);
    		JALAL(k,-0.30,0);
}

}

void renderSphere(float red, float green, float blue) {
    glPushMatrix();
    glRotatef(-angle, 0.0f, 1.0f, 0.0f); // Rotate opposite to the pyramid
    glColor3f(red, green, blue); // Set color

    float radius = 0.5f; // Radius of the sphere
    int slices = 20; // Number of subdivisions around the z-axis
    int stacks = 20; // Number of subdivisions along the z-axis

    glutSolidSphere(radius, slices, stacks);

    glPopMatrix();
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set up perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

    // Set up camera position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(angle, 0.0f, 1.0f, 0.0f); // Rotate around the Y-axis

    // Render the pyramid
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);    // Top vertex
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);  // Front left vertex
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);   // Front right vertex

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);    // Top vertex
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);   // Front right vertex
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);  // Back right vertex


    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);    // Top vertex
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);  // Back right vertex
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f); // Back left vertex


    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    glRasterPos3f(-0.5f, 0.0f, 0.0f); // Set the position for rendering


    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);    // Top vertex
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f); // Back left vertex
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);  // Front left vertex
    glEnd();

    //JALAL(-0.1,0.99,0);
    //JALAL(0.1,0.99,0);
    // renderSphere(1.0f, 0.0f, 0.0f); 
    JALAL(0.3,0.30,0);
    JALAL(0.3,0.25,0.1);
    JALAL(0.3,0.20,0.2);
    JALAL(0.3,0.15,0.3);
    JALAL(0.3,0.10,0.35);
    JALAL(0.3,0.05,0.35);
    
    JALAL(0.3,0.00,0.35);
    
    JALAL(0.3,-0.05,0.35);
    JALAL(0.3,-0.10,0.35);
    JALAL(0.3,-0.15,0.3);
    JALAL(0.3,-0.20,0.2);
    JALAL(0.3,-0.25,0.1);
    JALAL(0.3,-0.30,0);
    

    JALAL(1.3,0.30,0);
    JALAL(1.3,0.25,0.1);
    JALAL(1.3,0.20,0.2);
    JALAL(1.3,0.15,0.3);
    JALAL(1.3,0.10,0.35);
    JALAL(1.3,0.05,0.35);
    
    JALAL(1.3,0.00,0.35);
    
    JALAL(1.3,-0.05,0.35);
    JALAL(1.3,-0.10,0.35);
    JALAL(1.3,-0.15,0.3);
    JALAL(1.3,-0.20,0.2);
    JALAL(1.3,-0.25,0.1);
    JALAL(1.3,-0.30,0);
	JALAL_SWIT();

Turns();

    glutSwapBuffers();
}

void update(int value) {
    angle += 2.0f;                // Update the angle of rotation
    up_Turns();
    glutPostRedisplay();          // Call the display function
    glutTimerFunc(25, update, 0); // Call update function after 25 milliseconds
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Jalal Zerroudi");

    glutDisplayFunc(renderScene);

    glutTimerFunc(3, update, 0);

    glutMainLoop();

    return 0;
}
