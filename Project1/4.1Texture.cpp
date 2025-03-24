//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#include  "shader_s.h"
//
//#include <iostream>
////�����ص���������Ӧ��������
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
////������Ӧ
//void processInput(GLFWwindow* window);
//
//// settings
////���ڳߴ�
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//int main()
//{
//    // glfw: initialize and configure
//    // ------------------------------
//    //��ʼ��GLFW��
//    glfwInit();
//    //����opengl�����İ汾��
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // glfw window creation
//    // --------------------
//    //��������
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    //����ǰ���ڵ�����������Ϊ��ǰ�̵߳�������
//    glfwMakeContextCurrent(window);
//    //���ô��ڸı�ʱ�Ļص�����
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    //���� OpenGL ����ָ�룬opengl����ģʽ���ö�̬���غ���ָ��ķ�ʽ�������Ǿ�̬����
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // build and compile our shader zprogram
//    // ------------------------------------
//    //�ҵ���ɫ��
//    Shader ourShader("4.1.texture.vs", "4.1.texture.fs");
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    
//    //���붥����Ϣ��λ�ã���ɫ����������
//    float vertices[] = {
//        // positions          // colors           // texture coords
//         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
//         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
//        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
//        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
//    };
//    //ͼ�η�Ϊ�����Σ��洢��Щ����
//    unsigned int indices[] = {
//        0, 1, 3, // first triangle
//        1, 2, 3  // second triangle
//    };
//    //VBP���㻺�����VAO�����������EBOԪ�ػ������
//    unsigned int VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//    //����Щ����
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    //���㻺�����ֵ�����붥������
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    //Ԫ�ػ������ֵ������ָ���������������
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    //��ȡ���㻺������еĶ����������ݣ���0,1,2��λ�÷ֱ��Ӧλ�ã���ɫ���������꣬����glEnableVertexAttribArray������������
//    // position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // color attribute
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    // texture coord attribute
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//
//
//    // load and create a texture 
//    // -------------------------
//    //������������
//    unsigned int texture1;
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//    // set the texture wrapping parameters
//    //��������Ļ��ƺ�����
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    //�������ԣ�nrChannels��ͨ����
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true);
//    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
//    //��ȡͼ������
//    unsigned char* data1 = stbi_load("D:/opengl/Project1/resources/container.jpg", &width, &height, &nrChannels, 0);
//    if (data1)
//    {
//        //������ͼ��
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data1);
//        //���ɶ༶��Զ����
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    //�ͷ�ͼ������
//    stbi_image_free(data1);
//
//
//    // load and create a texture 
//        // -------------------------
//        //������������
//    unsigned int texture2;
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//    // set the texture wrapping parameters
//    //��������Ļ��ƺ�����
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
//    //��ȡͼ������
//    unsigned char* data2 = stbi_load("D:/opengl/Project1/resources/awesomeface.png", &width, &height, &nrChannels, 0);
//    if (data2)
//    {
//        //������ͼ��
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
//        //���ɶ༶��Զ����
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    //�ͷ�ͼ������
//    stbi_image_free(data2);
//
//    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
//    // -------------------------------------------------------------------------------------------
//    //���ǰ����ɫ������
//    ourShader.use(); // don't forget to activate/use the shader before setting uniforms!
//    // either set it manually like so:
//    //��ʼ����ɫ�������е�uniform��������������������ã��ڶ�������������Ԫ�ı��
//    ourShader.setInt("ourTexture1", 0);
//    ourShader.setInt("ourTexture2", 1);
//
//
//    // render loop
//    // -----------
//    //ѭ����Ⱦ
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----
//        //���봰��
//        processInput(window);
//
//        // render
//        // ------
//        //�����ɫ�������ɫ��������
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // bind Texture
//        //��������Ԫ1
//        glActiveTexture(GL_TEXTURE0);
//        //���������
//        glBindTexture(GL_TEXTURE_2D, texture1);
//
//        //��������Ԫ2
//        glActiveTexture(GL_TEXTURE1);
//        //���������
//        glBindTexture(GL_TEXTURE_2D, texture2);
//
//        // render container
//        //ʹ����ɫ������
//        ourShader.use();
//        //�� VAO ��ʹ���������������Ρ�
//        glBindVertexArray(VAO);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    //�ͷ���Щ����
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteBuffers(1, &EBO);
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
////��esc�رմ���
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
////�ı��ӿڴ�С
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}