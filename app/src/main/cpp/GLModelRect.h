//--------------------------------------------------------------------------------------------------
#ifndef _GLModelRect_h_
#define _GLModelRect_h_
//--------------------------------------------------------------------------------------------------
class GLShaderBase;
//--------------------------------------------------------------------------------------------------
class GLModelRect
{
public:
    GLModelRect();
    ~GLModelRect();
    void ModelRectUpdate();
    void ModelRectRender();
    void SetPosDelta(float fx, float fy);

private:
    const GLShaderBase* m_pShader;
    float m_fVertexList[20];
    unsigned short m_usIndexList[6];
    int m_nTextureId;
};
//--------------------------------------------------------------------------------------------------
#endif //_GLModelRect_h_
//--------------------------------------------------------------------------------------------------
