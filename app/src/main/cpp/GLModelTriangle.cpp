//--------------------------------------------------------------------------------------------------
#include "GLModelTriangle.h"
#include "GLShaderManager.h"
//--------------------------------------------------------------------------------------------------
GLModelTriangle::GLModelTriangle()
{
    m_pShader = GLShaderManager::Get()->GetShader(GLShader_Simple);
    m_fVertexList[0] = 0.0f;
    m_fVertexList[1] = 0.5f;
    m_fVertexList[2] = -0.5f;
    m_fVertexList[3] = -0.5f;
    m_fVertexList[4] = 0.5f;
    m_fVertexList[5] = -0.5f;
}
//--------------------------------------------------------------------------------------------------
GLModelTriangle::~GLModelTriangle()
{

}
//--------------------------------------------------------------------------------------------------
void GLModelTriangle::ModelTriangleUpdate()
{

}
//--------------------------------------------------------------------------------------------------
void GLModelTriangle::ModelTriangleRender()
{
    if (m_pShader)
    {
        GLShaderSimpleParam kParam;
        kParam.pVertex = m_fVertexList;
        m_pShader->ProcessRender(&kParam);
    }
}
//--------------------------------------------------------------------------------------------------

