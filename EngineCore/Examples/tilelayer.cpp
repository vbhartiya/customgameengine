#include "tilelayer.h"

TileLayer::TileLayer(engine::graphics::Shader* shader)
	: Layer(new engine::graphics::BatchRenderer2D(), shader, engine::maths::Mat4::Orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f))
{

}

TileLayer::~TileLayer() {

}

