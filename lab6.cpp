#include<GL/glu.h>
#include<GL/glut.h>
#include<windows.h>

GLfloat r=0;
GLfloat pos[4]={0,1,0,1};
GLfloat col[4]={1,1,1,1};
GLfloat col1[4]={1,0,0,1};
GLfloat col2[4]={0,1,0,1};
GLfloat col3[4]={1,1,0,1};


void Spin()
{
    r +=0.03;
    if(r>360)
        r=0;
    glutPostRedisplay();
}

void tableLeg()
{
        glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,col1);
        glPushMatrix();
            glTranslatef(0.5,0,0.5);
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.5,0,0.5);
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.5,0,-0.5);
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.5,0,-0.5);
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();
}

void tableTop()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,col2);
        glPushMatrix();
        glTranslatef(0,0.5,0);
            glScalef(1,.1,1);
            glutSolidCube(1.2);
        glPopMatrix();
    glPopAttrib();
}

void teapot()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,col3);
        glPushMatrix();
        glTranslatef(0,.78,0);
        glutSolidTeapot(.3);
        glPopMatrix();
    glPopAttrib();
}

void Draw()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,col);

    gluLookAt(0,1,3,0,0,0,0,1,0);
    glTranslatef(0,-.3,0);
    glRotatef(r,0,1,0);


    tableLeg();
    tableTop();
    teapot();

    glutSwapBuffers();
}

void myInit()
{
    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int c, char **v)
{
    glutInit(&c,v);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("L6");
    myInit();
    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutMainLoop();
    return 0;
}
