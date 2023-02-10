/**
 * @file species.h
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SPECIES_H
#define SPECIES_H

#include <string>
#include <iostream>

/**
 * @brief the Species class represents informations about various plants.
 * 
 */
class Species {
public:
    std::string common_name;
    std::string scientific_name;
    std::string family;
    std::string kingdom;
    int max_height;
    double min_temperature;
    double max_temperature;
    int min_light;
    int max_light;
    double min_humidity;
    double max_humidity;
    double min_PH;
    double max_PH;
    bool annual;
    bool perennial;
    bool deciduous;
    bool evergreen;
    int bloom_time;
    std::string fruit_color;

    friend std::ostream& operator<<(std::ostream& os, const Species species){
        os << "common_name: " << species.common_name << std::endl;
        os << "scientific_name: " << species.scientific_name << std::endl;
        os << "family: " << species.family << std::endl;
        os << "kingdom: " << species.kingdom << std::endl;
        os << "max_height: " << species.max_height << std::endl;
        os << "min_temperature: " << species.min_temperature << std::endl;
        os << "max_temperature: " << species.max_temperature << std::endl;
        os << "min_light: " << species.min_light << std::endl;
        os << "max_light: " << species.max_light << std::endl;
        os << "min_humidity: " << species.min_humidity << std::endl;
        os << "max_humidity: " << species.max_humidity << std::endl;
        os << "min_PH: " << species.min_PH << std::endl;
        os << "max_PH: " << species.max_PH << std::endl;
        os << "annual: " << species.annual << std::endl;
        os << "perennial: " << species.perennial << std::endl;
        os << "deciduous: " << species.deciduous << std::endl;
        os << "evergreen: " << species.evergreen << std::endl;
        os << "bloom_time: " << species.bloom_time << std::endl;
        os << "fruit_color: " << species.fruit_color << std::endl;
        return os;
    }
};

#endif