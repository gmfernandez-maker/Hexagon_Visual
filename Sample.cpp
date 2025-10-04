#include <GL/glut.h>
#include <iostream>
#ifdef _WIN32
#include <windows.h> // for Sleep on Windows
#else
#include <unistd.h>  // for usleep on Linux/Mac
#define Sleep(x) usleep((x) * 1000)
#endif

using namespace std;

// Global text position
float px = 0.0f, py = 0.0f;

// --- Display function ---
void defaultDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw text
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glRasterPos2f(px, py);

    const char* text = "FEU-TECH";
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }

    glFlush();
}

// --- Keyboard monitor ---
void keyboardMonitor(unsigned char key, int x, int y) {
    cout << "Key pressed: " << key << endl;

    switch (key) {
        case 'a': // move left
            px -= 0.02f;
            break;
        case 'd': // move right
            px += 0.02f;
            break;
        default:  // reset
            px = 0.0f;
            break;
    }
    glutPostRedisplay();
}

// --- Mouse monitor ---
void mouseMonitor(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN)
            cout << "Left button clicked..." << endl;
        else
            cout << "Left button released..." << endl;
    } else if (button == GLUT_RIGHT_BUTTON) {
        cout << "Right button clicked..." << endl;
    } else {
        cout << "Middle button clicked..." << endl;
    }
    cout << "Mouse coordinates: " << x << " " << y << endl;
}

// --- Motion with button pressed ---
void detectMotion(int x, int y) {
    cout << "Dragging: " << x << " " << y << endl;
}

// --- Passive motion (mouse moves without click) ---
void detectPassiveMotion(int x, int y) {
    cout << "Passive motion: " << x << " " << y << endl;
}

// --- Mouse entry (inside/outside window) ---
void mouseEntryDetector(int state) {
    if (state == GLUT_LEFT) {
        cout << "Mouse has left the application" << endl;
    } else if (state == GLUT_ENTERED) {
        cout << "Mouse has re-entered the application" << endl;
    }
}

// --- Animate text (manual Sleep, blocks loop) ---
void animateText() {
    Sleep(1000);       // delay 1 second
    px += 0.02f;
    glutPostRedisplay();
}

// --- Animate text with GLUT timer ---
void animateString(int value) {
    if (value == 1) {
        px += 0.02f;
    } else {
        px -= 0.02f;
    }
    glutPostRedisplay();

    // keep animation going
    glutTimerFunc(1000, animateString, value);
}

// --- Main ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("FEU-TECH Input Example");

    // Register callbacks
    glutDisplayFunc(defaultDisplay);
    glutKeyboardFunc(keyboardMonitor);
    glutMouseFunc(mouseMonitor);
    glutMotionFunc(detectMotion);
    glutPassiveMotionFunc(detectPassiveMotion);
    glutEntryFunc(mouseEntryDetector);

    // start animation (value=1 means move right, value=2 would move left)
    glutTimerFunc(1000, animateString, 1);

    glutMainLoop();
    return 0;
}
