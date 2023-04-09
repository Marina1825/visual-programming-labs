#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Object {
    int id;
    int x; 
    int y; 
    int path[1000][2];
    int path_length;
};

void moveRandom(struct Object *obj) {
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    obj->x += dx;
    obj->y += dy;
    
    obj->path[obj->path_length][0] = obj->x;
    obj->path[obj->path_length][1] = obj->y;
    obj->path_length++;
}

int main() {
    srand(time(NULL));
    
    struct Object obj = {
        .id = 1,
        .x = 500,
        .y = 500,
        .path_length = 0
    };
    
    for (int i = 0; i < 100; i++) {
        moveRandom(&obj);
        printf("Object %d moved to (%d, %d)\n", obj.id, obj.x, obj.y);
    }
    
    printf("Object %d path:\n", obj.id);
    for (int i = 0; i < obj.path_length; i++) {
        printf("(%d, %d) ", obj.path[i][0], obj.path[i][1]);
    }
    
    return 0;
}