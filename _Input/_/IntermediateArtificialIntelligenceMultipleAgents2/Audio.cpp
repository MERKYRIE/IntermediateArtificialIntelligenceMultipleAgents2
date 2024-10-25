#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

#include"Audio/Track.hpp"
#include"Audio/Sound.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NAudio
{
    SAudio::SAudio()
    {
        NDebug::GDebug.ISimpleDirectMediaLayerMaskError(Mix_Init(MIX_INIT_MP3));
        NDebug::GDebug.ISimpleDirectMediaLayerCodeError(Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048 , nullptr , 0));
        std::int32_t LFrequency;
        std::uint16_t LFormat;
        std::int32_t LChannels;
        NDebug::GDebug.IError(!Mix_QuerySpec(&LFrequency , &LFormat , &LChannels));
        NDebug::GDebug.IError(LFrequency != MIX_DEFAULT_FREQUENCY || LFormat != MIX_DEFAULT_FORMAT || LChannels != MIX_DEFAULT_CHANNELS);
        NDebug::GDebug.IError(Mix_AllocateChannels(0));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Sounds"})
        {
            if(LEntry.path().extension() == ".wav")
            {
                FSounds.emplace_back(std::make_shared<NSound::SSound>(LEntry.path().generic_string()));
            }
        }
        FSounds.shrink_to_fit();
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Tracks"})
        {
            if(LEntry.path().extension() == ".mp3")
            {
                FTracks.emplace_back(std::make_shared<NTrack::STrack>(LEntry.path().generic_string()));
            }
        }
        FTracks.shrink_to_fit();
    }

    void SAudio::IPreupdate()
    {
    
    }

    std::vector<std::shared_ptr<NTrack::STrack>> const& SAudio::ITracks()
    {
        return(FTracks);
    }

    std::vector<std::shared_ptr<NSound::SSound>> const& SAudio::ISounds()
    {
        return(FSounds);
    }

    void SAudio::ITracks(std::vector<std::shared_ptr<NTrack::STrack>> const& AValue)
    {
        FTracks = AValue;
    }

    void SAudio::ISounds(std::vector<std::shared_ptr<NSound::SSound>> const& AValue)
    {
        FSounds = AValue;
    }

    NTrack::STrack* SAudio::IAccessTrack(const std::string& APath)
    {
        std::vector<std::shared_ptr<NTrack::STrack>>::iterator LIterator
        {
            std::find_if(FTracks.begin() , FTracks.end() , [&](std::shared_ptr<NTrack::STrack>& LTrack){return(LTrack->IIs(APath));})
        };
        return(LIterator->get());
    }

    NSound::SSound* SAudio::IAccessSound(const std::string& APath)
    {
        std::vector<std::shared_ptr<NSound::SSound>>::iterator LIterator
        {
            std::find_if(FSounds.begin() , FSounds.end() , [&](std::shared_ptr<NSound::SSound>& LSound){return(LSound->IIs(APath));})
        };
        return(LIterator->get());
    }

    void SAudio::IPostupdate()
    {
    
    }

    SAudio::~SAudio()
    {
        FTracks.clear();
        FSounds.clear();
        Mix_CloseAudio();
        Mix_Quit();
    }
}