#include<iostream>
#include <math.h>
#include <GL/glut.h>
#define pi 3.142
#define WIN_WIDTH 1400
#define WIN_HEIGHT 1000
static GLfloat angle = 0;
static int submenu, mainmenu, value = -1;
float mov=5.0;
GLfloat camx,camy,camz=5.0f;
GLfloat anglex,angley,anglez;
int prevx,prevy, excitationRad=0;
bool excitation=false, nucleusAnimation=false;
GLenum Mouse=GLUT_UP;
using namespace std;
void init()
{
    glClearColor(0, 0, 0.1, 0.9);
    //glViewport(0,0,WIN_WIDTH,WIN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-800,800,-600,600,-1000,1000);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat light_position[]={1.0,1.0,1.0,0.0};
    GLfloat diffuseMaterial[4]={0.5,0.5,0.5,1.0};
    glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuseMaterial);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialf(GL_FRONT,GL_SHININESS,25.0);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glColorMaterial(GL_FRONT,GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}
void drawString(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);
    for (char *c = string; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
}
void drawhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);
    for (char *c = string; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}
void drawsubhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);
    for (char *c = string; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
}
void eleright(float rad)
{
    glColor3f(1, 1, 1);
    glTranslatef(rad,0,0);
    glutSolidSphere(20,16,16);
    glTranslatef(-rad,0,0);
}
void eleleft(float rad)
{
    glColor3f(1, 1, 1);
    glTranslatef(-rad, 0,0);
    glutSolidSphere(20,16,16);
    glTranslatef(rad,0,0);
}
void eletop(float rad)
{
    glColor3f(1, 1, 1);
    glTranslatef(0,rad,0);
    glutSolidSphere(20,16,16);
    glTranslatef(0,-rad,0);
}
void eledown(float rad)
{
    glColor3f(1, 1, 1);
    glTranslatef(0,-rad,0);
    glutSolidSphere(20,16,16);
    glTranslatef(0,rad,0);
}
void eletr(float rad)
{
    glColor3f(1, 1, 1);
    glTranslatef(rad-175,rad-175,0);
    glutSolidSphere(20,16,16);
    glTranslatef(175-rad,175-rad,0);
}
void eletl(float rad)
{
    glColor3f(1, 1, 1);
    glTranslatef(175-rad,rad-175,0);
    glutSolidSphere(20,16,16);
    glTranslatef(rad-175,175-rad,0);
}
void eledl(float rad)
{
    glColor3f(1, 1, 1);
    glTranslatef(175-rad,175-rad,0);
    glutSolidSphere(20,16,16);
    glTranslatef(rad-175,rad-175,0);
}
void eledr(float rad)
{
    glColor3f(1, 1, 1);
    glTranslatef(rad-175,175-rad,0);
    glutSolidSphere(20,16,16);
    glTranslatef(175-rad,rad-175,0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_NORMALIZE);
    glPushMatrix();
    glRotatef(angley,1.0f,0.0f,0.0f);
    glRotatef(anglex,0.0f,1.0f,0.0f);
    glRotatef(anglez,0.0f,0.0f,1.0f);
    if (value == -1)
    {
        char prn[] = "    Project On    ";
        drawsubhead(-165, 500, 0, prn);
        char pro[] = "ATOM SIMULATION";
        drawhead(-230, 400, 0, pro);
        char info[] = "Atom:        It is the smallest unit of matter that uniquely defines an element. ";
        drawhead(-690, 250, 0, info);
        char i[] ="      An atom consists of central nucleus that contains protons and neutrons";
        drawhead(-610, 200, 0, i);
        char el[] = "Electron:   Electrons are subatomic particles that revolve around the nucleus and are negatively charged.";
        drawhead(-690, 150, 0, el);
        char e[] = "    Ions can be formed by either the loss or gain of electrons.";
        drawhead(-590, 100, 0, e);
        char prot[] = "Proton:     Protons are positively charged subatomic particles that makes up the nucleus along with the neutron. ";
        drawhead(-690, 50, 0, prot);
        char p[] = "   The number of protons in an atom is equal to the number of electrons in it.";
        drawhead(-590, 0, 0, p);
        char neu[] = "Neutron:   Neutrons along with protons make up the nucleons and they do not carry any charge, that is, they are neutral.";
        drawhead(-690, -50, 0, neu);
        char pb[] = "PROJECT BY: ";
        drawhead(-200, -150, 0, pb);
        char p1[] = "K.Priyam";
        drawhead(-300, -250, 0, p1);
        char p1u[] = "19BCS052";
        drawsubhead(-300, -300, 0, p1u);
        char p2[] = "P.Goutam";
        drawhead(-25, -250, 0, p2);
        char p2u[] = "19BCS085";
        drawsubhead(-25, -300, 0, p2u);
        char in[] = "Press enter to Continue";
        drawhead(-225, -500, 0, in);
        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
    if (value != -1)
    {
        float k;
        glColor3f(0, 0, 1);
        mov-=0.2;
        for(int i=-250;i<=250;i+=10)
        {
            for(int j=0;j<360;j+=8)
            {
                if(nucleusAnimation)
                {
                    glPushMatrix();
                    glTranslated(mov*sqrt(62500-i*i)*cos((3.14/180)*j), mov*sqrt(62500-i*i)*sin((3.14/180)*j), mov*i);
                    glutSolidSphere(20,16,16);
                    glTranslated(-mov*sqrt(62500-i*i)*cos((3.14/180)*j), -mov*sqrt(62500-i*i)*sin((3.14/180)*j), -mov*i);
                    glPopMatrix();
                    if(mov<1)
                    {
                        nucleusAnimation=false;
                    }
                }
                else
                {
                    glPushMatrix();
                    glTranslated(sqrt(62500-i*i)*cos((3.14/180)*j), sqrt(62500-i*i)*sin((3.14/180)*j), i);
                    glutSolidSphere(20,16,16);
                    glTranslated(-sqrt(62500-i*i)*cos((3.14/180)*j), -sqrt(62500-i*i)*sin((3.14/180)*j), -i);
                    glPopMatrix();
                }

            }
        }
        //glutSolidSphere(250,16,16);
        char n[] = "NUCLEUS";
        drawString(-80, 20, 0, n);
        char d[] = "(NEUTRON + PROTON)";
        drawString(-155, -30, 0, d);
        if (value == 0)
        {
            char nu[] = "SELECT THE ELEMENT USING MENU";
            drawhead(-490, 900, 0, nu);
        }
    }
    if (value == 1)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-45,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        if(!excitation)
        {
            glRotatef(angle, 0, 0, 1);
            eleright(400);
            char e[] = "ELECTRON";
            drawString(420, 0, 0, e);
        }
        else
        {
            glRotatef(45,0.0f,1.0f,0.0f);
            glRotatef(angle, 0, 0, 1);
            eletop(800);
            glRotatef(-45,0.0f,1.0f,0.0f);
            char e[] = "ELECTRON";
            drawString(420, 0, 0, e);
        }
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 2)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-45,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        if(!excitation)
        {
            glRotatef(angle, 0, 0, 1);
            eleright(400);
            eleleft(400);
            char e[] = "ELECTRON";
            drawString(420, 0, 0, e);
        }
        else
        {
            glRotatef(angle, 0, 0, 1);
            eleleft(400);
            glRotatef(-angle, 0, 0, 1);
            glRotatef(45,0.0f,1.0f,0.0f);
            glRotatef(angle, 0, 0, 1);
            eletop(800);
            glRotatef(-45,0.0f,1.0f,0.0f);
            char e[] = "ELECTRON";
            drawString(420, 0, 0, e);
        }
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 3)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 600, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-90,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(-angle, 0, 0, 1);
        if(!excitation)
        {
            glRotatef(45,0.0f,1.0f,0.0f);
            glRotatef(angle, 0, 0, 1);
            eletop(600);
            glRotatef(-45,0.0f,1.0f,0.0f);
            char e[] = "ELECTRON";
            drawString(0, 620, 0, e);
        }
        else
        {
            glRotatef(90,0.0f,1.0f,0.0f);
            glRotatef(angle, 0, 0, 1);
            eletop(800);
            glRotatef(-90,0.0f,1.0f,0.0f);
            char e[] = "ELECTRON";
            drawString(0, 620, 0, e);
        }
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 4)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 600, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-90,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(-angle, 0, 0, 1);
        glRotatef(45,0.0f,1.0f,0.0f);
        glRotatef(angle, 0, 0, 1);
        eletop(600);
        eledown(600);
        glRotatef(-45,0.0f,1.0f,0.0f);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 5)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 600, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-90,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(-angle, 0, 0, 1);
        glRotatef(45,0.0f,1.0f,0.0f);
        glRotatef(angle, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 6)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 600, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-90,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(-angle, 0, 0, 1);
        glRotatef(45,0.0f,1.0f,0.0f);
        glRotatef(angle, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 7)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 600, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-90,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(-angle, 0, 0, 1);
        glRotatef(45,0.0f,1.0f,0.0f);
        glRotatef(angle, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 8)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 600, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-90,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(-angle, 0, 0, 1);
        glRotatef(45,0.0f,1.0f,0.0f);
        glRotatef(angle, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 9)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 600, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-90,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(-angle, 0, 0, 1);
        glRotatef(45,0.0f,1.0f,0.0f);
        glRotatef(angle, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 10)
    {
        glColor3f(1, 0, 0);
        glutSolidTorus(5, 400, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 600, 8, 128);
        glRotatef(45,0.0f,1.0f,0.0f);
        glutSolidTorus(5, 800, 8, 128);
        glRotatef(-90,0.0f,1.0f,0.0f);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(-angle, 0, 0, 1);
        glRotatef(45,0.0f,1.0f,0.0f);
        glRotatef(angle, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    glPopMatrix();
    glutSwapBuffers();
}
void rotate()
{

    angle = angle + 1.0;
    if (angle > 360)
        angle = angle - 360;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Sleep(70);
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 13)
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    else if (key == 'q' || key == 'Q')
    {
        exit(0);
    }
}
void menu(int option)
{
    if(option == 13)
    {
        exit(0);
    }
    else if (option == 11)
    {
        glutIdleFunc(rotate);
    }
    else if (option == 12)
    {
        glutIdleFunc(NULL);
    }
    else if(option==14)
    {
        value=-1;
    }
    else if(option==15)
    {
        excitation=true;
        excitationRad=200;
    }
    else
    {
        value = option;
        nucleusAnimation=true;
        mov=5;
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutPostRedisplay();
}
void createMenu(void)
{
    submenu = glutCreateMenu(menu);
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERILIUM", 4);
    glutAddMenuEntry("BORON", 5);
    glutAddMenuEntry("CARBON", 6);
    glutAddMenuEntry("NITROGEN", 7);
    glutAddMenuEntry("OXYGEN", 8);
    glutAddMenuEntry("FLUORINE", 9);
    glutAddMenuEntry("NEON", 10);
    mainmenu = glutCreateMenu(menu);
    glutAddSubMenu("SELECT THE ELEMENT", submenu);
    glutAddMenuEntry("START SIMULATION", 11);
    glutAddMenuEntry("STOP SIMULATION", 12);
    glutAddMenuEntry("GOTO HOME SCREEN",14);
    glutAddMenuEntry("EXCITATION",15);
    glutAddMenuEntry("EXIT", 13);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void mouse(int button,int state,int x,int y)
{
   switch(button)
   {
      case GLUT_LEFT_BUTTON:
         if(state==GLUT_DOWN)
         {
            Mouse=GLUT_DOWN;
            prevx=x;
            prevy=y;
         }
         if(state==GLUT_UP)
         {
            Mouse=GLUT_UP;
         }
         break;
      case GLUT_RIGHT_BUTTON:

         break;
   }
   glutPostRedisplay();
}

void motion(int x,int y)
{
   if(Mouse==GLUT_DOWN)
   {
      int deltax,deltay;
      deltax=prevx-x;
      deltay=prevy-y;
      anglex += 0.5*deltax;
      angley += 0.5*deltay;
      if(deltax!=0 && deltay!=0)
         anglez += 0.5*sqrt(deltax*deltax + deltay*deltay);
      if(anglex < 0)
         anglex+=360.0;
      if(angley < 0)
         angley+=360.0;
      if(anglez < 0)
         anglez += 360.0;
      if(anglex > 360.0)
         anglex-=360.0;
      if(angley > 360.0)
         angley-=360.0;
      if(anglez > 360.0)
         anglez-=360.0;
   }
   else
   {
      Mouse=GLUT_UP;
   }
   prevx=x;
   prevy=y;
   glutPostRedisplay();
}
int main(int argc, char **argv)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("ATOM SIMULATION");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    createMenu();
    glutMainLoop();
    return 0;
}
