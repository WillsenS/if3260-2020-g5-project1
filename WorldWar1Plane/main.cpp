/*
 * World War 1 Plane
 * using polygon
 */

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#define nVertex 135
#define nColor 13

using namespace std;

static float rotCamXY = 0.0;//kamera mengitari model
static float rotCamPro = 0.0; //memutar bidang proyeksi kamera
static float zoom = 0.0; //radius

static float rotX = 0.0;
static float rotY = 0.0;
static float rotZ = 0.0;

static float refX = 0.0;
static float refY = 0.0;
static float refZ = 0.0;

static float posX = 1.0;
static float posY = 0.0;
static float posZ = 0.0; //radius;

static float viewX = 0.0;
static float viewY = 0.0;
static float viewZ = 0.0;

static float upX = 0.0;
static float upY = 1.0;
static float upZ = 0.0;

static float vertexMatrix[nVertex][3];
static float colorMatrix[nColor][3];

static void init(void)
{
    glClearColor(0,0,0,0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

static void getColorBuffer()
{
    FILE *f;

    // For windows uses full path
    f = fopen("C:/Users/user/Documents/ITB/IF/Semester 6/Grafkom/Tubes 1/if3260-2020-g5-project1/WorldWar1Plane/color.txt", "r");

    // For Linux
    // f = fopen("color.txt", "r");
    int i,j;
    float temp;

    for(i=0; i<nColor; i++)
    {
        for(j=0; j<3; j++)
        {
            fscanf(f, "%f", &temp);
            if(temp == -9999)
                break;

            colorMatrix[i][j] = temp;
        }
    }

    fclose(f);
}

static void getVertexBuffer()
{
    FILE *f;

    // For windows uses full path
    f = fopen("C:/Users/user/Documents/ITB/IF/Semester 6/Grafkom/Tubes 1/if3260-2020-g5-project1/WorldWar1Plane/vertex.txt", "r");

    // For Linux
    // f = fopen("color.txt", "r");

    int i,j;
    float temp;

    for(i=0; i<nVertex; i++)
    {
        for(j=0; j<3; j++)
        {
            fscanf(f, "%f", &temp);
            if(temp == -9999)
                break;

            vertexMatrix[i][j] = temp;
        }
    }

    fclose(f);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3ub(255, 255, 255);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -4.0f + zoom);

    glRotatef(0.0+rotX, 1.0, 0.0, 0.0);
    glRotatef(0.0+rotY, 0.0, 1.0, 0.0);
    glRotatef(0.0+rotZ, 0.0, 0.0, 1.0);

    gluLookAt(posX, posY, posZ,
              viewX, viewY, viewZ,
              upX + refX, upY + refY, upZ + refZ);

    glScalef(1.0, 1.0, 1.0);

    //body pesawat di koordinat 0 Z
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[0][0], colorMatrix[0][1], colorMatrix[0][2]);
    glVertex3f(vertexMatrix[0][0], vertexMatrix[0][1], vertexMatrix[0][2]);
    glVertex3f(vertexMatrix[1][0], vertexMatrix[1][1], vertexMatrix[1][2]);
    glVertex3f(vertexMatrix[2][0], vertexMatrix[2][1], vertexMatrix[2][2]);
    glVertex3f(vertexMatrix[3][0], vertexMatrix[3][1], vertexMatrix[3][2]);
    glVertex3f(vertexMatrix[4][0], vertexMatrix[4][1], vertexMatrix[4][2]);
    glVertex3f(vertexMatrix[5][0], vertexMatrix[5][1], vertexMatrix[5][2]);
    glEnd();

    //body pesawat di koordinat -0.2 Z
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[1][0], colorMatrix[1][1], colorMatrix[1][2]);
    glVertex3f(vertexMatrix[6][0], vertexMatrix[6][1], vertexMatrix[6][2]);
    glVertex3f(vertexMatrix[7][0], vertexMatrix[7][1], vertexMatrix[7][2]);
    glVertex3f(vertexMatrix[8][0], vertexMatrix[8][1], vertexMatrix[8][2]);
    glVertex3f(vertexMatrix[9][0], vertexMatrix[9][1], vertexMatrix[9][2]);
    glVertex3f(vertexMatrix[10][0], vertexMatrix[10][1], vertexMatrix[10][2]);
    glVertex3f(vertexMatrix[11][0], vertexMatrix[11][1], vertexMatrix[11][2]);
    glEnd();

    //body pesawat penampang baling2
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[2][0], colorMatrix[2][1], colorMatrix[2][2]);
    glVertex3f(vertexMatrix[0][0], vertexMatrix[0][1], vertexMatrix[0][2]);
    glVertex3f(vertexMatrix[6][0], vertexMatrix[6][1], vertexMatrix[6][2]);
    glVertex3f(vertexMatrix[7][0], vertexMatrix[7][1], vertexMatrix[7][2]);
    glVertex3f(vertexMatrix[1][0], vertexMatrix[1][1], vertexMatrix[1][2]);
    glEnd();

    //body pesawat bagian atas
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[3][0], colorMatrix[3][1], colorMatrix[3][2]);
    glVertex3f(vertexMatrix[0][0], vertexMatrix[0][1], vertexMatrix[0][2]);
    glVertex3f(vertexMatrix[6][0], vertexMatrix[6][1], vertexMatrix[6][2]);
    glVertex3f(vertexMatrix[11][0], vertexMatrix[11][1], vertexMatrix[11][2]);
    glVertex3f(vertexMatrix[5][0], vertexMatrix[5][1], vertexMatrix[5][2]);
    glEnd();

    //body pesawat bagian atas belakang
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[4][0], colorMatrix[4][1], colorMatrix[4][2]);
    glVertex3f(vertexMatrix[11][0], vertexMatrix[11][1], vertexMatrix[11][2]);
    glVertex3f(vertexMatrix[5][0], vertexMatrix[5][1], vertexMatrix[5][2]);
    glVertex3f(vertexMatrix[10][0], vertexMatrix[10][1], vertexMatrix[10][2]);
    glVertex3f(vertexMatrix[4][0], vertexMatrix[4][1], vertexMatrix[4][2]);
    glEnd();

    //body pesawat bagian bawah
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[5][0], colorMatrix[5][1], colorMatrix[5][2]);
    glVertex3f(vertexMatrix[10][0], vertexMatrix[10][1], vertexMatrix[10][2]);;
    glVertex3f(vertexMatrix[4][0], vertexMatrix[4][1], vertexMatrix[4][2]);
    glVertex3f(vertexMatrix[3][0], vertexMatrix[3][1], vertexMatrix[3][2]);
    glVertex3f(vertexMatrix[2][0], vertexMatrix[2][1], vertexMatrix[2][2]);
    glVertex3f(vertexMatrix[1][0], vertexMatrix[1][1], vertexMatrix[1][2]);
    glVertex3f(vertexMatrix[7][0], vertexMatrix[7][1], vertexMatrix[7][2]);
    glVertex3f(vertexMatrix[8][0], vertexMatrix[8][1], vertexMatrix[8][2]);
    glVertex3f(vertexMatrix[9][0], vertexMatrix[9][1], vertexMatrix[9][2]);
    glEnd();

    /*sayap bawah*/
    //sayap bawah kanan
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[6][0], colorMatrix[6][1], colorMatrix[6][2]);
    glVertex3f(vertexMatrix[12][0], vertexMatrix[12][1], vertexMatrix[12][2]);
    glVertex3f(vertexMatrix[13][0], vertexMatrix[13][1], vertexMatrix[13][2]);
    glVertex3f(vertexMatrix[14][0], vertexMatrix[14][1], vertexMatrix[14][2]);
    glVertex3f(vertexMatrix[15][0], vertexMatrix[15][1], vertexMatrix[15][2]);
    glEnd();

    //sayap bawah kiri
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[6][0], colorMatrix[6][1], colorMatrix[6][2]);
    glVertex3f(vertexMatrix[16][0], vertexMatrix[16][1], vertexMatrix[16][2]);
    glVertex3f(vertexMatrix[17][0], vertexMatrix[17][1], vertexMatrix[17][2]);
    glVertex3f(vertexMatrix[18][0], vertexMatrix[18][1], vertexMatrix[18][2]);
    glVertex3f(vertexMatrix[19][0], vertexMatrix[19][1], vertexMatrix[19][2]);
    glEnd();

    //sayap bawah kanan (buat ketebalan)
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[6][0], colorMatrix[6][1], colorMatrix[6][2]);
    glVertex3f(vertexMatrix[20][0], vertexMatrix[20][1], vertexMatrix[20][2]);
    glVertex3f(vertexMatrix[21][0], vertexMatrix[21][1], vertexMatrix[21][2]);
    glVertex3f(vertexMatrix[22][0], vertexMatrix[22][1], vertexMatrix[22][2]);
    glVertex3f(vertexMatrix[23][0], vertexMatrix[23][1], vertexMatrix[23][2]);
    glEnd();

    // sayap bawah kiri (buat ketebelan)
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[6][0], colorMatrix[6][1], colorMatrix[6][2]);
    glVertex3f(vertexMatrix[24][0], vertexMatrix[24][1], vertexMatrix[24][2]);
    glVertex3f(vertexMatrix[25][0], vertexMatrix[25][1], vertexMatrix[25][2]);
    glVertex3f(vertexMatrix[26][0], vertexMatrix[26][1], vertexMatrix[26][2]);
    glVertex3f(vertexMatrix[27][0], vertexMatrix[27][1], vertexMatrix[27][2]);
    glEnd();

    /*sayap atas*/
    // sayap atas kanan
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[6][0], colorMatrix[6][1], colorMatrix[6][2]);
    glVertex3f(vertexMatrix[28][0], vertexMatrix[28][1], vertexMatrix[28][2]);
    glVertex3f(vertexMatrix[29][0], vertexMatrix[29][1], vertexMatrix[29][2]);
    glVertex3f(vertexMatrix[30][0], vertexMatrix[30][1], vertexMatrix[30][2]);
    glVertex3f(vertexMatrix[31][0], vertexMatrix[31][1], vertexMatrix[31][2]);
    glEnd();

    //sayap kiri atas
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[6][0], colorMatrix[6][1], colorMatrix[6][2]);
    glVertex3f(vertexMatrix[32][0], vertexMatrix[32][1], vertexMatrix[32][2]);
    glVertex3f(vertexMatrix[33][0], vertexMatrix[33][1], vertexMatrix[33][2]);
    glVertex3f(vertexMatrix[34][0], vertexMatrix[34][1], vertexMatrix[34][2]);
    glVertex3f(vertexMatrix[35][0], vertexMatrix[35][1], vertexMatrix[35][2]);
    glEnd();

    //sayap atas kanan (buat ketebalan)
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[6][0], colorMatrix[6][1], colorMatrix[6][2]);
    glVertex3f(vertexMatrix[36][0], vertexMatrix[36][1], vertexMatrix[36][2]);
    glVertex3f(vertexMatrix[37][0], vertexMatrix[37][1], vertexMatrix[37][2]);
    glVertex3f(vertexMatrix[38][0], vertexMatrix[38][1], vertexMatrix[38][2]);
    glVertex3f(vertexMatrix[39][0], vertexMatrix[39][1], vertexMatrix[39][2]);
    glEnd();

    //sayap kiri atas (buat ketebalan)
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[6][0], colorMatrix[6][1], colorMatrix[6][2]);
    glVertex3f(vertexMatrix[40][0], vertexMatrix[40][1], vertexMatrix[40][2]);
    glVertex3f(vertexMatrix[41][0], vertexMatrix[41][1], vertexMatrix[41][2]);
    glVertex3f(vertexMatrix[42][0], vertexMatrix[42][1], vertexMatrix[42][2]);
    glVertex3f(vertexMatrix[43][0], vertexMatrix[43][1], vertexMatrix[43][2]);
    glEnd();

    // penampang penyambung atas untuk sayap
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[6][0], colorMatrix[6][1], colorMatrix[6][2]);
    glVertex3f(vertexMatrix[32][0], vertexMatrix[32][1], vertexMatrix[32][2]);
    glVertex3f(vertexMatrix[33][0], vertexMatrix[33][1], vertexMatrix[33][2]);
    glVertex3f(vertexMatrix[29][0], vertexMatrix[29][1], vertexMatrix[29][2]);
    glVertex3f(vertexMatrix[28][0], vertexMatrix[28][1], vertexMatrix[28][2]);
    glEnd();

    //Penyangga sayap
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[44][0], vertexMatrix[44][1], vertexMatrix[44][2]);
    glVertex3f(vertexMatrix[45][0], vertexMatrix[45][1], vertexMatrix[45][2]);
    glVertex3f(vertexMatrix[46][0], vertexMatrix[46][1], vertexMatrix[46][2]);
    glVertex3f(vertexMatrix[47][0], vertexMatrix[47][1], vertexMatrix[47][2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[48][0], vertexMatrix[48][1], vertexMatrix[48][2]);
    glVertex3f(vertexMatrix[49][0], vertexMatrix[49][1], vertexMatrix[49][2]);
    glVertex3f(vertexMatrix[50][0], vertexMatrix[50][1], vertexMatrix[50][2]);
    glVertex3f(vertexMatrix[51][0], vertexMatrix[51][1], vertexMatrix[51][2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[52][0], vertexMatrix[52][1], vertexMatrix[52][2]);
    glVertex3f(vertexMatrix[53][0], vertexMatrix[53][1], vertexMatrix[53][2]);
    glVertex3f(vertexMatrix[54][0], vertexMatrix[54][1], vertexMatrix[54][2]);
    glVertex3f(vertexMatrix[55][0], vertexMatrix[55][1], vertexMatrix[55][2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[56][0], vertexMatrix[56][1], vertexMatrix[56][2]);
    glVertex3f(vertexMatrix[57][0], vertexMatrix[57][1], vertexMatrix[57][2]);
    glVertex3f(vertexMatrix[58][0], vertexMatrix[58][1], vertexMatrix[58][2]);
    glVertex3f(vertexMatrix[59][0], vertexMatrix[59][1], vertexMatrix[59][2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[60][0], vertexMatrix[60][1], vertexMatrix[60][2]);
    glVertex3f(vertexMatrix[61][0], vertexMatrix[61][1], vertexMatrix[61][2]);
    glVertex3f(vertexMatrix[62][0], vertexMatrix[62][1], vertexMatrix[62][2]);
    glVertex3f(vertexMatrix[63][0], vertexMatrix[63][1], vertexMatrix[63][2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[64][0], vertexMatrix[64][1], vertexMatrix[64][2]);
    glVertex3f(vertexMatrix[65][0], vertexMatrix[65][1], vertexMatrix[65][2]);
    glVertex3f(vertexMatrix[66][0], vertexMatrix[66][1], vertexMatrix[66][2]);
    glVertex3f(vertexMatrix[67][0], vertexMatrix[67][1], vertexMatrix[67][2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[68][0], vertexMatrix[68][1], vertexMatrix[68][2]);
    glVertex3f(vertexMatrix[69][0], vertexMatrix[69][1], vertexMatrix[69][2]);
    glVertex3f(vertexMatrix[70][0], vertexMatrix[70][1], vertexMatrix[70][2]);
    glVertex3f(vertexMatrix[71][0], vertexMatrix[71][1], vertexMatrix[71][2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[72][0], vertexMatrix[72][1], vertexMatrix[72][2]);
    glVertex3f(vertexMatrix[73][0], vertexMatrix[73][1], vertexMatrix[73][2]);
    glVertex3f(vertexMatrix[74][0], vertexMatrix[74][1], vertexMatrix[74][2]);
    glVertex3f(vertexMatrix[75][0], vertexMatrix[75][1], vertexMatrix[75][2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[76][0], vertexMatrix[76][1], vertexMatrix[76][2]);
    glVertex3f(vertexMatrix[77][0], vertexMatrix[77][1], vertexMatrix[77][2]);
    glVertex3f(vertexMatrix[78][0], vertexMatrix[78][1], vertexMatrix[78][2]);
    glVertex3f(vertexMatrix[79][0], vertexMatrix[79][1], vertexMatrix[79][2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[7][0], colorMatrix[7][1], colorMatrix[7][2]);
    glVertex3f(vertexMatrix[80][0], vertexMatrix[80][1], vertexMatrix[80][2]);
    glVertex3f(vertexMatrix[81][0], vertexMatrix[81][1], vertexMatrix[81][2]);
    glVertex3f(vertexMatrix[82][0], vertexMatrix[82][1], vertexMatrix[82][2]);
    glVertex3f(vertexMatrix[83][0], vertexMatrix[83][1], vertexMatrix[83][2]);
    glEnd();

    /*baling2*/
    //baling" vertikal
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[8][0], colorMatrix[8][1], colorMatrix[8][2]);
    for (int i=0; i < 50; i++){
        glVertex3f(1+i*vertexMatrix[84][0], vertexMatrix[84][1], vertexMatrix[84][2]);
        glVertex3f(1+i*vertexMatrix[85][0], vertexMatrix[85][1], vertexMatrix[85][2]);
        glVertex3f(1+i*vertexMatrix[86][0], vertexMatrix[86][1], vertexMatrix[86][2]);
        glVertex3f(1+i*vertexMatrix[87][0], vertexMatrix[87][1], vertexMatrix[87][2]);
    }
    glEnd();

    //baling" horizontal
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[8][0], colorMatrix[8][1], colorMatrix[8][2]);
    for (int i=0; i < 50; i++){
        glVertex3f(1+i*vertexMatrix[88][0], vertexMatrix[88][1], vertexMatrix[88][2]);
        glVertex3f(1+i*vertexMatrix[89][0], vertexMatrix[89][1], vertexMatrix[89][2]);
        glVertex3f(1+i*vertexMatrix[90][0], vertexMatrix[90][1], vertexMatrix[90][2]);
        glVertex3f(1+i*vertexMatrix[91][0], vertexMatrix[91][1], vertexMatrix[91][2]);
    }
    glEnd();

    //ekor
    //penampang kanan ekor
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[9][0], colorMatrix[9][1], colorMatrix[9][2]);
    glVertex3f(vertexMatrix[92][0], vertexMatrix[92][1], vertexMatrix[92][2]);
    glVertex3f(vertexMatrix[93][0], vertexMatrix[93][1], vertexMatrix[93][2]);
    glVertex3f(vertexMatrix[94][0], vertexMatrix[94][1], vertexMatrix[94][2]);
    glVertex3f(vertexMatrix[95][0], vertexMatrix[95][1], vertexMatrix[95][2]);
    glVertex3f(vertexMatrix[96][0], vertexMatrix[96][1], vertexMatrix[96][2]);
    glEnd();

    // penampang kiri ekor
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[9][0], colorMatrix[9][1], colorMatrix[9][2]);
    glVertex3f(vertexMatrix[97][0], vertexMatrix[97][1], vertexMatrix[97][2]);
    glVertex3f(vertexMatrix[98][0], vertexMatrix[98][1], vertexMatrix[98][2]);
    glVertex3f(vertexMatrix[99][0], vertexMatrix[99][1], vertexMatrix[99][2]);
    glVertex3f(vertexMatrix[100][0], vertexMatrix[100][1], vertexMatrix[100][2]);
    glVertex3f(vertexMatrix[101][0], vertexMatrix[101][1], vertexMatrix[101][2]);
    glEnd();

    // penampang belakang ekor
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[9][0], colorMatrix[9][1], colorMatrix[9][2]);
    glVertex3f(vertexMatrix[102][0], vertexMatrix[102][1], vertexMatrix[102][2]);
    glVertex3f(vertexMatrix[103][0], vertexMatrix[103][1], vertexMatrix[103][2]);
    glVertex3f(vertexMatrix[104][0], vertexMatrix[104][1], vertexMatrix[104][2]);
    glEnd();

    //sayap belakang
    //sayap kanan
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[10][0], colorMatrix[10][1], colorMatrix[10][2]);
    glVertex3f(vertexMatrix[105][0], vertexMatrix[105][1], vertexMatrix[105][2]);
    glVertex3f(vertexMatrix[106][0], vertexMatrix[106][1], vertexMatrix[106][2]);
    glVertex3f(vertexMatrix[107][0], vertexMatrix[107][1], vertexMatrix[107][2]);
    glVertex3f(vertexMatrix[108][0], vertexMatrix[108][1], vertexMatrix[108][2]);
    glEnd();

    //sayap kiri
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[10][0], colorMatrix[10][1], colorMatrix[10][2]);
    glVertex3f(vertexMatrix[109][0], vertexMatrix[109][1], vertexMatrix[109][2]);
    glVertex3f(vertexMatrix[110][0], vertexMatrix[110][1], vertexMatrix[110][2]);
    glVertex3f(vertexMatrix[111][0], vertexMatrix[111][1], vertexMatrix[111][2]);
    glVertex3f(vertexMatrix[112][0], vertexMatrix[112][1], vertexMatrix[112][2]);
    glEnd();

    //roda
    //penyangga roda
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[11][0], colorMatrix[11][1], colorMatrix[11][2]);
    glVertex3f(vertexMatrix[113][0], vertexMatrix[113][1], vertexMatrix[113][2]);
    glVertex3f(vertexMatrix[114][0], vertexMatrix[114][1], vertexMatrix[114][2]);
    glVertex3f(vertexMatrix[115][0], vertexMatrix[115][1], vertexMatrix[115][2]);
    glVertex3f(vertexMatrix[116][0], vertexMatrix[116][1], vertexMatrix[116][2]);
    glEnd();

    //penyangga roda
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[11][0], colorMatrix[11][1], colorMatrix[11][2]);
    glVertex3f(vertexMatrix[117][0], vertexMatrix[117][1], vertexMatrix[117][2]);
    glVertex3f(vertexMatrix[118][0], vertexMatrix[118][1], vertexMatrix[118][2]);
    glVertex3f(vertexMatrix[119][0], vertexMatrix[119][1], vertexMatrix[119][2]);
    glVertex3f(vertexMatrix[120][0], vertexMatrix[120][1], vertexMatrix[120][2]);
    glEnd();

    //penyangga roda
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[11][0], colorMatrix[11][1], colorMatrix[11][2]);
    glVertex3f(vertexMatrix[121][0], vertexMatrix[121][1], vertexMatrix[121][2]);
    glVertex3f(vertexMatrix[122][0], vertexMatrix[122][1], vertexMatrix[122][2]);
    glVertex3f(vertexMatrix[123][0], vertexMatrix[123][1], vertexMatrix[123][2]);
    glVertex3f(vertexMatrix[124][0], vertexMatrix[124][1], vertexMatrix[124][2]);
    glEnd();

    //penyangga roda
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[11][0], colorMatrix[11][1], colorMatrix[11][2]);
    glVertex3f(vertexMatrix[125][0], vertexMatrix[125][1], vertexMatrix[125][2]);
    glVertex3f(vertexMatrix[126][0], vertexMatrix[126][1], vertexMatrix[126][2]);
    glVertex3f(vertexMatrix[127][0], vertexMatrix[127][1], vertexMatrix[127][2]);
    glVertex3f(vertexMatrix[128][0], vertexMatrix[128][1], vertexMatrix[128][2]);
    glEnd();


    //rodanya
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[12][0], colorMatrix[12][1], colorMatrix[12][2]);
    for (int j = 0; j < 50; j++){
        for (int i=0; i < 359; i++)
       {
          float degInRad = i*3.14159/180;
          glVertex3f((cos(degInRad)*0.09) + vertexMatrix[129][0],(sin(degInRad)*0.09) + vertexMatrix[129][1],vertexMatrix[129][2]+j*0.002);
       }
    }
    glEnd();

    //rodanya
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[12][0], colorMatrix[12][1], colorMatrix[12][2]);
    for (int j = 0; j < 50; j++){
        for (int i=0; i < 359; i++)
       {
          float degInRad = i*3.14159/180;
          glVertex3f((cos(degInRad)*0.09) + vertexMatrix[130][0],(sin(degInRad)*0.09) + vertexMatrix[130][1],vertexMatrix[130][2]-j*0.002);
       }
    }
    glEnd();

    //sambungan buat roda
    glBegin(GL_POLYGON);
    glColor3f(colorMatrix[11][0], colorMatrix[11][1], colorMatrix[11][2]);
    glVertex3f(vertexMatrix[131][0], vertexMatrix[131][1], vertexMatrix[131][2]);
    glVertex3f(vertexMatrix[132][0], vertexMatrix[132][1], vertexMatrix[132][2]);
    glVertex3f(vertexMatrix[133][0], vertexMatrix[133][1], vertexMatrix[133][2]);
    glVertex3f(vertexMatrix[134][0], vertexMatrix[134][1], vertexMatrix[134][2]);
    glEnd();


    // Benda lain untuk titik acuan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 3.0, 3.0, 3.0);
    glVertex3f( 3.0, 3.0, 2.0);
    glVertex3f( 2.0, 3.0, 2.0);
    glVertex3f( 2.0, 3.0, 3.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 2.0, 2.0, 3.0);
    glVertex3f( 2.0, 2.0, 2.0);
    glVertex3f( 3.0, 2.0, 2.0);
    glVertex3f( 3.0, 2.0, 3.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( 2.0, 3.0, 3.0);
    glVertex3f( 2.0, 2.0, 3.0);
    glVertex3f( 3.0, 2.0, 3.0);
    glVertex3f( 3.0, 3.0, 3.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( 2.0, 3.0, 2.0);
    glVertex3f( 3.0, 3.0, 2.0);
    glVertex3f( 3.0, 2.0, 2.0);
    glVertex3f( 2.0, 2.0, 2.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 2.0, 3.0, 3.0);
    glVertex3f( 2.0, 3.0, 2.0);
    glVertex3f( 2.0, 2.0, 2.0);
    glVertex3f( 2.0, 2.0, 3.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 3.0, 3.0, 3.0);
    glVertex3f( 3.0, 2.0, 3.0);
    glVertex3f( 3.0, 2.0, 2.0);
    glVertex3f( 3.0, 3.0, 2.0);

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
            rotCamPro+=3;
            upX = cos(M_PI * rotCamPro / 180);
            upZ = sin(M_PI * rotCamPro / 180);
            break;
        case 'a':
            break;
        case 'd':
            break;
        case 'w':
            rotCamXY+=3;
            posX = cos(M_PI * rotCamXY / 180);
            posZ = sin(M_PI * rotCamXY / 180);
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
            rotCamXY = 0, rotCamPro = 0;
            rotX = 0, rotY = 0, rotZ = 0;
            viewX = 0, viewY = 0, viewZ = 0;
            posX = 1, posY = 0, posZ = 0;
            upX = 0, upY = 1, upZ = 0;
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
    // Inisialisasi dari file eksternal
    getColorBuffer();
    getVertexBuffer();


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
