
#include "MyGame.h"

//bool game_removed = 0;
int main()
{

	//init srand
	std::srand(static_cast<unsigned>(time(NULL)));


	//init game
	MyGame game;
	
	
	//game loop
	while (game.running())
	{
		//update
		game.uppdate();
		//render
		game.render();
		//MyTriangle tr(80.f, 3);

		
	}
	return 0;
}
