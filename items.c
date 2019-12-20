#include <stdio.h>
#include <stdlib.h>
#include "items.h"

Item items[] = {{"Torch", "You can use it to lit up a room", entry_room, NULL, 10, 0},
{"Match", "You can use it to burn or lit up something", entry_room, NULL, 5, 0},
{"Candle", "You can use it to lit up a place", store_room, NULL, 10, 0},
{"Keys", "You can use it to open some lock", entry_room, NULL, 30, 0},
{"Knife", "You can use it to cut something", store_room, NULL, 20, 0},
{"Ring", "This ring bears magic", hall_room, NULL, 50, STATE_INVISIBLE},
{"Flute", "You can use it to create melody", hall_room, NULL, 40, 0},
{"Safe", "What's inside!", hall_room, ring, 0, STATE_UNPICKABLE_LOCKED}};

Bag bag = {0, NULL};