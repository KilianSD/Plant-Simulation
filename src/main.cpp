/**
 * @file main.cpp
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief A gardening journal application that allows a user to keep track of their plants, including information such as planting date, location, and care instructions.
 * @version 0.1
 * @date 2023-02-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../include/plants_include.h"
#include "../include/date.h"
#include "../include/color.h"
#include "../include/image.h"
#include <dpp/dpp.h>
#include "../include/discord.h"
#include <memory>
#include <chrono>
#include <thread>

/**
 * @brief open local SQLite3 database so we can work with data appropriately.
 * 
 * @return returns sqlite3* if the database was successfully opened, else exit the program. 
 */
sqlite3* open_db(){
    sqlite3* db;
    int rc = sqlite3_open("../../database/species.db", &db);
    if(rc){
        std::cerr << "[error] Can't open database : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        exit(-1);
    }
    std::cout << "DATABASE OPENED !" << std::endl;
    return db;
}

int main(int argc, char** argv){
    // open database connection so we don't have to do it on every single Fruit/Vegetables Class definition.
    sqlite3* db = open_db();
    DateTime CurrentDate = get_current_date();

    DiscordUser discordUser;
    Color col;
    while(true){
        for(int i = 0; i < 10; i++){
            Image image(256, 256, col);
            image.writePNG("colors/" + col.getHex() + ".png");
            discordUser.sendWebhookMessageColor(col);
            col.randomizeColor();
        }
        std::this_thread::sleep_for(std::chrono::seconds(20));
    }
    Color c;

    std::cout << "Color (Before Random Generation) (RGB) : (" << c.getRed() << ", " << c.getGreen() << ", " << c.getBlue() << ")" << "\n";
    std::cout << "Color (Before Random Generation) (HSL) : (" << c.getHue() << ", " << c.getSaturation() << ", " << c.getLightness() << ")" << "\n";
    std::cout << "Color (Before Random Generation) (HEX) : (" << c << ")" << std::endl;
    c.randomizeColor();
    std::cout << "Generated Color (RGB) : (" << c.getRed() << ", " << c.getGreen() << ", " << c.getBlue() << ")" << "\n";
    std::cout << "Generated Color (HSL) : (" << c.getHue() << ", " << c.getSaturation() << ", " << c.getLightness() << ")" << "\n";
    std::cout << "Generated Color (HEX) : (" << c << ")" << std::endl;

    if(Color::color_black == Color::color_white) {
        std::cout << "Black and White are equal !" << std::endl;
    } else {
        std::cout << "Black and White are different !" << std::endl;
    }

    std::unique_ptr<Rose> r = std::make_unique<Rose>(db);
    r->startBloomAtDate(DateTime(2023, 1, 1, 0, 0, 0));
    if(r->isBloomPhase()) std::cout << "Rose is Blooming !" << std::endl;
    // std::unique_ptr<Tomato> t = std::make_unique<Tomato>(db);
    // std::unique_ptr<Banana> b = std::make_unique<Banana>(db);
    // std::unique_ptr<Lime> l = std::make_unique<Lime>(db);
    // std::unique_ptr<Strawberry> s = std::make_unique<Strawberry>(db);
    // std::unique_ptr<Rose> r = std::make_unique<Rose>(db);

    // std::cout << "----------[BANANA]----------\n" << b->getSpecies() << std::endl;
    // std::cout << "----------[TOMATO]----------\n" << t->getSpecies() << std::endl;
    // std::cout << "----------[LIME]----------\n" << l->getSpecies() << std::endl;
    // std::cout << "----------[STRAWBERRY]----------\n" << s->getSpecies() << std::endl;
    // std::cout << "----------[ROSE]----------\n" << r->getSpecies() << std::endl;

    return 0;
}

