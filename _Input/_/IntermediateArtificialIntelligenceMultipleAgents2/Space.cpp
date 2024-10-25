#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

#include"Mouse/Button.hpp"
#include"Video/Font.hpp"
#include"Video/Image.hpp"
#include"Video/Sprite.hpp"

#include"Space/Entity.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NSpace
{
    SSpace::SSpace()
    {
        FX = 0.0;
        FY = 0.0;
        FSpeedX = 0.0025;
        FSpeedY = 0.0025;
        FIterationX = 0;
        FIterationY = 0;
        FWidth = 10;
        FHeight = 10;
        FScaleX = 0.05;
        FScaleY = 0.05;
        FScaleLastX = FScaleX;
        FScaleLastY = FScaleY;
        FScaleXMinimum = 0.05;
        FScaleXMaximum = 0.2;
        FScaleYMinimum = 0.05;
        FScaleYMaximum = 0.2;
        FScalingX = 2.0;
        FScalingY = 2.0;
        FMatrix.resize(FWidth);
        for(FIterationX = 0 ; FIterationX < FWidth ; FIterationX++)
        {
            FMatrix[FIterationX].resize(FHeight);
            for(FIterationY = 0 ; FIterationY < FHeight ; FIterationY++)
            {
                FMatrix[FIterationX][FIterationY].FGround = std::make_shared<NVideo::NSprite::SSprite>();
                FMatrix[FIterationX][FIterationY].FGround->ILoad(NVideo::GVideo.IAccessFont("/Consolas.ttf")->IAccessString("Ground"));
            }
            FMatrix[FIterationX].shrink_to_fit();
        }
        FMatrix.shrink_to_fit();
        FMatrix[0][0].FEntity = std::make_shared<NEntity::SEntity>(0 , 0);
        FMatrix[1][1].FEntity = std::make_shared<NEntity::SEntity>(1 , 1);
        FMatrix[2][2].FEntity = std::make_shared<NEntity::SEntity>(2 , 2);
        FMatrix[8][9].FEntity = std::make_shared<NEntity::SEntity>(8 , 9);
        FMatrix[8][8].FEntity = std::make_shared<NEntity::SEntity>(8 , 8);
        FMatrix[9][8].FEntity = std::make_shared<NEntity::SEntity>(9 , 8);
    }

    void SSpace::IPreupdate()
    {
        FScaleLastX = FScaleX;
        FScaleLastY = FScaleY;
        FScaleX = std::clamp(FScaleX * std::pow(FScalingX , NMouse::GMouse.IWheelState()) , FScaleXMinimum , FScaleXMaximum);
        FScaleY = std::clamp(FScaleY * std::pow(FScalingY , NMouse::GMouse.IWheelState()) , FScaleYMinimum , FScaleYMaximum);
        FX -= FSpeedX * NMouse::GMouse.IXsHeldRelative()[SDL_BUTTON_MIDDLE] / FScaleLastX - (FScaleLastX != FScaleX) * NMouse::GMouse.IWheelState() * NMouse::GMouse.IAbsoluteXSquare() / std::max(FScaleLastX , FScaleX);
        FY -= FSpeedY * NMouse::GMouse.IYsHeldRelative()[SDL_BUTTON_MIDDLE] / FScaleLastY - (FScaleLastY != FScaleY) * NMouse::GMouse.IWheelState() * NMouse::GMouse.IAbsoluteYSquare() / std::max(FScaleLastY , FScaleY);
        if(NMouse::GMouse.IButtons().at("Left")->IStates().at("Released"))
        {
            FSelection.clear();
            double LRealMonitorPressedX{NMouse::GMouse.IXsPressedAbsoluteSquare()[SDL_BUTTON_LEFT]};
            double LRealMonitorPressedY{NMouse::GMouse.IYsPressedAbsoluteSquare()[SDL_BUTTON_LEFT]};
            double LRealMonitorReleasedX{NMouse::GMouse.IXsReleasedAbsoluteSquare()[SDL_BUTTON_LEFT]};
            double LRealMonitorReleasedY{NMouse::GMouse.IYsReleasedAbsoluteSquare()[SDL_BUTTON_LEFT]};
            double LRealMonitorMinimalX{std::min(LRealMonitorPressedX , LRealMonitorReleasedX)};
            double LRealMonitorMinimalY{std::min(LRealMonitorPressedY , LRealMonitorReleasedY)};
            double LRealMonitorMaximalX{std::max(LRealMonitorPressedX , LRealMonitorReleasedX)};
            double LRealMonitorMaximalY{std::max(LRealMonitorPressedY , LRealMonitorReleasedY)};
            double LRealTileMinimalX{LRealMonitorMinimalX / FScaleX};
            double LRealTileMinimalY{LRealMonitorMinimalY / FScaleY};
            double LRealTileMaximalX{LRealMonitorMaximalX / FScaleX};
            double LRealTileMaximalY{LRealMonitorMaximalY / FScaleY};
            double LRealSpaceMinimalX{LRealTileMinimalX + FX};
            double LRealSpaceMinimalY{LRealTileMinimalY + FY};
            double LRealSpaceMaximalX{LRealTileMaximalX + FX};
            double LRealSpaceMaximalY{LRealTileMaximalY + FY};
            double LRealFlooredSpaceMinimalX{std::floor(LRealSpaceMinimalX)};
            double LRealFlooredSpaceMinimalY{std::floor(LRealSpaceMinimalY)};
            double LRealCeiledSpaceMaximalX{std::ceil(LRealSpaceMaximalX)};
            double LRealCeiledSpaceMaximalY{std::ceil(LRealSpaceMaximalY)};
            std::int64_t LIntegralFlooredSpaceMinimalX{static_cast<std::int64_t>(LRealFlooredSpaceMinimalX)};
            std::int64_t LIntegralFlooredSpaceMinimalY{static_cast<std::int64_t>(LRealFlooredSpaceMinimalY)};
            std::int64_t LIntegralCeiledSpaceMaximalX{static_cast<std::int64_t>(LRealCeiledSpaceMaximalX)};
            std::int64_t LIntegralCeiledSpaceMaximalY{static_cast<std::int64_t>(LRealCeiledSpaceMaximalY)};
            std::int64_t LIntegralClampedFlooredSpaceMinimalX{std::clamp<std::int64_t>(LIntegralFlooredSpaceMinimalX , 0 , FWidth)};
            std::int64_t LIntegralClampedFlooredSpaceMinimalY{std::clamp<std::int64_t>(LIntegralFlooredSpaceMinimalY , 0 , FHeight)};
            std::int64_t LIntegralClampedCeiledSpaceMaximalX{std::clamp<std::int64_t>(LIntegralCeiledSpaceMaximalX , 0 , FWidth)};
            std::int64_t LIntegralClampedCeiledSpaceMaximalY{std::clamp<std::int64_t>(LIntegralCeiledSpaceMaximalY , 0 , FHeight)};
            for(FIterationX = LIntegralClampedFlooredSpaceMinimalX ; FIterationX < LIntegralClampedCeiledSpaceMaximalX ; FIterationX++)
            {
                for(FIterationY = LIntegralClampedFlooredSpaceMinimalY ; FIterationY < LIntegralClampedCeiledSpaceMaximalY ; FIterationY++)
                {
                    if(FMatrix[FIterationX][FIterationY].FEntity)
                    {
                        FSelection.push_back(FMatrix[FIterationX][FIterationY].FEntity.get());
                    }
                }
            }
        }
        if(NMouse::GMouse.IButtons().at("Right")->IStates().at("Pressed") && !FSelection.empty())
        {
            double LRealMonitorX{NMouse::GMouse.IAbsoluteXSquare()};
            double LRealMonitorY{NMouse::GMouse.IAbsoluteYSquare()};
            double LRealTileX{LRealMonitorX / FScaleX};
            double LRealTileY{LRealMonitorY / FScaleY};
            double LRealSpaceX{LRealTileX + FX};
            double LRealSpaceY{LRealTileY + FY};
            std::int64_t LIntegralSpaceX{static_cast<std::int64_t>(LRealSpaceX)};
            std::int64_t LIntegralSpaceY{static_cast<std::int64_t>(LRealSpaceY)};
            std::int64_t LIntegralClampedSpaceX{std::clamp<std::int64_t>(LIntegralSpaceX , 0 , FWidth - 1)};
            std::int64_t LIntegralClampedSpaceY{std::clamp<std::int64_t>(LIntegralSpaceY , 0 , FHeight - 1)};
            if(LIntegralSpaceX == LIntegralClampedSpaceX && LIntegralSpaceY == LIntegralClampedSpaceY)
            {
                struct SPartition
                {
                    std::int64_t FX;
                    std::int64_t FY;
                };
                std::vector<std::vector<std::int64_t>> LDistances;
                std::vector<SPartition> LPartitions;
                std::vector<std::vector<SPartition>> LPaths;
                LDistances.resize(GSpace.FWidth);
                LPaths.resize(GSpace.FWidth);
                for(std::int64_t LX{0} ; LX < GSpace.FWidth ; LX++)
                {
                    LDistances[LX].resize(GSpace.FHeight);
                    LPaths[LX].resize(GSpace.FHeight);
                    for(std::int64_t LY{0} ; LY < GSpace.FHeight ; LY++)
                    {
                        LDistances[LX][LY] = std::numeric_limits<std::int64_t>::max();
                        LPaths[LX][LY] = {-1 , -1};
                        if(!GSpace.FMatrix[LX][LY].FEntity || std::ranges::any_of(FSelection , [&](NEntity::SEntity *const& PEntity)->bool{return(GSpace.FMatrix[LX][LY].FEntity.get() == PEntity);}))
                        {
                            LPartitions.push_back({LX , LY});
                        }
                    }
                    LPaths[LX].shrink_to_fit();
                    LDistances[LX].shrink_to_fit();
                }
                LPaths.shrink_to_fit();
                LDistances.shrink_to_fit();
                LDistances[FSelection[0]->FX][FSelection[0]->FY] = 0;
                while(!LPartitions.empty())
                {
                    auto LClosest{std::ranges::min_element(LPartitions , [&](SPartition const& PA , SPartition const& PB)->bool{return(LDistances[PA.FX][PA.FY] < LDistances[PB.FX][PB.FY]);})};
                    SPartition LPartition{*LClosest};
                    LPartitions.erase(LClosest);
                    for(auto LIterator{LPartitions.begin()} ; LIterator != LPartitions.end() ; LIterator++)
                    {
                        if(std::abs(LPartition.FX - LIterator->FX) <= 1 && std::abs(LPartition.FY - LIterator->FY) <= 1)
                        {
                            std::int64_t LPath{LDistances[LPartition.FX][LPartition.FY] + 1};
                            if(LPath < LDistances[LIterator->FX][LIterator->FY])
                            {
                                LDistances[LIterator->FX][LIterator->FY] = LPath;
                                LPaths[LIterator->FX][LIterator->FY] = LPartition;
                            }
                        }
                    }
                }
                if(LPaths[LIntegralClampedSpaceX][LIntegralClampedSpaceY].FX != -1 && LPaths[LIntegralClampedSpaceX][LIntegralClampedSpaceY].FY != -1)
                {
                    SPartition LPartition{LIntegralClampedSpaceX , LIntegralClampedSpaceY};
                    for(std::int64_t LSelection{0} ; LSelection < std::ssize(FSelection) ; LSelection++)
                    {
                        if(LPartition.FX == FSelection[0]->FX && LPartition.FY == FSelection[0]->FY)
                        {
                            break;
                        }
                        FSelection[LSelection]->IMove(LPartition.FX , LPartition.FY);
                        LPartition = LPaths[LPartition.FX][LPartition.FY];
                    }
                }
            }
        }
        for(FIterationX = 0 ; FIterationX < FWidth ; FIterationX++)
        {
            for(FIterationY = 0 ; FIterationY < FHeight ; FIterationY++)
            {
                FMatrix[FIterationX][FIterationY].FGround
                ->IAccessDestinationXSquareAbsolute(FScaleX * (-FX + FIterationX))->IAccessDestinationYSquareAbsolute(FScaleY * (-FY + FIterationY))
                ->IAccessDestinationWidthSquareAbsolute(FScaleX)->IAccessDestinationHeightSquareAbsolute(FScaleY)
                ->IDraw();
                if(FMatrix[FIterationX][FIterationY].FEntity)
                {
                    FMatrix[FIterationX][FIterationY].FEntity->IUpdate();
                }
            }
        }
        for(std::int64_t LSelection{0} ; LSelection < std::ssize(FSelection) ; LSelection++)
        {
            FSelection[LSelection]->ISelect();
        }
        if(NMouse::GMouse.IButtons().at("Left")->IStates().at("Held"))
        {
            SDL_Rect LSelection{NMouse::GMouse.IXsPressedAbsolute()[SDL_BUTTON_LEFT] , NMouse::GMouse.IYsPressedAbsolute()[SDL_BUTTON_LEFT] , NMouse::GMouse.IAbsoluteX() - NMouse::GMouse.IXsPressedAbsolute()[SDL_BUTTON_LEFT] , NMouse::GMouse.IAbsoluteY() - NMouse::GMouse.IYsPressedAbsolute()[SDL_BUTTON_LEFT]};
            SDL_SetRenderDrawColor(NVideo::GVideo.IRenderer() , 0 , 100 , 100 , SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(NVideo::GVideo.IRenderer() , &LSelection);
        }
    }

    void SSpace::IPostupdate()
    {
    
    }

    SSpace::~SSpace()
    {
    
    }
}