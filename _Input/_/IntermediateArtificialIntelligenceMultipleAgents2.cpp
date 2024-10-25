#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2main")
#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2")
#pragma comment(lib , "../SimpleDirectMediaLayer/Image/SDL2_image")
#pragma comment(lib , "../SimpleDirectMediaLayer/Mixer/SDL2_mixer")
#pragma comment(lib , "../SimpleDirectMediaLayer/TrueTypeFont/SDL2_ttf")

#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2
{
    SIntermediateArtificialIntelligenceMultipleAgents2::SIntermediateArtificialIntelligenceMultipleAgents2()
    {
        NDebug::GDebug.ISimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    }

    void SIntermediateArtificialIntelligenceMultipleAgents2::IUpdate()
    {
        while(!NKeyboard::GKeyboard.IIsKeyHeld(SDL_SCANCODE_ESCAPE))
        {
            NAudio::GAudio.IPreupdate();
            NDebug::GDebug.IPreupdate();
            NKeyboard::GKeyboard.IPreupdate();
            NMouse::GMouse.IPreupdate();
            SDL_Event LEvent;
            while(SDL_PollEvent(&LEvent))
            {
                switch(LEvent.type)
                {
                    case(SDL_KEYDOWN):
                        NKeyboard::GKeyboard.IPostupdate(LEvent);
                    break;
                    case(SDL_KEYUP):
                        NKeyboard::GKeyboard.IPostupdate(LEvent);
                    break;
                    case(SDL_MOUSEBUTTONDOWN):
                        NMouse::GMouse.IPostupdate(LEvent);
                    break;
                    case(SDL_MOUSEBUTTONUP):
                        NMouse::GMouse.IPostupdate(LEvent);
                    break;
                    case(SDL_MOUSEMOTION):
                        NMouse::GMouse.IPostupdate(LEvent);
                    break;
                    case(SDL_MOUSEWHEEL):
                        NMouse::GMouse.IPostupdate(LEvent);
                    break;
                }
            }
            NTime::GTime.IPreupdate();
            NVideo::GVideo.IPreupdate();
            NInterface::GInterface.IPreupdate();
            NSpace::GSpace.IPreupdate();
            NSpace::GSpace.IPostupdate();
            NInterface::GInterface.IPostupdate();
            NVideo::GVideo.IPostupdate();
            NTime::GTime.IPostupdate();
            NDebug::GDebug.IPostupdate();
            NAudio::GAudio.IPostupdate();
        };
    }

    SIntermediateArtificialIntelligenceMultipleAgents2::~SIntermediateArtificialIntelligenceMultipleAgents2()
    {
        SDL_Quit();
    }
}

std::int32_t main(std::int32_t , char**)
{
    NIntermediateArtificialIntelligenceMultipleAgents2::GIntermediateArtificialIntelligenceMultipleAgents2.IUpdate();
    return(0);
}