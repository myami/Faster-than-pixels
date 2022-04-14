DROP TABLE IF EXISTS player_stats;
DROP TABLE IF EXISTS achievements;
DROP TABLE IF EXISTS player_achievements;

CREATE TABLE player_stats(
	id 			INTEGER 		NOT NULL AUTO_INCREMENT,
	pseudonyme 	VARCHAR(16) 	NOT NULL,
	mdp 		VARCHAR 		NOT NULL,
	mail 		VARCHAR 		NOT NULL,
	experience	FLOAT 			NOT NULL,
	interceptor	INTEGER			NOT NULL,
	bomber		INTEGER			NOT NULL,
	fighter		INTEGER			NOT NULL,
	carrier		INTEGER			NOT NULL,
	missions	INTEGER			NOT NULL,
	castaway	INTEGER			NOT NULL,
	PRIMARY KEY (id)
);

CREATE TABLE achievements(
	id 			INTEGER		NOT NULL AUTO_INCREMENT,
	nom 		VARCHAR		NOT NULL,
	description	VARCHAR		NOT NULL,
	PRIMARY KEY (id)
);

CREATE TABLE player_achievements(
	id 			INTEGER		NOT NULL AUTO_INCREMENT,
	player 		INTEGER		NOT NULL,
	achievement	INTEGER		NOT NULL,
	obtention	DATE		NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (player) REFERENCES player_stats(id),
	FOREIGN KEY (achievement) REFERENCES achievements(id)
);

CREATE TABLE highscore(
	id 			INTEGER		NOT NULL AUTO_INCREMENT,
	seed 		VARCHAR		NOT NULL,
	score 		FLOAT		NOT NULL,
	player 		INTEGER		NOT NULL,
	PRIMARY KEY(id),
	FOREIGN KEY (player) REFERENCES player_stats(id)
);
