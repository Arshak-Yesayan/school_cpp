#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef SETTINGS

using namespace std;

#define WIDTH 1280
#define HEIGHT 720

#define COLS 256
#define FOV 105
#define MAX_FPS 75

float MAX_DELAY = 1.f / (float)MAX_FPS;
float ANGLE = (float)FOV / (float)COLS;

#endif