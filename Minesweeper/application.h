#pragma once

#include <chrono>
#include <atomic>
#include <thread>
#include <condition_variable>

#include "precision_delay.h"
#include "minesweeper_action.h"
#include "fps_counter.h"
#include "tile_map.h"
#include "audio_loop_tracker.h"

#include "rendering/shader.h"
#include "rendering/text_renderer.h"
#include "rendering/texture.h"
#include "rendering/texture_registry.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

#include <SDL3/SDL.h>
#include <mgl.h>

class Application
{
public:
    Application() = default;
    ~Application();

    void Run(bool sandboxModeEnabled = false);

private:
    std::atomic<int> m_windowWidth = 1280;
    std::atomic<int> m_windowHeight = 720;

    MinesweeperActionQueue m_actionQueue;

    std::atomic<bool> m_running{ true };

    SDL_Window* m_window = nullptr;
    SDL_GLContext m_context = nullptr;
    SDL_AudioStream* m_audioStream = nullptr;

    std::unique_ptr<Shader> m_mainShader{ nullptr };
    std::shared_ptr<TextureRegistry> m_textureRegistry{ nullptr };

    std::unique_ptr<TileMap> m_tileMap{ nullptr };

    std::shared_ptr<Font> m_font{ nullptr };
    std::unique_ptr<TextRenderer> m_textRenderer{ nullptr };

    std::unordered_map<glm::ivec2, Tile*> m_collapseQueue;
    std::unordered_map<glm::ivec2, Tile*> m_delayedCollapseQueue;

    std::chrono::high_resolution_clock::time_point m_startTime = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point m_lastFrame = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point m_lastFPSCounterUpdate = std::chrono::high_resolution_clock::now();

    FPSCounter m_fpsCounter{ 120 };

    glm::mat4 m_projection = glm::mat4(1.0f);
    GLint m_projectionLocation = 0;
    GLint m_modelLocation = 0;
    GLint m_textureIDLocation = 0;
    GLint m_overlayTextureLocation = 0;
    GLint m_containsOverlayLocation = 0;
    GLint m_tintLocation = 0;

    float m_sideTextScale = 1.0f;

    glm::vec3 m_tintColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 m_targetTintColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 m_tintColorVelocity = glm::vec3(0.0f, 0.0f, 0.0f);

    AudioLoopTracker m_tracker = {
        .audioData = nullptr,
        .length = 0,
        .playPosition = 0,
        .volume = 1.0f,
    };

    glm::ivec2 m_hoveredTile = glm::ivec2(0, 0);

    GLuint m_tileVAO = 0;
    GLuint m_tileVBO = 0;
    GLuint m_tileEBO = 0;

    int m_safeTilesCollapsed = 0;

    int m_score = 0;
    int m_flagsRemaining = 0;
    int m_wins = 0;

    float m_tileScale = 100.0f;

    std::atomic<bool> m_dead{ false };
    std::atomic<bool> m_won{ false };
    std::atomic<bool> m_godMode{ false };
    std::atomic<bool> m_sandboxMode{ false };
    std::atomic<bool> m_paused{ false };
    bool m_safeStart = true;
    bool m_showFPSCounter = false;

    std::condition_variable m_tickCondition;

    std::atomic<bool> m_windowResized{ false };
    std::mutex m_tileMapMutex;

    bool m_firstClick = false;
    bool m_forceTick = false;

    std::thread m_renderThread;
    std::thread m_gameThread;

    static void APIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

    inline constexpr void PushAction(MinesweeperActionType type)
    {
        MinesweeperAction action;
        action.type = type;
        m_actionQueue.push(action);
    }

    template<typename T, typename... Args>
    inline constexpr void PushAction(Args&&... args)
    {
        T action(std::forward<Args>(args)...);
        m_actionQueue.push(*reinterpret_cast<MinesweeperAction*>(&action));
    }

    inline constexpr void ToggleGodmode() noexcept
    {
        m_godMode = !m_godMode;
    }

    inline constexpr void TogglePaused() noexcept
    {
        m_paused = !m_paused;
    }

    inline constexpr void StepForward() noexcept
    {
        std::lock_guard<std::mutex> lock(m_tileMapMutex);
        m_forceTick = true;
        m_tickCondition.notify_one();
    }

    inline constexpr void ToggleMusic() noexcept
    {
        m_tracker.volume = m_tracker.volume == 1.0f ? 0.0f : 1.0f;
    }

    inline constexpr void ToggleSafeClick() noexcept
    {
        m_safeStart = !m_safeStart;
    }

    void Initialize();

    void InitializeVideo();
    void CreateSDLWindow();

    void CreateOpenGLContext();
    void LoadOpenGL();
    void SetupOpenGLDebugMessenger() noexcept;

    void CreateShaders();
    void CreateProjectionMatrix() noexcept;

    void LoadTextures();
    void CreateTileBuffers();

    void ResetStats() noexcept;

    void CreateTileMap();

    glm::ivec2 GetHoveredTilePosition() noexcept;

    void LoadFont();
    void CreateTextRenderer();

    void CollapseTile(const glm::ivec2& position) noexcept;
    void ToggleFlag(const glm::ivec2& position) noexcept;

    static void SDLCALL AudioLoopCallback(void* userdata, SDL_AudioStream* audioStream, int additionalAmount, int totalAmount);

    void InitializeAudio();
    void CreateAudioStream();

    void KillPlayer();
    void PlayerWon();

    void FlagMines() noexcept;
    void CompleteBoard() noexcept;
    void ResetBoard() noexcept;

    void WindowResized() noexcept;
    void ScaleWindowViewport();

    void CreateThreads() noexcept;
    void ScaleTiles() noexcept;

    void RenderThread();
    void GameThread();
    void MainLoop();

    void LoadIniFile();
    void SaveSettings();

    void Cleanup() noexcept;

};
