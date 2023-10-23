#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>

///---------CAMERA CODE START--------///
int width = 800;
int height = 600;

float cameraX = -800.0f;
float cameraY = 0.0f;
float cameraZ = -3000.0f;
float cameraSpeed = 10.0f;
float cameraRotationSpeed = 1.0f;

float cameraPitch = -90.0f;
float cameraYaw = -360.0f;

void reshape(int w, int h)
{
    width = w;
    height = h;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 1000000.0);
    glMatrixMode(GL_MODELVIEW);
}

void moveCamera(float directionX, float directionY, float directionZ)
{
    glm::vec3 cameraFront;
    cameraFront.x = cos(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
    cameraFront.y = sin(glm::radians(cameraPitch));
    cameraFront.z = sin(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));

    glm::vec3 cameraRight = glm::normalize(glm::cross(cameraFront, glm::vec3(0.0f, 0.0f, 1.0f)));
    glm::vec3 cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));

    glm::vec3 cameraPosition(cameraX, cameraY, cameraZ);
    cameraPosition += directionX * cameraSpeed * cameraRight;
    cameraPosition += directionY * cameraSpeed * cameraFront;
    cameraPosition += directionZ * cameraSpeed * cameraUp;

    cameraX = cameraPosition.x;
    cameraY = cameraPosition.y;
    cameraZ = cameraPosition.z;
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a': // Move or turn left
        moveCamera(-1, 0, 0);
        break;
    case 'd': // Move or turn right
        moveCamera(1, 0, 0);
        break;
    case 'w': // Move or turn up
        moveCamera(0, 1, 0);
        break;
    case 's': // Move or turn down
        moveCamera(0, -1, 0);
        break;
    case 'q': // Move forward
        moveCamera(0, 0, 1);
        break;
    case 'e': // Move backward
        moveCamera(0, 0, -1);
        break;
    case 'j': // Turn left
        cameraYaw -= cameraRotationSpeed;
        break;
    case 'l': // Turn right
        cameraYaw += cameraRotationSpeed;
        break;
    case 'i': // Turn up
        cameraPitch += cameraRotationSpeed;
        if (cameraPitch > 89.0f)
            cameraPitch = 89.0f;
        break;
    case 'k': // Turn down
        cameraPitch -= cameraRotationSpeed;
        if (cameraPitch < -89.0f)
            cameraPitch = -89.0f;
        break;
    }

    glutPostRedisplay();
}

void updateCameraView()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glm::vec3 cameraFront;
    cameraFront.x = cos(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
    cameraFront.y = sin(glm::radians(cameraPitch));
    cameraFront.z = sin(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));

    glm::vec3 cameraTarget = glm::vec3(cameraX, cameraY, cameraZ) + cameraFront;
    glm::vec3 cameraUp = glm::vec3(0.0f, 0.0f, 1.0f);

    glm::mat4 view = glm::lookAt(glm::vec3(cameraX, cameraY, cameraZ), cameraTarget, cameraUp);
    glLoadMatrixf(glm::value_ptr(view));
}
///---------CAMERA CODE END--------///



////-------------CLASSROOM CODE START---------------////
///------CLASSROOM CODE COLOUR CODE START--------///
//floor_surface_colour
GLfloat mat_floor_ambient[] = { 0.1, 0.1, 0.2, 1.0 }; // Adjusted for a faded navy blue ambient color
GLfloat mat_floor_diffuse[] = { 0.1, 0.1, 0.2, 1.0 }; // Adjusted for a faded navy blue diffuse color
GLfloat mat_floor_specular[] = { 0.05, 0.05, 0.1, 1.0 }; // Adjusted for a less intense specular color
GLfloat mat_floor_shininess = 5.0; // Adjusted for a moderate shininess
//wall_surface_colour
GLfloat mat_wall_ambient[] = { 0.9, 0.8, 0.6, 1.0 }; // Adjusted for beige ambient color
GLfloat mat_wall_diffuse[] = { 0.9, 0.8, 0.6, 1.0 }; // Adjusted for beige diffuse color
GLfloat mat_wall_specular[] = { 0.2, 0.2, 0.2, 1.0 }; // You can keep the specular color the same
GLfloat mat_wall_shininess = 10.0; // You can adjust shininess as desired
//ceiling_surface_colour
GLfloat mat_ceiling_ambient[] = { 0.8, 0.8, 0.8, 1.0 }; // Adjusted for light gray ambient color
GLfloat mat_ceiling_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // Adjusted for light gray diffuse color
GLfloat mat_ceiling_specular[] = { 0.2, 0.2, 0.2, 1.0 }; // You can keep the specular color the same
GLfloat mat_ceiling_shininess = 10.0; // You can adjust shininess as desired






///------CLASSROOM CODE COLOUR CODE END--------///





///ADD LIBRARIES///








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
//PC cover/monitor color
GLfloat mat_pc_ambient[] = { 0.05, 0.05, 0.05, 1.0 }; // Darkened ambient color for almost black plastic
GLfloat mat_pc_diffuse[] = { 0.1, 0.1, 0.1, 1.0 }; // Darkened diffuse color for almost black plastic
GLfloat mat_pc_specular[] = { 0.01, 0.01, 0.01, 1.0 }; // Darkened specular color for almost black plastic
GLfloat mat_pc_shininess = 10.0; // Shininess of the almost black plastic surface
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

///------SKY COLOUR CODE START--------///
//sky_colour
GLfloat mat_sky_ambient[] = { 0.529, 0.808, 0.922, 1.0 }; // Light blue ambient color
GLfloat mat_sky_diffuse[] = { 0.529, 0.808, 0.922, 1.0 }; // Light blue diffuse color
GLfloat mat_sky_specular[] = { 0.529, 0.808, 0.922, 1.0 }; // Light blue specular color
GLfloat mat_sky_shininess = 30.0; // Adjust the shininess as needed
///------SKY COLOUR CODE END--------///











///ADD COLOURS///



///------SKY VOID CODE START--------///
void Sky()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_sky_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_sky_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_sky_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_sky_shininess);

}
///------SKY VOID CODE END--------///


///------CLASSROOM VOID CODE START--------///

void floor()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_floor_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_floor_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_floor_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_floor_shininess);

    glPushMatrix();
    glTranslated(0, -430, -400);
    glScalef(2500, 50, 3500);
    glutSolidCube(1.0);
    glPopMatrix();
}

void walls()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_wall_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_wall_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_wall_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_wall_shininess);

    glPushMatrix();
    glTranslated(1215, 345, -400);
    glScalef(70, 1500, 3500);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1215, 345, -400);
    glScalef(70, 1500, 3500);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 345, -2115);
    glScalef(2360, 1500, 70);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 345, 1315);
    glScalef(2360, 1500, 70);
    glutSolidCube(1.0);
    glPopMatrix();
}
void ceiling()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ceiling_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ceiling_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ceiling_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_ceiling_shininess);

    glPushMatrix();
    glTranslated(0, 1120, -400);
    glScalef(2500, 50, 3500);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Classroom()
{
    glPushMatrix();
    floor();
    walls();
    ceiling();
    glPopMatrix();
}
///------CLASSROOM VOID CODE END--------///
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

////ADD VOID CODE///












void myinit()
{
    glViewport(5000, 5000, 100000, 50000);  // Set the viewport to start at (0, 0) and have dimensions of 800x800.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1400, 1400, -1400, 1400, -3000, 3000);  // Adjust the orthographic projection to focus on a smaller region around the origin.
    glMatrixMode(GL_MODELVIEW);
}

void CLASSROOM_MASTER()
{
    glPushMatrix();
    glTranslatef(-1000, 0, -1000);
    Classroom();
    Table_Master();
    Sky();
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Apply camera transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    updateCameraView(); // This function applies the camera position and orientation

    // Set up lighting
    GLfloat light_direction[] = { -500.0, 500.0, -500.0, 0.0 };
    GLfloat light_color[] = { 1.0, 1.0, 0.9, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_direction);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Add your objects to the scene
    CLASSROOM_MASTER(); // Example function, replace with your own objects

    glutSwapBuffers();
}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Classroom");
    myinit(); // Initialize your OpenGL environment, including viewport and projection.
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    // Enable or disable OpenGL features as needed.
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    glutMainLoop();
}
