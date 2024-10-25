#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NAudio
{
    namespace NTrack
    {
        struct STrack;
    }

    namespace NSound
    {
        struct SSound;
    }
    
    inline struct SAudio
    {
        std::vector<std::shared_ptr<NTrack::STrack>> FTracks;
        std::vector<std::shared_ptr<NSound::SSound>> FSounds;

        SAudio();
        void IPreupdate();
        std::vector<std::shared_ptr<NTrack::STrack>> const& ITracks();
        std::vector<std::shared_ptr<NSound::SSound>> const& ISounds();
        void ITracks(std::vector<std::shared_ptr<NTrack::STrack>> const& AValue);
        void ISounds(std::vector<std::shared_ptr<NSound::SSound>> const& AValue);
        NTrack::STrack* IAccessTrack(const std::string& APath);
        NSound::SSound* IAccessSound(const std::string& APath);
        void IPostupdate();
        ~SAudio();
    }
    GAudio;
}