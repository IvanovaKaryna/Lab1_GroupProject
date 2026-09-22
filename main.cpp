#include "shared_types.h"

#include <iostream>
#include <memory>

// Student A
std::unique_ptr<Result> runStudentA(
    std::shared_ptr<const InputData> input);

// Student B
std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data);

int main()
{
    // Спільні вхідні дані
    auto input = std::make_shared<InputData>(
        InputData{
            {
                {1, 2},
                {0, 3, 4},
                {0},
                {1},
                {1}
            },
            0
        }
    );

    // Алгоритм Student A — BFS
    auto resultA = runStudentA(input);

    auto& [traversalOrder, reachableVertices] = *resultA;

    std::cout << "BFS traversal: ";

    for (int vertex : traversalOrder)
    {
        std::cout << vertex << ' ';
    }

    std::cout << "\nReachable vertices: ";

    for (int vertex : reachableVertices)
    {
        std::cout << vertex << ' ';
    }

    std::cout << '\n';

    // Алгоритм Student B — DFS
    auto resultB = calculateB(input);

    auto [orderB, reachableB] = *resultB;

    std::cout << "\nDFS traversal order: ";

    for (int vertex : orderB)
    {
        std::cout << vertex << ' ';
    }

    std::cout << "\nReachable vertices: ";

    for (int vertex : reachableB)
    {
        std::cout << vertex << ' ';
    }

    std::cout << '\n';

    return 0;
}