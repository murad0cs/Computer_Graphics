#include<cstdio>
#include <windows.h>
#include<math.h>
# define PI 3.14159265358979323846
#include <GL/gl.h>
#include <vector>
#include <cstdlib>
#include <GL/glut.h>
#include<MMSystem.h>
#include<iostream>
using namespace std;

void day();
void night();
void dayRain();
void nightDispaly(int x);
void dayDisplay(int x);
void dayRainDisplay(int x);
void nightRain();
void nightRainDispaly(int x);

GLfloat positionBird=0.0f;
GLfloat speedBird=0.01f;
void updateBird(int value)
{
    if(positionBird > 1.0)
        positionBird =-1.0f;
    positionBird += speedBird;
    glutPostRedisplay();
    glutTimerFunc(100, updateBird, 0);
}

GLfloat positionTrain=0.0f;
GLfloat speedTrain=0.025;
void updateTrain(int value)
{
    if(positionTrain > 2.1)
        positionTrain =-1.0f;
    positionTrain += speedTrain;
    glutPostRedisplay();
    glutTimerFunc(100, updateTrain, 0);
}


GLfloat positionRain= 0.0f;
GLfloat speedRain=- 0.01f;
void updateRain(int value)
{
    if(positionRain < -0.02f)
    {
        positionRain = 0.02f;
    }

    positionRain += speedRain;
    //glutPostRedisplay();
    glutTimerFunc(100, updateRain, 0);
}

GLfloat positionBoat=0.0f;
GLfloat speedBoat=- 0.01f;
void updateBoat(int value)
{
    if(positionBoat < -1.5f)
    {
        positionBoat = 1.0f;
    }

    positionBoat += speedBoat;
    //glutPostRedisplay();
    glutTimerFunc(100, updateBoat, 0);
}

GLfloat positionCloud1=0.0f;
GLfloat speedCloud1=0.003f;
void updateCloud1(int value)
{
    if(positionCloud1 < -1.5f)
    {
        positionCloud1 = 1.0f;
    }

    positionCloud1 -= speedCloud1;
    //glutPostRedisplay();
    glutTimerFunc(100, updateCloud1, 0);
}

GLfloat positionCloud2=0.0f;
GLfloat speedCloud2=0.005f;
void updateCloud2(int value)
{
    if(positionCloud2 < -1.5f)
    {
        positionCloud2 = 1.0f;
    }

    positionCloud2 -= speedCloud2;
    //glutPostRedisplay();
    glutTimerFunc(100, updateCloud2, 0);
}

GLfloat positionStandinfBoat=0.0f;
GLfloat speedStandingBoat=0.002f;
void updateStandingBoat(int value)
{
    if(positionStandinfBoat < -0.03)
    {
        positionStandinfBoat = 0.0f;
    }

    positionStandinfBoat -= speedStandingBoat;
    //glutPostRedisplay();
    glutTimerFunc(100, updateStandingBoat, 0);
}

void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 225, 255);

    glVertex2f(-1,0.2);
    glVertex2f(1,0.2);
    glVertex2f(1,1);
    glVertex2f(-1,1);

    glEnd();
}

void nightSky()
{
    glBegin(GL_QUADS);
    glColor3ub(2,11,38);

    glVertex2f(-1,0.2);
    glVertex2f(1,0.2);
    glVertex2f(1,1);
    glVertex2f(-1,1);

    glEnd();
}

void star()
{
    glPointSize( 2.5 );
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.8f,0.95f);
    glVertex2f(0.9f,0.9f);
    glVertex2f(0.95f,0.7f);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.7f,0.9f);
    glVertex2f(0.6f,0.8f);
    glVertex2f(0.5f,0.75f);
    glVertex2f(0.4f,0.9f);
    glVertex2f(0.3f,0.7f);
    glVertex2f(0.25f,0.9f);
    glVertex2f(0.25f,0.7f);
    glVertex2f(0.1f,0.9f);
    glVertex2f(0.15f,0.75f);
    glVertex2f(0.0f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.4f,0.8f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.9f,0.9f);
    glVertex2f(-0.95f,0.7f);
    glVertex2f(-0.8f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.5f,0.75f);
    glVertex2f(-0.4f,0.9f);
    glVertex2f(-0.3f,0.7f);
    glVertex2f(-0.25f,0.9f);
    glVertex2f(-0.25f,0.7f);
    glVertex2f(-0.15f,0.75f);
    glVertex2f(-0.1f,0.9f);
    glEnd();

}

void cloud1()
{
    /// for circle 1
    int i1;
    GLfloat x1=-0.1f;
    GLfloat y1=0.8f;
    GLfloat radius1 =0.05f;
    int triangleAmount1 = 20;
    GLfloat twicePi1 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 249, 245);
    glVertex2f(x1, y1);
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
            y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
        );
    }
    glEnd();

    /// for circle 2
    int i2;
    GLfloat x2=-0.05f;
    GLfloat y2=0.85f;
    GLfloat radius2 =0.05f;
    int triangleAmount2 = 20;
    GLfloat twicePi2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 249, 245);
    glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f(
            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
            y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
    glEnd();

    /// for circle 3
    int i3;
    GLfloat x3=0.0f;
    GLfloat y3=0.8f;
    GLfloat radius3 =0.05f;
    int triangleAmount3 = 20;
    GLfloat twicePi3 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 249, 245);
    glVertex2f(x3, y3);
    for(i3 = 0; i3 <= triangleAmount3; i3++)
    {
        glVertex2f(
            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
            y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
        );
    }
    glEnd();

    /// for circle 4
    int i4;
    GLfloat x4=-0.03f;
    GLfloat y4=0.77f;
    GLfloat radius4 =0.05f;
    int triangleAmount4 = 20;
    GLfloat twicePi4 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 249, 245);
    glVertex2f(x4, y4);
    for(i4 = 0; i4 <= triangleAmount4; i4++)
    {
        glVertex2f(
            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
            y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
        );
    }
    glEnd();
}

void cloud2()
{
    ///circle 1
    int i1;
    GLfloat x1=0.41f;
    GLfloat y1=0.88f;
    GLfloat radius1 =0.05f;
    int triangleAmount1 = 20;
    GLfloat twicePi1 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 249, 245);
    glVertex2f(x1, y1);
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
            y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
        );
    }
    glEnd();

    ///for circle 2
    int i2;
    GLfloat x2=0.39f;
    GLfloat y2=0.8f;
    GLfloat radius2 =0.05f;
    int triangleAmount2 = 20;
    GLfloat twicePi2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 249, 245);
    glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f(
            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
            y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
    glEnd();

    ///circle 3
    int i3;
    GLfloat x3=0.46f;
    GLfloat y3=0.85f;
    GLfloat radius3 =0.05f;
    int triangleAmount3 = 20;
    GLfloat twicePi3 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 249, 245);
    glVertex2f(x3, y3);
    for(i3 = 0; i3 <= triangleAmount3; i3++)
    {
        glVertex2f(
            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
            y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
        );
    }
    glEnd();

    ///for circle 4
    int i4;
    GLfloat x4=0.47f;
    GLfloat y4=0.78f;
    GLfloat radius4 =0.05f;
    int triangleAmount4 = 20;
    GLfloat twicePi4 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 249, 245);
    glVertex2f(x4, y4);
    for(i4 = 0; i4 <= triangleAmount4; i4++)
    {
        glVertex2f(
            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
            y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
        );
    }
    glEnd();
}

void sun()
{

    int i;
    GLfloat x=-0.4f;
    GLfloat y=.9f;
    GLfloat radius =0.07f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 222, 5);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void moon()
{
    int i;
    GLfloat x=-.5f;
    GLfloat y=.9f;
    GLfloat radius =.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(214,214,214);
    glVertex2f(x, y); //  for center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat xx=-.5f;
    GLfloat yx=.93f;
    GLfloat radiusx =.06f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(2,11,38);
    glVertex2f(xx, yx); // for center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            xx + (radiusx * cos(i *  twicePi / triangleAmount)),
            yx + (radiusx * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();



}

void hill()
{
    ///hill 1
    glBegin(GL_POLYGON);
    glColor3ub(32, 158, 80);

    glVertex2f(-0.55,0.2);
    glVertex2f(-0.57,0.3);
    glVertex2f(-0.67,0.4);
    glVertex2f(-0.77,0.45);
    glVertex2f(-0.87,0.4);
    glVertex2f(-0.97,0.3);
    glVertex2f(-1,0.2);

    glEnd();

    ///hill 2
    glBegin(GL_POLYGON);
    glColor3ub(32, 158, 80);

    glVertex2f(-0.05,0.2);
    glVertex2f(-0.07,0.3);
    glVertex2f(-0.17,0.4);
    glVertex2f(-0.27,0.45);
    glVertex2f(-0.37,0.4);
    glVertex2f(-0.47,0.3);
    glVertex2f(-0.5,0.2);

    glEnd();

    ///hill 3
    glBegin(GL_POLYGON);
    glColor3ub(32, 158, 80);

    glVertex2f(0.46,0.2);
    glVertex2f(0.43,0.3);
    glVertex2f(0.33,0.4);
    glVertex2f(0.23,0.45);
    glVertex2f(0.13,0.4);
    glVertex2f(0.03,0.3);
    glVertex2f(0,0.2);

    glEnd();

    ///hill 4
    glBegin(GL_POLYGON);
    glColor3ub(32, 158, 80);

    glVertex2f(0.97,0.2);
    glVertex2f(0.94,0.3);
    glVertex2f(0.84,0.4);
    glVertex2f(0.74,0.45);
    glVertex2f(0.64,0.4);
    glVertex2f(0.54,0.3);
    glVertex2f(0.51,0.2);

    glEnd();

    ///tree body
    glLineWidth(15);
    glBegin(GL_LINES);
    glColor3ub(122, 91, 38);

    ///body 1
    glVertex2f(-0.525,0.2);
    glVertex2f(-0.525,0.4);
    ///body 2
    glVertex2f(-0.025,0.2);
    glVertex2f(-0.025,0.4);
    ///body 3
    glVertex2f(0.485,0.2);
    glVertex2f(0.485,0.4);
    ///body 3
    glVertex2f(0.995,0.2);
    glVertex2f(0.995,0.4);
    glEnd();

    ///body 1 leaves
    int i1;
    GLfloat x1=-0.5f;
    GLfloat y1=0.4f;
    GLfloat radius1 =0.04f;
    int triangleAmount1 = 20;
    GLfloat twicePi1 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x1, y1);
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
            y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
        );
    }
    glEnd();

    int i2;
    GLfloat x2=-0.55f;
    GLfloat y2=0.4f;
    GLfloat radius2 =0.04f;
    int triangleAmount2 = 20;
    GLfloat twicePi2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f(
            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
            y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
    glEnd();

    int i3;
    GLfloat x3=-0.525f;
    GLfloat y3=0.45f;
    GLfloat radius3 =0.04f;
    int triangleAmount3 = 20;
    GLfloat twicePi3 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x3, y3);
    for(i3 = 0; i3 <= triangleAmount3; i3++)
    {
        glVertex2f(
            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
            y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
        );
    }
    glEnd();

    ///body 2 leaves
    int i4;
    GLfloat x4=0.0f;
    GLfloat y4=0.4f;
    GLfloat radius4 =0.04f;
    int triangleAmount4 = 20;
    GLfloat twicePi4 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x4, y4);
    for(i4 = 0; i4 <= triangleAmount4; i4++)
    {
        glVertex2f(
            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
            y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
        );
    }
    glEnd();

    int i5;
    GLfloat x5=-0.05f;
    GLfloat y5=0.4f;
    GLfloat radius5 =0.04f;
    int triangleAmount5 = 20;
    GLfloat twicePi5 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x5, y5);
    for(i5 = 0; i5 <= triangleAmount5; i5++)
    {
        glVertex2f(
            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
            y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
        );
    }
    glEnd();

    int i6;
    GLfloat x6=-0.025f;
    GLfloat y6=0.45f;
    GLfloat radius6 =0.04f;
    int triangleAmount6 = 20;
    GLfloat twicePi6 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x6, y6);
    for(i6 = 0; i6 <= triangleAmount6; i6++)
    {
        glVertex2f(
            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
            y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
        );
    }
    glEnd();

    ///body 3 leaves
    int i7;
    GLfloat x7=0.51f;
    GLfloat y7=0.4f;
    GLfloat radius7 =0.04f;
    int triangleAmount7 = 20;
    GLfloat twicePi7 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x7, y7);
    for(i7 = 0; i7 <= triangleAmount7; i7++)
    {
        glVertex2f(
            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
            y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
        );
    }
    glEnd();

    int i8;
    GLfloat x8=0.46f;
    GLfloat y8=0.4f;
    GLfloat radius8 =0.04f;
    int triangleAmount8 = 20;
    GLfloat twicePi8 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x8, y8);
    for(i8 = 0; i8 <= triangleAmount8; i8++)
    {
        glVertex2f(
            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
            y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
        );
    }
    glEnd();

    int i9;
    GLfloat x9=0.485f;
    GLfloat y9=0.45f;
    GLfloat radius9 =0.04f;
    int triangleAmount9 = 20;
    GLfloat twicePi9 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x9, y9);
    for(i9 = 0; i9 <= triangleAmount9; i9++)
    {
        glVertex2f(
            x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
            y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
        );
    }
    glEnd();

    ///body 4 leaves

    int i10;
    GLfloat x10=0.97f;
    GLfloat y10=0.4f;
    GLfloat radius10 =0.04f;
    int triangleAmount10 = 20;
    GLfloat twicePi10 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x10, y10);
    for(i10 = 0; i10 <= triangleAmount10; i10++)
    {
        glVertex2f(
            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
            y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
        );
    }
    glEnd();

    int i11;
    GLfloat x11=0.995f;
    GLfloat y11=0.45f;
    GLfloat radius11 =0.04f;
    int triangleAmount11 = 20;
    GLfloat twicePi11 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(17, 153, 37);
    glVertex2f(x11, y11);
    for(i11 = 0; i11 <= triangleAmount11; i11++)
    {
        glVertex2f(
            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
            y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
        );
    }
    glEnd();

}

void nightHill()
{
    ///hill 1
    glBegin(GL_POLYGON);
    glColor3ub(34, 102, 60);

    glVertex2f(-0.55,0.2);
    glVertex2f(-0.57,0.3);
    glVertex2f(-0.67,0.4);
    glVertex2f(-0.77,0.45);
    glVertex2f(-0.87,0.4);
    glVertex2f(-0.97,0.3);
    glVertex2f(-1,0.2);

    glEnd();

    ///hill 2
    glBegin(GL_POLYGON);
    glColor3ub(34, 102, 60);

    glVertex2f(-0.05,0.2);
    glVertex2f(-0.07,0.3);
    glVertex2f(-0.17,0.4);
    glVertex2f(-0.27,0.45);
    glVertex2f(-0.37,0.4);
    glVertex2f(-0.47,0.3);
    glVertex2f(-0.5,0.2);

    glEnd();

    ///hill 3
    glBegin(GL_POLYGON);
    glColor3ub(34, 102, 60);

    glVertex2f(0.46,0.2);
    glVertex2f(0.43,0.3);
    glVertex2f(0.33,0.4);
    glVertex2f(0.23,0.45);
    glVertex2f(0.13,0.4);
    glVertex2f(0.03,0.3);
    glVertex2f(0,0.2);

    glEnd();

    ///hill 4
    glBegin(GL_POLYGON);
    glColor3ub(34, 102, 60);

    glVertex2f(0.97,0.2);
    glVertex2f(0.94,0.3);
    glVertex2f(0.84,0.4);
    glVertex2f(0.74,0.45);
    glVertex2f(0.64,0.4);
    glVertex2f(0.54,0.3);
    glVertex2f(0.51,0.2);

    glEnd();

    ///tree body
    glLineWidth(15);
    glBegin(GL_LINES);
    glColor3ub(102,76,31);

    ///body 1
    glVertex2f(-0.525,0.2);
    glVertex2f(-0.525,0.4);
    ///body 2
    glVertex2f(-0.025,0.2);
    glVertex2f(-0.025,0.4);
    ///body 3
    glVertex2f(0.485,0.2);
    glVertex2f(0.485,0.4);
    ///body 3
    glVertex2f(0.995,0.2);
    glVertex2f(0.995,0.4);
    glEnd();

    ///body 1 leaves
    int i1;
    GLfloat x1=-0.5f;
    GLfloat y1=0.4f;
    GLfloat radius1 =0.04f;
    int triangleAmount1 = 20;
    GLfloat twicePi1 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x1, y1);
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
            y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
        );
    }
    glEnd();

    int i2;
    GLfloat x2=-0.55f;
    GLfloat y2=0.4f;
    GLfloat radius2 =0.04f;
    int triangleAmount2 = 20;
    GLfloat twicePi2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f(
            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
            y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
    glEnd();

    int i3;
    GLfloat x3=-0.525f;
    GLfloat y3=0.45f;
    GLfloat radius3 =0.04f;
    int triangleAmount3 = 20;
    GLfloat twicePi3 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x3, y3);
    for(i3 = 0; i3 <= triangleAmount3; i3++)
    {
        glVertex2f(
            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
            y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
        );
    }
    glEnd();

    ///body 2 leaves
    int i4;
    GLfloat x4=0.0f;
    GLfloat y4=0.4f;
    GLfloat radius4 =0.04f;
    int triangleAmount4 = 20;
    GLfloat twicePi4 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x4, y4);
    for(i4 = 0; i4 <= triangleAmount4; i4++)
    {
        glVertex2f(
            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
            y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
        );
    }
    glEnd();

    int i5;
    GLfloat x5=-0.05f;
    GLfloat y5=0.4f;
    GLfloat radius5 =0.04f;
    int triangleAmount5 = 20;
    GLfloat twicePi5 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x5, y5);
    for(i5 = 0; i5 <= triangleAmount5; i5++)
    {
        glVertex2f(
            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
            y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
        );
    }
    glEnd();

    int i6;
    GLfloat x6=-0.025f;
    GLfloat y6=0.45f;
    GLfloat radius6 =0.04f;
    int triangleAmount6 = 20;
    GLfloat twicePi6 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x6, y6);
    for(i6 = 0; i6 <= triangleAmount6; i6++)
    {
        glVertex2f(
            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
            y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
        );
    }
    glEnd();

    ///body 3 leaves
    int i7;
    GLfloat x7=0.51f;
    GLfloat y7=0.4f;
    GLfloat radius7 =0.04f;
    int triangleAmount7 = 20;
    GLfloat twicePi7 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x7, y7);
    for(i7 = 0; i7 <= triangleAmount7; i7++)
    {
        glVertex2f(
            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
            y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
        );
    }
    glEnd();

    int i8;
    GLfloat x8=0.46f;
    GLfloat y8=0.4f;
    GLfloat radius8 =0.04f;
    int triangleAmount8 = 20;
    GLfloat twicePi8 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x8, y8);
    for(i8 = 0; i8 <= triangleAmount8; i8++)
    {
        glVertex2f(
            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
            y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
        );
    }
    glEnd();

    int i9;
    GLfloat x9=0.485f;
    GLfloat y9=0.45f;
    GLfloat radius9 =0.04f;
    int triangleAmount9 = 20;
    GLfloat twicePi9 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x9, y9);
    for(i9 = 0; i9 <= triangleAmount9; i9++)
    {
        glVertex2f(
            x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
            y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
        );
    }
    glEnd();

    ///body 4 leaves

    int i10;
    GLfloat x10=0.97f;
    GLfloat y10=0.4f;
    GLfloat radius10 =0.04f;
    int triangleAmount10 = 20;
    GLfloat twicePi10 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x10, y10);
    for(i10 = 0; i10 <= triangleAmount10; i10++)
    {
        glVertex2f(
            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
            y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
        );
    }
    glEnd();

    int i11;
    GLfloat x11=0.995f;
    GLfloat y11=0.45f;
    GLfloat radius11 =0.04f;
    int triangleAmount11 = 20;
    GLfloat twicePi11 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,99,42);
    glVertex2f(x11, y11);
    for(i11 = 0; i11 <= triangleAmount11; i11++)
    {
        glVertex2f(
            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
            y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
        );
    }
    glEnd();
}

void rain()
{
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(1.0,1.0);
    glVertex2f(0.995,0.975);

    glVertex2f(0.980,1.0);
    glVertex2f(0.975,0.975);

    glVertex2f(0.960,1.0);
    glVertex2f(0.955,0.975);

    glVertex2f(0.940,1.0);
    glVertex2f(0.935,0.98);

    glVertex2f(0.920,1.0);
    glVertex2f(0.915,0.98);

    glVertex2f(0.900,1.0);
    glVertex2f(0.895,0.98);

    glVertex2f(0.880,1.0);
    glVertex2f(0.875,0.98);

    glVertex2f(0.860,1.0);
    glVertex2f(0.855,0.98);

    glVertex2f(0.840,1.0);
    glVertex2f(0.835,0.98);

    glVertex2f(0.820,1.0);
    glVertex2f(0.815,0.98);

    glVertex2f(0.800,1.0);
    glVertex2f(0.795,0.98);

    glVertex2f(0.780,1.0);
    glVertex2f(0.775,0.98);

    glVertex2f(0.760,1.0);
    glVertex2f(0.755,0.98);

    glVertex2f(0.740,1.0);
    glVertex2f(0.735,0.98);

    glVertex2f(0.720,1.0);
    glVertex2f(0.715,0.98);

    glVertex2f(0.700,1.0);
    glVertex2f(0.695,0.98);

    glVertex2f(0.680,1.0);
    glVertex2f(0.675,0.98);

    glVertex2f(0.660,1.0);
    glVertex2f(0.655,0.98);

    glVertex2f(0.640,1.0);
    glVertex2f(0.635,0.98);

    glVertex2f(0.620,1.0);
    glVertex2f(0.615,0.98);

    glVertex2f(0.600,1.0);
    glVertex2f(0.595,0.98);

    glVertex2f(0.580,1.0);
    glVertex2f(0.575,0.98);

    glVertex2f(0.560,1.0);
    glVertex2f(0.555,0.98);

    glVertex2f(0.540,1.0);
    glVertex2f(0.535,0.98);

    glVertex2f(0.520,1.0);
    glVertex2f(0.515,0.98);

    glVertex2f(0.500,1.0);
    glVertex2f(0.495,0.98);

    glVertex2f(0.480,1.0);
    glVertex2f(0.475,0.98);

    glVertex2f(0.460,1.0);
    glVertex2f(0.455,0.98);

    glVertex2f(0.440,1.0);
    glVertex2f(0.435,0.98);

    glVertex2f(0.420,1.0);
    glVertex2f(0.415,0.98);

    glVertex2f(0.400,1.0);
    glVertex2f(0.395,0.98);

    glVertex2f(0.380,1.0);
    glVertex2f(0.375,0.98);

    glVertex2f(0.360,1.0);
    glVertex2f(0.355,0.98);

    glVertex2f(0.340,1.0);
    glVertex2f(0.335,0.98);

    glVertex2f(0.320,1.0);
    glVertex2f(0.315,0.98);

    glVertex2f(0.300,1.0);
    glVertex2f(0.295,0.98);

    glVertex2f(0.280,1.0);
    glVertex2f(0.275,0.98);

    glVertex2f(0.260,1.0);
    glVertex2f(0.255,0.98);

    glVertex2f(0.240,1.0);
    glVertex2f(0.235,0.98);

    glVertex2f(0.220,1.0);
    glVertex2f(0.215,0.98);

    glVertex2f(0.200,1.0);
    glVertex2f(0.195,0.98);

    glVertex2f(0.180,1.0);
    glVertex2f(0.175,0.98);

    glVertex2f(0.160,1.0);
    glVertex2f(0.155,0.98);

    glVertex2f(0.140,1.0);
    glVertex2f(0.135,0.98);

    glVertex2f(0.120,1.0);
    glVertex2f(0.115,0.98);

    glVertex2f(0.100,1.0);
    glVertex2f(0.095,0.98);

    glVertex2f(0.080,1.0);
    glVertex2f(0.075,0.98);

    glVertex2f(0.060,1.0);
    glVertex2f(0.055,0.98);

    glVertex2f(0.040,1.0);
    glVertex2f(0.035,0.98);

    glVertex2f(0.020,1.0);
    glVertex2f(0.015,0.98);

    glVertex2f(0.000,1.0);
    glVertex2f(-0.005,0.98);

    glVertex2f(-0.020,1.0);
    glVertex2f(-0.025,0.98);

    glVertex2f(-0.040,1.0);
    glVertex2f(-0.045,0.98);

    glVertex2f(-0.060,1.0);
    glVertex2f(-0.065,0.98);

    glVertex2f(-0.080,1.0);
    glVertex2f(-0.085,0.98);

    glVertex2f(-0.100,1.0);
    glVertex2f(-0.105,0.98);

    glVertex2f(-0.120,1.0);
    glVertex2f(-0.125,0.98);

    glVertex2f(-0.140,1.0);
    glVertex2f(-0.145,0.98);

    glVertex2f(-0.160,1.0);
    glVertex2f(-0.165,0.98);

    glVertex2f(-0.180,1.0);
    glVertex2f(-0.185,0.98);

    glVertex2f(-0.200,1.0);
    glVertex2f(-0.205,0.98);

    glVertex2f(-0.220,1.0);
    glVertex2f(-0.225,0.98);

    glVertex2f(-0.240,1.0);
    glVertex2f(-0.245,0.98);

    glVertex2f(-0.260,1.0);
    glVertex2f(-0.265,0.98);

    glVertex2f(-0.280,1.0);
    glVertex2f(-0.285,0.98);

    glVertex2f(-0.300,1.0);
    glVertex2f(-0.305,0.98);

    glVertex2f(-0.320,1.0);
    glVertex2f(-0.325,0.98);

    glVertex2f(-0.340,1.0);
    glVertex2f(-0.345,0.98);

    glVertex2f(-0.360,1.0);
    glVertex2f(-0.365,0.98);

    glVertex2f(-0.380,1.0);
    glVertex2f(-0.385,0.98);

    glVertex2f(-0.400,1.0);
    glVertex2f(-0.405,0.98);

    glVertex2f(-0.420,1.0);
    glVertex2f(-0.425,0.98);

    glVertex2f(-0.440,1.0);
    glVertex2f(-0.445,0.98);

    glVertex2f(-0.460,1.0);
    glVertex2f(-0.465,0.98);

    glVertex2f(-0.480,1.0);
    glVertex2f(-0.485,0.98);

    glVertex2f(-0.500,1.0);
    glVertex2f(-0.505,0.98);

    glVertex2f(-0.520,1.0);
    glVertex2f(-0.525,0.98);

    glVertex2f(-0.540,1.0);
    glVertex2f(-0.545,0.98);

    glVertex2f(-0.560,1.0);
    glVertex2f(-0.565,0.98);

    glVertex2f(-0.580,1.0);
    glVertex2f(-0.585,0.98);

    glVertex2f(-0.600,1.0);
    glVertex2f(-0.605,0.98);

    glVertex2f(-0.620,1.0);
    glVertex2f(-0.625,0.98);

    glVertex2f(-0.640,1.0);
    glVertex2f(-0.645,0.98);

    glVertex2f(-0.660,1.0);
    glVertex2f(-0.665,0.98);

    glVertex2f(-0.680,1.0);
    glVertex2f(-0.685,0.98);

    glVertex2f(-0.700,1.0);
    glVertex2f(-0.705,0.98);

    glVertex2f(-0.720,1.0);
    glVertex2f(-0.725,0.98);

    glVertex2f(-0.740,1.0);
    glVertex2f(-0.745,0.98);

    glVertex2f(-0.760,1.0);
    glVertex2f(-0.765,0.98);

    glVertex2f(-0.780,1.0);
    glVertex2f(-0.785,0.98);

    glVertex2f(-0.800,1.0);
    glVertex2f(-0.805,0.98);

    glVertex2f(-0.820,1.0);
    glVertex2f(-0.825,0.98);

    glVertex2f(-0.840,1.0);
    glVertex2f(-0.845,0.98);

    glVertex2f(-0.860,1.0);
    glVertex2f(-0.865,0.98);

    glVertex2f(-0.880,1.0);
    glVertex2f(-0.885,0.98);

    glVertex2f(-0.900,1.0);
    glVertex2f(-0.905,0.98);

    glVertex2f(-0.920,1.0);
    glVertex2f(-0.925,0.98);

    glVertex2f(-0.940,1.0);
    glVertex2f(-0.945,0.98);

    glVertex2f(-0.960,1.0);
    glVertex2f(-0.965,0.98);

    glVertex2f(-0.980,1.0);
    glVertex2f(-0.985,0.98);

    glEnd();
    //glLineWidth(0.4);

}

void fullrain()
{


    glTranslatef(0.0,-0.15,0.0);
    rain();


    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

}

void boat()
{
    glBegin(GL_QUADS);
    glColor3f(0,0,0);

    glVertex2f(0.6,0.08);
    glVertex2f(0.35,0.08);
    ///body
    glVertex2f(0.38,0.03);
    glVertex2f(0.57,0.03);

    glEnd();

    ///shed
    glBegin(GL_POLYGON);
    glColor3ub(226, 163, 36);

    glVertex2f(0.4,0.08);
    glVertex2f(0.55,0.08);
    glVertex2f(0.54,0.15);
    glVertex2f(0.52,0.17);
    glVertex2f(0.43,0.17);
    glVertex2f(0.41,0.15);

    glEnd();

    ///sail
    glBegin(GL_QUADS);
    glColor3ub(255, 35, 35);

    glVertex2f(0.44,0.22);
    glVertex2f(0.49,0.2);
    glVertex2f(0.49,0.33);
    glVertex2f(0.44,0.35);

    glEnd();

    ///stick
    glBegin(GL_LINES);
    glColor3f(0,1,0);

    glVertex2f(0.465,0.17);
    glVertex2f(0.465,0.38);

    glEnd();
}

void nightboat()
{
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(0.3f, -0.25f);
    glVertex2f(0.35f, -0.3f);
    glVertex2f(0.65f, -0.3f);
    glVertex2f(0.7f, -0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 125, 46);
    glVertex2f(0.37f, -0.25f);
    glVertex2f(0.39f,-0.17f);
    glVertex2f(0.412f, -0.13f);
    glVertex2f(0.63f, -0.13f);
    glVertex2f(0.64f, -0.16f);
    glVertex2f(0.65f, -0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(152,15,15);
    glVertex2f(0.462f, -0.08f);
    glVertex2f(0.462f, 0.08f);
    glVertex2f(0.465f, 0.1f);
    glVertex2f(0.564f, 0.08f);
    glVertex2f(0.565f, 0.06f);
    glVertex2f(0.565f, -0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(8,132,25);
    glVertex2f(0.5f, -0.13f);
    glVertex2f(0.5f, 0.14f);
    glVertex2f(0.51f, 0.14f);
    glVertex2f(0.51f, -0.13f);
    glEnd();
}


void boat2()
{
    ///body
    glBegin(GL_QUADS);
    glColor3f(0,0,0);

    glVertex2f(0.3,-0.32);
    glVertex2f(0.05,-0.32);
    glVertex2f(0.08,-0.37);
    glVertex2f(0.27,-0.37);

    glEnd();

    ///shed
    glBegin(GL_POLYGON);
    glColor3ub(201, 188, 105);

    glVertex2f(0.1,-0.32);
    glVertex2f(0.25,-0.32);
    glVertex2f(0.24,-0.25);
    glVertex2f(0.22,-0.23);
    glVertex2f(0.13,-0.23);
    glVertex2f(0.11,-0.25);

    glEnd();

    ///sail
    glBegin(GL_QUADS);
    glColor3ub(255, 128, 0);

    glVertex2f(0.14,-0.18);
    glVertex2f(0.19,-0.2);
    glVertex2f(0.19,-0.07);
    glVertex2f(0.14,-0.05);

    glEnd();

    ///stick
    glBegin(GL_LINES);
    glColor3f(0,1,0);

    glVertex2f(0.165,-0.23);
    glVertex2f(0.165,-0.02);

    glEnd();
}

void nightBoat2()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.63f, -0.53f);
    glVertex2f(0.53f, -0.53f);
    glVertex2f(0.43f, -0.5f);
    glVertex2f(0.53f, -0.6f);
    glVertex2f(0.78f, -0.6f);
    glVertex2f(0.88f, -0.5f);
    glVertex2f(0.78f, -0.53f);
    glVertex2f(0.73f, -0.53f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(122, 122, 82);
    glVertex2f(0.43f, -0.5f);
    glVertex2f(0.53f, -0.53f);
    glVertex2f(0.63f, -0.53f);
    glVertex2f(0.73f, -0.53f);
    glVertex2f(0.78f, -0.53f);
    glVertex2f(0.88f, -0.5f);////
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.43f, -0.5f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.88f, -0.5f);////
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.43f, -0.5f);
    glEnd();

    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(0,0, 0);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.53f, -0.535f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.63f, -0.535f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.73f, -0.535f);
    glVertex2f(0.81f, -0.48f);
    glVertex2f(0.81f, -0.535f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(151, 104, 33);
    glVertex2f(0.42f, -0.35f);
    glVertex2f(0.4f, -0.53f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
    glVertex2f(0.38f, -0.42f);
    glVertex2f(0.43f, -0.5f);
    glEnd();
}

void river()
{
    glBegin(GL_QUADS);
    glColor3ub(18, 150, 227);

    glVertex2f(1,0.2);
    glVertex2f(-1,0.2);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);

    glEnd();
}

void standingBoat()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.63f, -0.53f);
    glVertex2f(0.53f, -0.53f);
    glVertex2f(0.43f, -0.5f);
    glVertex2f(0.53f, -0.6f);
    glVertex2f(0.78f, -0.6f);
    glVertex2f(0.88f, -0.5f);
    glVertex2f(0.78f, -0.53f);
    glVertex2f(0.73f, -0.53f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(122, 122, 82);
    glVertex2f(0.43f, -0.5f);
    glVertex2f(0.53f, -0.53f);
    glVertex2f(0.63f, -0.53f);
    glVertex2f(0.73f, -0.53f);
    glVertex2f(0.78f, -0.53f);
    glVertex2f(0.88f, -0.5f);////
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.43f, -0.5f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.88f, -0.5f);////
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.43f, -0.5f);
    glEnd();

    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(0,0, 0);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.53f, -0.535f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.63f, -0.535f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.73f, -0.535f);
    glVertex2f(0.81f, -0.48f);
    glVertex2f(0.81f, -0.535f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(204, 153, 0);
    glVertex2f(0.42f, -0.35f);
    glVertex2f(0.4f, -0.53f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
    glVertex2f(0.38f, -0.42f);
    glVertex2f(0.43f, -0.5f);
    glEnd();

}

void field()
{
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 51);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(-1.0f,0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, -0.03);
    glVertex2f(0.2f, -0.07);
    glVertex2f(0.3f, -0.1);//6
    glVertex2f(0.2f, -0.13);
    glVertex2f(0.1f, -0.17);
    glVertex2f(0.2f, -0.2);
    glVertex2f(0.35f, -0.23);
    glVertex2f(0.25f, -0.25);
    glVertex2f(0.18f, -0.28);//12
    glVertex2f(0.3f, -0.32);
    glVertex2f(0.2f, -0.35);
    glVertex2f(0.4f, -0.4);
    glVertex2f(0.4f, -0.6);
    glVertex2f(0.2f, -0.65);
    glVertex2f(0.3f, -0.7);
    glVertex2f(0.2f, -0.75);
    glVertex2f(0.4f, -0.8);
    glVertex2f(0.2f, -0.85);
    glVertex2f(0.35f, -0.9);
    glVertex2f(0.25f, -0.95);
    glVertex2f(0.4f, -1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.17f, -0.19);
    glVertex2f(0.19f, -0.2f);
    glVertex2f(0.3f, -0.12f);
    glVertex2f(0.3f, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.23f, -0.295);
    glVertex2f(0.25f, -0.305f);
    glVertex2f(0.35f, -0.25f);
    glVertex2f(0.35f, -0.23);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.3f, -0.32);
    glVertex2f(0.3f, -0.34);
    glVertex2f(0.25f, -0.365f);
    glVertex2f(0.2f, -0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.205f, -0.655);
    glVertex2f(0.4f, -0.6);
    glVertex2f(0.4f, -0.625);
    glVertex2f(0.25f, -0.675);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.3f, -0.7);
    glVertex2f(0.3f, -0.72);
    glVertex2f(0.24f, -0.7595);
    glVertex2f(0.2f, -0.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.4f, -0.8);
    glVertex2f(0.4f, -0.825);
    glVertex2f(0.24f, -0.865);
    glVertex2f(0.2f, -0.85);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.35f, -0.9);
    glVertex2f(0.35f, -0.925);
    glVertex2f(0.27f, -0.958);
    glVertex2f(0.25f, -0.948);
    glEnd();


}


void nightField()
{
    glBegin(GL_POLYGON);
    glColor3ub(56, 110, 23);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(-1.0f,0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, -0.03);
    glVertex2f(0.2f, -0.07);
    glVertex2f(0.3f, -0.1);//6
    glVertex2f(0.2f, -0.13);
    glVertex2f(0.1f, -0.17);
    glVertex2f(0.2f, -0.2);
    glVertex2f(0.35f, -0.23);
    glVertex2f(0.25f, -0.25);
    glVertex2f(0.18f, -0.28);//12
    glVertex2f(0.3f, -0.32);
    glVertex2f(0.2f, -0.35);
    glVertex2f(0.4f, -0.4);
    glVertex2f(0.4f, -0.6);
    glVertex2f(0.2f, -0.65);
    glVertex2f(0.3f, -0.7);
    glVertex2f(0.2f, -0.75);
    glVertex2f(0.4f, -0.8);
    glVertex2f(0.2f, -0.85);
    glVertex2f(0.35f, -0.9);
    glVertex2f(0.25f, -0.95);
    glVertex2f(0.4f, -1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.17f, -0.19);
    glVertex2f(0.19f, -0.2f);
    glVertex2f(0.3f, -0.12f);
    glVertex2f(0.3f, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.23f, -0.295);
    glVertex2f(0.25f, -0.305f);
    glVertex2f(0.35f, -0.25f);
    glVertex2f(0.35f, -0.23);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.3f, -0.32);
    glVertex2f(0.3f, -0.34);
    glVertex2f(0.25f, -0.365f);
    glVertex2f(0.2f, -0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.205f, -0.655);
    glVertex2f(0.4f, -0.6);
    glVertex2f(0.4f, -0.625);
    glVertex2f(0.25f, -0.675);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.3f, -0.7);
    glVertex2f(0.3f, -0.72);
    glVertex2f(0.24f, -0.7595);
    glVertex2f(0.2f, -0.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.4f, -0.8);
    glVertex2f(0.4f, -0.825);
    glVertex2f(0.24f, -0.865);
    glVertex2f(0.2f, -0.85);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.35f, -0.9);
    glVertex2f(0.35f, -0.925);
    glVertex2f(0.27f, -0.958);
    glVertex2f(0.25f, -0.948);
    glEnd();
}

void house()
{
    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.58f,0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-0.49f,0.2f);
    glVertex2f(-0.13f,0.2f);
    glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.49f,-0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.63f,0.2f);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.49f,-0.2f);
    glVertex2f(-0.17f,-0.2f);

    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.1f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.49f,0.2f);
    glVertex2f(-0.49f,-0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.49f,-0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.13f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.58f,0.5f);

    glColor3ub(0,0,0);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.63f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.57f,0.445f);
    glVertex2f(-0.61f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,-0.15f);

    glColor3ub(0,0,0);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.49f,-0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.18f,0.5f);

    glColor3ub(0,0,0);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.58f,0.5f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);    //main door
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.35f,-0.2f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.35f,-0.2f);
    glVertex2f(-0.285f,0.1f);
    glVertex2f(-0.285f,-0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.38f,0.05f); //left window
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.44f,-0.05f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.41f,0.05f);
    glVertex2f(-0.41f,-0.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.51f,0.12f); //2nd door
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.58f,-0.17f);
    glVertex2f(-0.51f,-0.2f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.58f,-0.17f);
    glVertex2f(-0.51f,0.12f);
    glVertex2f(-0.51f,-0.2f);
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.51f,0.12f);
    glVertex2f(-0.545f,0.13f);
    glVertex2f(-0.545f,-0.185f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.2f,0.05f);   //rightwindow
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.14f,-0.05f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.14f,-0.05f);
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.14f,-0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.17f,0.05f);
    glVertex2f(-0.17f,-0.05f);
    glEnd();

}

void nightHouse()
{
    glBegin(GL_POLYGON);
    glColor3ub(158, 122, 24);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.58f,0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158, 122, 24);
    glVertex2f(-0.49f,0.2f);
    glVertex2f(-0.13f,0.2f);
    glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.49f,-0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158, 122, 24);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.63f,0.2f);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.49f,-0.2f);
    glVertex2f(-0.17f,-0.2f);

    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.1f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.49f,0.2f);
    glVertex2f(-0.49f,-0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.49f,-0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.13f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.58f,0.5f);

    glColor3ub(0,0,0);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.63f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.57f,0.445f);
    glVertex2f(-0.61f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,-0.15f);

    glColor3ub(0,0,0);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.49f,-0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.18f,0.5f);

    glColor3ub(0,0,0);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.58f,0.5f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(145, 113, 25);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);    //main door
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.35f,-0.2f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.35f,-0.2f);
    glVertex2f(-0.285f,0.1f);
    glVertex2f(-0.285f,-0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(145, 113, 25);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.38f,0.05f); //left window
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.44f,-0.05f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.41f,0.05f);
    glVertex2f(-0.41f,-0.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(145, 113, 25);
    glVertex2f(-0.51f,0.12f); //2nd door
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.58f,-0.17f);
    glVertex2f(-0.51f,-0.2f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.58f,-0.17f);
    glVertex2f(-0.51f,0.12f);
    glVertex2f(-0.51f,-0.2f);
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.51f,0.12f);
    glVertex2f(-0.545f,0.13f);
    glVertex2f(-0.545f,-0.185f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(145, 113, 25);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.2f,0.05f);   //rightwindow
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.14f,-0.05f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.14f,-0.05f);
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.14f,-0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.17f,0.05f);
    glVertex2f(-0.17f,-0.05f);
    glEnd();
}

void tree()
{

    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    //glVertex2f(-0.7f,-0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

    int i;

    GLfloat x=-.75f;
    GLfloat y=.33f;
    GLfloat radius =.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=-.68f;
    GLfloat b=.31f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=-.81f;
    GLfloat d=.31f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=-.87f;
    GLfloat f=.35f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=-.61f;
    GLfloat h=.35f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i *  twicePi / triangleAmount)),
            h+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat a1=-.61f;
    GLfloat b1=.4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius * cos(i *  twicePi / triangleAmount)),
            b1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c1=-.88f;
    GLfloat d1=.4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c1 + (radius * cos(i *  twicePi / triangleAmount)),
            d1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e1=-.87f;
    GLfloat f1=.44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e1, f1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e1 + (radius * cos(i *  twicePi / triangleAmount)),
            f1+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g1=-.61f;
    GLfloat h1=.4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g1 + (radius * cos(i *  twicePi / triangleAmount)),
            h1+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat e11=-.64f;
    GLfloat f11=.44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e11, f11); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e11 + (radius * cos(i *  twicePi / triangleAmount)),
            f11+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e12=-.75f;
    GLfloat f12=.44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e12, f12); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e12 + (radius * cos(i *  twicePi / triangleAmount)),
            f12+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f;
    GLfloat f123=.5f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e123, f123); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e123 + (radius * cos(i *  twicePi / triangleAmount)),
            f123+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat e1232=-.7f;
    GLfloat f1232=.5f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e1232, f1232); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
            f1232+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void nightTree()
{

    glBegin(GL_POLYGON);
    glColor3ub(61, 45, 3);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    //glVertex2f(-0.7f,-0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(61, 45, 3);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(61, 45, 3);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(61, 45, 3);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(61, 45, 3);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

    int i;

    GLfloat x=-.75f;
    GLfloat y=.33f;
    GLfloat radius =.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=-.68f;
    GLfloat b=.31f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=-.81f;
    GLfloat d=.31f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=-.87f;
    GLfloat f=.35f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=-.61f;
    GLfloat h=.35f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i *  twicePi / triangleAmount)),
            h+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat a1=-.61f;
    GLfloat b1=.4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius * cos(i *  twicePi / triangleAmount)),
            b1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c1=-.88f;
    GLfloat d1=.4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c1 + (radius * cos(i *  twicePi / triangleAmount)),
            d1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e1=-.87f;
    GLfloat f1=.44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(e1, f1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e1 + (radius * cos(i *  twicePi / triangleAmount)),
            f1+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g1=-.61f;
    GLfloat h1=.4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g1 + (radius * cos(i *  twicePi / triangleAmount)),
            h1+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat e11=-.64f;
    GLfloat f11=.44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(e11, f11); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e11 + (radius * cos(i *  twicePi / triangleAmount)),
            f11+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e12=-.75f;
    GLfloat f12=.44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(e12, f12); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e12 + (radius * cos(i *  twicePi / triangleAmount)),
            f12+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(36, 120, 49);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f;
    GLfloat f123=.5f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(e123, f123); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e123 + (radius * cos(i *  twicePi / triangleAmount)),
            f123+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat e1232=-.7f;
    GLfloat f1232=.5f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(36, 120, 49);
    glVertex2f(e1232, f1232); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
            f1232+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void straw()
{
    glBegin(GL_POLYGON);
    glColor3ub(255, 219, 77);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.07f, 0.15f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(-0.05f, 0.27f);
    glVertex2f(-0.12f, 0.22f);
    glVertex2f(-0.17f, 0.15f);
    glVertex2f(-0.2f, 0.1f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.05f, 0.27f);
    glVertex2f(-0.05f, 0.31f);
    glEnd();
}

void nigthStraw()
{
    glBegin(GL_POLYGON);
    glColor3ub(164, 168, 32);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.07f, 0.15f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(-0.05f, 0.27f);
    glVertex2f(-0.12f, 0.22f);
    glVertex2f(-0.17f, 0.15f);
    glVertex2f(-0.2f, 0.1f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.05f, 0.27f);
    glVertex2f(-0.05f, 0.31f);
    glEnd();
}

void way()
{
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.35f,-0.2f);
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.28f,-0.5f);
    glVertex2f(-0.43f,-0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.43f,-0.5f);
    glVertex2f(-0.75f,-1.0f);
    glVertex2f(-0.56f,-1.0f);
    glVertex2f(-0.28f,-0.5f);
    glEnd();

}

void nightway()
{
    glBegin(GL_QUADS);
    glColor3ub(139, 139, 98);
    glVertex2f(-0.35f,-0.2f);
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.28f,-0.5f);
    glVertex2f(-0.43f,-0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 139, 98);
    glVertex2f(-0.43f,-0.5f);
    glVertex2f(-0.75f,-1.0f);
    glVertex2f(-0.56f,-1.0f);
    glVertex2f(-0.28f,-0.5f);
    glEnd();

}



void well()
{
  glBegin(GL_POLYGON);

   //round1
    glColor3ub(81, 112, 107);
    glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.9f,-0.55f);
    glVertex2f(-0.85f,-0.575f);
    glVertex2f(-0.8f,-0.59f);
    glVertex2f(-0.7f,-0.59f);
    glVertex2f(-0.65f,-0.575f);
    glVertex2f(-0.6f,-0.55f);
    glVertex2f(-0.6f,-0.35f);
    glEnd();

    //wall
    glBegin(GL_POLYGON);
    glColor3ub(77, 153, 141);
    glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.85f,-0.375f);
    glVertex2f(-0.8f,-0.38f);
    glVertex2f(-0.7f,-0.38f);
    glVertex2f(-0.65f,-0.375f);
    glVertex2f(-0.6f,-0.35f);
    glVertex2f(-0.65f,-0.33f);
    glVertex2f(-0.7f,-0.325f);
     glVertex2f(-0.8f,-0.325f);
     glVertex2f(-0.85f,-0.33f);
    glEnd();

    glLineWidth(5);
     glBegin(GL_LINES);
    glColor3ub(81, 112, 107);
     glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.85f,-0.33f);
    glVertex2f(-0.85f,-0.33f);
    glVertex2f(-0.8f,-0.325f);
    glVertex2f(-0.8f,-0.325f);
    glVertex2f(-0.7f,-0.325f);
    glVertex2f(-0.7f,-0.325f);
    glVertex2f(-0.65f,-0.33f);
     glVertex2f(-0.65f,-0.33f);
     glVertex2f(-0.6f,-0.35f);
    glEnd();


    //bucket
    glBegin(GL_POLYGON);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f,-0.43f);
    glVertex2f(-0.57f,-0.5f);
    glVertex2f(-0.52f,-0.5f);
    glVertex2f(-0.5f,-0.43f);
    glVertex2f(-0.52f,-0.42f);
    glVertex2f(-0.57f,-0.42f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 154, 214);
    glVertex2f(-0.585f,-0.43f);
    glVertex2f(-0.568f,-0.44f);
    glVertex2f(-0.528f,-0.44f);
    glVertex2f(-0.505f,-0.43f);
    glVertex2f(-0.528f,-0.425f);
    glVertex2f(-0.57f,-0.425f);
    glEnd();

     //Rope
    glLineWidth(3);
     glBegin(GL_LINES);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f,-0.43f);
    glVertex2f(-0.57f,-0.39f);//
    glVertex2f(-0.57f,-0.39f);
    glVertex2f(-0.55f,-0.39f);//
    glVertex2f(-0.55f,-0.39f);
    glVertex2f(-0.52f,-0.39f);//
    glVertex2f(-0.52f,-0.39f);
    glVertex2f(-0.5f,-0.43f);//
    glEnd();

    glLineWidth(2.5);
     glBegin(GL_LINES);
    glColor3ub(230, 172, 0);
    glVertex2f(-0.545f,-0.385f);
    glVertex2f(-0.57f,-0.45f);//
    glVertex2f(-0.57f,-0.45f);
    glVertex2f(-0.575f,-0.5f);//
    glVertex2f(-0.575f,-0.5f);
    glVertex2f(-0.58f,-0.53f);//
    glVertex2f(-0.58f,-0.53f);
    glVertex2f(-0.57f,-0.55f);//
    glVertex2f(-0.57f,-0.55f);
    glVertex2f(-0.48f,-0.53f);//
    glEnd();


}

void nightWell()
{
   glBegin(GL_POLYGON);

   //round1
    glColor3ub(72, 97, 93);
    glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.9f,-0.55f);
    glVertex2f(-0.85f,-0.575f);
    glVertex2f(-0.8f,-0.59f);
    glVertex2f(-0.7f,-0.59f);
    glVertex2f(-0.65f,-0.575f);
    glVertex2f(-0.6f,-0.55f);
    glVertex2f(-0.6f,-0.35f);
    glEnd();

    //wall
    glBegin(GL_POLYGON);
    glColor3ub(63, 112, 105);
    glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.85f,-0.375f);
    glVertex2f(-0.8f,-0.38f);
    glVertex2f(-0.7f,-0.38f);
    glVertex2f(-0.65f,-0.375f);
    glVertex2f(-0.6f,-0.35f);
    glVertex2f(-0.65f,-0.33f);
    glVertex2f(-0.7f,-0.325f);
     glVertex2f(-0.8f,-0.325f);
     glVertex2f(-0.85f,-0.33f);
    glEnd();

    glLineWidth(5);
     glBegin(GL_LINES);
    glColor3ub(72, 97, 93);
     glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.85f,-0.33f);
    glVertex2f(-0.85f,-0.33f);
    glVertex2f(-0.8f,-0.325f);
    glVertex2f(-0.8f,-0.325f);
    glVertex2f(-0.7f,-0.325f);
    glVertex2f(-0.7f,-0.325f);
    glVertex2f(-0.65f,-0.33f);
     glVertex2f(-0.65f,-0.33f);
     glVertex2f(-0.6f,-0.35f);
    glEnd();


    //bucket
    glBegin(GL_POLYGON);
    glColor3ub(146, 146, 116);
    glVertex2f(-0.59f,-0.43f);
    glVertex2f(-0.57f,-0.5f);
    glVertex2f(-0.52f,-0.5f);
    glVertex2f(-0.5f,-0.43f);
    glVertex2f(-0.52f,-0.42f);
    glVertex2f(-0.57f,-0.42f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(31, 132, 182);
    glVertex2f(-0.585f,-0.43f);
    glVertex2f(-0.568f,-0.44f);
    glVertex2f(-0.528f,-0.44f);
    glVertex2f(-0.505f,-0.43f);
    glVertex2f(-0.528f,-0.425f);
    glVertex2f(-0.57f,-0.425f);
    glEnd();


    glLineWidth(3);
     glBegin(GL_LINES);
    glColor3ub(146, 146, 116);
    glVertex2f(-0.59f,-0.43f);
    glVertex2f(-0.57f,-0.39f);//
    glVertex2f(-0.57f,-0.39f);
    glVertex2f(-0.55f,-0.39f);//
    glVertex2f(-0.55f,-0.39f);
    glVertex2f(-0.52f,-0.39f);//
    glVertex2f(-0.52f,-0.39f);
    glVertex2f(-0.5f,-0.43f);//
    glEnd();
    //Rope
    glLineWidth(2.5);
     glBegin(GL_LINES);
    glColor3ub(142, 113, 16);
    glVertex2f(-0.545f,-0.385f);
    glVertex2f(-0.57f,-0.45f);//
    glVertex2f(-0.57f,-0.45f);
    glVertex2f(-0.575f,-0.5f);//
    glVertex2f(-0.575f,-0.5f);
    glVertex2f(-0.58f,-0.53f);//
    glVertex2f(-0.58f,-0.53f);
    glVertex2f(-0.57f,-0.55f);//
    glVertex2f(-0.57f,-0.55f);
    glVertex2f(-0.48f,-0.53f);//
    glEnd();

}

void fence()
{

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);



    glEnd();
}

void nightFence()
{
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(135, 132, 70);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);
    glColor3ub(135, 132, 70);
    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);
    glColor3ub(135, 132, 70);
    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);
    glColor3ub(135, 132, 70);
    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glColor3ub(135, 132, 70);
    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glColor3ub(135, 132, 70);
    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glColor3ub(135, 132, 70);
    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);
    glColor3ub(135, 132, 70);
    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);
    glColor3ub(135, 132, 70);
    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);
    glColor3ub(135, 132, 70);
    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);
    glColor3ub(135, 132, 70);
    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glColor3ub(135, 132, 70);
    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);



    glEnd();
}

void bird()
{
    int i;

    GLfloat mm=0.182f;
    GLfloat nn=.801f;
    GLfloat radiusmm =.01f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
    //head
    glBegin(GL_TRIANGLE_FAN);
    //225, 225, 208
    glColor3ub(130,65,65);
    glVertex2f(mm, nn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
            nn + (radiusmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //body
    glBegin(GL_POLYGON);
    //225, 225, 208
    glColor3ub(130,65,65 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    //wing 1
    glBegin(GL_TRIANGLES);
    //217,217,21,7
    glColor3ub(130,65,65);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(181,110,110 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
    /////2nd bird////
    glBegin(GL_POLYGON);
    glColor3ub(130,65,65 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(130,65,65);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(181,110,110 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

    GLfloat mmm=0.062f;
    GLfloat nnn=.801f;
    GLfloat radiusmmm =.01f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(130,65,65);
    glVertex2f(mmm, nnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
            nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    /////3rd bird/////
    glBegin(GL_POLYGON);
    glColor3ub(130,65,65 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(130,65,65);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(181,110,110 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

    GLfloat mmmm=-0.638f;
    GLfloat nnnn=.801f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(130,65,65);
    glVertex2f(mmmm,nnnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
            nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    ////4th bird////
    GLfloat mmmmm=-0.518f;
    GLfloat nnnnn=.801f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(130,65,65);
    glVertex2f(mmmmm, nnnnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
            nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(130,65,65 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(130,65,65);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(181,110,110 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();


}

void train()
{
    glBegin(GL_QUADS);
    glColor3ub(91, 11, 11);

    ///body 1
    glVertex2f(-0.6,0.3);
    glVertex2f(-0.8,0.3);
    glVertex2f(-0.8,0.2);
    glVertex2f(-0.6,0.2);

    ///body 2
    glVertex2f(-0.39,0.3);
    glVertex2f(-0.59,0.3);
    glVertex2f(-0.59,0.2);
    glVertex2f(-0.39,0.2);

    ///body 3
    glVertex2f(-0.18,0.3);
    glVertex2f(-0.38,0.3);
    glVertex2f(-0.38,0.2);
    glVertex2f(-0.18,0.2);

    ///body 3 design 1
    glVertex2f(-0.16,0.23);
    glVertex2f(-0.18,0.25);
    glVertex2f(-0.18,0.2);
    glVertex2f(-0.16,0.2);

    ///body 3 design 2
    glVertex2f(-0.2,0.33);
    glVertex2f(-0.22,0.33);
    glVertex2f(-0.22,0.3);
    glVertex2f(-0.2,0.3);

    glEnd();

    ///train window
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);

    ///body 1 window
    glVertex2f(-0.74,0.27);
    glVertex2f(-0.78,0.27);
    glVertex2f(-0.78,0.24);
    glVertex2f(-0.74,0.24);

    glVertex2f(-0.68,0.27);
    glVertex2f(-0.72,0.27);
    glVertex2f(-0.72,0.24);
    glVertex2f(-0.68,0.24);

    glVertex2f(-0.62,0.27);
    glVertex2f(-0.66,0.27);
    glVertex2f(-0.66,0.24);
    glVertex2f(-0.62,0.24);

    ///body 2 window
    glVertex2f(-0.53,0.27);
    glVertex2f(-0.57,0.27);
    glVertex2f(-0.57,0.24);
    glVertex2f(-0.53,0.24);

    glVertex2f(-0.47,0.27);
    glVertex2f(-0.51,0.27);
    glVertex2f(-0.51,0.24);
    glVertex2f(-0.47,0.24);

    glVertex2f(-0.41,0.27);
    glVertex2f(-0.45,0.27);
    glVertex2f(-0.45,0.24);
    glVertex2f(-0.41,0.24);

    ///body 3 window
    glVertex2f(-0.32,0.27);
    glVertex2f(-0.36,0.27);
    glVertex2f(-0.36,0.24);
    glVertex2f(-0.32,0.24);

    glVertex2f(-0.26,0.27);
    glVertex2f(-0.3,0.27);
    glVertex2f(-0.3,0.24);
    glVertex2f(-0.26,0.24);

    glVertex2f(-0.2,0.27);
    glVertex2f(-0.24,0.27);
    glVertex2f(-0.24,0.24);
    glVertex2f(-0.2,0.24);

    glEnd();

}

/////////////////////////////////////////////////////////////// Animation Part Start///////////////////////////////////////
void rainAnimation()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(positionRain, positionRain, 0.0f);
    fullrain();
    glPopMatrix();
    glLoadIdentity();
}

void boatAnimation()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(positionBoat, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
}

void cloud1Animation()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(positionCloud1, 0.0f, 0.0f);
    cloud1();
    glPopMatrix();
    glLoadIdentity();
}

void cloud2Animation()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(positionCloud2, 0.0f, 0.0f);
    cloud2();
    glPopMatrix();
    glLoadIdentity();
}

void standingBoatAnimation()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0f, positionStandinfBoat, 0.0f);
    standingBoat();
    glPopMatrix();
    glLoadIdentity();
}

void standingBoatAnimation2()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0f, positionStandinfBoat, 0.0f);
    nightBoat2();
    glPopMatrix();
    glLoadIdentity();
}

void birdAnimation()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(positionBird, 0.0f, 0.0f);
    bird();
    glPopMatrix();
    glLoadIdentity();
}

void trainAnimation()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(positionTrain, 0.0f, 0.0f);
    train();
    glPopMatrix();
    glLoadIdentity();
}

void dayDisplay(int x)
{
    glutDisplayFunc(day);
}
void day()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    sun();
    cloud1Animation();
    cloud2Animation();
    trainAnimation();
    hill();
    river();
    standingBoatAnimation();
    boatAnimation();
    field();
    fence();
    tree();
    well();
    way();
    straw();
    house();
    birdAnimation();
    glutTimerFunc(10000000, dayRainDisplay, 0);
    glFlush();

}



void dayRainDisplay(int x)
{
    glutDisplayFunc(dayRain);
}

void dayRain()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    //sun();
    cloud1Animation();
    cloud2Animation();
    trainAnimation();
    hill();
    river();
    standingBoatAnimation();
    //boatAnimation();
    field();
    fence();
    tree();
    well();
    way();
    straw();
    house();
    rainAnimation();

    glutTimerFunc(10000000, nightDispaly, 0);

    glFlush();
}

void nightDispaly(int x)
{
    glutDisplayFunc(night);
}
void night()
{
    glClearColor(1.0,1.0,1.0,1.0);
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    nightSky();
    star();
    moon();
    //cloud1Animation();
    //cloud2Animation();
    nightHill();


    glEnable(GL_LIGHTING);//Enable Light Effect

    GLfloat global_ambient[] = {0.0, 1.0, 2, 0.1}; //ambient RGBA intensity of light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
    river();
    glDisable(GL_LIGHTING);

    standingBoatAnimation();
    standingBoatAnimation2();

    nightboat();
    nightField();
    nightFence();
    nightTree();
    nightWell();
    nightway();
    nigthStraw();
    nightHouse();

    glutTimerFunc(10000000, nightRainDispaly, 0);

    glFlush();
}

void nightRainDispaly(int x)
{
    glutDisplayFunc(nightRain);
}

void nightRain()
{
    glClearColor(1.0,1.0,1.0,1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    nightSky();

    nightHill();


    glEnable(GL_LIGHTING);//Enable Light Effect

    GLfloat global_ambient[] = {0.0, 1.0, 2, 0.1}; //ambient RGBA intensity of light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
    river();
    glDisable(GL_LIGHTING);

    standingBoatAnimation();
    standingBoatAnimation2();

    nightboat();
    nightField();
    nightFence();
    nightTree();
    nightWell();
    nightway();
    nigthStraw();
    nightHouse();
    rainAnimation();
    glutTimerFunc(10000000, dayDisplay, 0);

    glFlush();
}


void display(void)
{

    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-20);

    glFlush();
    glutSwapBuffers();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth( 1.0 );
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHT0);
}

void idle()
{
    glutPostRedisplay();
}

void sound()
{


    PlaySound("day.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    PlaySound("night.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    PlaySound("rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);


}


void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case  'D':
        glutDestroyWindow(1);
        glutInitWindowSize(1200, 600);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(day);
        PlaySound("day.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;

    case 'R':
        glutDestroyWindow(1);
        glutInitWindowSize(1200, 600);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);

        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(dayRain);
        PlaySound("rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;

    case 'N':
        glutDestroyWindow(1);
        glutInitWindowSize(1200, 600);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(night);
        PlaySound("night.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;
    case  'T':
        glutDestroyWindow(1);
        glutInitWindowSize(1200, 600);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1240)/2,(glutGet(GLUT_SCREEN_HEIGHT)-750)/2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(nightRain);
        PlaySound("rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;
    case 'E':
        exit(0);
        break;
    case  'd':
        glutDestroyWindow(1);
        glutInitWindowSize(1200, 600);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(day);
        PlaySound("day.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;

    case 'r':
        glutDestroyWindow(1);
        glutInitWindowSize(1200, 600);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);

        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(dayRain);
        PlaySound("rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;

    case 'n':
        glutDestroyWindow(1);
        glutInitWindowSize(1200, 600);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(night);
        PlaySound("night.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;
    case  't':
        glutDestroyWindow(1);
        glutInitWindowSize(1200, 600);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1240)/2,(glutGet(GLUT_SCREEN_HEIGHT)-750)/2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(nightRain);
        PlaySound("rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;
    case 'e':
        exit(0);
        break;


    default:
        break;
    }
    glutPostRedisplay();



}

int main(int argc,char ** argv)
{
    cout<<endl <<"******************** Welcome to village scenario********************" << endl << endl;
    cout<<"                    -created by Aiub CS student-" <<endl<<"Leon Md shahidul islam, Murad Abdullah al, Rafi Md Rafatur Raiyan, Hossain Md sabbir"<<endl<<endl<<endl;
    cout<<"Press D: for Day" <<endl<<endl;
    cout<<"Press N: for Night"<<endl<<endl;
    cout<<"Press R: for DayRain"<<endl<<endl;
    cout<<"Press T: for NightRain "<<endl<<endl;
    cout<<"Press E : for Exit from the program "<<endl<<endl;
    cout<<"Sound are attached with every scene"<<endl<<endl;
    cout<<endl <<"***********************************END********************************" << endl << endl;




    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
    glutCreateWindow("village scenario");


    glutDisplayFunc(display);



    glutKeyboardFunc(handleKeypress);

    glutTimerFunc(100, updateRain, 0);
    glutTimerFunc(100, updateBoat, 0);
    glutTimerFunc(100, updateCloud1, 0);
    glutTimerFunc(100, updateCloud2, 0);
    glutTimerFunc(100, updateBird, 0);
    glutTimerFunc(100, updateTrain, 0);
    glutTimerFunc(100, updateStandingBoat, 0);


    init();

    glutMainLoop();
    return 0;

}

