/**
 * @file plant.cpp
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "plant.h"

/**
 * @brief Construct a new Plant:: Plant object
 * 
 * @param db pointer to an opened sqlite3 database.
 * @param plant_name name of the plant to look up in the local SQL database file.
 * @param plant_type type of the plant (Fruit, Vegetable, Flower).
 */
Plant::Plant(sqlite3* db, const std::string& plant_name, const std::string& plant_type){    
    int rc;
    sqlite3_stmt *stmt;
    std::string sql = "SELECT * FROM " + plant_type + " WHERE common_name = '" + plant_name + "'"; 
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    if(rc != SQLITE_OK){
        std::cerr << "[error] SQL Error : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        exit(1);
    }


    rc = sqlite3_step(stmt);
    if(rc == SQLITE_ROW){ 
        species.common_name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        species.scientific_name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        species.family = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        species.kingdom = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        species.max_height = sqlite3_column_int(stmt, 4);
        species.min_temperature = sqlite3_column_double(stmt, 5);
        species.max_temperature = sqlite3_column_double(stmt, 6);
        species.min_light = sqlite3_column_int(stmt, 7);
        species.max_light = sqlite3_column_int(stmt, 8);
        species.min_humidity = sqlite3_column_double(stmt, 9);
        species.max_humidity = sqlite3_column_double(stmt, 10);
        species.min_PH = sqlite3_column_double(stmt, 11);
        species.max_PH = sqlite3_column_double(stmt, 12);
        species.annual = sqlite3_column_int(stmt, 13) == 1;
        species.perennial = sqlite3_column_int(stmt, 14) == 1;
        species.deciduous = sqlite3_column_int(stmt, 15) == 1;
        species.evergreen = sqlite3_column_int(stmt, 16) == 1;
        species.bloom_time = sqlite3_column_int(stmt, 17);
        species.fruit_color = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 18)));   
    } else if(rc != SQLITE_DONE){
        std::cerr << "[error] Failed to retrieve result : " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    rc = sqlite3_finalize(stmt);
    if(rc != SQLITE_OK){
        std::cerr << "[error] Failed to finalize SELECT statement : " << sqlite3_errmsg(db) << std::endl;
    }
}

/**
 * @brief Function that checks the property of a plant and
 * evaluate if it's ripe and ready to harvest.
 * 
 * @return true if the plant is ripe.
 * @return false if the plant is not ripe.
 */
// bool Plant::isRipe(){
//     return get_day_difference(get_current_date(), this->flowering_date) >= this->species.bloom_time;
// }

/**
 * @brief check if the plant needs to be fertilized based on the last_fertilized date.
 * 
 * @return true if the plant need fertilizer.
 * @return false if the plant does not need fertilizer. 
 */
// bool Plant::needsFertilizer(){
//     return get_day_difference(get_current_date(), this->last_fertilized) >= this->fertilization_schedule;
// }

/**
 * @brief check if the plant needs to be pruned based on the last_pruned date
 * 
 * @return true if the plant requires to be pruned (every 30 days).
 * @return false if the plant does not require to be prunes.
 */
// bool Plant::needsPruning(){
//     return get_day_difference(get_current_date(), this->last_pruned) > this->pruning_schedule;
// }

/**
 * @brief check if the plant needs to be watered based on the last_watered date.
 * 
 * @return true if the plant needs water. 
 * @return false if the plant does not need water.
 */
// bool Plant::needsWater(){
//     return get_day_difference(get_current_date(), this->last_watered) >= this->water_schedule;
// }