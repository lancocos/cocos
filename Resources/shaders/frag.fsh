// frag.fsh
// ƬԪ��ɫ������դ�������ÿ��ƬԪ��ִ��һ��Ƭ����ɫ��������һ��������������Ⱦ����ɫֵ��Ϊ���
// ����: varying, ���: gl_FragColor + gl_FragDepth

//�����ڶ�����ɫ����Ƭ����ɫ��֮�䴫�����ݣ�������ͱ�����ȫһֱ
varying vec4 v_fragmentColor;

// ÿһ��Shader������һ��main����
void main()
{
    // gl��ͷ�ı�������ϵͳ���õı���
    gl_FragColor = v_fragmentColor;// gl_FragColor �������ջ�����Ļ��������ص����ɫ
}