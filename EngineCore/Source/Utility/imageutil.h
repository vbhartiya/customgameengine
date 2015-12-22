#pragma once

#include <FreeImage/FreeImage.h>

namespace engine {

	struct ImageUtil {
		static BYTE* Load_Image(const char* filename, GLsizei* width, GLsizei*height) {
			//image format
			FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
			//pointer to the image, once loaded
			FIBITMAP *dib = nullptr;

			BYTE* pixels = nullptr;

			//check the file signature and deduce its format
			fif = FreeImage_GetFileType(filename, 0);
			//if still unknown, try to guess the file format from the file extension
			if (fif == FIF_UNKNOWN)
				fif = FreeImage_GetFIFFromFilename(filename);
			//if still unkown, return failure
			if (fif == FIF_UNKNOWN)
				return nullptr;

			//check that the plugin has reading capabilities and load the file
			if (FreeImage_FIFSupportsReading(fif))
				dib = FreeImage_Load(fif, filename);
			//if the image failed to load, return failure
			if (!dib)
				return nullptr;

			//retrieve the image data
			pixels = FreeImage_GetBits(dib);
			//get the image width and height
			*width = FreeImage_GetWidth(dib);
			*height = FreeImage_GetHeight(dib);
			int bits = FreeImage_GetBPP(dib);

			BYTE* result = new BYTE[*width * *height * (bits / 8)];
			memcpy(result, pixels, *width * *height * (bits / 8));

			//if this somehow one of these failed (they shouldn't), return failure
			if ((pixels == 0) || (width == 0) || (height == 0))
				return nullptr;

			FreeImage_Unload(dib);

			return result;
		}
	};

}
