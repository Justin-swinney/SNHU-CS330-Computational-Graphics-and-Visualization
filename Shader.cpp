#include "Shader.h"


const char* vertexShaderSource = R"(
    #version 440 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;
	layout (location = 2) in vec2 aTexCoord;

    out vec3 FragColor;
	out vec2 TexCoord;
	out vec3 FragPos;
	out vec3 Normal;

    uniform mat4 mvp;

    void main() {
        gl_Position = mvp * vec4(aPos, 1.0);
        FragColor = aColor;
		TexCoord = aTexCoord;
		FragPos = vec3(mvp * vec4(aPos, 1.0));
        Normal = mat3(transpose(inverse(mvp))) * normalize(aPos);
    }
)";

const char* fragmentShaderSource = R"(
    #version 440 core

	in vec2 TexCoord;
	in vec3 FragPos;
    in vec3 Normal;

    out vec4 FragColor;
    precision mediump float;
    uniform sampler2D texture1;

    uniform vec3 keyLightDir;
    uniform vec3 keyLightColor;
    uniform float keyLightIntensity;

    // Ambient
    uniform vec3 ambientLightColor;
    uniform float ambientLightIntensity;

    // Material 
    uniform vec3 materialAmbient;
    uniform vec3 materialDiffuse;
    uniform vec3 materialSpecular;
    uniform float shininess;
    uniform vec3 emissiveColor;

    void main() {

        // Lighting calculations for key light (ceiling light) 
        float keyDiffuse = max(dot(normalize(keyLightDir), normalize(Normal)), 0.0);
        vec3 keyDiffuseColor = keyDiffuse * keyLightIntensity * keyLightColor;

        // Ambient
        vec3 ambientColor = ambientLightIntensity * ambientLightColor * materialAmbient;
        vec3 lighting = keyDiffuseColor + ambientColor;

        // Specular
        vec3 viewDir = normalize(-FragPos);
        vec3 reflectDir = reflect(-keyLightDir, Normal);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
        vec3 specularColor = keyLightIntensity * spec * materialSpecular;

        // Objects to produce light themselves 
        vec3 emissive = emissiveColor * texture(texture1, TexCoord).rgb;
        // some objects are need vec3 emissive = emissiveColor * texture(texture1, TexCoord).r;
        
        vec3 finalColor = materialDiffuse * (lighting + specularColor) + emissive;
        FragColor = vec4(finalColor, 1.0);
    }
)";

unsigned int createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource) {

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
