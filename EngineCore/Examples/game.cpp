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
		delete m_layer;
	}

	void Init() override {
		m_window = CreateNewWindow("Game", 960, 540);
		
		m_layer = new Layer(new engine::graphics::BatchRenderer2D(), 
							new Shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag"), 
							Mat4::Orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		m_layer->SetScale(Vec2(m_window->GetWidth() / 32.0f, m_window->GetHeight() / 18.0f));

		m_mainScene = new Scene("Main");
		/*
		Actor* m_mainActor = new Actor("Main Actor");
		m_mainActor->GetTransform()->SetPosition(Vec3(0, 0, 0));
		m_mainActor->GetTransform()->SetScale(Vec2(1,1));

		CSprite* sprite = new CSprite(Vec4(1, 0.6f, 0.6f, 1));
		m_mainActor->AddComponent(sprite, m_layer);

		CRigidBody* physics = new CRigidBody(1);
		m_mainActor->AddComponent(physics);

		CCollider* collider = new CCollider(Vec3(0.5f, 0.5f, 0), Vec3(1, 1, 0));
		m_mainActor->AddComponent(collider);
		
		m_mainActor->Start();

		Actor* m_floor = new Actor("Floor");
		m_floor->GetTransform()->SetPosition(Vec3(-16, -9, 0));
		m_floor->GetTransform()->SetScale(Vec2(32, 1));

		CSprite* floor_sprite = new CSprite(Vec4(1.0f,0.4f,0.4f,1));
		m_floor->AddComponent(floor_sprite, m_layer);

		CCollider* floor_collider = new CCollider(Vec3(0.5f, 0.5f, 0), Vec3(1, 1, 0));
		m_floor->AddComponent(floor_collider);

		m_mainScene->Add(m_mainActor);
		m_mainScene->Add(m_floor);
		*/

		tinyxml2::XMLDocument doc;
		doc.LoadFile("scene.xml");

		m_mainScene->Add(ActorFactory::CreateActorFromXML(doc.FirstChildElement()->FirstChildElement(), m_layer));
		m_mainScene->Add(ActorFactory::CreateActorFromXML(doc.FirstChildElement()->FirstChildElement()->NextSiblingElement(), m_layer));
	}

	void Render() override {
		m_layer->Render();
	}

	void Update(float deltaTime) override {
		/*float axis = 0;

		if (m_window->IsKeyPressed(GLFW_KEY_D))
			axis = 1;
		else if (m_window->IsKeyPressed(GLFW_KEY_A))
			axis = -1;

		if(m_window->IsKeyTyped(GLFW_KEY_SPACE))
			m_mainActor->GetRigidBody()->AddForce(Vec3(0, abs(axis) * 300, 0));

		m_mainActor->GetTransform()->Translate(Vec3(axis * 0.1f, 0, 0));
		m_mainActor->GetTransform()->SetRotation(Vec3(0, 0, Sign(axis) * m_mainActor->GetRigidBody()->GetVelocity().y));
		*/

		m_mainScene->Update(deltaTime);
	}
}; 

int main() {
	Game game;
	game.Start();

	return 0;
}