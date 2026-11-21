#pragma once

#include <cstdint>

#include <glm/glm.hpp>

#define MINESWEEPER_TILE_EMPTY 0
#define MINESWEEPER_TILE_1 1
#define MINESWEEPER_TILE_2 2
#define MINESWEEPER_TILE_3 3
#define MINESWEEPER_TILE_4 4
#define MINESWEEPER_TILE_5 5
#define MINESWEEPER_TILE_6 6
#define MINESWEEPER_TILE_7 7
#define MINESWEEPER_TILE_8 8
#define MINESWEEPER_TILE_BOMB 9
#define MINESWEEPER_TILE_FLAG 10
#define MINESWEEPER_TILE_COLLAPSED 11
#define MINESWEEPER_TILE_HOVERING 12

#define MINESWEEPER_TILE_NONE (static_cast<unsigned int>(-1))

struct Tile
{
    glm::ivec2 position;
    unsigned int textureID;
    bool collapsed;
    bool flagPlaced;
    bool isBomb;
    bool hovered;
    uint8_t neighboringBombs;
};
