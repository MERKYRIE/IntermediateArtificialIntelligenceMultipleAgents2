#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

#include"Image.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NVideo::NImage
{
    SImage::SImage(const std::string& APath)
    {
        FPath = APath.substr(APath.find('/'));
        FHandle = IMG_LoadTexture(GVideo.IRenderer() , APath.c_str());
        NDebug::GDebug.ISimpleDirectMediaLayerHandleError(FHandle);
    }

    SImage::SImage(TTF_Font* AFont , const std::string& AString)
    {
        FPath = AString;
        SDL_Surface* LSurface
        {
            TTF_RenderUTF8_LCD_Wrapped
            (
                AFont
                ,
                (std::string{} + "\n" + " " + AString + " " + "\n").c_str()
                ,
                SDL_Color{.r{100} , .g{100} , .b{100} , .a{SDL_ALPHA_OPAQUE}}
                ,
                SDL_Color{.r{0} , .g{0} , .b{0} , .a{SDL_ALPHA_OPAQUE}}
                ,
                0
            )
        };
        NDebug::GDebug.ISimpleDirectMediaLayerHandleError(LSurface);
        FHandle = SDL_CreateTextureFromSurface(GVideo.IRenderer() , LSurface);
        NDebug::GDebug.ISimpleDirectMediaLayerHandleError(FHandle);
        SDL_FreeSurface(LSurface);
    }

    std::string const& SImage::IPath()
    {
        return(FPath);
    }

    SDL_Texture* const& SImage::IHandle()
    {
        return(FHandle);
    }

    SImage* SImage::IPath(std::string const& AValue)
    {
        FPath = AValue;
        return(this);
    }

    SImage* SImage::IHandle(SDL_Texture* const& AValue)
    {
        FHandle = AValue;
        return(this);
    }

    bool SImage::IIs(const std::string& APath)
    {
        return(FPath == APath);
    }

    std::int32_t SImage::IAccessWidth()
    {
        std::int32_t LWidth;
        SDL_QueryTexture(FHandle , nullptr , nullptr , &LWidth , nullptr);
        return LWidth;
    }

    std::int32_t SImage::IAccessHeight()
    {
        std::int32_t LHeight;
        SDL_QueryTexture(FHandle , nullptr , nullptr , nullptr , &LHeight);
        return LHeight;
    }

    std::int32_t SImage::IAccessMinimum()
    {
        std::int32_t LWidth;
        std::int32_t LHeight;
        SDL_QueryTexture(FHandle , nullptr , nullptr , &LWidth , &LHeight);
        return(std::min(LWidth , LHeight));
    }

    std::int32_t SImage::IAccessMaximum()
    {
        std::int32_t LWidth;
        std::int32_t LHeight;
        SDL_QueryTexture(FHandle , nullptr , nullptr , &LWidth , &LHeight);
        return(std::max(LWidth , LHeight));
    }

    SImage* SImage::IDraw(const SDL_Rect& ASource , const SDL_Rect& ADestination)
    {
        SDL_RenderCopy(GVideo.IRenderer() , FHandle , &ASource , &ADestination);
        return(this);
    }

    SImage::~SImage()
    {
        SDL_DestroyTexture(FHandle);
    }
}