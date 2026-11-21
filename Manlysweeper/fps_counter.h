#pragma once

#include <vector>

class FPSCounter
{
public:
    FPSCounter(size_t maximumFrameCount) : m_maximumFrameCount(maximumFrameCount), m_frameCounter(0)
    {
        m_frameCounts.resize(maximumFrameCount);
    }

    inline void Push(unsigned int frameCount)
    {
        m_frameCounter = (m_frameCounter + 1) % m_maximumFrameCount;
        m_frameCounts[m_frameCounter] = frameCount;
    }

    inline void Clear()
    {
        m_frameCounts.clear();
    }

    constexpr inline unsigned int GetAverage() const
    {
        unsigned int totalCount = 0;
        for (int frameCount : m_frameCounts)
        {
            totalCount += frameCount;
        }
        return static_cast<unsigned int>(totalCount / m_maximumFrameCount);
    }

private:
    std::vector<unsigned int> m_frameCounts;
    size_t m_frameCounter;
    size_t m_maximumFrameCount;

};
