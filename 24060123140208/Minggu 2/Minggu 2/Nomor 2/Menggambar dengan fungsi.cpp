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

#include <GL/glut.h>
#include <cmath>


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // 1. Dinding rumah (GL_QUADS)
    glColor3f(0.8f, 0.5f, 0.2f); // Coklat
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.2f);
        glVertex2f(-0.5f, 0.2f);
    glEnd();

    // 2. Atap rumah (GL_TRIANGLE_FAN)
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.6f);  // Puncak atap
        glVertex2f(-0.6f, 0.2f);
        glVertex2f(0.6f, 0.2f);
    glEnd();

    // 3. Pintu (GL_QUADS)
    glColor3f(0.5f, 0.2f, 0.0f); // Coklat tua
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.5f);
        glVertex2f(0.1f, -0.5f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(-0.1f, -0.1f);
    glEnd();

    // 4. Jendela (GL_LINE_LOOP)
    glColor3f(0.0f, 0.0f, 1.0f); // Biru
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.2f, -0.1f);
        glVertex2f(0.4f, -0.1f);
        glVertex2f(0.4f, 0.1f);
        glVertex2f(0.2f, 0.1f);
    glEnd();

    // 5. Jalan setapak (GL_QUAD_STRIP)
    glColor3f(0.6f, 0.6f, 0.6f); // Abu-abu
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.2f, -0.5f);
        glVertex2f(0.2f, -0.5f);
        glVertex2f(-0.1f, -0.8f);
        glVertex2f(0.1f, -0.8f);
    glEnd();

    // 6. Matahari (GL_TRIANGLE_FAN)
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.7f, 0.7f); // Pusat matahari
        for (int i = 0; i <= 360; i += 36) {
            float rad = i * 3.14159 / 180;
            glVertex2f(0.7f + 0.1f * cos(rad), 0.7f + 0.1f * sin(rad));
        }
    glEnd();

    // 7. Awan (GL_TRIANGLE_STRIP)
    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.7f, 0.6f);
        glVertex2f(-0.6f, 0.65f);
        glVertex2f(-0.5f, 0.6f);
        glVertex2f(-0.4f, 0.65f);
        glVertex2f(-0.3f, 0.6f);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Warna background langit biru
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Gambar Rumah dengan OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

