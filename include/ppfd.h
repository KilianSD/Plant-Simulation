/**
 * @file ppfd.h
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief PPFD stands for 'Photosynthetic Photon Flux Density', it is a measurement of the amount of
    photosynthetically active radiation (PAR) received by a plant over a given area and time.
    PPFD is measured in micromoles of photons per square meter per second (µmol/m²/s) and is used
    to determine the quality and quantity of light that a plant is receiving. The PPFD value is crucial
    in optimizing the growth and health of plants grown in artificial lightning environments.
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PPFD_H
#define PPFD_H
#include <vector>

/**
 * @class PPFDMap
 * @brief A PPFD Map is a visual representation of the distribution of PPFD values in a specific area.
    It shows the intensity of light that plants are receiving in different parts of the growing
    area. By creating a PPFD map, growers can identify areas where their plants are receiving
    optimal light and areas that need improvement, such as adding supplemental lighting or adjusting
    the height of lights. The PPFD may helps growers make informed decisions about their growing
    operations and can result in increased plant growth and productivity.
 * 
 */
class PPFDMap {
public:
    PPFDMap(int rows, int columns);
    ~PPFDMap() = default;

    int rows;
    int columns;
    std::vector<std::vector<double>> values;
};

#endif