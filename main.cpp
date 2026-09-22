#include <iostream>
#include <memory>

#include "shared_types.h"

// Функція Студента Б
std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data);

int main()
{
    std::cout << "Lab1 Group Project" << std::endl;

    // Спільні вхідні дані
    auto data = std::make_shared<const InputData>(
        InputData{
            {
                {1, 2},       // 0
                {0, 3, 4},    // 1
                {0, 5},       // 2
                {1, 6},       // 3
                {1, 7},       // 4
                {2},          // 5
                {3},          // 6
                {4}           // 7
            },
            0
        }
    );

    // Алгоритм Студента Б — DFS
    auto resultB = calculateB(data);

    // Structured bindings
    auto [orderB, reachableB] = *resultB;

    // Виведення порядку обходу
    std::cout << "\nDFS traversal order: ";

    for (int vertex : orderB)
    {
        std::cout << vertex << " ";
    }

    // Виведення досяжних вершин
    std::cout << "\nReachable vertices: ";

    for (int vertex : reachableB)
    {
        std::cout << vertex << " ";
    }

    std::cout << "\n";

    return 0;
}