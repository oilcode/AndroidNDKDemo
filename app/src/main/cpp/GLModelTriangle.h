//--------------------------------------------------------------------------------------------------
#ifndef _GLModelTriangle_h_
#define _GLModelTriangle_h_
//--------------------------------------------------------------------------------------------------
class GLShaderBase;
//--------------------------------------------------------------------------------------------------
class GLModelTriangle
{
public:
    GLModelTriangle();
    ~GLModelTriangle();
    void ModelTriangleUpdate();
    void ModelTriangleRender();

private:
    const GLShaderBase* m_pShader;
    float m_fVertexList[6];

};
//--------------------------------------------------------------------------------------------------
#endif //_GLModelTriangle_h_
//--------------------------------------------------------------------------------------------------
