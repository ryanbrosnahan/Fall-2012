#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <OGRE/ExampleApplication.h>

namespace Bot
{

class Application : public ExampleApplication
{

public:

	bool configure();

	void createScene();

	void createCamera();

	void createFrameListener();

	void destroyScene();

private:

	// The "character" in the game (an entity)
	Ogre::Entity* robotEntity;

};

}

#endif
