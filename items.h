#ifndef ITEMS_H
#define ITEMS_H

#include "rooms.h"

typedef struct Item
{
    char * name;    // name of the item
    char * description; // details of the item
    Room * location;    // location or room where the item exists
    struct Item * item;    // item can hold item( A safe can hold items)
    int point;  // point for the item
    int state;  // item's function depends on the state
} Item;

extern Item items[];

#define torch (&items+0)
#define match (&items+1)
#define candle (&items+2)
#define keys (&items+3)
#define knife (&items+4)
#define ring (&items+5)
#define flute (&items+6)
#define blue_ball (&items+7)
#define red_ball (&items+8)
#define green_ball (&items+9)
#define diamond (&items+10)
#define spell_card (&items+11)
#define jar (&items+12)
#define jonaki (&items+13)
#define locket (&items+14)
#define inv_cloak (&items+15)
#define safe (&items+16)
#define grandchild (&items+17)

#define MAX_ITEM 18

#endif