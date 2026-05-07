#include <GL/freeglut.h>
#include <cstdlib>

// RUET Rift: The 10-Hour Distortion
// Clean base project for a syllabus-friendly C++ OpenGL/GLUT program.

int windowWidth = 1280;
int windowHeight = 720;

// Temporary player position. The player model and movement will be added later.
float playerX = 0.0f;
float playerY = 0.0f;
float playerZ = 0.0f;

// Camera mode 0 = third-person, camera mode 1 = top-view.
int cameraMode = 0;
float cameraDistance = 18.0f;
float cameraHeight = 9.0f;
float cameraYaw = 35.0f;

void drawGroundPlane() {
    // A flat rectangle is enough for the first base scene.
    glDisable(GL_LIGHTING);
    glColor3f(0.22f, 0.52f, 0.24f);

    glBegin(GL_QUADS);
        glVertex3f(-30.0f, 0.0f, -30.0f);
        glVertex3f( 30.0f, 0.0f, -30.0f);
        glVertex3f( 30.0f, 0.0f,  30.0f);
        glVertex3f(-30.0f, 0.0f,  30.0f);
    glEnd();
}

void drawCoordinateAxes() {
    // Temporary debug axes:
    // X axis = red, Y axis = green, Z axis = blue.
    glDisable(GL_LIGHTING);
    glLineWidth(3.0f);

    glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.03f, 0.0f);
        glVertex3f(8.0f, 0.03f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 0.03f, 0.0f);
        glVertex3f(0.0f, 8.0f, 0.0f);

        glColor3f(0.0f, 0.25f, 1.0f);
        glVertex3f(0.0f, 0.03f, 0.0f);
        glVertex3f(0.0f, 0.03f, 8.0f);
    glEnd();

    glLineWidth(1.0f);
}

void setupCamera() {
    // MODELVIEW controls the camera and object transformations.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // gluLookAt works like this:
    // 1. eye position    = where the camera is placed
    // 2. center position = the point the camera looks at
    // 3. up direction    = which direction should be considered upward
    if (cameraMode == 0) {
        // Third-person camera: placed behind and above the temporary player.
        float eyeX = playerX;
        float eyeY = playerY + cameraHeight;
        float eyeZ = playerZ + cameraDistance;

        gluLookAt(
            eyeX, eyeY, eyeZ,
            playerX, playerY + 1.0f, playerZ,
            0.0f, 1.0f, 0.0f
        );
    } else {
        // Top-view camera: placed high above the temporary player.
        gluLookAt(
            playerX, playerY + 45.0f, playerZ + 0.1f,
            playerX, playerY,         playerZ,
            0.0f,   0.0f,            -1.0f
        );
    }

    // A small Y-axis rotation makes the base scene easier to read in third-person.
    if (cameraMode == 0) {
        glRotatef(cameraYaw, 0.0f, 1.0f, 0.0f);
    }
}

void display() {
    // Clear both color and depth buffers before drawing a new frame.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setupCamera();
    drawGroundPlane();
    drawCoordinateAxes();

    // GLUT_DOUBLE uses a back buffer. Swap makes the completed frame visible.
    glutSwapBuffers();
}

void reshape(int width, int height) {
    if (height == 0) {
        height = 1;
    }

    windowWidth = width;
    windowHeight = height;

    // Viewport maps normalized OpenGL output to the actual window pixels.
    glViewport(0, 0, windowWidth, windowHeight);

    // PROJECTION controls perspective: field of view, aspect ratio, near/far planes.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspectRatio = static_cast<float>(windowWidth) / static_cast<float>(windowHeight);
    gluPerspective(60.0f, aspectRatio, 0.1f, 500.0f);

    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    (void)x;
    (void)y;

    switch (key) {
        case 27: // Esc
            std::exit(0);
            break;

        case 'r':
        case 'R':
            cameraMode = 0;
            cameraYaw = 35.0f;
            break;

        case 'c':
        case 'C':
            cameraMode = (cameraMode + 1) % 2;
            break;

        default:
            break;
    }
}

void update(int value) {
    (void)value;

    // Timer callback gives a steady animation/update point for future game logic.
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // About 60 frames per second.
}

void initializeOpenGL() {
    // Depth testing allows nearer 3D objects to correctly hide farther objects.
    glEnable(GL_DEPTH_TEST);

    // Smooth line/primitive colors are useful for simple classroom demos.
    glShadeModel(GL_SMOOTH);

    // Background sky color for the empty base scene.
    glClearColor(0.48f, 0.72f, 0.95f, 1.0f);
}

int main(int argc, char** argv) {
    // Initialize GLUT and create one double-buffered RGB window with depth support.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 80);
    glutCreateWindow("RUET Rift: The 10-Hour Distortion");

    initializeOpenGL();

    // Register GLUT callbacks. GLUT calls these functions when needed.
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
