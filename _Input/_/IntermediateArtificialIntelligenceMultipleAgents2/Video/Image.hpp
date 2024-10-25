#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NVideo::NImage
{
    struct SImage
    {
        std::string FPath;
        SDL_Texture* FHandle;

        SImage(const std::string& APath);
        SImage(TTF_Font* AFont , const std::string& AString);
        std::string const& IPath();
        SDL_Texture* const& IHandle();
        SImage* IPath(std::string const& AValue);
        SImage* IHandle(SDL_Texture* const& AValue);
        bool IIs(const std::string& APath);
        std::int32_t IAccessWidth();
        std::int32_t IAccessHeight();
        std::int32_t IAccessMinimum();
        std::int32_t IAccessMaximum();
        SImage* IDraw(const SDL_Rect& ASource , const SDL_Rect& ADestination);
        ~SImage();
    };
}