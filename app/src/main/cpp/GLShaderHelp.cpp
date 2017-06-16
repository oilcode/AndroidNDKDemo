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
        glDeleteShader(uiVertexHandle);
        return 0;
    }

    unsigned int uiProgramHandle = glCreateProgram();
    if (uiProgramHandle == 0)
    {
        glDeleteShader(uiVertexHandle);
        glDeleteShader(uiFragmentHandle);
        return 0;
    }

    glAttachShader(uiProgramHandle, uiVertexHandle);
    glAttachShader(uiProgramHandle, uiFragmentHandle);

    //glBindAttribLocation(uiProgramHandle, 0, "a_Position");
    //glBindAttribLocation(uiProgramHandle, 1, "a_texCoord");
    //glBindAttribLocation(uiProgramHandle, 2, "u_samplerTexture");

    glLinkProgram(uiProgramHandle);

    //不管链接是否成功，都尝试打印出编译回馈信息。
    GLint nLinkInfoLen = 0;
    glGetProgramiv(uiProgramHandle, GL_INFO_LOG_LENGTH, &nLinkInfoLen);
    if (nLinkInfoLen > 0)
    {
        char* buff = (char*)malloc(nLinkInfoLen+1);
        if (buff)
        {
            buff[nLinkInfoLen] = 0;
            glGetProgramInfoLog(uiProgramHandle, nLinkInfoLen, NULL, buff);
            SoIDEOutputLogError("%s", buff);
            free(buff);
            buff = 0;
        }
    }

    //删除不需要的数据。
    glDetachShader(uiProgramHandle, uiVertexHandle);
    glDetachShader(uiProgramHandle, uiFragmentHandle);
    glDeleteShader(uiVertexHandle);
    glDeleteShader(uiFragmentHandle);

    //检查链接是否成功。
    GLint linkStatus = GL_FALSE;
    glGetProgramiv(uiProgramHandle, GL_LINK_STATUS, &linkStatus);
    if (linkStatus == GL_FALSE)
    {
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

    //不管编译是否成功，都尝试打印出编译回馈信息。
    GLint nCompileInfoLen = 0;
    glGetShaderiv(uiShaderHandle, GL_INFO_LOG_LENGTH, &nCompileInfoLen);
    if (nCompileInfoLen > 0)
    {
        char* buff = (char*)malloc(nCompileInfoLen+1);
        if (buff)
        {
            buff[nCompileInfoLen] = 0;
            glGetShaderInfoLog(uiShaderHandle, nCompileInfoLen, NULL, buff);
            SoIDEOutputLogError("%s", buff);
            free(buff);
            buff = 0;
        }
    }

    //检查编译是否成功。
    GLint nCompileResult = GL_FALSE;
    glGetShaderiv(uiShaderHandle, GL_COMPILE_STATUS, &nCompileResult);
    if (nCompileResult == GL_FALSE)
    {
        glDeleteShader(uiShaderHandle);
        uiShaderHandle = 0;
    }

    return uiShaderHandle;
}
//--------------------------------------------------------------------------------------------------
