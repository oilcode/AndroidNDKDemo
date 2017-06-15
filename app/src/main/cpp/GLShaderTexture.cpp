//--------------------------------------------------------------------------------------------------
#include "GLShaderTexture.h"
#include "GLShaderHelp.h"
//--------------------------------------------------------------------------------------------------
GLShaderTexture::GLShaderTexture()
:m_uiProgramHandle(0)
,m_uiPositionHandle(0)
,m_uiTexCoordHandle(0)
,m_uiTextureHandle(0)
{
    const char* VertexShader = "uniform mat4 u_MVPMatrix; attribute vec4 a_Position; attribute vec2 a_texCoord; varying vec2 v_texCoord; void main() { gl_Position = a_Position; v_texCoord = a_texCoord; }";
    const char* FragmentShader = "precision mediump float; varying vec2 v_texCoord; uniform sampler2D u_samplerTexture; void main() { gl_FragColor = texture2D(u_samplerTexture, v_texCoord); }";
    m_uiProgramHandle = GLShaderHelp::CreateProgram(VertexShader, FragmentShader);

    m_uiPositionHandle = glGetAttribLocation(m_uiProgramHandle, "a_Position");
    m_uiTexCoordHandle = glGetAttribLocation(m_uiProgramHandle, "a_texCoord");
    m_uiTextureHandle = glGetUniformLocation(m_uiProgramHandle, "u_samplerTexture");
}
//--------------------------------------------------------------------------------------------------
GLShaderTexture::~GLShaderTexture()
{
    if (m_uiProgramHandle)
    {
        glDeleteProgram(m_uiProgramHandle);
        m_uiProgramHandle = 0;
    }
    m_uiPositionHandle = 0;
    m_uiTexCoordHandle = 0;
    m_uiTextureHandle = 0;
}
//--------------------------------------------------------------------------------------------------
void GLShaderTexture::ProcessRender(void* pParam) const
{
    GLShaderTextureParam* pTextureParam = (GLShaderTextureParam*)pParam;

    glUseProgram(m_uiProgramHandle);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, pTextureParam->nTextureId);
    // Set the sampler to texture unit 0
    glUniform1i(m_uiTextureHandle, 0);

    glEnableVertexAttribArray(m_uiPositionHandle);
    glVertexAttribPointer(m_uiPositionHandle, 3, GL_FLOAT, GL_FALSE, 20, pTextureParam->pVertex);

    glEnableVertexAttribArray(m_uiTexCoordHandle);
    glVertexAttribPointer(m_uiTexCoordHandle, 2, GL_FLOAT, GL_FALSE, 20, pTextureParam->pVertex+3);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, pTextureParam->pIndex);
}
//--------------------------------------------------------------------------------------------------
