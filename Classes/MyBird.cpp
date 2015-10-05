//
//  MyBird.cpp
//  protecHause
//
//  Created by NguyenHuy on 8/10/15.
//
//

#include "MyBird.h"
MyBird::MyBird(){}
MyBird::~MyBird(){}
MyBird* MyBird::create(){
    MyBird * obj = new MyBird();
    obj->frmCache = SpriteFrameCache::getInstance();
    obj->frmCache->addSpriteFramesWithFile("bird.plist");
    auto frm = obj->frmCache->getSpriteFrameByName("bird1.png");
    obj->initWithSpriteFrame(frm);
    obj->autorelease();
    obj->setfly();
    return obj;
    
}
void MyBird::setfly(){
    auto phys = PhysicsBody::createBox(Size(getContentSize().width/2,getContentSize().height/2),PhysicsMaterial(0,1,0));
    setPhysicsBody(phys);
    phys->setContactTestBitmask(2);
    phys->setGravityEnable(false);
    phys->setCollisionBitmask(0x000);
    char str[50]={0};
    Vector<SpriteFrame*> vFrm;
    for(int i=1;i<=14;i++){
        sprintf(str,"bird%d.png",i);
        auto spFrm = frmCache->getSpriteFrameByName(str);
        vFrm.pushBack(spFrm);
    }
    
    auto animation = Animation::createWithSpriteFrames(vFrm,0.1);
    auto ani = Animate::create(animation);
    auto repeat = RepeatForever::create(ani);
    this->runAction(repeat);
    schedule(schedule_selector(MyBird::setRemoveParent),4);
}
void MyBird::setRemoveParent(float){
    if(getPositionY()<0) {
        removeFromParent();
        CCLOG("done remove bird!");
    }
}
void MyBird::setDie(Vect vect){
    stopAllActions();
    getPhysicsBody()->setGravityEnable(true);
    auto frm = frmCache->getSpriteFrameByName("birdLeg.png");
    setSpriteFrame(frm);
    auto veloc = getPhysicsBody()->getVelocity();
    char str[50]={0};
    for(int i=1;i<=6;i++){
        sprintf(str, "birdPart%d.png",i);
        auto sp = Sprite::createWithSpriteFrame(frmCache->getSpriteFrameByName(str));
        sp->setAnchorPoint(Vect(0.5,0.5));
        sp->setPosition(Vect(getContentSize().width/2,getContentSize().height/2));
        auto phys = PhysicsBody::createBox(Size(sp->getContentSize().width/2,getContentSize().height/2),PhysicsMaterial(5,1,5));
        phys->setCollisionBitmask(0x000);
        phys->setVelocity(Vect(i*30,100));
        float ro= random(-100, 100);
        sp->setRotation(ro);
        sp->setPhysicsBody(phys);
        addChild(sp);
    }
    
}
void MyBird::setFireShit(){}