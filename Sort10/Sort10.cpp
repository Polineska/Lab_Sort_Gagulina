
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <cstdlib>



/*Quick Sort*/
template <typename T> // Объявление шаблонной функции с одним параметром 
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high]; // Выбор опорного элемента
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
int randomPartition(std::vector<T>& arr, int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());// Генератор случайных чисел
    std::uniform_int_distribution<int> dis(low, high);
    int randomIndex = dis(gen);
    std::swap(arr[randomIndex], arr[high]);

    return partition(arr, low, high);
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <typename T>
void printVector(const std::vector<T>& arr) { // Функция для вывода на экран
    for (const T& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


/*BubbleSort*/
template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*InsertionSort*/
template<typename T>
void insertionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main() {
    

    // Создаем массивы различных размеров
    unsigned int start_time, end_time, search_time;

    // Создаем массивы различных размеров и заполняем случайными значениями
    std::vector<int> arr1(10);
    for (int i = 0; i < arr1.size(); ++i) {
        arr1[i] = rand() % 100; // Генерация случайного числа от 0 до 99
    }

    std::vector<int> arr2(100);
    for (int i = 0; i < arr2.size(); ++i) {
        arr2[i] = rand() % 100; // Генерация случайного числа от 0 до 99
    }

    std::vector<int> arr3(1000);
    for (int i = 0; i < arr3.size(); ++i) {
        arr3[i] = rand() % 1000; // Генерация случайного числа от 0 до 999
    }

    std::vector<int> arr4(10000);
    for (int i = 0; i < arr4.size(); ++i) {
        arr4[i] = rand() % 10000; // Генерация случайного числа от 0 до 9999
    }

    std::vector<int> arr5(100000);
    for (int i = 0; i < arr5.size(); ++i) {
        arr5[i] = rand() % 100000; // Генерация случайного числа от 0 до 999999
    }
    // Измеряем время работы Quick Sort
    start_time = clock();
    quickSort(arr1, 0, arr1.size() - 1);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Quick Sort on array of size 10: " << search_time << " ms" << std::endl;

    start_time = clock();
    quickSort(arr2, 0, arr2.size() - 1);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Quick Sort on array of size 100: " << search_time << " ms" << std::endl;

    start_time = clock();
    quickSort(arr3, 0, arr3.size() - 1);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Quick Sort on array of size 1000: " << search_time << " ms" << std::endl;

    start_time = clock();
    quickSort(arr4, 0, arr4.size() - 1);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Quick Sort on array of size 10000: " << search_time << " ms" << std::endl;

    start_time = clock();
    quickSort(arr5, 0, arr5.size() - 1);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Quick Sort on array of size 100000: " << search_time << " ms" << std::endl;

    // Измеряем время работы Bubble Sort
    start_time = clock();
    bubbleSort(arr1);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Bubble Sort on array of size 10: " << search_time << " ms" << std::endl;

    start_time = clock();
    bubbleSort(arr2);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Bubble Sort on array of size 100: " << search_time << " ms" << std::endl;

    start_time = clock();
    bubbleSort(arr3);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Bubble Sort on array of size 1000: " << search_time << " ms" << std::endl;

    start_time = clock();
    bubbleSort(arr4);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Bubble Sort on array of size 10000: " << search_time << " ms" << std::endl;

    start_time = clock();
    bubbleSort(arr5);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Bubble Sort on array of size 100000: " << search_time << " ms" << std::endl;


    // Измеряем время работы Bucket Sort
    start_time = clock();
    insertionSort(arr1);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Insertion Sort on array of size 10: " << search_time << " ms" << std::endl;

    start_time = clock();
    insertionSort(arr2);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Insertion Sort on array of size 100: " << search_time << " ms" << std::endl;


    start_time = clock();
    insertionSort(arr3);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Insertion Sort on array of size 1000: " << search_time << " ms" << std::endl;

    start_time = clock();
    insertionSort(arr4);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Insertion Sort on array of size 10000: " << search_time << " ms" << std::endl;

    start_time = clock();
    insertionSort(arr5);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Insertion Sort on array of size 100000: " << search_time << " ms" << std::endl;

    return 0;
}




















