/**
 * @file fruit.h
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FRUIT_H
#define FRUIT_H

#include <string>
#include <iostream>
#include <sqlite3.h>
#include "date.h"
#include "plant.h"
#include "color.h"

class Fruit : public Plant {
public:
    unsigned int fruitCount;
    Color fruitColor;
    
    Fruit(sqlite3* db, const std::string& plant_name);
    ~Fruit() = default;

    // virtual void growFruit();
    // virtual bool isFruitRipe();
};

class Tomato : public Fruit {
public:
    Tomato(sqlite3* db);
    ~Tomato() = default;
};

class Strawberry : public Fruit {
public:
    Strawberry(sqlite3* db);
    ~Strawberry() = default;
};

class Banana : public Fruit {
public:
    Banana(sqlite3* db);
    ~Banana() = default;
};

class Lime : public Fruit {
public: 
    Lime(sqlite3* db);
    ~Lime() = default;
};

#endif