/**
 * @file color.cpp
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "color.h"

const Color Color::color_black = Color(RGB(0, 0, 0));
const Color Color::color_white = Color(RGB(255, 255, 255));
const Color Color::color_red = Color(RGB(255, 0, 0));
const Color Color::color_blue = Color(RGB(0, 255, 0));
const Color Color::color_green = Color(RGB(0, 0, 255));


/// @brief Add two colors with a maximum value limit of 255 and a minimum value limit of 0
/// @param other the color we want to add to the current class values
/// @return returns a Color object
Color Color::operator+(const Color& other) const {
    return Color(RGB((rgb.red + other.rgb.red) % (255 + 1), (rgb.green + other.rgb.green) % (255 + 1), (rgb.blue + other.rgb.blue) % (255 + 1)));
}

/// @brief Substract two colors with a maximum value limit of 255 and a minimum value limit of 0
/// @param other the color we want to add to the current class values
/// @return returns a Color object
Color Color::operator-(const Color& other) const {
    return Color(RGB((rgb.red - other.rgb.red) % (255 + 1), (rgb.green - other.rgb.green) % (255 + 1), (rgb.blue - other.rgb.blue) % (255 + 1)));
}

/// @brief Verify if two colors are equal, two colors are equal if the R, G and B values are equal.
/// @param other the Color object we want to compare with
/// @return true if they are equal, otherwise returns false
bool Color::operator==(const Color& other) const {
    return rgb.red == other.rgb.red && rgb.blue == other.rgb.blue && rgb.green == other.rgb.green;
}

/// @brief Verify if two colors are different, two colors are different if atleast one value of R, G or B are unequal 
/// @param other the Color object we want to compare with
/// @return true if they are different, otherwise returns false
bool Color::operator!=(const Color& other) const {
    return rgb.red != other.rgb.red || rgb.blue != other.rgb.blue || rgb.green != other.rgb.green;
}

/// @brief Color class default constructor, since we do no specify any value for R, G, or B we decided to randomly generate one. This could be modified in the future for a white blank color (0, 0, 0).
Color::Color(){
    // For now, we'll set that our default constructor chooses a random color.
    randomizeColor();
    convertRGBtoHEX();
    convertRGBtoHSL();
}

/// @brief Color class RGB constructor
/// @param r RGB value (RGB)
Color::Color(RGB r) : rgb(r) {
    convertRGBtoHEX();
    convertRGBtoHSL();
}

/// @brief Color class HSL constructor
/// @param h HSL value (HSL)
Color::Color(HSL h) : hsl(h) {
    convertHSLtoRGB();
    convertRGBtoHEX();
}

/// @brief Color class HEX constructor
/// @param h HEX value (std::string)
Color::Color(HEX h) : hex(h){
    convertHEXtoRGB();
    convertRGBtoHSL();
}

/// @brief Output a Color using it's hex representation
/// @param os stream
/// @param c Color
/// @return stream
std::ostream& operator<<(std::ostream& os, const Color& c){
    return os << c.getHex();
}


Color Color::mixColors(const Color& color1, const Color& color2){
    return Color(RGB(((color1.rgb.red + color2.rgb.red) / 2) % (255 + 1), ((color1.rgb.green + color2.rgb.green) / 2) % (255 + 1), ((color1.rgb.blue + color2.rgb.blue) / 2) % (255 + 1)));
}

Color Color::blendColors(const Color& other) {
    return Color(RGB(((this->rgb.red + other.rgb.red) / 2) % (255 + 1), ((this->rgb.green + other.rgb.green) / 2) % (255 + 1), ((this->rgb.blue + other.rgb.blue) / 2) % (255 + 1)));
}

std::string padHexString(int value){
    std::stringstream hexStream;
    hexStream << std::setfill('0') << std::setw(2) << std::hex << value;
    return hexStream.str();
}

std::string Color::getHex() const {
    std::stringstream hexStream;
    hexStream << "#" << padHexString(rgb.red) << padHexString(rgb.green) << padHexString(rgb.blue);
    return hexStream.str();
}

void Color::randomizeColor() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    rgb.red = dis(gen);
    rgb.green = dis(gen);
    rgb.blue = dis(gen);
    convertRGBtoHEX();
    convertRGBtoHSL();
}

Color Color::getRandomColor(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    return Color(RGB(dis(gen), dis(gen), dis(gen)));
}

void Color::invertColor(){
    rgb.red -= 255;
    rgb.green -= 255;
    rgb.blue -= 255;
}

void Color::convertRGBtoHSL(){
    double r = rgb.red / 255.0;
    double g = rgb.green / 255.0;
    double b = rgb.blue / 255.0;

    double max = r;
    max = std::max(max, g);
    max = std::max(max, b);
    double min = r;
    min = std::min(min, g);
    min = std::min(min, b);
    double delta = max - min;

    hsl.lightness = (max + min) / 2;

    if(delta == 0){
        hsl.hue = 0;
        hsl.saturation = 0;
    } else {
        hsl.saturation = delta / (1 - fabs(2 * hsl.lightness - 1));

        double hue_temp;
        if(max == r){
            hue_temp = (g - b) / delta + (g < b ? 6 : 0);
        } else if (max == g){
            hue_temp = (b - r) / delta + 2;
        } else {
            hue_temp = (r - g) / delta + 4;
        }
        hsl.hue = hue_temp / 6;
    }

    hsl.hue *= 360;
    hsl.saturation *= 100;
    hsl.lightness *= 100;

}

double hueToRGB(double p, double q, double t){
    if(t < 0) t += 1;
    if(t > 1) t -= 1;
    if(t < 1/6) return p + (q - p) * 6 * t;
    if(t < 1/2) return q;
    if(t < 2/3) return p + (q - p) * (2/3 - t) * 6;
    return p;
}

void Color::convertHSLtoRGB(){
    double r, g, b;

    if(hsl.saturation == 0){
        r = g = b = hsl.lightness;
    } else {
        double q = (hsl.lightness < 0.5) ? hsl.lightness * (1 + hsl.saturation) : hsl.lightness + hsl.saturation - hsl.lightness * hsl.saturation;
        double p = 2 * hsl.lightness - q;
        r = hueToRGB(p, q, hsl.hue + 1/3);
        g = hueToRGB(p, q, hsl.hue);
        b = hueToRGB(p, q, hsl.hue - 1/3);
    }

    rgb.red = static_cast<int>(r * 255);
    rgb.green = static_cast<int>(g * 255);
    rgb.blue = static_cast<int>(b * 255);
}


void Color::convertRGBtoHEX() {
    std::stringstream ss;
    ss << std::hex << (rgb.red << 16 | rgb.green << 8 | rgb.blue);
    hex = ss.str();
}

void Color::convertHEXtoRGB() {
    hex.hex = hex.hex.substr(hex.hex.find_first_of('#') + 1);
    rgb.red = (int)strtol(hex.hex.substr(0, 2).c_str(), nullptr, 16);
    rgb.green = (int)strtol(hex.hex.substr(2, 2).c_str(), nullptr, 16);
    rgb.blue = (int)strtol(hex.hex.substr(4, 2).c_str(), nullptr, 16);
}

void Color::darken(double amount){
    hsl.lightness -= amount;
    hsl.lightness = std::max(0.0, std::min(hsl.lightness, 1.0));
    convertHSLtoRGB();
    convertRGBtoHEX();
}

void Color::lighten(double amount){
    hsl.lightness += amount;
    hsl.lightness = std::max(0.0, std::min(hsl.lightness, 1.0));
    convertHSLtoRGB();
    convertRGBtoHEX();
}