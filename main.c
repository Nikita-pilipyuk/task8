#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void puzir(int* mas, int n)
{

    int kolperest = 0, kolif = 0;
    int max;
    int i, j;
    for (i = 1; i < n ; i++) {

        max = 0;
        for (j = 0; j < n -i; j++) {


            kolif = kolif + 1;
            if (mas[j] > mas[j + 1]) {

                mas[j] = mas[j] + mas[j + 1];
                mas[j + 1] = mas[j] - mas[j + 1];
                mas[j] = mas[j] - mas[j + 1];
                kolperest = kolperest + 1;
                max=1;
            }



        }
        if (max == 0) {
                i = n;
            }

    }

        printf("\nKolichestvo perestanovok: %d", kolperest);
        printf("\nKolichestvo sravneniy: %d", kolif);



    }



    void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int array[], int low, int high, int* nswap, int* nif) {


    int pivot = array[high];
    int i = (low - 1);

   int j;
    for (j = low; j < high; j++) {
        *nif = *nif + 1;
        printf("\n1 if %d %d", array[j] , pivot);
        if (array[j] <= pivot) {
           // *nif = *nif + 1;
            i++;
           // printf("\n2 if%d %d", array[i], array[j]);
            if ( i != j) {
                    *nswap = *nswap + 1;
                    swap(&i, &j);
            }
        }
    }

    printf("\n If v kontse partition %d %d", array[i+1], array[high]);
    if (i+1!=high) {

    *nswap = *nswap + 1;
    swap(&array[i + 1], &array[high]);
}
    return (i + 1);
}

void quickSort(int array[], int low, int high,int *nswap,int *nif) {

    if (low < high) {

        int pi = partition(array, low, high, &*nswap, &*nif);


            quickSort(array, low, pi - 1, &*nswap, &*nif);




            quickSort(array, pi + 1, high, &*nswap, &*nif);

        }

    }


    void printArray(int array[], int size) {
        int i;
        for ( i = 0; i < size; ++i) {
            printf("%d ", array[i]);
        }
        printf("\n");
}




void insertionSort(int mas[], int n)
{
    int nswap=0,nif=0;
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = mas[i];
        j = i - 1;
        nif++;
        while (j >= 0 && mas[j] > key) {
            nswap++;
            mas[j + 1] = mas[j];
            j = j - 1;
        }
        mas[j + 1] = key;
    }

    printf("Kolichestvo perestanovok: %d\n", nswap);
    printf("Kolicestvo sravneniy: %d\n", nif);
}



int main()
{
    int *mas, n,q=-1;

    while (q != 0) {
        printf("\n\n\n\n0)Vihod\n1)Puziryok\n2)Bistraya sortirovka(Quick sort)\n3)Sortirovka stavkam(Insertion sort)");
        printf("\nVvedite chislo  ");
        scanf_s("%d", &q);
        switch (q) {
        case 1: {

            printf("Vvedite kolichestvo elementov v massive: ");
            scanf_s("%d", &n);

            mas = (int*)malloc(n * sizeof(int));
            printf("Vvedite elementi massiva: ");
            int i;
            for (i = 0; i < n; i++)
            {
                scanf_s("%d", &mas[i]);
            }

            puzir(mas, n );
            printf ("\nSam massiv otsortirovanniy puzirkom : ");

            for ( i = 0; i < n; i++) {
                    printf("%d ", mas[i]);
            }
            break;
                 }
        case 2: {
            printf("Vvedite kolichestvo elementov very massive: ");
            scanf_s("%d", &n);

            mas = (int*)malloc(n * sizeof(int));
            printf("Vvedite elementi massiva: ");
            int i;
            for ( i = 0; i < n; i++)
            {
                scanf_s("%d", &mas[i]);
            }
            int nswap = 0, nif = 0;
            quickSort(mas, 0, n - 1, &nswap, &nif);

            printf("Kolichestvo perestanovok: %d\n", nswap);
            printf("Kolichestvo sravneniy: %d", nif);
            printf(" Massiv: \n");
            printArray(mas, n);
            break;
        }
        case 3: {
            printf("Vvedite kolichestvo elementov v massive: ");
            scanf_s("%d", &n);

            mas = (int*)malloc(n * sizeof(int));
            printf("Vvedite elementi massiva: ");
            int i;
            for ( i = 0; i < n; i++)
            {
                scanf_s("%d", &mas[i]);
            }
            insertionSort(mas, n);
            printArray(mas, n);
            break;
        }
        }

    }
   return 0;
}
