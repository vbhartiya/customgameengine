#pragma once

#include "Utility/timer.h"

#include "Graphics/sprite.h"
#include "Graphics/window.h"
#include "Graphics/shader.h"
#include "Graphics/batchrenderer2D.h"

#include "Graphics/Layers/layer.h"

#include "Maths/Maths.h"

#include "Components/actor.h"
#include "Components/csprite.h"
#include "Components/ctransform.h"
#include "Components/crigidbody.h"
#include "Components/ccoliider.h"

namespace engine {
	class Engine {
	private: 
		graphics::Window *m_window;
		Timer *m_timer;

		unsigned int m_fps = 0;
		unsigned int m_ups = 0;

	protected:
		Engine() {

		}

		virtual ~Engine() {
			delete m_window;
			delete m_timer;
		}

		graphics::Window* CreateNewWindow(const char* name, int width, int height) {
			m_window = new graphics::Window(name, width, height);
			return m_window;
		}

		// Runs upon initialization
		virtual void Init() = 0;

		// Runs once per second
		virtual void Tick() {};

		// Runs 60 times per second 
		virtual void Update(float deltaTime) {};

		// Runs as fast as possible
		virtual void Render() = 0;

		const int GetFPS() const { return m_fps; }
		const int GetUPS() const { return m_ups; }

	public:
		void Start() {
			Init();
			Run();
		}

 	private:
		void Run() {
			m_timer = new Timer();

			float frameTimer = 0.0f;
			float updateTimer = 0.0f;
			float updateTick = 1.0f / 60.0f;
			 
			unsigned int frames = 0;
			unsigned int updates = 0;

			while (!m_window->Closed()) {
				m_window->Clear();
				Render();

				float currTime = m_timer->Elapsed();

				if (currTime - updateTimer > updateTick) {
					updateTimer += updateTick;
					updates++;
					Update(updateTick);
					m_window->Update();
				}
				
				frames++;

				if (m_timer->Elapsed() - frameTimer > 1.0f) {
					frameTimer += 1.0f;

					m_fps = frames;
					m_ups = updates;

					frames = 0;
					updates = 0;

					Tick();
				}

			}
		}
	};
}
