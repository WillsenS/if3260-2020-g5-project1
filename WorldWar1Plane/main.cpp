/*
 * World War 1 Plane
 * using polygon
 */

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

static float rotXZ = 0.0;
static float rotXY = 0.0;
static float zoom = 0.0;

static float posX = 0.0;
static float posY = 0.0;
static float posZ = 0.0; //radius;

static float viewX = 0.0;
static float viewY = 0.0;
static float viewZ = 0.0;

static float upX = 0.0;
static float upY = 1.0;
static float upZ = 0.0;

static void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -7.0f);

//    glRotatef(0.0+rotX, 1.0, 0.0, 0.0);
//    glRotatef(0.0+rotY, 0.0, 1.0, 0.0);

    gluLookAt(posX, posY, posZ,
              viewX + cos(rotXZ * M_PI / 180), viewY, viewZ + sin(rotXZ * M_PI / 180),
              upX + cos(rotXY * M_PI / 180), upY + sin(rotXY * M_PI / 180), upZ);

    glScalef(1.0 + zoom, 1.0 + zoom, 1.0 + zoom);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 1.0, 1.0, 1.0);
    glVertex3f( 1.0, 1.0, -1.0);
    glVertex3f( -1.0, 1.0, -1.0);
    glVertex3f( -1.0, 1.0, 1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( -1.0, -1.0, 1.0);
    glVertex3f( -1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, 1.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( -1.0, 1.0, 1.0);
    glVertex3f( -1.0, -1.0, 1.0);
    glVertex3f( 1.0, -1.0, 1.0);
    glVertex3f( 1.0, 1.0, 1.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( -1.0, 1.0, -1.0);
    glVertex3f( 1.0, 1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( -1.0, -1.0, -1.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( -1.0, 1.0, 1.0);
    glVertex3f( -1.0, 1.0, -1.0);
    glVertex3f( -1.0, -1.0, -1.0);
    glVertex3f( -1.0, -1.0, 1.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 1.0, 1.0, 1.0);
    glVertex3f( 1.0, -1.0, 1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, 1.0, -1.0);

    glEnd();

    glFlush();
    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            exit(0);
            break;
        case 'w':
            rotXY+=5;
            upY = 0;
            break;
        case 's':
            rotXY-=5;
            upY = 0;
            break;
        case 'a':
            rotXZ+=5;
            break;
        case 'd':
            rotXZ-=5;
            break;
        case 'z':
            zoom+=0.1;
            break;
        case 'x':
            zoom-=0.1;
            break;
        case 'r':
            rotXZ = 0;
            rotXY = 0;
            zoom = 0;
            upY = 1;
            break;

    }

    glutPostRedisplay();
}

static void resize (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("World War 1 Plane");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}
