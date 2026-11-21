#pragma once

#include <random>

#include <glm/glm.hpp>

#include "tile.h"

class TileMap
{
public:
    glm::ivec2 mapSize;
    std::vector<Tile> tiles;
    int bombCount;

    TileMap(const glm::ivec2& mapSize, int bombCount, int64_t seed = 0)
        : mapSize(mapSize), bombCount(bombCount), columnDistribution(0, mapSize.x - 1), rowDistribution(0, mapSize.y - 1)
    {
        if (seed == 0)
        {
            std::random_device m_device;
            int64_t high = m_device();
            int64_t low = m_device();
            m_seed = (high << 32) | low;
        }
        else
        {
            m_seed = seed;
        }
        m_rng.seed(m_seed);
        for (int y = 0; y < mapSize.y; ++y)
        {
            for (int x = 0; x < mapSize.x; ++x)
            {
                Tile newTile;
                newTile.position = glm::ivec2(x, y);
                newTile.textureID = MINESWEEPER_TILE_NONE;
                newTile.collapsed = false;
                newTile.flagPlaced = false;
                newTile.isBomb = false;
                newTile.hovered = false;
                newTile.neighboringBombs = 0;
                tiles.push_back(std::move(newTile));
            }
        }
    }

    inline constexpr int64_t GetSeed() const
    {
        return m_seed;
    }

    inline constexpr Tile* GetTile(const glm::ivec2& position)
    {
        if (position.x < 0 || position.x >= mapSize.x || position.y < 0 || position.y >= mapSize.y) return nullptr;
        return &tiles[position.x + (position.y * mapSize.x)];
    }

    void GenerateBombs();
    void GenerateBombs(const std::vector<Tile*>& illegalBombTiles);

private:
    std::mt19937_64 m_rng;

    std::uniform_int_distribution<int> columnDistribution;
    std::uniform_int_distribution<int> rowDistribution;

    int64_t m_seed;

    inline constexpr Tile* RandomTile();

};
