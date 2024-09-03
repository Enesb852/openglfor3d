
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>

std::string loadShaderSrc(const std::string& fileName)
{
    std::ifstream file(fileName);
    std::stringstream buffer;

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << fileName << std::endl;
        return "";
    }

    buffer << file.rdbuf();
    return buffer.str();
}

GLint compileShader(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vertexCode = loadShaderSrc(vertexPath);
    std::string fragmentCode = loadShaderSrc(fragmentPath);

    GLint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
    glCompileShader(vertexShader);
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cerr << "Vertex Shader Compilation Error: " << infoLog << std::endl;
    }

    glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cerr << "Fragment Shader Compilation Error: " << infoLog << std::endl;
    }

    GLint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Shader Program Linking Error: " << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    gladLoadGL();

    // Köşe verilerini tanımla
    GLfloat vertices[] = {
    // (sol alt)köşe
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 
    // (üst)köşe 
        0.0f,  0.5f, 0.0f,      0.5f, 1.0f,
    // Üçüncü köşe (sağ alt)
        0.5f, -0.5f, 0.0f,      1.0f, 0.0f
    };

    GLuint shaderProgram = compileShader("vertex_shader.glsl", "fragment_shader.glsl");
    glUseProgram(shaderProgram);

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("../res/wall.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture"), 0);
    
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Köşe verilerini oluşturun ve bağlayın
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Köşe verilerini etkinleştir
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    // VAO'yu serbest bırakın
    glBindVertexArray(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        // Shader programını kullan
        glUseProgram(shaderProgram);

        // VAO'yu bağlayın
        glBindVertexArray(VAO);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    // Temizlik işlemleri
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}