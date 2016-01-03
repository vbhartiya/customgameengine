#include <vector>
#include <time.h>

#include "Source/Maths/maths.h"
#include "Source/Utility/fileutil.h"
#include "Source/Utility/timer.h"


#include "Source/Graphics/Layers/layer.h"

#include "Source/Graphics/window.h"
#include "Source/Graphics/shader.h"
#include "Source/Graphics/batchrenderer2D.h"
#include "Source/Graphics/sprite.h"
#include "Source/Graphics/texture.h"
#include "Source/Graphics/label.h"
#include "Source/Graphics/fontmanager.h"
#include "Source/Graphics/shader.h"

#include "Source/Audio/audiomanager.h"

#include "Source/Graphics/Buffers/buffer.h"
#include "Source/Graphics/Buffers/indexbuffer.h"
#include "Source/Graphics/Buffers/vertexarray.h"

#include "Source/Graphics/Layers/group.h"

#include "Ext/GorillaAudio/src/gorilla/ga.h"
#include "Ext/GorillaAudio/src/gorilla/gau.h"

#include <FreeImage/FreeImage.h>

#include "Ext/TinyXML/tinyxml2.h"
#include <map>

#if 0
int main() {

	using namespace engine;
	using namespace graphics;
	using namespace audio;
	using namespace maths;

	Window* window = Window::GetWindow("Engine", 800, 450);

	glClearColor(0.2f, 0.3f, 0.9f, 1.0f);

	//Texture *tex[] = { new Texture("test.jpg"), new Texture("test2.jpg") };

	//int texIDs[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Shader* shader = new Shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	//shader->Enable();
	//shader->SetUniform1iv("tex", texIDs, 10);

	Layer layer(new BatchRenderer2D(), shader, Mat4::Orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
	//Group *transformation = new Group(Mat4::Translation(Vec3(5, 3, 0)) * Mat4::Rotation(45, Vec3(0, 0, 1)));
	//layer.Add(transformation);

	layer.SetScale(Vec2(32.0f / 800, 18.0f / 450));

	float increment = 2.0f;

	for (float y = -9.0f; y < 9.0f; y+=increment) {
		for (float x = -16.0f; x < 16.0f; x+= increment*16.0f/12.0f) {
			//layer.Add(new Sprite(x, y, increment*16.0f / 12.0f, increment, tex[rand()%2]));
		}
	}

	FontManager::Add(new Font("arial", "arial.ttf", 200));

	Group* fpsGroup = new Group(Mat4::Translation(Vec3(-0.0f, 0.0f, 0.0f)));
	Label* fps = new Label("A", 0.2f, 0.2f, 0xFFFFFFFF, "arial", 200);

	fpsGroup->Add(new Sprite(0, 0, 6, 1.3f, Vec4(0.1f, 0.1f, 0.1f, 0.8f)));
	fpsGroup->Add(fps);

	layer.Add(fpsGroup);


	std::cout << "Drawing " << 18.0f / increment * 32.0f / (increment * 16.0f / 12.0f) << " Sprites" << std::endl;

	AudioManager::Add(new Sound("Triumph", "Triumph.wav"));
	//AudioManager::Get("Triumph")->Play();
		
	Timer timer;
	float time = 0.0f;
	unsigned int frames = 0;

	while (!window->Closed()) {
		window->Clear();
		
		layer.Render();

		shader->Disable();

		window->Update();

		frames++;

		if (timer.Elapsed() - time > 1.0f) {
			time = timer.Elapsed();
			//printf("%d fps\n", frames);
			//fps->SetText(std::to_string(frames) + " FPS");
			frames = 0;
		}		
	}

	for (int i = 0; i < 2; i++) {
//		delete tex[i];
	}

	return 0;
}
#endif