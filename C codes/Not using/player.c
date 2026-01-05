#include <stdio.h>

typedef struct{
    int age;
    char* name;
} Player;


// creates another instance of the struct Player based off of an original instance
Player young_player(Player original_player){
    Player player_out;
    player_out.age = 22;
    player_out.name = original_player.name;
    // young_player is equivalently set as within
    // Player player_out={22, player.name};
    
    return player_out;
}

int main(void){
    Player brenden = {28, "Brenden"};
    Player young_brenden = young_player(brenden);
    printf("%ss age is %d\n", brenden.name,brenden.age);
    printf("young %ss age is %d\n", young_brenden.name,young_brenden.age);

    Player* ptr_player =&brenden;
    (*ptr_player).age=23;  
    printf("%ss age is %d\n", ptr_player[0].name, ptr_player[0].age);

    ptr_player->age=24;
    printf("%ss age is %d\n", (*ptr_player).name, (*ptr_player).age);
    
}

