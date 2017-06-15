//--------------------------------------------------------------------------------------------------
#ifndef _GLShaderHelp_h_
#define _GLShaderHelp_h_
//--------------------------------------------------------------------------------------------------
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
//--------------------------------------------------------------------------------------------------
class GLShaderHelp
{
public:
    static unsigned int CreateProgram(const char* szVertexSource, const char* szFragmentSource);

private:
    static unsigned int CompileShader(unsigned int eShaderType, const char* szSource);
    
};
//--------------------------------------------------------------------------------------------------
#endif //_GLShaderHelp_h_
//--------------------------------------------------------------------------------------------------
