//
//  Hunter.h
//  protecHause
//
//  Created by NguyenHuy on 8/8/15.
//
//

#ifndef __protecHause__Hunter__
#define __protecHause__Hunter__

#include <stdio.h>
#include "fireBullet.h"
USING_NS_CC;
class Hunter:public Sprite{
public:
    Hunter();
    ~Hunter();
    static Hunter* create();
    Vect posBulletInParent;
    void setStatus(float);
    void setFire(Vect,float);
    void setBullet();
    SpriteBatchNode * batchNode;
    SpriteFrameCache * frmCache;
    
};

#endif /* defined(__protecHause__Hunter__) */
