#pragma once

#include <glm/glm.hpp>
#include <queue>

enum class MinesweeperActionType : int
{
    None = 0,
    ToggleMusic,
    Restart,
    ClickTile,
    ToggleFlag,
    FlagAllMines,
    ResetBoard,
    AutoCompleteBoard,
    ToggleGodmode,
    TogglePaused,
    StepForward,
    ToggleSafeClick,
};

#if defined(_MSC_VER) && !defined(__clang__)
#pragma warning(push)
#pragma warning(disable : 26495)
#endif

struct MinesweeperActionBase
{
    MinesweeperActionType type;

    MinesweeperActionBase() : type(MinesweeperActionType::None) {}
    ~MinesweeperActionBase() = default;

    MinesweeperActionBase(MinesweeperActionType type) : type(type) {}
};

struct MinesweeperActionClickTile : public MinesweeperActionBase
{
    glm::ivec2 tile;

    MinesweeperActionClickTile(const glm::ivec2& tile) : MinesweeperActionBase(MinesweeperActionType::ClickTile), tile(tile) {}
};

struct MinesweeperActionToggleFlag : public MinesweeperActionBase
{
    glm::ivec2 tile;

    MinesweeperActionToggleFlag(const glm::ivec2& tile) : MinesweeperActionBase(MinesweeperActionType::ToggleFlag), tile(tile) {}
};

union MinesweeperAction
{
    MinesweeperActionType type;
    MinesweeperActionClickTile clickTile;
    MinesweeperActionToggleFlag toggleFlag;

    MinesweeperAction() : type(MinesweeperActionType::None) {}
    MinesweeperAction(MinesweeperActionType type) : type(type) {}
};

using MinesweeperActionQueue = std::queue<MinesweeperAction>;

#if defined(_MSC_VER) && !defined(__clang__)
#pragma warning(pop)
#endif
