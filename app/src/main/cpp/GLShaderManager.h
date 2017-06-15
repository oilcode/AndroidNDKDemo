//--------------------------------------------------------------------------------------------------
#ifndef _GLShaderManager_h_
#define _GLShaderManager_h_
//--------------------------------------------------------------------------------------------------
#include "GLShaderSimple.h"
#include "GLShaderTexture.h"
//--------------------------------------------------------------------------------------------------
enum GLShaderType
{
    GLShader_Simple,
    GLShader_Texture,
    GLShader_Max,
};
//--------------------------------------------------------------------------------------------------
class GLShaderManager
{
public:
    static bool CreateShaderManager();
    static void ReleaseShaderManager();
    static GLShaderManager* Get();

    const GLShaderBase* GetShader(GLShaderType eType);

private:
    GLShaderManager();
    ~GLShaderManager();
    bool InitShaderManager();
    void ClearShaderManager();

private:
    static GLShaderManager* ms_pInstance;
    GLShaderBase* m_pShaderList[GLShader_Max];
};
//--------------------------------------------------------------------------------------------------
inline GLShaderManager* GLShaderManager::Get()
{
    return ms_pInstance;
}
//--------------------------------------------------------------------------------------------------
#endif //_GLShaderManager_h_
//--------------------------------------------------------------------------------------------------
