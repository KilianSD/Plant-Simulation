/**
 * @file flower.cpp
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "flower.h"
#include <sqlite3.h>

Flower::Flower(sqlite3* db, const std::string& plant_name) : Plant(db, plant_name, "Flower"){

}

void Flower::startBloomNow(){
    setFloweringDate(get_current_date());
}

void Flower::startBloomAtDate(DateTime& date){
    setFloweringDate(date);
}

bool Flower::isBloomPhase(){
    return get_day_difference(get_current_date(), getFloweringDate()) > 0;
}

/**
 * @brief Construct a new Rose:: Rose object
 * 
 * @param db pointer to an opened sqlite3 database.
 */
Rose::Rose(sqlite3* db) : Flower(db, "Rose"){
    
}

void Rose::startBloomNow() {
    setFloweringDate(get_current_date());
}

void Rose::startBloomAtDate(DateTime& date){
    setFloweringDate(date);
}