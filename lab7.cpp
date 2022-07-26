#include<GL/glu.h>
#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
int n;

void tri(GLfloat A[],GLfloat B[],GLfloat C[])
{
    glBegin(GL_POLYGON);
        glVertex3fv(A);
        glVertex3fv(B);
        glVertex3fv(C);
    glEnd();
}

void div(GLfloat v1[],GLfloat v2[],GLfloat v3[],GLfloat v4[],int n)
{
    GLfloat v12[3],v23[3],v13[3],v14[3],v24[3],v34[3];
    int i;

    if(n>0)
    {
        for(i=0;i<3;i++)
        {
            v12[i]= (v1[i]+v2[i])/2;
            v23[i]= (v3[i]+v2[i])/2;
            v13[i]= (v1[i]+v3[i])/2;
            v14[i]= (v1[i]+v4[i])/2;
            v24[i]= (v2[i]+v4[i])/2;
            v34[i]= (v3[i]+v4[i])/2;
        }
        div(v1,v12,v13,v14,n-1);
        div(v12,v2,v23,v24,n-1);
        div(v13,v23,v3,v34,n-1);
        div(v14,v24,v34,v4,n-1);
    }
    else
    {
        glColor3f(1,0,0);
        tri(v1,v2,v3);
        glColor3f(1,1,0);
        tri(v1,v2,v4);
        glColor3f(0,0,1);
        tri(v2,v3,v4);
        glColor3f(0,1,0);
        tri(v3,v1,v4);

    }
}

void Draw()
{
    GLfloat p[4][3]=    {
                            {-0.8,-0.8,-0.8},
                            { 0.8,-0.8,-0.8},
                            { 0.0, 0.0, 0.8},
                            { 0.0, 0.8, 0.0}
                        };
    //GLfloat pos[4]={0,1,0,1};
    //GLfloat col[4]={1,0,0,1};


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1,1,1,1);

    //glLightfv(GL_LIGHT0,GL_POSITION,pos);
    //glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
    div(p[0],p[1],p[2],p[3],n);

    glutSwapBuffers();
}

int main(int c,char **v)
{
    printf("Enter division\t:");
    scanf("%d",&n);
    glutInit(&c,v);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("L7");
    glutDisplayFunc(Draw);

    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutMainLoop();
    return 0;
}
