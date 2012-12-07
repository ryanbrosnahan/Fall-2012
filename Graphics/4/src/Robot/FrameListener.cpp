#include "FrameListener.hpp"

#include <OGRE/OgreRoot.h>
#include <OGRE/OgreRenderWindow.h>
#include <OGRE/OgreEntity.h>
#include <OGRE/OgreMath.h>

// Constructor
Bot::FrameListener::FrameListener(Ogre::Root* root) : root(root)
{
    // Get the robot entity
    this->robotEntity = this->root
        ->getSceneManager("ExampleSMInstance")->getEntity("Robot");

    // Get the current window ID
    std::size_t winId;
    this->root->getAutoCreatedWindow()->getCustomAttribute("WINDOW", &winId);

    // Setup the input manager
    this->inputManager = OIS::InputManager::createInputSystem(winId);

    // Setup the keyboard input listener
    this->inputKeyboard = static_cast<OIS::Keyboard*>
        (this->inputManager->createInputObject(OIS::OISKeyboard, false));
}


// Cleanup the input systems
Bot::FrameListener::~FrameListener()
{
    this->inputManager->destroyInputObject(this->inputKeyboard);
    OIS::InputManager::destroyInputSystem(this->inputManager);
}

// Each frame tick there is a FrameEvent
bool Bot::FrameListener::frameRenderingQueued(const Ogre::FrameEvent& event)
{
    this->inputKeyboard->capture();

    // Robot should default to idle state
    this->currentAnimation = this->robotEntity->getAnimationState("Idle");

    // If R is pressed, wave, or in this case, shoot.
    if (this->inputKeyboard->isKeyDown(OIS::KC_R)) {
        this->currentAnimation = this->robotEntity->getAnimationState("Shoot");
    }

    // If W is pressed, walk
    if (this->inputKeyboard->isKeyDown(OIS::KC_W)) {
        //this->robotEntity->getParentNode()->yaw(Ogre::Radian(.0005f)); // DO THE MOONWALK!

        // Motion for walking
        this->robotEntity->getParentNode()->translate(0.01f, 0, 0);

        // Make the camera follow the robot
        this->root
            ->getSceneManager("ExampleSMInstance")
            ->getCamera("PlayerCam")
            ->setPosition(this->robotEntity->getParentNode()->getPosition() + Ogre::Vector3(150, 135, 75));

        // Update the lookAt as well to follow the robot
        this->root
            ->getSceneManager("ExampleSMInstance")
            ->getCamera("PlayerCam")
            ->lookAt(this->robotEntity->getParentNode()->getPosition());

        // Do the walk animation
        this->currentAnimation = this->robotEntity->getAnimationState("Walk");
    }

    // Quit if ESC or Q are pressed -OR- if the window is closed
    if (this->inputKeyboard->isKeyDown(OIS::KC_ESCAPE)
        || this->inputKeyboard->isKeyDown(OIS::KC_Q)
        || this->root->getAutoCreatedWindow()->isClosed())
    {
        return FALSE;
    }

    // Increment the animation
    this->currentAnimation->setEnabled(true);
    this->currentAnimation->setLoop(true);
    this->currentAnimation->addTime(event.timeSinceLastFrame);

    return true;
}
