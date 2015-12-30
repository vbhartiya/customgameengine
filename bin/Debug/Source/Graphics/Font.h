#pragma once

#include <string>
#include "../../Ext/FreeType-GL/freetype-gl.h"

namespace engine { namespace graphics {
	class Font {
	private:
		texture_atlas_t* m_FTAtlas;
		texture_font_t* m_FTFont;
		unsigned int m_size;
		std::string m_filename;
		std::string m_name;
	public:
		Font(const std::string& name, const std::string& filename, unsigned int size);

		inline texture_font_t* GetFont() { return m_FTFont; }

		inline const unsigned int GetID() const { return m_FTAtlas->id; }
		inline const std::string& GetName() const { return m_name; }
		inline const std::string& GetFilename() const { return m_filename; }
		inline const unsigned int GetSize() const { return m_size; }
	};
}	}
