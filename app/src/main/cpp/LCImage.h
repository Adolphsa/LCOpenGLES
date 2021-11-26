//
// Created by Administrator on 2021/11/24.
//

#ifndef LCOPENGLES_LCIMAGE_H
#define LCOPENGLES_LCIMAGE_H

#ifndef U8_t
#define U8_t unsigned char
#endif

class LCImage {

public:
    LCImage();
    ~LCImage();

    int         GetWidth() const;
    int         GetHeight() const;
    int         GetType() const ;
    U8_t*       GetData() const;

    void        ReadFromFile(U8_t* fileName);
    void        ReadFromBuffer(U8_t* dataBuff,int length);

private:
    int         m_width;
    int         m_height;
    int         m_type;
    U8_t*       m_pImgData;
};


#endif //LCOPENGLES_LCIMAGE_H
