#include <stdio.h>

int main(void){

    struct particle{
        int x;
        int y;
        char direction;
    } particle_vector = {23, 98, 's'};

    printf("the particle is at coordinates: x:%d, y:%d and is moving %c.\n",
        particle_vector.x,
        particle_vector.y,
        particle_vector.direction
    );

    particle_vector.x = 5;
    particle_vector.y = 8;
    particle_vector.direction = 'n';

    printf("the particle is at coordinates: x:%d, y:%d and is moving %c.\n",
        particle_vector.x,
        particle_vector.y,
        particle_vector.direction
    );

    return 0;
}