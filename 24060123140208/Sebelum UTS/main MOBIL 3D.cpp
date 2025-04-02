#include <GL/glut.h>
#include <math.h>

// Variabel global untuk pencahayaan dan animasi
GLfloat ambient_light[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat diffuse_light[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_position[] = { 5.0f, 5.0f, 5.0f, 1.0f };
double Loop = 0, LoopAll = 0;

// Fungsi untuk membuat silinder
void cylinder(float alas, float up, float height) {
    float i;
    glPushMatrix();
    glTranslatef(1.0, 0.0, -alas / 8);
    glutSolidCone(alas, 0, 32, 4);
    
    for (i = 0; i <= height; i += alas / 24) {
        glTranslatef(0.0, 0.0, alas / 24);
        glutSolidTorus(alas / 4, alas - ((i * (alas - up)) / height), 16, 16);
    }
    
    glTranslatef(0.0, 0.0, alas / 4);
    glutSolidCone(height, 0, 20, 1);
    glColor3f(0., 0., 0.);
    glPopMatrix();
}

// Fungsi untuk membuat kerucut
void kerucut(float bottom, float up, float width) {
    float i;
    glPushMatrix();
    glTranslatef(1.0, 0.0, bottom / 24);
    glutSolidCone(bottom, 0, 32, 4);
    
    for (i = 0; i <= width; i += bottom / 24) {
        glTranslatef(0.0, 0.0, bottom / 24);
        glutSolidTorus(bottom / 4, bottom - ((i * (bottom - up)) / width), 16, 16);
    }
    
    glTranslatef(0.0, 0.0, bottom / 4);
    glutSolidCone(up, 0, 20, 1);
    glColor3f(0., 1., 1.);
    glPopMatrix();
}

// Fungsi untuk membuat blok/kubus
void blok(float tebal, int ratiol, int ratiop) {
    glPushMatrix();
    for (int i = 0; i < ratiop; i++) {
        glTranslatef(-(ratiol + 1) * tebal / 2, 0.0, 0.0);
        for (int j = 0; j < ratiol; j++) {
            glTranslatef(tebal, 0.0, 0.0);
            glutSolidCube(tebal);
        }
        glTranslatef(-(ratiol - 1) * tebal / 2, 0.0, tebal);
    }
    glPopMatrix();
}

// Inisialisasi pencahayaan dan konfigurasi
void kendaraan(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.33, 0.1, 1000.0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHTING);
    
    // Konfigurasi cahaya utama
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Material properties untuk efek tambahan
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_shininess[] = { 50.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

// Fungsi display utama
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Posisi kamera yang lebih baik
    gluLookAt(0.0f, 10.0f, 50.0f,  // Posisi kamera
              0.0f, 0.0f, 0.0f,    // Titik pandang
              0.0f, 1.0f, 0.0f);   // Vektor up

    // Rotasi dan translasi mobil
    Loop += 0.1;
    glRotatef(Loop, 0.9, 4.0, 0.6);

    // Badan mobil
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);  // Warna biru
    blok(10, 3, 2);  // Badan mobil
    
    // Atap mobil
    glTranslatef(0, 9, 0);
    blok(10, 3, 2);
    
    // Bumper depan
    glTranslatef(10, -10, 0);
    blok(10, 5.5, 2);
    
    // Bagian belakang
    glRotatef(-35, 0, 0, 15);
    glTranslatef(0, 7, 0);
    blok(10, 2, 2);

    // Kaca depan
    glTranslatef(2, 4.9, -2.5);
    glColor3f(0.5, 0.5, 0.5);
    blok(0.5, 20, 31);
    glPopMatrix();

    // Roda mobil
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    
    // Roda kanan depan
    glTranslatef(20, -8, -7);
    cylinder(5, 5, 3);

    // Roda kanan belakang
    glTranslatef(-20, 8, 7);
    glTranslatef(-5, -8, -7);
    cylinder(5, 5, 3);

    // Roda kiri belakang
    glTranslatef(5, 8, 7);
    glRotatef(180, 0, 180, 0);
    glTranslatef(3, -8, -17);
    cylinder(5, 5, 3);

    // Roda kiri depan
    glTranslatef(-3, 8, 17);
    glTranslatef(-22, -8, -17);
    cylinder(5, 5, 3);
    glPopMatrix();

    // Jendela kiri
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glTranslatef(-5, 4, 0);
    blok(0.5, 4, 3);
    glPopMatrix();

    // Pintu kiri
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(-5, -3, 0);
    blok(1, 4, 3);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

// Fungsi idle untuk animasi
void munculsih() {
    display();
}

// Fungsi utama
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 3D dengan Depth dan Lighting");
    
    kendaraan(); // Inisialisasi pencahayaan dan depth

    glutDisplayFunc(display);
    glutIdleFunc(munculsih);

    glutMainLoop();
    return 0;
}
