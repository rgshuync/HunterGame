//
//  fireBullet.cpp
//  protecHause
//
//  Created by NguyenHuy on 8/8/15.
//
//

#include "fireBullet.h"

fireBullet::fireBullet(){}
fireBullet::~fireBullet(){}

fireBullet * fireBullet::create(){
    auto obj = new fireBullet();
    if(obj->initWithFile("bullet.png")){
        auto cirle = PhysicsBody::createCircle(obj->getContentSize().width,PhysicsMaterial(0,1,0));
        obj->setPhysicsBody(cirle);
        cirle->setContactTestBitmask(true);
        obj->autorelease();
       
        //obj->addChild(sp);
    }
    
    
    return obj;
}

void fireBullet::setFire(float angle){
    auto sp = Sprite::create("fire1.png");
    sp->setAnchorPoint(Vect(1,0.5));
    sp->setPosition(Vect(getContentSize().width/2,getContentSize().height/2));
    sp->setRotation(-angle);
    
   // addChild(sp);
}
void fireBullet::setBoom(){
    
}
void fireBullet::setScheRemove(){
    schedule(schedule_selector(fireBullet::setRemove));
}
void fireBullet::setRemove(float d){
    if(getPositionY()<0){
        removeFromParent();
        CCLOG("done remove bullet!");
    }
}