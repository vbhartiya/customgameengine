#pragma once

#include <iostream>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

#include "../Maths/Maths.h"
#include "fontmanager.h"
#include "../Audio/audiomanager.h"

#define MAX_KEYS	 1024
#define MAX_BUTTONS  32

namespace engine {	namespace graphics {

	class Window {
	private:
		const char* m_name;
		int m_width, m_height;
		bool m_closed;

		GLFWwindow* m_window;

		bool m_keys[MAX_KEYS];
		bool m_keyStates[MAX_KEYS];

		bool m_buttons[MAX_BUTTONS];
		bool m_buttonStates[MAX_BUTTONS];
		
		double m_mouse_x, m_mouse_y;
	public:
		Window(const char* name, int width, int height);
		~Window();
		bool Closed() const;
		void Update();
		void Clear() const;

		bool IsKeyPressed(unsigned int keycode) const;
		bool IsKeyTyped(unsigned int keycode) const;
		bool IsMouseButtonPressed(unsigned int button) const;
		bool IsMouseButtonClicked(unsigned int button) const;
		maths::Vec2 GetMousePos() const;

		inline int GetWidth() const { return m_width; }
		inline int GetHeight() const { return m_height; }
	private:
		bool Init();

		friend void Window_Resize(GLFWwindow *window, int width, int height);
		friend void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods);
		friend void Cursor_Position_Callback(GLFWwindow* window, double xpos, double ypos);
	};

}	}