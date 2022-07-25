#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<windows.h>

GLfloat R,px,py;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);


    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.1,0);
        glVertex2f(0.5,0);
        glVertex2f(0.3,0.5);
    glEnd();


    glTranslatef(px,py,0);
    glRotatef(R,0,0,1);
    glTranslatef(-px,-py,0);

    glColor3f(1,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.1,0);
        glVertex2f(0.5,0);
        glVertex2f(0.3,0.5);
    glEnd();

    glFlush();
}

int main(int c,char **v)
{
    printf("PIVIOT POINT\t:");
    scanf("%f%f",&px,&py);
    printf("\nROTATION\t:");
    scanf("%f",&R);

    glutInit(&c,v);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("L2");
    glutDisplayFunc(Draw);

    glutMainLoop();
    return 0;
}
