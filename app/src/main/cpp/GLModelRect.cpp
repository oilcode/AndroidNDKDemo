//--------------------------------------------------------------------------------------------------
#include "GLModelRect.h"
#include "GLManager.h"
#include "GLTextureManager.h"
#include "GLShaderManager.h"
//--------------------------------------------------------------------------------------------------
GLModelRect::GLModelRect()
{
    m_pShader = GLShaderManager::Get()->GetShader(GLShader_Texture);

    //左上
    m_fVertexList[0] = -0.5f;
    m_fVertexList[1] = 0.5f;
    m_fVertexList[2] = 0.0f;
    m_fVertexList[3] = 0.0f;
    m_fVertexList[4] = 0.0f;

    //左下
    m_fVertexList[5] = -0.5f;
    m_fVertexList[6] = -0.5f;
    m_fVertexList[7] = 0.0f;
    m_fVertexList[8] = 0.0f;
    m_fVertexList[9] = 1.0f;

    //右下
    m_fVertexList[10] = 0.5f;
    m_fVertexList[11] = -0.5f;
    m_fVertexList[12] = 0.0f;
    m_fVertexList[13] = 1.0f;
    m_fVertexList[14] = 1.0f;

    //右上
    m_fVertexList[15] = 0.5f;
    m_fVertexList[16] = 0.5f;
    m_fVertexList[17] = 0.0f;
    m_fVertexList[18] = 1.0f;
    m_fVertexList[19] = 0.0f;

    m_usIndexList[0] = 0;
    m_usIndexList[1] = 1;
    m_usIndexList[2] = 2;
    m_usIndexList[3] = 0;
    m_usIndexList[4] = 2;
    m_usIndexList[5] = 3;

    m_nTextureId = GLTextureManager::GetInstance()->LoadTextureFile("hud.png");
}
//--------------------------------------------------------------------------------------------------
GLModelRect::~GLModelRect()
{

}
//--------------------------------------------------------------------------------------------------
void GLModelRect::ModelRectUpdate()
{

}
//--------------------------------------------------------------------------------------------------
void GLModelRect::ModelRectRender()
{
    if (m_pShader)
    {
        GLShaderTextureParam kParam;
        kParam.pVertex = m_fVertexList;
        kParam.pIndex = m_usIndexList;
        kParam.nTextureId = m_nTextureId;
        m_pShader->ProcessRender(&kParam);
    }
}
//--------------------------------------------------------------------------------------------------
void GLModelRect::SetPosDelta(float fx, float fy)
{
    int nWidth = 0;
    int nHeight = 0;
    GLManager::Get()->GetResolution(&nWidth, &nHeight);
    float fDeltaX = fx / (float)nWidth;
    float fDeltaY = -fy / (float)nHeight;

    m_fVertexList[0] += fDeltaX;
    m_fVertexList[1] += fDeltaY;
    m_fVertexList[5] += fDeltaX;
    m_fVertexList[6] += fDeltaY;
    m_fVertexList[10] += fDeltaX;
    m_fVertexList[11] += fDeltaY;
    m_fVertexList[15] += fDeltaX;
    m_fVertexList[16] += fDeltaY;
}
//--------------------------------------------------------------------------------------------------

