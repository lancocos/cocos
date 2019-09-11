// vert.vsh
// ������ɫ����VBO/VAO�ṩ��ÿ�����㶼ִ��һ�鶥����ɫ�������һ��varying��gl_Position��

// ��������:
// attribute: ֻ�����治ͬ����仯��ȫ�ֱ�����Ӧ�ó����룬ֻ�����ڶ�����ɫ����
// uniform: ֻ�����治ͬͼԪ�仯��ȫ�ֱ�����Ӧ�ó����룬
// varying: �ڶ���shader�п�д����Ƭ��shader��ֻ���������ڶ�����ɫ����Ƭ����ɫ��֮�䴫������

// ����: attribute�� �����varying+gl_positon + gl_Position + gl_PointSize

attribute vec4 a_position;
attribute vec4 a_color;

varying vec4 v_fragmentColor;

// ÿһ��Shader������һ��main����
void main()
{
    // gl��ͷ�ı�������ϵͳ���õı���
    gl_Position = CC_MVPMatrix * a_position;// ÿ������е�Varying����ʾ��Ŀռ�λ�á�
    v_fragmentColor = a_color;
}