DROP DATABASE IF EXISTS Entrega1;
CREATE DATABASE Entrega1;
USE Entrega1;
CREATE TABLE jugadores (
 id_jugador INTEGER PRIMARY KEY NOT NULL,
 nombre_usuario TEXT NOT NULL,
 edad INTEGER NOT NULL
)ENGINE = InnoDB;
CREATE TABLE historial (
 id_jugador INTEGER NOT NULL,
 numero_partidas INTEGER NOT NULL,
 partidas_ganadas INTEGER NOT NULL,
 beneficio_total DECIMAL(10,2) NOT NULL,
 FOREIGN KEY (id_jugador) REFERENCES jugadores(id_jugador)
)ENGINE = InnoDB;
INSERT INTO jugadores VALUES(01,'Juan',14);
INSERT INTO jugadores VALUES(02,'Maria',34);
INSERT INTO jugadores VALUES(03,'Pedro',23);
INSERT INTO jugadores VALUES(04,'Luis',18);
INSERT INTO jugadores VALUES(05,'Julia',19);
INSERT INTO historial VALUES(01,123,56,23.99);
INSERT INTO historial VALUES(02,120,80,90.50);
INSERT INTO historial VALUES(03,20,4,0.05);
INSERT INTO historial VALUES(04,70,51,50.00);
INSERT INTO historial VALUES(05,33,12,10.25);
