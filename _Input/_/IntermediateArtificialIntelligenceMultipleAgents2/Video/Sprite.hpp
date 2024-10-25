#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NVideo::NSprite
{
    struct SSprite
    {
        NImage::SImage* FImage;
        SDL_Rect FSource;
        SDL_Rect FDestination;

        SSprite();
        NImage::SImage* const& IImage();
        SDL_Rect const& ISource();
        SDL_Rect const& IDestination();
        SSprite* IImage(NImage::SImage* const& AImage);
        SSprite* ISource(SDL_Rect const& AValue);
        SSprite* IDestination(SDL_Rect const& AValue);
        SSprite* ILoad(NImage::SImage* AImage);
        SSprite* IUnload();
        std::int32_t IAccessSourceX();
        std::int32_t IAccessSourceY();
        std::int32_t IAccessSourceWidth();
        std::int32_t IAccessSourceHeight();
        SSprite* IAccessSourceXAbsolute(std::int32_t AX);
        SSprite* IAccessSourceYAbsolute(std::int32_t AY);
        SSprite* IAccessSourceWidthAbsolute(std::int32_t AWidth);
        SSprite* IAccessSourceHeightAbsolute(std::int32_t AHeight);
        SSprite* IAccessSourceXRelative(std::int32_t AX);
        SSprite* IAccessSourceYRelative(std::int32_t AY);
        SSprite* IAccessSourceWidthRelative(std::int32_t AWidth);
        SSprite* IAccessSourceHeightRelative(std::int32_t AHeight);
        double IAccessSourceXRectangle();
        double IAccessSourceYRectangle();
        double IAccessSourceWidthRectangle();
        double IAccessSourceHeightRectangle();
        SSprite* IAccessSourceXRectangleAbsolute(double AX);
        SSprite* IAccessSourceYRectangleAbsolute(double AY);
        SSprite* IAccessSourceWidthRectangleAbsolute(double AWidth);
        SSprite* IAccessSourceHeightRectangleAbsolute(double AHeight);
        SSprite* IAccessSourceXRectangleRelative(double AX);
        SSprite* IAccessSourceYRectangleRelative(double AY);
        SSprite* IAccessSourceWidthRectangleRelative(double AWidth);
        SSprite* IAccessSourceHeightRectangleRelative(double AHeight);
        double IAccessSourceXSquare();
        double IAccessSourceYSquare();
        double IAccessSourceWidthSquare();
        double IAccessSourceHeightSquare();
        SSprite* IAccessSourceXSquareAbsolute(double AX);
        SSprite* IAccessSourceYSquareAbsolute(double AY);
        SSprite* IAccessSourceWidthSquareAbsolute(double AWidth);
        SSprite* IAccessSourceHeightSquareAbsolute(double AHeight);
        SSprite* IAccessSourceXSquareRelative(double AX);
        SSprite* IAccessSourceYSquareRelative(double AY);
        SSprite* IAccessSourceWidthSquareRelative(double AWidth);
        SSprite* IAccessSourceHeightSquareRelative(double AHeight);
        std::int32_t IAccessDestinationX();
        std::int32_t IAccessDestinationY();
        std::int32_t IAccessDestinationWidth();
        std::int32_t IAccessDestinationHeight();
        SSprite* IAccessDestinationXAbsolute(std::int32_t AX);
        SSprite* IAccessDestinationYAbsolute(std::int32_t AY);
        SSprite* IAccessDestinationWidthAbsolute(std::int32_t AWidth);
        SSprite* IAccessDestinationHeightAbsolute(std::int32_t AHeight);
        SSprite* IAccessDestinationXRelative(std::int32_t AX);
        SSprite* IAccessDestinationYRelative(std::int32_t AY);
        SSprite* IAccessDestinationWidthRelative(std::int32_t AWidth);
        SSprite* IAccessDestinationHeightRelative(std::int32_t AHeight);
        double IAccessDestinationXRectangle();
        double IAccessDestinationYRectangle();
        double IAccessDestinationWidthRectangle();
        double IAccessDestinationHeightRectangle();
        SSprite* IAccessDestinationXRectangleAbsolute(double AX);
        SSprite* IAccessDestinationYRectangleAbsolute(double AY);
        SSprite* IAccessDestinationWidthRectangleAbsolute(double AWidth);
        SSprite* IAccessDestinationHeightRectangleAbsolute(double AHeight);
        SSprite* IAccessDestinationXRectangleRelative(double AX);
        SSprite* IAccessDestinationYRectangleRelative(double AY);
        SSprite* IAccessDestinationWidthRectangleRelative(double AWidth);
        SSprite* IAccessDestinationHeightRectangleRelative(double AHeight);
        double IAccessDestinationXSquare();
        double IAccessDestinationYSquare();
        double IAccessDestinationWidthSquare();
        double IAccessDestinationHeightSquare();
        SSprite* IAccessDestinationXSquareAbsolute(double AX);
        SSprite* IAccessDestinationYSquareAbsolute(double AY);
        SSprite* IAccessDestinationWidthSquareAbsolute(double AWidth);
        SSprite* IAccessDestinationHeightSquareAbsolute(double AHeight);
        SSprite* IAccessDestinationXSquareRelative(double AX);
        SSprite* IAccessDestinationYSquareRelative(double AY);
        SSprite* IAccessDestinationWidthSquareRelative(double AWidth);
        SSprite* IAccessDestinationHeightSquareRelative(double AHeight);
        SSprite* IDraw();
    };
}