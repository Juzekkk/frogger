#pragma once

typedef enum {
	Start = 1,
	End = 2,
	Grass = 3,
	Road = 4,
	River = 5,
	Car = 6,
	Log = 7,
	Spawner = 8,
	Player = 9
} EntityType;

typedef enum {
	Enterable = 1,
	Unenterable = 2,
	Deadly = 3
} Interaction;

typedef enum {
	Up = 1,
	Right = 2,
	Down = 3,
	Left = 4
} Side;