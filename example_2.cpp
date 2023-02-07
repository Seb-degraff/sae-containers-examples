#include <iostream>
#include <vector>
#include <algorithm>

struct Enemy {
    int health;
};

int enemies_count = 0;
int enemies_cap = 0;
//Enemy enemies[MAX_ENEMIES];
Enemy* enemies = nullptr;

void add_enemy(int health)
{
    if (enemies_count == enemies_cap) {
        enemies_cap = std::max(4, enemies_cap * 2);
        enemies = (Enemy*) realloc(enemies, sizeof(Enemy) * enemies_cap);
    }
    enemies[enemies_count++] = Enemy { health = health };
}

void remove_enemy_at_index(int index)
{
    enemies[index] = enemies[enemies_count-1];
    enemies_count--;
}

int main()
{
    add_enemy(42);
    add_enemy(1);
    add_enemy(2);
    add_enemy(3);
    add_enemy(3);
    add_enemy(5);
    add_enemy(61);

    remove_enemy_at_index(5);
    remove_enemy_at_index(2);

    for (int i = 0; i < enemies_count; i++) {
        printf("enemy with health: %i\n", enemies[i].health);
    }
}
