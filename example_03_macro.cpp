#include <iostream>
#include <vector>
#include <algorithm>

struct Enemy {
    int health;
};

#define array(ElementType)        \
    struct ElementType##_array {  \
        ElementType*  elements;   \
        int           count;      \
        int           capacity;   \
    }

#define array_push(array, val) do {                                                                 \
    void *ptrdata = (array).elements;                                                               \
    if ((array).count == (array).capacity) {                                                        \
        (array).capacity = std::max(4, (array).capacity * 2);                                       \
        (array).elements = (typeid(*enemies.elements)) realloc((void*) enemies.elements, sizeof(*(array.elements)) * (array).capacity); \
    }                                                                                               \
    (array).elements[(array).count++] = val; \
} while (0)

array(Enemy) enemies = {0};

int main()
{
    array_push(enemies, (Enemy { 42 }));
    array_push(enemies, (Enemy { 45 }));
    array_push(enemies, (Enemy { 591 }));

    for (int i = 0; i < enemies.count; i++) {
        printf("enemy with health: %i\n", enemies.elements[i].health);
    }
}
