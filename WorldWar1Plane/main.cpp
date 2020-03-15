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

    glScalef(1.0 + zoom, 1.0 + zoom, 1.0 + zoom)
    //body pesawat di koordinat 0 Z
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 1.0, 0.2, 0);
    glVertex3f( 1.0, -0.2, 0);
    glVertex3f( 0.9, -0.25, 0);
    glVertex3f( 0.6, -0.3, 0);
    glVertex3f( -0.8, -0.35, 0);
    glVertex3f( -0.9, -0.25, 0);
    glEnd();
    
    //body pesawat di koordinat -0.2 Z
    glBegin(GL_POLYGON);
    glColor3f(0,1,1);
    glVertex3f( 1.0, 0.2, -0.2);
    glVertex3f( 1.0, -0.2, -0.2);
    glVertex3f( 0.9, -0.25, -0.2);
    glVertex3f( 0.6, -0.3, -0.2);
    glVertex3f( -0.8, -0.35, -0.2);
    glVertex3f( -0.9, -0.25, -0.2);
    glEnd();
    //body pesawat penampang baling2
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex3f( 1.0, 0.2, 0);
    glVertex3f( 1.0, 0.2, -0.2);
    glVertex3f( 1.0, -0.2, -0.2);
    glVertex3f( 1.0, -0.2, 0);
    glEnd();
//body pesawat bagian atas
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex3f( 1.0, 0.2, 0);
    glVertex3f( 1.0, 0.2, -0.2);
    glVertex3f( -0.9, -0.25, -0.2);
    glVertex3f( -0.9, -0.25, 0);
    glEnd();
//body pesawat bagian atas belakang
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex3f( -0.9, -0.25, -0.2);
    glVertex3f( -0.9, -0.25, 0);
    glVertex3f( -0.8, -0.35, -0.2);
    glVertex3f( -0.8, -0.35, 0);
    glEnd();
//body pesawat bagian bawah
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex3f( -0.8, -0.35, -0.2);
    glVertex3f( -0.8, -0.35, 0);
    glVertex3f( 0.6, -0.3, 0);
    glVertex3f( 0.9, -0.25, 0);
    glVertex3f( 1, -0.2, 0);
    glVertex3f( 1, -0.2, -0.2);
    glVertex3f( 0.9, -0.25, -0.2);
    glVertex3f( 0.6, -0.3, -0.2);

    glEnd();

    /*sayap bawah*/
//sayap bawah kanan
    glBegin(GL_POLYGON);
    glColor3f(1,0.0,0);
    glVertex3f( 0.6, -0.3, 0);
    glVertex3f( 0.3, -0.31, 0);
    glVertex3f( 0.3, -0.31, 1);
    glVertex3f( 0.6, -0.3, 1);
    glEnd();
//sayap bawah kanan (buat ketebalan)
    glBegin(GL_POLYGON);
    glColor3f(1,0.0,0);
    glVertex3f( 0.6, -0.27, 0);
    glVertex3f( 0.3, -0.29, 0);
    glVertex3f( 0.3, -0.31, 1);
    glVertex3f( 0.6, -0.3, 1);

    glEnd();
//sayap bawah kiri
    glBegin(GL_POLYGON);
    glColor3f(1,0.0,0);
    glVertex3f( 0.6, -0.3,-0.2);
    glVertex3f( 0.3, -0.31, -0.2);
    glVertex3f( 0.3, -0.31, -1.2);
    glVertex3f( 0.6, -0.3, -1.2);
    glEnd();
// sayap bawah kiri (buat ketebelan)
    glBegin(GL_POLYGON);
    glColor3f(1,0.0,0);
    glVertex3f( 0.6, -0.27, -0.2);
    glVertex3f( 0.3, -0.29, -0.2);
    glVertex3f( 0.3, -0.31, -1.2);
    glVertex3f( 0.6, -0.3, -1.2);

    glEnd();

    /*sayap atas*/
// sayap atas kanan
    glBegin(GL_POLYGON);
    glColor3f(1,0.0,0);
    glVertex3f( 0.6, 0.3, 0);
    glVertex3f( 0.3, 0.29, 0);
    glVertex3f( 0.3, 0.29, 1);
    glVertex3f( 0.6, 0.3, 1);
    glEnd();
//sayap atas kanan (buat ketebalan)
    glBegin(GL_POLYGON);
    glColor3f(1,0.0,0);
    glVertex3f( 0.6, 0.33, 0);
    glVertex3f( 0.3, 0.29, 0);
    glVertex3f( 0.3, 0.29, 1);
    glVertex3f( 0.6, 0.30, 1);

    glEnd();
//sayap kiri atas
    glBegin(GL_POLYGON);
    glColor3f(1,0.0,0);
    glVertex3f( 0.6, 0.3,-0.2);
    glVertex3f( 0.3, 0.29, -0.2);
    glVertex3f( 0.3, 0.29, -1.2);
    glVertex3f( 0.6, 0.3, -1.2);
    glEnd();
//sayap kiri atas (buat ketebalan)
    glBegin(GL_POLYGON);
    glColor3f(1,0.0,0);
    glVertex3f( 0.6, 0.33, -0.2);
    glVertex3f( 0.3, 0.29, -0.2);
    glVertex3f( 0.3, 0.31, -1.2);
    glVertex3f( 0.6, 0.3, -1.2);

    glEnd();
// penampang penyambung atas untuk sayap
    glBegin(GL_POLYGON);
    glColor3f(1,0.0,0);
    glVertex3f( 0.6, 0.33, -0.2);
    glVertex3f( 0.3, 0.29, -0.2);
    glVertex3f( 0.3, 0.29, 0);
    glVertex3f( 0.6, 0.33, 0);

    glEnd();

    /*baling2*/
    //baling" vertikal
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6,1);
    for (int i=0; i < 50; i++){
        glVertex3f(1+i*0.001, 0.35, -0.075);
        glVertex3f(1+i*0.001, 0.35, -0.125);
        glVertex3f(1+i*0.001, -0.35, -0.075);
        glVertex3f(1+i*0.001, -0.35, -0.125);
    }
    glEnd();
//baling" horizontal
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6,1);
    for (int i=0; i < 50; i++){
        glVertex3f(1+i*0.001, 0.025, 0.25);
        glVertex3f(1+i*0.001, 0.025, -0.45);
        glVertex3f(1+i*0.001, -0.025, -0.45);
        glVertex3f(1+i*0.001, -0.025, 0.25);
    }

    glEnd();
    //ekor
    //penampang kanan ekor
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6,1);
    glVertex3f(-0.6, -0.1789, 0);
    glVertex3f(-0.8, 0.15, -0.1);
    glVertex3f(-1.1, 0.15, -0.1);
    glVertex3f(-1.1, -0.35, 0);
    glVertex3f(-0.6, -0.35, 0);

    glEnd();
// penampang kiri ekor
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6,1);
    glVertex3f(-0.6, -0.1789, -0.2);
    glVertex3f(-0.8, 0.15, -0.1);
    glVertex3f(-1.1, 0.15, -0.1);
    glVertex3f(-1.1, -0.35, -0.2);
    glVertex3f(-0.6, -0.35, -0.2);

    glEnd();
// penampang belakang ekor
    glBegin(GL_POLYGON);
    glVertex3f(-1.1, -0.35, -0.2);
    glVertex3f(-1.1, -0.35, 0);
    glVertex3f(-1.1, 0.15, -0.1);
    glEnd();

    //sayap belakang
    //sayap kanan
    glBegin(GL_POLYGON);
    glColor3f(1,0.3,0.1);
    glVertex3f(-1.1, -0.35, 0);
    glVertex3f(-0.6, -0.1789, 0);
    glVertex3f(-0.9, -0.25, 0.3);
    glVertex3f(-1.1, -0.35, 0.4);
    glEnd();
//sayap kiri
    glBegin(GL_POLYGON);
    glColor3f(1,0.3,0.1);
    glVertex3f(-1.1, -0.35, -0.2);
    glVertex3f(-0.6, -0.1789, -0.2);
    glVertex3f(-0.9, -0.25, -0.5);
    glVertex3f(-1.1, -0.35, -0.6);
    glEnd();

    //Penyangga sayap

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.35,-0.3,0.6);
    glVertex3f(0.375,-0.3,0.6);
    glVertex3f(0.375,0.29,0.6);
    glVertex3f(0.35,0.29,0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.55,-0.3,0.6);
    glVertex3f(0.525,-0.3,0.6);
    glVertex3f(0.525,0.29,0.6);
    glVertex3f(0.55,0.29,0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.55,-0.3,0.6);
    glVertex3f(0.525,-0.3,0.6);
    glVertex3f(0.375,0.29,0.6);
    glVertex3f(0.35,0.29,0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.35,-0.3,-0.8);
    glVertex3f(0.375,-0.3,-0.8);
    glVertex3f(0.375,0.29,-0.8);
    glVertex3f(0.35,0.29,-0.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.55,-0.3,-0.8);
    glVertex3f(0.525,-0.3,-0.8);
    glVertex3f(0.525,0.29,-0.8);
    glVertex3f(0.55,0.29,-0.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.55,-0.3,-0.8);
    glVertex3f(0.525,-0.3,-0.8);
    glVertex3f(0.375,0.29,-0.8);
    glVertex3f(0.35,0.29,-0.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.3,-0.3,0);
    glVertex3f(0.325,-0.3,0);
    glVertex3f(0.325,0.29,0.3);
    glVertex3f(0.3,0.29,0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.6,-0.3,0);
    glVertex3f(0.575,-0.3,0);
    glVertex3f(0.575,0.29,0.3);
    glVertex3f(0.6,0.29,0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.3,-0.3,-0.2);
    glVertex3f(0.325,-0.3,-0.2);
    glVertex3f(0.325,0.29,-0.5);
    glVertex3f(0.3,0.29,-0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.6,-0.3,-0.2);
    glVertex3f(0.575,-0.3,-0.2);
    glVertex3f(0.575,0.29,-0.5);
    glVertex3f(0.6,0.29,-0.5);
    glEnd();

    //roda
    //penyangga roda
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.3,-0.3,0);
    glVertex3f(0.325,-0.3,0);
    glVertex3f(0.475,-0.5,0.2);
    glVertex3f(0.45,-0.5,0.2);
    glEnd();
//penyangga roda
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.6,-0.3,0);
    glVertex3f(0.575,-0.3,0);
    glVertex3f(0.475,-0.5,0.2);
    glVertex3f(0.45,-0.5,0.2);
    glEnd();
//penyangga roda
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.3,-0.3,-0.2);
    glVertex3f(0.325,-0.3,-0.2);
    glVertex3f(0.475,-0.5,-0.4);
    glVertex3f(0.45,-0.5,-0.4);
    glEnd();
//penyangga roda
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.6,-0.3,-0.2);
    glVertex3f(0.575,-0.3,-0.2);
    glVertex3f(0.475,-0.5,-0.4);
    glVertex3f(0.45,-0.5,-0.4);
    glEnd();
//rodanya
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.3);
    for (int j = 0; j < 50; j++){
        for (int i=0; i < 359; i++)
       {
          float degInRad = i*3.14159/180;
          glVertex3f((cos(degInRad)*0.09)+0.45,(sin(degInRad)*0.09)-0.5,0.2+j*0.002);
       }
    }

   glEnd();
//rodanya
   glBegin(GL_POLYGON);
   glColor3f(0.3,0.3,0.3);
    for (int j = 0; j < 50; j++){
        for (int i=0; i < 359; i++)
       {
          float degInRad = i*3.14159/180;
          glVertex3f((cos(degInRad)*0.09)+0.45,(sin(degInRad)*0.09)-0.5,-0.4-j*0.002);
       }
    }
   glEnd();
    //sambungan roda
   glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.475,-0.5,-0.4);
    glVertex3f(0.45,-0.5,-0.4);
    glVertex3f(0.475,-0.5,0.2);
    glVertex3f(0.45,-0.5,0.2);
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
