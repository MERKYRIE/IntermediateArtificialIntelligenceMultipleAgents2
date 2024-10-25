#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NMouse
{
    namespace NButton
    {
        struct SButton;
    }

    inline struct SMouse
    {
        std::int64_t FButtonNumber;

        std::unordered_map<std::int64_t , std::string> FButtonAdaptors;

        std::unordered_map<std::string , std::shared_ptr<NButton::SButton>> FButtons;

        bool FXModified;

        std::int32_t FX;
        double FXRectangle;
        double FXSquare;

        std::int32_t FXDelta;
        double FXDeltaRectangle;
        double FXDeltaSquare;

        bool FYModified;

        std::int32_t FY;
        double FYRectangle;
        double FYSquare;

        std::int32_t FYDelta;
        double FYDeltaRectangle;
        double FYDeltaSquare;

        std::vector<std::int32_t> FXsPressed;
        std::vector<double> FXsPressedRectangle;
        std::vector<double> FXsPressedSquare;
        
        std::vector<std::int32_t> FXsReleased;
        std::vector<double> FXsReleasedRectangle;
        std::vector<double> FXsReleasedSquare;
        
        std::vector<std::int32_t> FXsDeltaHeld;
        std::vector<double> FXsDeltaHeldRectangle;
        std::vector<double> FXsDeltaHeldSquare;

        std::vector<std::int32_t> FYsPressed;
        std::vector<double> FYsPressedRectangle;
        std::vector<double> FYsPressedSquare;

        std::vector<std::int32_t> FYsReleased;
        std::vector<double> FYsReleasedRectangle;
        std::vector<double> FYsReleasedSquare;

        std::vector<std::int32_t> FYsDeltaHeld;
        std::vector<double> FYsDeltaHeldRectangle;
        std::vector<double> FYsHeldDeltaSquare;

        std::int32_t FWheel;
        bool FWheelModified;
        bool FWheelDown;
        bool FWheelUp;

        SMouse();
        void IPreupdate();

        std::int64_t const& IButtonNumber();

        std::unordered_map<std::string , std::shared_ptr<NButton::SButton>> const& IButtons();

        bool const& IIsXModified();

        std::int32_t const& IAbsoluteX();
        double const& IAbsoluteXRectangle();
        double const& IAbsoluteXSquare();

        std::int32_t const& IRelativeX();
        double const& IRelativeXRectangle();
        double const& IRelativeXSquare();

        bool const& IIsYModified();

        std::int32_t const& IAbsoluteY();
        double const& IAbsoluteYRectangle();
        double const& IAbsoluteYSquare();

        std::int32_t const& IRelativeY();
        double const& IRelativeYRectangle();
        double const& IRelativeYSquare();

        std::vector<std::int32_t> const& IXsPressedAbsolute();
        std::vector<double> const& IXsPressedAbsoluteRectangle();
        std::vector<double> const& IXsPressedAbsoluteSquare();

        std::vector<std::int32_t> const& IYsPressedAbsolute();
        std::vector<double> const& IYsPressedAbsoluteRectangle();
        std::vector<double> const& IYsPressedAbsoluteSquare();

        std::vector<std::int32_t> const& IXsReleasedAbsolute();
        std::vector<double> const& IXsReleasedAbsoluteRectangle();
        std::vector<double> const& IXsReleasedAbsoluteSquare();

        std::vector<std::int32_t> const& IYsReleasedAbsolute();
        std::vector<double> const& IYsReleasedAbsoluteRectangle();
        std::vector<double> const& IYsReleasedAbsoluteSquare();

        std::vector<std::int32_t> const& IXsHeldRelative();
        std::vector<double> const& IXsHeldRelativeRectangle();
        std::vector<double> const& IXsHeldRelativeSquare();

        std::vector<std::int32_t> const& IYsHeldRelative();
        std::vector<double> const& IYsHeldRelativeRectangle();
        std::vector<double> const& IYsHeldRelativeSquare();

        std::int32_t const& IWheelState();
        bool const& IIsWheelModified();
        bool const& IIsWheelDown();
        bool const& IIsWheelUp();

        void IButtonNumber(std::int64_t const& AValue);

        void IButtons(std::unordered_map<std::string , std::shared_ptr<NButton::SButton>> const& AValue);

        void IIsXModified(bool const& AValue);

        void IAbsoluteX(std::int32_t const& AValue);
        void IAbsoluteXRectangle(double const& AValue);
        void IAbsoluteXSquare(double const& AValue);

        void IRelativeX(std::int32_t const& AValue);
        void IRelativeXRectangle(double const& AValue);
        void IRelativeXSquare(double const& AValue);

        void IIsYModified(bool const& AValue);

        void IAbsoluteY(std::int32_t const& AValue);
        void IAbsoluteYRectangle(double const& AValue);
        void IAbsoluteYSquare(double const& AValue);

        void IRelativeY(std::int32_t const& AValue);
        void IRelativeYRectangle(double const& AValue);
        void IRelativeYSquare(double const& AValue);

        void IXsPressedAbsolute(std::vector<std::int32_t> const& AValue);
        void IXsPressedAbsoluteRectangle(std::vector<double> const& AValue);
        void IXsPressedAbsoluteSquare(std::vector<double> const& AValue);

        void IYsPressedAbsolute(std::vector<std::int32_t> const& AValue);
        void IYsPressedAbsoluteRectangle(std::vector<double> const& AValue);
        void IYsPressedAbsoluteSquare(std::vector<double> const& AValue);

        void IXsReleasedAbsolute(std::vector<std::int32_t> const& AValue);
        void IXsReleasedAbsoluteRectangle(std::vector<double> const& AValue);
        void IXsReleasedAbsoluteSquare(std::vector<double> const& AValue);

        void IYsReleasedAbsolute(std::vector<std::int32_t> const& AValue);
        void IYsReleasedAbsoluteRectangle(std::vector<double> const& AValue);
        void IYsReleasedAbsoluteSquare(std::vector<double> const& AValue);

        void IXsHeldRelative(std::vector<std::int32_t> const& AValue);
        void IXsHeldRelativeRectangle(std::vector<double> const& AValue);
        void IXsHeldRelativeSquare(std::vector<double> const& AValue);

        void IYsHeldRelative(std::vector<std::int32_t> const& AValue);
        void IYsHeldRelativeRectangle(std::vector<double> const& AValue);
        void IYsHeldRelativeSquare(std::vector<double> const& AValue);

        void IWheelState(std::int32_t const& AValue);
        void IIsWheelModified(bool const& AValue);
        void IIsWheelDown(bool const& AValue);
        void IIsWheelUp(bool const& AValue);

        void IPostupdate(SDL_Event& AEvent);
        ~SMouse();
    }
    GMouse;
}