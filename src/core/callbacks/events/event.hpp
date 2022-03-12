#pragma once

// BASED HEAVILY ON TheCherno's IMPLEMENTATION IN HIS GAME ENGINE SERIES
// https://thecherno.com/engine

namespace fge {

  #define EVENT_TYPE(event_cat) static Type typeStatic() { return event_cat; }\
                                   virtual Type type() const override { return typeStatic(); }
  
  class FGE_API Event {
    friend class EventDispatcher;
  public:
    enum Type {
      None     = 0,
      Window   = 1 << 0,
      App      = 1 << 1,
      Logic    = 1 << 2,
      Render   = 1 << 3,
      Keyboard = 1 << 4,
      Mouse    = 1 << 5,
      Cursor   = 1 << 6,
      Scroll   = 1 << 7,

      // These might be best to separate out to avoid confusion
      Pipeline = App | Logic | Render,
      Input    = Keyboard | Cursor | Mouse | Scroll,
    };

    [[nodiscard]] virtual Type type() const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
    [[nodiscard]] virtual bool wasHandled() const { return wasHandled_; }
  protected:
    bool wasHandled_{false};
  };

  inline std::ostream& operator<<(std::ostream& out, const Event& e) {
    return out << e.toString();
  }

  // Takes an event and conditionally dispatches it to a handler if it matches the category type
  class EventDispatcher {
    template<typename Event_t>
    using EventHandlerFn = std::function<bool(Event_t&)>;
  public:
    explicit EventDispatcher(Event& e)
      : event_{e} {}
    
    template<typename Event_t>
    void dispatch(EventHandlerFn<Event_t> handlerFn) {
      event_.wasHandled_ = handlerFn(dynamic_cast<Event_t&>(event_));
    }
  private:
    Event& event_;
  };
}