#include <math.h>
#include "mobil.h"
#ifdef __APPLE__ // untuk program yang dijalankan di MacOS
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else // untuk program yang dijalankan di Windows
#include <GL/glut.h>
#endif


void Halangan::Cone()
{
    // sisi satu
    sisiCone();
    
    // sisi dua
    glPushMatrix();
    glRotatef(-90, 0.0, 1.0, 0.0);
    glTranslatef(-2.5, -0.1, -1.);
    sisiCone();
    glPopMatrix();
    
    // sisi tiga
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-0.75, -0.1, 2.);
    sisiCone();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    glTranslatef(-3.0, 0., 1.5);
    sisiCone();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(.0, 0.5, -1.5);
    glBegin(GL_QUADS);
        //Sisi atas
        glColor3f(1.0f, .5f, .0f);
        glVertex3f(0.6, 0.5, 1.8);
        glVertex3f(2.4, 0.5, 1.8);
        glVertex3f(2.4, 0.5, 0.0);
        glVertex3f(0.6, 0.5, 0.0);
        //Sisi kiri
        glEnd();
    glPopMatrix();
}

void Halangan::sisiCone()
{
    // sisi satu

    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.8, 1.0, 0.0);
    glVertex3f(2.2, 1.0, 0.0);
    
    glVertex3f(1.0, 2.0, -0.2);
    glVertex3f(2.0, 2.0, -0.2);
    glEnd();
    
    
    
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(1.0, 2.0, -0.2);
    glVertex3f(2.0, 2.0, -0.2);
    
    glVertex3f(1.2, 3.0, -0.4);
    glVertex3f(1.8, 3.0, -0.4);
    glEnd();
    
    
    
    
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0, 1., 1.0);
    glVertex3f(1.2, 3.0, -0.4);
    glVertex3f(1.8, 3.0, -0.4);
    
    glVertex3f(1.4, 4.0, -.6);
    glVertex3f(1.6, 4.0, -.6);
    glEnd();
    
}

void Halangan::Mobil(float r, float g, float b)
{
    glPushMatrix();
    
        glColor3f(r, g, b);
        blok(10, 3, 2);
        glTranslatef(0, 9, 0);
        blok(10, 3, 2);
        glTranslatef(10, -10, 0);
        blok(10, 5.5, 2);
        glRotatef(-35, 0, 0, 15);
        glTranslatef(0, 7, 0);
        blok(10, 2, 2);
        glTranslatef(2, 4.9, -2.5);
        glColor3f(2.0, 1.0, 1.0);// warna kaca
        blok(0.5, 20, 31);

        glRotatef(180, 45, -45, 0);
        

        glPopMatrix();


        glPushMatrix();//roda
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(20, -8, -7);
        cylinder(5, 5, 3);

        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(-20, 8, 7);
        glTranslatef(-5, -8, -7);
        cylinder(5, 5, 3);

        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(5, 8, 7);
        glRotatef(180, 0, 180, 0);
        glTranslatef(3, -8, -17);
        cylinder(5, 5, 3);

        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(-3, 8, 17);
        glTranslatef(-22, -8, -17);
        cylinder(5, 5, 3);

        glColor3f(1.0, 1.0, 1.0);

        glRotatef(90, 1, 0, 0);
        glTranslatef(8, 2.5, -15);
        blok(2, 4, 5);


        glRotatef(90, 0, 1, 0);
        glTranslatef(0, -0.2, 7);
        blok(2, 4, 8);


        glRotatef(0, 0, 0, 0);
        glTranslatef(0, 19.2, 0);
        blok(2, 4, 8);

        glRotatef(90, 0, 1, 0);
        glTranslatef(7, 0, -8);
        blok(2, 4, 5);

        glColor3f(9.9, 9.9, 0.0);//lampu
        glRotatef(90, 0, 1, 0);
        glTranslatef(0, -3, 20);
        cylinder(2, 2, 3);

        glColor3f(9.9, 9.9, 0.0);//lampu
        glRotatef(0, 0, 0, 0);
        glTranslatef(0, -12, 0);
        cylinder(2, 2, 3);

        glColor3f(1, 0.0, 0.0);//knalpot
        glRotatef(0, 0, 0, 0);
        glTranslatef(0, 0, -52);
        cylinder(1, 1, 3);

        glColor3f(1.0, 1.0, 1.0);
        glRotatef(90, 1, 0, 0);
        glTranslatef(-8, 3.5, -12);
        blok(2, 4, 8);

        glColor3f(9.0, 0.0, 0.0);//lampu atas
        glRotatef(0, 0, 0, 0);
        glTranslatef(-8, 28, 0);
        cylinder(1, 1, 12);


    glPopMatrix();

}

void Halangan::kerucut(float ngisor, float nduwur, float dowo)
{
    float i;
    glPushMatrix();
    glTranslatef(1.0, 0.0, ngisor / 24);
    glutSolidCone(ngisor, 0, 32, 4);
    for (i = 0; i <= dowo; i += ngisor / 24)
    {
        glTranslatef(0.0, 0.0, ngisor / 24);
        glutSolidTorus(ngisor / 4, ngisor - ((i * (ngisor - nduwur)) / dowo), 16, 16);
    }
    glTranslatef(0.0, 0.0, ngisor / 4);
    glutSolidCone(nduwur, 0, 20, 1);
    glColor3f(0., 1., 1.);
    glPopMatrix();
}


void Halangan::cylinder(float alas, float atas, float tinggi)
{
    float i;
    glPushMatrix();
    glTranslatef(1.0, 0.0, -alas / 8);
    glutSolidCone(alas, 0, 32, 4);
    for (i = 0; i <= tinggi; i += alas / 24)
    {
        glTranslatef(0.0, 0.0, alas / 24);
        glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
    }
    glTranslatef(0.0, 0.0, alas / 4);
    glutSolidCone(atas, 0, 20, 1);
    glColor3f(1., 0., 0.);
    glPopMatrix();
}

void Halangan::blok(float tebal, int ratiol, int ratiop)
{
    float i, j;
    glPushMatrix();
    for (i = 0; i < ratiop; i++)
    {
        glTranslatef(-(ratiol + 1) * tebal / 2, 0.0, 0.0);
        for (j = 0; j < ratiol; j++)
        {
            glTranslatef(tebal, 0.0, 0.0);
            glutSolidCube(tebal);
        }
        glTranslatef(-(ratiol - 1) * tebal / 2, 0.0, tebal);
    }
    glPopMatrix();
}

