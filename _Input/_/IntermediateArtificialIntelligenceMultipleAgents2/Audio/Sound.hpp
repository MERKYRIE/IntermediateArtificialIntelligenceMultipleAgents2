#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NAudio::NSound
{
    struct SSound
    {
        std::string FPath;
        Mix_Chunk* FHandle;
        std::int32_t FChannel;

        SSound(const std::string& APath);
        std::string const& IPath();
        Mix_Chunk* const& IHandle();
        std::int32_t const& IChannel();
        SSound* IPath(std::string const& AValue);
        SSound* IHandle(Mix_Chunk* const& AValue);
        SSound* IChannel(std::int32_t const& AValue);
        bool IIs(const std::string& APath);
        SSound* IPlay();
        bool IIsPlaying();
        ~SSound();
    };
}