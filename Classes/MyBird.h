//
//  MyBird.h
//  protecHause
//
//  Created by NguyenHuy on 8/10/15.
//
//

#ifndef __protecHause__MyBird__
#define __protecHause__MyBird__

#include <stdio.h>
USING_NS_CC;
class MyBird:public Sprite{
public:
    MyBird();
    ~MyBird();
    static MyBird* create();
    void setfly();
    void setDie(Vect);
    void setFireShit();
    SpriteFrameCache * frmCache;
private:
    void setRemoveParent(float);
};
#endif /* defined(__protecHause__MyBird__) */
