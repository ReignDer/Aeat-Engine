#include "aepch.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Aeat {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}