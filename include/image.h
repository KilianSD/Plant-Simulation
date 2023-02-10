#include "color.h"
#include "lodepng.h"

class Image {
public: 
    Image(size_t width, size_t height, Color& color)
        : width(width), height(height), pixels(width * height, color) {}

    size_t getWidth() const { return width; }
    size_t getHeight() const { return height; }

    Color& operator()(size_t x, size_t y) { return pixels[y * width + x]; }
    const Color& operator()(size_t x, size_t y) const { return pixels[y * width + x]; }

    void writePNG(const std::string& filename) const {
        std::vector<uint8_t> image;
        image.reserve(width * height * 4);
        for(const Color& pixel : pixels) {
            image.push_back(pixel.getRed());
            image.push_back(pixel.getGreen());
            image.push_back(pixel.getBlue());
            image.push_back(255);
        }
        unsigned error = lodepng::encode(filename, image, width, height);
        if(error) {
            std::cerr << "Error writing PNG file : " << lodepng_error_text(error) << std::endl;
        }
    }
private:
    size_t width;
    size_t height;
    std::vector<Color> pixels;
};