#include <iostream>
#include <stdlib.h>
#include <time.h>

struct Object {
    int id;
    int x; 
    int y; 
    int path[1000][1000];
    int path_length;
};

class Coordinates {

};

void moveRandom(struct Object *obj) {
    int dx = rand() % 15 - 1;
    int dy = rand() % 15 - 1;
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

    class Coordinates {

    };
    
    int way = 0;
    int max_way = rand() % (100 - 0) + 0;
    
    std::cout << "Position " << way << " step: (" << obj.x << ", " << obj.y << ")\n";

    for (int i = 0; i < max_way; i++) {
        moveRandom(&obj);
        way += 1;
    }
    std::cout << "Position " << way << " step: (" << obj.x << ", " << obj.y << ")\n\n";

    std::cout << "Object " << obj.id << " path:\n";

    for (int i = 0; i < obj.path_length; i++) {
        std::cout << "(" << obj.path[i][0] << ", " << obj.path[i][1] << "); ";
    }
    std::cout << "\n\n";

    std::cout << "The path traversed by object " << obj.id << " : " << way << "\n";
    
    return 0;
}