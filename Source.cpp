
#include <windows.h> 
#include <Gl/glut.h> 

float x = 0; // Initial x-coordinate of the object
float y = 0; // Initial y-coordinate of the object
int ligt = 0; // Variable to control lighting mode

// ---------------------------------Function to handle keyboard input---------------------------------
void windowKey(unsigned char key, int x, int y)
{
    if (key == '1') {
        ligt = 0; // Set lighting mode to 1
        glutPostRedisplay(); // Trigger redisplay
    }
    else if (key == '2') {
        ligt = 1; // Set lighting mode to 2
        glutPostRedisplay(); // Trigger redisplay
    }
}

// ---------------------------------Function to draw the scene---------------------------------
void draw()
{
    // Clear Color and Depth Buffers 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ---------------------------------Background---------------------------------
    glPushMatrix();
    gluLookAt(0, 0, 150, 0, 0, 0, 0, 1, 0); // Set the camera

    // Draw background-stars
    glColor3f(1, 1, 1); // White color for stars
    glPointSize(2); // Set point size
    glBegin(GL_POINTS); // Begin drawing points(stars)
    for (int i = 0; i < 100; ++i) { // Draw 100 stars
        float randX = rand() % 140 - 70; // Random x coordinate within range (-70, 70)
        float randY = rand() % 140 - 40; // Random y coordinate within range (-70, 70)
        glVertex2f(randX, randY);
    }
    glEnd(); // End drawing points(stars)

    // Draw background-sky
    glBegin(GL_QUADS);
    glColor3f(0.002, 0.035, 0.08);
    glVertex2d(-70, -40);
    glColor3f(0.01, 0.09, 0.2);
    glVertex2d(-70, 70);
    glColor3f(0.2, 0.35, 0.5);
    glVertex2d(70, 70);
    glColor3f(0.25, 0.42, 0.6);
    glVertex2d(70, -40);
    glEnd();
    // Draw background-land
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.15, 0.1);
    glVertex2d(-70, -70);
    glColor3f(0.2, 0.25, 0.2);
    glVertex2d(-70, -40);
    glColor3f(0.3, 0.35, 0.3);
    glVertex2d(70, -40);
    glColor3f(0.2, 0.25, 0.2);
    glVertex2d(70, -70);
    glEnd();
    glPopMatrix();

    // ---------------------------------Setup lighting for the scene---------------------------------
    glPushMatrix();
    gluLookAt(0, 0, 150, 0, 0, 0, 0, 1, 0); // Set the camera 
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    if (ligt == 0) {
        glEnable(GL_COLOR_MATERIAL); //to keep the colors that we defined
    }
    else if (ligt == 1) {

        glShadeModel(GL_FLAT);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        // Perl material
        GLfloat  mat_ambient2[] = { 0.25, 0.20725, 0.20725, 0.922 };
        GLfloat mat_diffuse2[] = { 1, 0.829, 0.829, 0.922 };
        GLfloat mat_specular2[] = { 0.296648, 0.296648, 0.296648, 0.922 };
        float shine = 11.264;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient2);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse2);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular2);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
    }

    //---------------------------------the space ship, moon, and clouds---------------------------------

    // Draw the moon                    
    glColor3f(1, 0.906, 0.702);
    glPushMatrix();
    glTranslated(-50, 50, 0); // Translate to the top left corner
    glutSolidSphere(10, 30, 30); // Draw the moon
    glPopMatrix();

    // Draw cloud 1
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslated(-30, 20, 0);
    glutSolidSphere(5, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-20, 25, 0);
    glutSolidSphere(7, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-10, 22, 0);
    glutSolidSphere(6, 30, 30);
    glPopMatrix();

    // Draw cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslated(30, 30, 0);
    glutSolidSphere(5, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glTranslated(20, 35, 0);

    glutSolidSphere(7, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glTranslated(10, 32, 0);
    glutSolidSphere(6, 30, 30);
    glPopMatrix();

    // Draw cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslated(5, 45, 0);
    glutSolidSphere(5, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-5, 50, 0);
    glutSolidSphere(7, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-15, 47, 0);
    glutSolidSphere(6, 30, 30);
    glPopMatrix();

    // Draw the space ship
    // to update space shape position(to make it move)
    x += 0.1; //like the speed of the obj
    if (x > 50) {
        x = -50;
    }
    y += 0.1;
    if (y > 50) {
        y = -50;
    }
    glColor3f(0.851, 0.851, 0.851);
    glTranslated(x, y, 0);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glutSolidSphere(15, 30, 30);
    glPopMatrix();

    glColor3f(0.251, 0.494, 0.678);
    glPushMatrix();
    glTranslated(0, -5, 0);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(5, 20, 30, 30);
    glPopMatrix();

    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslated(0, 5, 0);
    glRotatef(90, 1, 0, 0);
    glutSolidCone(15, 25, 30, 30);
    glPopMatrix();
    // Space ship beam
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslated(0, -30, 0);
    glScalef(1, -1, 1);
    glRotatef(90, 1, 0, 0);
    glutSolidCone(10, 20, 30, 30);
    glPopMatrix();

    glPopMatrix(); // End of the objects

    // Disable lighting
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHT0);


    glutSwapBuffers(); // Swap buffers
}

// ---------------------------------Main function---------------------------------
int main() {

    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(800, 700);
    glutCreateWindow("Project_Group5");

    glEnable(GL_DEPTH_TEST); // Enable depth test

    // Set projection type
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reset matrix
    gluPerspective(45, 1, 30, -100);

    // Set matrix mode for modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // Reset matrix

    // display draw and keyboard function callbacks
    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutKeyboardFunc(windowKey);
    glutMainLoop();

}