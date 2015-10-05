#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <Hunter.h>
#include "MyBird.h"
USING_NS_CC;
#define PI 3.14
class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    SpriteFrameCache * frmCache;
    SpriteBatchNode * batchNode;
    float anglePos;
    Vect preVect;
    Vect LastVect;
    Hunter * spHunter;
    ProgressTimer *proShoot;
    float forceShoot;
    // a selector callback
    void getAngleGun(Touch*);
    void menuCloseCallback(cocos2d::Ref* pSender);
    void updateProg();
    float getProg();
    void createBird(float);
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    PhysicsWorld * getPhysicsWorld();
    bool onContactBegin(PhysicsContact & contact);
    // implement the "static create()" method manually
private:
    PhysicsWorld * seneWorld;
    void setPhysicsWorld(PhysicsWorld * world){seneWorld= world;}
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
