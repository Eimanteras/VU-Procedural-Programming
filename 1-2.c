/// Eimantas Sostakas, 5grupe, 4uzduotis

// Ávesti sveikø skaièiø sekà, kurios pabaiga şymima skaièiumi 0.
// Iğvesti nariø, kurie yra sveikø skaièiø kvadratai, skaièiø

#include <stdio.h>


int main() {

    int sk;
    int temp;
    int i;
    int n = 0;
    printf("Iveskite skaicius: ");
    do
    {
        while (scanf("%d",&sk) != 1)
        {
            printf("Prasau ivesti sveika skaiciu! \n");
            while(getchar() != '\n');
        }
        i = 1;
        temp = 1;
        do
        {
            temp = i * i;
            i++;
            if(sk == temp)
                n++;
        }
        while(sk > temp);

    }

    while(sk != 0);
    printf("nariu, kurie yra sveiku skaiciu kvadratai, skaicius = %d \n", n);

    return 0;
}
