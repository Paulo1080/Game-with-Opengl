#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>

int controle = 0;
float p1X = 0.0; //controlar o player
float ballx = 0.0;
float bally = 0.0;
float angulo = 0.0;
int automatinc = 7;

int collisionDetec() {

    int retorno = 0;
    if ((ballx <= -0.87 && ballx >= -0.91) || (ballx >= 0.87 && ballx <= 0.91)) retorno = 1; // bordaX
    else if ((bally <= -0.87 && bally >= -0.89) || (bally >= 0.87 && bally <= 89)) retorno = 1; //borda Y
    else if ((bally <= -0.77 && bally >= -0.8) && (bally >= (-0.20 + p1X) && bally <= (0.20 + p1X))) retorno = 3; //player


    return retorno;
}

void ballMove() {
    //automatic increment c - cima = 1, v - baixo = 2, x - esquerda = 3, b direita = 4
    if (automatinc == 1 && ballx >= -0.87) {
        ballx -= 0.0003;
    }
    else if (automatinc == 2 && ballx <= 0.87) {
        ballx += 0.0003;
    }
    else if (automatinc == 3 && bally >= -0.87) {
        bally -= 0.0005;
    }
    else if (automatinc == 4 && bally <= 0.87) {
        bally += 0.0005;
    }
    else if (automatinc == 5 && ballx <= 0.87 && bally <= 0.87) {
        int Inc = rand() % 6;
        ballx += 0.0005;
        bally += 0.0001 * Inc;
    }
    else if (automatinc == 6 && ballx >= -0.87 && bally >= -0.87) {
        int Inc = rand() % 6;
        ballx -= 0.0005;
        bally -= 0.0001 * Inc;
    }
    else if (automatinc == 7 && ballx <= 0.87 && bally >= -0.87) {
        int Inc = rand() % 6;
        ballx += 0.0005;
        bally -= 0.0001 * Inc;
    }
    else if (automatinc == 8 && ballx >= -0.87 && bally <= 0.87) {
        int Inc = rand() % 6;
        ballx -= 0.0005;
        bally += 0.0001 * Inc;
    }
    else {
        automatinc = (rand() % 100) % 9;
    }

    //if (ballx >= -0.7 && ballx <= 0.7) ballx += 0.0001;
    //if (bally >= -0.7 && bally <= 0.7) bally += 0.0001;
    glutPostRedisplay();
}

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1415;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


void desenhaQ() {

    //bordas
    glColor3f(255.0, 255.0, 255.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-0.9, 0.9, 0.0);
    glVertex3f(0.9, 0.9, 0.0);
    glVertex3f(0.9, -0.9, 0.0);
    glVertex3f(-0.9, -0.9, 0.0);
    glVertex3f(-0.9, 0.9, 0.0);
    glEnd();

    //Player
    glColor3f(255.0, 255.0, 0.0);
    glTranslatef(0.0, p1X, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.1, -0.85, 0.0);
    glVertex3f(-0.1, -0.85, 0.0);
    glVertex3f(-0.1, -0.8, 0.0);
    glVertex3f(0.1, -0.8, 0.0);
    glEnd();

    //coluna1
    glColor3f(0.0, 255.0, 255.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.7, 0.8, 0.0);
    glVertex3f(-0.8, 0.8, 0.0);
    glVertex3f(-0.8, 0.7, 0.0);
    glVertex3f(-0.7, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.7, 0.69, 0.0);
    glVertex3f(-0.8, 0.69, 0.0);
    glVertex3f(-0.8, 0.59, 0.0);
    glVertex3f(-0.7, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.7, 0.58, 0.0);
    glVertex3f(-0.8, 0.58, 0.0);
    glVertex3f(-0.8, 0.48, 0.0);
    glVertex3f(-0.7, 0.48, 0.0);
    glEnd();

    //coluna2

    glBegin(GL_POLYGON);
    glVertex3f(-0.59, 0.8, 0.0);
    glVertex3f(-0.69, 0.8, 0.0);
    glVertex3f(-0.69, 0.7, 0.0);
    glVertex3f(-0.59, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.59, 0.69, 0.0);
    glVertex3f(-0.69, 0.69, 0.0);
    glVertex3f(-0.69, 0.59, 0.0);
    glVertex3f(-0.59, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.59, 0.58, 0.0);
    glVertex3f(-0.69, 0.58, 0.0);
    glVertex3f(-0.69, 0.48, 0.0);
    glVertex3f(-0.59, 0.48, 0.0);
    glEnd();

    //coluna3

    glBegin(GL_POLYGON);
    glVertex3f(-0.48, 0.8, 0.0);
    glVertex3f(-0.58, 0.8, 0.0);
    glVertex3f(-0.58, 0.7, 0.0);
    glVertex3f(-0.48, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.48, 0.69, 0.0);
    glVertex3f(-0.58, 0.69, 0.0);
    glVertex3f(-0.58, 0.59, 0.0);
    glVertex3f(-0.48, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.48, 0.58, 0.0);
    glVertex3f(-0.58, 0.58, 0.0);
    glVertex3f(-0.58, 0.48, 0.0);
    glVertex3f(-0.48, 0.48, 0.0);
    glEnd();

    // coluna4

    glBegin(GL_POLYGON);
    glVertex3f(-0.37, 0.8, 0.0);
    glVertex3f(-0.47, 0.8, 0.0);
    glVertex3f(-0.47, 0.7, 0.0);
    glVertex3f(-0.37, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.37, 0.69, 0.0);
    glVertex3f(-0.47, 0.69, 0.0);
    glVertex3f(-0.47, 0.59, 0.0);
    glVertex3f(-0.37, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.37, 0.58, 0.0);
    glVertex3f(-0.47, 0.58, 0.0);
    glVertex3f(-0.47, 0.48, 0.0);
    glVertex3f(-0.37, 0.48, 0.0);
    glEnd();

    // coluna4

    glBegin(GL_POLYGON);
    glVertex3f(-0.26, 0.8, 0.0);
    glVertex3f(-0.36, 0.8, 0.0);
    glVertex3f(-0.36, 0.7, 0.0);
    glVertex3f(-0.26, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.26, 0.69, 0.0);
    glVertex3f(-0.36, 0.69, 0.0);
    glVertex3f(-0.36, 0.59, 0.0);
    glVertex3f(-0.26, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.26, 0.58, 0.0);
    glVertex3f(-0.36, 0.58, 0.0);
    glVertex3f(-0.36, 0.48, 0.0);
    glVertex3f(-0.26, 0.48, 0.0);
    glEnd();

    // coluna5

    glBegin(GL_POLYGON);
    glVertex3f(-0.15, 0.8, 0.0);
    glVertex3f(-0.25, 0.8, 0.0);
    glVertex3f(-0.25, 0.7, 0.0);
    glVertex3f(-0.15, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.15, 0.69, 0.0);
    glVertex3f(-0.25, 0.69, 0.0);
    glVertex3f(-0.25, 0.59, 0.0);
    glVertex3f(-0.15, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.15, 0.58, 0.0);
    glVertex3f(-0.25, 0.58, 0.0);
    glVertex3f(-0.25, 0.48, 0.0);
    glVertex3f(-0.15, 0.48, 0.0);
    glEnd();

    // coluna6

    glBegin(GL_POLYGON);
    glVertex3f(-0.04, 0.8, 0.0);
    glVertex3f(-0.14, 0.8, 0.0);
    glVertex3f(-0.14, 0.7, 0.0);
    glVertex3f(-0.04, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.04, 0.69, 0.0);
    glVertex3f(-0.14, 0.69, 0.0);
    glVertex3f(-0.14, 0.59, 0.0);
    glVertex3f(-0.04, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.04, 0.58, 0.0);
    glVertex3f(-0.14, 0.58, 0.0);
    glVertex3f(-0.14, 0.48, 0.0);
    glVertex3f(-0.04, 0.48, 0.0);
    glEnd();

    // coluna7 

    glBegin(GL_POLYGON);
    glVertex3f(0.07, 0.8, 0.0);
    glVertex3f(-0.03, 0.8, 0.0);
    glVertex3f(-0.03, 0.7, 0.0);
    glVertex3f(0.07, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.07, 0.69, 0.0);
    glVertex3f(-0.03, 0.69, 0.0);
    glVertex3f(-0.03, 0.59, 0.0);
    glVertex3f(0.07, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.07, 0.58, 0.0);
    glVertex3f(-0.03, 0.58, 0.0);
    glVertex3f(-0.03, 0.48, 0.0);
    glVertex3f(0.07, 0.48, 0.0);
    glEnd();

    // coluna8 

    glBegin(GL_POLYGON);
    glVertex3f(0.18, 0.8, 0.0);
    glVertex3f(0.08, 0.8, 0.0);
    glVertex3f(0.08, 0.7, 0.0);
    glVertex3f(0.18, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.18, 0.69, 0.0);
    glVertex3f(0.08, 0.69, 0.0);
    glVertex3f(0.08, 0.59, 0.0);
    glVertex3f(0.18, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.18, 0.58, 0.0);
    glVertex3f(0.08, 0.58, 0.0);
    glVertex3f(0.08, 0.48, 0.0);
    glVertex3f(0.18, 0.48, 0.0);
    glEnd();

    // coluna9 

    glBegin(GL_POLYGON);
    glVertex3f(0.29, 0.8, 0.0);
    glVertex3f(0.19, 0.8, 0.0);
    glVertex3f(0.19, 0.7, 0.0);
    glVertex3f(0.29, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.29, 0.69, 0.0);
    glVertex3f(0.19, 0.69, 0.0);
    glVertex3f(0.19, 0.59, 0.0);
    glVertex3f(0.29, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.29, 0.58, 0.0);
    glVertex3f(0.19, 0.58, 0.0);
    glVertex3f(0.19, 0.48, 0.0);
    glVertex3f(0.29, 0.48, 0.0);
    glEnd();

    // coluna10 

    glBegin(GL_POLYGON);
    glVertex3f(0.40, 0.8, 0.0);
    glVertex3f(0.30, 0.8, 0.0);
    glVertex3f(0.30, 0.7, 0.0);
    glVertex3f(0.40, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.40, 0.69, 0.0);
    glVertex3f(0.30, 0.69, 0.0);
    glVertex3f(0.30, 0.59, 0.0);
    glVertex3f(0.40, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.40, 0.58, 0.0);
    glVertex3f(0.30, 0.58, 0.0);
    glVertex3f(0.30, 0.48, 0.0);
    glVertex3f(0.40, 0.48, 0.0);
    glEnd();

    // coluna11

    glBegin(GL_POLYGON);
    glVertex3f(0.51, 0.8, 0.0);
    glVertex3f(0.41, 0.8, 0.0);
    glVertex3f(0.41, 0.7, 0.0);
    glVertex3f(0.51, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.51, 0.69, 0.0);
    glVertex3f(0.41, 0.69, 0.0);
    glVertex3f(0.41, 0.59, 0.0);
    glVertex3f(0.51, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.51, 0.58, 0.0);
    glVertex3f(0.41, 0.58, 0.0);
    glVertex3f(0.41, 0.48, 0.0);
    glVertex3f(0.51, 0.48, 0.0);
    glEnd();

    // coluna12

    glBegin(GL_POLYGON);
    glVertex3f(0.62, 0.8, 0.0);
    glVertex3f(0.52, 0.8, 0.0);
    glVertex3f(0.52, 0.7, 0.0);
    glVertex3f(0.62, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.62, 0.69, 0.0);
    glVertex3f(0.52, 0.69, 0.0);
    glVertex3f(0.52, 0.59, 0.0);
    glVertex3f(0.62, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.62, 0.58, 0.0);
    glVertex3f(0.52, 0.58, 0.0);
    glVertex3f(0.52, 0.48, 0.0);
    glVertex3f(0.62, 0.48, 0.0);
    glEnd();

    // coluna13

    glBegin(GL_POLYGON);
    glVertex3f(0.73, 0.8, 0.0);
    glVertex3f(0.63, 0.8, 0.0);
    glVertex3f(0.63, 0.7, 0.0);
    glVertex3f(0.73, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.73, 0.69, 0.0);
    glVertex3f(0.63, 0.69, 0.0);
    glVertex3f(0.63, 0.59, 0.0);
    glVertex3f(0.73, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.73, 0.58, 0.0);
    glVertex3f(0.63, 0.58, 0.0);
    glVertex3f(0.63, 0.48, 0.0);
    glVertex3f(0.73, 0.48, 0.0);
    glEnd();

    // coluna14

    glBegin(GL_POLYGON);
    glVertex3f(0.84, 0.8, 0.0);
    glVertex3f(0.74, 0.8, 0.0);
    glVertex3f(0.74, 0.7, 0.0);
    glVertex3f(0.84, 0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.84, 0.69, 0.0);
    glVertex3f(0.74, 0.69, 0.0);
    glVertex3f(0.74, 0.59, 0.0);
    glVertex3f(0.84, 0.59, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.84, 0.58, 0.0);
    glVertex3f(0.74, 0.58, 0.0);
    glVertex3f(0.74, 0.48, 0.0);
    glVertex3f(0.84, 0.48, 0.0);
    glEnd();

    //bola

    glLoadIdentity();
    glColor3f(255.0, 0.0, 0.0);
    glTranslatef(ballx, bally, 0.0);
    drawHollowCircle(0.0, 0.0, 0.02);


}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    ballMove();
    desenhaQ();
    glFlush();
}



//callback de teclado
static void Key(unsigned char key, int x, int y)
{
    //automatic increment c - cima = 1, v - baixo = 2, x - esquerda = 3, b direita = 4
    switch (key) {
    case 'c':
        automatinc = 1;
        break;
    case 'v':
        automatinc = 2;
        break;
    case 'x':
        automatinc = 3;
        break;
    case 'b':
        automatinc = 4;
        break;
    case 'w':
        if (p1X <= 0.6) {
            p1X += 0.1;
        }
        else {
            p1X = 0.7;
        }
        glutPostRedisplay();
        break;
    case 's':
        if (p1X >= -0.7) p1X -= 0.1;
        glutPostRedisplay();
        break;
 /*   case 'u':
        ballx += 0.01;
        bally += 0.01;
        printf("ballx %f, bally %f, %d \n", ballx, bally, collisionDetec());
        glutPostRedisplay();
        break;
    case 'h':
        ballx -= 0.01;
        bally -= 0.01;
        printf("ballx %f, bally %f, %d \n", ballx, bally, collisionDetec());
        glutPostRedisplay();
        break;
    case 'j':
        ballx += 0.01;
        bally -= 0.01;
        printf("ballx %f, bally %f, %d \n", ballx, bally, collisionDetec());
        glutPostRedisplay();
        break;
    case 'y':
        ballx -= 0.01;
        bally += 0.01;
        printf("ballx %f, bally %f, %d \n", ballx, bally, collisionDetec());
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
    }
}
*/


int main(int argc, char** argv)
{
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformadas");
    ballMove();
    glutDisplayFunc(displayMe);
    //glutKeyboardUpFunc(Key);
    glutMainLoop();
    return 0;
}







