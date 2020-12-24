#include <stdio.h>
using namespace std;

int main()
{
    int skaicius = 0;
    int maximum = 0;
    printf ("Iveskite skaicius: ");
    scanf("%d", &skaicius);
    while(skaicius != 0)
    {
        scanf("%d", &skaicius);
        if(skaicius > maximum)
        {
            maximum = skaicius;
        }
    }
  printf ("%d Max: ",maximum);
}
