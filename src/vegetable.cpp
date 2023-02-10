/**
 * @file vegetable.cpp
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../include/vegetable.h"

Vegetable::Vegetable(sqlite3* db, const std::string& plant_name) : Plant(db, plant_name, "Vegetable"){

}
