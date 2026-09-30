#include <stdio.h>
#include <string.h>

void menu(void)
{
    printf("1. Kitob qo`shish\n");
    printf("2. Barcha kitoblarni ko`rsatish\n");
    printf("3. Kitob qidirish\n");
    printf("4. Kitob o`chrish\n");
    printf("5. Bal boyicha sort\n");
    printf("6. Chiqish\n");
}

int main(void)
{

    typedef struct
    {
        int id;
        int ball;
        char title[100];
        char author[50];
        int year;
        int available;
        char borrower[50];
    } kitoblar;

    kitoblar kitoblarnomi[100];
    int soni = 0;
    int tanlov;

    FILE *fayl = fopen("kitoblar.txt", "r");
    if (fayl != NULL)
    {
        while (fscanf(fayl, "%d %d %s %s %d %d %s",
                      &kitoblarnomi[soni].id,
                      &kitoblarnomi[soni].ball,
                      kitoblarnomi[soni].title,
                      kitoblarnomi[soni].author,
                      &kitoblarnomi[soni].year,
                      &kitoblarnomi[soni].available,
                      kitoblarnomi[soni].borrower) == 7)
        {
            soni++;
        }
        fclose(fayl);
    }

    while (1)
    {

        menu();

        printf("mendan son sorang\n");

        if (scanf(" %d", &tanlov) != 1)
        {
            // printf("Noto'g'ri tanlov!\n");

            while (getchar() != '\n')
            {
            }

            continue;
        }

        switch (tanlov)
        {
        case 1:
            printf("1-Tanlov uchun ish\n");
            scanf("%d", &kitoblarnomi[soni].id);
            scanf("%d", &kitoblarnomi[soni].ball);
            scanf("%s", kitoblarnomi[soni].title);
            scanf("%s", kitoblarnomi[soni].author);
            scanf("%d", &kitoblarnomi[soni].year);
            scanf("%d", &kitoblarnomi[soni].available);
            scanf("%s", kitoblarnomi[soni].borrower);

            fayl = fopen("kitoblar.txt", "a");

            if (fayl == NULL)
            {
                printf("xatolik yuz berdi\n");
            }
            else
            {
                fprintf(fayl, "%d %d %s %s %d %d %s\n",
                        kitoblarnomi[soni].id,
                        kitoblarnomi[soni].ball,
                        kitoblarnomi[soni].title,
                        kitoblarnomi[soni].author,
                        kitoblarnomi[soni].year,
                        kitoblarnomi[soni].available,
                        kitoblarnomi[soni].borrower);

                fclose(fayl);
            }

            printf("%d\n", kitoblarnomi[soni].id);
            printf("%s\n", kitoblarnomi[soni].title);
            printf("%s\n", kitoblarnomi[soni].author);
            printf("%d\n", kitoblarnomi[soni].year);
            printf("%d\n", kitoblarnomi[soni].available);
            printf("%s\n", kitoblarnomi[soni].borrower);

            soni++;
            break;

        case 2:
            printf("2-Tanlov uchun ish\n");

            if (soni == 0)
            {
                printf("hozircha kitoblar yoq");
            }
            else
            {
                for (int i = 0; i < soni; i++)
                {
                    printf("%s\n", kitoblarnomi[i].title);
                    printf("%s\n", kitoblarnomi[i].author);
                    printf("%d\n", kitoblarnomi[i].year);
                    printf("%d\n", kitoblarnomi[i].available);
                    printf("%s\n", kitoblarnomi[i].borrower);
                }
            }
            break;

        case 3:
            char qidiruv[100];

            printf("3 -Tanlov uchun ish\n");
            printf("kitob nomini kiriting");
            scanf("%s", qidiruv);

            for (int i = 0; i < soni; i++)
            {
                if (strcmp(kitoblarnomi[i].title, qidiruv) == 0)
                {
                    printf("Topildi kitob nomi %s\n", qidiruv);
                }
            }
            break;

        case 4:
        {
            int ochrish_id;

            printf("4-tanlov uchun ish\n");
            printf("ochrmoqchi bolgan kitobingizni id sini yozing");

            scanf("%d", &ochrish_id);

            for (int i = 0; i < soni; i++)
            {
                if (kitoblarnomi[i].id == ochrish_id)
                {
                    printf("%d\n", ochrish_id);

                    for (int j = i; j < soni - 1; j++)
                    {
                        kitoblarnomi[j] = kitoblarnomi[j + 1];
                    }

                    soni--;

                    break;
                }
            }

            fayl = fopen("kitoblar.txt", "w");

            if (fayl == NULL)
            {
                printf("xatolik yuz berdi");
            }
            else
            {
                for (int i = 0; i < soni; i++)
                {
                    fprintf(fayl, "%d %d %s %s %d %d %s\n",
                            kitoblarnomi[i].id,
                            kitoblarnomi[i].ball,
                            kitoblarnomi[i].title,
                            kitoblarnomi[i].author,
                            kitoblarnomi[i].year,
                            kitoblarnomi[i].available,
                            kitoblarnomi[i].borrower);
                }

                fclose(fayl);
            }

            printf("kitob ochrildi!\n");
            break;
        }

        case 5:
            printf("5-tanlov uchun ish\n");

            for (int i = 0; i < soni - 1; i++)
            {
                for (int j = 0; j < soni - 1; j++)
                {
                    if (kitoblarnomi[j].ball > kitoblarnomi[j + 1].ball)
                    {
                        kitoblar temp = kitoblarnomi[j];
                        kitoblarnomi[j] = kitoblarnomi[j + 1];
                        kitoblarnomi[j + 1] = temp;
                    }
                }
            }

            break;

        case 6:
            printf("6-tanlov uchun ish\n");
            break;

        default:
            break;
        }

        if (tanlov == 6)
        {
            break;
        }
    }
}