#include<GL/glu.h>
#include<GL/glut.h>
#include<windows.h>
#include<stdio.h>

GLfloat cx=0,cy=0,cz=3;

void Key(unsigned char ch,int x, int y)
{
    switch(ch)
    {
        case 'x':   cx-=1; break;
        case 'X':   cx+=1; break;
        case 'y':   cy-=1; break;
        case 'Y':   cy+=1; break;
        case 'z':   cz-=1; break;
        case 'Z':   cz+=1; break;
    }
    glutPostRedisplay();
}


void face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])
{
    glBegin(GL_POLYGON);
        glVertex3fv(A);
        glVertex3fv(B);
        glVertex3fv(C);
        glVertex3fv(D);
    glEnd();
}

void Draw()
{
    GLfloat v[8][3]=    {
                            { 0.5, 0.5,-0.5},
                            {-0.5, 0.5,-0.5},
                            {-0.5,-0.5,-0.5},
                            { 0.5,-0.5,-0.5},

                            { 0.5, 0.5, 0.5},
                            {-0.5, 0.5, 0.5},
                            {-0.5,-0.5, 0.5},
                            { 0.5,-0.5, 0.5}
                        };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1);
    glLoadIdentity();

    gluLookAt(cx,cy,cz,0,0,0,0,1,0);
    glColor3f(1,0,0);
    face(v[0],v[1],v[2],v[3]);
    glColor3f(0,1,0);
    face(v[4],v[5],v[6],v[7]);
    glColor3f(0,0,1);
    face(v[0],v[1],v[5],v[4]);
    glColor3f(1,1,0);
    face(v[1],v[2],v[6],v[5]);
    glColor3f(0,1,1);
    face(v[2],v[3],v[7],v[6]);
    glColor3f(1,0,1);
    face(v[3],v[0],v[4],v[7]);


    glutSwapBuffers();
}

void myInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int c,char **v)
{
    glutInit(&c,v);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("L4");
    myInit();
    glutDisplayFunc(Draw);
    glutKeyboardFunc(Key);

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;

}
