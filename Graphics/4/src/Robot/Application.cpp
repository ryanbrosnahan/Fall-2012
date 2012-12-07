#include "Application.hpp"
#include "FrameListener.hpp"
#include <OGRE/OgreEntity.h>

// Configure contains some default settings hardcoded
bool Bot::Application::configure() {

	// Always load the GL render system
	mRoot->loadPlugin("RenderSystem_GL");

	// Get the GL Render system and set it on the root
	Ogre::RenderSystem* RS = mRoot->getAvailableRenderers()[0];
	mRoot->setRenderSystem(RS);

	// Not fullscreen
	RS->setConfigOption("Full Screen", "no");

	// Setup the root window
	mWindow = mRoot->initialise(true, "Project 4");

	return true;
}

// Makes the scene: puts stuff in the scene
void Bot::Application::createScene() {

    // a light, not really needed
    Ogre::SceneNode* lightNode = mSceneMgr->getRootSceneNode()
        ->createChildSceneNode("LightNode", Ogre::Vector3(10.f, 0.f, 0.f));

    // ground plane geometry
    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

    // a "physical" plane created based on geometry above
    Ogre::MeshManager::getSingletonPtr()->createPlane(
            "plane", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
            plane, 2500, 2500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

    // Make it an entity and place it in the scene
    Ogre::Entity* groundPlane = mSceneMgr->createEntity("Ground", "plane");

    Ogre::SceneNode* planeSceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(
            "GroundNode", Ogre::Vector3(0.0f, -5.0f, 0.0f));

    planeSceneNode->attachObject(groundPlane);

    groundPlane->setMaterialName("Examples/Rockwall");

    // Robot
    Ogre::SceneNode* robotSceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("RobotNode");

    robotEntity = mSceneMgr->createEntity("Robot", "robot.mesh");

    robotSceneNode->attachObject(this->robotEntity);
}

// Create a camera and look at the Robot
void Bot::Application::createCamera() {
    ExampleApplication::createCamera();
    mCamera->setPosition(150, 135, 75);
    mCamera->lookAt(0,0,0);
}

// Frame listener, only for the robot at this point
void Bot::Application::createFrameListener() {
    mRoot->addFrameListener(new Bot::FrameListener(this->mRoot));
}

// Pointers; must be explicitly destroyed
void Bot::Application::destroyScene() {
    this->mSceneMgr->destroyEntity(this->robotEntity);
    this->mSceneMgr->clearScene();
}