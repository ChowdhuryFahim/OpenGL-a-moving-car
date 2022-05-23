#include <GL/glut.h>    // Header File For The GLUT Library
#include <GL/gl.h>    // Header File For The OpenGL32 Library
#include <GL/glu.h>    // Header File For The GLu32 Library



#define ESCAPE 27


int window;


float rtri = 0.0f;

float rquad = 0.0f;



void InitGL(int Width, int Height)
{
  // This Will Clear The Background Color To Black
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);                // Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);                // The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);            // Enables Depth Testing
  glShadeModel(GL_SMOOTH);            // Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();                // Reset The Projection Matrix

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);

  glMatrixMode(GL_MODELVIEW);
}


float ballX = -0.5f;
float ballY = 0.0f;
float ballZ = 0.0f;

void drawBall(void) {
        glColor3f(0.0, 1.0, 0.0); //set ball colour
        glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.3, 20, 20); //create ball.
        glTranslatef(ballX+1.5,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.3, 20, 20); //
        }



void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        // Clear The Screen And The Depth Buffer
  glLoadIdentity();                // Reset The View

  glTranslatef(rtri,0.0f,-6.0f);        // Move Left 1.5 Units And Into The Screen 6.0


  glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(1.0f,0.0f,0.0f);            // Set The Color To Red
  glVertex3f(-1.0f, 1.0f, 0.0f);        // Top left
  glVertex3f(0.4f, 1.0f, 0.0f);

  glVertex3f(1.0f, 0.4f, 0.0f);

  glColor3f(0.0f,1.0f,0.0f);            // Set The Color To Green
  glVertex3f( 1.0f,0.0f, 0.0f);        // Bottom Right
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Blue
  glVertex3f(-1.0f,0.0f, 0.0f);// Bottom Left


  glEnd();
  drawBall();

  rtri+=0.005f;                    // Increase The Rotation Variable For The Triangle
  if(rtri>2)
      rtri=-2.0f;
  rquad-=15.0f;                    // Decrease The Rotation Variable For The Quad


  glutSwapBuffers();
}


void keyPressed(unsigned char key, int x, int y)
{

    /* If escape is pressed, kill everything. */
    if (key == ESCAPE)
    {
    /* shut down our window */
    glutDestroyWindow(window);

    /* exit the program */
    exit(0);
    }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH); // initial display mode is used when creating top-level windows, subwindows, and overlays

  /* get a 640 x 480 window */
  glutInitWindowSize(640, 480);


  glutInitWindowPosition(0, 0);

  /* Open a window */
  window = glutCreateWindow("Moving Car");

  /* function to do all our OpenGL drawing. */
  glutDisplayFunc(&DrawGLScene);


  /* Even if there are no events, redraw our gl scene. */
  glutIdleFunc(&DrawGLScene);


  /* function called when the keyboard is pressed. */
  glutKeyboardFunc(&keyPressed);

  /* Initialize our window. */
  InitGL(640, 480);

  /* Start Event Processing Engine */
  glutMainLoop();

  return 1;
}
