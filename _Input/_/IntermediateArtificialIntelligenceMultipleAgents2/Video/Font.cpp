#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

#include"Font.hpp"
#include"Image.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NVideo::NFont
{
    SFont::SFont(const std::string& APath)
    {
        FPath = APath.substr(APath.find('/'));
        TTF_Font* LFont{TTF_OpenFont(APath.c_str() , 64)};
        NDebug::GDebug.ISimpleDirectMediaLayerHandleError(LFont);
        for(char LDigit{'0'} ; LDigit <= '9' ; LDigit++)
        {
            FDigits.emplace_back(new NImage::SImage{LFont , std::string{LDigit}});
        }
        FDigits.shrink_to_fit();
        for(char LUppercase{'A'} ; LUppercase <= 'Z' ; LUppercase++)
        {
            FUppercases.emplace_back(new NImage::SImage{LFont , std::string{LUppercase}});
        }
        FUppercases.shrink_to_fit();
        for(char LLowercase{'a'} ; LLowercase <= 'z' ; LLowercase++)
        {
            FLowercases.emplace_back(new NImage::SImage{LFont , std::string{LLowercase}});
        }
        FLowercases.shrink_to_fit();
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Strings"})
        {
            if(LEntry.path().extension() == ".txt")
            {
                std::fstream LStream{LEntry.path().string() , std::ios::in};
                while(LStream)
                {
                    std::string LString;
                    LStream >> LString;
                    if(LStream)
                    {
                        FStrings.emplace_back(new NImage::SImage{LFont , LString});
                    }
                }
            }
        }
        FStrings.shrink_to_fit();
        TTF_CloseFont(LFont);
    }

    std::string const& SFont::IPath()
    {
        return(FPath);
    }

    std::vector<std::shared_ptr<NImage::SImage>> const& SFont::IDigits()
    {
        return(FDigits);
    }

    std::vector<std::shared_ptr<NImage::SImage>> const& SFont::IUppercases()
    {
        return(FUppercases);
    }

    std::vector<std::shared_ptr<NImage::SImage>> const& SFont::ILowercases()
    {
        return(FLowercases);
    }

    std::vector<std::shared_ptr<NImage::SImage>> const& SFont::IStrings()
    {
        return(FStrings);
    }

    SFont* SFont::IPath(std::string const& AValue)
    {
        FPath = AValue;
        return(this);
    }

    SFont* SFont::IDigits(std::vector<std::shared_ptr<NImage::SImage>> const& AValue)
    {
        FDigits = AValue;
        return(this);
    }

    SFont* SFont::IUppercases(std::vector<std::shared_ptr<NImage::SImage>> const& AValue)
    {
        FUppercases = AValue;
        return(this);
    }

    SFont* SFont::ILowercases(std::vector<std::shared_ptr<NImage::SImage>> const& AValue)
    {
        FLowercases = AValue;
        return(this);
    }

    SFont* SFont::IStrings(std::vector<std::shared_ptr<NImage::SImage>> const& AValue)
    {
        FStrings = AValue;
        return(this);
    }

    bool SFont::IIs(const std::string& APath)
    {
        return(FPath == APath);
    }

    NImage::SImage* SFont::IAccessDigit(char ACode)
    {
        return(FDigits[static_cast<std::int64_t>(ACode) - static_cast<std::int64_t>('0')].get());
    }

    NImage::SImage* SFont::IAccessUppercase(char ACode)
    {
        return(FUppercases[static_cast<std::int64_t>(ACode) - static_cast<std::int64_t>('A')].get());
    }

    NImage::SImage* SFont::IAccessLowercase(char ACode)
    {
        return(FLowercases[static_cast<std::int64_t>(ACode) - static_cast<std::int64_t>('a')].get());
    }

    NImage::SImage* SFont::IAccessString(const std::string& AString)
    {
        std::vector<std::shared_ptr<NImage::SImage>>::iterator LIterator
        {
            std::find_if(FStrings.begin() , FStrings.end() , [&](std::shared_ptr<NImage::SImage>& LPointer){return(LPointer->IIs(AString));})
        };
        return(LIterator->get());
    }

    SFont::~SFont()
    {
        FLowercases.clear();
        FUppercases.clear();
        FDigits.clear();
    }
}