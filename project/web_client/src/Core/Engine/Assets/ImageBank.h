#pragma once

namespace zw {
	class ImageBank
	{
	  public:
	    ImageBank();

	    ~ImageBank();

	    GLuint GetImage(const std::string &imageName);

	    GLuint CreateBlankImage(const std::string &uniqueImageName);

	  private:
	    void LoadImages();

	    GLuint LoadSingleImage(const std::string &absFilePath);

	    std::map<int, GLuint> m_images;

	    const std::string k_relImagesPath = "images";
	};
}
