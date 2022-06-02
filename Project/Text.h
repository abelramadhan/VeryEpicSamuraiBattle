#ifndef TEXT_H
#define TEXT_H

#include <ft2build.h>
#include <freetype/freetype.h>
#include <map>
#include <iostream>
#include <GL/glew.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include "Shader.h"

using namespace glm;
using namespace std;

namespace Engine {
	struct Character {
		GLuint TextureID; // ID handle of the glyph texture
		ivec2 Size; // Size of glyph
		ivec2 Bearing; // Offset from baseline to left/top of glyph
		GLuint Advance; // Offset to advance to next glyph
	};

	class Text
	{
	public:
		Text(const char* fontName, Shader* shader);
		void SetFontSize(uint fontSize);
		void SetScale(float scale);
		void SetColor(float r, float g, float b);
		void Draw(string text, GLfloat x, GLfloat y);
	private:
		void Init();
		map<GLchar, Character> Characters;
		uint fontSize = 12;
		const char* fontName = NULL;
		GLuint vbo, ebo, vao;
		Shader* shader;
		vec3 color = vec3(1.0f, 1.0f, 1.0f);
		float scale;
	};

}

#endif

