#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NVideo::NFont
{
    struct SFont
    {       
        std::string FPath;
        std::vector<std::shared_ptr<NImage::SImage>> FDigits;
        std::vector<std::shared_ptr<NImage::SImage>> FUppercases;
        std::vector<std::shared_ptr<NImage::SImage>> FLowercases;
        std::vector<std::shared_ptr<NImage::SImage>> FStrings;

        SFont(const std::string& APath);
        std::string const& IPath();
        std::vector<std::shared_ptr<NImage::SImage>> const& IDigits();
        std::vector<std::shared_ptr<NImage::SImage>> const& IUppercases();
        std::vector<std::shared_ptr<NImage::SImage>> const& ILowercases();
        std::vector<std::shared_ptr<NImage::SImage>> const& IStrings();
        SFont* IPath(std::string const& AValue);
        SFont* IDigits(std::vector<std::shared_ptr<NImage::SImage>> const& AValue);
        SFont* IUppercases(std::vector<std::shared_ptr<NImage::SImage>> const& AValue);
        SFont* ILowercases(std::vector<std::shared_ptr<NImage::SImage>> const& AValue);
        SFont* IStrings(std::vector<std::shared_ptr<NImage::SImage>> const& AValue);
        bool IIs(const std::string& APath);
        NImage::SImage* IAccessDigit(char ACode);
        NImage::SImage* IAccessUppercase(char ACode);
        NImage::SImage* IAccessLowercase(char ACode);
        NImage::SImage* IAccessString(const std::string& AString);
        ~SFont();
    };
}