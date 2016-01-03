#include "../Source/engine.h"
#include "cinput.h"

using namespace engine;
using namespace graphics;
using namespace component;
using namespace maths;

class Game : public Engine {
private:
	Window* m_window;
	Layer* m_layer;
	Scene* m_mainScene;
	float angle = 0;
public:
	Game() {

	}

	~Game() {
		delete m_mainScene;
	}

	void Init() override {
		m_window = CreateNewWindow("Game", 960, 540);
		m_window->SetBackgroundColor(Vec4(1, 0.85f, 0.85f, 1));
		
		m_layer = new Layer(new engine::graphics::BatchRenderer2D(), 
							new Shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag"), 
							Mat4::Orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		m_layer->SetScale(Vec2(32.0f/m_window->GetWidth(), 18.0f/ m_window->GetHeight()));

		m_mainScene = new Scene("Main", "scene.xml", m_layer);

		m_mainScene->Start();
	}

	void Render() override {
		m_layer->Render();
	}

	void Update(float deltaTime) override {

		m_mainScene->Update(deltaTime);
	}
}; 
/*
int main() {
	Game game;
	game.Start();

	return 0;
}*/