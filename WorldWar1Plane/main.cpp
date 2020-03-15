/*
 * World War 1 Plane
 * using polygon
 */

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

static float rotCamXY = 0.0;//kamera mengitari model
static float rotCamPro = 0.0; //memutar bidang proyeksi kamera
static float zoom = 0.0; //radius

static float rotX = 0.0;
static float rotY = 0.0;
static float rotZ = 0.0;

static float refX = 0.0;
static float refY = 0.0;
static float refZ = 0.0;

static float posX = 0.0;
static float posY = 0.0;
static float posZ = 0.0; //radius;

static float viewX = 0.0;
static float viewY = 0.0;
static float viewZ = 0.0;

static float upX = 0.0;
static float upY = 0.0;
static float upZ = 1.0;

static void init(void)
{
    glClearColor(0,0,0,0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3ub(255, 255, 255);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -7.0f + zoom);

    glRotatef(0.0+rotX, 1.0, 0.0, 0.0);
    glRotatef(0.0+rotY, 0.0, 1.0, 0.0);
    glRotatef(0.0+rotZ, 0.0, 0.0, 1.0);

    gluLookAt(posX, posY, posZ,
              viewX, viewY, viewZ,
              upX + refX, upY + refY, upZ + refZ);

    glScalef(1.0, 1.0, 1.0);

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

    glRotatef(0.0+rotX, 1.0, 0.0, 0.0);
    glRotatef(0.0+rotY, 0.0, 1.0, 0.0);
    glRotatef(0.0+rotZ, 0.0, 0.0, 1.0);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 4.0, 4.0, 4.0);
    glVertex3f( 4.0, 4.0, 2.0);
    glVertex3f( 2.0, 4.0, 2.0);
    glVertex3f( 2.0, 4.0, 4.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 2.0, 2.0, 4.0);
    glVertex3f( 2.0, 2.0, 2.0);
    glVertex3f( 4.0, 2.0, 2.0);
    glVertex3f( 4.0, 2.0, 4.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( 2.0, 4.0, 4.0);
    glVertex3f( 2.0, 2.0, 4.0);
    glVertex3f( 4.0, 2.0, 4.0);
    glVertex3f( 4.0, 4.0, 4.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( 2.0, 4.0, 2.0);
    glVertex3f( 4.0, 4.0, 2.0);
    glVertex3f( 4.0, 2.0, 2.0);
    glVertex3f( 2.0, 2.0, 2.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 2.0, 4.0, 4.0);
    glVertex3f( 2.0, 4.0, 2.0);
    glVertex3f( 2.0, 2.0, 2.0);
    glVertex3f( 2.0, 2.0, 4.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 4.0, 4.0, 4.0);
    glVertex3f( 4.0, 2.0, 4.0);
    glVertex3f( 4.0, 2.0, 2.0);
    glVertex3f( 4.0, 4.0, 2.0);

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
        case 's':
            //posX = (zoom + view)
            break;
        case 'a':
            break;
        case 'd':
            break;
        case 'w':
            rotCamXY+=3;
            posX = cos(M_PI * rotXY / 180);
            posY = sin(M_PI * rotXY / 180);
            break;
        case 'x':
            rotX+=3;
            break;
        case 'y':
            rotY+=3;
            break;
        case 'z':
            rotZ+=3;
            break;
        case 'o':
            zoom+=0.1;
            break;
        case 'p':
            zoom-=0.1;
            break;
        case 'r':
            rotXZ = 0, rotXY = 0, rotYZ = 0;
            rotX = 0, rotY = 0, rotZ = 0;
            viewX = 0, viewY = 0, viewZ = 0;
            posX = 0, posY = 0, posZ = 0;
            upX = 0, upY = 0, upZ = 1;
            refX = 0, refY = 0, refZ = 0;
            zoom = 0;
            break;
     }

    glutPostRedisplay();
}

static void resize (int w, int h)
{
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
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
