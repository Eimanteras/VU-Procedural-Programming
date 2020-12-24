/// Eimantas Sostakas, 5grupe, 5uzduotis

///5. Ávesti sveikà skaièiø N. Uþpildyti matricà N*N sveikais skaièiais 1, 2, 3, …, suraðytais spirale.

#include <stdio.h>
#include <stdlib.h>


void fill(int** matrix, int n);

int main() {
    int n;
    int** matrix;
    printf("Iveskite sveika skaiciu \n");
    scanf("%d",&n);
    matrix = malloc(n*sizeof(int*));             /// pasiimam atminti pointeriams, kurie saugos adresus i kitus pointerius, saugancius adresus i kintamuosius
    for (int i=0; i<n; ++i)
        *(matrix+i) = malloc(n*sizeof(int));        /// kiekvienam pointeriui i kintamuosius isskiriam po n*4 baitu
    fill(matrix, n);                              /// uzpildom matrica spirales principu
    free(matrix);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
    return 0;
}

void fill(int** matrix, int n) {
    int gg=1, x=0, y=0, maxim=n-1, squares=4*n-4, tmpgg=1;
    while (gg < n*n+1) {
        *(*(matrix+x)+y) = gg;
        if (x < maxim && y == n-maxim-1) x++;
        else if (x == maxim && y < maxim) y++;
        else if (y == maxim && x <= maxim && x > n-maxim-1) x--;
        else if (x == n-maxim-1 && y <= maxim && y > n-maxim) y--;
        gg++;
        tmpgg++;
        if (tmpgg == squares) {
            tmpgg = 0;
            squares-=8;
            maxim--;
        }
    }
    //return matrix;
}
