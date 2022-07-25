#include<GL/glu.h>
#include<GL/glut.h>
#include<windows.h>

GLfloat xmin=-.5,xmax=.5,ymin=-.5,ymax=.5,x1=-.8,y1=-.4,x2=.8,y2=.3;
int c1,c2,l=1,r=2,b=4,t=8,flag=1,clip_flag=0;

int get_code(GLfloat x,GLfloat y)
{
   int code=0;
   if(x<xmin)
        code = code | l;
   if(x>xmax)
        code = code | r;
   if(y<ymin)
        code = code | b;
   if(y>ymax)
        code = code | t;
    return code;
}

void clip()
{
    int c;
    float x,y;
    if(c1)
        c=c1;
    else
        c=c2;

    if(c&l)
    {
        x=xmin;
        y=y1+(y2-y1)*((xmin-x1)/(x2-x1));
    }
    if(c&r)
    {
        x=xmax;
        y=y1+(y2-y1)*((xmax-x1)/(x2-x1));
    }
    if(c&b)
    {
        y=ymin;
        x=x1+(x2-x1)*((ymin-y1)/(y2-y1));
    }
    if(c&t)
    {
        y=ymax;
        x=x1+(x2-x1)*((ymax-y1)/(y2-y1));
    }
    if(c==c1)
    {
        x1=x;
        y1=y;
    }
    else
    {
        x2=x;
        y2=y;
    }
}

void key(unsigned char ch, int x, int y)
{
    clip_flag=1;
    glutPostRedisplay();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,1);
    glLoadIdentity();
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin,ymin);
        glVertex2f(xmin,ymax);
        glVertex2f(xmax,ymax);
        glVertex2f(xmax,ymin);
    glEnd();

    if(flag==1)
    {
        glBegin(GL_LINES);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
        glEnd();
    }

    while(1 & clip_flag==1)
    {
        c1=get_code(x1,y1);
        c2=get_code(x2,y2);

        if((c1|c2)==0)
            break;
        else if((c1&c2)!=0)
        {
            flag=0;
            break;
        }
        else
            clip();
    }

    glFlush();
}

int main(int c,char **v)
{
    glutInit(&c,v);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("L5");
    glutDisplayFunc(Draw);
    glutKeyboardFunc(key);

    glutMainLoop();
    return 0;
}
