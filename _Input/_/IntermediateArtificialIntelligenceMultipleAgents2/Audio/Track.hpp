#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NAudio::NTrack
{
    struct STrack
    {
        std::string FPath;
        Mix_Music* FHandle;

        STrack(const std::string& APath);
        std::string const& IPath();
        Mix_Music* const& IHandle();
        STrack* IPath(std::string const& AValue);
        STrack* IHandle(Mix_Music* const& AValue);
        bool IIs(const std::string& APath);
        STrack* IPlay();
        STrack* IPause();
        STrack* IResume();
        STrack* IStop();
        STrack* IAccessVolume(std::uint8_t AValue);
        ~STrack();
    };
}