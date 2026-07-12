#include "application.h"

#include "rendering/vertex.h"

#define MLY_INI_IMPLEMENTATION
#include <mly_ini.h>

Application::~Application()
{
    SaveSettings();
    Cleanup();
}

void Application::Run(bool sandboxModeEnabled)
{
    m_sandboxMode = sandboxModeEnabled;
    Initialize();
    MainLoop();
}

void APIENTRY Application::MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    if (severity == GL_DEBUG_SEVERITY_HIGH)
    {
        std::println(stderr, "[OpenGL Error]: {}", message);
    }
}

void Application::Initialize()
{
    InitializeVideo();
    CreateSDLWindow();
    CreateOpenGLContext();
    LoadOpenGL();
    CreateShaders();
    LoadTextures();
    CreateTileBuffers();
    LoadFont();
    CreateTextRenderer();
    CreateTileMap();
    LoadIniFile();
    InitializeAudio();
    CreateAudioStream();
    ScaleWindowViewport();
    CreateThreads();
}

void Application::InitializeVideo()
{
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO))
    {
        throw std::runtime_error(std::format("[SDL3] Failed to initialize video subsystem: {}", SDL_GetError()));
    }
}

void Application::CreateSDLWindow()
{
    m_window = SDL_CreateWindow("Minesweeper", m_windowWidth, m_windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (m_window == nullptr)
    {
        throw std::runtime_error(std::format("Failed to create SDL3 window: {}", SDL_GetError()));
    }
}

void Application::CreateOpenGLContext()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    m_context = SDL_GL_CreateContext(m_window);
    if (m_context == nullptr)
    {
        throw std::runtime_error(std::format("Failed to create OpenGL context: {}", SDL_GetError()));
    }
}

void Application::LoadOpenGL()
{
    if (!mglLoadGLLoader((mgl_loadProc_t)SDL_GL_GetProcAddress))
    {
        throw std::runtime_error("Failed to load OpenGL!");
    }
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Application::SetupOpenGLDebugMessenger() noexcept
{
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(MessageCallback, nullptr);
}

void Application::CreateShaders()
{
    m_mainShader = std::make_unique<Shader>("main", "assets/shaders/main_vert.glsl", "assets/shaders/main_frag.glsl");
    m_projectionLocation = m_mainShader->GetUniformLocation("projection");
    m_modelLocation = m_mainShader->GetUniformLocation("model");
    m_textureIDLocation = m_mainShader->GetUniformLocation("textureID");
    m_overlayTextureLocation = m_mainShader->GetUniformLocation("overlayTextureID");
    m_containsOverlayLocation = m_mainShader->GetUniformLocation("containsOverlay");
    m_tintLocation = m_mainShader->GetUniformLocation("tint");
}

void Application::CreateProjectionMatrix() noexcept
{
    m_projection = glm::ortho(
        static_cast<float>(-m_windowWidth) / 2.0f,
        static_cast<float>(m_windowWidth) / 2.0f,
        static_cast<float>(-m_windowHeight) / 2.0f,
        static_cast<float>(m_windowHeight) / 2.0f,
        -1.0f, 1.0f
    );
    m_mainShader->Use();
    m_mainShader->SetUniformMatrix(m_projectionLocation, m_projection);
}

void Application::LoadTextures()
{
    m_textureRegistry = std::make_unique<TextureRegistry>();
    SetGlobalTextureRegistry(m_textureRegistry);

    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_EMPTY, std::make_unique<Texture>("assets/textures/MinesweeperTile.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_1, std::make_unique<Texture>("assets/textures/MinesweeperTile1.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_2, std::make_unique<Texture>("assets/textures/MinesweeperTile2.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_3, std::make_unique<Texture>("assets/textures/MinesweeperTile3.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_4, std::make_unique<Texture>("assets/textures/MinesweeperTile4.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_5, std::make_unique<Texture>("assets/textures/MinesweeperTile5.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_6, std::make_unique<Texture>("assets/textures/MinesweeperTile6.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_7, std::make_unique<Texture>("assets/textures/MinesweeperTile7.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_8, std::make_unique<Texture>("assets/textures/MinesweeperTile8.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_FLAG, std::make_unique<Texture>("assets/textures/MinesweeperFlag.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_BOMB, std::make_unique<Texture>("assets/textures/MinesweeperBomb.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_COLLAPSED, std::make_unique<Texture>("assets/textures/MinesweeperTileCollapsed.bmp"));
    m_textureRegistry->RegisterTexture(MINESWEEPER_TILE_HOVERING, std::make_unique<Texture>("assets/textures/MinesweeperTileHovering.bmp"));
}

void Application::CreateTileBuffers()
{
    glGenVertexArrays(1, &m_tileVAO);
    if (m_tileVAO == 0) throw std::runtime_error("Failed to create tile VAO!");
    glGenBuffers(1, &m_tileVBO);
    if (m_tileVBO == 0) throw std::runtime_error("Failed to create tile VBO!");
    glGenBuffers(1, &m_tileEBO);
    if (m_tileEBO == 0) throw std::runtime_error("Failed to create tile EBO!");

    Vertex tileVertices[] = {
        Vertex{ glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
        Vertex{ glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) },
        Vertex{ glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f) },
        Vertex{ glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
    };

    unsigned int indices[] = {
        0, 1, 2, 2, 1, 3
    };

    glBindVertexArray(m_tileVAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_tileVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(tileVertices), tileVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_tileEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Application::ResetStats() noexcept
{
    m_collapseQueue.clear();
    m_delayedCollapseQueue.clear();
    m_score = 0;
    m_flagsRemaining = m_tileMap->bombCount;
    m_dead = false;
    m_targetTintColor = glm::vec3(1.0f, 1.0f, 1.0f);
    m_safeTilesCollapsed = 0;
    m_won = false;
    m_firstClick = true;
}

void Application::CreateTileMap()
{
    std::lock_guard<std::mutex> lock(m_tileMapMutex);
    m_tileMap = std::make_unique<TileMap>(glm::ivec2(30, 24), 99);
    ScaleTiles();
    ResetStats();
}

glm::ivec2 Application::GetHoveredTilePosition() noexcept
{
    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    float mouseCenterX = mouseX - (static_cast<float>(m_windowWidth) / 2.0f);
    float mouseCenterY = (static_cast<float>(m_windowHeight) / 2.0f) - mouseY;

    float worldX = mouseCenterX / m_tileScale;
    float worldY = mouseCenterY / m_tileScale;

    float targetTileX = worldX + (static_cast<float>(m_tileMap->mapSize.x) / 2.0f);
    float targetTileY = worldY + (static_cast<float>(m_tileMap->mapSize.y) / 2.0f);

    int column = static_cast<int>(std::floor(targetTileX));
    int row = static_cast<int>(std::floor(targetTileY));

    return glm::ivec2(column, row);
}

void Application::LoadFont()
{
    m_font = std::make_unique<Font>("assets/fonts/VCR_MONO.ttf");
}

void Application::CreateTextRenderer()
{
    m_textRenderer = std::make_unique<TextRenderer>(m_font);
    m_textRenderer->SetViewportSize(glm::vec2(static_cast<float>(m_windowWidth), static_cast<float>(m_windowHeight)));
}

void Application::CollapseTile(const glm::ivec2& position) noexcept
{
    Tile* tile = m_tileMap->GetTile(position);
    if (tile == nullptr || tile->collapsed || tile->flagPlaced) return;

    bool forceTick = m_collapseQueue.size() == 0;

    if (m_firstClick)
    {
        m_firstClick = false;
        if (m_safeStart)
        {
            std::vector<Tile*> illegalBombTiles;
            for (int y = -1; y <= 1; ++y)
            {
                for (int x = -1; x <= 1; ++x)
                {
                    glm::ivec2 position = glm::ivec2(
                        tile->position.x + x,
                        tile->position.y + y
                    );
                    if (position.x < 0 || position.x >= m_tileMap->mapSize.x || position.y < 0 || position.y >= m_tileMap->mapSize.y) continue;
                    size_t index = position.x + (position.y * m_tileMap->mapSize.x);
                    illegalBombTiles.push_back(&m_tileMap->tiles[index]);
                }
            }
            m_tileMap->GenerateBombs(illegalBombTiles);
        }
        else
        {
            m_tileMap->GenerateBombs();
        }
    }

    m_collapseQueue[tile->position] = tile;

    if (forceTick)
    {
        m_forceTick = true;
        m_tickCondition.notify_one();
    }
}

void Application::ToggleFlag(const glm::ivec2& position) noexcept
{
    Tile* tile = m_tileMap->GetTile(position);
    if (tile == nullptr || tile->collapsed) return;

    if (tile->flagPlaced)
    {
        tile->flagPlaced = false;
        tile->textureID = MINESWEEPER_TILE_NONE;
        m_flagsRemaining += 1;
    }
    else if (m_flagsRemaining > 0)
    {
        tile->flagPlaced = true;
        tile->textureID = MINESWEEPER_TILE_FLAG;
        m_flagsRemaining -= 1;
    }
}

void SDLCALL Application::AudioLoopCallback(void* userdata, SDL_AudioStream* audioStream, int additionalAmount, int totalAmount)
{
    AudioLoopTracker* tracker = static_cast<AudioLoopTracker*>(userdata);

    while (additionalAmount > 0)
    {
        unsigned int bytesLeft = tracker->length - tracker->playPosition;
        unsigned int bytesToWrite = additionalAmount;

        if (bytesToWrite > bytesLeft)
        {
            bytesToWrite = bytesLeft;
        }

        if (tracker->volume > 0.0f) SDL_PutAudioStreamData(audioStream, tracker->audioData + tracker->playPosition, bytesToWrite);

        tracker->playPosition += bytesToWrite;
        additionalAmount -= bytesToWrite;

        if (tracker->playPosition >= tracker->length)
        {
            tracker->playPosition = 0;
        }
    }
}

void Application::InitializeAudio()
{
    if (!SDL_InitSubSystem(SDL_INIT_AUDIO))
    {
        throw std::runtime_error(std::format("[SDL3] Failed to initialize audio subsystem: {}", SDL_GetError()));
    }
}

void Application::CreateAudioStream()
{
    m_tracker.playPosition = 0;
    SDL_AudioSpec spec;
    if (!SDL_LoadWAV("assets/audio/GameTrackTest.wav", &spec, &m_tracker.audioData, &m_tracker.length))
    {
        throw std::runtime_error(std::format("Failed to open audio file: {}", SDL_GetError()));
    }
    m_audioStream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, nullptr, nullptr);
    if (m_audioStream == nullptr)
    {
        throw std::runtime_error(std::format("Failed to open audio device stream: {}", SDL_GetError()));
    }
    SDL_SetAudioStreamGetCallback(m_audioStream, AudioLoopCallback, &m_tracker);
    SDL_ResumeAudioStreamDevice(m_audioStream);
}

void Application::KillPlayer()
{
    if (m_godMode) return;
    m_dead = true;
    m_won = false;
    m_targetTintColor = glm::vec3(1.0f, 0.5f, 0.5f);
}

void Application::PlayerWon()
{
    if (m_dead) return;
    m_won = true;
    m_targetTintColor = glm::vec3(1.0f, 0.8f, 0.3f);
    m_wins += 1;
}

void Application::FlagMines() noexcept
{
    std::lock_guard<std::mutex> lock(m_tileMapMutex);

    if (m_dead || m_won) return;

    bool shouldPlace = m_flagsRemaining > 0;

    for (auto& tile : m_tileMap->tiles)
    {
        if (tile.isBomb && (shouldPlace ? !tile.flagPlaced : tile.flagPlaced))
        {
            ToggleFlag(tile.position);
        }
    }
}

void Application::CompleteBoard() noexcept
{
    std::lock_guard<std::mutex> lock(m_tileMapMutex);
    for (auto& tile : m_tileMap->tiles)
    {
        if (!tile.isBomb && tile.flagPlaced)
        {
            ToggleFlag(tile.position);
        }
    }
    for (auto& tile : m_tileMap->tiles)
    {
        if (tile.isBomb && !tile.flagPlaced)
        {
            ToggleFlag(tile.position);
        }
        m_firstClick = false;
        CollapseTile(tile.position);
    }
}

void Application::ResetBoard() noexcept
{
    std::lock_guard<std::mutex> lock(m_tileMapMutex);
    m_tileMap = std::make_unique<TileMap>(m_tileMap->mapSize, m_tileMap->bombCount, m_tileMap->GetSeed());
    ResetStats();
}

void Application::WindowResized() noexcept
{
    int width, height;
    SDL_GetWindowSizeInPixels(m_window, &width, &height);
    m_windowWidth.store(width);
    m_windowHeight.store(height);
    m_windowResized = true;
}

void Application::ScaleWindowViewport()
{
    glViewport(0, 0, m_windowWidth, m_windowHeight);
    CreateProjectionMatrix();
    m_textRenderer->SetViewportSize(static_cast<float>(m_windowWidth), static_cast<float>(m_windowHeight));
    ScaleTiles();
    float totalBoardWidth = m_tileMap->mapSize.x * m_tileScale;
    float sidePaneSize = (static_cast<float>(m_windowWidth) - totalBoardWidth);
    float pointSizePixels = m_font->PointToPixelsX(m_font->GetSize());
    m_sideTextScale = sidePaneSize / 13.5f;
    m_font->SetSize(m_font->PixelsToPointX(m_sideTextScale));
}

void Application::CreateThreads() noexcept
{
    SDL_GL_MakeCurrent(m_window, NULL);
    m_renderThread = std::thread(&Application::RenderThread, this);
    m_gameThread = std::thread(&Application::GameThread, this);
}

void Application::ScaleTiles() noexcept
{
    float newScale = static_cast<float>(m_windowHeight) / m_tileMap->mapSize.y;
    if (m_tileMap->mapSize.x * newScale > m_windowWidth)
    {
        newScale = static_cast<float>(m_windowWidth) / m_tileMap->mapSize.x;
    }
    m_tileScale = newScale;
}

void Application::RenderThread()
{
#ifndef NDEBUG
    try
    {
#endif
        if (!SDL_GL_MakeCurrent(m_window, m_context))
        {
            throw std::runtime_error(std::format("[SDL3] Failed to make GL context current on render thread: {}", SDL_GetError()));
        }

        SDL_GL_SetSwapInterval(0);
        SetupOpenGLDebugMessenger();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        auto lastRenderedFrame = std::chrono::high_resolution_clock::now();

        while (m_running)
        {
            auto currentFrame = std::chrono::high_resolution_clock::now();
            float deltaTime = std::chrono::duration<float, std::chrono::milliseconds::period>(currentFrame - lastRenderedFrame).count() * 0.001f;
            lastRenderedFrame = currentFrame;

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            uint64_t secondsSinceStart = static_cast<uint64_t>(std::chrono::duration<double, std::chrono::seconds::period>(currentFrame - m_startTime).count());

            uint64_t currentTimeSeconds = secondsSinceStart % 60;
            uint64_t currentTimeMinutes = (secondsSinceStart / 60) % 60;
            uint64_t currentTimeHours = (secondsSinceStart / 3600) % 24;
            uint64_t currentTimeDays = (secondsSinceStart / 86400) % 7;
            uint64_t currentTimeWeeks = secondsSinceStart / 604800;

            glm::vec3 difference = m_targetTintColor - m_tintColor;
            glm::vec3 springForce = difference * 50.0f;
            glm::vec3 dampForce = -m_tintColorVelocity * 17.5f;
            glm::vec3 totalForce = springForce + dampForce;
            m_tintColorVelocity += totalForce * deltaTime;
            m_tintColor += m_tintColorVelocity * deltaTime;

            m_mainShader->Use();

            glBindVertexArray(m_tileVAO);
            glBindBuffer(GL_ARRAY_BUFFER, m_tileVBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_tileEBO);

            m_mainShader->SetUniformInt(m_textureIDLocation, 0);
            m_mainShader->SetUniformInt(m_overlayTextureLocation, 1);
            m_mainShader->SetUniformVector(m_tintLocation, m_tintColor);

            {
                std::lock_guard<std::mutex> lock(m_tileMapMutex);
                for (auto& tile : m_tileMap->tiles)
                {
                    unsigned int targetBackgroundID = MINESWEEPER_TILE_EMPTY;
                    if (tile.collapsed && !tile.isBomb && tile.neighboringBombs < 1)
                        targetBackgroundID = MINESWEEPER_TILE_COLLAPSED;
                    else if (tile.hovered && !m_dead && !m_won)
                        targetBackgroundID = MINESWEEPER_TILE_HOVERING;

                    tile.hovered = tile.position == m_hoveredTile;

                    GLuint backgroundTexture = m_textureRegistry->GetTexture(targetBackgroundID)->GetID();
                    GLuint overlayTexture = (tile.textureID == MINESWEEPER_TILE_NONE || tile.textureID < 1 || tile.textureID > 10) ? MINESWEEPER_TILE_NONE : m_textureRegistry->GetTexture(tile.textureID)->GetID();

                    glActiveTexture(GL_TEXTURE0);
                    glBindTexture(GL_TEXTURE_2D, backgroundTexture);
                    glActiveTexture(GL_TEXTURE1);
                    if (overlayTexture != MINESWEEPER_TILE_NONE)
                    {
                        glBindTexture(GL_TEXTURE_2D, overlayTexture);
                    }

                    m_mainShader->SetUniformInt(m_containsOverlayLocation, overlayTexture == MINESWEEPER_TILE_NONE ? 0 : 1);

                    glm::mat4 model = glm::mat4(1.0f);

                    glm::ivec2 gridPosition = tile.position;
                    glm::vec3 position = glm::vec3(
                        static_cast<float>(gridPosition.x) - static_cast<float>(m_tileMap->mapSize.x) / 2.0f,
                        static_cast<float>(gridPosition.y) - static_cast<float>(m_tileMap->mapSize.y) / 2.0f,
                        0.0f
                    );

                    model = glm::translate(model, position * m_tileScale);
                    model = glm::scale(model, glm::vec3(m_tileScale, m_tileScale, 1.0f));

                    m_mainShader->SetUniformMatrix(m_modelLocation, model);

                    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                }
            }

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);

            if (m_windowResized)
            {
                m_windowResized = false;
                ScaleWindowViewport();
            }

            m_textRenderer->RenderText(
                std::format("---STATS---\nScore:\t{:03}\nFlags:\t{:03}\nWins:\t{:03}", m_score, m_flagsRemaining, m_wins),
                0,
                0,
                1.0f,
                glm::vec3(1.0f, 1.0f, 1.0f),
                0.0f, 0.0f
            );

            if (m_showFPSCounter)
            {
                static unsigned int fps = 0;

                m_fpsCounter.Push(static_cast<unsigned int>(std::round(1.0f / deltaTime)));

                int timeSinceFPSCounterUpdate = static_cast<int>(std::chrono::duration<float, std::chrono::milliseconds::period>(currentFrame - m_lastFPSCounterUpdate).count());
                if (timeSinceFPSCounterUpdate > 1000)
                {
                    m_lastFPSCounterUpdate = currentFrame;
                    fps = m_fpsCounter.GetAverage();
                }
                m_textRenderer->RenderText(
                    std::format("FPS: {}", fps),
                    static_cast<float>(m_windowWidth),
                    static_cast<float>(m_windowHeight),
                    1.0f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    1.0f, 1.0f
                );
            }

            if (currentTimeWeeks > 0)
            {
                m_textRenderer->RenderText(
                   std::format("{:02}:{:02}:{:02}:{:02}:{:02}", currentTimeWeeks, currentTimeDays, currentTimeHours, currentTimeMinutes, currentTimeSeconds),
                   static_cast<float>(m_windowWidth),
                   0,
                   1.0f,
                   glm::vec3(1.0f, 1.0f, 1.0f),
                   1.0f, 0.0f
                );
            }
            if (currentTimeDays > 0)
            {
                m_textRenderer->RenderText(
                   std::format("{:02}:{:02}:{:02}:{:02}", currentTimeDays, currentTimeHours, currentTimeMinutes, currentTimeSeconds),
                   static_cast<float>(m_windowWidth),
                   0,
                   1.0f,
                   glm::vec3(1.0f, 1.0f, 1.0f),
                   1.0f, 0.0f
                );
            }
            if (currentTimeHours > 0)
            {
                m_textRenderer->RenderText(
                   std::format("{:02}:{:02}:{:02}", currentTimeHours, currentTimeMinutes, currentTimeSeconds),
                   static_cast<float>(m_windowWidth),
                   0,
                   1.0f,
                   glm::vec3(1.0f, 1.0f, 1.0f),
                   1.0f, 0.0f
                );
            }
            else
            {
                m_textRenderer->RenderText(
                    std::format("{:02}:{:02}", currentTimeMinutes, currentTimeSeconds),
                    static_cast<float>(m_windowWidth),
                    0,
                    1.0f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    1.0f, 0.0f
                );
            }

            if (m_dead)
            {
                m_textRenderer->RenderText(
                    "Ur Ded\nPress [R] to restart.",
                    static_cast<float>(m_windowWidth) / 2.0f,
                    static_cast<float>(m_windowHeight) / 2.0f,
                    1.0f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    0.5f, 0.5f
                );
            }
            else if (m_won)
            {
                m_textRenderer->RenderText(
                    "U Hath Woneth\nPress [R] to play again.",
                    static_cast<float>(m_windowWidth) / 2.0f,
                    static_cast<float>(m_windowHeight) / 2.0f,
                    1.0f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    0.5f, 0.5f
                );
            }

            m_textRenderer->RenderText(
                "-------CONTROLS--------",
                0.0f,
                static_cast<float>(m_windowHeight),
                0.5f,
                glm::vec3(1.0f, 1.0f, 1.0f),
                0.0f, 1.0f
            );

            m_textRenderer->RenderText(
                "[R]: Restart",
                0.0f,
                static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 1.0f) * 0.5f,
                0.5f,
                glm::vec3(1.0f, 1.0f, 1.0f),
                0.0f, 1.0f
            );

            m_textRenderer->RenderText(
                "[M]: Toggle Music",
                0.0f,
                static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 2.0f) * 0.5f,
                0.5f,
                glm::vec3(1.0f, 1.0f, 1.0f),
                0.0f, 1.0f
            );

            m_textRenderer->RenderText(
                std::format("[T]: Toggle Safe Start\nSafe Start: {}", m_safeStart),
                0.0f,
                static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 4.0f) * 0.5f,
                0.5f,
                glm::vec3(1.0f, 1.0f, 1.0f),
                0.0f, 1.0f
            );

            if (m_sandboxMode)
            {
                m_textRenderer->RenderText(
                    "-----SANDBOX TOOLS-----",
                    0.0f,
                    static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 8.0f) * 0.5f,
                    0.5f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    0.0f, 1.0f
                );
                m_textRenderer->RenderText(
                    "[F1]: Complete Board",
                    0.0f,
                    static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 9.0f) * 0.5f,
                    0.5f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    0.0f, 1.0f
                );
                m_textRenderer->RenderText(
                    "[F2]: Flag Mines",
                    0.0f,
                    static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 10.0f) * 0.5f,
                    0.5f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    0.0f, 1.0f
                );
                m_textRenderer->RenderText(
                    "[F3]: Reset Board",
                    0.0f,
                    static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 11.0f) * 0.5f,
                    0.5f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    0.0f, 1.0f
                );
                m_textRenderer->RenderText(
                    std::format("[]]: Force Tick", m_paused.load()),
                    0.0f,
                    static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 13.0f) * 0.5f,
                    0.5f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    0.0f, 1.0f
                );
                m_textRenderer->RenderText(
                    std::format("[G]: Toggle Godmode\nGodmode: {}", m_godMode.load()),
                    0.0f,
                    static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 15.0f) * 0.5f,
                    0.5f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    0.0f, 1.0f
                );
                m_textRenderer->RenderText(
                    std::format("[P]: Pause\nPaused: {}", m_paused.load()),
                    0.0f,
                    static_cast<float>(m_windowHeight) - m_font->PointToPixelsY(m_font->GetSize() * 17.0f) * 0.5f,
                    0.5f,
                    glm::vec3(1.0f, 1.0f, 1.0f),
                    0.0f, 1.0f
                );
            }

            SDL_GL_SwapWindow(m_window);

            PrecisionDelay(4);
        }
#ifndef NDEBUG
    }
    catch (const std::exception& e)
    {
        std::println(stderr, "Runtime Exception Encountered: {}", e.what());
        m_running = false;
    }
#endif

    SDL_GL_MakeCurrent(m_window, NULL);
}

void Application::GameThread()
{
    auto nextTick = std::chrono::steady_clock::now();
    while (true)
    {
        std::unique_lock lock(m_tileMapMutex);
        bool interrupted = m_tickCondition.wait_until(lock, nextTick, [this]() { return m_forceTick || !m_running; });

        if (!m_running) break;

        auto currentTime = std::chrono::steady_clock::now();
        nextTick = currentTime + std::chrono::milliseconds(22);

        if (m_collapseQueue.size() == 0 || (m_paused && !m_forceTick)) continue;

        m_forceTick = false;

        std::unordered_map<glm::ivec2, Tile*> currentQueue = m_collapseQueue;
        m_collapseQueue.clear();

        for (const auto& delayedCollapse : m_delayedCollapseQueue)
        {
            m_collapseQueue.insert(delayedCollapse);
        }
        m_delayedCollapseQueue.clear();
        while (!currentQueue.empty())
        {
            Tile* tile = currentQueue.begin()->second;
            currentQueue.erase(currentQueue.begin());

            if (tile == nullptr || tile->collapsed) continue;

            tile->collapsed = true;
            if (tile->isBomb)
            {
                tile->textureID = MINESWEEPER_TILE_BOMB;
                KillPlayer();
                continue;
            }
            
            if (tile->flagPlaced)
            {
                tile->flagPlaced = false;
                m_flagsRemaining += 1;
            }
            m_score += 1;
            m_safeTilesCollapsed += 1;
            if (m_safeTilesCollapsed == m_tileMap->tiles.size() - m_tileMap->bombCount)
            {
                PlayerWon();
            }
            if (tile->neighboringBombs > 0 && tile->neighboringBombs <= 8)
            {
                tile->textureID = tile->neighboringBombs;
                continue;
            }
            tile->textureID = MINESWEEPER_TILE_NONE;
            for (int y = -1; y <= 1; ++y)
            {
                for (int x = -1; x <= 1; ++x)
                {
                    if (x == 0 && y == 0) continue;
                    glm::ivec2 gridPosition = tile->position + glm::ivec2(y, x);
                    if (gridPosition.x < 0 || gridPosition.x >= m_tileMap->mapSize.x
                        || gridPosition.y < 0 || gridPosition.y >= m_tileMap->mapSize.y) continue;
                    Tile* neighbor = m_tileMap->GetTile(gridPosition);
                    if (neighbor->collapsed) continue;
                    if ((x == -1 || x == 1) && (y == -1 || y == 1))
                    {
                        m_delayedCollapseQueue[neighbor->position] = neighbor;
                        continue;
                    }
                    m_collapseQueue[neighbor->position] = neighbor;
                }
            }
        }
    }
}

void Application::MainLoop()
{
    SDL_Event event;
    while (m_running)
    {
        m_hoveredTile = GetHoveredTilePosition();

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    m_running = false;
                    break;

                case SDL_EVENT_WINDOW_RESIZED:
                    WindowResized();
                    break;

                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        PushAction<MinesweeperActionClickTile>(m_hoveredTile);
                    }
                    else if (event.button.button == SDL_BUTTON_RIGHT)
                    {
                        PushAction<MinesweeperActionToggleFlag>(m_hoveredTile);
                    }
                    break;

                case SDL_EVENT_KEY_DOWN:
                {
                    switch (event.key.key)
                    {
                        default:
                            if (m_sandboxMode)
                            {
                                switch (event.key.key)
                                {
                                    case SDLK_F1:
                                        PushAction(MinesweeperActionType::AutoCompleteBoard);
                                        break;
                                    case SDLK_F2:
                                        PushAction(MinesweeperActionType::FlagAllMines);
                                        break;
                                    case SDLK_F3:
                                        PushAction(MinesweeperActionType::ResetBoard);
                                        break;
                                    case SDLK_G:
                                        PushAction(MinesweeperActionType::ToggleGodmode);
                                        break;
                                    case SDLK_P:
                                        PushAction(MinesweeperActionType::TogglePaused);
                                        break;
                                    case SDLK_RIGHTBRACKET:
                                        PushAction(MinesweeperActionType::StepForward);
                                        break;
                                }
                            }
                            break;
                        case SDLK_R:
                            PushAction(MinesweeperActionType::Restart);
                            break;
                        case SDLK_M:
                            PushAction(MinesweeperActionType::ToggleMusic);
                            break;
                        case SDLK_T:
                            PushAction(MinesweeperActionType::ToggleSafeClick);
                            break;
                    }
                }
                break;
            }
        }

        {
            while (!m_actionQueue.empty())
            {
                MinesweeperAction action = m_actionQueue.front();
                m_actionQueue.pop();

                switch (action.type)
                {
                    default:
                        break;
                    case MinesweeperActionType::Restart:
                        CreateTileMap();
                        break;
                    case MinesweeperActionType::ClickTile:
                    {
                        std::lock_guard<std::mutex> lock(m_tileMapMutex);
                        if (m_dead || m_won) continue;
                        CollapseTile(action.clickTile.tile);
                    }
                    break;
                    case MinesweeperActionType::ToggleFlag:
                    {
                        std::lock_guard<std::mutex> lock(m_tileMapMutex);
                        if (m_dead || m_won) continue;
                        ToggleFlag(action.toggleFlag.tile);
                    }
                    break;
                    case MinesweeperActionType::FlagAllMines:
                        FlagMines();
                        break;
                    case MinesweeperActionType::ResetBoard:
                        ResetBoard();
                        break;
                    case MinesweeperActionType::AutoCompleteBoard:
                        CompleteBoard();
                        break;
                    case MinesweeperActionType::ToggleGodmode:
                        ToggleGodmode();
                        break;
                    case MinesweeperActionType::ToggleMusic:
                        ToggleMusic();
                        break;
                    case MinesweeperActionType::TogglePaused:
                        TogglePaused();
                        break;
                    case MinesweeperActionType::StepForward:
                        StepForward();
                        break;
                    case MinesweeperActionType::ToggleSafeClick:
                        ToggleSafeClick();
                        break;
                }
            }

            Tile* hoveredTile = m_tileMap->GetTile(m_hoveredTile);
            if (hoveredTile != nullptr)
            {
                hoveredTile->hovered = true;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void Application::LoadIniFile()
{
    MLY_IniFile* iniFile = MLY_IniOpenFile("game.ini", MLY_INI_FILE_FLAGS_READ | MLY_INI_FILE_FLAGS_CREATE_IF_MISSING);

    if (iniFile == nullptr)
    {
        throw std::runtime_error(std::format("Failed to load ini file 'game.ini': {}", MLY_IniError()));
    }

    MLY_IniSection* gameplay = MLY_IniFileGetSection(iniFile, "Gameplay", false);
    if (gameplay != nullptr)
    {
        MLY_IniField* safeStart = MLY_IniSectionGetField(gameplay, "safeStart", false);
        if (safeStart != nullptr) m_safeStart = MLY_IniFieldGetBool(safeStart);
    }

    MLY_IniSection* audio = MLY_IniFileGetSection(iniFile, "Audio", false);
    if (audio != nullptr)
    {
        MLY_IniField* disableMusic = MLY_IniSectionGetField(audio, "disableMusic", false);
        if (disableMusic != nullptr) m_tracker.volume = MLY_IniFieldGetBool(disableMusic) ? 0.0f : 1.0f;
    }

    MLY_IniSection* stats = MLY_IniFileGetSection(iniFile, "Stats", false);
    if (stats != nullptr)
    {
        MLY_IniField* wins = MLY_IniSectionGetField(stats, "wins", false);
        if (wins != nullptr) m_wins = MLY_IniFieldGetInt(wins);
    }

    MLY_IniSection* debug = MLY_IniFileGetSection(iniFile, "Debug", false);
    if (debug != nullptr)
    {
        MLY_IniField* showFPSCounter = MLY_IniSectionGetField(debug, "showFPS", false);
        if (showFPSCounter != nullptr) m_showFPSCounter = MLY_IniFieldGetBool(showFPSCounter);
        MLY_IniField* sandbox = MLY_IniSectionGetField(debug, "sandbox", false);
        if (sandbox != nullptr) m_sandboxMode = MLY_IniFieldGetBool(sandbox);
    }

    MLY_IniCloseFile(iniFile);
}

void Application::SaveSettings()
{
    MLY_IniFile* iniFile = MLY_IniOpenFile("game.ini", MLY_INI_FILE_FLAGS_DEFAULT);

    if (iniFile == nullptr)
    {
        std::println("{}", MLY_IniError());
        return;
    }

    MLY_IniSection* gameplay = MLY_IniFileGetSection(iniFile, "Gameplay", true);
    MLY_IniField* safeStartField = MLY_IniSectionGetField(gameplay, "safeStart", true);
    MLY_IniFieldSetBool(safeStartField, m_safeStart);

    MLY_IniSection* audio = MLY_IniFileGetSection(iniFile, "Audio", true);
    MLY_IniField* disableMusicField = MLY_IniSectionGetField(audio, "disableMusic", true);
    MLY_IniFieldSetBool(disableMusicField, m_tracker.volume == 0.0f);

    MLY_IniSection* stats = MLY_IniFileGetSection(iniFile, "Stats", true);
    MLY_IniField* winsField = MLY_IniSectionGetField(stats, "wins", true);
    MLY_IniFieldSetInt(winsField, m_wins);

    MLY_IniSection* debug = MLY_IniFileGetSection(iniFile, "Debug", true);
    MLY_IniField* showFPSCounterField = MLY_IniSectionGetField(debug, "showFPS", true);
    MLY_IniFieldSetBool(showFPSCounterField, m_showFPSCounter);
    MLY_IniField* lastSeedField = MLY_IniSectionGetField(debug, "lastSeed", true);
    MLY_IniFieldSetInt(lastSeedField, m_tileMap->GetSeed());

    MLY_IniCommitFile(iniFile);
    MLY_IniCloseFile(iniFile);
}

void Application::Cleanup() noexcept
{
    m_tickCondition.notify_one();
    if (m_renderThread.joinable()) m_renderThread.join();
    if (m_gameThread.joinable()) m_gameThread.join();
    if (m_tileVAO != 0) glDeleteVertexArrays(1, &m_tileVAO);
    if (m_tileVBO != 0) glDeleteBuffers(1, &m_tileVBO);
    if (m_tileEBO != 0) glDeleteBuffers(1, &m_tileEBO);
    if (m_audioStream != nullptr) SDL_DestroyAudioStream(m_audioStream);
    if (m_tracker.audioData != nullptr) SDL_free(m_tracker.audioData);
    if (m_context != nullptr) SDL_GL_DestroyContext(m_context);
    if (m_window != nullptr) SDL_DestroyWindow(m_window);
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}
