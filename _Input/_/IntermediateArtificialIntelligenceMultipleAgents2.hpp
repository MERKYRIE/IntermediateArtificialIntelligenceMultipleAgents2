#pragma once

#include<array>
#include<filesystem>
#include<fstream>
#include<iostream>
#include<numbers>
#include<map>
#include<random>
#include<source_location>
#include<set>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<variant>
#include<vector>

#pragma warning(push)
    #pragma warning(disable : 26819)

    #include"../SimpleDirectMediaLayer/SDL.h"
    #include"../SimpleDirectMediaLayer/Image/SDL_image.h"
    #include"../SimpleDirectMediaLayer/Mixer/SDL_mixer.h"
    #include"../SimpleDirectMediaLayer/TrueTypeFont/SDL_ttf.h"
#pragma warning(pop)

#pragma warning(disable : 26495)

namespace NIntermediateArtificialIntelligenceMultipleAgents2
{
    inline struct SIntermediateArtificialIntelligenceMultipleAgents2
    {
        SIntermediateArtificialIntelligenceMultipleAgents2();
        void IUpdate();
        ~SIntermediateArtificialIntelligenceMultipleAgents2();
    }
    GIntermediateArtificialIntelligenceMultipleAgents2;
}

#include"IntermediateArtificialIntelligenceMultipleAgents2/Audio.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents2/Debug.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents2/Keyboard.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents2/Mouse.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents2/Time.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents2/Video.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents2/Space.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents2/Interface.hpp"