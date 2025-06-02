#include "gedung.h"
#include <math.h>
#ifdef __APPLE__ // untuk program yang dijalankan di MacOS
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else // untuk program yang dijalankan di Windows
#include <GL/glut.h>
#endif


void gedung1()
{ 

	//BADAN BANGUNAN
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(3,4,3);
    glScalef(6,2.4,6);
    glutSolidCube(3.4);
    glPopMatrix();

    // ==== menara =====
    GLUquadric * quadratic;
    quadratic = gluNewQuadric();
    // ==== kanan depan ======
    glColor3f(1, 1, 0.0);
    glPushMatrix();
    glTranslatef(11.4,13,11.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
    // ==== kiri depan ======
    glPushMatrix();
    glTranslatef(-5.4,13,11.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
    // ==== kiri belakang ======
    glPushMatrix();
    glTranslatef(-5.4,13,-5.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
    // ==== kanan belakang ======
    glPushMatrix();
    glTranslatef(11.4,13,-5.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();


}



void gedung3()
{
 	//BADAN BANGUNAN
    glPushMatrix();
    glColor3f(0, 1, 1);
    glTranslatef(3,4,3);
    glScalef(6,5.5,6);
    glutSolidCube(3.4);
    glPopMatrix();

    // ==== menara =====
    GLUquadric * quadratic;
    quadratic = gluNewQuadric();
    // ==== kanan depan ======
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(11.4,13,11.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
    // ==== kiri depan ======
    glPushMatrix();
    glTranslatef(-5.4,13,11.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
    // ==== kiri belakang ======
    glPushMatrix();
    glTranslatef(-5.4,13,-5.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
    // ==== kanan belakang ======
    glPushMatrix();
    glTranslatef(11.4,13,-5.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
}
