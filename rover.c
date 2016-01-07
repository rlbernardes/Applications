#include "rover.h"
#include<ctype.h>

struct list_of_rovers {
    struct rovers datas;
    struct list_of_rovers *prox;
};

typedef struct list_of_rovers lr;

list_rovers *create_rovers() {
    list_rovers *list = (list_rovers *) malloc(sizeof (list_rovers));
    if (list != NULL) {
        *list = NULL;
    }
    return list;
}

void free_rover(list_rovers* list) {
    if (list != NULL) {
        lr *no;
        while ((*list) != NULL) {
            no = *list;
            *list = (*list)->prox;
            free(no);
        }
        free(list);
    }
}

int rover_empty(list_rovers* list) {
    if (list == NULL)
        return 1;
    if (*list == NULL)
        return 1;
    return 0;
}

int insert_rover(list_rovers *list, struct rovers rv) {
    if (list == NULL)
        return 0;
    lr *no = (lr*) malloc(sizeof (lr));
    if (no == NULL)
        return 0;
    no->datas = rv;
    no->prox = NULL;
    if ((*list) == NULL)
        *list = no;
    else {
        lr *aux = *list;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;

    }
    return 1;
}

int remove_rover(list_rovers* list, int id_rover) {
    if (list == NULL)
        return 0;
    lr *no = *list, *store;
    while (no->prox != NULL && no->datas.id_rover != id_rover) {
        store = no;
        no->prox;
    }
    if (no == NULL) return 0;
    if (no == (*list))
        *list = no->prox;
    else
        store->prox = no->prox;
    free(no);
    return 1;
}

int place_of_rover(list_rovers* list, int id_rover, int coordenate_x, int coordenate_y, char cardinal_point) {
    if (!rover_empty(list)) {
        lr *no = *list;
        while (no->prox != NULL && no->datas.id_rover != id_rover) {
            no->prox;
        }
        if (no == NULL) return 0;
        else {
            no->datas.position = cardinal_point;
            no->datas.x = coordenate_x;
            no->datas.y = coordenate_y;
        }
        return 1;
    } else
        return 0;
}

int move_rover(list_rovers *list, int id_rover, char action) {
    if (!rover_empty(list)) {
        lr *no = *list;
        while (no->prox != NULL && no->datas.id_rover != id_rover) {
            no = no->prox;
        }
        if (no == NULL) return 0;
        else {
            if (action == 'M') {
                if (no->datas.position == 'N') no->datas.y++;
                else if (no->datas.position == 'S') no->datas.y--;
                else if (no->datas.position == 'W') no->datas.x--;
                else if (no->datas.position == 'E') no->datas.x++;
                else return 0;
                return 1;
            } else if (action == 'L') {
                if (no->datas.position == 'N') no->datas.position = 'W';
                else if (no->datas.position == 'S') no->datas.position = 'E';
                else if (no->datas.position == 'E') no->datas.position = 'N';
                else if (no->datas.position == 'W') no->datas.position = 'S';
                return 1;
            } else if (action == 'R') {
                if (no->datas.position == 'N') no->datas.position = 'E';
                else if (no->datas.position == 'S') no->datas.position = 'W';
                else if (no->datas.position == 'E') no->datas.position = 'S';
                else if (no->datas.position == 'W') no->datas.position = 'N';
                return 1;
            } else return 0;
        }
    } else return 0;
}

int print_place_rover(list_rovers* list, int id_rover) {
    if (!rover_empty(list)) {
        lr *no = *list;
        while (no->prox != NULL && no->datas.id_rover != id_rover) {
            no = no->prox;
        }
        if (no == NULL) return 0;
        printf("\nRover: %i", no->datas.id_rover);
        printf("\n%i, %i, %c", no->datas.x, no->datas.y, no->datas.position);
    } else return 0;
}

void new_rover(list_rovers *list, struct rovers* rv) {
    getchar();
    if (!rover_empty(list)) {
        lr *no = *list;
        while (no->prox != NULL) {
            no = no->prox;
        }
        printf("\nId Rover: %d", no->datas.id_rover + 1);
        rv->id_rover = no->datas.id_rover + 1;
    } else {
        printf("\nId Rover: %d", 1);
        rv->id_rover = 1;
    }
    printf("\nPos x: ");
    scanf("%d", &rv->x);

    printf("Pos y: ");
    scanf("%d", &rv->y);


    printf("Coordinate: ");
    scanf(" %c", &rv->position);

    printf("\nRover started with success!!!");
    printf("\n\n=============================================================\n\n");
}

void new_rover_input(list_rovers *list, int pos_x, int pos_y, int *id_rover, char position) {
    struct rovers rv;
    if (!rover_empty(list)) {
        lr *no = *list;
        while (no->prox != NULL) {
            no = no->prox;
        }
        printf("\nId Rover: %d", no->datas.id_rover + 1);
        rv.id_rover = no->datas.id_rover + 1;
    } else {
        printf("\nId Rover: %d", 1);
        rv.id_rover = 1;
    }
    rv.x = pos_x;
    rv.y = pos_y;
    if (position == NULL)
        rv.position = 'N';
    else
        rv.position = position;
    insert_rover(list, rv);
    *id_rover = rv.id_rover;
}

void read_input_file(list_rovers *lrover) {
    char url[] = "input.txt";
    char ch;
    FILE *arq;
    int id_rover = -1, count_digits = 0, pos_x, pos_y, flag = 1, first_line = 0;
    arq = fopen(url, "r");
    if (arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else
        while ((ch = fgetc(arq)) != EOF) {
            if (isdigit(ch)) {
                count_digits = count_digits + 1;
                if (count_digits % 2 != 0)
                    pos_x = ch - '0';
                else
                    pos_y = ch - '0';

            }else if(ch != ' '){
                if(count_digits == 2 && ch == '\n'){
                    new_rover_input(lrover, pos_x, pos_y, &id_rover, NULL);
                    count_digits = 0;
                }else if((ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E') && count_digits == 2 && flag == 1){
                    flag = 0;
                    place_of_rover(lrover, id_rover, pos_x, pos_y, ch);
                    count_digits = 0;
                }else if((ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E') && count_digits == 2 && flag == 0){
                    new_rover_input(lrover, pos_x, pos_y, &id_rover, ch);
                    count_digits = 0;
                }else if(ch == 'M' || ch == 'L' || ch == 'R'){
                        move_rover(lrover, id_rover, ch);
                        count_digits = 0;
                    }
            }
        }

    fclose(arq);
    lr *no = *lrover;
    printf("\nResult file input======================\n");
    do {
            printf("\nRover number: %d\n", no->datas.id_rover);
            printf("Position axis x: %d\n", no->datas.x);
            printf("Position axis y: %d\n", no->datas.y);
            printf("Coordinate: %c\n", no->datas.position);
            no = no->prox;
    }while (no != NULL);
    printf("\n=======================================\n");
}
