#version 330 core

in vec2 TexCoord;

out vec4 color;

// 接收外部的纹理对象1，纹理对象2
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{
		// 查指定纹理在指定纹理坐标下的颜色，查两个纹理，并0.2比例因子混合
	color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);
}
