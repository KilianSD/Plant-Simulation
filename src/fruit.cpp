/**
 * @file fruit.cpp
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "fruit.h"

Fruit::Fruit(sqlite3* db, const std::string& plant_name) : Plant(db, plant_name, "Fruit"){

}

/**
 * @brief Construct a new Tomato:: Tomato object
 * 
 * @param db pointer to an opened sqlite3 database.
 */
Tomato::Tomato(sqlite3* db) : Fruit(db, "Tomato") {
}

/**
 * @brief Construct a new Strawberry:: Strawberry object
 * 
 * @param db pointer to an opened sqlite3 database.
 */
Strawberry::Strawberry(sqlite3* db) : Fruit(db, "Strawberry"){
}

/**
 * @brief Construct a new Banana:: Banana object
 * 
 * @param db pointer to an opened sqlite3 database.
 */
Banana::Banana(sqlite3* db) : Fruit(db, "Banana"){
}

/**
 * @brief Construct a new Lime:: Lime object
 * 
 * @param db pointer to an opened sqlite3 database.
 */
Lime::Lime(sqlite3* db) : Fruit(db, "Lime"){

}