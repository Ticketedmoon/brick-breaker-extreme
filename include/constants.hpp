#pragma once

namespace constants 
{
	inline const int WINDOW_WIDTH = 1280;
	inline const int WINDOW_HEIGHT = 720;
	inline const int X_SCREEN_LOCATION_OFFSET = 600;
	inline const int Y_SCREEN_LOCATION_OFFSET = 320;
}

enum GameState { 
	PLAYING, 
	GAMEOVER, 
	VICTORY 
};