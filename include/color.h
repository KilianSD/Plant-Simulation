/**
 * @file color.h
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <tuple>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <random>

class RGB {
public:
    /// @brief RGB Default Constructor, sets red, green and, blue to 0.
    RGB() : red(0), green(0), blue(0){}

    /// @brief RGB Constructor, sets red, green, and blue to r, g, and b
    /// @param r red color.
    /// @param g green color.
    /// @param b blue color.
    RGB(int r, int g, int b) : red(r), green(g), blue(b){}

    /// @brief Copy Constructor, takes an already existing Color and copy its values in a new one.
    /// @param r RGB value to copy.
    RGB(const RGB& r) : red(r.red), green(r.green), blue(r.blue) {}
    
    /// @brief red color.
    int red; 
    
    /// @brief green color.
    int green; 
    
    /// @brief blue color.
    int blue;
};

class HSL {
public:
    /// @brief Default HSL Constructor, sets hue, saturation, and lightness to 0.
    HSL() : hue(0), saturation(0), lightness(0){}

    /// @brief HSL Constructor, sets hue, saturation, and lightness, to h, s, and l
    /// @param h hue value.
    /// @param s saturation value.
    /// @param l lightness value.
    HSL(double h, double s, double l) : hue(h), saturation(s), lightness(l) {}

    /// @brief HSL Copy Constructor, takes an already existing HSL color and copy its values to a new one.
    /// @param h HSL value to copy from.
    HSL(const HSL& h) : hue(h.hue), saturation(h.saturation), lightness(h.lightness) {}
    
    /// @brief hue value.
    double hue;

    /// @brief saturation value.
    double saturation;

    /// @brief lightness value.
    double lightness;
};

class HEX {
public:
    /// @brief Default HEX Constructor, sets HEX to ""
    HEX() : hex(){}

    /// @brief HEX Constructor, takes a HEX value and construct an HEX Color.
    /// @param h hex value to construct with.
    HEX(std::string h) : hex(h){}

    /// @brief hex value.
    std::string hex;
};

/* 
 *   The "Color" class in this code defines a class that represents a color with various properties and methods.
 *   The class has three constant static members (color_black, color_white, color_red, color_green, color_blue) that represent common colors.
 *   It has four constructors to create a Color object, one default constructor (Color()), and three others to create a color using RGB, HSL, or HEX values.
 *   It has a copy constructor, a destructor, and several operators (such as +, -, ==, !=, and <<) defined.
 *   The class also has various getter and setter functions to get or set the red, green, and blue values in the RGB representation, hue, saturation, and lightness values in the HSL representation, and the hexadecimal representation of the color.
 *   It also has functions to randomize a color, mix two colors, blend two colors, invert a color, darken or lighten a color, and convert between RGB, HSL, and HEX representations.
 *   The class has three private members, RGB, HSL, and HEX, which represent the color in different color spaces.
 *   There are also several private conversion functions to convert between RGB, HSL, and HEX representations.
 */

class Color {
public:
    /// @brief Common Constant Color Black
    static const Color color_black;

    /// @brief Common Constant Color White
    static const Color color_white;

    /// @brief Common Constant Color Red
    static const Color color_red;

    /// @brief Common Constant Color Green
    static const Color color_green;

    /// @brief Common Constant Color Blue
    static const Color color_blue;


    /// @brief Default Constructor, initializes R, G and B to random values
    Color();
    
    /// @brief RGB Constructor, takes a RGB color and automatically convert it to HSL and HEX.
    /// @param rgb rgb Specifies the RGB value we want to construct our color with.
    Color(RGB rgb); // RGB Constructor (should automatically convert to HSL and HEX)

    /// @brief HSL Constructor, takes a HSL value and automatically convert it to RGB and HEX.
    /// @param hsl hsl Specifies the HSL value we want to construct our color with.
    Color(HSL hsl); // HSL Constructor (should automatically convert to RGB and HEX)

    /// @brief HEX Constructor, takes a HEX value and automatically convert it into RGB and HSL.
    /// @param hex hex Specifies the HEX value we want to construct our color with.
    Color(HEX hex); // HEX Constructor (should automatically convert to RGB and HSL)


    /// @brief Copy Constructor, takes a already existing Color and copy it's values to a new Color.
    /// @param other other Specifies an already existing Color. 
    Color(const Color& other) : rgb(other.rgb), hsl(other.hsl), hex(other.hex) {}
    
    ~Color() = default;
    
    /// @brief Addition Operator for our Color class, basically add the RGB value of 2 Color classes together.
    /// @param other Color to add to the current Color.
    /// @return a new Color, with the resulting values from our addition.
    Color operator+(const Color& other) const;
    
    /// @brief Subtraction Operator for our Color class, basically subtract the RGB value of 2 Color classes together.
    /// @param other Color to subtract to the current Color.
    /// @return a new Color, with the resulting values from our subtraction
    Color operator-(const Color& other) const;

    /// @brief Equality Operator for our Color class, basically compares the RGB values of 2 Color classes together, the classes are equal if the RGB member of both is equal to each other.
    /// @param other Color to check for equality with the current Color.
    /// @return false or true depending or wether the Color were equal or not.
    bool operator==(const Color& other) const;

    /// @brief Inequality Operator for our Color class, basically compares the RGB values of 2 Color classes together, the classes are inequal if the RGB memebr of each is different.
    /// @param other Color to check for inequality with the current Color.
    /// @return false or true depending on wether the Color were inequal or not.
    bool operator!=(const Color& other) const;


    friend std::ostream& operator<<(std::ostream& os, const Color& c);
    
    
    /// @brief Getter function to retrieve the red value from our Color class.
    /// @return returns the red value as an int.
    int getRed() const { return rgb.red; }

    /// @brief Getter function to retrieve the green value from our Color class.
    /// @return returns the green value as an int.
    int getGreen() const { return rgb.green; }

    /// @brief Getter function to retrieve the blue value from our Color class.
    /// @return returns the blue value as an int.
    int getBlue() const { return rgb.blue; }

    /// @brief Getter function to retrieve the hue value from our Color class.
    /// @return returns the hue value as a double.
    double getHue() const { return hsl.hue; }

    /// @brief Getter function to retrieve the saturation value from our Color class.
    /// @return returns the saturation as a double.
    double getSaturation() const { return hsl.saturation; }

    /// @brief Getter function to retrieve the lightness value from our Color class.
    /// @return returns the lightness as a double.
    double getLightness() const { return hsl.lightness; }

    /// @brief randomize the current color fields of our Color.
    void randomizeColor();

    /// @brief Getter function to retrieve a random generated Color. 
    /// @return a new Color, with the random generated fields.
    Color getRandomColor();

    /// @brief Getter function to retrieve our Color as HEX representation.
    /// @return returns the HEX representation of our Color.
    std::string getHex() const;

    std::tuple<int, int, int> getRGB() const { return std::make_tuple(rgb.red, rgb.green, rgb.blue); }
    std::tuple<double, double, double> getHSL() const { return std::make_tuple(hsl.hue, hsl.saturation, hsl.lightness); }

    /// @brief Setter function, to change the red value (should automatically do the conversions to keep the other members up-to-date).
    /// @param r value we want to change red to.
    void setRed(int r) { rgb.red = r; convertRGBtoHSL(); convertRGBtoHEX(); }

    /// @brief Setter function, to change the green value (should automatically do the conversions to keep the other members up-to-date).
    /// @param g value we want to change green to.
    void setGreen(int g) { rgb.green = g; convertRGBtoHSL(); convertRGBtoHEX(); }

    /// @brief Setter function, to change the blue value (should automatically do the conversions to keep the other members up-to-date).
    /// @param b value we want to change blue to.
    void setBlue(int b) { rgb.blue = b; convertRGBtoHSL(); convertRGBtoHEX(); }

    /// @brief Setter function, to change the hue value (should automatically do the conversions to keep the other members up-to-date).
    /// @param h value we want to change hue to.
    void setHue(double h) { hsl.hue = h; convertHSLtoRGB(); convertRGBtoHEX(); }

    /// @brief Setter function, to change the saturation value (should automatically do the conversion to keep the other members up-to-date).
    /// @param s value we want to change saturation to.
    void setSaturation(double s) { hsl.saturation = s; convertHSLtoRGB(); convertRGBtoHEX(); }

    /// @brief Setter function, to change the lightness value (should automatically do the conversions to keep the other members up-to-date).
    /// @param l value we want to change lightness to.
    void setLightness(double l) { hsl.lightness = l; convertHSLtoRGB(); convertRGBtoHEX(); }

    /// @brief Setter function, to change the hex value (should automatically do the conversions to keep the other members up-to-date).
    /// @param h value we want to change hex to.
    void setHex(std::string h) { hex.hex = h; convertHEXtoRGB(); convertRGBtoHSL(); }
    // Other Functions
    Color mixColors(const Color& color1, const Color& color2);
    Color blendColors(const Color& other);
    
    /// @brief Invert a Color.
    void invertColor();

    /// @brief Darken a Color using the amount parameter.
    /// @param amount Amount to darken the color.
    void darken(double amount);

    /// @brief Lighten a Color using the amount parameter.
    /// @param amount Amount to lighten the color.
    void lighten(double amount);
private:
    /// @brief Color Representation as RGB.
    RGB rgb;
    /// @brief Color Representation as HSL.
    HSL hsl;
    /// @brief Color Representation as HEX.
    HEX hex;
    
    /// @brief Convert from RGB value to HSL.
    void convertRGBtoHSL();

    /// @brief Convert from HSL value to RGB.
    void convertHSLtoRGB();

    /// @brief Convert from RGB value to HEX.
    void convertRGBtoHEX();

    /// @brief Convert HEX value to RGB.
    void convertHEXtoRGB();
};

#endif