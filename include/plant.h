/**
 * @file plant.h
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <iostream>
#include <sqlite3.h>
#include "date.h"
#include "species.h"

/**
 * @class Plant
 * @brief A class for representing a Plant.
 * 
 * This class provides a convenient way to store and manipulate plant data.
 * 
 */
class Plant {
public:
    // Constructors & Destructors
    Plant(sqlite3* db, const std::string& plant_name, const std::string& plant_type);
    ~Plant() = default;
    // Getter Functions
    std::string getName() const { return name; }
    std::string getNote() const { return note; }
    Species getSpecies() const { return species; }
    unsigned int getAge() const { return age; }
    unsigned int getHeight() const { return height; }
    unsigned int getWidth() const { return width; }
    int getTemperature() const { return temperature; }
    int getHumidity() const { return humidity; }
    double getPH() const { return PH; }
    DateTime getPlantedDate() const { return planted_date; }
    DateTime getFloweringDate() const { return flowering_date; }
    DateTime getLastWatered() const { return last_watered; }
    DateTime getLastFertilized() const { return last_fertilized; }
    DateTime getLastPruned() const { return last_pruned; }
    DateTime getHarvestStartDate() const { return harvest_start_date; }
    DateTime getHarvestEndDate() const { return harvest_end_date; }
    unsigned int getWaterSchedule() const { return water_schedule; }
    unsigned int getFertilizationSchedule() const { return fertilization_schedule; }
    unsigned int getPruningSchedule() const { return pruning_schedule; }
    int getPlantAge() const { return get_day_difference(get_current_date(), planted_date); }
    // Setter Functions
    void setAge(int age) { this->age = age; }
    void setNote(std::string note) { this->note = note; }
    void setTemperature(int temperature) { this->temperature = temperature; }
    void setHumidity(int humidity) { this->humidity = humidity; }
    void setPH(double PH) { this->PH = PH; }
    void setHeight(unsigned int height) { this->height = height; }
    void setWidth(unsigned int width) { this->width = width; }
    void setWaterSchedule(unsigned int water_schedule) { this->water_schedule = water_schedule; }
    void setFertilizationSchedule(unsigned int fertilization_schedule) { this->fertilization_schedule = fertilization_schedule; }
    void setPruningSchedule(unsigned int pruning_schedule) { this->pruning_schedule = pruning_schedule; }
    void setFloweringDate(DateTime& date) { this->flowering_date = date; }
    // Virtual Functions
    // virtual bool isRipe() = 0; // the fact of putting = 0 after the virtual function declaration says that we want it to be a pure virtual function that is defined to be overwritten.
    // virtual bool needsWater() = 0;
    // virtual bool needsFertilizer() = 0;
    // virtual bool needsPruning() = 0;
private:
    sqlite3* db;
    std::string name;
    std::string note;
    Species species; 
    unsigned int age;
    unsigned int height;
    unsigned int width;
    int temperature;
    int humidity;
    double PH;
    /// @brief date of which the plant was planted.
    DateTime planted_date;
    /// @brief date of which flowering was induced.
    DateTime flowering_date;
    /// @brief last watered date.
    DateTime last_watered;
    /// @brief last fertilized date.
    DateTime last_fertilized;
    /// @brief last pruned date.
    DateTime last_pruned;
    /// @brief date where the harvest was started.
    DateTime harvest_start_date;
    /// @brief date where the harvest was finished.
    DateTime harvest_end_date;
    /// @brief water schedule in days. (e.g : 5)
    unsigned int water_schedule; 
    /// @brief fertilization schedule in days. (e.g 5)
    unsigned int fertilization_schedule;
    /// @brief pruning schedule in days. (e.g 30)
    unsigned int pruning_schedule;
};

#endif