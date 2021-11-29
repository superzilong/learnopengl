#include "Window.h"
#include "../OpenGL/OpenGLRenderContext.h"

namespace gen
{
	Window::Window(const WindowProps& props)
	{
		Init(props);
		std::string hel = "hello";
	}

	Window::~Window()
	{
	}

	void Window::OnUpdate()
	{
	}

	void Window::SetVSync(bool enabled)
	{
	}

	bool Window::IsVSync() const
	{
		return true;
	}

	void Window::Init(const WindowProps& props)
	{
		m_Context = std::make_unique<OpenGLRenderContext>(m_Window);
	}

	void Window::Shutdown()
	{
	}
}
