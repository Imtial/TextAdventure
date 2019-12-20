#ifndef ROOMS_H
#define ROOMS_H

#define MAX_ROOM    8

#define STATE_INVISIBLE -9999
#define STATE_UNAVAILABLE   -1
#define STATE_UNPICKABLE_LOCKED     -2
#define STATE_UNPICKABLE_UNLOCKED   -3
#define STATE_VISIBLE   0
#define STATE_DARK  -1000
#define STATE_OK    0

typedef struct Room
{
    char * name;
    char * description;
    int n_doors;
    struct Room ** adj_rooms;
    char ** adj_tags;
    int state;
} Room;

extern Room rooms[];

#define entry_room (rooms+0)
#define store_room (rooms+1)
#define hall_room (rooms+2)

#define end_of_rooms (rooms+3)

extern Room * cur_loc;

#endif