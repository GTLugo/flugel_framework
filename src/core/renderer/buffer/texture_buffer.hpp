//
// Created by galex on 2/20/2022.
//

#pragma once

namespace ff {
  class TextureBuffer {
  public:
    enum class Format {
      None = 0,
      RGB
    };

    virtual ~TextureBuffer() = default;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;
    [[nodiscard]] virtual u32 handle() const = 0;

    static Shared<TextureBuffer> create(Format format, i32 width, i32 height, void* data);
  };
}

