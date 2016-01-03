#include "batchrenderer2D.h"

namespace engine {	namespace graphics {

	BatchRenderer2D::BatchRenderer2D() {
		m_indexCount = 0;

		Init();
	}

	BatchRenderer2D::~BatchRenderer2D() {
		delete m_ibo; 
		glDeleteBuffers(1, &m_vbo);
	}

	void BatchRenderer2D::Init() {
		glGenVertexArrays(1, &m_vao);
		glGenBuffers(1, &m_vbo);

		glBindVertexArray(m_vao);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
		
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_UV_INDEX);
		glEnableVertexAttribArray(SHADER_TEXID_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);

		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::vertex)));
		glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::uv)));
		glVertexAttribPointer(SHADER_TEXID_INDEX, 1, GL_FLOAT, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::texID)));
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*) (offsetof(VertexData, VertexData::color)));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		
		GLushort indices[RENDERER_INDICES_SIZE];
		for (int i = 0, offset = 0; i < RENDERER_INDICES_SIZE; i += 6, offset += 4) {
			indices[i + 0] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;
		}

		m_ibo = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

		glBindVertexArray(0);
	}

	void BatchRenderer2D::Begin() {
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		m_buffer = (VertexData *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void BatchRenderer2D::End() {
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void BatchRenderer2D::DrawString(const std::string& text, const maths::Vec3& position, const unsigned int col, Font& font, const maths::Vec2& scale) {
		using namespace ftgl;
		
		float ts = 0.0f;
		bool found = false;
		for (int i = 0; i < m_textureSlots.size(); i++) {
			if (m_textureSlots[i] == font.GetID()) {
				ts = (float)i + 1.0f;
				found = true;
				break;
			}
		}

		if (!found) {
			if (m_textureSlots.size() >= RENDERER_MAX_TEXTURES) {
				End();
				Flush();
				Begin();
			}

			m_textureSlots.push_back(font.GetID());
			ts = (float)m_textureSlots.size();
		}

		float x = position.x;

		texture_font_t* ftFont = font.GetFont();

		for (int i = 0; i < text.length(); i++) {
			char c = text[i];
			texture_glyph_t* glyph = texture_font_get_glyph(ftFont, c);
			
			if (glyph != NULL) {

				if (i > 0) {
					float kerning = texture_glyph_get_kerning(glyph, text[i - 1]);
					x += kerning * scale.x;
				}

				float x0 = x + glyph->offset_x * scale.x;
				float y0 = position.y + glyph->offset_y * scale.y;
				float x1 = x0 + glyph->width * scale.x;
				float y1 = y0 - glyph->height * scale.y;

				float u0 = glyph->s0;
				float v0 = glyph->t0;
				float u1 = glyph->s1;
				float v1 = glyph->t1;

				m_buffer->vertex = *m_transformationBack * maths::Vec3(x0, y0, 0);
				m_buffer->uv = maths::Vec2(u0, v0);
				m_buffer->texID = ts;
				m_buffer->color = col;
				m_buffer++;

				m_buffer->vertex = *m_transformationBack * maths::Vec3(x0, y1, 0);
				m_buffer->uv = maths::Vec2(u0, v1);
				m_buffer->texID = ts;
				m_buffer->color = col;
				m_buffer++;

				m_buffer->vertex = *m_transformationBack * maths::Vec3(x1, y1, 0);
				m_buffer->uv = maths::Vec2(u1, v1);
				m_buffer->texID = ts;
				m_buffer->color = col;
				m_buffer++;

				m_buffer->vertex = *m_transformationBack * maths::Vec3(x1, y0, 0);
				m_buffer->uv = maths::Vec2(u1, v0);
				m_buffer->texID = ts;
				m_buffer->color = col;
				m_buffer++;

				m_indexCount += 6;

				x += glyph->advance_x * scale.x;
			}
		}
	}

	void BatchRenderer2D::Submit(const Renderable2D *renderable) {

		if (m_indexCount >= RENDERER_INDICES_SIZE) {
			End();
			Flush();
			Begin();
		}

		const maths::Vec2 &size = renderable->GetSize();
		const maths::Vec3 &position = renderable->GetPosition();
		const unsigned int c = renderable->GetColor();
		const GLuint tid = renderable->GetTexID();

		
		const std::vector<maths::Vec2> &uv = renderable->GetUV();

		float ts = 0.0f;
		if (tid > 0) {

			bool found = false;
			for (int i = 0; i < m_textureSlots.size(); i++) {
				if (m_textureSlots[i] == tid) {
					ts = (float)i + 1.0f;
					found = true;
					break;
				}
			}

			if (!found) {
				if (m_textureSlots.size() >= RENDERER_MAX_TEXTURES) {
					End();
					Flush();
					Begin();
				}

				m_textureSlots.push_back(tid);
				ts = (float)m_textureSlots.size();
			}

		}

		m_buffer->vertex = *m_transformationBack * position;
		m_buffer->uv = uv[0];
		m_buffer->texID = ts;
		m_buffer->color = c;
		m_buffer++;

		m_buffer->vertex = *m_transformationBack * maths::Vec3(position.x, position.y + size.y, position.z);
		m_buffer->uv = uv[1];
		m_buffer->texID = ts;
		m_buffer->color = c;
		m_buffer++;

		m_buffer->vertex = *m_transformationBack * maths::Vec3(position.x + size.x, position.y + size.y, position.z);
		m_buffer->uv = uv[2];
		m_buffer->texID = ts;
		m_buffer->color = c;
		m_buffer++;

		m_buffer->vertex = *m_transformationBack * maths::Vec3(position.x + size.x, position.y, position.z);
		m_buffer->uv = uv[3];
		m_buffer->texID = ts;
		m_buffer->color = c;
		m_buffer++;

		m_indexCount += 6;
	}

	void BatchRenderer2D::Flush() {

		for (int i = 0; i < m_textureSlots.size(); i++) {
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, m_textureSlots[i]);
		}

		glBindVertexArray(m_vao);
		m_ibo->Bind();

		glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_SHORT, NULL);

		m_ibo->Unbind();
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);

		m_indexCount = 0;
		m_textureSlots.clear();
	}

}	}