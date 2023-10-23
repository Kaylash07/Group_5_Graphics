#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/gl.h>

////-------------CLASSROOM CODE START---------------////
///------CLASSROOM CODE COLOUR CODE START--------///



///------CLASSROOM CODE COLOUR CODE END--------///

///------CLASSROOM VOID CODE START--------///


///------CLASSROOM VOID CODE END--------///




///------TABLE COLOUR CODE START--------///
//table_surface_colour
GLfloat mat_surface_ambient[] = { 0.8, 0.4, 0.1, 1.0 }; // Adjusted for a more orange ambient color
GLfloat mat_surface_diffuse[] = { 0.8, 0.4, 0.1, 1.0 }; // Adjusted for a more orange diffuse color
GLfloat mat_surface_specular[] = { 0.1, 0.1, 0.1, 1.0 }; // Specular color is usually less intense
GLfloat mat_surface_shininess = 10.0;                  // Adjusted for a moderate shininess
//table_frame_colour
GLfloat mat_legs_ambient[] = { 0.05, 0.05, 0.05, 1.0 }; // Adjusted for a darker ambient color
GLfloat mat_legs_diffuse[] = { 0.05, 0.05, 0.05, 1.0 }; // Adjusted for a darker diffuse color
GLfloat mat_legs_specular[] = { 0.1, 0.1, 0.1, 1.0 };  // Specular color is usually less intense
GLfloat mat_legs_shininess = 50.0;                   // Adjusted for a relatively high shininess

//PC color (darker gray)
GLfloat mat_pc_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // Ambient color for plastic
GLfloat mat_pc_diffuse[] = { 0.7, 0.7, 0.7, 1.0 }; // Diffuse color for plastic
GLfloat mat_pc_specular[] = { 0.1, 0.1, 0.1, 1.0 }; // Specular color for plastic
GLfloat mat_pc_shininess = 10.0; // Shininess of the plastic surface


//PC screen color (black)
GLfloat mat_screen_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // Ambient color for glass
GLfloat mat_screen_diffuse[] = { 0.1, 0.1, 0.1, 0.8 }; // Diffuse color for glass
GLfloat mat_screen_specular[] = { 0.9, 0.9, 0.9, 1.0 }; // Specular color for glass
GLfloat mat_screen_shininess = 50.0; // Shininess of the glass surface


///------TABLE COLOUR CODE END--------///

///------CHAIR COLOUR CODE START--------///
//chair_colour
GLfloat mat_chair_ambient[] = { 0.396, 0.263, 0.129, 5.0 }; // Darker brown ambient color
GLfloat mat_chair_diffuse[] = { 0.396, 0.263, 0.129, 5.0 }; // Darker brown diffuse color
GLfloat mat_chair_specular[] = { 0.396, 0.263, 0.129, 5.0 }; // Darker brown specular color
GLfloat mat_chair_shininess = 2.0;
///------CHAIR COLOUR CODE END--------///







///------TABLE VOID CODE START--------///
//Table
void leg()
{
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScalef(20, 400, 20);
    glutSolidCube(1.0);
    glPopMatrix();
}
void legjoin1()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(20, 20, 270);
    glutSolidCube(1.0);
    glPopMatrix();
}
void legjoin2()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(110, 20, 20);
    glutSolidCube(1.0);
    glPopMatrix();
}
void legjoin3()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(900, 20, 20);
    glutSolidCube(1.0);
    glPopMatrix();
}
void legjoin4()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(20, 20, 270);
    glutSolidCube(1.0);
    glPopMatrix();
}
void vertical_mesh()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(4, 360, 4);
    glutSolidCube(1.0);
    glPopMatrix();
}
void horizontal_mesh()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(4, 4, 280);
    glutSolidCube(1.0);
    glPopMatrix();
}
void meshes()
{
    //vertical mesh()
    glPushMatrix();
    glTranslatef(+435, -180, 125);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 115);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 105);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 95);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 85);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 75);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 65);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 55);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 45);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 35);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 25);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 15);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 5);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -5);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -15);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -25);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -35);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -45);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -55);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -65);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -75);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -85);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -95);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -105);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -115);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -125);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -135);
    vertical_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, -145);
    vertical_mesh();
    glPopMatrix();
    //horizontal mesh
    glPushMatrix();
    glTranslatef(+435, -45, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -60, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -75, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -90, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -105, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -120, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -135, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -150, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -165, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -180, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -195, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -205, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -220, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -235, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -250, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -265, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -280, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -295, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -310, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -325, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -340, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -325, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -340, 0);
    horizontal_mesh();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+435, -355, 0);
    horizontal_mesh();
    glPopMatrix();
}
void Table_Frame()
{
    //legs
    glPushMatrix();
    glTranslatef(-330, -210, -140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-330, -210, +140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+330, -210, -140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+330, -210, +140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+440, -210, +140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-440, -210, +140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-440, -210, -140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+440, -210, -140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+0, -210, -140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+120, -210, -140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+0, -210, +140);
    leg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+120, -210, +140);
    leg();
    glPopMatrix();
    //legjoin1
    glPushMatrix();
    glTranslatef(+120, -350, 0);
    legjoin1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+0, -350, 0);
    legjoin1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+330, -350, 0);
    legjoin1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-330, -350, 0);
    legjoin1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+440, -350, 0);
    legjoin1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-440, -350, 0);
    legjoin1();
    glPopMatrix();
    //legjoin2
    glPushMatrix();
    glTranslatef(-380, -350, 140);
    legjoin2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-380, -350, -140);
    legjoin2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60, -350, -140);
    legjoin2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60, -350, +140);
    legjoin2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+380, -350, -140);
    legjoin2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+380, -350, 140);
    legjoin2();
    glPopMatrix();
    //legjoin3
    glPushMatrix();
    glTranslatef(+0, -20, 140);
    legjoin3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+0, -20, -140);
    legjoin3();
    glPopMatrix();
    //legjoin4
    glPushMatrix();
    glTranslatef(+120, -20, 0);
    legjoin4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+0, -20, 0);
    legjoin4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+330, -20, 0);
    legjoin4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-330, -20, 0);
    legjoin4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(+440, -20, 0);
    legjoin4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-440, -20, 0);
    legjoin4();
    glPopMatrix();
    //meshes
    glPushMatrix();
    glTranslatef(10, 0, 0);
    meshes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-110, 0, 0);
    meshes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-310, 0, 0);
    meshes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-440, 0, 0);
    meshes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-310, 0, 0);
    meshes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-440, 0, 0);
    meshes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-760, 0, 0);
    meshes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-880, 0, 0);
    meshes();
    glPopMatrix();
}
void surfaces()
{
    //surfaces1 1
    glPushMatrix();
    glTranslatef(0, 0, 20);
    glScalef(900, 20, 370);
    glutSolidCube(1.0);
    glPopMatrix();
    //compartmentp1_1
    glPushMatrix();
    glTranslatef(0, -40, +200);
    glScalef(900, 100, 10);
    glutSolidCube(1.0);
    glPopMatrix();
    //compartmentp1_2
    glPushMatrix();
    glTranslatef(0, -80, +180);
    glScalef(900, 20, 50);
    glutSolidCube(1.0);
    glPopMatrix();
    //compartmentp1_3
    glPushMatrix();
    glTranslatef(+440, -50, +180);
    glScalef(20, 80, 50);
    glutSolidCube(1.0);
    glPopMatrix();
    //compartmentp1_4
    glPushMatrix();
    glTranslatef(-440, -50, +180);
    glScalef(20, 80, 50);
    glutSolidCube(1.0);
    glPopMatrix();
    //frontcover1
    glPushMatrix();
    glTranslatef(0, -180, +150);
    glScalef(900, 360, 10);
    glutSolidCube(1.0);
    glPopMatrix();
    //towerholder1_1
    glPushMatrix();
    glTranslatef(+380, -350, 0);
    glScalef(100, 20, 280);
    glutSolidCube(1.0);
    glPopMatrix();
    //towerholder1_2
    glPushMatrix();
    glTranslatef(+60, -350, 0);
    glScalef(100, 20, 280);
    glutSolidCube(1.0);
    glPopMatrix();
    //towerholder1_3
    glPushMatrix();
    glTranslatef(-380, -350, 0);
    glScalef(100, 20, 280);
    glutSolidCube(1.0);
    glPopMatrix();
}
//pc_tower
void tower()
{
    //box
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(80, 310, 250);
    glutSolidCube(1.0);
    glPopMatrix();
}
void monitor()
{
    //screen_cover
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(120, 100, 4);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60, 0, -1);
    glScalef(10, 100, 7);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60, 0, -1);
    glScalef(10, 100, 7);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -50, -1);
    glScalef(130, 10, 7);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 50, -1);
    glScalef(130, 10, 7);
    glutSolidCube(1.0);
    glPopMatrix();
    //neck
    glPushMatrix();
    glTranslatef(0, -70, -1);
    glScalef(10, 30, 7);
    glutSolidCube(1.0);
    glPopMatrix();
    //base
    glPushMatrix();
    glTranslatef(0, -90, -1);
    glScalef(70, 10, 40);
    glutSolidCube(1.0);
    glPopMatrix();
}
void screen()
{
    //screen1
    glPushMatrix();
    glTranslatef(230, 100, 46.9);
    glScalef(120, 100, 1);
    glutSolidCube(1.0);
    glPopMatrix();
    //screen2
    glPushMatrix();
    glTranslatef(-230, 100, 46.9);
    glScalef(120, 100, 1);
    glutSolidCube(1.0);
    glPopMatrix();
    //screen3
    glPushMatrix();
    glTranslatef(-80, 100, 46.9);
    glScalef(120, 100, 1);
    glutSolidCube(1.0);
    glPopMatrix();
}
//keyboard
void board()
{
    glPushMatrix();
    glTranslatef(-1, 0, 0);
    glScalef(105, 10, 40);
    glutSolidCube(1.0);
    glPopMatrix();
}
void key()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(5, 10, 5);
    glutSolidCube(1.0);
    glPopMatrix();
}
void keys_row()
{
    glPushMatrix();
    glTranslatef(275, 15, -30);
    key();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(275, 15, -37);
    key();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(275, 15, -44);
    key();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(275, 15, -51);
    key();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(275, 15, -58);
    key();
    glPopMatrix();
}
//ALL_KEYS
void keys_master()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-14, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-21, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-42, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-49, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-56, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-63, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-77, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-84, 0, 0);
    keys_row();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-91, 0, 0);
    keys_row();
    glPopMatrix();
}
void keyboard()
{
    glPushMatrix();
    glTranslatef(230, 10, -45);
    board();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    keys_master();
    glPopMatrix();
}
//ALL_PCs
void PC_master()
{
    //pc_tower1
    glPushMatrix();
    glTranslatef(385, -200, 0);
    tower();
    glPopMatrix();
    //pc_tower2
    glPushMatrix();
    glTranslatef(-385, -200, 0);
    tower();
    glPopMatrix();
    //pc_tower3
    glPushMatrix();
    glTranslatef(60, -200, 0);
    tower();
    glPopMatrix();
    //pc_monitor1
    glPushMatrix();
    glTranslatef(230, 100, 50);
    monitor();
    glPopMatrix();
    //pc_monitor2
    glPushMatrix();
    glTranslatef(-230, 100, 50);
    monitor();
    glPopMatrix();
    //pc_monitor1
    glPushMatrix();
    glTranslatef(-80, 100, 50);
    monitor();
    glPopMatrix();
    //Keyboard1
    glPushMatrix();
    glTranslatef(0, 0, 0);
    keyboard();
    glPopMatrix();
    //Keyboard2
    glPushMatrix();
    glTranslatef(-310, 0, 0);
    keyboard();
    glPopMatrix();
    //Keyboard3
    glPushMatrix();
    glTranslatef(-460, 0, 0);
    keyboard();
    glPopMatrix();
}

//Chair_Code
void chair()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_chair_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_chair_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_chair_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_chair_shininess);

    glPushMatrix();
    glTranslated(0, 400, 0);
    glScalef(15, 450, 15);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(100, 400, 0);
    glScalef(15, 450, 15);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 280, 100);
    glScalef(15, 200, 15);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(100, 280, 100);
    glScalef(15, 200, 15);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(50, 380, 50);
    glScalef(120, 20, 120);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(50, 500, 0);
    glScalef(110, 30, 15);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(50, 600, 0);
    glScalef(110, 30, 15);
    glutSolidCube(1.0);
    glPopMatrix();
}

//chair_1
void Chair_Master()
{

    glPushMatrix();
    glTranslatef(180, -580, -200);
    chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-150, -580, -200);
    chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-300, -580, -200);
    chair();
    glPopMatrix();
}

//Tables
void Table1()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_surface_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_surface_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_surface_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_surface_shininess);
    surfaces();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_legs_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_legs_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_legs_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_legs_shininess);
    Table_Frame();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_pc_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_pc_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_pc_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_pc_shininess);
    PC_master();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_screen_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_screen_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_screen_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_screen_shininess);
    screen();

    Chair_Master();
}
void Table2()
{
    glPushMatrix();
    glTranslatef(0, 0, -750);
    Table1();
    glPopMatrix();
}
void Table3()
{
    glPushMatrix();
    glTranslatef(0, 0, -1500);
    Table1();
    glPopMatrix();
}
void Table4()
{
    glPushMatrix();
    glTranslatef(1250, 0, -750);
    Table1();
    glPopMatrix();
}
void Table5()
{
    glPushMatrix();
    glTranslatef(1250, 0, -1500);
    Table1();
    glPopMatrix();
}
void Table6()
{
    glPushMatrix();
    glTranslatef(1250, 0, 0);
    Table1();
    glPopMatrix();
}

//ALL_TABLES
void Table_Master()
{
    glPushMatrix();
    glTranslatef(-500, 0, 0);
    Table1();
    Table2();
    Table3();
    Table4();
    Table5();
    Table6();
    glPopMatrix();
}
///------TABLE VOID CODE END--------///

void myinit()
{
    glViewport(0, 0, 50000, 50000);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1500, 1500, -1500, 1500, -3000, 3000);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat a[] = { 0.8,350.0,+350,1.0 };
    GLfloat b[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, a);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, b);
    glRotatef(10, 0.2, 1, 0.2);

    ///-----------LIGHT SOURCE CODE START--------///
    //Light_direction
    GLfloat light_direction[] = { -500.0, 500.0, -500.0, 0.0 };
    //Sunlight_colour
    GLfloat light_color[] = { 1.0, 1.0, 0.9, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_direction);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    ///-----------LIGHT SOURCE CODE END--------///

     ///------TABLE DISPLAY START--------///
    Table_Master();
    ///------TABLE DISPLAY END--------///

    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(50000, 50000);
    glutCreateWindow("Classroom");
    myinit();
    glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glutMainLoop();
}
