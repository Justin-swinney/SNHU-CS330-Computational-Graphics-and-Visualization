#pragma once
#include <vector>
#include <glm/fwd.hpp>
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class MeshData {
public:
    MeshData();
    ~MeshData();

    void createDeskMesh();
    void createKeyboardMesh();
    void createSpacebarMesh();
    void createStandardKeysMesh();
    void createShiftKeyMesh();
    void createCubeMesh();
    void createMonitorMesh();
    void createMacBookMesh();
    void createMonitorScreenMesh();
    void createMouseMesh(float radius, int parts, float height);
    void createTorusMesh(float outerRadius, float innerRadius, int sides, int rings);
    void createCylinderMesh(float radius, float height, int sides);
    const vector<GLfloat>& getVertices() const;
    const vector<GLuint>& getIndices() const;

    const vector<GLfloat>& getMouseVertices() const;
    const vector<GLuint>& getMouseIndices() const;
    const vector<GLfloat>& getTorusVertices() const;
    const vector<GLuint>& getTorusIndices() const;
    const vector<GLfloat>& getCylinderVertices() const;
    const vector<GLuint>& getCylinderIndices() const;
private:

    vector<GLfloat> vertices;
    vector<GLuint> indices;
    vector<GLfloat> mouseVertices;
    vector<GLfloat> torusVertices;
    vector<GLfloat> cylinderVertices;
    vector<GLuint> mouseIndices;
    vector<GLuint> torusIndices;
    vector<GLuint> cylinderIndices;
   
   

};