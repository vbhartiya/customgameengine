#include "window.h"

namespace engine {	namespace graphics {

	void Window_Resize(GLFWwindow*, int, int);
	void Key_Callback(GLFWwindow*, int , int , int , int);

	Window::Window(const char* name, int width, int height) {
		m_name = name;
		m_width = width;
		m_height = height;

		if (!Init())
			glfwTerminate();

		FontManager::Add(new Font("arial", "arial.ttf", 32));

		audio::AudioManager::Init();
		physics::PhysicsManager::Init();

		for (int i = 0; i < MAX_KEYS; i++) {
			m_keys[i] = false;
			m_keyStates[i] = false;
		}

		for (int i = 0; i < MAX_BUTTONS; i++) {
			m_buttons[i] = false;
			m_buttonStates[i] = false;
		}

		m_mouse_x = 0.0f;
		m_mouse_y = 0.0f;
	}

	Window::~Window() {
		FontManager::Clean();
		audio::AudioManager::Clean();
		physics::PhysicsManager::Clean();

		glfwTerminate();
	}

	bool Window::Init() {

		if (!glfwInit()) {
			std::cout << "Failed to initialize GLFW" << std::endl;
			return false;
		}

		m_window = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
		if (!m_window) {
			glfwTerminate();
			std::cout << "Failed to create window" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, this);

		glfwSetFramebufferSizeCallback(m_window, Window_Resize);
		glfwSetKeyCallback(m_window, Key_Callback);
		glfwSetMouseButtonCallback(m_window, Mouse_Button_Callback);
		glfwSetCursorPosCallback(m_window, Cursor_Position_Callback);

		glfwSwapInterval(0);

		if (glewInit() != GLEW_OK) {
			std::cout << "Failed to initialize GLEW" << std::endl;
			return false;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return true;
	}

	bool Window::Closed() const {
		return glfwWindowShouldClose(m_window) == 1;
	}

	void Window::Clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Window::IsKeyPressed(unsigned int keycode) const {
		if (keycode >= MAX_KEYS) {
			// TODO: Log this
			return false;
		}

		return m_keys[keycode];
	}

	bool Window::IsKeyTyped(unsigned int keycode) const {
		if (keycode >= MAX_KEYS) {
			// TODO: Log this
			return false;
		}

		return m_keyStates[keycode] && !m_keys[keycode];
	}

	bool Window::IsMouseButtonPressed(unsigned int button) const {
		if (button >= MAX_BUTTONS) {
			// TODO: Log this
			return false;
		}

		return m_buttons[button];
	}

	bool Window::IsMouseButtonClicked(unsigned int button) const {
		if (button >= MAX_BUTTONS) {
			// TODO: Log this
			return false;
		}

		return m_buttonStates[button] && !m_buttons[button];
	}

	maths::Vec2 Window::GetMousePos() const {
		return maths::Vec2(m_mouse_x, m_mouse_y);
	}

	void Window::Update() {
		memcpy(m_keyStates, m_keys, MAX_KEYS);
		memcpy(m_buttonStates, m_buttons, MAX_BUTTONS);

		GLenum error = glGetError();

		if (error != GL_NO_ERROR) {
			std::cout << "OpenGL Error : " << error << std::endl;
		}
		
		audio::AudioManager::Update();
		physics::PhysicsManager::Update();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	void Window_Resize(GLFWwindow *window,  int width, int height) {
		glViewport(0, 0, width, height);

		Window* current_window = (Window*)glfwGetWindowUserPointer(window);
		current_window->m_width = width;
		current_window->m_height = height;
	}
	
	void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* current_window = (Window*) glfwGetWindowUserPointer(window);
		current_window->m_keys[key] = (action != GLFW_RELEASE);
	}

	void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods) {
		Window* current_window = (Window*)glfwGetWindowUserPointer(window);
		current_window->m_buttons[button] = (action != GLFW_RELEASE);
	}

	void Cursor_Position_Callback(GLFWwindow* window, double xpos, double ypos) {
		Window* current_window = (Window*)glfwGetWindowUserPointer(window);
		current_window->m_mouse_x = xpos;
		current_window->m_mouse_y = ypos;
	}

}	}