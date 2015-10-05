#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
   // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto evenTouch = EventListenerTouchOneByOne::create();
    evenTouch->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    evenTouch->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    evenTouch->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    auto evenContact = EventListenerPhysicsContact::create();
    evenContact->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    _eventDispatcher->   addEventListenerWithSceneGraphPriority(evenContact, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(evenTouch, this);
    
    //frmCache = SpriteFrameCache::getInstance();
    //frmCache->addSpriteFramesWithFile("soldier.plist");
    //batchNode = SpriteBatchNode::create("soldier.png");
    //auto fsp = frmCache->getSpriteFrameByName("soldier14.png");
    spHunter = Hunter::create();
    spHunter->setTag(1);
    //batchNode->addChild(spHunter);
    spHunter->setAnchorPoint(Vect(0.5,0));
    spHunter->setPosition(Vect(visibleSize.width/3-80,80));
    auto bg= Sprite::create("bg_desert.png");
    bg->setAnchorPoint(Vect(0.5,0.5));
    bg->setPosition(Vect(visibleSize.width/2,visibleSize.height/2));
    bg->setScaleX(0.9);
    bg->setScaleY(1.1);
    addChild(bg,1);
    addChild(spHunter,2);
    //create progress bar
    auto spBg = Sprite::create("bgBar.png");
    spBg->setScale(0.4f);
    spBg->setRotation(-90);
    spBg->setAnchorPoint(Vect(0,0.5f));
    spBg->setPosition(Vect(20,spHunter->getPositionY()));
    addChild(spBg,3);
    proShoot= ProgressTimer::create(Sprite::create("progress.png"));
    proShoot->setBarChangeRate(Vect(1,0));
    proShoot->setAnchorPoint(Vect(0.5,0.5));
    spBg->addChild(proShoot);
    proShoot->setPosition(Vect(spBg->getContentSize().width/2,spBg->getContentSize().height/2));
    //proShoot->setPercentage(80);
    proShoot->setType(ProgressTimer::Type::BAR);
    proShoot->setMidpoint(Vect(0,1));
    schedule(schedule_selector(HelloWorld::createBird),1.5);
    return true;
}
bool HelloWorld::onContactBegin(PhysicsContact & contact){
    auto sA = contact.getShapeA();
    auto bullet = (MyBird*) (sA->getBody()->getNode());
    auto sB = contact.getShapeB();
    auto spA = (MyBird*)(sA->getBody()->getNode());
    if(sB->getBody()->getContactTestBitmask()==2) {
        auto bird=(MyBird*)(sB->getBody()->getNode());
        bird->setDie(bullet->getPhysicsBody()->getVelocity());
    }
    return true;
}
void HelloWorld::updateProg(){
     auto proTo = ProgressFromTo::create(1, 0, 100);
    proShoot->runAction(proTo);
}
float HelloWorld::getProg(){
    auto percent= proShoot->getPercentage();
    proShoot->stopAllActions();
    return percent;
}
void HelloWorld::getAngleGun(Touch * touch){
    auto posBullX = spHunter->posBulletInParent.x + spHunter->getPositionX()- spHunter->getContentSize().width/2;
    auto posBullY = spHunter->posBulletInParent.y + spHunter->getPositionY();
    auto angleStatus = atanf((touch->getLocation().y/touch->getLocation().x))*180/PI;
    anglePos = atanf(((touch->getLocation().y-posBullY)/(touch->getLocation().x-posBullX)))*180/PI;
    CCLOG("goc laf %f",anglePos);
    if(anglePos<0) anglePos=0;
    else if(anglePos>60) anglePos=60;
    spHunter->setStatus(anglePos);
}
bool HelloWorld::onTouchBegan(Touch* touch, Event * event){
    CCLOG("vitriX %f, vitriY %f",touch->getLocation().x,touch->getLocation().y);
    preVect = touch->getLocation();
    getAngleGun(touch);
    auto callFunc = CallFunc::create(CC_CALLBACK_0(HelloWorld::updateProg, this));
    runAction(callFunc);
    return true;
}
void HelloWorld::onTouchMoved(Touch* touch, Event*event){
    getAngleGun(touch);
}
void HelloWorld::onTouchEnded(Touch*touch, Event*event){
    forceShoot= getProg();
    auto vectX = forceShoot*15*cosf(anglePos*3.14/180);
    auto vectY = forceShoot*15*sinf(anglePos*3.14/180);
    auto fireVect= Vect(vectX,vectY);
    
    spHunter->setFire(fireVect,anglePos);
    
}
void HelloWorld::onTouchCancelled(cocos2d::Touch*, cocos2d::Event*){}
void HelloWorld::createBird(float){
     Size visibleSize = Director::getInstance()->getVisibleSize();
    auto spB = MyBird::create();
    spB->setPosition(Vect(visibleSize.width,random(visibleSize.height/3, visibleSize.height)));
    spB->getPhysicsBody()->applyImpulse(Vect(-70,0));
    addChild(spB,5);
}