-- Delete tables id they already exist
PRAGMA foreign_keys = OFF;
drop table if exists Food;
drop table if exists Nutrition;
PRAGMA foreign_keys = ON;

CREATE TABLE Food (
    PFK             CHAR(7)     NOT NULL,
    ID              INTEGER     NOT NULL,
    Derivation      TEXT,
    Name            TEXT        NOT NULL,
    Description     TEXT,
    Sampling        TEXT,
    Nitrogen        REAL,
    Fat             REAL,
    Gravity         REAL,
    Analysed        TEXT,
    Unanalysed      TEXT,
    Classification  INTEGER,
    ClassName       TEXT,
    
    PRIMARY KEY (PFK)
);

CREATE TABLE Nutrition (
    PFK             CHAR(7)     NOT NULL,
    Classification  INTEGER,
    Name            TEXT        NOT NULL,
    Energy_Fibre   INTEGER,
    Energy          INTEGER,
    Protein         REAL,
    Fat             REAL,
    Carbohydrate    REAL,
    
    PRIMARY KEY (PFK),
    FOREIGN KEY (PFK) REFERENCES Food (PFK)

    /*
    Moisture        REAL,
    Protein         REAL,
    Nitrogen        REAL,
    Fat             REAL,
    Ash             REAL,
    Fibre           REAL,
    Alcohol         REAL,
    Fructose        REAL,
    Glucose         REAL,
    Sucrose         REAL,
    Maltose         REAL,
    Lactose         REAL,
    Galactose       REAL,
    Maltotrios      REAL,
    Sugar(Total)    REAL,
    Sugar(Added)    REAL,
    Sugar(Free)     REAL,
    Starch          REAL,
    Dextrin         REAL,
    Glycerol        REAL,
    Glycogen        REAL,
    Inulin          REAL,
    Erythritol      REAL,
    Maltitol        REAL,
    Mannitol        REAL,
    Xylitol         REAL,
    Maltodextrin    REAL,
    Oligosaccharides    REAL,
    Polydextrose    REAL,
    Raffinose       REAL,
    Stachyose       REAL,
    Sorbitol        REAL,
    ResistantStarch REAL,
    Carbohydrate    REAL,
    Carbohydrate(Alcohol)   REAL,
    Acetic acid 

Citric acid 
Fumaric acid 
Lactic acid 
Malic acid
Oxalic acid 
Propionic acid 
Quinic acid 
Shikimic acid 
Succinic acid 
Tartaric acid 
Aluminium
Antimony
Arsenic
Cadmium
Calcium
Chromium
Chloride
Cobalt
Copper
Fluorid
Iodin
Iron
Lead
Magnesium
Manganese
Mercury
Molybdenum
Nickel
Phosphoru
Potassiu
Selenium
Sodium
Sulphu
Tin
Zinc
Retinol (preformed vitamin A) 
Alpha-carotene 
Beta-carotene 
Cryptoxanthin 
Beta-carotene equivalents (provitamin A) 
Vitamin A retinol equivalents 
Lutein 
Lycopene 
Xanthophyl 
Thiamin (B1) 
Riboflavin (B2) 
Niacin (B3) 
Niacin derived from tryptophan 
Niacin derived equivalents 
Pantothenic acid (B5) 
Pyridoxine (B6) 
Biotin (B7) 
Cobalamin (B12) 
Folate, natural 
Folic acid 
Total folates 
Dietary folate equivalents 
Vitamin C 
Cholecalciferol (D3) 
Ergocalciferol (D2) 
25-hydroxy cholecalciferol (25-OH D3) 
25-hydroxy ergocalciferol (25-OH D2) 
Vitamin D3 equivalents 
Alpha tocopherol 
Alpha tocotrienol 
Beta tocopherol 
Beta tocotrienol 
Delta tocopherol 
Delta tocotrienol 
Gamma tocopherol 
Gamma tocotrienol 
Vitamin E 
C4 (%T)	
C6 (%T)	
C8 (%T)	
C10 (%T)	
C11 (%T)	
C12 (%T)	
C13 (%T)	
C14 (%T)	
C15 (%T)	
C16 (%T)	
C17 (%T)	
C18 (%T)	
C19 (%T)	
C20 (%T)	
C21 (%T)	
C22 (%T)	
C23 (%T)	
C24 (%T)	
"Total saturated fatty acids, equated (%T)"	
C10:1 (%T)	
C12:1 (%T)	
C14:1 (%T)	
C15:1 (%T)	
C16:1 (%T)	
C17:1 (%T)	
C18:1 (%T)	
C18:1w5 (%T)	
C18:1w6 (%T)	
C18:1w7 (%T)	
C18:1w9 (%T)	
C20:1 (%T)	
C20:1w9 (%T)	
C20:1w13 (%T)	
C20:1w11 (%T)	
C22:1 (%T)	
C22:1w9 (%T)	
C22:1w11 (%T)	
C24:1 (%T)	
C24:1w9 (%T)	
C24:1w11 (%T)	
C24:1w13 (%T)	
"Total monounsaturated fatty acids, equated (%T)"	
C12:2 (%T)	
C16:2w4 (%T)	
C16:3 (%T)	
C18:2w6 (%T)	
C18:3w3 (%T)	
C18:3w4 (%T)	
C18:3w6 (%T)	
C18:4w1 (%T)	
C18:4w3 (%T)	
C20:2 (%T)	
C20:2w6 (%T)	
C20:3 (%T)	
C20:4 (%T)	
C20:3w3 (%T)	
C20:3w6 (%T)	
C20:4w3 (%T)	
C20:4w6 (%T)	
C20:5w3 (%T)	
C21:5w3 (%T)	
C22:2 (%T)	
C22:2w6 (%T)	
C22:4w6 (%T)	
C22:5w3 (%T)	
C22:5w6 (%T)	
C22:6w3 (%T)	
Total polyunsaturated fatty acids, equated (%T)	
Total long chain omega 3 fatty acids, equated 
Total undifferentiated fatty acids 
Total trans fatty acids, imputed 
C4 (g)	
C6 (g)	
C8 (g)	
C10 (g)	
C11 (g)	
C12 (g)	
C13 (g)	
C14 (g)	
C15 (g)	
C16 (g)	
C17 (g)	
C18 (g)	
C19 (g)	
C20 (g)	
C21 (g)	
C22 (g)	
C23 (g)	
C24 (g)	
Total saturated fatty acids, equated 
C10:1 (g)	
C12:1 (g)	
C14:1 (g)	
C15:1 (g)	
C16:1 (g)	
C17:1 (g)	
C18:1 (g)	
C18:1w5 (mg)	
C18:1w6 (mg)	
C18:1w7 (g)	
C18:1w9 (mg)	
C20:1 (g)	
C20:1w9 (mg)	
C20:1w13 (mg)	
C20:1w11 (mg)	
C22:1 (g)	
C22:1w9 (mg)	
C22:1w11 (mg)	
C24:1 (g)	
C24:1w9 (mg)	
C24:1w11 (mg)	
C24:1w13 (mg)	
Total monounsaturated fatty acids, equated 
C12:2 (g)	
C16:2w4 (mg)	
C16:3 (g)	
C18:2w6 (g)	
C18:3w3 (g)	
C18:3w4 (g)	
C18:3w6 (mg)	
C18:4w1 (g)	
C18:4w3 (mg)	
C20:2 (mg)	
C20:2w6 (mg)	
C20:3 (mg)	
C20:3w3 (mg)	
C20:3w6 (mg)	
C20:4 (g)	
C20:4w3 (mg)	
C20:4w6 (mg)	
C20:5w3 (mg)	
C21:5w3 (g)	
C22:5w3 (mg)	
C22:4w6 (mg)	
C22:2 (g)	
C22:2w6 (mg)	
C22:5w6 (g)	
C22:6w3 (mg)	
Total polyunsaturated fatty acids, equated 
Total long chain omega 3 fatty acids, equated 
Total undifferentiated fatty acids, mass basis basis 
Total trans fatty acids, imputed 
Caffeine 
Cholesterol 
Alanine 
Arginine 
Aspartic acid 
Cystine plus cysteine 
Glutamic acid 
Glycine 
Histidine 
Isoleucine 
Leucine 
Lysine 
Methionine 
Phenylalanine 
Proline 
Serine 
Threonine 
Tyrosine 
Tryptophan 
Valine 
Alanine 
Arginine 
Aspartic acid 
Cystine plus cysteine 
Glutamic acid 
Glycine 
Histidine 
Isoleucine 
Leucine 
Lysine 
Methionine 
Phenylalanine 
Proline 
Serine 
Threonine 
Tyrosine 
Tryptophan 
Valine 
 */   
);