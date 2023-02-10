/**
 * @file vegetable.h
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VEGETABLE_H
#define VEGETABLE_H


#include <string>
#include <iostream>
#include "sqlite3.h"
#include "date.h"
#include "plant.h"
#include "color.h"

class Vegetable : public Plant {
public:
    unsigned int vegetableCount;
    Color vegetableColor;

    // virtual void growVegetable();
    // virtual bool isVegetableRipe();

    Vegetable(sqlite3* db, const std::string& plant_name);
    ~Vegetable() = default;
};

#endif