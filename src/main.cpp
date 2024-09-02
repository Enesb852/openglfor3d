
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>

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
    // İlk köşe (sol alt)
        -0.5f, -0.5f, 0.0f, 
    // İkinci köşe (üst)
        0.0f,  0.5f, 0.0f,  
    // Üçüncü köşe (sağ alt)
        0.5f, -0.5f, 0.0f  
    };

    unsigned int shaderProgram = compileShader("vshader.glsl", "fshader.glsl");
    if (shaderProgram == 0) {
        std::cerr << "Failed to create shader program." << std::endl;
        return -1;
    }

    glUseProgram(shaderProgram);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Köşe verilerini oluşturun ve bağlayın
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Köşe verilerini etkinleştir
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // VAO'yu serbest bırakın
    glBindVertexArray(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Shader programını kullan
        glUseProgram(shaderProgram);

        // VAO'yu bağlayın ve Üçgeni çizin
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