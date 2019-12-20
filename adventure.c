#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "items.h"

#define true 1
#define false 0

int points = 0;
char input[50] = "look around";

int get_bag_item_index(Item * it)
{
    if(it == NULL) return -1;
    for(int i=0; i<bag.size; i++) if(bag.items[i] == it) return i;
    return -1;
}

void execute_go(char * noun)
{
    for(int i=0; cur_loc->adj_tags[i] != NULL; i++)
    {
        if(strcmp(noun, cur_loc->adj_tags[i]) == 0)
        {
            printf("%s\n", (cur_loc->adj_rooms[i])->name);
            cur_loc = cur_loc->adj_rooms[i];
            break;
        }
    }
}

void execute_look(char * noun)
{
    if(strcmp(noun, "around") == 0)
    {
        printf("%s\n", cur_loc->description);
        printf("I can see ");
        for(int i=0; i<MAX_ITEM; i++)
        {
            if((items+i)->location == cur_loc && (items+i)->state != STATE_INVISIBLE)
            {
                printf("%s ", (items+i)->name);
            }
        }
        printf("\n");
    }
    if(strcmp(noun, "Safe") == 0)
    {
        if(safe->state == STATE_UNPICKABLE_UNLOCKED)
        {
            printf("Wow! Is that a %s?\n", safe->item->name);
            safe->item->state = STATE_VISIBLE;
        }
    }
}

Item * get_item(char * noun)
{
    for(int i=0; i<MAX_ITEM; i++)
    {
        if(strcmp(noun, (items+i)->name) == 0) return (items+i);
    }

    return NULL;
}

void execute_pick(char * noun)
{
    Item * item = get_item(noun);
    
    if(item != NULL && bag.size <= CAPACITY)
    {
        bag.items[bag.size++] = item;
        bag.items[bag.size] = NULL;
        points += item->point;
    }
    printf("%s is picked\n", noun);
}

void execute_drop(char * noun)
{
    int indx = get_bag_item_index(get_item(noun));

    if(indx != -1)
    {
        points -= bag.items[indx]->point;
        bag.items[indx] = bag.items[--bag.size];
    }

    printf("%s is dropped\n", noun);
}

void execute_use(char * noun)
{
    Item * item = get_item(noun);
    int indx = get_bag_item_index(item);

    if(indx != -1)
    {
        if(item == keys && cur_loc == hall_room)
        {
            safe->state = STATE_UNPICKABLE_UNLOCKED;
            printf("You have unlocked the safe! Use look command to look inside!\n");
            execute_drop(keys->name);
        }
    }
}

void show_inventory()
{
    for(int i=0; i<bag.size; i++)
    {
        printf("%d. %s\n", i+1, bag.items[i]->name);
    }
    printf("Your total points = %d\n", points);
}

int get_input()
{
    printf("=> ");
    return fgets(input, sizeof(input), stdin) != NULL;
}

int parse_exec(char * input)
{
    char * verb = strtok(input, " \n");
    char * noun = strtok(NULL, " \n");

    if(verb != NULL)
    {
        if(strcmp(verb, "quit") == 0)
        {
            return false;
        }
        else if(strcmp(verb, "look") == 0)
        {
            execute_look(noun);
        }
        else if(strcmp(verb, "go") == 0)
        {
            execute_go(noun);
        }
        else if(strcmp(verb, "use") == 0)
        {
            execute_use(noun);
        }
        else if(strcmp(verb, "pick") == 0)
        {
            execute_pick(noun);
        }
        else if(strcmp(verb, "drop") == 0)
        {
            execute_drop(noun);
        }
        else if(strcmp(verb, "inventory") == 0)
        {
            show_inventory();
        }
        
    }

    return true;
}

int main()
{
    printf("Welcome to Adventure\n");

    bag.items = (Item*) malloc(sizeof(Item*) * (CAPACITY+1));

    while(parse_exec(input) && get_input())
    {
        // main game
    }

    free(bag.items);
    printf("Bye\n");

    return 0;
}