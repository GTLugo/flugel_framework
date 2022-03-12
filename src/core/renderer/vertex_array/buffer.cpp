#include "buffer.hpp"

#if defined(FLUGEL_USE_OPENGL)
  #include "api/opengl/vertex_array/opengl_buffer.hpp"
#endif

#include "core/renderer/renderer.hpp"

namespace fge {
  Shared<VertexBuffer> VertexBuffer::create(float* vertices, u32 bitSize) {
    FGE_ASSERT_ENG(vertices, "No vertices found for vertex buffer!");
    switch (Renderer::api()) {
      case Renderer::API::None: {
        FGE_ASSERT_ENG(false, "Running with no API not implemented!");
        return nullptr;
      }
      case Renderer::API::OpenGL: {
        #if defined(FLUGEL_USE_OPENGL)
          return makeShared<OpenGLVertexBuffer>(vertices, bitSize);
        #else
          FGE_ASSERT_ENG(false, "OpenGL not supported!");
          return nullptr;
        #endif
      }
      case Renderer::API::Vulkan: {
        #if defined(FLUGEL_USE_VULKAN)
          FGE_ASSERT_ENG(false, "Vulkan not implemented!");
          return nullptr;
        #else
          FGE_ASSERT_ENG(false, "Vulkan not supported!");
          return nullptr;
        #endif
      }
      case Renderer::API::D3D11: {
        #if defined(FLUGEL_USE_D3D11)
          FGE_ASSERT_ENG(false, "D3D11 not implemented!");
          return nullptr;
        #else
          FGE_ASSERT_ENG(false, "D3D11 not supported!");
          return nullptr;
        #endif
      }
      default: {
        FGE_ASSERT_ENG(false, "Unknown render api!");
        return nullptr;
      }
    }
  }

  Shared<VertexBuffer> VertexBuffer::create(std::vector<float>& vertices) {
    return create(vertices.data(), vertices.size() * sizeof(vertices[0]));
  }

  Shared<VertexBuffer> VertexBuffer::create(const std::initializer_list<float>& vertices) {
    std::vector<float> verts{vertices};
    return create(verts);
  }

  Shared<IndexBuffer> IndexBuffer::create(u32* indices, u32 count) {
    switch (Renderer::api()) {
      case Renderer::API::None: {
        FGE_ASSERT_ENG(false, "Running with no API not implemented!");
        return nullptr;
      }
      case Renderer::API::OpenGL: {
        #if defined(FLUGEL_USE_OPENGL)
          return makeShared<OpenGLIndexBuffer>(indices, count);
        #else
          FGE_ASSERT_ENG(false, "OpenGL not supported!");
          return nullptr;
        #endif
      }
      case Renderer::API::Vulkan: {
        #if defined(FLUGEL_USE_VULKAN)
          FGE_ASSERT_ENG(false, "Vulkan not implemented!");
          return nullptr;
        #else
          FGE_ASSERT_ENG(false, "Vulkan not supported!");
          return nullptr;
        #endif
      }
      case Renderer::API::D3D11: {
        #if defined(FLUGEL_USE_D3D11)
          FGE_ASSERT_ENG(false, "D3D11 not implemented!");
          return nullptr;
        #else
          FGE_ASSERT_ENG(false, "D3D11 not supported!");
          return nullptr;
        #endif
      }
      default: {
        FGE_ASSERT_ENG(false, "Unknown render api!");
        return nullptr;
      }
    }
  }
  
  Shared<IndexBuffer> IndexBuffer::create(const std::initializer_list<u32>& indices) {
    std::vector<u32> i{indices};
    return create(i);
  }
  
  Shared<IndexBuffer> IndexBuffer::create(std::vector<u32>& indices) {
    return create(indices.data(), indices.size());
  }
}