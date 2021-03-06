#include <math.h>
#include "./a4.h"

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size) {
  double d = 0.0;

  for (int i = 0; i < image_size; i++) {
    d += pow(A[i].r - B[i].r, 2) 
       + pow(A[i].g - B[i].g, 2)
       + pow(A[i].b - B[i].b, 2);
  }

  return sqrt(d);
}

void comp_fitness_population(const PIXEL *image, Individual *individual,
                             int population_size) {
  // Assuming all images are the same size
  int image_size = individual[0].image.width * individual[0].image.height;
  for (int i = 0; i < population_size; i++) {
    individual[i].fitness =
        comp_distance(image, individual[i].image.data, image_size);
  }
}
