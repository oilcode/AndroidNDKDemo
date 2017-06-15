//--------------------------------------------------------------------------------------------------
#include "GLShaderSimple.h"
#include "GLShaderHelp.h"
//--------------------------------------------------------------------------------------------------
GLShaderSimple::GLShaderSimple()
:m_uiProgramHandle(0)
,m_uiPositionHandle(0)
{
    const char* VertexShader = "attribute vec4 vPosition; void main() { gl_Position = vPosition; }";
    const char* FragmentShader = "precision mediump float; void main() { gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0); }";
    m_uiProgramHandle = GLShaderHelp::CreateProgram(VertexShader, FragmentShader);
    m_uiPositionHandle = glGetAttribLocation(m_uiProgramHandle, "vPosition");
}
//--------------------------------------------------------------------------------------------------
GLShaderSimple::~GLShaderSimple()
{
    if (m_uiProgramHandle)
    {
        glDeleteProgram(m_uiProgramHandle);
        m_uiProgramHandle = 0;
    }
    m_uiPositionHandle = 0;
}
//--------------------------------------------------------------------------------------------------
void GLShaderSimple::ProcessRender(void* pParam) const
{
    GLShaderSimpleParam* pSimpleParam = (GLShaderSimpleParam*)pParam;

    glUseProgram(m_uiProgramHandle);

    glVertexAttribPointer(m_uiPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, pSimpleParam->pVertex);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
//--------------------------------------------------------------------------------------------------
