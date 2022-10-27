
/* -- INCLUDE FILES ------------------------------------------------------ */
#include <iostream>
#include <cmath>
#include <fstream>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
using namespace std;
void myKeyboard(unsigned char theKey, int x, int y);
/* -- DATA STRUCTURES ---------------------------------------------------- */
// Our point class.
class GLintPoint
{
public:
    int x;
    int y;
    GLintPoint(int x, int y) : x(x), y(y) {}
};

/* -- GLOBAL VARIABLES --------------------------------------------------- */
double cur_Vp_L = 0;
double cur_Vp_R = 1024;
double cur_Vp_B = 0;
double cur_Vp_T = 780;
/* -- LOCAL VARIABLES ---------------------------------------------------- */
void drawDot(GLint x, GLint y)
{
}
void myInit(void)
{
    glClearColor(0.0f, 0.4f, 0.4f, 1.0f);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    gluOrtho2D(0.0, 1024.0, 0.0, 768.0);
    glViewport(0, 640, 0, 480);
}

/* ------------------------------PARAMETERS----------------------------------------- */
GLintPoint A[] = {
    GLintPoint(600, 300),
    GLintPoint(500.0, 335.0),
    GLintPoint(310.0, 400.0),
    GLintPoint(310.0, 400.0),
    GLintPoint(185.0, 350.0),
    GLintPoint(40.0, 300.0),
    GLintPoint(40.0, 40.0),
    GLintPoint(600.0, 40.0),
    GLintPoint(600.0, 40.0)};
GLintPoint B[] = {
    GLintPoint(600.0, 300.0),
    GLintPoint(450.0, 300.0),
    GLintPoint(400.0, 350.0),
    GLintPoint(200.0, 350.0),
    GLintPoint(150.0, 300.0),
    GLintPoint(40.0, 300.0),
    GLintPoint(40.0, 200.0),
    GLintPoint(600.0, 200.0),
};
static const float pi = 3.1415926535897932384626433832795029f;

float t = 0.0f; // t stands for time. I supposed
float deltaT = 0.001f;

bool bRunning = true;
int i_NumFrame = 200;
int i_frame = 0;

double dx = 1;
double dy = 1;
double d_moveSpeed = 2.2;
double sx = 1;
double sy = 1;
double scaleRate = 1.2;
float f_angle = 0;
int iRotateSpeed = 10;
//--------------- setWindow ---------------------
void setWindow(float left, float right, float bottom, float top)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);
}
//---------------- setViewport ------------------
void setViewport(float left, float right, float bottom, float top)
{
    glViewport(left, bottom, right - left, top - bottom);
}
//---------------- Display utility functions  ------------------
void drawHouse()
{

    glBegin(GL_LINE_LOOP);
    for (auto point : A)
    {
        glVertex2f(point.x, point.y);
    }
    glEnd();
    glFlush();
}
void drawCar()
{
    glBegin(GL_LINE_LOOP);
    for (auto point : B)
    {
        glVertex2f(point.x, point.y);
    }
    glEnd();
    glFlush();
}
float tweening(float a, float b, float t)
{
    return (1 - t) * a + t * b;
}
void Animation_Naive() // without double Buffer
{
    glBegin(GL_LINE_LOOP);
    if (t == 0.0f || t + deltaT < 0.0f || t == 1.0f || t + deltaT > 1.0f)
        if (t == 0.0f || t + deltaT < 0.0f)
        {
            deltaT = 0.005;
        }
        else if (t == 1.0f || t + deltaT > 1.0f)
        {
            deltaT = -0.005;
        }

    // cout << "t: " << t << ", deltaT: " << deltaT << endl;
    for (int i = 0; i < 8; i++)
    {
        // cout << "t: " << t << ", deltaT: " << deltaT << endl;
        float pX = tweening(A[i].x, B[i].x, t);
        float pY = tweening(A[i].y, B[i].y, t);
        glVertex2f(pX, pY);
    }
    glEnd();
    glFlush();
}
void drawFuncGraph()
{
    setWindow(-50.0, 250.0, -50.0, 50.0);
    int multiplier = 6;
    setViewport(cur_Vp_L + 150, cur_Vp_R + 150, cur_Vp_B, cur_Vp_T);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.5, 0.1, 1);
    for (GLfloat x = -14.0; x < 200.0; x += 5)
        glVertex2f(x, x * x * x + 2 * x * x + 3);
    glEnd();

    glBegin(GL_LINE_STRIP);
    setViewport(cur_Vp_L - 100 * multiplier, cur_Vp_R + 100 * multiplier, cur_Vp_B - 100 * multiplier, cur_Vp_T + 100 * multiplier);
    glColor3f(0.6, 0.6, 0.4);
    for (GLfloat x = -14.0; x < 200.0; x += 5)
        glVertex2f(x, 2 * sin(x) + 0.5 * cos(x));
    glEnd();
    glFlush();
}
void Chap5()
{
    drawHouse();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // load CT to ident matrix

    // translate

    glTranslated(dx, dy, 1.0); // set CT to CT*translation;
    // rotate
    glRotated(f_angle, 0.0, 0.0, 1.0); // set CT to CT * (2D rotation)
    // glRotated(f_angle, 10.0, 10.0, 1.0); // set CT to CT * (2D rotation)
    // scale
    glScaled(sx, sy, 1.0);
}
void drawPolyLine(const char *filePath)
{

    fstream instream;
    instream.open(filePath);
    if (instream.fail())
    {
        cout << "Error: Could not open file " << filePath << endl;
        return;
    }

    int numpolys = 0;
    int numLines = 0;
    double x, y;
    instream >> numpolys;

    setWindow(0.0, 780.0, 0.0, 600.0);
    setViewport(0, 640, 0, 480);
    glColor3f(0.2, 0.1, 1);
    for (int j = 0; j < numpolys; j++) // read each polyline
    {
        instream >> numLines;
        glBegin(GL_LINE_STRIP); // draw the next polyline
        for (int i = 0; i < numLines; i++)
        {
            instream >> x >> y; // read the next x, y pair
            glVertex2f(x, y);
        }
        glEnd(); // end
    }
    glFlush();
    instream.close();
}
// Complicated Curve - 5th Gen Koch Snowflake, cardioid, rose & spiral parametric curves
void drawCardioid()
{
    glBegin(GL_LINE_STRIP);
    static const float r = 50.0f;
    for (float angle = 0.0f; angle < (pi * 2.0f); angle += 0.05f)
    {
        // f(phi) = 2r(1-cos(phi)) // phi is the angle.
        float x = 2.0f * r * cos(angle) * (1.0f - cos(angle));
        float y = 2.0f * r * sin(angle) * (1.0f - cos(angle));
        // cout << "x: " << x << "y: " << y << endl;
        glVertex2f(x + 500, y + 400);
    }
    glEnd();
}
void drawRose()
{
    glColor3f(1, 0.0f, 0);
    int k = 4;
    float a = 50; // amplitude
    glBegin(GL_LINE_STRIP);
    float r = 60.0f;
    for (float angle = 0.0f; angle < (pi * 2.0f * k); angle += 0.05f)
    {
        r -= 5.0f;
        float x = a * cos(k * angle) * cos(angle);
        float y = a * cos(k * angle) * sin(angle);
        glVertex2f(x + 450, y + 100);
    }
    glEnd();
    glColor3f(1, 1.0f, 1);
}
void draw_SpiralParametricCurvers()
{
    int k = 1;
    glColor3f(0, 0.0f, 0);
    glBegin(GL_LINE_STRIP);
    float r = 60.0f;
    for (float angle = 0.0f; angle < (pi * 2.0f * k); angle += 0.05f)
    {
        r -= 5.0f;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(x + 700, y + 200);
    }
    glEnd();
    glColor3f(1, 1.0f, 1);

    // glFlush();
}
void Chap3()
{
    drawCardioid();
    drawRose();
    draw_SpiralParametricCurvers();
}
void Chap4()
{
    Animation_Naive();
    drawHouse();
    drawCar();
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear Screen to draw new shape, hence creating illusion of animation.
    Chap5();
    glutSwapBuffers();
    t += deltaT;
    glutPostRedisplay(); // tell glut that it's window's need to be redrawn
}
void myKeyboard(unsigned char theKey, int x, int y)
{
    switch (theKey)
    {
    case 27:
        cout << "Exit program" << endl;
        bRunning = false;
        exit(-1); // terminate the program
        break;
    case 'w':
        cout << "up" << endl;
        cur_Vp_T += 60;
        cur_Vp_B += 60;
        dy += d_moveSpeed;

        break;
    case 's':
        cout << "down" << endl;
        cur_Vp_T -= 60;
        cur_Vp_B -= 60;
        dy -= d_moveSpeed;

        break;
    case 'a':
        // arrow left
        cout << "left" << endl;
        cur_Vp_R -= 60;
        cur_Vp_L -= 60;
        dx -= d_moveSpeed;
        break;
    case 'd':
        cout << "right" << endl;
        cur_Vp_R += 60;
        cur_Vp_L += 60;
        dx += d_moveSpeed;

        break;
    case 'z':
        cout << "zoom in" << endl;
        cur_Vp_R += 40;
        cur_Vp_L -= 40;
        cur_Vp_T += 40;
        cur_Vp_B -= 40;
        sx *= scaleRate;
        sy *= scaleRate;
        break;
    case 'x':
        cout << "zoom out" << endl;
        cout << cur_Vp_R << " " << cur_Vp_T << " " << endl;
        if (cur_Vp_R >= 530 && cur_Vp_T >= 300)
        {
            cur_Vp_R -= 40;
            cur_Vp_L += 40;
            cur_Vp_T -= 40;
            cur_Vp_B += 40;
        }
        sx /= scaleRate;
        sy /= scaleRate;
        break;
    case 'r':
        f_angle += iRotateSpeed;
        break;
    case 't':
        f_angle -= iRotateSpeed;
        break;
    default:
        break; // do nothing
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    // Initialize GLUT.
    glutInit(&argc, argv);
    // Set the mode to draw in.
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // Set the window size in screen pixels.
    glutInitWindowSize(640, 480);
    // Set the window position in screen pixels.
    glutInitWindowPosition(100, 60);
    // Create the window.
    glutCreateWindow("Lab");
    // reDraw window
    glutDisplayFunc(myDisplay);

    // Listen for keyboard events
    glutKeyboardFunc(myKeyboard);
    // Initialize some things.
    myInit();
    // Now that we have set everything up, loop responding to events.
    glutMainLoop();
}

/* ----------------------------------------------------------------------- */
