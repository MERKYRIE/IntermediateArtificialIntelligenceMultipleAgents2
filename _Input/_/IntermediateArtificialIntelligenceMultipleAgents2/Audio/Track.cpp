#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

#include"Track.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NAudio::NTrack
{
    STrack::STrack(const std::string& APath)
    {
        FPath = APath.substr(APath.find('/'));
        NDebug::GDebug.ISimpleDirectMediaLayerHandleError(FHandle = Mix_LoadMUS(APath.c_str()));
    }

    std::string const& STrack::IPath()
    {
        return(FPath);
    }

    Mix_Music* const& STrack::IHandle()
    {
        return(FHandle);
    }

    STrack* STrack::IPath(std::string const& AValue)
    {
        FPath = AValue;
        return(this);
    }

    STrack* STrack::IHandle(Mix_Music* const& AValue)
    {
        FHandle = AValue;
        return(this);
    }

    bool STrack::IIs(const std::string& APath)
    {
        return(FPath == APath);
    }

    STrack* STrack::IPlay()
    {
        NDebug::GDebug.ISimpleDirectMediaLayerCodeError(Mix_PlayMusic(FHandle , 0));
        return(this);
    }

    STrack* STrack::IPause()
    {
        Mix_PauseMusic();
        return(this);
    }

    STrack* STrack::IResume()
    {
        Mix_ResumeMusic();
        return(this);
    }

    STrack* STrack::IStop()
    {
        Mix_HaltMusic();
        return(this);
    }

    STrack* STrack::IAccessVolume(std::uint8_t AValue)
    {
        Mix_VolumeMusic(AValue);
        NDebug::GDebug.IError(Mix_VolumeMusic(SDL_QUERY) != AValue);
        return(this);
    }

    STrack::~STrack()
    {
        Mix_FreeMusic(FHandle);
    }
}