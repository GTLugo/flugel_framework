#pragma once

#include "core/input/key_codes.hpp"
#include "core/input/mouse_codes.hpp"

namespace fge {
  class FGE_API Input {
  public:
    static bool isPressed(Key::Code key) { return instance_->isKeyPressedImpl(key); }
    static bool isPressed(Mouse::Code button) { return instance_->isMousePressedImpl(button); }
    //static bool isPressed(Modifier::Codes mods) { return instance_->areModifiersPressedImpl(mods); }
    static vector2_t cursorPos() { return instance_->cursorPosImpl(); }
    static double cursorPosX() { return instance_->cursorPosXImpl(); }
    static double cursorPosY() { return instance_->cursorPosYImpl(); }

  protected:
    virtual bool isKeyPressedImpl(Key::Code key) = 0;
    virtual bool isMousePressedImpl(Mouse::Code button) = 0;
    //virtual bool areModifiersPressedImpl(Modifier::Codes mods) = 0;
    virtual vector2_t cursorPosImpl() = 0;
    virtual double cursorPosXImpl() = 0;
    virtual double cursorPosYImpl() = 0;
    
  private:
    static Unique<Input> instance_;
  };
}