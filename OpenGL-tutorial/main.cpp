// What is glad and GLFW?: https://www.reddit.com/r/cpp_questions/comments/ryr3fk/comment/hrqyder/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
    glfwInit();
    /*
     * A hint is a suggestion or preference provided to a system or library, in this case `glfwWindowHint` is used
     * to provide hints to the window creation process. These hints guide GLFW in how it should configure the window
     * and its associated OpenGL context. For example, hints can specify things like the desired OpenGL version,
     * whether to use forward or backward compatibility, whether to use hardware acceleration, etc.
    */
    //Creating an OpenGL context for the window, GLFW will try to create a context that is compatible with OpenGL version 3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //Creating an OpenGL context for the window, GLFW will try to create a context that is compatible with OpenGL version x.3
    //So the preferred openGL version is 3.3 but this is not restricted, it's more a suggestion than anything.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
    while(!glfwWindowShouldClose(window))
    {
        /*
         * Similar to pygames pygame.display.flip(), rendering commands are drawn to the back buffer
         * as the most common kind of OpenGL context is double-buffered. After rendering is complete this command
         * swaps the back buffer with the front buffer
         */
        glfwSwapBuffers(window);
        /*
         * This function processes all pending events, such as user input events (e.g., keyboard and mouse events)
         * and window events (e.g., resizing events). It updates the state of GLFW accordingly. By calling this
         * function, your application can respond to user input and window events in real-time.
         *
         */
        glfwPollEvents();

    }
    glfwTerminate();
    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void draw_triangles(){
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    /* OpenGL has many types of buffer objects and the buffer type of a vertex buffer object
     * is GL_ARRAY_BUFFER. OpenGL allows us to bind to several buffers at once as long as they
     * have a different buffer type. We can bind the newly created buffer to the GL_ARRAY_BUFFER
     * target with the glBindBuffer function:
     */
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    /* The fourth parameter specifies how we want the graphics card to manage the given data.
     * This can take 3 forms:
     *      GL_STREAM_DRAW: the data is set only once and used by the GPU at most a few times.
     *      GL_STATIC_DRAW: the data is set only once and used many times.
     *      GL_DYNAMIC_DRAW: the data is changed a lot and used many times.
     * The position data of the triangle does not change, is used a lot, and stays the
     * same for every render call so its usage type should best be GL_STATIC_DRAW.
     */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}
void shaders() {
    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);


    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* fragmentShaderSource;
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
}