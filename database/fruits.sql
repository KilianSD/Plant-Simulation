DROP TABLE Fruit;

CREATE TABLE Fruit (
    common_name         TEXT,
    scientific_name     TEXT,
    family              TEXT,
    kingdom             TEXT,
    max_height          INTEGER,
    min_temperature     REAL,
    max_temperature     REAL,
    min_light           INTEGER,
    max_light           INTEGER,
    min_humidity        REAL,
    max_humidity        REAL,
    min_PH              REAL, 
    max_PH              REAL,
    annual              INTEGER,
    perennial           INTEGER,
    deciduous           INTEGER,
    evergreen           INTEGER,
    BLOOM_TIME          INTEGER,
    fruit_color         TEXT
);

INSERT INTO Fruit(common_name, scientific_name, family, kingdom, max_height, min_temperature, max_temperature, min_light, max_light, min_humidity, max_humidity, min_PH, max_PH, annual, perennial, deciduous, evergreen, bloom_time, fruit_color) VALUES 
('Tomato', 'Solanum lycopersicum', 'Solanaceae', 'Plantae', 150, 10, 30, 5, 8, 40, 70, 5.5, 7.0, 1, 0, 0, 0, 20, 'Red'),
("Lime", "Citrus aurantifolia", "Rutaceae", "Plantae", 300, 60.0, 90.0, 1000, 5000, 40.0, 60.0, 5.0, 7.0, 0, 1, 0, 1, 0, "Green"),
("Pepper", "Capsicum annuum", "Solanaceae", "Plantae", 24, 40.0, 95.0, 1000, 5000, 40.0, 70.0, 5.5, 7.0, 0, 1, 0, 0, 0, "Red"),
("Citrus", "Citrus spp.", "Rutaceae", "Plantae", 300, 60.0, 90.0, 1000, 5000, 40.0, 60.0, 5.0, 7.0, 0, 1, 0, 1, 0, "Orange"),
("Strawberry", "Fragaria x ananassa", "Rosaceae", "Plantae", 12, 32.0, 75.0, 1000, 5000, 40.0, 70.0, 5.5, 7.0, 0, 0, 0, 0, 90, "Red"),
("Raspberry", "Rubus idaeus", "Rosaceae", "Plantae", 72, 32.0, 75.0, 1000, 5000, 40.0, 70.0, 5.5, 7.0, 0, 0, 0, 0, 90, "Red"),
("Blackberry", "Rubus fruticosus", "Rosaceae", "Plantae", 72, 32.0, 75.0, 1000, 5000, 40.0, 70.0, 5.5, 7.0, 0, 0, 0, 0, 90, "Black"),
("Pineapple", "Ananas comosus", "Bromeliaceae", "Plantae", 72, 60.0, 90.0, 1000, 5000, 40.0, 60.0, 5.0, 7.0, 0, 1, 0, 0, 0, "Yellow"),
('Banana', 'Musa', 'Musaceae', 'Plantae', 300, 50, 95, 1000, 2000, 50, 80, 5.5, 7.5, 0, 1, 0, 1, 120, 'Yellow');