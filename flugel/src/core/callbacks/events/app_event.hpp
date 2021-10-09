#pragma once

#include "event.hpp"

namespace fge {
  enum class AppEventType {
    None = 0,
    Start, Poll, Tick, UpdateFixed, Update, Render, End,
  };

  class FGE_API AppEvent : public Event {
  public:
    EVENT_CATEGORY(EventCategory::App)

    AppEventType type() const { return type_; }
  protected:
    const AppEventType type_;
    
    AppEvent(AppEventType type)
      : type_{type} {}
  };

  class FGE_API AppStartEvent : public AppEvent {
  public:
    AppStartEvent()
     : AppEvent{AppEventType::Start} {}

    std::string toString() const override {
      std::stringstream ss;
      ss << "Event <App> (START)";
      return ss.str();
    }
  };

  class FGE_API AppPollEvent : public AppEvent {
  public:
    AppPollEvent()
     : AppEvent{AppEventType::Poll} {}

    std::string toString() const override {
      std::stringstream ss;
      ss << "Event <App> (POLL)";
      return ss.str();
    }
  };

  class FGE_API AppTickEvent : public AppEvent {
  public:
    AppTickEvent()
     : AppEvent{AppEventType::Tick} {}

    std::string toString() const override {
      std::stringstream ss;
      ss << "Event <App> (TICK)";
      return ss.str();
    }
  };

  class FGE_API AppUpdateFixedEvent : public AppEvent {
  public:
    AppUpdateFixedEvent()
     : AppEvent{AppEventType::UpdateFixed} {}

    std::string toString() const override {
      std::stringstream ss;
      ss << "Event <App> (UPDATE_FIXED)";
      return ss.str();
    }
  };

  class FGE_API AppUpdateEvent : public AppEvent {
  public:
    AppUpdateEvent()
     : AppEvent{AppEventType::Update} {}

    std::string toString() const override {
      std::stringstream ss;
      ss << "Event <App> (UPDATE)";
      return ss.str();
    }
  };

  class FGE_API AppRenderEvent : public AppEvent {
  public:
    AppRenderEvent()
     : AppEvent{AppEventType::Render} {}

    std::string toString() const override {
      std::stringstream ss;
      ss << "Event <App> (RENDER)";
      return ss.str();
    }
  };

  class FGE_API AppEndEvent : public AppEvent {
  public:
    AppEndEvent()
     : AppEvent{AppEventType::End} {}

    std::string toString() const override {
      std::stringstream ss;
      ss << "Event <App> (END)";
      return ss.str();
    }
  };
}