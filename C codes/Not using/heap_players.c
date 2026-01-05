#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int age;
    char* name;
} Player;

int main(void){
    int n=10;
    Player* ptr_players;
    // allocates 10 Players for ptr_players
    ptr_players = (Player*) malloc(10*sizeof(Player));
    if (ptr_players != NULL){
        // 0th Player entry in ptr_players
        ptr_players->age=30;
        ptr_players->name="first";
        // 4th Player entry in ptr_players
        (ptr_players+4)->age=40;
        (ptr_players+4)->name="fourth";
        // 5th Player entry in ptr_players
        (*(ptr_players+5)).age=50;
        (*(ptr_players+5)).name="fifth";
        // 6th Player entry in ptr_players
        ptr_players[6].age=60;
        ptr_players[6].name="sixth";
    }
    printf("%ss age is %d\n", ptr_players[0].name, ptr_players[0].age);
    printf("%ss age is %d\n", ptr_players[4].name, ptr_players[4].age);
    printf("%ss age is %d\n", ptr_players[5].name, ptr_players[5].age);
    printf("%ss age is %d\n", ptr_players[6].name, ptr_players[6].age);



    free(ptr_players);
}