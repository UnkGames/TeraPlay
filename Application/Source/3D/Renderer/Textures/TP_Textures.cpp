#include"TP_Textures.h"
#include"stb_image.h"

	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
	{
		// Load from file
		int image_width = 0;
		int image_height = 0;
		unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
		if (image_data == NULL)
			return false;

		// Create a OpenGL texture identifier
		GLuint image_texture;
		glGenTextures(1, &image_texture);
		glBindTexture(GL_TEXTURE_2D, image_texture);

		// Setup filtering parameters for display
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

		// Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
		glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
		stbi_image_free(image_data);

		*out_texture = image_texture;
		*out_width = image_width;
		*out_height = image_height;

		return true;
	}
namespace TeraPlay {



	void Textures::TextureImporter(const char* FilePath, GLuint* out_texture, int* Width, int* Hieght)
	{
		int Texture_width = 0;
		int Texture_height = 0;
		stbi_set_flip_vertically_on_load(1);

		unsigned char* Texture_Data = stbi_load(FilePath, &Texture_width, &Texture_height, NULL, 4);
		glGenTextures(1, &Texture);
		glBindTexture(GL_TEXTURE_2D, Texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // This is required on WebGL for non power-of-two textures
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Same

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Texture_width, Texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Texture_Data);
		stbi_image_free(Texture_Data);
		stbi_set_flip_vertically_on_load(0);

		*out_texture = Texture;
		*Width = Texture_width;
		*Hieght = Texture_height;
	}
	void Textures::bind(unsigned int Index) {
		glActiveTexture(GL_TEXTURE0 + Index);
		glBindTexture(GL_TEXTURE_2D, Texture);
	}

	void Textures::unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}


