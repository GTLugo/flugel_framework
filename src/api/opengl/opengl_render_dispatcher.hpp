//
// Created by galex on 2/17/2022.
//
#pragma once

#include "core/renderer/render_dispatcher.hpp"

namespace ff {
  class OpenGLRenderDispatcher : public RenderDispatcher {
  public:
    void clear(Color color) final;
    void draw(const Shared<VertexArray>& vertexArray) final;
    void setDepthTest(bool enabled) final;
  };
}
