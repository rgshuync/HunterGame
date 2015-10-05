//
//  Hunter.cpp
//  protecHause
//
//  Created by NguyenHuy on 8/8/15.
//
//

#include "Hunter.h"

Hunter::Hunter(){}
Hunter::~Hunter(){}

Hunter* Hunter::create(){
    auto obj = new Hunter();
    obj->batchNode= SpriteBatchNode::create("soldier.png");
    obj->frmCache= SpriteFrameCache::getInstance();
    obj->frmCache->addSpriteFramesWithFile("soldier.plist");
    auto frm = obj->frmCache->getSpriteFrameByName("soldier14.png");
    obj->initWithSpriteFrame(frm);
    obj->posBulletInParent=Vect(obj->getContentSize().width/2-10,obj->getContentSize().height/2+12);
    
    return obj;
}
void Hunter::setFire(Vect fireVect,float angle){
    auto bullet = fireBullet::create();
    bullet->setAnchorPoint(Vect(0.5,0.5));
    bullet->setPosition(posBulletInParent);
    bullet->setFire(angle);
    addChild(bullet);
    bullet->getPhysicsBody()->applyImpulse(fireVect);
    bullet->setScheRemove();
}

void Hunter::setStatus(float anglePos){
    
    if(anglePos<=0){
        auto fr = frmCache->getSpriteFrameByName("soldier14.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>0 && anglePos <= 5){
        auto fr = frmCache->getSpriteFrameByName("soldier13.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>5 && anglePos <= 10){
        auto fr = frmCache->getSpriteFrameByName("soldier12.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>10 && anglePos <= 15){
        auto fr = frmCache->getSpriteFrameByName("soldier11.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>15 && anglePos <= 20){
        auto fr = frmCache->getSpriteFrameByName("soldier10.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>20 && anglePos <= 25){
        auto fr = frmCache->getSpriteFrameByName("soldier9.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>25 && anglePos <= 30){
        auto fr = frmCache->getSpriteFrameByName("soldier8.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>30 && anglePos <= 35){
        auto fr = frmCache->getSpriteFrameByName("soldier7.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>35 && anglePos <= 40){
        auto fr = frmCache->getSpriteFrameByName("soldier6.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>40 && anglePos <= 45){
        auto fr = frmCache->getSpriteFrameByName("soldier5.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>45 && anglePos <= 50){
        auto fr = frmCache->getSpriteFrameByName("soldier4.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>50 && anglePos <= 55){
        auto fr = frmCache->getSpriteFrameByName("soldier3.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>55 && anglePos < 60){
        auto fr = frmCache->getSpriteFrameByName("soldier2.png");
        setSpriteFrame(fr);
    }
    else if(anglePos>=60){
        auto fr = frmCache->getSpriteFrameByName("soldier1.png");
        setSpriteFrame(fr);
        
    }

}