#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NMouse::NButton
{
    struct SButton
    {
        std::unordered_map<std::string , bool> FStates;

        SButton();

        SButton* IPreupdate();

        std::unordered_map<std::string , bool> const& IStates();

        SButton* IStates(std::unordered_map<std::string , bool> const& AValue);

        SButton* IPostupdate(SDL_Event const& AEvent);

        ~SButton();
    };
}