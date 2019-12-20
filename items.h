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

#define CAPACITY 6

#define MAX_ITEM 8

#define torch (items+0)
#define match (items+1)
#define candle (items+2)
#define keys (items+3)
#define knife (items+4)
#define ring (items+5)
#define flute (items+6)
#define safe (items+7)

#define end_item (items+MAX_ITEM)

typedef struct Bag
{
    int size;
    Item ** items;
} Bag;

extern Bag bag;

#endif