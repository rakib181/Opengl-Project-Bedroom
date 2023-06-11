#include <iostream>
#include<GL/gl.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <bits/stdc++.h>
#include<GL/gl.h>
#include<windows.h>
#include<math.h>
#include<mmsystem.h>

using namespace std;

const int width = 1000;
const int height = 1000;

GLfloat eyeX = 0;
GLfloat eyeY = 0;
GLfloat eyeZ = 80;

GLfloat lookX = 0;
GLfloat lookY = 0;
GLfloat lookZ = 0;

static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
    {0,2,6,4},
    {1,5,7,3},
    {0,4,5,1},
    {2,3,7,6},
    {0,1,3,2},
    {4,6,7,5}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void cube(float r,float g,float b)
{

    glBegin(GL_QUADS);
    glColor3d(r,g,b);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}

void khat(){
    glPushMatrix();
    glScaled(28, 6, -30);
    cube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1, 0, 0);
    glScaled(2, 6, -30);
    cube(.62, .62, .62);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1, 0, 0);
    glScaled(30, 6, 1);
    cube(.62, .62, .62);
    glPopMatrix();

       glPushMatrix();
    glTranslated(-1, 0, -30);
    glScaled(30, 18, -7);
    cube(.4, .2, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(28, 0, 1);
    glScaled(2, 6, -30);
    cube(.62, .62, .62);
    glPopMatrix();
}

void almira(){
    glPushMatrix();
    glScaled(40, 60, 5);
    cube(0, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glScaled(40, 5, 5);
     cube(.62, .62, .62);
    glPopMatrix();

    glPushMatrix();
    glScaled(40, 10, 6);
     cube(.62, .62, .62);
    glPopMatrix();

     glPushMatrix();
    glScaled(2, 60, 6);
    cube(.62, .62, .62);
    glPopMatrix();

     glPushMatrix();
     glTranslated(40, 0, 0);
    glScaled(2, 60, 6);
     cube(.62, .62, .62);
    glPopMatrix();

     glPushMatrix();
     glTranslated(0, 55, 0);
    glScaled(40, 5, 6);
     cube(.62, .62, .62);
    glPopMatrix();

     glPushMatrix();
     glTranslated(0, 28, 0);
    glScaled(40, 5, 6);
     cube(.62, .62, .62);
    glPopMatrix();

     glPushMatrix();
     glTranslated(20, 0, 0);
    glScaled(2, 60, 6);
    cube(.62, .62, .62);
    glPopMatrix();


     glPushMatrix();
     glTranslated(7, 18, 0);
     glScaled(5, 1, 6);
     cube(0, 0, 0);
     glPopMatrix();

      glPushMatrix();
     glTranslated(28, 18, 0);
     glScaled(5, 1, 6);
     cube(0, 0, 0);
     glPopMatrix();

      glPushMatrix();
     glTranslated(24, 40, 0);
     glScaled(.5, 5.5, 6);
     cube(0, 0, 0);
     glPopMatrix();
}


void AC(){
    glPushMatrix();
    glScaled(30, 7, 6);
    cube(1, 1, 1);
    glPopMatrix();
}


void wall(){
   glPushMatrix();
   glTranslated(-150,-30, 5);
   glScaled(300, 260, 1);
   cube(0, .2, .2);
   glPopMatrix();

    glPushMatrix();
   glTranslated(-150,-25,0);
   glScaled(300, 1, 260);
   cube(.3, .2, .2);
   glPopMatrix();
}

void stick(){
   glPushMatrix();
   glTranslated(91, -20, 0);
    glScaled(.5, 25, .5);
    cube(0, 0, 0);
    glPopMatrix();
}

void locker(){
   glPushMatrix();
    glTranslated(-10, 0, 0);
    glScaled(15, 10, 6);
     cube(1, .50, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.2, 0, 0);
    glScaled(1, 10, 6);
    cube(0.6, 0.29, 0);
    glPopMatrix();

     glPushMatrix();
    glTranslated(-11, 0, 0);
    glScaled(1, 10, 6);
     cube(0.6, 0.29, 0);
    glPopMatrix();

       glPushMatrix();
    glTranslated(-11, -1, 0);
    glScaled(17, 1, 6);
    cube(0.6, 0.29, 0);
    glPopMatrix();

       glPushMatrix();
    glTranslated(-11, 10, 0);
    glScaled(17, 1, 6);
     cube(0.6, 0.29, 0);
    glPopMatrix();

     glPushMatrix();
     glTranslated(2, 4, 6);
     glScaled(.5, 3, 1);
     cube(0, 0, 0);
     glPopMatrix();
}

void light()
{
    glPushMatrix();
    glTranslated(4.8, 7.5, 0);
    glScaled(5, 3, .5);
    cube(0, 0.09, .2);
    glPopMatrix();
    glBegin(GL_TRIANGLES);
		glColor3f(1,1,1);
		glVertex2f(0.0,0);
		glColor3f(0.8,0.89,0.8);
		glVertex2f(7,10.0);
		glColor3f(1,1,1);
		glVertex2f(14,0.0);
	glEnd();

}

void Triangle();

void janala();

void balish();

void tv();

void stand();

void ghori();

void book();

void chofa();

void table();

void paya();

void remote();

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, width, height);glPushMatrix();

    glPushMatrix();
    glTranslated(0, 0, -20);
    wall();
    glPopMatrix();

    glPushMatrix();
    glTranslated(60, 60, -17);
    AC();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-110, -30, -15);
    almira();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-85, 60, 0);
    light();
    glPopMatrix();

      glPushMatrix();
    glTranslated(15, 60, 0);
    light();
    glPopMatrix();

    glPushMatrix();
    glTranslated(10, -15, 50);
    khat();
    glPopMatrix();

    glPushMatrix();
    glTranslated(85, 5, 0);
    light();
    glPopMatrix();

    stick();

    glPushMatrix();
    glTranslated(100, -25, -5);
    locker();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-11.8, -48, 28);
    balish();
    glPopMatrix();

    glPushMatrix();
    glTranslated(12, -2, 6);
    Triangle();
    glPopMatrix();

    janala();

    glPushMatrix();
    glTranslated(-33, 32.5, 5);
    tv();
    glPopMatrix();

    ghori();

    glPushMatrix();
    glTranslated(-35.5, 3, -10.8);
    book();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-70.5, -1.8, -61.49);
    glPushMatrix();
    glRotated(120, 0, 0, .7);
    glPushMatrix();
    glTranslated(70, 20, 50);
    book();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15, 0, -10);
    glPushMatrix();
    glTranslated(10, -3, 5);
    chofa();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4, 0, 0);
    table();
    glPopMatrix();
    glutSwapBuffers();
}

void table(){
  glPushMatrix();
  glTranslated(-8, -7, 60);
  glScaled(8, .5, 6);
  cube(.8, .4, 0);
  glPopMatrix();

  paya();

  glPushMatrix();
  glTranslated(0, 0, -8);
  paya();
  glPopMatrix();


  glPushMatrix();
  glTranslated(-10, 0, -8);
  paya();
  glPopMatrix();

  glPushMatrix();
  glTranslated(-10, 0, .2);
  paya();
  glPopMatrix();

  glPushMatrix();
  glTranslated(3, 1.9, 5);
  remote();
  glPopMatrix();

}

void remote(){
  glPushMatrix();
  glTranslated(-10, -8.4, 55);
  glScaled(3, .5, .5);
  cube(0, 0, 0);
  glPopMatrix();
}

void paya(){
  glPushMatrix();
  glTranslated(-10, -21, 48);
  glScaled(.8, 5, .5);
  cube(1, .50, 0);
  glPopMatrix();
}

void chofa(){
    glPushMatrix();
    glPushMatrix();
    glTranslated(-35, -16, 48);
    glScaled(10, 4.5, 8);
    cube(1, 1, 1);
    glPopMatrix();

     glPushMatrix();
    glPushMatrix();
    glTranslated(-36, -16, 48);
    glScaled(4, 12, 8);
    cube(1, .4, .4);
    glPopMatrix();

}

void book(){
   glPushMatrix();
   glTranslated(-50, 0, 0);
   glScaled(12, 1.5, 1.6);
   cube(1, 1, 1);
   glPopMatrix();

   glPushMatrix();
   glTranslated(0, 1.7, 0);
   glPushMatrix();
   glTranslated(-50, 0, 0);
   glScaled(12, .5, 1.5);
   cube(0, 0, 0);
   glPopMatrix();
   glPopMatrix();

    glPushMatrix();
   glTranslated(0, -.5, 0);
   glPushMatrix();
   glTranslated(-50, 0, 0);
   glScaled(12, .5, 1.5);
   cube(0, 0, 0);
   glPopMatrix();
   glPopMatrix();

   // Another

    glPushMatrix();
    glTranslated(0, 2.5, 0);
    glPushMatrix();
   glTranslated(-50, 0, 0);
   glScaled(12, 1.5, 1.6);
   cube(1, 1, 1);
   glPopMatrix();

   glPushMatrix();
   glTranslated(0, 1.7, 0);
   glPushMatrix();
   glTranslated(-50, 0, 0);
   glScaled(12, .5, 1.5);
   cube(.6, .29, 0);
   glPopMatrix();
   glPopMatrix();

    glPushMatrix();
   glTranslated(0, -.5, 0);
   glPushMatrix();
   glTranslated(-50, 0, 0);
   glScaled(12, .5, 1.5);
   cube(.6, .29, 0);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
}

void tv(){
   glPushMatrix();
   glTranslated(-50, 0, 0);
   glScaled(20, 14, 1);
   cube(1, 1, 1);
   glPopMatrix();

    glPushMatrix();
   glTranslated(-51, 0, 0);
   glScaled(1, 14, 1);
   cube(0, 0, 0);
   glPopMatrix();

    glPushMatrix();
   glTranslated(-30, 0, 0);
   glScaled(1, 14, 1);
   cube(0, 0, 0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(-51, -1, 0);
   glScaled(22, 1, 1);
   cube(0, 0, 0);
   glPopMatrix();

    glPushMatrix();
   glTranslated(-51, 14, 0);
   glScaled(22, 1, 1);
   cube(0, 0, 0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(5, 3, 0);
   glPushMatrix();
   glTranslated(-51, -10, 0);
   stand();
   glPopMatrix();
   glPopMatrix();


}

void ghori(){
    glPushMatrix();
   glTranslated(-35, 50, 0);
   glScaled(15, 17, 1.5);
   cube(1, 1, 1);
   glPopMatrix();

    glPushMatrix();
   glTranslated(-36, 50, 0);
   glScaled(1, 17, 1.5);
    cube(.62, .62, .62);
   glPopMatrix();

     glPushMatrix();
   glTranslated(-20, 50, 0);
   glScaled(1, 17, 1.5);
    cube(.62, .62, .62);
   glPopMatrix();


     glPushMatrix();
   glTranslated(-35, 65.5, .5);
   glScaled(15, 1.5, 1.5);
    cube(.62, .62, .62);
   glPopMatrix();


     glPushMatrix();
   glTranslated(-35, 48.8, 1.5);
   glScaled(16, 1.5, 1.5);
    cube(.62, .62, .62);
   glPopMatrix();

    glPushMatrix();
    glTranslated(33.5, 36.5, 0);
    glPushMatrix();
    glRotated(45, 0, 0, .5);
    glPushMatrix();
    glTranslated(-28, 58, 1.6);
    glScaled(5, .5, .5);
    cube(0, 0, 0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(33, 37, 0);
    glPushMatrix();
     glRotated(45, 0, 0, 1.5);
    glPushMatrix();
    glTranslated(33.5, 36.5, 0);
    glPushMatrix();
    glRotated(45, 0, 0, .5);
    glPushMatrix();
    glTranslated(-28, 58, 1.6);
    glScaled(6, .5, .5);
    cube(0, 0, 0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslated(32, 15, 2);
    glPushMatrix();
    glRotated(68, 0, 0, .5);
    glPushMatrix();
    glTranslated(10, 70, 1.6);
    glScaled(7, .5, .5);
    cube(0, 0, 0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(6.2, 32, 43);
    glPushMatrix();
    glTranslated(-20, 0, 0);
    glScaled(1.5, .5, .5);
    cube(0, 0, 0);
    glPopMatrix();
    glPopMatrix();

}

void stand(){
   glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 0);
		glVertex2f(0.0,0);
        glColor3f(.4, .2, 0);
		glVertex2f(5,7.0);
        glColor3f(0, 0, 0);
		glVertex2f(10,0.0);
	glEnd();
}

void janala(){
   glPushMatrix();
   glTranslated(-25, 0, 0);
   glScaled(35, 40, 1);
   cube(.8, .89, 1);
   glPopMatrix();

   glPushMatrix();
   glScaled(15, 40, 2);
   cube(0, 0, .2);
   glPopMatrix();

    glPushMatrix();
    glRotated(30, 0, 5, 0);
    glPushMatrix();
    glTranslated(-24, 0, -10);
    glScaled(15, 40, 2);
    cube(.8, .4, 0);
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    glTranslated(7, 15.5, 6);
    glPushMatrix();
    glTranslated(-30, 0, 0);
   glScaled(.5, 8, .5);
   cube(0, 0, 0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(-31, 0, 0);
   glScaled(1, .5, .5);
   cube(0, 0, 0);
   glPopMatrix();

    glPushMatrix();
   glTranslated(-31, 7.5, 0);
   glScaled(1, .5, .5);
   cube(0, 0, 0);
   glPopMatrix();
   glPopMatrix();


}

void Triangle(){
     glBegin(GL_TRIANGLES);
        glColor3f(.4, .2, 0);
		glVertex2f(0.0,0);
        glColor3f(.4, .2, 0);
		glVertex2f(15,25.0);
        glColor3f(.4, .2, 0);
		glVertex2f(35,0.0);
	glEnd();
}

void balish(){
     glPushMatrix();
     glTranslated(20, 40, 0);
     glScaled(25, 2, 4);
     cube(.8, .8, 1);
     glPopMatrix();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'w':
        eyeY=eyeY+0.1;
        break;
    case 's':
        eyeY=eyeY-0.1;
        break;
    case 'd':
        eyeX=eyeX+0.1;
        break;
    case 'a':
        eyeX=eyeX-0.1;
    break;

    case 'i':
        lookY=lookY+0.1;
        break;
    case 'k':
        lookY=lookY-0.1;
        break;
    case 'j':
        lookX=lookX+0.1;
        break;
    case 'l':
        lookX=lookX-0.1;
        break;


    case '+':
        eyeZ=eyeZ+0.1;
        break;
    case '-':
        eyeZ=eyeZ-0.1;
        break;

    }

    glutPostRedisplay();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Project Bedroom");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    PlaySound("song", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutMainLoop();

    return 0;
}
