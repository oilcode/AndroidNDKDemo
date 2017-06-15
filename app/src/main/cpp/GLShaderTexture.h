//--------------------------------------------------------------------------------------------------
#ifndef _GLShaderTexture_h_
#define _GLShaderTexture_h_
//--------------------------------------------------------------------------------------------------
#include "GLShaderBase.h"
//--------------------------------------------------------------------------------------------------
struct GLShaderTextureParam
{
    const float* pVertex;
    const unsigned short* pIndex;
    int nTextureId;
};
//--------------------------------------------------------------------------------------------------
class GLShaderTexture : public GLShaderBase
{
public:
    GLShaderTexture();
    ~GLShaderTexture();
    void ProcessRender(void* pParam) const;

private:
    unsigned int m_uiProgramHandle;
    unsigned int m_uiPositionHandle;
    unsigned int m_uiTexCoordHandle;
    unsigned int m_uiTextureHandle;
};
//--------------------------------------------------------------------------------------------------
#endif //_GLShaderTexture_h_
//--------------------------------------------------------------------------------------------------
