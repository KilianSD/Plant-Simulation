DROP TABLE Flower;

CREATE TABLE Flower (
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

INSERT INTO Flower(common_name, scientific_name, family, kingdom, max_height, min_temperature, max_temperature, min_light, max_light, min_humidity, max_humidity, min_PH, max_PH, annual, perennial, deciduous, evergreen, bloom_time, fruit_color) VALUES
('Rose', 'Rosa', 'Rosaceae', 'Plantae', 100, 40, 85, 4, 8, 40, 70, 6, 7, 0, 1, 0, 0, 7, 'red');