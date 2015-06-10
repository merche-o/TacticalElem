#include "Settings.h"

const int			Settings::WIDTH = 1280;
const int			Settings::HEIGHT = 800;
const int			Settings::MAP_HEIGHT = 12;
const int			Settings::MAP_WIDTH = 12;
const int			Settings::CASE_SIZE = 45;
const int			Settings::INTERFACE_BOTTOM_HEIGHT = 210;
const int			Settings::INTERFACE_RIGHT_WIDTH = 350;
const int			Settings::INTERFACE_HOVER_PLAYER[2] = {WIDTH - INTERFACE_RIGHT_WIDTH + 65, 60};
const int			Settings::INTERFACE_HOVER_CASE[2] = {WIDTH - INTERFACE_RIGHT_WIDTH + 65, 295};
const int			Settings::INTERFACE_CURRENT_PLAYER[2] = {WIDTH - INTERFACE_RIGHT_WIDTH + 65, 570};
const int			Settings::INTERFACE_TIMELINE[2] = {600, HEIGHT - INTERFACE_BOTTOM_HEIGHT};
const int			Settings::INTERFACE_SPELLS[2] = {40, HEIGHT - INTERFACE_BOTTOM_HEIGHT};
const std::string	Settings::GAME_NAME = std::string("Tactical Element");