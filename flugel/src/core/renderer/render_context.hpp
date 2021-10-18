#pragma once

namespace fge {
  class RenderContext {
  public:
    //virtual void* nativeContext() = 0;
    virtual void setCurrent(bool isCurrent) = 0;
    virtual void swapBuffers() = 0;
  private:
    virtual void init() = 0;
  };
}