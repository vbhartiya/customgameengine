#include "../Source/engine.h"

using namespace engine;
using namespace graphics;
using namespace component;
using namespace maths;

class Game : public Engine {
private:
	Window* m_window;
	Layer* m_layer;
	Actor *m_mainActor, *m_floor;
public:
	Game() {

	}

	~Game() {
		delete m_layer;
		delete m_mainActor;
	}

	void Init() override {
		m_window = CreateNewWindow("Game", 960, 540);
		
		Texture *tex[] = { new Texture("test.jpg"), new Texture("test2.jpg") };
		
		m_layer = new Layer(new engine::graphics::BatchRenderer2D(), 
							new Shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag"), 
							Mat4::Orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		m_layer->SetScale(Vec2(m_window->GetWidth() / 32.0f, m_window->GetHeight() / 18.0f));

		m_mainActor = new Actor("Main Actor");
		m_mainActor->GetTransform()->SetPosition(Vec3(0, 8, 0));
		m_mainActor->GetTransform()->SetScale(Vec2(2, 1));
		
		CSprite* sprite = new CSprite(*m_layer, tex[0]);
		m_mainActor->AddComponent(sprite);

		CRigidBody* physics = new CRigidBody(1);
		m_mainActor->AddComponent(physics);

		CCollider* collider = new CCollider(Vec3(0, 0, 0), Vec3(1, 1, 0));
		m_mainActor->AddComponent(collider);
		
		m_mainActor->Start();

		m_floor = new Actor("Floor");
		m_floor->GetTransform()->SetPosition(Vec3(-16, -1, 0));
		m_floor->GetTransform()->SetScale(Vec2(32, 2));

		CSprite* floor_sprite = new CSprite(*m_layer);
		m_floor->AddComponent(floor_sprite);

		CCollider* floor_collider = new CCollider(Vec3(0, 0, 0), Vec3(1, 1, 0));
		m_floor->AddComponent(floor_collider);
	}

	void Render() override {
		m_layer->Render();
	}

	void Update(float deltaTime) override {
		m_mainActor->Update(deltaTime);
		m_floor->Update(deltaTime);
	}
}; 

int main() {
	Game game;
	game.Start();

	return 0;
}   