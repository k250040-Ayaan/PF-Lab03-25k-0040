#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------
   PART 1: Engine Specification Structure (2 marks)
------------------------------------------------------------------ */
typedef struct
{
    char fuelType[20];
    int horsepower;
} Engine;

/* ------------------------------------------------------------------
   PART 2: Vehicle Structure (2 marks)
------------------------------------------------------------------ */
typedef struct
{
    char model[50];
    int year;
    Engine engine; // vehicle contains engine
} Vehicle;

/* ------------------------------------------------------------------
   PART 3: Display Vehicle Info (2 marks)
------------------------------------------------------------------ */
void displayVehicle(Vehicle v)
{
    printf("Model: %s\n", v.model);
    printf("Year: %d\n", v.year);
    printf("Fuel Type: %s\n", v.engine.fuelType);
    printf("Horsepower: %d\n", v.engine.horsepower);
}

/* ------------------------------------------------------------------
   PART 4: Check Fuel Type Requirement (2 marks)
   Example: return 1 if vehicle uses Petrol
------------------------------------------------------------------ */
int usesPetrol(Vehicle v)
{
    if (strcmp(v.engine.fuelType, "Petrol") == 0)
        return 1;
    return 0;
}

/* ------------------------------------------------------------------
   PART 5: Compare Two Vehicles' Engines (2 marks)
------------------------------------------------------------------ */
int sameEngineType(Vehicle v1, Vehicle v2)
{
    if (strcmp(v1.engine.fuelType, v2.engine.fuelType) == 0)
        return 1;
    return 0;
}

