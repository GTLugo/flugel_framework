#pragma once

namespace ff {
  class RenderContext {
  public:
    virtual void* nativeContext() = 0;
    virtual void setCurrent(bool isCurrent) = 0;
    virtual void swapBuffers() = 0;
  };
}