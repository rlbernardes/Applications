#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

  struct rovers{
        int x;
        int y;
        int id_rover;
        char position;
    };

    typedef struct list_of_rovers *list_rovers;

    list_rovers *create_rovers();
    void free_rover(list_rovers *list);
    int rover_empty(list_rovers *list);
    int insert_rover(list_rovers *list, struct rovers rv);
    int remove_rover(list_rovers *list, int id_rover);
    int place_of_rover(list_rovers *list, int id_rover, int coordenate_x, int coordenate_y, char 		cardinal_point);
    int move_rover(list_rovers *list, int id_rover, char action);
    int print_place_rover(list_rovers *list, int id_rover);
    void new_rover(list_rovers *list, struct rovers *rv);
    void new_rover_input(list_rovers *list, int pos_x, int pos_y, int *id_rover, char position);
    void read_input_file(list_rovers *list);
