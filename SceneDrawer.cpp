#include "SceneDrawer.h"

GLuint deskVBO, deskEBO, deskVAO;
GLuint keyboardVBO, keyboardEBO, keyboardVAO;
GLuint spacebarVBO, spacebarEBO, spacebarVAO;
GLuint standardKeysVBO, standardKeysEBO, standardKeysVAO;
GLuint shiftKeyVBO, shiftKeyEBO, shiftKeyVAO;
GLuint CubeVBO, CubeVAO, CubeEBO;
GLuint monitorVBO, monitorEBO, monitorVAO;
GLuint monitorScreenVBO, monitorScreenEBO, monitorScreenVAO;
GLuint macBookVBO, macBookEBO, macBookVAO;
GLuint MouseVBO, MouseEBO, MouseVAO;
GLuint monitorBackRingVBO, monitorBackRingEBO, monitorBackRingVAO;
GLuint cylinderVBO, cylinderEBO, cylinderVAO;


MeshData meshData;
float pitchAngle_keys = 10.0f;

GLuint SceneDrawer::deskTextureID;
GLuint SceneDrawer::keyboardTextureID;
GLuint SceneDrawer::keysTextureID;
GLuint SceneDrawer::spacebarTextureID;
GLuint SceneDrawer::shiftTextureID;
GLuint SceneDrawer::enterTextureID;
GLuint SceneDrawer::capsTextureID;
GLuint SceneDrawer::backspaceTextureID;
GLuint SceneDrawer::backslashTextureID;
GLuint SceneDrawer::tabTextureID;
GLuint SceneDrawer::leftMonitorTextureID;
GLuint SceneDrawer::centerMonitorTextureID;
GLuint SceneDrawer::rightMonitorTextureID;
GLuint SceneDrawer::macBookTextureID;
GLuint SceneDrawer::mouseTopTextureID;
GLuint SceneDrawer::monitorMountTextureID;
vector<string> SceneDrawer::texFileNames;
vector<GLuint> SceneDrawer::textureIDs;

// Load Normal Textures

void SceneDrawer::loadTextures() {
    deskTextureID = TextureLoader::loadTexture("desk-texture.jpg");
    keyboardTextureID = TextureLoader::loadTexture("white-texture.jpg");
    spacebarTextureID = TextureLoader::loadTexture("computer_key_Space_bar.png");
    shiftTextureID = TextureLoader::loadTexture("computer_key_Shift.jpg");
    enterTextureID = TextureLoader::loadTexture("computer_key_Enter.jpg");
    capsTextureID = TextureLoader::loadTexture("computer_key_Caps_Lock.jpg");
    backspaceTextureID = TextureLoader::loadTexture("computer_key_Backspace.jpg");
    backslashTextureID = TextureLoader::loadTexture("computer_key_Pipe_Backslash.jpg");
    tabTextureID = TextureLoader::loadTexture("computer_key_Tab.jpg");
    leftMonitorTextureID = TextureLoader::loadTexture("Left-Monitor.png");
    centerMonitorTextureID = TextureLoader::loadTexture("Center-Monitor.png");
    rightMonitorTextureID = TextureLoader::loadTexture("Right-Monitor.png");
    macBookTextureID = TextureLoader::loadTexture("MacBook-Texture.jpg");
    mouseTopTextureID = TextureLoader::loadTexture("Mouse-Top.jpg");
    monitorMountTextureID = TextureLoader::loadTexture("monitor-mount.jpg");
}

// Load Standard key textures 
void SceneDrawer::loadStandardKeyTextures(int numTextures) {
    for (int i = 1; i <= numTextures; ++i) {
        string fileName = "texture" + std::to_string(i) + ".jpg";
        texFileNames.push_back(fileName);
        GLuint textureID = TextureLoader::loadTexture(fileName);
        textureIDs.push_back(textureID);
    }
}
/*******************************************************************************************************************************/

    /**************************************************************************************************
    *																								  *
    *   BUFFERS																				          *
    *																								  *
    **************************************************************************************************/

const vector<GLfloat>& deskVertices = meshData.getVertices();
const vector<GLuint>& deskIndices = meshData.getIndices();

const vector<GLfloat>& keyboardVertices = meshData.getVertices();
const vector<GLuint>& keyboardIndices = meshData.getIndices();

const vector<GLfloat>& spacebarVertices = meshData.getVertices();
const vector<GLuint>& spacebarIndices = meshData.getIndices();

const vector<GLfloat>& standardKeysVertices = meshData.getVertices();
const vector<GLuint>& standardKeysIndices = meshData.getIndices();

const vector<GLfloat>& shiftKeyVertices = meshData.getVertices();
const vector<GLuint>& shiftKeyIndices = meshData.getIndices();

const vector<GLfloat>& CubeVertices = meshData.getVertices();
const vector<GLuint>& CubeIndices = meshData.getIndices();


const vector<GLfloat>& monitorVertices = meshData.getVertices();
const vector<GLuint>& monitorIndices = meshData.getIndices();

const vector<GLfloat>& monitorScreenVertices = meshData.getVertices();
const vector<GLuint>& monitorScreenIndices = meshData.getIndices();

const vector<GLfloat>& macBookVertices = meshData.getVertices();
const vector<GLuint>&macBookIndices = meshData.getIndices();

const vector<GLfloat>& MouseVertices = meshData.getMouseVertices();
const vector<GLuint>& MouseIndices = meshData.getMouseIndices();

const vector<GLfloat>& torusVertices = meshData.getTorusVertices();
const vector<GLuint>& torusIndices = meshData.getTorusIndices();

const vector<GLfloat>& cylinderVertices = meshData.getCylinderVertices();
const vector<GLuint>& cylinderIndices = meshData.getCylinderIndices();






void SceneDrawer::createBuffers() {
    cout << "**** Indices used per object rendered ****" << endl;
    // DESK
    meshData.createDeskMesh();
    Buffer::createBuffer(deskVAO, deskVBO, deskEBO, deskVertices, deskIndices);
    cout << "Desk: " << deskIndices.size() << " Number of triangles per object = " << deskIndices.size() / 3 << endl;

    // KEYBOARD
    meshData.createKeyboardMesh();
    Buffer::createBuffer(keyboardVAO, keyboardVBO, keyboardEBO, keyboardVertices, keyboardIndices);
    cout << "Keyboard: " << keyboardIndices.size() << " Number of triangles per object = " << keyboardIndices.size() / 3 << endl;

    // SPACEBAR
    meshData.createSpacebarMesh();
    Buffer::createBuffer(spacebarVAO, spacebarVBO, spacebarEBO, spacebarVertices, spacebarIndices);
    cout << "Spacebar: " << spacebarIndices.size() << " Number of triangles per object = " << spacebarIndices.size() / 3 << endl;
    // STANDARD KEYS
    meshData.createStandardKeysMesh();
    Buffer::createBuffer(standardKeysVAO, standardKeysVBO, standardKeysEBO, standardKeysVertices, standardKeysIndices);
    cout << "Standard Keys: " << standardKeysIndices.size() << " Number of triangles per object = " << standardKeysIndices.size() / 3 << endl;
    // TODO: CHANGE TO MEDIUM KEYS
    meshData.createShiftKeyMesh();
    Buffer::createBuffer(shiftKeyVAO, shiftKeyVBO, shiftKeyEBO, shiftKeyVertices, shiftKeyIndices);
    cout << "Shift Key: " << shiftKeyIndices.size() << " Number of triangles per object = " << shiftKeyIndices.size() / 3 << endl;

    // LIGHT SOURCE 

    meshData.createCubeMesh();
    Buffer::createBuffer(CubeVAO, CubeVBO, CubeEBO, CubeVertices, CubeIndices);
    cout << "Cube: " << CubeIndices.size() << " Number of triangles per object = " << CubeIndices.size() / 3 << endl;

    // MONITOR SCREEN 
    meshData.createMonitorMesh();
    Buffer::createBuffer(monitorVAO, monitorVBO, monitorEBO, monitorVertices, monitorIndices);
    cout << "Monitor Body: " << monitorIndices.size() << " Number of triangles per object = " << monitorIndices.size() / 3 << endl;

    meshData.createMonitorScreenMesh();
    Buffer::createBuffer(monitorScreenVAO, monitorScreenVBO, monitorScreenEBO, monitorScreenVertices, monitorScreenIndices);
    cout << "Monitor Screen: " << monitorScreenIndices.size() << " Number of triangles per object = " << monitorScreenIndices.size() / 3 << endl;

    // MACBOOK
    meshData.createMacBookMesh();
    Buffer::createBuffer(macBookVAO, macBookVBO, macBookEBO, macBookVertices, macBookIndices);
    cout << "MacBook: " << macBookIndices.size() << " Number of triangles per object = " << macBookIndices.size() / 3 << endl;
    // MOUSE BODY
    meshData.createMouseMesh(0.1f, 20, 0.02);
    Buffer::createBuffer(MouseVAO, MouseVBO, MouseEBO, MouseVertices, MouseIndices);
    cout << "Mouse: " <<MouseIndices.size() << " Number of triangles per object = " << MouseIndices.size() / 3 << endl;
    // MOUSE WHEEL & MONITOR MOUNT PART
    meshData.createTorusMesh(0.5f, 0.3f, 50, 10); 
    Buffer::createBuffer(monitorBackRingVAO, monitorBackRingVBO, monitorBackRingEBO, torusVertices, torusIndices);
    cout <<"Torus: " << torusIndices.size() << " Number of triangles per object = " << torusIndices.size() / 3 << endl;
    // MONIOR MAIN SUPPORT MOUNT FROM DESK
    meshData.createCylinderMesh(0.08f, 1.0f, 25);
    Buffer::createBuffer(cylinderVAO, cylinderVBO, cylinderEBO, cylinderVertices, cylinderIndices);
    cout << "Cylinder: " << cylinderIndices.size() << " Number of triangles per object = " << cylinderIndices.size() / 3 << endl;


}




/*******************************************************************************************************************************/
    /**************************************************************************************************
    *																								  *
    *  SCENE DRAWER																			          *
    *																								  *
    **************************************************************************************************/


void SceneDrawer::drawScene(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {

    /**************************************
    *					             	  *
    *  LIGHTS       					  *
    *									  *
    **************************************/
    drawLightTest(shaderProgramID, view, projection);

    /**************************************
    *					             	  *
    *  DESK             				  *
    *									  *
    **************************************/
    drawDesk(shaderProgramID, view, projection);

    /**************************************
    *					             	  *
    *  MONITORS & STAND					  *
    *									  *
    **************************************/
      
    // Monitor scale
    float scaleX_monitor = 0.9f;
    float scaleY_monitor = 1.3f;
    float scaleZ_monitor = 1.0f;

     // Center monitor translate 
    float translateX_center_monitor = 0.0f;
    float translateY_center_monitor = -0.8f;
    float translateZ_center_monitor = -0.6f;

    drawMonitor(shaderProgramID, view, projection, glm::vec3(scaleX_monitor, scaleY_monitor, scaleZ_monitor), glm::vec3(translateX_center_monitor, translateY_center_monitor, translateZ_center_monitor), "Center", centerMonitorTextureID);

    // Left monitor translate 
    float translateX_left_monitor = -1.937f;
    float translateY_left_monitor = -0.8f;
    float translateZ_left_monitor = -0.25f;

    drawMonitor(shaderProgramID, view, projection, glm::vec3(scaleX_monitor, scaleY_monitor, scaleZ_monitor), glm::vec3(translateX_left_monitor, translateY_left_monitor, translateZ_left_monitor), "Left", leftMonitorTextureID);

    // Right monitor translate 
    float translateX_right_monitor = 1.937f;
    float translateY_right_monitor = -0.8f;
    float translateZ_right_monitor = -0.25f;

    drawMonitor(shaderProgramID, view, projection, glm::vec3(scaleX_monitor, scaleY_monitor, scaleZ_monitor), glm::vec3(translateX_right_monitor, translateY_right_monitor, translateZ_right_monitor), "Right", rightMonitorTextureID);

    /**************************************
    *					             	  *
    *  KEYBOARD 				          *
    *									  *
    **************************************/
    drawKeyboard(shaderProgramID, view, projection);

    /**************************************
    *					             	  *
    *  MACBOOK  				          *
    *									  *
    **************************************/
    drawMacBook(shaderProgramID, view, projection); // 432 indices for all above except for keyboard 

    /**************************************
    *					             	  *
    *  MOUSE      				          *
    *									  *
    **************************************/
 

    float translateX_Mouse = -0.6f; //-0.96
    float translateY_Mouse= 0.1f; // should be 1.37
    float translateZ_Mouse = 0.16f;

    float scaleX_Mouse = 6.0f;
    float scaleY_Mouse = 0.45f;
    float scaleZ_Mouse = 1.5f;

  
    drawMouseBody(shaderProgramID, view, projection, glm::vec3(scaleX_Mouse, scaleY_Mouse, scaleZ_Mouse), glm::vec3(translateX_Mouse, translateY_Mouse, translateZ_Mouse), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f), mouseTopTextureID);


    /**************************************
    *					             	  *
    *  MONITOR MOUNT      				  *
    *									  *
    **************************************/
    drawMonitorMount(shaderProgramID, view, projection);

}


/*******************************************************************************************************************************/


    /**************************************************************************************************
    *																								  *
    *   DESK																				          *
    *																								  *
    **************************************************************************************************/

void SceneDrawer::drawDesk(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {
    glm::mat4 deskModel = glm::mat4(1.0f);
    float scaleX_desk = 4.5f;
    float scaleY_desk = 0.2f;
    float scaleZ_desk = 2.5f;
    deskModel = glm::scale(deskModel, glm::vec3(scaleX_desk, scaleY_desk, scaleZ_desk));
    glm::mat4 mvp = projection * view * deskModel;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);
    glm::vec3 deskAmbient = glm::vec3(0.001f, 0.001f, 0.001f);
    glm::vec3 deskDiffuse = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 deskSpecular = glm::vec3(0.1f, 0.1f, 0.1f);
    float deskShininess = 0.1f;
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(deskAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(deskDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(deskSpecular));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), deskShininess);
    glBindTexture(GL_TEXTURE_2D, deskTextureID);
    glBindVertexArray(deskVAO);
    glDrawElements(GL_TRIANGLES, deskIndices.size(), GL_UNSIGNED_INT, 0);
    //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    
}

/********************************************************************************************************************************************************************************/
/**************************************************************************************************
*																								  *
*   Light Source																		          *
*																								  *
**************************************************************************************************/

void SceneDrawer::drawLightTest(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {
    glUniform3f(glGetUniformLocation(shaderProgramID, "keyLightColor"), 1.0f, 1.0f, 1.0f);
    glUniform1f(glGetUniformLocation(shaderProgramID, "keyLightIntensity"), 0.4f);
    glm::vec3 keyLightPosition = glm::vec3(0.5f, 8.0f, 1.0f);   // position of key light object
    glm::mat4 keyLightModel = glm::mat4(1.0f);
    keyLightModel = glm::translate(keyLightModel, keyLightPosition);
    glm::vec3 keyLightDir = glm::normalize(glm::vec3(0.0f, 0.1f, 0.0f));  // key light direction 0.0f, 0.04f, 0.0f
    glUniform3fv(glGetUniformLocation(shaderProgramID, "keyLightDir"), 1, glm::value_ptr(keyLightDir));

    glm::vec3 keyLightAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 keyLightDiffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 keyLightSpecular = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 keyLightEmissiveColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 keyLightEmissiveDirection = glm::vec3(0.0f, 0.0f, 0.0f);

    float keyLightShininess = 0.1f;

    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(keyLightAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(keyLightDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(keyLightSpecular));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), keyLightShininess);
    glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(keyLightEmissiveColor));

    glm::mat4 mvp = projection * view * keyLightModel;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);
    glBindVertexArray(CubeVAO);
    glDrawElements(GL_TRIANGLES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


/********************************************************************************************************************************************************************************/
/**************************************************************************************************
*																								  *
*   MONITOR     																		          *
*																								  *
**************************************************************************************************/
void SceneDrawer::drawMonitor(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, string rotate, GLuint texture) {
    drawMonitorScreen(shaderProgramID, view, projection, scale, translation, rotate, texture);


    glm::mat4 monitor_model = glm::mat4(1.0f);
    monitor_model = glm::scale(monitor_model, scale);
    monitor_model = glm::translate(monitor_model, translation);
    if (rotate == "Left") {
        monitor_model = glm::rotate(monitor_model, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (rotate == "Right") {
        monitor_model = glm::rotate(monitor_model, glm::radians(-20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    glm::mat4 mvp = projection * view * monitor_model;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);

    glm::vec3 monitorAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 monitorDiffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 monitorSpecular = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 monitorEmissiveColor = glm::vec3(0.0f, 0.0f, 0.0f);
    float monitorShininess = 0.2f;

    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(monitorAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(monitorDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(monitorSpecular));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), monitorShininess);
    glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(monitorEmissiveColor));
   
    glBindVertexArray(monitorVAO);
    glDrawElements(GL_TRIANGLES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    // glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
  


}


/**************************************************************************************************
*																								  *
*   MONITOR SCREEN																		          *
*																								  *
**************************************************************************************************/

void SceneDrawer::drawMonitorScreen(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, string rotate, GLuint texture) {

    glm::mat4 monitor_screen_model = glm::mat4(1.0f);
    monitor_screen_model = glm::scale(monitor_screen_model, scale);
    monitor_screen_model = glm::translate(monitor_screen_model, translation);
    if (rotate == "Left") {
        monitor_screen_model = glm::rotate(monitor_screen_model, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (rotate == "Right") {
        monitor_screen_model = glm::rotate(monitor_screen_model, glm::radians(-20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    glm::mat4 mvp = projection * view * monitor_screen_model;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);

    glm::vec3 monitorScreenAmbient = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 monitorScreenDiffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 monitorScreenSpecular = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 monitorScreenEmissiveColor = glm::vec3(1.0f, 1.0f, 1.0f);
    float monitorScreenShininess = 0.2f;



    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(monitorScreenAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(monitorScreenDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(monitorScreenSpecular));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), monitorScreenShininess);
    glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(monitorScreenEmissiveColor));
     


    glBindVertexArray(monitorScreenVAO);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);    //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}


/**************************************************************************************************
*																								  *
*   MONITOR MOUNT     																		      *
*																								  *
**************************************************************************************************/

void SceneDrawer::drawMonitorMount(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {
    // Main support
    drawCylinder(shaderProgramID, view, projection);

    // Center Monitor Ring 
    drawTorus(shaderProgramID, view, projection, glm::vec3(0.5f, 0.4f, 0.3f), glm::vec3(0.0f, 1.45f, 2.1f), 180.0f, monitorMountTextureID);
    // Center Monitor Mounting Plate
    drawCube(shaderProgramID, view, projection, glm::vec3(2.5f, 1.0f, 0.1f), glm::vec3(0.0f, 0.65f, -6.75f), 0.0f, monitorMountTextureID);
    // Center Arm 
    drawCube(shaderProgramID, view, projection, glm::vec3(0.5f, 0.3f, 1.5f), glm::vec3(0.0f, 2.2f, -0.5f), 0.0f, monitorMountTextureID);

    // Left Monitor Ring
    drawTorus(shaderProgramID, view, projection, glm::vec3(0.5f, 0.4f, 0.3f), glm::vec3(3.0f, 1.45f, 3.0f), 202.0f, monitorMountTextureID);
    // Left Monitor Mounting Plate
    drawCube(shaderProgramID, view, projection, glm::vec3(2.5f, 1.0f, 0.1f), glm::vec3(-0.58f, 0.65f, -10.0f), 25.0f, monitorMountTextureID);
    // Left Monitor Arm 
    drawCube(shaderProgramID, view, projection, glm::vec3(0.5f, 0.3f, 1.5f), glm::vec3(-3.0f, 2.2f, -0.7f), 22.0f, monitorMountTextureID);
    drawCube(shaderProgramID, view, projection, glm::vec3(0.5f, 0.35f, 4.5f), glm::vec3(-2.51f, 1.88f, 0.235f), -65.0f, monitorMountTextureID);
    drawCube(shaderProgramID, view, projection, glm::vec3(0.5f, 0.40f, 5.5f), glm::vec3(-1.75f, 1.64f, 0.11f), -90.0f, monitorMountTextureID);

    // Right Monitor Ring
    drawTorus(shaderProgramID, view, projection, glm::vec3(0.5f, 0.4f, 0.3f), glm::vec3(-3.0f, 1.45f, 3.0f), -202.0f, monitorMountTextureID);
    // Right Monitor Mounting Plate
    drawCube(shaderProgramID, view, projection, glm::vec3(2.5f, 1.0f, 0.1f), glm::vec3(0.58f, 0.65f, -10.00f), -25.0f, monitorMountTextureID);
    // Right Monitor Arm 
    drawCube(shaderProgramID, view, projection, glm::vec3(0.5f, 0.3f, 1.5f), glm::vec3(3.0f, 2.2f, -0.7f), -22.0f, monitorMountTextureID);
    drawCube(shaderProgramID, view, projection, glm::vec3(0.5f, 0.35f, 4.5f), glm::vec3(2.51f, 1.88f, 0.235f), 65.0f, monitorMountTextureID);
    drawCube(shaderProgramID, view, projection, glm::vec3(0.5f, 0.40f, 5.5f), glm::vec3(1.75f, 1.64f, 0.11f), 90.0f, monitorMountTextureID);
}

void SceneDrawer::drawCylinder(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {
    glm::mat4 mainSupport_Model = glm::mat4(1.0f);

    mainSupport_Model = glm::scale(mainSupport_Model, glm::vec3(1.0f, 0.9f, 0.8f));
    mainSupport_Model = glm::rotate(mainSupport_Model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 
    mainSupport_Model = glm::translate(mainSupport_Model, glm::vec3(0.0f, -1.1f, -1.0f)); // x = left right  y = front back  z = up and down <- due to roatation



    glm::vec3  mainSupportAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3  mainSupportDiffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3  mainSupportSpecular = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3  mainSupportEmissiveColor = glm::vec3(0.1f, 0.1f, 0.1f);
    float mainSupportShininess = 0.01f;

    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(mainSupportAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(mainSupportDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(mainSupportSpecular));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(mainSupportEmissiveColor));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), mainSupportShininess);

    glm::mat4 mvp = projection * view * mainSupport_Model;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);

    glBindTexture(GL_TEXTURE_2D, monitorMountTextureID);
    glBindVertexArray(cylinderVAO);
    glDrawElements(GL_TRIANGLES, meshData.getCylinderIndices().size(), GL_UNSIGNED_INT, 0);
    //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}


void SceneDrawer::drawCube(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, float roatationDegree, GLuint texture) {

    glm::mat4 MonitorBackMountPlate_Model = glm::mat4(1.0f);

    if (roatationDegree != 0.0f) {
        MonitorBackMountPlate_Model = glm::rotate(MonitorBackMountPlate_Model, glm::radians(roatationDegree), glm::vec3(0.0f, 1.0f, 0.0f));
        MonitorBackMountPlate_Model = glm::scale(MonitorBackMountPlate_Model, scale);
        MonitorBackMountPlate_Model = glm::translate(MonitorBackMountPlate_Model, translation);
    }

    else {
        MonitorBackMountPlate_Model = glm::scale(MonitorBackMountPlate_Model, scale);
        MonitorBackMountPlate_Model = glm::translate(MonitorBackMountPlate_Model, translation);
    }
    glm::vec3 monitorBackMountPlateAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 monitorBackMountPlateDiffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 monitorBackMountPlateSpecular = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 monitorBackMountPlateEmissiveColor = glm::vec3(0.1f, 0.1f, 0.1f);
    float  monitorBackMountPlateShininess = 0.1f;

    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(monitorBackMountPlateAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(monitorBackMountPlateDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(monitorBackMountPlateSpecular));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(monitorBackMountPlateEmissiveColor));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), monitorBackMountPlateShininess);

    glm::mat4 mvp = projection * view * MonitorBackMountPlate_Model;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);
    glBindVertexArray(CubeVAO);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glDrawElements(GL_TRIANGLES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}




void SceneDrawer::drawTorus(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, float roatationDegree, GLuint texture) {
    glm::mat4 MonitorBackRing_Model = glm::mat4(1.0f);

    if (roatationDegree != 0) {
        MonitorBackRing_Model = glm::rotate(MonitorBackRing_Model, glm::radians(roatationDegree), glm::vec3(0.0f, 1.0f, 0.0f));
        MonitorBackRing_Model = glm::scale(MonitorBackRing_Model, scale);
        MonitorBackRing_Model = glm::translate(MonitorBackRing_Model, translation);
    }


    glm::vec3 monitorBackRingAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 monitorBackRingDiffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 monitorBackRingSpecular = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 monitorBackRingEmissiveColor = glm::vec3(0.1f, 0.1f, 0.1f);
    float monitorBackRingShininess = 0.1f;

    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(monitorBackRingAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(monitorBackRingDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(monitorBackRingSpecular));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(monitorBackRingEmissiveColor));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), monitorBackRingShininess);

    glm::mat4 mvp = projection * view * MonitorBackRing_Model;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);

    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(monitorBackRingVAO);
    glDrawElements(GL_TRIANGLE_STRIP, meshData.getTorusIndices().size(), GL_UNSIGNED_INT, 0);
    //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}


/**************************************************************************************************
*																								  *
*   MACBOOK     																		          *
*																								  *
**************************************************************************************************/


void SceneDrawer::drawMacBook(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {
  
    glm::mat4 macBook_Model = glm::mat4(1.0f);
    float scaleX_Macbook = 0.8f;
    float scaleY_Macbook = 0.15f;
    float scaleZ_Macbook = 1.2f;

    float translateX_MacBook = -1.8f;
    float translateY_MacBook = 0.28f;
    float translateZ_MacBook = 0.45f;

    macBook_Model = glm::scale(macBook_Model, glm::vec3(scaleX_Macbook, scaleY_Macbook, scaleZ_Macbook));
    macBook_Model = glm::translate(macBook_Model, glm::vec3(translateX_MacBook, translateY_MacBook, translateZ_MacBook));
    macBook_Model = glm::rotate(macBook_Model, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f)); 

    glm::mat4 mvp = projection * view * macBook_Model;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);
    glm::vec3 macBookAmbient = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 macBookDiffuse = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 macBookSpecular = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 macBookEmissiveColor = glm::vec3(0.4f, 0.4f, 0.4f);
    float macBookShininess = 0.4f;
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(macBookAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(macBookDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(macBookSpecular));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(macBookEmissiveColor));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), macBookShininess);

    glBindTexture(GL_TEXTURE_2D, macBookTextureID);
    glBindVertexArray(macBookVAO);
    glDrawElements(GL_TRIANGLES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
   
    //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);


}



/**************************************************************************************************
*																								  *
*   MOUSE    																		          *
*																								  *
**************************************************************************************************/

void SceneDrawer::drawMouseBody(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, float roatationDegrees, const glm::vec3& rotationAxis, GLuint texture){
    glm::mat4 mouseBody_Model = glm::mat4(1.0f);

    mouseBody_Model = glm::scale(mouseBody_Model, glm::vec3(scale));
    mouseBody_Model = glm::rotate(mouseBody_Model, glm::radians(roatationDegrees), rotationAxis);
    mouseBody_Model = glm::translate(mouseBody_Model, translation);

    glm::vec3 mouseBodyAmbient = glm::vec3(0.4f, 0.4f, 0.4f);
    glm::vec3 mouseBodyDiffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 mouseBodySpecular = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 mouseBodyEmissiveColor = glm::vec3(0.8f, 0.8f, 0.8f);
    float mouseBodyShininess = 0.1f;

    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(mouseBodyAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(mouseBodyDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(mouseBodySpecular));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(mouseBodyEmissiveColor));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), mouseBodyShininess);

    glm::mat4 mvp = projection * view * mouseBody_Model;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);

    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(MouseVAO);
    glDrawElements(GL_TRIANGLES, meshData.getMouseIndices().size(), GL_UNSIGNED_INT, 0);
    //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);

}


/**************************************************************************************************
*																								  *
*   KEYBOARD BASE																		          *
*																								  *
**************************************************************************************************/

void SceneDrawer::drawKeyboard(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {

    glm::mat4 model_keyboard = glm::mat4(1.0f);
    float scaleX_keyboard = 1.0f;
    float scaleY_keyboard = 0.2f;
    float scaleZ_keyboard = 0.7f;
    float translateZ_keyboard = 1.31f;
    float pitchAngle_keyboard = 20.0f;

    model_keyboard = glm::scale(model_keyboard, glm::vec3(scaleX_keyboard, scaleY_keyboard, scaleZ_keyboard));
    model_keyboard = glm::translate(model_keyboard, glm::vec3(0.0f, 0.2f, translateZ_keyboard));
    model_keyboard = glm::rotate(model_keyboard, glm::radians(pitchAngle_keyboard), glm::vec3(1.0f, 0.0f, 0.0f));

    vector<GLfloat> modifiedVertices = keyboardVertices;

    for (int i = 0; i < sizeof(keyboardVertices) / sizeof(GLfloat); i += 6) {
        glm::vec4 vertex(keyboardVertices[i], keyboardVertices[i + 1], keyboardVertices[i + 2], 1.0f);
        vertex = model_keyboard * vertex;
        modifiedVertices[i] = vertex.x;
        modifiedVertices[i + 1] = vertex.y;
        modifiedVertices[i + 2] = vertex.z;
    }

    // Match spec to key lights refer to sin cos wave link img before adjusting.
    glm::vec3 keyboardSpecular = glm::vec3(
        0.5 + 0.5 * sin(glfwGetTime() + 0), 
        0.5 + 0.5 * sin(glfwGetTime() + 1),
        0.5 + 0.5 * cos(glfwGetTime() + 2)
    );

    glm::mat4 mvp = projection * view * model_keyboard;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);

    glm::vec3 keyboardAmbient = glm::vec3(0.2f, 0.2f, 0.2f);
    glm::vec3 keyboardDiffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    glm::vec3 keyboardEmissiveColor = glm::vec3(0.7f, 0.7f, 0.7f);
    float keyboardShininess = 0.4f;
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(keyboardAmbient));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(keyboardDiffuse));
    glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(keyboardSpecular));
    glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), keyboardShininess);
    glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(keyboardEmissiveColor));

    glBindTexture(GL_TEXTURE_2D, keyboardTextureID);
    glBindVertexArray(keyboardVAO);
    glDrawElements(GL_TRIANGLES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    drawRow1(shaderProgramID, view, projection);
    drawRow2(shaderProgramID, view, projection);
    drawRow3(shaderProgramID, view, projection);
    drawRow4(shaderProgramID, view, projection);
    drawRow5(shaderProgramID, view, projection);
}

/**************************************************************************************************
 *																								  *
 *   SPACEBAR KEYS																		          *
 *																								  *
 **************************************************************************************************/
void SceneDrawer::drawSpacebar(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {

    glm::mat4 model_spacebar = glm::mat4(1.0f);
    float scaleX_spacebar = 0.4f;
    float scaleY_spacebar = 0.084f;
    float scaleZ_spacebar = 0.6f;
    model_spacebar = glm::scale(model_spacebar, glm::vec3(scaleX_spacebar, scaleY_spacebar, scaleZ_spacebar));
    model_spacebar = glm::rotate(model_spacebar, glm::radians(5.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    float translateZ_spacebar = 1.768f;
    model_spacebar = glm::translate(model_spacebar, glm::vec3(-0.1f, 0.85f, translateZ_spacebar));

    glm::mat4 mvp_spacebar = projection * view * model_spacebar;
    unsigned int mvpLoc_spacebar = glGetUniformLocation(shaderProgramID, "mvp");
    
    glUniformMatrix4fv(mvpLoc_spacebar, 1, GL_FALSE, glm::value_ptr(mvp_spacebar));
    glBindTexture(GL_TEXTURE_2D, spacebarTextureID);
    glBindVertexArray(spacebarVAO);
    glDrawElements(GL_TRIANGLES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}


/**************************************************************************************************
 *																								  *
 *   SMALL KEYS																		              *
 *																								  *
 **************************************************************************************************/

void SceneDrawer::drawSmallKeys(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, float finalX, float increment, int textureIndexStart) {

    glm::mat4 model_standard = glm::mat4(1.0f);
    model_standard = glm::scale(model_standard, scale);
    model_standard = glm::rotate(model_standard, glm::radians(pitchAngle_keys), glm::vec3(1.0f, 0.0f, 0.0f));
    model_standard = glm::translate(model_standard, translation);
    glm::mat4 mvp = projection * view * model_standard;
    setUniformMatrix4fv(shaderProgramID, "mvp", mvp);

    glm::vec3 keysEmissiveColor = glm::vec3(
        0.5 + 0.5 * sin(glfwGetTime() + 0),
        0.5 + 0.5 * sin(glfwGetTime() + 1),
        0.5 + 0.5 * cos(glfwGetTime() + 2)
    );

    for (float i = 0; i < finalX; i += increment) {
        glm::mat4 model_standardKey = glm::translate(model_standard, glm::vec3(i, 0.0f, 0.0f));
        setUniformMatrix4fv(shaderProgramID, "mvp", projection * view * model_standardKey);
        int textureIndex = static_cast<int>(i / increment) + textureIndexStart;
        glBindTexture(GL_TEXTURE_2D, textureIDs[textureIndex]);
        glm::vec3 keysAmbient = glm::vec3(1.0f, 1.0f, 1.0f);
        glm::vec3 keysDiffuse = glm::vec3(0.5f, 0.5f, 0.5f);
        glm::vec3 keysSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
        float keysShininess = 0.3f;
        glUniform3fv(glGetUniformLocation(shaderProgramID, "materialAmbient"), 1, glm::value_ptr(keysAmbient));
        glUniform3fv(glGetUniformLocation(shaderProgramID, "materialDiffuse"), 1, glm::value_ptr(keysDiffuse));
        glUniform3fv(glGetUniformLocation(shaderProgramID, "materialSpecular"), 1, glm::value_ptr(keysSpecular));
        glUniform1f(glGetUniformLocation(shaderProgramID, "shininess"), keysShininess);
        glUniform3fv(glGetUniformLocation(shaderProgramID, "emissiveColor"), 1, glm::value_ptr(keysEmissiveColor));
        glBindVertexArray(standardKeysVAO);
        glDrawElements(GL_TRIANGLES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
        //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

   
}

/**************************************************************************************************
 *																								  *
 *   MEDIUM KEYS																                  *
 *																								  *
 **************************************************************************************************/
void SceneDrawer::drawMediumKeys(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, GLuint textureID) {

    glm::mat4 model_mediumKeys = glm::mat4(1.0f);
    model_mediumKeys = glm::scale(model_mediumKeys, scale);
    model_mediumKeys = glm::rotate(model_mediumKeys, glm::radians(pitchAngle_keys), glm::vec3(1.0f, 0.0f, 0.0f));
    model_mediumKeys = glm::translate(model_mediumKeys, translation);

    setUniformMatrix4fv(shaderProgramID, "mvp", projection * view * model_mediumKeys);

    glBindTexture(GL_TEXTURE_2D, textureID);
    glBindVertexArray(shiftKeyVAO);
    glDrawElements(GL_TRIANGLES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    //glDrawElements(GL_LINES, meshData.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

/**************************************************************************************************
 *																								  *
 *   ROW 1 KEY																	                  *
 *																								  *
 **************************************************************************************************/
void SceneDrawer::drawRow1(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {

    // SCALE 
    float scaleX_standardKey = 0.3f;
    float scaleY_standardKey = 0.09f;
    float scaleZ_standardKey = 0.3f;

    float scaleX_spacebar = 0.4f;
    float scaleY_spacebar = 0.084f;
    float scaleZ_spacebar = 0.6f;

    // TRANSLATE
    float translateX_rightSide_standardKey = 0.7f;
    float translateX_leftSide_standardKey = -1.468f; //-0.96
    float translateY_standardKey = 1.37f; // should be 1.37
    float translateZ_standardKey = 3.5f;
    float translateZ_spacebar = 1.768f;

    
 
      // Row 1 left side 3 keys (ctrl, windows, alt)
    drawSmallKeys(shaderProgramID, view, projection, glm::vec3(scaleX_standardKey, scaleY_standardKey, scaleZ_standardKey), glm::vec3(translateX_leftSide_standardKey, translateY_standardKey, translateZ_standardKey), 0.75f, 0.25f, 4);

    
    // Spacebar 
     SceneDrawer::drawSpacebar(shaderProgramID, view, projection);
   
    // Row 1 right side 4 keys (alt, pause/break, menu, ctrl)
    drawSmallKeys(shaderProgramID, view, projection, glm::vec3(scaleX_standardKey, scaleY_standardKey, scaleZ_standardKey), glm::vec3(translateX_rightSide_standardKey, translateY_standardKey, translateZ_standardKey), 1.0f, 0.25f, 0);
}

/**************************************************************************************************
 *																								  *
 *   ROW 2 KEY																	                  *
 *																								  *
 **************************************************************************************************/
void SceneDrawer::drawRow2(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {

    // SCALE 
    float scaleX_standardKey = 0.25f;
    float scaleY_standardKey = 0.10f;
    float scaleZ_standardKey = 0.3f;

    float scaleX_shiftKey_left = 0.37f;
    float scaleY_shiftKey = 0.10f;
    float scaleZ_shiftKey = 0.3f;
    float scaleX_shiftKey_right = 0.32f;

    // TRANSLATE
    float translateX_standardKey = -1.1f;
    float translateY_standardKey = 1.32f;
    float translateZ_standardKey = 3.27f;

    float translateX_shiftKey_left = -1.06f;
    float translateY_shiftKey_left = 1.32f;
    float translateZ_shiftKey_left = 3.27f;

    float translateX_shiftKey_right = 1.245f;
    float translateY_shiftKey_right = 1.32f;
    float translateZ_shiftKey_right = 3.27f;

 
    // Standard keys 
    drawSmallKeys(shaderProgramID, view, projection, glm::vec3(scaleX_standardKey, scaleY_standardKey, scaleZ_standardKey), glm::vec3(translateX_standardKey, translateY_standardKey, translateZ_standardKey), 2.5f, 0.25f, 7);
    // Shift Key Right
    drawMediumKeys(shaderProgramID, view, projection, glm::vec3(scaleX_shiftKey_right, scaleY_shiftKey, scaleZ_shiftKey), glm::vec3(translateX_shiftKey_right, translateY_shiftKey_right, translateZ_shiftKey_right), shiftTextureID);

    // Shift Key Left
    drawMediumKeys(shaderProgramID, view, projection, glm::vec3(scaleX_shiftKey_left, scaleY_shiftKey, scaleZ_shiftKey), glm::vec3(translateX_shiftKey_left, translateY_shiftKey_left, translateZ_shiftKey_left), shiftTextureID);
}

/**************************************************************************************************
 *																								   *
 *   ROW 3 KEY																	                   *
 *																								   *
 **************************************************************************************************/
void SceneDrawer::drawRow3(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {

    // SCALE
    float scaleX_capsKey = 0.28f;
    float scaleY_capsKey = 0.12f;
    float scaleZ_capsKey = 0.3f;

    float scaleX_enterKey = 0.285f;
    float scaleY_enterKey = 0.12f;
    float scaleZ_enterKey = 0.3f;

    float scaleX_standardKey = 0.25f;
    float scaleY_standardKey = 0.12f;
    float scaleZ_standardKey = 0.3f;

    // TRANSLATE
    float translateX_capsKey = -1.467f;
    float translateY_capsKey = 1.20f;
    float translateZ_capsKey = 3.05f;

    float translateX_enterKey = 1.43f;
    float translateY_enterKey = 1.20f;
    float translateZ_enterKey = 3.05f;

    float translateX_standardKey = -1.25f;
    float translateY_standardKey = 1.20f;
    float translateZ_standardKey = 3.05f;

    // Enter Key (right)
    drawMediumKeys(shaderProgramID, view, projection, glm::vec3(scaleX_enterKey, scaleY_enterKey, scaleZ_enterKey), glm::vec3(translateX_enterKey, translateY_enterKey, translateZ_enterKey), enterTextureID);


    // Standard Keys
    drawSmallKeys(shaderProgramID, view, projection, glm::vec3(scaleX_standardKey, scaleY_standardKey, scaleZ_standardKey), glm::vec3(translateX_standardKey, translateY_standardKey, translateZ_standardKey), 2.75f, 0.25f, 17);

    // Caps Key (left)
    drawMediumKeys(shaderProgramID, view, projection, glm::vec3(scaleX_capsKey, scaleY_capsKey, scaleZ_capsKey), glm::vec3(translateX_capsKey, translateY_capsKey, translateZ_capsKey), capsTextureID);
}

/**************************************************************************************************
 *																								   *
 *   ROW 4 KEY																	                   *
 *																								   *
 **************************************************************************************************/
void SceneDrawer::drawRow4(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {

    // SCALE
    float scaleX_tabKey = 0.23f;
    float scaleY_tabKey = 0.12f;
    float scaleZ_tabKey = 0.3f;

    // TRANSLATE
    float translateZ_tabKey = 2.81f;
    float translateX_tabKey = -1.841f;
    float translateY_tabKey = 1.219f;

    // SCALE
    float scaleX_standardKey = 0.25f;
    float scaleY_standardKey = 0.12f;
    float scaleZ_standardKey = 0.3f;

    float scaleX_slashKey = 0.19f;
    float scaleY_slashKey = 0.12f;
    float scaleZ_slashKey = 0.3f;

    // TRANSLATE
    float translateX_standardKey = -1.35f;
    float translateY_standardKey = 1.219f;
    float translateZ_standardKey = 2.81f;

    float translateZ_slashKey = 2.81;
    float translateX_slashKey = 2.25f;
    float translateY_slashKey = 1.219f;

    // Standard Keys
    drawSmallKeys(shaderProgramID, view, projection, glm::vec3(scaleX_standardKey, scaleY_standardKey, scaleZ_standardKey), glm::vec3(translateX_standardKey, translateY_standardKey, translateZ_standardKey), 3.00f, 0.25f, 28);

    // slash key (right)
    drawMediumKeys(shaderProgramID, view, projection, glm::vec3(scaleX_slashKey, scaleY_slashKey, scaleZ_slashKey), glm::vec3(translateX_slashKey, translateY_slashKey, translateZ_slashKey), backslashTextureID);

    // TAB Key (left)
    drawMediumKeys(shaderProgramID, view, projection, glm::vec3(scaleX_tabKey, scaleY_tabKey, scaleZ_tabKey), glm::vec3(translateX_tabKey, translateY_tabKey, translateZ_tabKey), tabTextureID);
}   

/**************************************************************************************************
 *																								*
 *   ROW 5 KEY																	                *
 *																								*
 **************************************************************************************************/
void SceneDrawer::drawRow5(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection) {

    // SCALE
    float scaleX_standardKey = 0.25f;
    float scaleY_standardKey = 0.12f;
    float scaleZ_standardKey = 0.3f;

    float scaleX_backKey = 0.30f;
    float scaleY_backKey = 0.12f;
    float scaleZ_backKey = 0.3f;

    // TRANSLATE
    float translateX_standardKey = -1.795f;
    float translateY_standardKey = 1.240f;
    float translateZ_standardKey = 2.573f;

    float translateZ_backKey = 2.573f;
    float translateX_backKey = 1.35f;
    float translateY_backKey = 1.240f;

    //Standard Keys
    drawSmallKeys(shaderProgramID, view, projection, glm::vec3(scaleX_standardKey, scaleY_standardKey, scaleZ_standardKey), glm::vec3(translateX_standardKey, translateY_standardKey, translateZ_standardKey), 3.25f, 0.25f, 40);

    // backspace key (right)
    drawMediumKeys(shaderProgramID, view, projection, glm::vec3(scaleX_backKey, scaleY_backKey, scaleZ_backKey), glm::vec3(translateX_backKey, translateY_backKey, translateZ_backKey), backspaceTextureID);
}

void SceneDrawer::setUniformMatrix4fv(GLuint shaderProgramID, const char* uniformName, glm::mat4 matrix) {
    unsigned int uniformLoc = glGetUniformLocation(shaderProgramID, uniformName);
    glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(matrix));
}

void SceneDrawer::cleanResources() {
    glDeleteVertexArrays(1, &deskVAO);
    glDeleteBuffers(1, &deskVBO);
    glDeleteBuffers(1, &deskEBO);

    glDeleteVertexArrays(1, &keyboardVAO);
    glDeleteBuffers(1, &keyboardVBO);
    glDeleteBuffers(1, &keyboardEBO);

    glDeleteVertexArrays(1, &spacebarVAO);
    glDeleteBuffers(1, &spacebarVBO);
    glDeleteBuffers(1, &spacebarEBO);

    glDeleteVertexArrays(1, &standardKeysVAO);
    glDeleteBuffers(1, &standardKeysVBO);
    glDeleteBuffers(1, &standardKeysEBO);

    glDeleteVertexArrays(1, &shiftKeyVAO);
    glDeleteBuffers(1, &shiftKeyVBO);
    glDeleteBuffers(1, &shiftKeyEBO);

    glDeleteVertexArrays(1, &CubeVAO);
    glDeleteBuffers(1, &CubeVBO);
    glDeleteBuffers(1, &CubeEBO);

    glDeleteVertexArrays(1, &monitorVAO);
    glDeleteBuffers(1, &monitorVBO);
    glDeleteBuffers(1, &monitorEBO);

    glDeleteVertexArrays(1, &monitorScreenVAO);
    glDeleteBuffers(1, &monitorScreenVBO);
    glDeleteBuffers(1, &monitorScreenEBO);

    glDeleteVertexArrays(1, &macBookVAO);
    glDeleteBuffers(1, &macBookVBO);
    glDeleteBuffers(1, &macBookEBO);

    glDeleteVertexArrays(1, &MouseVAO);
    glDeleteBuffers(1, &MouseVBO);
    glDeleteBuffers(1, &MouseEBO);

    glDeleteVertexArrays(1, &monitorBackRingVAO);
    glDeleteBuffers(1, &monitorBackRingVBO);
    glDeleteBuffers(1, &monitorBackRingEBO);

    glDeleteVertexArrays(1, &cylinderVAO);
    glDeleteBuffers(1, &cylinderVBO);
    glDeleteBuffers(1, &cylinderEBO);


}
