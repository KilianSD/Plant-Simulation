DROP TABLE Vegetable;

CREATE TABLE Vegetable (
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

