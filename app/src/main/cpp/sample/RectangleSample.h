//
// Created by Administrator on 2021/11/23.
//

#ifndef LCOPENGLES_RECTANGLESAMPLE_H
#define LCOPENGLES_RECTANGLESAMPLE_H

#include "../LCOpenGLShader.h"

class RectangleSample {

public:
    RectangleSample();
    ~RectangleSample();

    void Init(AAssetManager*  pManager);
    void Draw();
    void Destroy();


private:
    LCOpenGLShader* m_pOpenGLShader;
};


#endif //LCOPENGLES_RECTANGLESAMPLE_H
