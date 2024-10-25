#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NSpace::NEntity
{
    struct SEntity
    {
        std::shared_ptr<NVideo::NSprite::SSprite> FSprite;
        std::int64_t FX;
        std::int64_t FY;
        bool FMoving;
        std::int64_t FMovementX;
        std::int64_t FMovementY;
        std::int64_t FTimer;

        SEntity(std::int64_t const& LX , std::int64_t const& LY);
        SEntity* IUpdate();
        SEntity* ISelect();
        SEntity* IMove(std::int64_t const& LX , std::int64_t const& LY);
    };
}