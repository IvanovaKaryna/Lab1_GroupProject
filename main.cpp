#include "shared_types.h"

#include <chrono>
#include <iostream>
#include <memory>

std::unique_ptr<Result> runStudentA(
    std::shared_ptr<const InputData> input);

std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data);

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
    // Student a - bfs

    auto startBFS = std::chrono::high_resolution_clock::now();

    auto resultA = runStudentA(input);

    auto endBFS = std::chrono::high_resolution_clock::now();

    auto bfsTime =
        std::chrono::duration_cast<std::chrono::microseconds>(
            endBFS - startBFS
        ).count();

    auto& [traversalOrderA, reachableVerticesA] = *resultA;

    std::cout << "BFS traversal: ";

    for (int vertex : traversalOrderA)
    {
        std::cout << vertex << ' ';
    }

    std::cout << "\nReachable vertices: ";

    for (int vertex : reachableVerticesA)
    {
        std::cout << vertex << ' ';
    }

    std::cout << "\nVisited vertices: "
        << reachableVerticesA.size();

    std::cout << "\nExecution time: "
        << bfsTime << " microseconds\n";

    // Student b dfs

    auto startDFS = std::chrono::high_resolution_clock::now();

    auto resultB = calculateB(input);

    auto endDFS = std::chrono::high_resolution_clock::now();

    auto dfsTime =
        std::chrono::duration_cast<std::chrono::microseconds>(
            endDFS - startDFS
        ).count();

    auto& [traversalOrderB, reachableVerticesB] = *resultB;

    std::cout << "\nDFS traversal: ";

    for (int vertex : traversalOrderB)
    {
        std::cout << vertex << ' ';
    }

    std::cout << "\nReachable vertices: ";

    for (int vertex : reachableVerticesB)
    {
        std::cout << vertex << ' ';
    }

    std::cout << "\nVisited vertices: "
        << reachableVerticesB.size();

    std::cout << "\nExecution time: "
        << dfsTime << " microseconds\n";

    std::cout << "\n=== Comparison ===\n";

    std::cout << "Traversal orders are "
        << (traversalOrderA == traversalOrderB
            ? "the same"
            : "different")
        << ".\n";

    std::cout << "BFS visited vertices: "
        << reachableVerticesA.size() << '\n';

    std::cout << "DFS visited vertices: "
        << reachableVerticesB.size() << '\n';

    std::cout << "BFS execution time: "
        << bfsTime << " microseconds\n";

    std::cout << "DFS execution time: "
        << dfsTime << " microseconds\n";

    return 0;
}