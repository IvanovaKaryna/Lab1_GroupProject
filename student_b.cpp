#include <memory>
#include <stack>
#include <vector>
#include <algorithm>

#include "shared_types.h"

std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data)
{
    auto result = std::make_unique<Result>();

    if (!data)
    {
        return result;
    }

    const auto& graph = data->adjacencyList;
    int start = data->startVertex;

    if (start < 0 || start >= static_cast<int>(graph.size()))
    {
        return result;
    }

    std::vector<bool> visited(graph.size(), false);
    std::stack<int> stack;

    stack.push(start);
    visited[start] = true;

    while (!stack.empty())
    {
        int current = stack.top();
        stack.pop();

        result->traversalOrder.push_back(current);
        result->reachableVertices.push_back(current);

        for (auto it = graph[current].rbegin();
             it != graph[current].rend();
             ++it)
        {
            int neighbor = *it;

            if (neighbor >= 0 &&
                neighbor < static_cast<int>(graph.size()) &&
                !visited[neighbor])
            {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }

    std::sort(
        result->reachableVertices.begin(),
        result->reachableVertices.end()
    );

    return result;
}
