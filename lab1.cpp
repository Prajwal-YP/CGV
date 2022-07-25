#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<windows.h>


void Draw()
{
    GLfloat x1=100,y1=250,x2=250,y2=100;
    GLfloat m,p,dx,dy,x,y,t;

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);

    if(x1==x2)
        m=y2-y1;
    else
        m=(y2-y1)/(x2-x1);



    if(fabs(m)<1)
    {
        if(x1>x2)
        {
            t=x1;   x1=x2;  x2=t;
            t=y1;   y1=y2;  y2=t;
        }

        dx=fabs(x2-x1);
        dy=fabs(y2-y1);

        p=2*dy-dx;
        x=x1;
        y=y1;

        glBegin(GL_POINTS);
            while(x<=x2)
            {
                glVertex2f(x,y);
                x++;

                if(p>=0)
                {
                    if(m>0)
                        y++;
                    else
                        y--;
                    p+=2*dy-2*dx;
                }
                else
                    p+=2*dy;
            }
        glEnd();

    }
    else
    {
        if(y1>y2)
        {
            t=x1;   x1=x2;  x2=t;
            t=y1;   y1=y2;  y2=t;
        }

        dx=fabs(x2-x1);
        dy=fabs(y2-y1);

        p=2*dx-dy;
        x=x1;
        y=y1;


        glBegin(GL_POINTS);
            while(y<=y2)
            {
                glVertex2f(x,y);
                y++;

                if(p>=0)
                {
                    if(m>0)
                        x++;
                    else
                        x--;
                    p+=2*dx-2*dy;
                }
                else
                    p+=2*dx;
            }
        glEnd();
    }


    glFlush();

}

void myInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int c,char **v)
{
    glutInit(&c,v);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("L1");
    myInit();
    glutDisplayFunc(Draw);

    glutMainLoop();
    return 0;
}
