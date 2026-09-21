#include "shared_types.h"

#include <queue>
#include <memory>
#include <vector>

std::unique_ptr<Result> runStudentA(std::shared_ptr<const InputData> input)
{
    auto result = std::make_unique<Result>();

    const int n = static_cast<int>(input->adjacencyList.size());

    if (input->startVertex < 0 || input->startVertex >= n) {
        return result;
    }

    std::vector<bool> visited(n, false);
    std::queue<int> queue;

    visited[input->startVertex] = true;
    queue.push(input->startVertex);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        result->traversalOrder.push_back(current);
        result->reachableVertices.push_back(current);

        for (int neighbor : input->adjacencyList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }

    return result;
}