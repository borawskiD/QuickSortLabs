#include <iomanip>
#include <iostream>
#include <random>

void printArray(int *tab, int left, int right){
    for (int i = left;i<=right;i++){
        std::cout<<tab[i] << " ";
    }
    std::cout<<std::endl;
}
void quicksort(int *tab, int left, int right){
    std::cout<<"\n";
    std::cout<<"Aktualnie analizowana tablica: ";
    printArray(tab,left,right);
    int pivotIndex = (int)((left + right)/2);
    int pivot = tab[pivotIndex];
    std::cout << "Wybrany piwot: " << pivot << "\n";
    int i = left;
    int j = i;

    tab[pivotIndex] = tab[right];
    while(i < right){
        std::cout<<"Sprawdzę, czy moge przesunąć element tablicy o indeksie "<<i<<" (element < pivot): \n";
        if(tab[i] < pivot){
            std::cout<<"Tak, " << tab[i] << " < "<<pivot<<"\n";
            std::swap(tab[i], tab[j]);
            std::cout<<"Tablica po przeniesieniu: ";
            printArray(tab,left,right);
            std::cout<<std::endl;
            j++;
        } else std::cout<<"Nie, " << tab[i] << " >= "<<pivot<<"\n \n";
        i++;
    }
    std::cout<<"Przenoszenie zakończone, zatem czas podzielić i posortować tablicę: \n";
    std::cout << "Przywracam piwot z powrotem na swoje miejsce, tj. pomiędzy liczby niższe od piwota a wyższe bądź równe. \n";
    std::cout << tab[j] << "<->" << pivot<<std::endl;
    tab[right] = tab[j];
    tab[j] = pivot;
    std::cout<<"\nWygląd tablicy przed (kolejnym) iteracyjnym podzieleniem: ";
    printArray(tab,0,9);
    std::cout<<"\n";
    std::cout<<"Czy możliwe jest posortowanie lewej części tablicy?\n";
    if(left < j-1){
        std::cout<<"Tak, jest to możliwe. Wykonanie:\n \n";
        quicksort(tab, left, j-1);
    }else std::cout<<"Nie, nie jest to możliwe. \n";
    std::cout<<"\nCzy możliwe jest posortowanie prawej części tablicy?\n";
    if(j+1 < right){
        std::cout<<"Tak, jest to możliwe. Wykonanie: \n\n ";
        quicksort(tab, j+1, right);
    }else std::cout<<"Nie, nie jest to możliwe. \n";
}

int main() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 100);

    int n = 10;
    int tab[n];

    for (int i = 0; i < n; i++) {
        tab[i] = distr(gen);
    }

    std::cout << "Before quicksort algorithm: \n";
    for (int i = 0; i < n; i++) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    quicksort(tab, 0, n - 1);
    std::cout<<"---\n";
    std::cout << "\nAfter quicksort algorithm: \n";

    for(int i = 0; i < n; i++){
        std::cout << tab[i]<< " ";
    }
    std::cout<<std::endl;

    return 0;
}

/*
 * Dominik Borawski
 * A1 215 IC
 * QuickSort
 */

/*
Before quicksort algorithm:
86 39 84 15 97 77 49 73 75 4

Aktualnie analizowana tablica: 86 39 84 15 97 77 49 73 75 4
Wybrany piwot: 97
Sprawdzę, czy moge przesunąć element tablicy o indeksie 0 (element < pivot):
Tak, 86 < 97
Tablica po przeniesieniu: 86 39 84 15 4 77 49 73 75 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 1 (element < pivot):
Tak, 39 < 97
Tablica po przeniesieniu: 86 39 84 15 4 77 49 73 75 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 2 (element < pivot):
Tak, 84 < 97
Tablica po przeniesieniu: 86 39 84 15 4 77 49 73 75 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 3 (element < pivot):
Tak, 15 < 97
Tablica po przeniesieniu: 86 39 84 15 4 77 49 73 75 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 4 (element < pivot):
Tak, 4 < 97
Tablica po przeniesieniu: 86 39 84 15 4 77 49 73 75 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 5 (element < pivot):
Tak, 77 < 97
Tablica po przeniesieniu: 86 39 84 15 4 77 49 73 75 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 6 (element < pivot):
Tak, 49 < 97
Tablica po przeniesieniu: 86 39 84 15 4 77 49 73 75 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 7 (element < pivot):
Tak, 73 < 97
Tablica po przeniesieniu: 86 39 84 15 4 77 49 73 75 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 8 (element < pivot):
Tak, 75 < 97
Tablica po przeniesieniu: 86 39 84 15 4 77 49 73 75 4

Przenoszenie zakończone, zatem czas podzielić i posortować tablicę:
Przywracam piwot z powrotem na swoje miejsce, tj. pomiędzy liczby niższe od piwota a wyższe bądź równe.
4<->97

Wygląd tablicy przed (kolejnym) iteracyjnym podzieleniem: 86 39 84 15 4 77 49 73 75 97

Czy możliwe jest posortowanie lewej części tablicy?
Tak, jest to możliwe. Wykonanie:


Aktualnie analizowana tablica: 86 39 84 15 4 77 49 73 75
Wybrany piwot: 4
Sprawdzę, czy moge przesunąć element tablicy o indeksie 0 (element < pivot):
Nie, 86 >= 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 1 (element < pivot):
Nie, 39 >= 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 2 (element < pivot):
Nie, 84 >= 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 3 (element < pivot):
Nie, 15 >= 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 4 (element < pivot):
Nie, 75 >= 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 5 (element < pivot):
Nie, 77 >= 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 6 (element < pivot):
Nie, 49 >= 4

Sprawdzę, czy moge przesunąć element tablicy o indeksie 7 (element < pivot):
Nie, 73 >= 4

Przenoszenie zakończone, zatem czas podzielić i posortować tablicę:
Przywracam piwot z powrotem na swoje miejsce, tj. pomiędzy liczby niższe od piwota a wyższe bądź równe.
86<->4

Wygląd tablicy przed (kolejnym) iteracyjnym podzieleniem: 4 39 84 15 75 77 49 73 86 97

Czy możliwe jest posortowanie lewej części tablicy?
Nie, nie jest to możliwe.

Czy możliwe jest posortowanie prawej części tablicy?
Tak, jest to możliwe. Wykonanie:


Aktualnie analizowana tablica: 39 84 15 75 77 49 73 86
Wybrany piwot: 75
Sprawdzę, czy moge przesunąć element tablicy o indeksie 1 (element < pivot):
Tak, 39 < 75
Tablica po przeniesieniu: 39 84 15 86 77 49 73 86

Sprawdzę, czy moge przesunąć element tablicy o indeksie 2 (element < pivot):
Nie, 84 >= 75

Sprawdzę, czy moge przesunąć element tablicy o indeksie 3 (element < pivot):
Tak, 15 < 75
Tablica po przeniesieniu: 39 15 84 86 77 49 73 86

Sprawdzę, czy moge przesunąć element tablicy o indeksie 4 (element < pivot):
Nie, 86 >= 75

Sprawdzę, czy moge przesunąć element tablicy o indeksie 5 (element < pivot):
Nie, 77 >= 75

Sprawdzę, czy moge przesunąć element tablicy o indeksie 6 (element < pivot):
Tak, 49 < 75
Tablica po przeniesieniu: 39 15 49 86 77 84 73 86

Sprawdzę, czy moge przesunąć element tablicy o indeksie 7 (element < pivot):
Tak, 73 < 75
Tablica po przeniesieniu: 39 15 49 73 77 84 86 86

Przenoszenie zakończone, zatem czas podzielić i posortować tablicę:
Przywracam piwot z powrotem na swoje miejsce, tj. pomiędzy liczby niższe od piwota a wyższe bądź równe.
77<->75

Wygląd tablicy przed (kolejnym) iteracyjnym podzieleniem: 4 39 15 49 73 75 84 86 77 97

Czy możliwe jest posortowanie lewej części tablicy?
Tak, jest to możliwe. Wykonanie:


Aktualnie analizowana tablica: 39 15 49 73
Wybrany piwot: 15
Sprawdzę, czy moge przesunąć element tablicy o indeksie 1 (element < pivot):
Nie, 39 >= 15

Sprawdzę, czy moge przesunąć element tablicy o indeksie 2 (element < pivot):
Nie, 73 >= 15

Sprawdzę, czy moge przesunąć element tablicy o indeksie 3 (element < pivot):
Nie, 49 >= 15

Przenoszenie zakończone, zatem czas podzielić i posortować tablicę:
Przywracam piwot z powrotem na swoje miejsce, tj. pomiędzy liczby niższe od piwota a wyższe bądź równe.
39<->15

Wygląd tablicy przed (kolejnym) iteracyjnym podzieleniem: 4 15 73 49 39 75 84 86 77 97

Czy możliwe jest posortowanie lewej części tablicy?
Nie, nie jest to możliwe.

Czy możliwe jest posortowanie prawej części tablicy?
Tak, jest to możliwe. Wykonanie:


Aktualnie analizowana tablica: 73 49 39
Wybrany piwot: 49
Sprawdzę, czy moge przesunąć element tablicy o indeksie 2 (element < pivot):
Nie, 73 >= 49

Sprawdzę, czy moge przesunąć element tablicy o indeksie 3 (element < pivot):
Tak, 39 < 49
Tablica po przeniesieniu: 39 73 39

Przenoszenie zakończone, zatem czas podzielić i posortować tablicę:
Przywracam piwot z powrotem na swoje miejsce, tj. pomiędzy liczby niższe od piwota a wyższe bądź równe.
73<->49

Wygląd tablicy przed (kolejnym) iteracyjnym podzieleniem: 4 15 39 49 73 75 84 86 77 97

Czy możliwe jest posortowanie lewej części tablicy?
Nie, nie jest to możliwe.

Czy możliwe jest posortowanie prawej części tablicy?
Nie, nie jest to możliwe.

Czy możliwe jest posortowanie prawej części tablicy?
Tak, jest to możliwe. Wykonanie:


Aktualnie analizowana tablica: 84 86 77
Wybrany piwot: 86
Sprawdzę, czy moge przesunąć element tablicy o indeksie 6 (element < pivot):
Tak, 84 < 86
Tablica po przeniesieniu: 84 77 77

Sprawdzę, czy moge przesunąć element tablicy o indeksie 7 (element < pivot):
Tak, 77 < 86
Tablica po przeniesieniu: 84 77 77

Przenoszenie zakończone, zatem czas podzielić i posortować tablicę:
Przywracam piwot z powrotem na swoje miejsce, tj. pomiędzy liczby niższe od piwota a wyższe bądź równe.
77<->86

Wygląd tablicy przed (kolejnym) iteracyjnym podzieleniem: 4 15 39 49 73 75 84 77 86 97

Czy możliwe jest posortowanie lewej części tablicy?
Tak, jest to możliwe. Wykonanie:


Aktualnie analizowana tablica: 84 77
Wybrany piwot: 84
Sprawdzę, czy moge przesunąć element tablicy o indeksie 6 (element < pivot):
Tak, 77 < 84
Tablica po przeniesieniu: 77 77

Przenoszenie zakończone, zatem czas podzielić i posortować tablicę:
Przywracam piwot z powrotem na swoje miejsce, tj. pomiędzy liczby niższe od piwota a wyższe bądź równe.
77<->84

Wygląd tablicy przed (kolejnym) iteracyjnym podzieleniem: 4 15 39 49 73 75 77 84 86 97

Czy możliwe jest posortowanie lewej części tablicy?
Nie, nie jest to możliwe.

Czy możliwe jest posortowanie prawej części tablicy?
Nie, nie jest to możliwe.

Czy możliwe jest posortowanie prawej części tablicy?
Nie, nie jest to możliwe.

Czy możliwe jest posortowanie prawej części tablicy?
Nie, nie jest to możliwe.
---

After quicksort algorithm:
4 15 39 49 73 75 77 84 86 97
 */