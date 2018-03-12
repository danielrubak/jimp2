//
// Created by rubadani on 06.03.18.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H

int **Array2D(int n_rows, int n_columns);
int **NewArray2D(int n_rows, int n_columns);
void FillArray2D(int n_rows, int n_columns, int *const *array);
void DeleteArray2D(int **array, int n_rows, int n_columns);

#endif //JIMP_EXERCISES_ARRAY2D_H
