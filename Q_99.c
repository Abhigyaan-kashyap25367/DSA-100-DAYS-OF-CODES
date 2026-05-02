// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

int compareCars(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int* speed, int n) {
    if (n == 0) return 0;

    Car* cars = (Car*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(Car), compareCars);

    int fleets = 0;
    double current_max_time = 0.0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > current_max_time) {
            fleets++;
            current_max_time = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    printf("%d\n", carFleet(target, position, speed, n));
    return 0;
}