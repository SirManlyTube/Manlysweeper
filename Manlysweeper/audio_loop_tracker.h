#pragma once

struct AudioLoopTracker
{
    unsigned char* audioData;
    unsigned int length;
    unsigned int playPosition;
    float volume;
};
