// vert.vsh
// 顶点着色器，VBO/VAO提供的每个顶点都执行一遍顶点着色器，输出一个varying和gl_Position等

// 变量修饰:
// attribute: 只读，随不同顶点变化的全局变量，应用程序传入，只能用在顶点着色器中
// uniform: 只读，随不同图元变化的全局变量，应用程序传入，
// varying: 在顶点shader中可写，在片断shader中只读，用于在顶点着色器和片段着色器之间传递数据

// 输入: attribute， 输出：varying+gl_positon + gl_Position + gl_PointSize

attribute vec4 a_position;
attribute vec4 a_color;

varying vec4 v_fragmentColor;

// 每一个Shader程序都有一个main函数
void main()
{
    // gl开头的变量名是系统内置的变量
    gl_Position = CC_MVPMatrix * a_position;// 每个点固有的Varying，表示点的空间位置。
    v_fragmentColor = a_color;
}