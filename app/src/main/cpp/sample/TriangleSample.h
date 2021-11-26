//
// Created by Administrator on 2021/11/23.
//

#ifndef LCOPENGLES_TRIANGLESAMPLE_H
#define LCOPENGLES_TRIANGLESAMPLE_H

#include "../LCOpenGLShader.h"

class TriangleSample {

public:
    TriangleSample();
    ~TriangleSample();

    void Init(AAssetManager*  pManager);
    void Draw();
    void Destroy();

private:
    LCOpenGLShader* m_pOpenGLShader;

};


#endif //LCOPENGLES_TRIANGLESAMPLE_H
