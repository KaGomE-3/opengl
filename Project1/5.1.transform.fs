#version 330 core

in vec2 TexCoord;

out vec4 color;

// �����ⲿ���������1���������2
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{
		// ��ָ��������ָ�����������µ���ɫ��������������0.2�������ӻ��
	color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);
}
