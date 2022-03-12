#pragma once

#include "core/callbacks/events/event.hpp"
#include "core/callbacks/events/app_event.hpp"
#include "core/callbacks/events/render_event.hpp"
#include "core/callbacks/events/logic_event.hpp"
#include "core/callbacks/events/window_event.hpp"
#include "core/callbacks/events/keyboard_event.hpp"
#include "core/callbacks/events/mouse_event.hpp"

namespace fge {
  class FGE_API Layer {
  public:
    explicit Layer(std::string name = "layer");
    virtual ~Layer();
    
    virtual void attach() {}
    virtual void detach() {}

    void toggle(bool enabled) { enabled_ = enabled; }
    [[nodiscard]] bool isEnabled() const { return enabled_; }
    
    void onEvent(Event& e) {
      if (!enabled_) return;

      EventDispatcher d{e};
      //FGE_DEBUG_ENG("{0}: {1}", name_, e);
      switch (e.type()) { // Input events
        case Event::Keyboard: { return d.dispatch<KeyboardEvent>(FGE_BIND(onKeyboardEvent)); }
        case Event::Mouse:    { return d.dispatch<MouseEvent>   (FGE_BIND(onMouseEvent));    }
        case Event::Cursor:   { return d.dispatch<CursorEvent>  (FGE_BIND(onCursorEvent));   }
        case Event::Scroll:   { return d.dispatch<ScrollEvent>  (FGE_BIND(onScrollEvent));   }
        case Event::App:      { return d.dispatch<AppEvent>     (FGE_BIND(onAppEvent));      }
        case Event::Render:   { return d.dispatch<RenderEvent>  (FGE_BIND(onRenderEvent));   }
        case Event::Logic:    { return d.dispatch<LogicEvent>   (FGE_BIND(onLogicEvent));    }
        case Event::Window:   { return d.dispatch<WindowEvent>  (FGE_BIND(onWindowEvent));   }
        default: break;
      }
//      switch (e.category()) { // App events
//        default: break;
//      }
    }

    [[nodiscard]] const std::string& name() const { return name_; }
  protected:
    std::string name_;
    bool enabled_{true};
    // bool enabled_;

    virtual bool onAppEvent(AppEvent& e)           { return false; }
    virtual bool onRenderEvent(RenderEvent& e)     { return false; }
    virtual bool onLogicEvent(LogicEvent& e)       { return false; }

    virtual bool onWindowEvent(WindowEvent& e)     { return false; }
    virtual bool onKeyboardEvent(KeyboardEvent& e) { return false; }
    virtual bool onMouseEvent(MouseEvent& e)       { return false; }
    virtual bool onCursorEvent(CursorEvent& e)     { return false; }
    virtual bool onScrollEvent(ScrollEvent& e)     { return false; }
  private:
    // virtual bool onAppEvent(AppEvent& e);
  };
}