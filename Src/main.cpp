/* Module      : MainFile.cpp
 * Author      :
 * Email       :
 * Course      : Computer Graphics
 *
 * Description :
 *
 *
 * Date        :
 *
 * History:
 * Revision      Date          Changed By
 * --------      ----------    ----------
 * 01.00         ?????          ???
 * First release.
 *
 */

/* -- INCLUDE FILES ------------------------------------------------------ */
#include <iostream>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
using namespace std;

void myKeyboard(unsigned char theKey, int x = NULL, int y = NULL);
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

/* -- LOCAL VARIABLES ---------------------------------------------------- */

/* ----------------------------------------------------------------------- */
/* Function    : void drawDot( GLint x, GLint y )
 *
 * Description : Draw a point at location (x, y) in the window.
 *
 * Parameters  : GLint x : X coordinate of point to draw.
 *               GLint y : X coordinate of point to draw.
 *
 * Returns     : void
 */

void drawDot(GLint x, GLint y)
{
}

/* ----------------------------------------------------------------------- */
/* Function    : void myInit( void )
 *
 * Description : Initialize OpenGL and the window where things will be
 *               drawn.
 *
 * Parameters  : void
 *
 * Returns     : void
 */

void myInit(void)
{
    // glClearColor(1.0, 1.0, 1.0, 0.0);
    glClearColor(0.0f, 0.4f, 0.4f, 1.0f);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

/* ----------------------------------------------------------------------- */
/* Function    : void myDisplay( void )
 *
 * Description : This function gets called everytime the window needs to
 *               be redrawn.
 *
 * Parameters  : void
 *
 * Returns     : void
 */
bool btriangle = true;
bool bPolygon = false;
GLintPoint peak(170, 200);
int height = 100;
int width = 100;
void myDisplay()
{
    cout << btriangle << endl;
    glClear(GL_COLOR_BUFFER_BIT);
    if (btriangle)
        glBegin(GL_TRIANGLES);
    else if (bPolygon)
        // glBegin(GL_POLYGON_SMOOTH);
        glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_POINTS);

    glColor3f(1.0f, 0.2f, 0.0f);

    if (!bPolygon)
    {
        glVertex2i(80, 120);
        glVertex2i(160, 120);
        glVertex2i(120, 180);
    }
    else
    {
        glVertex2i(peak.x, peak.y); // draw shell of house
        glVertex2i(peak.x + width / 2, peak.y - 3 * height / 8);
        glVertex2i(peak.x + width / 2, peak.y - height);
        glVertex2i(peak.x - width / 2, peak.y - height);
        glVertex2i(peak.x - width / 2, peak.y - 3 * height / 8);
    }
    glEnd();
    glFlush();
}
void myKeyboard(unsigned char theKey, int x, int y)
{
    switch (theKey)
    {

    case 'a':
        bPolygon = !bPolygon;
        btriangle = !bPolygon;
        break;
    case 'd':
        bPolygon = false;
        btriangle = false;
        break;
    case 'e':
        exit(-1); // terminate the program
        // cout << "keyboard pressed" << endl;

    default:
        break; // do nothing
    }
    glutPostRedisplay();
}
/* ----------------------------------------------------------------------- */
/* Function    : int main( int argc, char** argv )
 *
 * Description : This is the main function. It sets up the rendering
 *               context, and then reacts to user events.
 *
 * Parameters  : int argc     : Number of command-line arguments.
 *               char *argv[] : Array of command-line arguments.
 *
 * Returns     : int : Return code to pass to the shell.
 */

int main(int argc, char *argv[])
{
    // Initialize GLUT.
    glutInit(&argc, argv);
    // Set the mode to draw in.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set the window size in screen pixels.
    glutInitWindowSize(640, 480);
    // Set the window position in screen pixels.
    glutInitWindowPosition(100, 150);
    // Create the window.
    glutCreateWindow("Lab");
    // Set the callback funcion to call when we need to draw something.
    glutDisplayFunc(myDisplay);
    // Listen for keyboard events
    glutKeyboardFunc(myKeyboard);
    // Initialize some things.
    myInit();
    // Now that we have set everything up, loop responding to events.
    glutMainLoop();
}

/* ----------------------------------------------------------------------- */
