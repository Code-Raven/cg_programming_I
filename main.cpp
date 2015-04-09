#include "Application.h"

//Globals…
GLFWwindow* window = NULL;

int InitWindow(){
    
    //Initialise GLFW.
    if(!glfwInit()){
        assert(!"Failed to initialize GLFW\n");
        return EXIT_WITH_ERROR;
    }
    
    glfwWindowHint(GLFW_SAMPLES, ANTIALIASING);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPEN_GL_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPEN_GL_VERSION);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //To make MacOS happy; should not be needed.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL.
    
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_NAME, NULL, NULL);
    
    if(window == NULL){
        assert(!"Failed to open GLFW window. GPU is not 3.3 compatible.\n");
        glfwTerminate();
        return EXIT_WITH_ERROR;
    }
    
    //Initialize GLEW.
    glfwMakeContextCurrent(window);
    
    //Ensure we can capture the escape key being pressed below.
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    return EXIT_WITH_SUCCESS;
}

int InitGlew(){
    
    glewExperimental = true; //Needed in core profile.
    if(glewInit() != GLEW_OK) {
        assert(!"Failed to initialize GLEW\n");
        return EXIT_WITH_ERROR;
    }
    
    return EXIT_WITH_SUCCESS;
}

int main(){
    
    if(InitWindow() | InitGlew()){// | Load()){
        return EXIT_WITH_ERROR;  //ToDo: Replace with "assert" later.
    }
    
    do{
        //Update();
        //Render();
        
        //Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    } // Check if the ESC key was pressed or the window was closed
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0);
    
    return EXIT_WITH_SUCCESS;
}