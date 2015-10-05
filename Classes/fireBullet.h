//
//  fireBullet.h
//  protecHause
//
//  Created by NguyenHuy on 8/8/15.
//
//

#ifndef __protecHause__fireBullet__
#define __protecHause__fireBullet__

#include <stdio.h>
USING_NS_CC;
class fireBullet:public Sprite{
public:
    fireBullet();
    ~fireBullet();
    static fireBullet* create();
    void setFire(float);
    void setBoom();
    void setScheRemove();
private:
    void setRemove(float);

};
#endif /* defined(__protecHause__fireBullet__) */
