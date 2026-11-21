#include "tile_map.h"

void TileMap::GenerateBombs()
{
    int bombsGenerated = 0;
    while (bombsGenerated < bombCount)
    {
        Tile* selectedTile;
        do
        {
            selectedTile = RandomTile();
        } while (selectedTile->isBomb);

        for (int y = -1; y <= 1; ++y)
        {
            for (int x = -1; x <= 1; ++x)
            {
                if (x == 0 && y == 0) continue;
                glm::ivec2 position = glm::ivec2(selectedTile->position.x + x, selectedTile->position.y + y);
                if (position.x >= 0 && position.x < mapSize.x && position.y >= 0 && position.y < mapSize.y)
                {
                    tiles[position.x + (position.y * mapSize.x)].neighboringBombs += 1;
                }
            }
        }
        selectedTile->isBomb = true;

        ++bombsGenerated;
    }
}

void TileMap::GenerateBombs(const std::vector<Tile*>& illegalBombTiles)
{
    int bombsGenerated = 0;
    while (bombsGenerated < bombCount)
    {
        Tile* selectedTile;
        bool tileIllegal;
        do
        {
            tileIllegal = false;
            selectedTile = RandomTile();
            if (selectedTile->isBomb)
            {
                tileIllegal = true;
            }
            else
            {
                for (Tile* tile : illegalBombTiles)
                {
                    if (selectedTile->position == tile->position)
                    {
                        tileIllegal = true;
                        break;
                    }
                }
            }
        } while (tileIllegal);

        for (int y = -1; y <= 1; ++y)
        {
            for (int x = -1; x <= 1; ++x)
            {
                if (x == 0 && y == 0) continue;
                glm::ivec2 position = glm::ivec2(selectedTile->position.x + x, selectedTile->position.y + y);
                if (position.x >= 0 && position.x < mapSize.x && position.y >= 0 && position.y < mapSize.y)
                {
                    tiles[position.x + (position.y * mapSize.x)].neighboringBombs += 1;
                }
            }
        }
        selectedTile->isBomb = true;

        ++bombsGenerated;
    }
}

inline constexpr Tile* TileMap::RandomTile()
{
    int randomColumn = columnDistribution(m_rng);
    int randomRow = rowDistribution(m_rng);
    size_t index = randomColumn + (randomRow * mapSize.x);

    Tile* randomTile = &tiles[index];

    return randomTile;
}
