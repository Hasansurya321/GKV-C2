/*
 * FreeGLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone 
 * and torus shapes in FreeGLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <GL/glut.h>

#include <stdlib.h>

#include <GL/glut.h>

// Fungsi menggambar kubus 2D dengan berbagai metode OpenGL
void drawSquare(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);

    // Gambar batas luar menggunakan GL_LINE_LOOP
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(-0.2, 0.2);
    glEnd();

    // Menggunakan GL_QUADS untuk mengisi kubus
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(-0.2, 0.2);
    glEnd();

    // Menggunakan GL_TRIANGLE_FAN untuk efek tambahan
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, -0.2);
    glEnd();

    glPopMatrix();
}

// Fungsi menggambar susunan kubus berbentuk tanda plus "+"
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Posisi pusat
    drawSquare(0.0, 0.0); // Kubus tengah

    // Posisi kiri, kanan, atas, bawah
    drawSquare(-0.5, 0.0); // Kubus kiri
    drawSquare(0.5, 0.0);  // Kubus kanan
    drawSquare(0.0, 0.5);  // Kubus atas
    drawSquare(0.0, -0.5); // Kubus bawah

    glutSwapBuffers();
}

// Setup OpenGL
void initOpenGL() {
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kubus 2D Bertingkat - OpenGL");
    initOpenGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

