#include "Shader.h"

Shader::Shader(const char* vertPath, const char* fragPath)
{
    std::ifstream vertFile;
    vertFile.open(vertPath);

    std::ifstream fragFile;
    fragFile.open(fragPath);

    std::stringstream vBuffer;
    std::stringstream fBuffer;
    vBuffer << vertFile.rdbuf();
    std::string vertData = vBuffer.str();

    fBuffer << fragFile.rdbuf();
    std::string fragData = fBuffer.str();

    const char* vertCode = vertData.c_str();
    const char* fragCode = fragData.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertCode, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragCode,NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);
    // check for linking errors
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Use()
{
    glUseProgram(id);
}

void Shader::SetInt(const std::string& name, int x)
{
    glUniform1i(glGetUniformLocation( id,name.c_str()),x );
}

void Shader::SetFloat(const std::string& name, float x)
{
    glUniform1f(glGetUniformLocation(id, name.c_str()), x);
}

void Shader::SetVec3(const std::string& name, float x, float y, float z)
{
    glUniform3f(glGetUniformLocation(id, name.c_str()),x,y,z);
}

void Shader::SetVec3(const std::string& name, const glm::vec3& vec)
{
    glUniform3f(glGetUniformLocation(id, name.c_str()),vec.x,vec.y,vec.z);
}

void Shader::SetVec2(const std::string& name, float x, float y)
{
    glUniform2f(glGetUniformLocation(id, name.c_str()), x, y);
}

void Shader::SetVec2(const std::string& name, const glm::vec2& vec)
{
    glUniform2f(glGetUniformLocation(id, name.c_str()), vec.x, vec.y);
}

void Shader::SetMat4(const std::string& name, const glm::mat4& mat)
{
    //glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
     
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetMat3(const std::string& name, const glm::mat4& mat)
{
    glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetMat2(const std::string& name, const glm::mat4& mat)
{
    glUniformMatrix2fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

Shader::~Shader() 
{
    glDeleteProgram(id);
}