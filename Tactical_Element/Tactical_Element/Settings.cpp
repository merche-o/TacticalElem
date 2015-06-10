#include "Settings.h"

const int			Settings::WIDTH = 1280;
const int			Settings::HEIGHT = 800;
const int			Settings::MAP_HEIGHT = 12;
const int			Settings::MAP_WIDTH = 12;
const int			Settings::CASE_SIZE = 45;
const int			Settings::INTERFACE_BOTTOM_HEIGHT = 250;
const int			Settings::INTERFACE_RIGHT_WIDTH = 350;
const int			Settings::INTERFACE_HOVER_PLAYER[2] = {WIDTH - INTERFACE_RIGHT_WIDTH + 65, 100};
const int			Settings::INTERFACE_HOVER_CASE[2] = {WIDTH - INTERFACE_RIGHT_WIDTH + 65, 350};
const int			Settings::INTERFACE_CURRENT_PLAYER[2] = {WIDTH - INTERFACE_RIGHT_WIDTH + 65, 550};
const std::string	Settings::GAME_NAME = std::string("Tactical Element");