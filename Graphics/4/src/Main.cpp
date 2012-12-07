#include "Robot/Application.hpp"

int main(int argc, const char* const argv[]) {

	Bot::Application app;

	try	{
		app.go();
	}
	catch (const Ogre::Exception& e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}
