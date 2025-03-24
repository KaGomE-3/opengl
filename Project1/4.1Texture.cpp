//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#include  "shader_s.h"
//
//#include <iostream>
////声明回调函数，响应窗口缩放
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
////按键响应
//void processInput(GLFWwindow* window);
//
//// settings
////窗口尺寸
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//int main()
//{
//    // glfw: initialize and configure
//    // ------------------------------
//    //初始化GLFW库
//    glfwInit();
//    //设置opengl上下文版本号
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
//    //创建窗口
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    //将当前窗口的上下文设置为当前线程的上下文
//    glfwMakeContextCurrent(window);
//    //设置窗口改变时的回调函数
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    //加载 OpenGL 函数指针，opengl核心模式采用动态加载函数指针的方式，而不是静态链接
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // build and compile our shader zprogram
//    // ------------------------------------
//    //我的着色器
//    Shader ourShader("4.1.texture.vs", "4.1.texture.fs");
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    
//    //传入顶点信息，位置，颜色和纹理坐标
//    float vertices[] = {
//        // positions          // colors           // texture coords
//         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
//         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
//        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
//        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
//    };
//    //图形分为三角形，存储这些索引
//    unsigned int indices[] = {
//        0, 1, 3, // first triangle
//        1, 2, 3  // second triangle
//    };
//    //VBP顶点缓冲对象，VAO顶点数组对象，EBO元素缓冲对象
//    unsigned int VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//    //绑定这些对象
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    //顶点缓冲对象赋值，传入顶点数据
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    //元素缓冲对象赋值，传入分割三角形索引数据
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    //读取顶点缓冲对象中的顶点属性数据，按0,1,2的位置分别对应位置，颜色和纹理坐标，并用glEnableVertexAttribArray（）激活属性
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
//    //创建并绑定纹理
//    unsigned int texture1;
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//    // set the texture wrapping parameters
//    //设置纹理的环绕和缩放
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    //设置属性，nrChannels是通道数
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true);
//    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
//    //获取图像数据
//    unsigned char* data1 = stbi_load("D:/opengl/Project1/resources/container.jpg", &width, &height, &nrChannels, 0);
//    if (data1)
//    {
//        //给纹理赋图像
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data1);
//        //生成多级渐远纹理
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    //释放图像数据
//    stbi_image_free(data1);
//
//
//    // load and create a texture 
//        // -------------------------
//        //创建并绑定纹理
//    unsigned int texture2;
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//    // set the texture wrapping parameters
//    //设置纹理的环绕和缩放
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
//    //获取图像数据
//    unsigned char* data2 = stbi_load("D:/opengl/Project1/resources/awesomeface.png", &width, &height, &nrChannels, 0);
//    if (data2)
//    {
//        //给纹理赋图像
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
//        //生成多级渐远纹理
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    //释放图像数据
//    stbi_image_free(data2);
//
//    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
//    // -------------------------------------------------------------------------------------------
//    //激活当前的着色器程序
//    ourShader.use(); // don't forget to activate/use the shader before setting uniforms!
//    // either set it manually like so:
//    //初始化着色器程序中的uniform变量，起到连接纹理的作用，第二个参数是纹理单元的编号
//    ourShader.setInt("ourTexture1", 0);
//    ourShader.setInt("ourTexture2", 1);
//
//
//    // render loop
//    // -----------
//    //循环渲染
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----
//        //输入窗口
//        processInput(window);
//
//        // render
//        // ------
//        //清除颜色并清除颜色缓冲区。
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // bind Texture
//        //激活纹理单元1
//        glActiveTexture(GL_TEXTURE0);
//        //绑定纹理对象。
//        glBindTexture(GL_TEXTURE_2D, texture1);
//
//        //激活纹理单元2
//        glActiveTexture(GL_TEXTURE1);
//        //绑定纹理对象。
//        glBindTexture(GL_TEXTURE_2D, texture2);
//
//        // render container
//        //使用着色器程序
//        ourShader.use();
//        //绑定 VAO 并使用索引绘制三角形。
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
//    //释放这些对象
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
////按esc关闭窗口
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
////改变视口大小
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}