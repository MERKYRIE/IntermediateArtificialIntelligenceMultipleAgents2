#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

#include"Sound.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NAudio::NSound
{
    SSound::SSound(const std::string& APath)
    {
        FPath = APath.substr(APath.find('/'));
        NDebug::GDebug.ISimpleDirectMediaLayerHandleError(FHandle = Mix_LoadWAV(APath.c_str()));
        FChannel = Mix_AllocateChannels(SDL_QUERY);
        NDebug::GDebug.IError(Mix_AllocateChannels(Mix_AllocateChannels(SDL_QUERY) + 1) != FChannel + 1);
    }

    std::string const& SSound::IPath()
    {
        return(FPath);
    }

    Mix_Chunk* const& SSound::IHandle()
    {
        return(FHandle);
    }

    std::int32_t const& SSound::IChannel()
    {
        return(FChannel);
    }

    SSound* SSound::IPath(std::string const& AValue)
    {
        FPath = AValue;
        return(this);
    }

    SSound* SSound::IHandle(Mix_Chunk* const& AValue)
    {
        FHandle = AValue;
        return(this);
    }

    SSound* SSound::IChannel(std::int32_t const& AValue)
    {
        FChannel = AValue;
        return(this);
    }

    bool SSound::IIs(const std::string& APath)
    {
        return(FPath == APath);
    }

    SSound* SSound::IPlay()
    {
        NDebug::GDebug.ISimpleDirectMediaLayerCodeError(Mix_PlayChannel(FChannel , FHandle , 0) != FChannel);
        return(this);
    }

    bool SSound::IIsPlaying()
    {
        return(Mix_Playing(FChannel));
    }

    SSound::~SSound()
    {
        Mix_FreeChunk(FHandle);
    }
}