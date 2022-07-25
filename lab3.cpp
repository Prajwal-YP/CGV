#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<windows.h>

GLfloat r=0,a;

void Spin()
{
    r+=.03;
    if(r>360)
        r=0;
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

void cube(GLfloat v[][3])
{
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

    GLfloat rv[8][3],Q;
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1,1,1,1);

    glLoadIdentity();
    Q=r*(3.14/180);

    if(a==1)
    {
        for(i=0;i<8;i++)
        {
            rv[i][0]=v[i][0];
            rv[i][1]=v[i][1]*cos(Q)-v[i][2]*sin(Q);
            rv[i][2]=v[i][1]*sin(Q)+v[i][2]*cos(Q);
        }
    }
    if(a==2)
    {
        for(i=0;i<8;i++)
        {
            rv[i][0]=v[i][0]*cos(Q)+v[i][2]*sin(Q);
            rv[i][1]=v[i][1];
            rv[i][2]=-v[i][0]*sin(Q)+v[i][2]*cos(Q);
        }
    }
    if(a==3)
    {
        for(i=0;i<8;i++)
        {
            rv[i][0]=v[i][0]*cos(Q)-v[i][1]*sin(Q);
            rv[i][1]=v[i][0]*sin(Q)+v[i][1]*cos(Q);;
            rv[i][2]=v[i][2];
        }
    }

    cube(rv);

    glutSwapBuffers();
}

void myInit()
{

}

int main(int c, char **v)
{
    printf("Enter R-axis\t:");
    scanf("%f",&a);

    glutInit(&c,v);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("L3");
    myInit();
    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
    return 0;
}
