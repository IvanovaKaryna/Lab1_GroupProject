#include "shared_types.h"

#include <iostream>
#include <memory>

std::unique_ptr<Result> runStudentA(
    std::shared_ptr<const InputData> input);

int main()
{
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

    auto resultA = runStudentA(input);

    auto& [traversalOrder, reachableVertices] = *resultA;

    std::cout << "BFS traversal: ";

    for (int vertex : traversalOrder) {
        std::cout << vertex << ' ';
    }

    std::cout << "\nReachable vertices: ";

    for (int vertex : reachableVertices) {
        std::cout << vertex << ' ';
    }

    std::cout << '\n';

    return 0;
}