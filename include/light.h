/**
 * @file light.h
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "ppfd.h"
#include <string>


class Light {
public:     
    // Constructors & Destructors
    ~Light() = default;
    Light(double intensity_PAR, std::string spectrum, int duration_hr) : intensity_PAR(intensity_PAR), spectrum(spectrum), duration_hr(duration_hr) { }

    // Getter Functions
    double getIntensityPAR() const { return intensity_PAR; }
    double getIntensityPER() const { return intensity_PER; }
    std::string getSpectrum() const { return spectrum; }
    int getDurationHr() const { return duration_hr; }
    std::string getLightModel() const { return lightModel; }
    //PPFDMap getLightMap() const { return lightMap; }
    
    // Setter Functions
    void setIntensityPAR(double PAR) { intensity_PAR = PAR; }
    void setIntensityPER(double PER) { intensity_PER = PER; }
    void setSpectrum(std::string spectrum) { this->spectrum = spectrum; }
    void setDurationHr(int duration) { duration_hr = duration; }
    void setLightModel(std::string lightModel) { this->lightModel = lightModel; }
    //void setLightMap(PPFDMap map) { lightMap = map; }
private:
    /// @brief model of the lamp (e.g Mars Hydro TS1000)
    std::string lightModel;
    /// @brief PPFD Map for the model lamp (not required but useful).
    //PPFDMap lightMap;
    /// @brief intensity of the light in PAR.
    double intensity_PAR;
    /// @brief intensity of the light in percentage (if light dimmable, else it will always be at 100%).
    double intensity_PER; 
    /// @brief spectrum of the light (e.g Full Spectrum, Red Spectrum...)
    std::string spectrum;
    /// @brief duration per day in hour in which the light will be turned on.
    int duration_hr;
};

// class Light{
//     /// @brief Name of the light (e.g : Mars Hydro TS1000).
//     std::string lightModel;
    
//     /// @brief PAR Map for the light model.
//     PPFDMap lightMap;
    
//     /// @brief light intensity in PAR (Photosynthetic Active Radiation).
//     unsigned int intensity_PAR; 
    
//     /// @brief light intensity in percentage (Useful for Dimmable Lights).
//     double intensity_PERCENT;
    
//     /// @brief light distance from plant (in inches).
//     double lightDistanceFromPlant;
    
//     /// @brief PPFD received by the plant.
//     double ppfd;

//     /// @brief the following function calculate the PPFD recevied by a plant this might be better to implement this somewhere else.
//     void calculatePPFD(){ this->ppfd = this->lightIntensity / (this->lightDistanceFromPlant * this->lightDistanceFromPlant); }
    
//     /// @brief Light Constructor, requires the light model.
//     /// @param lightModel Name of the light (e.g : Mars Hydro TS1000).
//     Light(std::string lightModel);
    
//     /// @brief Light Constructor with PPFD Map specifications.
//     /// @param lightModel Name of the light (e.g : Mars Hydro TS1000).
//     /// @param rows PPFD Map rows number.
//     /// @param columns PPFD Map columns number.
//     Light(std::string lightModel, unsigned int rows, unsigned int columns);
// };



#endif