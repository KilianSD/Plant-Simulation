/**
 * @file flower.h
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FLOWER_H
#define FLOWER_H

#include <string>
#include <iostream>
#include "sqlite3.h"
#include "date.h"
#include "plant.h"
#include "color.h"

class Flower : public Plant {
public:
    Color flowerColor;

    Flower(sqlite3* db, const std::string& plant_name);
    ~Flower() = default;
    
    virtual void startBloomNow();
    virtual void startBloomAtDate(DateTime& date);
    virtual bool isBloomPhase();
};

class Rose : public Flower {
public:
    Rose(sqlite3* db);
    ~Rose() = default;
    virtual void startBloomNow() override;
    virtual void startBloomAtDate(DateTime& date) override;
};

#endif