#pragma once

#include "../Graphics/window.h"
#include "../Maths/Maths.h"

namespace engine {	namespace input {

	static class Input {
	public:
		static inline bool IsKeyPressed(unsigned int keycode) { return graphics::Window::m_instance->IsKeyPressed(keycode); }
		static inline bool IsKeyTyped(unsigned int keycode) { return graphics::Window::m_instance->IsKeyTyped(keycode); }
		static inline bool IsMouseButtonPressed(unsigned int button) { return graphics::Window::m_instance->IsMouseButtonPressed(button); }
		static inline bool IsMouseButtonClicked(unsigned int button) { return graphics::Window::m_instance->IsMouseButtonClicked(button); }
		static inline maths::Vec2 GetMousePos() { return graphics::Window::m_instance->GetMousePos(); }
	};

}	}