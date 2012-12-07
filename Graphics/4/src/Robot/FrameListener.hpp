#ifndef FRAMELISTENER_HPP
#define FRAMELISTENER_HPP

#include <OIS/OIS.h>
#include <OGRE/OgreFrameListener.h>

namespace Bot
{

class FrameListener : public Ogre::FrameListener {

private:
    OIS::InputManager* inputManager;
    OIS::Keyboard*     inputKeyboard;

    Ogre::Root*   root;
    Ogre::Entity* robotEntity;

    Ogre::AnimationState* currentAnimation;

public:
    FrameListener(Ogre::Root*);
    ~FrameListener();

    bool frameRenderingQueued(const Ogre::FrameEvent &evt);

};

} // namespace

#endif