//--------------------------------------------------------------------------------------------------
#include "GLShaderHelp.h"
#include "SoBaseInclude.h"
#include <stdlib.h>
//--------------------------------------------------------------------------------------------------
unsigned int GLShaderHelp::CreateProgram(const char* szVertexSource, const char* szFragmentSource)
{
    unsigned int uiVertexHandle = CompileShader(GL_VERTEX_SHADER, szVertexSource);
    if (uiVertexHandle == 0)
    {
        return 0;
    }

    unsigned int uiFragmentHandle = CompileShader(GL_FRAGMENT_SHADER, szFragmentSource);
    if (uiFragmentHandle == 0)
    {
        return 0;
    }

    unsigned int uiProgramHandle = glCreateProgram();
    if (uiProgramHandle == 0)
    {
        return 0;
    }

    glAttachShader(uiProgramHandle, uiVertexHandle);
    glAttachShader(uiProgramHandle, uiFragmentHandle);

    //glBindAttribLocation(uiProgramHandle, 0, "a_Position");
    //glBindAttribLocation(uiProgramHandle, 1, "a_texCoord");
    //glBindAttribLocation(uiProgramHandle, 2, "u_samplerTexture");

    glLinkProgram(uiProgramHandle);

    GLint linkStatus = GL_FALSE;
    glGetProgramiv(uiProgramHandle, GL_LINK_STATUS, &linkStatus);
    if (linkStatus == GL_FALSE)
    {
        GLint nInfoLen = 0;
        glGetProgramiv(uiProgramHandle, GL_INFO_LOG_LENGTH, &nInfoLen);
        if (nInfoLen > 0)
        {
            char* buff = (char*)malloc(nInfoLen);
            if (buff)
            {
                glGetProgramInfoLog(uiProgramHandle, nInfoLen, NULL, buff);
                SoIDEOutputLogError("%s", buff);
                free(buff);
                buff = 0;
            }
        }

        glDeleteProgram(uiProgramHandle);
        uiProgramHandle = 0;
    }

    return uiProgramHandle;
}
//--------------------------------------------------------------------------------------------------
unsigned int GLShaderHelp::CompileShader(unsigned int eShaderType, const char* szSource)
{
    unsigned int uiShaderHandle = glCreateShader(eShaderType);
    if (uiShaderHandle == 0)
    {
        return 0;
    }

    glShaderSource(uiShaderHandle, 1, &szSource, NULL);
    glCompileShader(uiShaderHandle);

    //检查编译是否成功
    GLint nCompileResult = GL_FALSE;
    glGetShaderiv(uiShaderHandle, GL_COMPILE_STATUS, &nCompileResult);
    if (nCompileResult == GL_FALSE)
    {
        GLint nInfoLen = 0;
        glGetShaderiv(uiShaderHandle, GL_INFO_LOG_LENGTH, &nInfoLen);
        if (nInfoLen > 0)
        {
            char* buff = (char*)malloc(nInfoLen);
            if (buff)
            {
                glGetShaderInfoLog(uiShaderHandle, nInfoLen, NULL, buff);
                SoIDEOutputLogError("%s", buff);
                free(buff);
                buff = 0;
            }
        }

        glDeleteShader(uiShaderHandle);
        uiShaderHandle = 0;
    }

    return uiShaderHandle;
}
//--------------------------------------------------------------------------------------------------
