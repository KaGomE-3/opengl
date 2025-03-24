#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 ourColor;
out vec2 TexCoord;

void main()
{
    //拿到VAO中一个顶点对应的位置坐标属性、颜色属性、纹理坐标属性
	gl_Position = vec4(position, 1.0f);
	ourColor = color;
	TexCoord = texCoord;
}
