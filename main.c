#include "rover.c"

int main(){
    int option = -1;
    list_rovers *lrover = create_rovers();
    while(option != 0){
        printf("\n\t\t\t====Opções====");
        printf("\n0 - Out");
        printf("\n1 - New rover");
        printf("\n2 - Define place of rover");
        printf("\n3 - Remove rover");
        printf("\n4 - To move rover");
        printf("\n5 - Print the place of the rover");
        printf("\n6 - Read input file");
        printf("\n\n=============================================================\n\n");
        printf("\n\nChoose one option: ");
        scanf("%d", &option);
        int result;
        struct rovers rv;
        if(option == 1){
            new_rover(lrover, &rv);
            insert_rover(lrover, rv);
        }
        if(option == 2){
            getchar();
            int id, x, y;
            char pos;

            printf("\nId Rover: ");
            scanf("%d", &id);

            printf("Pos x: ");
            scanf("%d", &x);

            printf("Pos y: ");
            scanf("%d", &y);

            printf("Coordinate: ");
            scanf(" %c", &pos);
            place_of_rover(lrover, id, x, y, pos);
        }
        if(option == 3){
            int id;
            printf("\nEnter with the id of rover that you want to remove: ");
            scanf("%d", &id);
            result = remove_rover(lrover, id);
        }
        if(option == 4){
            int id;
            char action;
            printf("\nEnter with the id of rover that you want to apply the action: ");
            scanf("%d,", &id);
            printf("\nEnter with the action (M = to move the rover, L to rotation for left and R to rotation for right): ");
            scanf(" %c", &action);
            move_rover(lrover, id, action);
        }
        if(option == 5){
            int id;
            printf("\nEnter with the id of rover that you want to print. ");
            scanf("%d", &id);
            print_place_rover(lrover, id);
        }
        if(option == 6){
            read_input_file(lrover);
        }
        if(option == 0) free_rover(lrover);
    }
    getchar();
    return 0;
}
