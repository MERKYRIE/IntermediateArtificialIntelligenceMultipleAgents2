#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

#include"Button.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NMouse::NButton
{
    SButton::SButton()
    {
        FStates["Pressed"] = false;
        FStates["Held"] = false;
        FStates["Released"] = false;
    }

    SButton* SButton::IPreupdate()
    {
        FStates["Pressed"] = false;
        FStates["Released"] = false;
        return(this);
    }

    std::unordered_map<std::string , bool> const& SButton::IStates()
    {
        return(FStates);
    }

    SButton* SButton::IStates(std::unordered_map<std::string , bool> const& AValue)
    {
        FStates = AValue;
        return(this);
    }

    SButton* SButton::IPostupdate(SDL_Event const& AEvent)
    {
        switch(AEvent.type)
        {
            case(SDL_MOUSEBUTTONDOWN):
                FStates["Pressed"] = true;
                FStates["Held"] = true;
                FStates["Released"] = false;
            break;
            case(SDL_MOUSEBUTTONUP):
                FStates["Pressed"] = false;
                FStates["Held"] = false;
                FStates["Released"] = true;
            break;
        }
        return(this);
    }

    SButton::~SButton()
    {
    
    }
}