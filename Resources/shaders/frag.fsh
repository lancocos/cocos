// frag.fsh
// 片元着色器，光栅化输出的每个片元都执行一遍片段着色器，生成一个或多个（多重渲染）颜色值作为输出
// 输入: varying, 输出: gl_FragColor + gl_FragDepth

//用于在顶点着色器和片段着色器之间传递数据，因此类型必须完全一直
varying vec4 v_fragmentColor;

// 每一个Shader程序都有一个main函数
void main()
{
    // gl开头的变量名是系统内置的变量
    gl_FragColor = v_fragmentColor;// gl_FragColor 定义最终画在屏幕上面的像素点的颜色
}