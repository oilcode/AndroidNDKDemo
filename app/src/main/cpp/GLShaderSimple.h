//--------------------------------------------------------------------------------------------------
#ifndef _GLShaderSimple_h_
#define _GLShaderSimple_h_
//--------------------------------------------------------------------------------------------------
#include "GLShaderBase.h"
//--------------------------------------------------------------------------------------------------
struct GLShaderSimpleParam
{
    const float* pVertex;
};
//--------------------------------------------------------------------------------------------------
class GLShaderSimple : public GLShaderBase
{
public:
    GLShaderSimple();
    ~GLShaderSimple();
    void ProcessRender(void* pParam) const;

private:
    unsigned int m_uiProgramHandle;
    unsigned int m_uiPositionHandle;
};
//--------------------------------------------------------------------------------------------------
#endif //_GLShaderSimple_h_
//--------------------------------------------------------------------------------------------------
