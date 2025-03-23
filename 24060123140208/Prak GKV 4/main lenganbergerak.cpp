#include <GL/glut.h>

static int rotX = 0, rotY = 0, rotZ = 0;
static int shoulder = 0, elbow = 0, wrist = 0;
static int finger[5] = {0, 0, 0, 0, 0};
static int finger2[5] = {0, 0, 0, 0, 0};

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawCube(float sx, float sy, float sz) {
    glPushMatrix();
    glScalef(sx, sy, sz);
    glutWireCube(1.0);
    glPopMatrix();
}

void drawFinger(float base_angle, float mid_angle, float x_offset, float y_offset) {
    glPushMatrix();
    glTranslatef(x_offset, y_offset, 0.0);
    glRotatef(base_angle, 1.0, 0.0, 0.0);
    glTranslatef(0.1, 0.0, 0.0);
    drawCube(0.2, 0.05, 0.05);
    glTranslatef(0.1, 0.0, 0.0);
    glRotatef(mid_angle, 0.0, 0.1, 0.0);
    glTranslatef(0.1, 0.0, 0.0);
    drawCube(0.2, 0.05, 0.05);
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Rotasi global
    glRotatef(rotX, 1.0, 0.0, 0.0);
    glRotatef(rotY, 0.0, 1.0, 0.0);
    glRotatef(rotZ, 0.0, 0.0, 1.0);

    // Lengan atas (shoulder) sedikit dimiringkan lebih banyak
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef(shoulder + 15, 0.0, 0.0, 1.0); // sedikit lebih banyak rotasi
    glTranslatef(1.0, 0.0, 0.0);
    drawCube(2.0, 0.4, 1.0);

    // Lengan bawah (elbow) dengan rotasi lebih besar
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef(elbow + 10, 0.0, 0.0, 1.0); // rotasi lebih besar
    glTranslatef(1.0, 0.0, 0.0);
    drawCube(2.0, 0.4, 1.0);

    // Pergelangan tangan (wrist) dengan sedikit perubahan rotasi
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef(wrist + 5, 0.0, 1.0, 0.0); // sedikit perubahan rotasi
    drawCube(0.4, 0.6, 0.2);

    // Jari-jari dengan perubahan sedikit pada sudut
    drawFinger(finger[0] + 10, finger2[0], 0.15, 0.25);
    drawFinger(finger[1] + 5, finger2[1], 0.1, 0.15);
    drawFinger(finger[2] + 8, finger2[2], 0.05, 0.05);
    drawFinger(finger[3], finger2[3], 0.0, -0.05);
    drawFinger(finger[4] - 5, finger2[4], -0.05, -0.15);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'x': rotX = (rotX + 5) % 360; break;
        case 'X': rotX = (rotX - 5 + 360) % 360; break;
        case 'y': rotY = (rotY + 5) % 360; break;
        case 'Y': rotY = (rotY - 5 + 360) % 360; break;
        case 'z': rotZ = (rotZ + 5) % 360; break;
        case 'Z': rotZ = (rotZ - 5 + 360) % 360; break;

        case 'a': shoulder = (shoulder + 5) % 360; break;
        case 's': shoulder = (shoulder - 5 + 360) % 360; break;
        case 'd': elbow = (elbow + 5) % 360; break;
        case 'f': elbow = (elbow - 5 + 360) % 360; break;
        case 'g': wrist = (wrist + 5) % 360; break;
        case 'h': wrist = (wrist - 5 + 360) % 360; break;

        case '1': if(finger[0] < 90) finger[0] += 5; break;
        case '!': if(finger[0] > 0) finger[0] -= 5; break;
        case '2': if(finger[1] < 90) finger[1] += 5; break;
        case '@': if(finger[1] > 0) finger[1] -= 5; break;
        case '3': if(finger[2] < 90) finger[2] += 5; break;
        case '#': if(finger[2] > 0) finger[2] -= 5; break;
        case '4': if(finger[3] < 90) finger[3] += 5; break;
        case '$': if(finger[3] > 0) finger[3] -= 5; break;
        case '5': if(finger[4] < 90) finger[4] += 5; break;
        case '%': if(finger[4] > 0) finger[4] -= 5; break;

        case '6': if(finger2[0] < 90) finger2[0] += 5; break;
        case '^': if(finger2[0] > 0) finger2[0] -= 5; break;
        case '7': if(finger2[1] < 90) finger2[1] += 5; break;
        case '&': if(finger2[1] > 0) finger2[1] -= 5; break;
        case '8': if(finger2[2] < 90) finger2[2] += 5; break;
        case '*': if(finger2[2] > 0) finger2[2] -= 5; break;
        case '9': if(finger2[3] < 90) finger2[3] += 5; break;
        case '(': if(finger2[3] > 0) finger2[3] -= 5; break;
        case '0': if(finger2[4] < 90) finger2[4] += 5; break;
        case ')': if(finger2[4] > 0) finger2[4] -= 5; break;

        case 27: exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot Arm with Realistic Fingers");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

