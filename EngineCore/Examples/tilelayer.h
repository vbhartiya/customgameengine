#pragma once

#include "../Source/Graphics/Layers/layer.h"
#include "../Source/Graphics/batchrenderer2D.h"

class TileLayer : public engine::graphics::Layer {
public:
	TileLayer(engine::graphics::Shader* shader);
	virtual ~TileLayer();
};