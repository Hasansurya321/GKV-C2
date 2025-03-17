#include <GL/glut.h>
#include <cmath>

// Variabel rotasi untuk sendi bahu dan siku
float shoulderAngle = 0.0f;  // Angka untuk rotasi bahu
float elbowAngle = 0.0f;     // Angka untuk rotasi siku

// Fungsi untuk menggambar persegi panjang (digunakan untuk menggambar bagian lengan)
void drawRect(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex3f(x, y, 0.0f); // Kiri bawah
    glVertex3f(x + width, y, 0.0f); // Kanan bawah
    glVertex3f(x + width, y + height, 0.0f); // Kanan atas
    glVertex3f(x, y + height, 0.0f); // Kiri atas
    glEnd();
}

// Fungsi untuk menggambar lingkaran (digunakan untuk menggambar roda atau sendi)
void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex3f(x + dx, y + dy, 0.0f);
    }
    glEnd();
}

// Fungsi untuk menggambar lengan
void drawArm() {
    // Lengan atas (Bagian dari bahu ke siku)
    glPushMatrix();
    glRotatef(shoulderAngle, 0.0f, 0.0f, 1.0f); // Rotasi sendi bahu
    glColor3f(0.8f, 0.4f, 0.0f);  // Warna lengan (Coklat)
    drawRect(-0.1f, -0.2f, 0.2f, 0.6f);  // Lengan atas
    glPopMatrix();

    // Lengan bawah (Bagian dari siku ke tangan)
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f); // Posisi siku
    glRotatef(elbowAngle, 0.0f, 0.0f, 1.0f); // Rotasi sendi siku
    glColor3f(0.8f, 0.4f, 0.0f);  // Warna lengan bawah (Coklat)
    drawRect(-0.1f, -0.2f, 0.2f, 0.6f);  // Lengan bawah
    glPopMatrix();

    // Gambar tangan (lingkaran kecil di ujung lengan bawah)
    glPushMatrix();
    glTranslatef(0.0f, 1.2f, 0.0f); // Posisi tangan
    glColor3f(1.0f, 0.8f, 0.6f);  // Warna tangan (Coklat terang)
    drawCircle(0.0f, 0.0f, 0.1f); // Tangan (lingkaran)
    glPopMatrix();
}

// Fungsi untuk menggambar objek secara keseluruhan
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar lengan bergerak
    drawArm();

    glutSwapBuffers();
}

// Fungsi untuk memperbarui rotasi ketika tombol ditekan
void update(int value) {
    shoulderAngle += 2.0f;  // Menambah rotasi bahu
    if (shoulderAngle > 360.0f) shoulderAngle -= 360.0f;  // Rotasi terus berputar

    elbowAngle += 1.5f;  // Menambah rotasi siku
    if (elbowAngle > 180.0f) elbowAngle -= 180.0f;  // Rotasi siku maksimal 180 derajat

    glutPostRedisplay();  // Meminta OpenGL untuk menggambar ulang
    glutTimerFunc(16, update, 0);  // Memperbarui setiap 16 ms (sekitar 60 FPS)
}

// Fungsi inisialisasi OpenGL
void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Warna latar belakang (langit biru)
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f); // Proyeksi 2D
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Arm Animation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0); // Memulai animasi
    glutMainLoop(); // Masuk ke loop utama OpenGL

    return 0;
}

