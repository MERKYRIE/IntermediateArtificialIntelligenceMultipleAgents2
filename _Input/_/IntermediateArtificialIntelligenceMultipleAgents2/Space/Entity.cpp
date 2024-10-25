#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

#include"IntermediateArtificialIntelligenceMultipleAgents2/Video/Font.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents2/Video/Sprite.hpp"

#include"Entity.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NSpace::NEntity
{
    SEntity::SEntity(std::int64_t const& LX , std::int64_t const& LY)
    {
        FSprite = std::make_shared<NVideo::NSprite::SSprite>();
        FSprite->ILoad(NVideo::GVideo.IAccessFont("/Consolas.ttf")->IAccessString("Entity"));
        FX = LX;
        FY = LY;
        FMoving = false;
        FMovementX = 0;
        FMovementY = 0;
        FTimer = 0;
    }

    SEntity* SEntity::IUpdate()
    {
        if(FMoving)
        {
            FTimer += NTime::GTime.ITimepointRelative();
            if(FTimer >= 500)
            {
                FTimer = 0;
                struct SPartition
                {
                    std::int64_t FX;
                    std::int64_t FY;
                };
                std::vector<SPartition> LPartitions;
                std::vector<std::vector<SPartition>> LPaths;
                std::vector<std::vector<std::int64_t>> LDistances;
                std::vector<std::vector<std::int64_t>> LScores;
                LPartitions.push_back({FX , FY});
                LPaths.resize(GSpace.FWidth);
                LDistances.resize(GSpace.FWidth);
                LScores.resize(GSpace.FWidth);
                for(std::int64_t LX{0} ; LX < GSpace.FWidth ; LX++)
                {
                    LPaths[LX].resize(GSpace.FHeight);
                    LDistances[LX].resize(GSpace.FHeight);
                    LScores[LX].resize(GSpace.FHeight);
                    for(std::int64_t LY{0} ; LY < GSpace.FHeight ; LY++)
                    {
                        LPaths[LX][LY] = {-1 , -1};
                        LDistances[LX][LY] = std::numeric_limits<std::int64_t>::max();
                        LScores[LX][LY] = std::numeric_limits<std::int64_t>::max();
                    }
                    LScores[LX].shrink_to_fit();
                    LDistances[LX].shrink_to_fit();
                    LPaths[LX].shrink_to_fit();
                }
                LScores.shrink_to_fit();
                LDistances.shrink_to_fit();
                LPaths.shrink_to_fit();
                LDistances[FX][FY] = 0;
                LScores[FX][FY] = std::max(std::abs(FX - FMovementX) , std::abs(FY - FMovementY));
                while(!LPartitions.empty())
                {
                    auto LClosest{std::ranges::min_element(LPartitions , [&](SPartition const& PA , SPartition const& PB)->bool{return(LScores[PA.FX][PA.FY] < LScores[PB.FX][PB.FY]);})};
                    if(LClosest->FX == FMovementX && LClosest->FY == FMovementY)
                    {
                        break;
                    }
                    SPartition LPartition{*LClosest};
                    LPartitions.erase(LClosest);
                    if(LPartition.FX - 1 == std::clamp<std::intmax_t>(LPartition.FX - 1 , 0 , GSpace.FWidth - 1) && (!GSpace.FMatrix[LPartition.FX - 1][LPartition.FY].FEntity || GSpace.FMatrix[LPartition.FX - 1][LPartition.FY].FEntity.get() == this))
                    {
                        std::int64_t LPath{LDistances[LPartition.FX][LPartition.FY] + 1};
                        if(LPath < LDistances[LPartition.FX - 1][LPartition.FY])
                        {
                            LPaths[LPartition.FX - 1][LPartition.FY] = LPartition;
                            LDistances[LPartition.FX - 1][LPartition.FY] = LPath;
                            LScores[LPartition.FX - 1][LPartition.FY] = LPath + std::max(std::abs(LPartition.FX - 1 - FMovementX) , std::abs(LPartition.FY - FMovementY));
                            if(std::ranges::find_if(LPartitions , [&](SPartition const& PPartition)->bool{return(LPartition.FX - 1 == PPartition.FX && LPartition.FY == PPartition.FY);}) == LPartitions.end())
                            {
                                LPartitions.push_back({LPartition.FX - 1 , LPartition.FY});
                            }
                        }
                    }
                    if(LPartition.FX + 1 == std::clamp<std::intmax_t>(LPartition.FX + 1 , 0 , GSpace.FWidth - 1) && (!GSpace.FMatrix[LPartition.FX + 1][LPartition.FY].FEntity || GSpace.FMatrix[LPartition.FX + 1][LPartition.FY].FEntity.get() == this))
                    {
                        std::int64_t LPath{LDistances[LPartition.FX][LPartition.FY] + 1};
                        if(LPath < LDistances[LPartition.FX + 1][LPartition.FY])
                        {
                            LPaths[LPartition.FX + 1][LPartition.FY] = LPartition;
                            LDistances[LPartition.FX + 1][LPartition.FY] = LPath;
                            LScores[LPartition.FX + 1][LPartition.FY] = LPath + std::max(std::abs(LPartition.FX + 1 - FMovementX) , std::abs(LPartition.FY - FMovementY));
                            if(std::ranges::find_if(LPartitions , [&](SPartition const& PPartition)->bool{return(LPartition.FX + 1 == PPartition.FX && LPartition.FY == PPartition.FY);}) == LPartitions.end())
                            {
                                LPartitions.push_back({LPartition.FX + 1 , LPartition.FY});
                            }
                        }
                    }
                    if(LPartition.FY - 1 == std::clamp<std::intmax_t>(LPartition.FY - 1 , 0 , GSpace.FHeight - 1) && (!GSpace.FMatrix[LPartition.FX][LPartition.FY - 1].FEntity || GSpace.FMatrix[LPartition.FX][LPartition.FY - 1].FEntity.get() == this))
                    {
                        std::int64_t LPath{LDistances[LPartition.FX][LPartition.FY ] + 1};
                        if(LPath < LDistances[LPartition.FX][LPartition.FY - 1])
                        {
                            LPaths[LPartition.FX][LPartition.FY - 1] = LPartition;
                            LDistances[LPartition.FX][LPartition.FY - 1] = LPath;
                            LScores[LPartition.FX][LPartition.FY - 1] = LPath + std::max(std::abs(LPartition.FX - FMovementX) , std::abs(LPartition.FY - 1 - FMovementY));
                            if(std::ranges::find_if(LPartitions , [&](SPartition const& PPartition)->bool{return(LPartition.FX == PPartition.FX && LPartition.FY - 1 == PPartition.FY);}) == LPartitions.end())
                            {
                                LPartitions.push_back({LPartition.FX , LPartition.FY - 1});
                            }
                        }
                    }
                    if(LPartition.FY + 1 == std::clamp<std::intmax_t>(LPartition.FY + 1 , 0 , GSpace.FHeight - 1) && (!GSpace.FMatrix[LPartition.FX][LPartition.FY + 1].FEntity || GSpace.FMatrix[LPartition.FX][LPartition.FY + 1].FEntity.get() == this))
                    {
                        std::int64_t LPath{LDistances[LPartition.FX][LPartition.FY] + 1};
                        if(LPath < LDistances[LPartition.FX][LPartition.FY + 1])
                        {
                            LPaths[LPartition.FX][LPartition.FY + 1] = LPartition;
                            LDistances[LPartition.FX][LPartition.FY + 1] = LPath;
                            LScores[LPartition.FX][LPartition.FY + 1] = LPath + std::max(std::abs(LPartition.FX - FMovementX) , std::abs(LPartition.FY + 1 - FMovementY));
                            if(std::ranges::find_if(LPartitions , [&](SPartition const& PPartition)->bool{return(LPartition.FX == PPartition.FX && LPartition.FY + 1 == PPartition.FY);}) == LPartitions.end())
                            {
                                LPartitions.push_back({LPartition.FX , LPartition.FY + 1});
                            }
                        }
                    }
                    if(LPartition.FX - 1 == std::clamp<std::intmax_t>(LPartition.FX - 1 , 0 , GSpace.FWidth - 1) && LPartition.FY - 1 == std::clamp<std::intmax_t>(LPartition.FY - 1 , 0 , GSpace.FHeight - 1) && (!GSpace.FMatrix[LPartition.FX - 1][LPartition.FY - 1].FEntity || GSpace.FMatrix[LPartition.FX - 1][LPartition.FY - 1].FEntity.get() == this))
                    {
                        std::int64_t LPath{LDistances[LPartition.FX][LPartition.FY] + 1};
                        if(LPath < LDistances[LPartition.FX - 1][LPartition.FY - 1])
                        {
                            LPaths[LPartition.FX - 1][LPartition.FY - 1] = LPartition;
                            LDistances[LPartition.FX - 1][LPartition.FY - 1] = LPath;
                            LScores[LPartition.FX - 1][LPartition.FY - 1] = LPath + std::max(std::abs(LPartition.FX - 1 - FMovementX) , std::abs(LPartition.FY - 1 - FMovementY));
                            if(std::ranges::find_if(LPartitions , [&](SPartition const& PPartition)->bool{return(LPartition.FX - 1 == PPartition.FX && LPartition.FY - 1 == PPartition.FY);}) == LPartitions.end())
                            {
                                LPartitions.push_back({LPartition.FX - 1 , LPartition.FY - 1});
                            }
                        }
                    }
                    if(LPartition.FX + 1 == std::clamp<std::intmax_t>(LPartition.FX + 1 , 0 , GSpace.FWidth - 1) && LPartition.FY + 1 == std::clamp<std::intmax_t>(LPartition.FY + 1 , 0 , GSpace.FHeight - 1) && (!GSpace.FMatrix[LPartition.FX + 1][LPartition.FY + 1].FEntity || GSpace.FMatrix[LPartition.FX + 1][LPartition.FY + 1].FEntity.get() == this))
                    {
                        std::int64_t LPath{LDistances[LPartition.FX][LPartition.FY] + 1};
                        if(LPath < LDistances[LPartition.FX + 1][LPartition.FY + 1])
                        {
                            LPaths[LPartition.FX + 1][LPartition.FY + 1] = LPartition;
                            LDistances[LPartition.FX + 1][LPartition.FY + 1] = LPath;
                            LScores[LPartition.FX + 1][LPartition.FY + 1] = LPath + std::max(std::abs(LPartition.FX + 1 - FMovementX) , std::abs(LPartition.FY + 1 - FMovementY));
                            if(std::ranges::find_if(LPartitions , [&](SPartition const& PPartition)->bool{return(LPartition.FX + 1 == PPartition.FX && LPartition.FY + 1 == PPartition.FY);}) == LPartitions.end())
                            {
                                LPartitions.push_back({LPartition.FX + 1 , LPartition.FY + 1});
                            }
                        }
                    }
                    if(LPartition.FX - 1 == std::clamp<std::intmax_t>(LPartition.FX - 1 , 0 , GSpace.FWidth - 1) && LPartition.FY + 1 == std::clamp<std::intmax_t>(LPartition.FY + 1 , 0 , GSpace.FHeight - 1) && (!GSpace.FMatrix[LPartition.FX - 1][LPartition.FY + 1].FEntity || GSpace.FMatrix[LPartition.FX - 1][LPartition.FY + 1].FEntity.get() == this))
                    {
                        std::int64_t LPath{LDistances[LPartition.FX][LPartition.FY] + 1};
                        if(LPath < LDistances[LPartition.FX - 1][LPartition.FY + 1])
                        {
                            LPaths[LPartition.FX - 1][LPartition.FY + 1] = LPartition;
                            LDistances[LPartition.FX - 1][LPartition.FY + 1] = LPath;
                            LScores[LPartition.FX - 1][LPartition.FY + 1] = LPath + std::max(std::abs(LPartition.FX - 1 - FMovementX) , std::abs(LPartition.FY + 1 - FMovementY));
                            if(std::ranges::find_if(LPartitions , [&](SPartition const& PPartition)->bool{return(LPartition.FX - 1 == PPartition.FX && LPartition.FY + 1 == PPartition.FY);}) == LPartitions.end())
                            {
                                LPartitions.push_back({LPartition.FX - 1 , LPartition.FY + 1});
                            }
                        }
                    }
                    if(LPartition.FX + 1 == std::clamp<std::intmax_t>(LPartition.FX + 1 , 0 , GSpace.FWidth - 1) && LPartition.FY - 1 == std::clamp<std::intmax_t>(LPartition.FY - 1 , 0 , GSpace.FHeight - 1) && (!GSpace.FMatrix[LPartition.FX + 1][LPartition.FY - 1].FEntity || GSpace.FMatrix[LPartition.FX + 1][LPartition.FY - 1].FEntity.get() == this))
                    {
                        std::int64_t LPath{LDistances[LPartition.FX][LPartition.FY] + 1};
                        if(LPath < LDistances[LPartition.FX + 1][LPartition.FY - 1])
                        {
                            LPaths[LPartition.FX + 1][LPartition.FY - 1] = LPartition;
                            LDistances[LPartition.FX + 1][LPartition.FY - 1] = LPath;
                            LScores[LPartition.FX + 1][LPartition.FY - 1] = LPath + std::max(std::abs(LPartition.FX + 1 - FMovementX) , std::abs(LPartition.FY - 1 - FMovementY));
                            if(std::ranges::find_if(LPartitions , [&](SPartition const& PPartition)->bool{return(LPartition.FX + 1 == PPartition.FX && LPartition.FY - 1 == PPartition.FY);}) == LPartitions.end())
                            {
                                LPartitions.push_back({LPartition.FX + 1 , LPartition.FY - 1});
                            }
                        }
                    }
                }
                if(LPaths[FMovementX][FMovementY].FX != -1 && LPaths[FMovementX][FMovementY].FY != -1)
                {
                    SPartition LPartition{FMovementX , FMovementY};
                    while(LPaths[LPartition.FX][LPartition.FY].FX != FX || LPaths[LPartition.FX][LPartition.FY].FY != FY)
                    {
                        LPartition = LPaths[LPartition.FX][LPartition.FY];
                    }
                    GSpace.FMatrix[FX][FY].FEntity.swap(GSpace.FMatrix[LPartition.FX][LPartition.FY].FEntity);
                    FX = LPartition.FX;
                    FY = LPartition.FY;
                    if(FX == FMovementX && FY == FMovementY)
                    {
                        FMoving = false;
                    }
                }
            }
        }
        FSprite
        ->IAccessDestinationXSquareAbsolute(GSpace.FScaleX * (-GSpace.FX + GSpace.FIterationX))->IAccessDestinationYSquareAbsolute(GSpace.FScaleY * (-GSpace.FY + GSpace.FIterationY))
        ->IAccessDestinationWidthSquareAbsolute(GSpace.FScaleX)->IAccessDestinationHeightSquareAbsolute(GSpace.FScaleY)
        ->IDraw();
        return(this);
    }

    SEntity* SEntity::ISelect()
    {
        SDL_Rect LSelection{NVideo::GVideo.IConvertFromSquareToPixel(GSpace.FScaleX * (-GSpace.FX + FX)) , NVideo::GVideo.IConvertFromSquareToPixel(GSpace.FScaleY * (-GSpace.FY + FY)) , NVideo::GVideo.IConvertFromSquareToPixel(GSpace.FScaleX) , NVideo::GVideo.IConvertFromSquareToPixel(GSpace.FScaleY)};
        SDL_SetRenderDrawColor(NVideo::GVideo.IRenderer() , 0 , 100 , 0 , SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(NVideo::GVideo.IRenderer() , &LSelection);
        return(this);
    }

    SEntity* SEntity::IMove(std::int64_t const& LX , std::int64_t const& LY)
    {
        FMoving = true;
        FMovementX = LX;
        FMovementY = LY;
        FTimer = 0;
        return(this);
    }
}