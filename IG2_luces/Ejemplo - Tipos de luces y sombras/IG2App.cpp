#include "IG2App.h"

using namespace Ogre;
using namespace std;

bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt){
        
    // ESC key finished the rendering...
    if (evt.keysym.sym == SDLK_ESCAPE){
        getRoot()->queueEndRendering();
    }
    
    // Move 'node' -Z (point)
    if (evt.keysym.sym == SDLK_w){
        nodePoint->translate(0, 0, -3);
    }
    
    // Move 'node' +Z (point)
    else if (evt.keysym.sym == SDLK_s){
        nodePoint->translate(0, 0, 3);
    }
    
    // Move 'node' +X (point)
    else if (evt.keysym.sym == SDLK_d){
        nodePoint->translate(3, 0, 0);
    }
    
    // Move 'node' -X (point)
    else if (evt.keysym.sym == SDLK_a){
        nodePoint->translate(-3, 0, 0);
    }
    
    
    // Move 'node' -Z (spotlight)
    if (evt.keysym.sym == SDLK_t){
        nodeSpot1->translate(0, 0, -3);
    }
    
    // Move 'node' +Z (spotlight)
    else if (evt.keysym.sym == SDLK_g){
        nodeSpot1->translate(0, 0, 3);
    }
    
    // Move 'node' +X (spotlight)
    else if (evt.keysym.sym == SDLK_h){
        nodeSpot1->translate(3, 0, 0);
    }
    
    // Move 'node' -X (spotlight)
    else if (evt.keysym.sym == SDLK_f){
        nodeSpot1->translate(-3, 0, 0);
    }
    
    
    
    
    
    
//    if (evt.keysym.sym == SDLK_x){
//        node->translate(0, 3, 0);
//    }
    
  return true;
}

void IG2App::shutdown(){
    
  mShaderGenerator->removeSceneManager(mSM);
  mSM->removeRenderQueueListener(mOverlaySystem);  
					
  mRoot->destroySceneManager(mSM);  

  delete mTrayMgr;  mTrayMgr = nullptr;
  delete mCamMgr; mCamMgr = nullptr;
  
  // do not forget to call the base 
  IG2ApplicationContext::shutdown(); 
}

void IG2App::setup(void){
    
    // do not forget to call the base first
    IG2ApplicationContext::setup();

    // Create the scene manager
    mSM = mRoot->createSceneManager();

    // Register our scene with the RTSS
    mShaderGenerator->addSceneManager(mSM);

    mSM->addRenderQueueListener(mOverlaySystem);
    mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow.render);
    mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
    addInputListener(mTrayMgr);
    
    // Adds the listener for this object
    addInputListener(this);
    setupScene();
}

void IG2App::setupScene(void){
    
    //------------------------------------------------------------------------
    // Creating the camera
    
    Camera* cam = mSM->createCamera("Cam");
    cam->setNearClipDistance(1);
    cam->setFarClipDistance(10000);
    cam->setAutoAspectRatio(true);
    //cam->setPolygonMode(Ogre::PM_WIREFRAME);
            
    mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
    mCamNode->attachObject(cam);

    mCamNode->setPosition(0, 0, 1000);
    mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);
    //mCamNode->setDirection(Ogre::Vector3(0, 0, -1));
    
    // and tell it to render into the main window
    Viewport* vp = getRenderWindow()->addViewport(cam);
    //vp->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, 0.9));
    
    mCamMgr = new OgreBites::CameraMan(mCamNode);
    addInputListener(mCamMgr);
    mCamMgr->setStyle(OgreBites::CS_ORBIT);
    
    
    //------------------------------------------------------------------------
    // Creating the floor and Sinbad
    
    MeshManager::getSingleton().createPlane("floor", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
                                            Plane(Vector3::UNIT_Y, 0),
                                            1500, 1500, 200, 200, true, 1, 5, 5,
                                            Vector3::UNIT_Z);
    
    Entity* ent = mSM->createEntity ("exampleFloor", "floor");
    ent->setMaterialName("example/stonesFloor");
    SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode();
    floor->attachObject(ent);
    
    Ogre::Entity * ogreheadEnt = mSM->createEntity("ogrehead.mesh");
    mOgreheadNode =  mSM->getRootSceneNode()->createChildSceneNode();
    mOgreheadNode->attachObject(ogreheadEnt);
    mOgreheadNode->scale(0.7, 0.7, 0.7);
    mOgreheadNode->setPosition(0, 20, 0);
    
    mSM->setShadowTechnique(Ogre::SHADOWTYPE_TEXTURE_MODULATIVE_INTEGRATED);
    
    //------------------------------------------------------------------------
    // Creating the light (Ambient light)
    //mSM->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    
    
    //------------------------------------------------------------------------
    // Creating the light (Point light)
    
    // The light
//    Ogre::Light* pointLight1 = mSM->createLight("PointLight1");
//    pointLight1->setType(Light::LT_POINT);
//    //pointLight1->setDiffuseColour(1.0f,1.0f,1.0f);
//    //pointLight1->setDiffuseColour(1.0f,0.0f,0.0f);
//    //pointLight1->setDiffuseColour(0.0f, 0.0f, 1.0f);
//    
//    // Node with the light attached
//    nodePoint = mSM->getRootSceneNode()->createChildSceneNode();
//    nodePoint->setPosition(50, 30, 30);
//    nodePoint->attachObject(pointLight1);
    
    
    
    //------------------------------------------------------------------------
    // Creating the light (Spot light)
    
    // The light
    Ogre::Light* spotLight1 = mSM->createLight("SpotLight1");
    spotLight1->setType(Light::LT_SPOTLIGHT);
    spotLight1->setSpotlightInnerAngle(Ogre::Degree(5.0f));
    spotLight1->setSpotlightOuterAngle(Ogre::Degree(45.0f));
    spotLight1->setSpotlightFalloff(0.0f);
    spotLight1->setDiffuseColour(1.0f, 1.0f, 1.0f);
    //spotLight1->setDiffuseColour(1.0f,0.0f,0.0f);
    //spotLight1->setDiffuseColour(1.0f, 0.0f, 0.0f);
    
    // Node with the light attached
    nodeSpot1 = mSM->getRootSceneNode()->createChildSceneNode();
    nodeSpot1->setPosition(100,100,100);
    nodeSpot1->setDirection(Ogre::Vector3(-1,-1,-1));
    nodeSpot1->attachObject(spotLight1);
    
//    Ogre::Light* spotLight2 = mSM->createLight("SpotLight2");
//    spotLight2->setType(Light::LT_SPOTLIGHT);
//    spotLight2->setSpotlightInnerAngle(Ogre::Degree(5.0f));
//    spotLight2->setSpotlightOuterAngle(Ogre::Degree(45.0f));
//    //spotLight2->setSpotlightFalloff(0.0f);
//    //spotLight2->setDiffuseColour(1.0f,1.0f,1.0f);
//    //spotLight2->setDiffuseColour(1.0f,0.0f,0.0f);
//    spotLight2->setDiffuseColour(0.0f, 1.0f, 0.0f);
//    
//    // Node with the light attached
//    nodeSpot2 = mSM->getRootSceneNode()->createChildSceneNode();
//    nodeSpot2->setPosition(-50,200,0);
//    nodeSpot2->setDirection(Ogre::Vector3(0,-1,0));
//    nodeSpot2->attachObject(spotLight2);
    
    
    //------------------------------------------------------------------------
    // Creating the light (Directional light)
    
    // The light
//    Ogre::Light* directionalLight1 = mSM->createLight("DirectionalLight1");
//    directionalLight1->setType(Light::LT_DIRECTIONAL);
//    directionalLight1->setDiffuseColour(1.0f,1.0f,1.0f);
//    //directionalLight1->setDiffuseColour(1.0f,0.0f,0.0f);
//    //directionalLight1->setDiffuseColour(0.0f, 1.0f, 0.0f);
//
//    // Node with the light attached
//    nodeDir = mSM->getRootSceneNode()->createChildSceneNode();
//    nodeDir->setDirection(Ogre::Vector3(0,-1,0));
//    nodeDir->attachObject(directionalLight1);
    
}
