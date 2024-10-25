#include"IntermediateArtificialIntelligenceMultipleAgents2.hpp"

#include"Mouse/Button.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents2::NMouse
{
    SMouse::SMouse()
    {
        FButtonNumber = 6;
        FButtonAdaptors[SDL_BUTTON_LEFT] = "Left";
        FButtonAdaptors[SDL_BUTTON_MIDDLE] = "Middle";
        FButtonAdaptors[SDL_BUTTON_RIGHT] = "Right";
        FButtonAdaptors[SDL_BUTTON_X1] = "X1";
        FButtonAdaptors[SDL_BUTTON_X2] = "X2";
        FButtons["Left"] = std::make_shared<NButton::SButton>();
        FButtons["Middle"] = std::make_shared<NButton::SButton>();
        FButtons["Right"] = std::make_shared<NButton::SButton>();
        FButtons["X1"] = std::make_shared<NButton::SButton>();
        FButtons["X2"] = std::make_shared<NButton::SButton>();
        FXsPressed.resize(FButtonNumber);
        FYsPressed.resize(FButtonNumber);
        FXsPressedRectangle.resize(FButtonNumber);
        FYsPressedRectangle.resize(FButtonNumber);
        FXsPressedSquare.resize(FButtonNumber);
        FYsPressedSquare.resize(FButtonNumber);
        FXsReleased.resize(FButtonNumber);
        FYsReleased.resize(FButtonNumber);
        FXsReleasedRectangle.resize(FButtonNumber);
        FYsReleasedRectangle.resize(FButtonNumber);
        FXsReleasedSquare.resize(FButtonNumber);
        FYsReleasedSquare.resize(FButtonNumber);
        FXsDeltaHeld.resize(FButtonNumber);
        FYsDeltaHeld.resize(FButtonNumber);
        FXsDeltaHeldRectangle.resize(FButtonNumber);
        FYsDeltaHeldRectangle.resize(FButtonNumber);
        FXsDeltaHeldSquare.resize(FButtonNumber);
        FYsHeldDeltaSquare.resize(FButtonNumber);
        for(std::int64_t LButton{1} ; LButton < FButtonNumber ; LButton++)
        {
            FXsPressed[LButton] = 0;
            FYsPressed[LButton] = 0;
            FXsPressedRectangle[LButton] = 0.0;
            FYsPressedRectangle[LButton] = 0.0;
            FXsPressedSquare[LButton] = 0.0;
            FYsPressedSquare[LButton] = 0.0;
            FXsReleased[LButton] = 0;
            FYsReleased[LButton] = 0;
            FXsReleasedRectangle[LButton] = 0.0;
            FYsReleasedRectangle[LButton] = 0.0;
            FXsReleasedSquare[LButton] = 0.0;
            FYsReleasedSquare[LButton] = 0.0;
            FXsDeltaHeld[LButton] = 0;
            FYsDeltaHeld[LButton] = 0;
            FXsDeltaHeldRectangle[LButton] = 0.0;
            FYsDeltaHeldRectangle[LButton] = 0.0;
            FXsDeltaHeldSquare[LButton] = 0.0;
            FYsHeldDeltaSquare[LButton] = 0.0;
        }
        FX = 0;
        FXDelta = 0;
        FXRectangle = 0.0;
        FXDeltaRectangle = 0.0;
        FXSquare = 0.0;
        FXDeltaSquare = 0.0;
        FXModified = false;
        FY = 0;
        FYDelta = 0;
        FYRectangle = 0.0;
        FYDeltaRectangle = 0.0;
        FYSquare = 0.0;
        FYDeltaSquare = 0.0;
        FYModified = false;
        FWheel = 0;
        FWheelModified = false;
        FWheelDown = false;
        FWheelUp = false;
    }

    void SMouse::IPreupdate()
    {
        for(std::int64_t LButton{1} ; LButton < FButtonNumber ; LButton++)
        {
            FButtons[FButtonAdaptors[LButton]]->IPreupdate();
            FXsDeltaHeld[LButton] = 0;
            FYsDeltaHeld[LButton] = 0;
            FXsDeltaHeldRectangle[LButton] = 0.0;
            FYsDeltaHeldRectangle[LButton] = 0.0;
            FXsDeltaHeldSquare[LButton] = 0.0;
            FYsHeldDeltaSquare[LButton] = 0.0;
        }
        FXDelta = 0;
        FXDeltaRectangle = 0.0;
        FXDeltaSquare = 0.0;
        FXModified = false;
        FYDelta = 0;
        FYDeltaRectangle = 0.0;
        FYDeltaSquare = 0.0;
        FYModified = false;
        FWheel = 0;
        FWheelModified = false;
        FWheelDown = false;
        FWheelUp = false;
    }

    std::int64_t const& SMouse::IButtonNumber()
    {
        return(FButtonNumber);
    }

    std::unordered_map<std::string , std::shared_ptr<NButton::SButton>> const& SMouse::IButtons()
    {
        return(FButtons);
    }

    std::int32_t const& SMouse::IAbsoluteX()
    {
        return(FX);
    }

    std::int32_t const& SMouse::IRelativeX()
    {
        return(FXDelta);
    }

    double const& SMouse::IAbsoluteXRectangle()
    {
        return(FXRectangle);
    }

    double const& SMouse::IRelativeXRectangle()
    {
        return(FXDeltaRectangle);
    }

    double const& SMouse::IAbsoluteXSquare()
    {
        return(FXSquare);
    }

    double const& SMouse::IRelativeXSquare()
    {
        return(FXDeltaSquare);
    }

    bool const& SMouse::IIsXModified()
    {
        return(FXModified);
    }

    std::int32_t const& SMouse::IAbsoluteY()
    {
        return(FY);
    }

    std::int32_t const& SMouse::IRelativeY()
    {
        return(FYDelta);
    }

    double const& SMouse::IAbsoluteYRectangle()
    {
        return(FYRectangle);
    }

    double const& SMouse::IRelativeYRectangle()
    {
        return(FYDeltaRectangle);
    }

    double const& SMouse::IAbsoluteYSquare()
    {
        return(FYSquare);
    }

    double const& SMouse::IRelativeYSquare()
    {
        return(FYDeltaSquare);
    }

    bool const& SMouse::IIsYModified()
    {
        return(FYModified);
    }

    std::vector<std::int32_t> const& SMouse::IXsPressedAbsolute()
    {
        return(FXsPressed);
    }

    std::vector<std::int32_t> const& SMouse::IYsPressedAbsolute()
    {
        return(FYsPressed);
    }

    std::vector<double> const& SMouse::IXsPressedAbsoluteRectangle()
    {
        return(FXsPressedRectangle);
    }

    std::vector<double> const& SMouse::IYsPressedAbsoluteRectangle()
    {
        return(FYsPressedRectangle);
    }

    std::vector<double> const& SMouse::IXsPressedAbsoluteSquare()
    {
        return(FXsPressedSquare);
    }

    std::vector<double> const& SMouse::IYsPressedAbsoluteSquare()
    {
        return(FYsPressedSquare);
    }

    std::vector<std::int32_t> const& SMouse::IXsReleasedAbsolute()
    {
        return(FXsReleased);
    }

    std::vector<std::int32_t> const& SMouse::IYsReleasedAbsolute()
    {
        return(FYsReleased);
    }

    std::vector<double> const& SMouse::IXsReleasedAbsoluteRectangle()
    {
        return(FXsReleasedRectangle);
    }

    std::vector<double> const& SMouse::IYsReleasedAbsoluteRectangle()
    {
        return(FYsReleasedRectangle);
    }

    std::vector<double> const& SMouse::IXsReleasedAbsoluteSquare()
    {
        return(FXsReleasedSquare);
    }

    std::vector<double> const& SMouse::IYsReleasedAbsoluteSquare()
    {
        return(FYsReleasedSquare);
    }

    std::vector<std::int32_t> const& SMouse::IXsHeldRelative()
    {
        return(FXsDeltaHeld);
    }

    std::vector<std::int32_t> const& SMouse::IYsHeldRelative()
    {
        return(FYsDeltaHeld);
    }

    std::vector<double> const& SMouse::IXsHeldRelativeRectangle()
    {
        return(FXsDeltaHeldRectangle);
    }

    std::vector<double> const& SMouse::IYsHeldRelativeRectangle()
    {
        return(FYsDeltaHeldRectangle);
    }

    std::vector<double> const& SMouse::IXsHeldRelativeSquare()
    {
        return(FXsDeltaHeldSquare);
    }

    std::vector<double> const& SMouse::IYsHeldRelativeSquare()
    {
        return(FYsHeldDeltaSquare);
    }

    std::int32_t const& SMouse::IWheelState()
    {
        return(FWheel);
    }

    bool const& SMouse::IIsWheelModified()
    {
        return(FWheelModified);
    }

    bool const& SMouse::IIsWheelDown()
    {
        return(FWheelDown);
    }

    bool const& SMouse::IIsWheelUp()
    {
        return(FWheelUp);
    }

    void SMouse::IButtonNumber(std::int64_t const& AValue)
    {
        FButtonNumber = AValue;
    }

    void SMouse::IButtons(std::unordered_map<std::string , std::shared_ptr<NButton::SButton>> const& AValue)
    {
        FButtons = AValue;
    }

    void SMouse::IAbsoluteX(std::int32_t const& AValue)
    {
        FX = AValue;
    }

    void SMouse::IRelativeX(std::int32_t const& AValue)
    {
        FXDelta = AValue;
    }

    void SMouse::IAbsoluteXRectangle(double const& AValue)
    {
        FXRectangle = AValue;
    }

    void SMouse::IRelativeXRectangle(double const& AValue)
    {
        FXDeltaRectangle = AValue;
    }

    void SMouse::IAbsoluteXSquare(double const& AValue)
    {
        FXSquare = AValue;
    }

    void SMouse::IRelativeXSquare(double const& AValue)
    {
        FXDeltaSquare = AValue;
    }

    void SMouse::IIsXModified(bool const& AValue)
    {
        FXModified = AValue;
    }

    void SMouse::IAbsoluteY(std::int32_t const& AValue)
    {
        FY = AValue;
    }

    void SMouse::IRelativeY(std::int32_t const& AValue)
    {
        FYDelta = AValue;
    }

    void SMouse::IAbsoluteYRectangle(double const& AValue)
    {
        FYRectangle = AValue;
    }

    void SMouse::IRelativeYRectangle(double const& AValue)
    {
        FYDeltaRectangle = AValue;
    }

    void SMouse::IAbsoluteYSquare(double const& AValue)
    {
        FYSquare = AValue;
    }

    void SMouse::IRelativeYSquare(double const& AValue)
    {
        FYDeltaSquare = AValue;
    }

    void SMouse::IIsYModified(bool const& AValue)
    {
        FYModified = AValue;
    }

    void SMouse::IXsPressedAbsolute(std::vector<std::int32_t> const& AValue)
    {
        FXsPressed = AValue;
    }

    void SMouse::IYsPressedAbsolute(std::vector<std::int32_t> const& AValue)
    {
        FYsPressed = AValue;
    }

    void SMouse::IXsPressedAbsoluteRectangle(std::vector<double> const& AValue)
    {
        FXsPressedRectangle = AValue;
    }

    void SMouse::IYsPressedAbsoluteRectangle(std::vector<double> const& AValue)
    {
        FYsPressedRectangle = AValue;
    }

    void SMouse::IXsPressedAbsoluteSquare(std::vector<double> const& AValue)
    {
        FXsPressedSquare = AValue;
    }

    void SMouse::IYsPressedAbsoluteSquare(std::vector<double> const& AValue)
    {
        FYsPressedSquare = AValue;
    }

    void SMouse::IXsReleasedAbsolute(std::vector<std::int32_t> const& AValue)
    {
        FXsReleased = AValue;
    }

    void SMouse::IYsReleasedAbsolute(std::vector<std::int32_t> const& AValue)
    {
        FYsReleased = AValue;
    }

    void SMouse::IXsReleasedAbsoluteRectangle(std::vector<double> const& AValue)
    {
        FXsReleasedRectangle = AValue;
    }

    void SMouse::IYsReleasedAbsoluteRectangle(std::vector<double> const& AValue)
    {
        FYsReleasedRectangle = AValue;
    }

    void SMouse::IXsReleasedAbsoluteSquare(std::vector<double> const& AValue)
    {
        FXsReleasedSquare = AValue;
    }

    void SMouse::IYsReleasedAbsoluteSquare(std::vector<double> const& AValue)
    {
        FYsReleasedSquare = AValue;
    }

    void SMouse::IXsHeldRelative(std::vector<std::int32_t> const& AValue)
    {
        FXsDeltaHeld = AValue;
    }

    void SMouse::IYsHeldRelative(std::vector<std::int32_t> const& AValue)
    {
        FYsDeltaHeld = AValue;
    }

    void SMouse::IXsHeldRelativeRectangle(std::vector<double> const& AValue)
    {
        FXsDeltaHeldRectangle = AValue;
    }

    void SMouse::IYsHeldRelativeRectangle(std::vector<double> const& AValue)
    {
        FYsDeltaHeldRectangle = AValue;
    }

    void SMouse::IXsHeldRelativeSquare(std::vector<double> const& AValue)
    {
        FXsDeltaHeldSquare = AValue;
    }

    void SMouse::IYsHeldRelativeSquare(std::vector<double> const& AValue)
    {
        FYsHeldDeltaSquare = AValue;
    }

    void SMouse::IWheelState(std::int32_t const& AValue)
    {
        FWheel = AValue;
    }

    void SMouse::IIsWheelModified(bool const& AValue)
    {
        FWheelModified = AValue;
    }

    void SMouse::IIsWheelDown(bool const& AValue)
    {
        FWheelDown = AValue;
    }

    void SMouse::IIsWheelUp(bool const& AValue)
    {
        FWheelUp = AValue;
    }

    void SMouse::IPostupdate(SDL_Event& AEvent)
    {
        switch(AEvent.type)
        {
            case(SDL_MOUSEBUTTONDOWN):
                FButtons[FButtonAdaptors[AEvent.button.button]]->IPostupdate(AEvent);
                FXsPressed[AEvent.button.button] = AEvent.button.x;
                FYsPressed[AEvent.button.button] = AEvent.button.y;
                FXsPressedRectangle[AEvent.button.button] = NVideo::GVideo.IConvertFromPixelToRectangleHorizontal(FXsPressed[AEvent.button.button]);
                FYsPressedRectangle[AEvent.button.button] = NVideo::GVideo.IConvertFromPixelToRectangleVertical(FYsPressed[AEvent.button.button]);
                FXsPressedSquare[AEvent.button.button] = NVideo::GVideo.IConvertFromPixelToSquare(FXsPressed[AEvent.button.button]);
                FYsPressedSquare[AEvent.button.button] = NVideo::GVideo.IConvertFromPixelToSquare(FYsPressed[AEvent.button.button]);
            break;
            case(SDL_MOUSEBUTTONUP):
                FButtons[FButtonAdaptors[AEvent.button.button]]->IPostupdate(AEvent);
                FXsReleased[AEvent.button.button] = AEvent.button.x;
                FYsReleased[AEvent.button.button] = AEvent.button.y;
                FXsReleasedRectangle[AEvent.button.button] = NVideo::GVideo.IConvertFromPixelToRectangleHorizontal(FXsReleased[AEvent.button.button]);
                FYsReleasedRectangle[AEvent.button.button] = NVideo::GVideo.IConvertFromPixelToRectangleVertical(FYsReleased[AEvent.button.button]);
                FXsReleasedSquare[AEvent.button.button] = NVideo::GVideo.IConvertFromPixelToSquare(FXsReleased[AEvent.button.button]);
                FYsReleasedSquare[AEvent.button.button] = NVideo::GVideo.IConvertFromPixelToSquare(FYsReleased[AEvent.button.button]);
            break;
            case(SDL_MOUSEMOTION):
                FX = AEvent.motion.x;
                FXDelta = AEvent.motion.xrel;
                FXRectangle = NVideo::GVideo.IConvertFromPixelToRectangleHorizontal(FX);
                FXDeltaRectangle = NVideo::GVideo.IConvertFromPixelToRectangleVertical(FXDelta);
                FXSquare = NVideo::GVideo.IConvertFromPixelToSquare(FX);
                FXDeltaSquare = NVideo::GVideo.IConvertFromPixelToSquare(FXDelta);
                FXModified = FXDelta;
                FY = AEvent.motion.y;
                FYDelta = AEvent.motion.yrel;
                FYRectangle = NVideo::GVideo.IConvertFromPixelToRectangleHorizontal(FY);
                FYDeltaRectangle = NVideo::GVideo.IConvertFromPixelToRectangleVertical(FYDelta);
                FYSquare = NVideo::GVideo.IConvertFromPixelToSquare(FY);
                FYDeltaSquare = NVideo::GVideo.IConvertFromPixelToSquare(FYDelta);
                FYModified = FYDelta;
                for(std::int64_t LButton{1} ; LButton < FButtonNumber ; LButton++)
                {
                    if(FButtons[FButtonAdaptors[LButton]]->IStates().at("Held"))
                    {
                        FXsDeltaHeld[LButton] = FXDelta;
                        FYsDeltaHeld[LButton] = FYDelta;
                        FXsDeltaHeldRectangle[LButton] = NVideo::GVideo.IConvertFromPixelToRectangleHorizontal(FXsDeltaHeld[LButton]);
                        FYsDeltaHeldRectangle[LButton] = NVideo::GVideo.IConvertFromPixelToRectangleVertical(FYsDeltaHeld[LButton]);
                        FXsDeltaHeldSquare[LButton] = NVideo::GVideo.IConvertFromPixelToSquare(FXsDeltaHeld[LButton]);
                        FYsHeldDeltaSquare[LButton] = NVideo::GVideo.IConvertFromPixelToSquare(FYsDeltaHeld[LButton]);
                    }
                }
            break;
            case(SDL_MOUSEWHEEL):
                switch(AEvent.wheel.y)
                {
                    case(-1):
                        FWheel = AEvent.wheel.y;
                        FWheelModified = true;
                        FWheelDown = true;
                        FWheelUp = false;
                    break;
                    case(0):
                        FWheel = AEvent.wheel.y;
                        FWheelModified = false;
                        FWheelDown = false;
                        FWheelUp = false;
                    break;
                    case(+1):
                        FWheel = AEvent.wheel.y;
                        FWheelModified = true;
                        FWheelDown = false;
                        FWheelUp = true;
                    break;
                }
            break;
        }
    }

    SMouse::~SMouse()
    {
    
    }
}