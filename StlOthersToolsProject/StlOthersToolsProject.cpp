// StlOthersToolsProject.cpp 
//

#include <iostream>
#include <chrono>
#include <iomanip>

void BubbleSort(int* array, int size)
{
    for (int i{}; i < size; i++)
        for (int j = size - 1; j > i; j--)
            if (array[j] < array[j - 1])
                std::swap(array[j], array[j - 1]);
}

void QuickSort(int* array, int begin, int end)
{
    int left{ begin };
    int right{ end };
    int middle{ array[(begin + end) / 2] };

    do
    {
        while (array[left] < middle) left++;
        while (array[right] > middle) right--;
        if (left <= right)
        {
            std::swap(array[left], array[right]);
            left++;
            right--;
        }
    } while (left <= right);

    if (begin < right) QuickSort(array, begin, right);
    if (left < end) QuickSort(array, left, end);
}

void PrintArray(int* array, int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}


int main()
{
    /*auto nowFirst = std::chrono::system_clock::now();
    std::cout << nowFirst << "\n";*/

    srand(time(nullptr));
    int size{ 1000000 };
    int* array1 = new int[size];
    int* array2 = new int[size];

    for (int i{}; i < size; i++)
    {
        int num{ rand() % 100 };
        array1[i] = num;
        array2[i] = num;
    }

    //PrintArray(array1, size);

    auto nowFirst = std::chrono::system_clock::now();
    BubbleSort(array1, size);
    //PrintArray(array1, size);
    auto nowSecond = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration1 = nowFirst - nowSecond;
    std::cout << std::fixed << duration1 << "\n";

    nowFirst = std::chrono::system_clock::now();
    QuickSort(array2, 0, size - 1);
    //PrintArray(array2, size);
    nowSecond = std::chrono::system_clock::now();
    duration1 = nowFirst - nowSecond;
    std::cout << std::fixed << duration1 << "\n";
}
