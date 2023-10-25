#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>

///--------------CAMERA CODE START---------///
int width = 800;
int height = 600;

// Camera parameters
glm::vec3 cameraPosition = glm::vec3(-800.0f, 0.0f, 0.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float cameraSpeed = 20.0f;
float cameraYaw = 0.0f;
float cameraPitch = 0.0f;

// Function prototypes
void reshape(int w, int h);
void moveCamera(float offsetX, float offsetY, float offsetZ);
void rotateCamera(float pitchOffset, float yawOffset);
void updateCameraView();
void display();
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv);

void reshape(int w, int h)
{
    width = w;
    height = h;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 100000000.0);
    glMatrixMode(GL_MODELVIEW);
}

void moveCamera(float offsetX, float offsetY, float offsetZ)
{
    glm::vec3 right = glm::cross(cameraFront, cameraUp);
    cameraPosition += cameraSpeed * (offsetX * right + offsetY * cameraFront + offsetZ * cameraUp);
}

void rotateCamera(float pitchOffset, float yawOffset)
{
    const float sensitivity = 15.0f;
    cameraYaw += yawOffset * sensitivity;
    cameraPitch += pitchOffset * sensitivity;

    if (cameraPitch > 89.0f) cameraPitch = 89.0f;
    if (cameraPitch < -89.0f) cameraPitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
    front.y = sin(glm::radians(cameraPitch));
    front.z = sin(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
    cameraFront = glm::normalize(front);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a': // Move camera left along the x-axis
        moveCamera(-1, 0, 0);
        break;
    case 'd': // Move camera right along the x-axis
        moveCamera(1, 0, 0);
        break;
    case 'w': // Move camera up along the y-axis
        moveCamera(0, 1, 0);
        break;
    case 's': // Move camera down along the y-axis
        moveCamera(0, -1, 0);
        break;
    case 'q': // Move camera forward along the z-axis
        moveCamera(0, 0, 1);
        break;
    case 'e': // Move camera backward along the z-axis
        moveCamera(0, 0, -1);
        break;
    case 'j': // Rotate camera left
        rotateCamera(0, -1);
        break;
    case 'l': // Rotate camera right
        rotateCamera(0, 1);
        break;
    case 'i': // Rotate camera up
        rotateCamera(1, 0);
        break;
    case 'k': // Rotate camera down
        rotateCamera(-1, 0);
        break;
    }
    glutPostRedisplay();
}

void updateCameraView()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glm::mat4 view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
    glLoadMatrixf(glm::value_ptr(view));
}
///--------------CAMERA CODE END---------///


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
//window_surface_colour
GLfloat mat_window_ambient[] = { 0.0, 0.1, 0.1, 0.8 }; // Adjusted for a glass-like ambient color
GLfloat mat_window_diffuse[] = { 0.1, 0.1, 0.1, 0.8 , 0.1}; // Adjusted for a glass-like diffuse color
GLfloat mat_window_specular[] = { 0.9, 0.9, 0.9, 0.8 }; // Adjusted for a glass-like specular color
GLfloat mat_window_shininess = 100.0; // Increased shininess to make it look more like glass
//ceiling_surface_colour
GLfloat mat_ceiling_ambient[] = { 0.8, 0.8, 0.8, 1.0 }; // Adjusted for light gray ambient color
GLfloat mat_ceiling_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // Adjusted for light gray diffuse color
GLfloat mat_ceiling_specular[] = { 0.2, 0.2, 0.2, 1.0 }; // You can keep the specular color the same
GLfloat mat_ceiling_shininess = 10.0; // You can adjust shininess as desired
///------CLASSROOM CODE COLOUR CODE END--------///

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

///------ROBOT COLOUR CODE START--------///
//robot_colour
GLfloat mat_robot_ambient[] = { 0.192, 0.192, 0.192, 1.0 }; // Dark silver ambient color
GLfloat mat_robot_diffuse[] = { 0.192, 0.192, 0.192, 1.0 }; // Dark silver diffuse color
GLfloat mat_robot_specular[] = { 0.509, 0.509, 0.509, 1.0 }; // Light silver specular color
GLfloat mat_robot_shininess = 32.0; // Adjust the shininess for a metallic look
///------ROBOT COLOUR CODE END--------///

///------HUMAN COLOUR CODE START--------///
//upper_body
GLfloat mat_upperbody_ambient[] = { 1.0, 0.0, 0.0, 1.0 }; // Red ambient color
GLfloat mat_upperbody_diffuse[] = { 1.0, 0.0, 0.0, 1.0 }; // Red diffuse color
GLfloat mat_upperbody_specular[] = { 0.0, 0.0, 0.0, 1.0 }; // No specular for cloth-like appearance
GLfloat mat_upperbody_shininess = 15.0; // Adjust the shininess for a cloth-like look

//upper_body
GLfloat mat_lowerbody_ambient[] = { 0.0, 0.0, 0.2, 1.0 }; // Dark blue ambient color for denim
GLfloat mat_lowerbody_diffuse[] = { 0.0, 0.0, 0.4, 1.0 }; // Slightly lighter blue diffuse color for denim
GLfloat mat_lowerbody_specular[] = { 0.2, 0.2, 0.2, 1.0 }; // Some low-level specular highlights for denim
GLfloat mat_lowerbody_shininess = 25.0; // Adjusted shininess for denim appearance

//skin_body
GLfloat mat_skin_ambient[] = { 0.8, 0.6, 0.5, 1.0 }; // Skin-like ambient color
GLfloat mat_skin_diffuse[] = { 0.8, 0.6, 0.5, 1.0 }; // Skin-like diffuse color
GLfloat mat_skin_specular[] = { 0.2, 0.2, 0.2, 1.0 }; // Low-intensity specular for skin
GLfloat mat_skin_shininess = 30.0; // Adjust the shininess for a skin-like look

//shoes_body
GLfloat mat_shoes_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // Dark ambient color for black leather
GLfloat mat_shoes_diffuse[] = { 0.1, 0.1, 0.1, 1.0 }; // Dark diffuse color for black leather
GLfloat mat_shoes_specular[] = { 0.2, 0.2, 0.2, 1.0 }; // Low-intensity specular for leather
GLfloat mat_shoes_shininess = 80.0; // Adjust the shininess for a leather-like look
///------HUMAN COLOUR CODE END--------///

///------SKY COLOUR CODE START--------///
//sky_colour
GLfloat mat_sky_ambient[] = { 0.529, 0.808, 0.922, 1.0 }; // Light blue ambient color
GLfloat mat_sky_diffuse[] = { 0.529, 0.808, 0.922, 1.0 }; // Light blue diffuse color
GLfloat mat_sky_specular[] = { 0.529, 0.808, 0.922, 1.0 }; // Light blue specular color
GLfloat mat_sky_shininess = 30.0; // Adjust the shininess as needed
///------SKY COLOUR CODE END--------///

///------SKY VOID CODE START--------///
void Sky()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_sky_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_sky_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_sky_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_sky_shininess);

    glPushMatrix();
    glTranslated(-5000, 700, -400);
    glScalef(1, 10000, 10000);
    glutSolidCube(1.0);
    glPopMatrix();

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
//right wall
    glPushMatrix();
    glTranslated(1215, 345, -800);
    glScalef(70, 1500, 2700);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1215, 345, 1200);
    glScalef(70, 1500, 300);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1215, 800, -200);
    glScalef(70, 600, 2700);
    glutSolidCube(1.0);
    glPopMatrix();

//left wall
    glPushMatrix();
    glTranslated(-1215, -200, -400);
    glScalef(70, 500, 3500);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1215, 1000, -400);
    glScalef(70, 300, 3500);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1215, 345, 1200);
    glScalef(70, 1500, 300);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1215, 345, -2000);
    glScalef(70, 1500, 300);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1215, 345, -400);
    glScalef(70, 1500, 150);
    glutSolidCube(1.0);
    glPopMatrix();

//front an back wall
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

void windows()
{
    // Set up the material properties to make it transparent
    GLfloat mat_glass_ambient[] = { 0.0, 0.0, 0.0, 0.3 };  // Low ambient color
    GLfloat mat_glass_diffuse[] = { 0.0, 0.0, 0.0, 0.3 };  // Low diffuse color
    GLfloat mat_glass_specular[] = { 0.5, 0.5, 0.5, 0.3 }; // Low specular color
    GLfloat mat_glass_shininess = 32.0;  // Adjust shininess as needed

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_glass_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_glass_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_glass_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_glass_shininess);

    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glTranslated(-1235, 500, -400);
    glScalef(5, 1000, 3500);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Disable blending to restore the default rendering
    glDisable(GL_BLEND);
}

void window_pane()
{
    GLfloat mat_windowpane_ambient[] = { 0.19225, 0.19225, 0.19225, 1.0 };  // Silver ambient color
    GLfloat mat_windowpane_diffuse[] = { 0.50754, 0.50754, 0.50754, 1.0 };  // Silver diffuse color
    GLfloat mat_windowpane_specular[] = { 0.508273, 0.508273, 0.508273, 1.0 }; // Silver specular color
    GLfloat mat_windowpane_shininess = 51.2;  // Adjust shininess as needed

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_windowpane_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_windowpane_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_windowpane_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_windowpane_shininess);

    glPushMatrix();
    glTranslated(-1235, 60, -400);
    glScalef(10, 20, 3500);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 840, -400);
    glScalef(10, 20, 3500);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 600, -400);
    glScalef(10, 20, 3500);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 300, -400);
    glScalef(10, 20, 3500);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 450, -315);
    glScalef(10, 1000, 20);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 450, -485);
    glScalef(10, 1000, 20);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 450, -905);
    glScalef(10, 1000, 20);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 450, -1405);
    glScalef(10, 1000, 20);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 450, -1840);
    glScalef(10, 1000, 20);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 450, 1040);
    glScalef(10, 1000, 20);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 450, 105);
    glScalef(10, 1000, 20);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1235, 450, 605);
    glScalef(10, 1000, 20);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();
}

void door()
{
    GLfloat mat_door_ambient[] = { 0.7, 0.7, 0.0, 1.0 }; // Yellow ambient color
    GLfloat mat_door_diffuse[] = { 0.7, 0.7, 0.0, 1.0 }; // Yellow diffuse color
    GLfloat mat_door_specular[] = { 0.9, 0.9, 0.9, 1.0 }; // Specular color
    GLfloat mat_door_shininess = 30.0; // Adjust shininess as needed

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_door_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_door_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_door_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_door_shininess);

    glPushMatrix();
    glTranslated(1215, 100, 800);
    glScalef(40, 1000, 500);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1215, 80, 1050);
    glScalef(60, 1000, 50);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1215, 80, 550);
    glScalef(60, 1000, 50);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1215, 500, 800);
    glScalef(60, 50, 500);
    glRotatef(180, 1, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1175, 50, 650);
    glutSolidSphere(15.0f, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1190, 50, 650);
    glScalef(30, 10, 10);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1195, 50, 650);
    glScalef(5, 50, 20);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Classroom()
{
    glPushMatrix();
    floor();
    walls();
    windows();
    window_pane();
    door();
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

///------------------ROBOT CODE START---------------///

void drawRobot()
{
    // Body
    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glScalef(0.8f, 0.5f, 0.3f);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(0.0f, -0.45f, 0.0f);
    glScalef(0.6f, 0.4f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(0.0f, -0.75f, 0.0f);
    glScalef(0.4f, 0.9f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(0.0f, -1.2f, 0.0f);
    glScalef(0.5f, 0.2f, 0.3f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Skeleton
    glPushMatrix();
    glTranslatef(0.0f, -0.25f, 0.0f);
    glScalef(0.1f, 2.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(1.5f, 0.1f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.2f, 0.0f);
    glScalef(0.8f, 0.1f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.45f, -1.7f, 0.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.45f, -1.7f, 0.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.65f, -0.5f, 0.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.65f, -0.5f, 0.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Joints
    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(-0.45f, -1.2f, 0.0f);
    glutSolidSphere(0.15f, 20, 20);
    glPopMatrix();

    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(0.45f, -1.2f, 0.0f);
    glutSolidSphere(0.15f, 20, 20);
    glPopMatrix();

    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(0.65f, 0.0f, 0.0f);
    glutSolidSphere(0.15f, 20, 20);
    glPopMatrix();

    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(-0.65f, 0.0f, 0.0f);
    glutSolidSphere(0.15f, 20, 20);
    glPopMatrix();

    // Head
    glColor3f(5.0, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    glutSolidSphere(0.3f, 20, 20);
    glPopMatrix();

    // Arms
    glPushMatrix();
    glTranslatef(0.65f, -0.2f, 0.0f);
    glScalef(0.2f, 0.3f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.65f, -0.2f, 0.0f);
    glScalef(0.2f, 0.3f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.65f, -0.8f, 0.0f);
    glScalef(0.2f, 0.4f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.65f, -0.8f, 0.0f);
    glScalef(0.2f, 0.4f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Legs
    glPushMatrix();
    glTranslatef(0.45f, -2.0f, 0.0f);
    glScalef(0.2f, 0.3f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.45f, -2.0f, 0.0f);
    glScalef(0.2f, 0.3f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.45f, -1.5f, 0.0f);
    glScalef(0.2f, 0.4f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.45f, -1.5f, 0.0f);
    glScalef(0.2f, 0.4f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    //shoes
    glPushMatrix();
    glTranslatef(0.50f, -2.2f, 0.0f);
    glScalef(0.4f, 0.1f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.50f, -2.2f, 0.0f);
    glScalef(0.4f, 0.1f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();
}

void robot()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_robot_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_robot_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_robot_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_robot_shininess);

    glPushMatrix();
    glTranslatef(100, 190, 0);
    glScalef(80, 80, 80);
    glRotatef(200, 0, 1, 0);
    drawRobot();
    glPopMatrix();
}
///------------------ROBOT CODE END---------------///

///------------------HUMAN CODE START---------------///
    // Body
void Upperbody()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_upperbody_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_upperbody_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_upperbody_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_upperbody_shininess);

    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glScalef(0.8f, 0.5f, 0.3f);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(0.0f, -0.45f, 0.0f);
    glScalef(0.6f, 0.9f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Arms
        glPushMatrix();
        glTranslatef(0.45f, -0.3f, 0.0f);
        glScalef(0.2f, 1.0f, 0.2f);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.45f, -0.3f, 0.0f);
        glScalef(0.2f, 1.0f, 0.2f);
        glutSolidCube(1.0);
        glPopMatrix();
}

    // Skeleton
void skeleton()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_skin_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_skin_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_skin_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_skin_shininess);

    glPushMatrix();
    glTranslatef(0.0f, -0.15f, 0.0f);
    glScalef(0.1f, 1.5f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.45f, -0.5f, 0.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.45f, -0.5f, 0.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();
}

    // Joints
void joints()
{
    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(-0.45f, -1.2f, 0.0f);
    glutSolidSphere(0.15f, 20, 20);
    glPopMatrix();

    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(0.45f, -1.2f, 0.0f);
    glutSolidSphere(0.15f, 20, 20);
    glPopMatrix();

    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(0.65f, 0.0f, 0.0f);
    glutSolidSphere(0.15f, 20, 20);
    glPopMatrix();

    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(-0.65f, 0.0f, 0.0f);
    glutSolidSphere(0.15f, 20, 20);
    glPopMatrix();
}

    // Head
void head()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_skin_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_skin_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_skin_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_skin_shininess);

    glColor3f(5.0, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    glutSolidSphere(0.3f, 20, 20);
    glPopMatrix();
}

void lowerbody()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_lowerbody_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_lowerbody_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_lowerbody_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_lowerbody_shininess);

    // Legs
    glPushMatrix();
    glTranslatef(0.18f, -1.6f, 0.0f);
    glScalef(0.25f, 1.4f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.18f, -1.6f, 0.0f);
    glScalef(0.25f, 1.4f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
    glScalef(0.3f, 0.2f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

}

    //shoes
void shoes()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_shoes_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_shoes_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_shoes_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shoes_shininess);

    glPushMatrix();
    glTranslatef(0.20f, -2.3f, -0.05f);
    glScalef(0.2f, 0.15f, 0.3f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.20f, -2.3f, -0.05f);
    glScalef(0.2f, 0.15f, 0.3f);
    glutSolidCube(1.0);
    glPopMatrix();
}

void human()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_robot_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_robot_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_robot_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_robot_shininess);

    glPushMatrix();
    glTranslatef(100, 70, -300);
    glScalef(150, 200, 150);
    glRotatef(180, 0, 1, 0);
    head();
    Upperbody();
    skeleton();
    lowerbody();
    shoes();
    glPopMatrix();
}

void Humans()
{
    glPushMatrix();
    glTranslatef(-200, 0, 0);
    human();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(70, 0, 0);
    glRotatef(180, 0, 1, 0);
    human();
    glPopMatrix();

    human();
}

void HUMAN_MASTER()
{
    glPushMatrix();
    glTranslatef(100, 0, 0);
    Humans();
    glPopMatrix();
}
///------------------HUMAN CODE END---------------///

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

    robot();

    HUMAN_MASTER();

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
    Classroom(); //walls,floor, ceiling
    Table_Master();//all table components, desktop and towers
    Sky();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Apply camera transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    updateCameraView();

    // Set up lighting
    GLfloat light_position[] = { -500.0, 500.0, -500.0, 0.0 };
    GLfloat light_color[] = { 1.0, 1.0, 0.9, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Displays objects to the scene
    CLASSROOM_MASTER(); //Contains ALL components of the class

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


