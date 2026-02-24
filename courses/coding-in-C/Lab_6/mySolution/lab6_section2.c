#include <stdio.h>

typedef struct
{
    float fuel_level;
    float max_fuel_level;
    char model[50];
} Car;

void refuel(Car *p_car, float amount)
{
    p_car->fuel_level += amount;

    if (p_car->fuel_level > p_car->max_fuel_level)
    {
        p_car->fuel_level = p_car->max_fuel_level;
    }
}

int main(void)
{
    Car my_car = {5.0f, 50.0f, "CLA"};

    refuel(&my_car, 30.0f);

    printf("Model: %s\n", my_car.model);
    printf("Fuel level: %.2f / %.2f\n",
           my_car.fuel_level,
           my_car.max_fuel_level);

    return 0;
}

