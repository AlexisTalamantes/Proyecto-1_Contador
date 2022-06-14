#include <stdio.h>
#include <stdlib.h>

int main(argc, argv)
    int argc;
    char *argv[];
{
    int c, i, inword;
    FILE *fp;
    long linect, wordct, charct;
    long tlinect = 1, twordct = 1, tcharct = 1;

    i = 1;

    do 
    { //Se corrigen llaves
        linect = wordct = charct = 0;//Se cambia de lugar
        inword = 0;//Se cambia de lugar

        if ((fp=fopen(argv[i],"r")) == NULL)
        {//Se corrigen llaves
            fprintf (stdout, "can't open %s\n", argv[i]);
            exit(1); 
        }//Se corrigen llaves

        while ((c = getc(fp)) != EOF) 
        {//Se corrigen llaves
            ++charct;
            if (c == '\n')
            {//Se corrigen llaves
                ++linect;
            }//Se corrigen llaves
            if (c == ' ' || c == '\t' || c == '\n')
            {//Se corrigen llaves
            inword = 0;
            }//Se corrigen llaves
            else if (inword == 0) 
            {//Se corrigen llaves
                inword = 1; 
                ++wordct; 
            }//Se corrigen llaves
        }
        
        printf("%7ld %7ld %7ld", linect, wordct, charct);
        if (argc > 1)
        {//Se corrigen llaves
            printf("%s\n", argv[i]);
        }//Se corrigen llaves
        else
        {//Se corrigen llaves
            printf("\n");
        }//Se corrigen llaves
        fclose(fp);
        tlinect += linect;
        twordct += wordct;
        tcharct += charct; 

    }while (++i < argc);
        
    if (argc > 1)
    {//Se corrigen llaves
     printf("%7ld %7ld %7ld total\n", linect, twordct, tcharct);
    }//Se corrigen llaves
    exit(0);
 }