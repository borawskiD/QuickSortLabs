#include <cstdlib>
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

    std::cout << "After quicksort algorithm: \n";

    for(int i = 0; i < n; i++){
        std::cout << tab[i]<< " ";
    }
    std::cout<<std::endl;

    return 0;
}
