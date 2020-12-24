/// Eimantas Sostakas, 5grupe, 9uzduotis

#include <stdio.h>
#include <stdlib.h>

const size_t DATA = 256;

void tikrinti(char buferis[], char *ats_eilute);

int main(int argc, char** argv)
{
    FILE *duom;
    FILE *rez;
    char buf[DATA];
    char *ats_eilute;
    //char pavDuom[DATA];
    //char pavRez[DATA];

    //printf("Iveskite failo pavadinima is kurio nuskaitysite duomenis \n");
    //printf("%s \n", argv[1]);
   // scanf( "%s" , &pavDuom);

    duom = fopen(argv[1],"r");
    if (!duom){
        printf("Failo pavadinimo %s nera \n", argv[1]);
        return 1;
    }
    //printf("Iveskite failo pavadinima i kuri spausdinsi duomenis \n");
    //printf("%s \n", argv[2]);
    //scanf( "%s" , &pavRez);

    if (argv[1] == argv[2]){
            printf("Rezultatu failas negali sutapti su duomenu failu \n");
            return 1;
            }
    rez = fopen(argv[2], "w");
    if(rez == NULL)
    {
        printf("Nepavyko sukurti failo pavadinimu %s \n", argv[2]);
        return 1;
    }
    while(fgets(buf, sizeof(buf), duom)) {
        //int ilgis = strlen(buf);
        //printf("%d \n", ilgis);    //eilutes ilgis
        tikrinti(buf, ats_eilute);
        fputs(ats_eilute, rez);
        //printf("%s \n" , buf);
    }
		fclose(duom);
		fclose(rez);
        free(buf);
        free(ats_eilute);
    return 0;
}

void tikrinti(char buferis[], char *ats_eilute){
    int ilgis = 0; //eilutes ilgis
    char l;
    while (buferis[ilgis] != '\0'){
        ilgis++;
    }
    //printf("%d \n", ilgis);
    //*ats_eilute = malloc(ilgis*sizeof(char));

    for(l = 0; buferis[l] != '\0'; ++l){
        *(ats_eilute+l) = buferis[l];
    }
    ats_eilute[l] = '\0';

   // printf("%s \n", ats_eilute);

    int vt = 0; //pasikeitusi eilutes vieta simboliams

    for(int i = 0; i < ilgis; i++){
        if(buferis[i+1] == ' '){
            int m = 1;
            int n = i;
            while(buferis[n + 2] == ' '){
                n = n + 1;
                m = m + 1;
            }
            if(buferis[i] == buferis[i + m + 1]){
                for(int j = 0; j < ilgis-i; j++){
                    ats_eilute[i+j+1-vt] = buferis[i+m+j+1];
                    //printf("%s \n", ats_eilute);
                   // printf("%s \n", buferis);
                    //printf("%d %d \n", m, i);
                    }
                vt = vt + m;
            }
          //  i = i-m;
        }
    }
}
