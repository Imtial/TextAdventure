#include <stdio.h>
#include "rooms.h"

static const char *tags_entry[] = {"west", "south", NULL};
static const Room *adj_entry[] = {store_room, hall_room, NULL};

static const char *tags_store[] = {"east", "north", NULL};
static const Room *adj_store[] = {entry_room, hall_room, NULL};

static const char *tags_hall[] = {"north", "south", NULL};
static const Room *adj_hall[] = {entry_room, store_room, NULL};

Room rooms[] = {{"Entry Room", "A dark long room", 2, adj_entry, tags_entry, STATE_VISIBLE},
{"Store Room", "A big messy room. Looks like a store room", 2, adj_store, tags_store, STATE_VISIBLE},
{"Hall Room", "A huge hall room, full of lights", 2, adj_hall, tags_hall, STATE_VISIBLE}};

Room * cur_loc = entry_room;
