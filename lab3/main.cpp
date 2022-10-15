/* -- INCLUDE FILES ------------------------------------------------------ */
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>

const GLfloat PI=3.14159;

const int gen = 5;

GLfloat x_cu=0.0;
GLfloat y_cu=0.0;
/* -- DATA STRUCTURES ---------------------------------------------------- */
// Our point class.
class GLintPoint  {

};

void drawDot( GLint x, GLint y )  {
}

void myInit( void )  {
    glClearColor( 1.0, 1.0, 1.0, 0.0 );
    glColor3f( 0.0, 0.0, 0.0 );
    glLineWidth(3.0);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    //glOrtho( -10, 10, -100, 100, 0.0, 0.0 );
    gluOrtho2D (0, 0, 640, 480);

}

void drawKoch(GLfloat goc, GLfloat length, GLfloat n){
    // Chuyen goc sang radian
    GLfloat gocRad = PI*goc/180.0;
    // Tinh toa do diem moi thong qua goc ban dau, khoang cach 2 diem
    GLfloat x_moi = x_cu + length*cos(gocRad);
    GLfloat y_moi = y_cu + length*sin(gocRad);

    if(n==0){
        // Ve doan thang sau khi tinh dc toa do 2 diem
        glVertex2f(x_cu, y_cu);
        glVertex2f(x_moi, y_moi);

        x_cu = x_moi;
        y_cu = y_moi;
    }else{
        n--;
        length/=3;
        drawKoch(goc,length,n);

        goc +=60;
        drawKoch(goc,length,n);

        goc -=120;
        drawKoch(goc,length,n);

        goc +=60;
        drawKoch(goc,length,n);
        }
    }

void myDisplay( void ){
    int i =0;
        i++;
    glClear( GL_COLOR_BUFFER_BIT );
    glBegin(GL_LINES);
        x_cu=-1.0; y_cu=0.0;
        drawKoch(0,1.0,gen-1);
        x_cu=-0.5; y_cu=(sqrt(3.0)/-2.0);
        drawKoch(-240,1.0,gen-1);
        x_cu=0.0; y_cu=0.0;
        drawKoch(-120,1.0,gen-1);
    glEnd();
    glFlush();
}

int main( int argc, char *argv[] )  {
  // Initialize GLUT.
  glutInit( &argc, argv );
  // Set the mode to draw in.
  glutInitDisplayMode( GLUT_SINGLE |GLUT_RGB );
  glutInitWindowSize(600,600);
  glutInitWindowPosition(50,50);
  // Create the window.
  glutCreateWindow( "Lab03_01" );
  // Set the callback funcion to call when we need to draw something.
  glutDisplayFunc( myDisplay );
  // Initialize some things.
  myInit( );
  // Now that we have set everything up, loop responding to events.
  glutMainLoop( );
}

