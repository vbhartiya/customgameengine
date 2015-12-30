#include "Font.h"

namespace engine { namespace graphics {

	Font::Font(const std::string& name, const std::string& filename, unsigned int size)
		:	m_name(name), m_filename(filename), m_size(size)
	{
		m_FTAtlas = texture_atlas_new(512, 512, 2);
		m_FTFont = texture_font_new_from_file(m_FTAtlas, size, filename.c_str());
	}

}	}