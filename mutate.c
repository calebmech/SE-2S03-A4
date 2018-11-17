#include "a4.h"
#include <stdlib.h>
#include <math.h>

#define data(row, col) data[row * width + col]

void mutate(Individual *individual, double rate){
    PPM_IMAGE image = individual->image;
    PIXEL *data = image.data;
    int height = image.height, width = image.width;
    int max_color = image.max_color;
    
    int n = width * height, pixToChange = (int)(rate/100*n);
    
    for (int i = 0;i < pixToChange;i++){
        int row = rand() % height + 1;
        int col = rand() % width + 1;

        data(row, col).r = rand() % (max_color + 1);
        data(row, col).g = rand() % (max_color + 1);
        data(row, col).b = rand() % (max_color + 1);
    }
}

void mutate_population(Individual *individual, int population_size, double rate){
    for (int i = 0;i < population_size;i++){
        mutate(individual, rate);
    }
}
