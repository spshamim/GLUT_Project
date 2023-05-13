#include<cstdio>
#include <windows.h>
#include<math.h>
#include <vector>
#include <cstdlib>
# define PI 3.14159265358979323846
#include <GL/gl.h>
#include <GL/glut.h>
#include<MMSystem.h>
#include <cmath>
#include<vector>

float sun_move = 0.0f;
float cloud_move = 0.0f;
float cloud_move1 = 0.0f;
float cloud_move2 = 0.0f;
float main_Bird = 0.0f;
float boat1_move = 0.0f;
float boat2_move = 0.0f;
float STAND_BOAT_move = 0.0f;
float STAND_BOAT_move2 = 0.0f;
bool isBoatMoving = true;
float boatPosition = 0.0f;
bool isNightMode = false;
bool showDisplay1 = true;
bool inDisplay1 = true;

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

bool start1 = false;
bool start2 = false;
bool start3 = false;

void playSound()
{
    if(inDisplay1)
    {
        return;
    }
    if (isNightMode)
    {
        PlaySound("1224.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    }
    else
    {
        PlaySound("bird-2.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'n':
        start1 = true;
        isBoatMoving = false;
        isNightMode = true;
        playSound();
        break;
    case 'd':
        start2 = true;
        isBoatMoving = true;
        isNightMode = false;
        playSound();
        break;
    case 's':
        showDisplay1 = !showDisplay1;
        inDisplay1 = !inDisplay1;

        if(showDisplay1)
        {
            PlaySound(NULL, NULL, SND_ASYNC);
        }
        else
        {
            playSound();
        }
        glutPostRedisplay();
        break;
    }
}

GLfloat position22 = 0.0f;
GLfloat speed22 = 0.007f;
void Bird(int value)
{
    if(position22 > 1.0)
        position22 =-1.0f;
    position22 += speed22;
    glutPostRedisplay();
    glutTimerFunc(100, Bird, 0);
}

void mainBird()
{
//----------1st Bird------------
    glBegin(GL_POLYGON);
    glColor3ub(76, 187, 23);
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 53, 36);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 53, 36);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();

    int i;
    GLfloat m1=0.182f;//radiusmm=1,nn,mm=1
    GLfloat n1=0.801f;
    GLfloat radius1 =0.01f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(140, 71, 54);
    glVertex2f(m1, n1);//Center of Circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            m1 + (radius1 * cos(i *  twicePi / triangleAmount)),
            n1 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

//-----------2nd Bird------------
    glBegin(GL_POLYGON);
    glColor3ub(18, 173, 43);
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 53, 36);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 53, 36);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

    GLfloat m2=0.062f;//mmm,nnn,radiusmmm=2
    GLfloat n2=0.801f;
    GLfloat radius2 =0.01f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(140, 71, 54);
    glVertex2f(m2, n2);//Center of Circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            m2 + (radius2 * cos(i *  twicePi / triangleAmount)),
            n2 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

//-----------3rd Bird---------------
    glBegin(GL_POLYGON);
    glColor3ub(79, 179, 59);
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 53, 36);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 53, 36);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

    GLfloat m3=-0.638f;//mmmm,nnnn=3,radiusmmm=2
    GLfloat n3=0.801f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(140, 71, 54);
    glVertex2f(m3,n3);//Center of Circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            m3 + (radius2 * cos(i *  twicePi / triangleAmount)),
            n3 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

//--------------4th bird-------------
    glBegin(GL_POLYGON);
    glColor3ub(79, 179, 59);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 53, 36);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 53, 36);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();

    GLfloat m4=-0.518f;//mmmmm,nnnnn=4, radiusmm=1
    GLfloat n4=0.801f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(140, 71, 54);
    glVertex2f(m4, n4);//Center of Circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            m4 + (radius1 * cos(i *  twicePi / triangleAmount)),
            n4 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
//------------------------------------------------------
//------------------ Sun ---------------------
GLfloat position4 = 0.0f;
GLfloat speed4 =-0.01f;


void mainSun()
{

    float radius = 0.1;
    float center[] = { -0.2, 0.88 };

    glColor3ub(253, 184, 19);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * radius + center[0], sin(degInRad) * radius + center[1]);
    }
    glEnd();
    glFlush();
}
//----------------------------------------
//-------------- Moon -------------------
void moon()
{

    float radius = 0.1;
    float center[] = { 0.8, 0.88 };

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * radius + center[0], sin(degInRad) * radius + center[1]);
    }
    glEnd();
    glFlush();
}
//----------------------------------------
//-------------- Sky -------------------
void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(51, 204, 255);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3ub(205, 240, 255);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(-1.0f, -0.15f);
    glEnd();
}
void sky2()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 51, 204);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}
//----------------------------------------
//-------------- Star -------------------
/*void Stars()
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
}*/

//-------------------------------------------
//------------ Cloud ---------------
GLfloat position2 = 0.0f;
GLfloat speed2 = 0.004f;
void Cloud(int value)//cloud=Cloud
{
    if(position2 > 1.0)
        position2 =-1.0f;
    position2 += speed2;
    glutPostRedisplay();
    glutTimerFunc(100, Cloud, 0);
}
GLfloat position1 = 1.0f;
GLfloat speed1 = - 0.005f;
//--------- Cloud1 ----------
void cloud1()
{
    int i;

    GLfloat x=0.5f;
    GLfloat y=0.86f;
    GLfloat radius =0.05f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=0.55f;
    GLfloat b=0.83f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=0.45f;
    GLfloat d=0.83f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=0.52f;
    GLfloat f=0.8f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=0.6f;
    GLfloat h=0.82f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i *  twicePi / triangleAmount)),
            h+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
//--------- Cloud2 ----------
void cloud2()
{
    int i;

    GLfloat x=-0.5f;
    GLfloat y=0.86f;
    GLfloat radius =0.05f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=-0.55f;
    GLfloat b=0.83f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=-0.45f;
    GLfloat d=0.83f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=-0.52f;
    GLfloat f=0.8f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=-0.6f;
    GLfloat h=0.82f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i *  twicePi / triangleAmount)),
            h+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
//--------- Cloud3 ----------
void cloud3()
{
    // glLoadIdentity();
    int i;

    GLfloat x=0.0f;
    GLfloat y=0.86f;
    GLfloat radius =0.05f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=0.05f;
    GLfloat b=0.83f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=-0.05f;
    GLfloat d=0.83f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=0.02f;
    GLfloat f=0.8f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=0.1f;
    GLfloat h=0.82f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g+ (radius * cos(i *  twicePi / triangleAmount)),
            h+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Water()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.75f, 1.0f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.66f, 1.0f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.7f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.8f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.66f, 1.0f);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.9f);
    glEnd();
}

void Water_Side_Ground()
{
    glBegin(GL_POLYGON);
    glColor3f(0.65f, 0.53f, 0.41f);
    glVertex2f(1.0f, -0.54f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-1.0f, -0.54f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.54f, 0.41f, 0.35f);
    glVertex2f(1.0f, -0.58f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-1.0f, -0.58f);
    glEnd();
}

void Water_Side_Field()
{
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.8f, 0.2f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(1.0f, -0.58f);
    glVertex2f(-1.0f, -0.58f);
    glVertex2f(-1.0f, -0.35f);
    glEnd();
}

void road()
{
    glBegin(GL_QUADS);
    glColor3f(0.76f, 0.7f, 0.50f);
    glVertex2f(-1.0f, -0.18f);
    glVertex2f(1.0f, -0.18f);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(-1.0f, -0.35f);
    glEnd();

}

void ground_2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.8f, 0.2f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.0f, -0.18f);
    glVertex2f(-1.0f, -0.18f);
    glVertex2f(-1.0f, -0.15f);
    glEnd();
}

void House()
{
    glBegin(GL_POLYGON);
    glColor3ub(205, 153, 0);
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
//------------------------------------
//--------------main door-----------
    glBegin(GL_POLYGON);
    glColor3ub(104, 53, 0);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);
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
//--------------------------------------------
//---------------left window---------------
    glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.38f,0.05f);
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
//------------------------------------
//------------2nd door-------------
    glBegin(GL_POLYGON);
    glColor3ub(104, 53, 0);
    glVertex2f(-0.51f,0.12f);
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
//---------------------------------------------
//----------------rightwindow---------------
    glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.2f,0.05f);
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

void House2()
{
    glBegin(GL_POLYGON);
    //glColor3ub(205, 153, 0);
    glColor3ub(230, 120, 105);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.58f,0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(204, 153, 0);
    glColor3ub(230, 120, 105);
    glVertex2f(-0.49f,0.2f);
    glVertex2f(-0.13f,0.2f);
    glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.49f,-0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 120, 105);
    //glColor3ub(204, 153, 0);
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
//------------------------------------
//--------------main door-----------
    glBegin(GL_POLYGON);
    glColor3ub(104, 53, 0);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);
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
//--------------------------------------------
//---------------left window---------------
    glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.38f,0.05f);
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
//------------------------------------
//------------2nd door-------------
    glBegin(GL_POLYGON);
    glColor3ub(104, 53, 0);
    glVertex2f(-0.51f,0.12f);
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
//---------------------------------------------
//----------------rightwindow---------------
    glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.2f,0.05f);
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

void chorki()
{
    glLineWidth(5);

    glBegin(GL_LINES); // left line
    glColor3ub(0, 0, 0);
    glVertex2f(0.55f, -0.17f);
    glVertex2f(0.6f, 0.15f);
    glEnd();

    glBegin(GL_LINES); // left to right line 1
    glColor3ub(0, 0, 0);
    glVertex2f(0.55f, -0.17f);
    glVertex2f(0.64f, -0.12f);
    glEnd();

    glBegin(GL_LINES); // left to right line 2
    glColor3ub(0, 0, 0);
    glVertex2f(0.56f, -0.12f);
    glVertex2f(0.635f, -0.07f);
    glEnd();

//////////////////////////////////////////////

    glBegin(GL_LINES); // right line
    glColor3ub(0, 0, 0);
    glVertex2f(0.65f, -0.17);
    glVertex2f(0.6f, 0.15f);
    glEnd();

    glBegin(GL_LINES); // right to left line 1
    glColor3ub(0, 0, 0);
    glVertex2f(0.65f, -0.17);
    glVertex2f(0.56f, -0.12f);
    glEnd();

    glBegin(GL_LINES); // right to left line 2
    glColor3ub(0, 0, 0);
    glVertex2f(0.64f, -0.12f);
    glVertex2f(0.565f, -0.07f);
    glEnd();


}

void chorki_fan()
{
    glPushMatrix();

    glTranslatef(0.6f, 0.14f, 0.0f);

    static float angle = 0.0f;
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    angle += 1.0f;

    glTranslatef(-0.6f, -0.24f, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3ub(192, 192, 192);
    glVertex2f(0.6f, 0.24f);
    glVertex2f(0.69f, 0.21f);
    glVertex2f(0.69f, 0.27f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(192, 192, 192);
    glVertex2f(0.6f, 0.24f);
    glVertex2f(0.5f, 0.21f);
    glVertex2f(0.5f, 0.27f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(192, 192, 192);
    glVertex2f(0.6f, 0.24f);
    glVertex2f(0.617f, 0.12f);
    glVertex2f(0.583f, 0.12f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(192, 192, 192);
    glVertex2f(0.6f, 0.23f);
    glVertex2f(0.617f, 0.36f);
    glVertex2f(0.583f, 0.36f);
    //glFlush();
    glEnd();
    glPopMatrix();
}

void update(int value)
{
    glutPostRedisplay();
    glutTimerFunc(35, update, 0);
}


//------------------------------------------
//------------ Grass ---------------------
void grass1()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(-0.8f, -0.58f);
    glVertex2f(-0.81f, -0.5f);
    glVertex2f(-0.78f, -0.58f);
    glVertex2f(-0.77f, -0.44f);
    glVertex2f(-0.745f, -0.58f);
    glVertex2f(-0.73f, -0.5f);
    glVertex2f(-0.75f, -0.58f);
    glEnd();
}

void grass2()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(-0.7f, -0.58f);
    glVertex2f(-0.71f, -0.5f);
    glVertex2f(-0.68f, -0.58f);
    glVertex2f(-0.67f, -0.44f);
    glVertex2f(-0.645f, -0.58f);
    glVertex2f(-0.63f, -0.5f);
    glVertex2f(-0.65f, -0.58f);
    glEnd();
}

void grass3()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(-0.6f, -0.58f);
    glVertex2f(-0.61f, -0.5f);
    glVertex2f(-0.58f, -0.58f);
    glVertex2f(-0.57f, -0.44f);
    glVertex2f(-0.545f, -0.58f);
    glVertex2f(-0.53f, -0.5f);
    glVertex2f(-0.55f, -0.58f);
    glEnd();
}

void grass4()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(-0.4f, -0.58f);
    glVertex2f(-0.41f, -0.5f);
    glVertex2f(-0.38f, -0.58f);
    glVertex2f(-0.37f, -0.44f);
    glVertex2f(-0.345f, -0.58f);
    glVertex2f(-0.33f, -0.5f);
    glVertex2f(-0.35f, -0.58f);
    glEnd();
}

void grass5()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.6f, -0.58f);
    glVertex2f(0.59f, -0.5f);
    glVertex2f(0.62f, -0.58f);
    glVertex2f(0.63f, -0.44f);
    glVertex2f(0.655f, -0.58f);
    glVertex2f(0.67f, -0.5f);
    glVertex2f(0.65f, -0.58f);
    glEnd();
}

void grass6()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass7()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass8()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass9()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass10()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass11()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass12()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass13()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass14()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass15()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass16()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass17()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}
void grass18()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}

void grass19()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
    glEnd();
}

void grass20()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0); // dark green color
    glVertex2f(0.4f, -0.58f);
    glVertex2f(0.39f, -0.5f);
    glVertex2f(0.42f, -0.58f);
    glVertex2f(0.43f, -0.44f);
    glVertex2f(0.455f, -0.58f);
    glVertex2f(0.47f, -0.5f);
    glVertex2f(0.45f, -0.58f);
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

    GLfloat x=-0.75f;
    GLfloat y=0.33f;
    GLfloat radius =0.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a=-0.68f;
    GLfloat b=0.31f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c=-0.81f;
    GLfloat d=0.31f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=-0.87f;
    GLfloat f=0.35f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=-0.61f;
    GLfloat h=0.35f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i *  twicePi / triangleAmount)),
            h+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat a1=-0.61f;
    GLfloat b1=0.4f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius * cos(i *  twicePi / triangleAmount)),
            b1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c1=-0.88f;
    GLfloat d1=0.4f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c1 + (radius * cos(i *  twicePi / triangleAmount)),
            d1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e1=-0.87f;
    GLfloat f1=0.44f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(e1, f1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e1 + (radius * cos(i *  twicePi / triangleAmount)),
            f1+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g1=-0.61f;
    GLfloat h1=0.4f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g1 + (radius * cos(i *  twicePi / triangleAmount)),
            h1+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat e11=-0.64f;
    GLfloat f11=0.44f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(e11, f11); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e11 + (radius * cos(i *  twicePi / triangleAmount)),
            f11+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e12=-0.75f;
    GLfloat f12=0.44f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
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
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-0.8f;
    GLfloat f123=0.5f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
    glVertex2f(e123, f123); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e123 + (radius * cos(i *  twicePi / triangleAmount)),
            f123+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat e1232=-0.7f;
    GLfloat f1232=0.5f;

    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);
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

void tree2()
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

    GLfloat x=-0.75f;
    GLfloat y=0.33f;
    GLfloat radius =0.06f;
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

    GLfloat a=-0.68f;
    GLfloat b=0.31f;

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

    GLfloat c=-0.81f;
    GLfloat d=0.31f;

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

    GLfloat e=-0.87f;
    GLfloat f=0.35f;

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

    GLfloat g=-0.61f;
    GLfloat h=0.35f;

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
    GLfloat a1=-0.61f;
    GLfloat b1=0.4f;

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

    GLfloat c1=-0.88f;
    GLfloat d1=0.4f;

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

    GLfloat e1=-0.87f;
    GLfloat f1=0.44f;

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

    GLfloat g1=-0.61f;
    GLfloat h1=0.4f;

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
    GLfloat e11=-0.64f;
    GLfloat f11=0.44f;

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

    GLfloat e12=-0.75f;
    GLfloat f12=0.44f;

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

    GLfloat e123=-0.8f;
    GLfloat f123=0.5f;

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
    GLfloat e1232=-0.7f;
    GLfloat f1232=0.5f;

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



void BOAT2()
{
    glBegin(GL_POLYGON); // 2nd
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
}


void Hill_1()
{
    glBegin(GL_POLYGON);
    //glColor3ub(102, 51, 0);
    glColor3f(0.4f, 0.6f, 0.1f);
    glVertex2f(-0.98f,0.0f);
    glVertex2f(-0.85f,0.5f);
    glVertex2f(-0.7f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.7f,0.0f);
    glVertex2f(-0.54f,0.5f);
    glVertex2f(-0.4f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.4f,0.0f);
    glVertex2f(-0.25f,0.5f);
    glVertex2f(-0.1f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f,0.0f);
    glVertex2f(0.05f,0.5f);
    glVertex2f(0.2f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.2f,0.0f);
    glVertex2f(0.35f,0.5f);
    glVertex2f(0.5f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.5f,0.0f);
    glVertex2f(0.64f,0.5f);
    glVertex2f(0.8f,0.0f);
    glEnd();
    /* --------------------------------------- */
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.7f, 0.2f);
    glVertex2f(-0.8f,0.0f);
    glVertex2f(-0.7f,0.4f);
    glVertex2f(-0.6f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.4f,0.4f);
    glVertex2f(-0.3f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f,0.0f);
    glVertex2f(-0.1f,0.4f);
    glVertex2f(-0.0f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.1f,0.0f);
    glVertex2f(0.2f,0.4f);
    glVertex2f(0.3f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.4f,0.0f);
    glVertex2f(0.5f,0.4f);
    glVertex2f(0.6f,0.0f);
    glEnd();
}

void STAND_BOAT()
{
    glBegin(GL_POLYGON); // 1st boat starting
    glColor3ub(0,0,0);
    glVertex2f(-0.2f, -0.8f);
    glVertex2f(-0.15f, -0.85f);
    glVertex2f(0.15f, -0.85f);
    glVertex2f(0.2f, -0.8f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 153, 0);
    glVertex2f(-0.13f, -0.8f);
    glVertex2f(-0.11f,-0.72f);
    glVertex2f(-0.088f, -0.68f);
    glVertex2f(0.13f, -0.68f);
    glVertex2f(0.14f, -0.71f);
    glVertex2f(0.15f, -0.8f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,25,25);
    glVertex2f(-0.038f, -0.63f);
    glVertex2f(-0.038f, -0.47f);
    glVertex2f(-0.035f, -0.45f);
    glVertex2f(0.064f, -0.47f);
    glVertex2f(0.065f, -0.49f);
    glVertex2f(0.065f, -0.65f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(0.0f, -0.68f);
    glVertex2f(0.0f, -0.45f);
    glVertex2f(0.01f, -0.45f);
    glVertex2f(0.01f, -0.68f);
    glEnd();
}

void STAND_BOAT2()
{
    glBegin(GL_POLYGON); // 2nd
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
}

void moveBoat2(float xUnits, float yUnits) // boat 2 translation
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(xUnits, yUnits, 0);
    BOAT2();
    glPopMatrix();
}

void night_effect()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glPointSize(6.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.9f, 0.9f);
    glVertex2f(-0.8f,0.8f);
    glVertex2f(-0.9f,0.71f);
    glVertex2f(-0.82f,0.7f);
    glVertex2f(-0.7f, 0.6f);
    glVertex2f(-0.65f, 0.9f);

    glVertex2f(0.9f, 0.9f);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.9f,0.55f);
    glVertex2f(0.82f,0.4f);
    glVertex2f(0.7f, 0.6f);
    glVertex2f(0.65f, 0.9f);

    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.0f, 0.65f);

    glVertex2f(-0.55f, 0.9f);
    glVertex2f(-0.45f,0.6f);
    glVertex2f(-0.4f,0.72f);
    glVertex2f(-0.33f,0.63f);
    glVertex2f(-0.33f,0.4f);
    glVertex2f(-0.22f, 0.45f);
    glVertex2f(-0.1f, 0.9f);

    glVertex2f(0.55f, 0.9f);
    glVertex2f(0.45f,0.6f);
    glVertex2f(0.4f,0.72f);
    glVertex2f(0.33f,0.63f);
    glVertex2f(0.33f,0.4f);
    glVertex2f(0.22f, 0.45f);
    glVertex2f(0.1f, 0.9f);
    glEnd();
}

void renderBoat()
{
    glPushMatrix();
    glTranslatef(0.0f, -0.33f, 0.0f);
    glTranslatef(boatPosition, 0.0, 0.0);
    glScalef(0.77f, 0.77f, 0.0f);
    STAND_BOAT();
    glPopMatrix();
}

void display2()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    sky();
    glPushMatrix();
    glTranslatef(0.0, sun_move,0.0);
    mainSun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(main_Bird, 0.0,0.0);
    mainBird();
    glPopMatrix();

    main_Bird += 0.006;
    {
        if(main_Bird > 1.5)
        {
            main_Bird = -1.2;
        }
    }
    glEnd();

    glPushMatrix();
    glTranslatef(cloud_move, 0.0,0.0);
    cloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud_move1, 0.0,0.0);
    cloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud_move2, 0.0,0.0);
    cloud3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud_move2, 0.0,0.0);
    cloud3();
    glPopMatrix();

    cloud_move += 0.003;
    {
        if(cloud_move > 1.5)
        {
            cloud_move = -1.2;
        }
    }

    cloud_move1 += 0.003;
    {
        if(cloud_move1 > 1.5)
        {
            cloud_move1 = -1.2;
        }
    }

    cloud_move2 += 0.003;
    {
        if(cloud_move2 > 1.5)
        {
            cloud_move2 = -1.2;
        }
    }
    glEnd();
    if (start3 == true)
    {
        glEnable(GL_LIGHT0);
        night_effect();
        moon();
    }

    if (start1 == true)
    {
        sun_move -= 0.011;
        if(sun_move < -0.95)
        {
            glDisable(GL_LIGHT0);
            start1=false;
            start3=true;
        }
    }
    if (start2 == true)
    {
        start3=false;
        glEnable(GL_LIGHT0);
        sun_move += 0.005;
        if (sun_move > 0.30)
        {
            glEnable(GL_LIGHT0);
        }
        if (sun_move > 0)
        {
            start2= false;
        }
    }

    glLoadIdentity();
    gluOrtho2D(-1.0, 0.7, -1.0, 0.7);
    glutSwapBuffers();

    ground_2();

    Water();
    Water_Side_Ground();
    Water_Side_Field();
    grass1();
    grass2();
    grass3();
    grass4();
    grass5();
    grass6();


    road();

    moveBoat2(-0.2f, -0.15f);//

    if (isBoatMoving)
    {
        renderBoat();
        boatPosition -= 0.005;
        if (boatPosition < -1.2)
        {
            boatPosition = 1.1;
        }
    }
    else
    {
        renderBoat();
    }

    glutSwapBuffers();

    glPushMatrix();
    glTranslatef(-0.05f, -0.149f, 0.0f); // moving down some unit
    Hill_1();
    glPopMatrix();

    glutSwapBuffers();

    glPushMatrix();
    glTranslatef(-0.45f, -0.075f, 0.0f); // moving down some unit
    glScalef(0.5f, 0.5f, 0.0f); // scale down some unit
    House2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.22f, -0.34f, 0.0f); // moving down some unit
    glScalef(0.8f, 0.8f, 0.0f); // scale down some unit
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.28f, -0.39f, 0.0f); // moving down some unit
    glScalef(0.5f, 0.5f, 0.0f); // scale down some unit
    tree2();
    glPopMatrix();

    glutSwapBuffers();


    //------------------------------
    glPushMatrix();
    glTranslatef(0.54f, -0.075f, 0.0f); // moving down some unit
    glScalef(0.5f, 0.5f, 0.0f); // scale down some unit
    House();
    glPopMatrix();

    //---------End House-------------------

    chorki();
    chorki_fan();

    /*----*/
    glPushMatrix();
    glTranslatef(-0.65f, 0.065f, 0.0f);
    grass7();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.75f, 0.09f, 0.0f);
    grass8();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.85f, 0.065f, 0.0f);
    grass9();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.95f, 0.085f, 0.0f);
    grass10();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.15f, 0.095f, 0.0f);
    grass11();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.25f, 0.035f, 0.0f);
    grass12();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.43f, 0.055f, 0.0f);
    grass13();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.53f, 0.09f, 0.0f);
    grass14();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.39f, 0.099f, 0.0f);
    grass15();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1.30f, 0.035f, 0.0f);
    grass16();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 0.065f, 0.0f);
    grass17();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.1f, 0.0f);
    grass18();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.95f, 0.095f, 0.0f);
    grass19();
    glPopMatrix();
    glutSwapBuffers();

    glEnd();
    glFlush(); // Render now

}

void display1()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    renderBitmapString(-0.8f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University-Bangladesh");

    renderBitmapString(-0.8f, 0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Course : Computer Graphics");
    renderBitmapString(-0.8f, 0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Course Teacher : Mahfujur Rahman");

    renderBitmapString(-0.8f, 0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "A Village Scenario");

    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(-0.8f, 0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Team members :");
    renderBitmapString(-0.6f, 0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Md. Shahriar Parvez Shamim, ID : 21-44998-2");
    renderBitmapString(-0.6f, -0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Md. Al Faiaz Rahman Fahim, ID : 21-45080-2");
    renderBitmapString(-0.6f, -0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Ashik Ahamed, ID : 21-45368-2");
    renderBitmapString(-0.6f, -0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Ahamad Safat, ID : 21-45017-2");
    renderBitmapString(-0.6f, -0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Amina Tazin, ID : 21-45141-2");

    glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(-0.8f, -0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Instruction:");
    renderBitmapString(-0.6f, -0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press S : Change Display");
    renderBitmapString(-0.6f, -0.8f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press D : Day Light View");
    renderBitmapString(-0.6f, -0.9f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press N : Night View");
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (showDisplay1)
    {
        display1();
    }
    else
    {
        display2();
    }

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1100,600);
    glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH)/2 - 1100/2,glutGet(GLUT_SCREEN_HEIGHT)/2 - 600/2);
    glutCreateWindow("Back to country side");
    renderBoat();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(35, update, 0);
    playSound();
    glutMainLoop();

    return 0;
}

