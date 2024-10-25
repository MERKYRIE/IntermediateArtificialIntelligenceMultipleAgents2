#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NSpace
{
    namespace NEntity
    {
        struct SEntity;
    }
    
    struct SPartition
    {
        std::shared_ptr<NVideo::NSprite::SSprite> FGround;
        std::shared_ptr<NEntity::SEntity> FEntity;
    };
    
    inline struct SSpace
    {
        double FX;
        double FY;
        double FSpeedX;
        double FSpeedY;
        std::int64_t FIterationX;
        std::int64_t FIterationY;
        std::int64_t FWidth;
        std::int64_t FHeight;
        double FScaleX;
        double FScaleY;
        double FScaleLastX;
        double FScaleLastY;
        double FScaleXMinimum;
        double FScaleXMaximum;
        double FScaleYMinimum;
        double FScaleYMaximum;
        double FScalingX;
        double FScalingY;
        std::vector<std::vector<SPartition>> FMatrix;
        std::vector<NEntity::SEntity*> FSelection;

        SSpace();
        void IPreupdate();
        void IPostupdate();
        ~SSpace();
    }
    GSpace;
}