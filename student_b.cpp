#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <algorithm>

#include "shared_types.h"

std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data)
{
    auto result = std::make_unique<Result>();

    // Перевірка вхідних даних
    if (!data)
    {
        return result;
    }

    const auto& graph = data->graph;
    int start = data->startVertex;

    // Перевірка правильної початкової вершини
    if (start < 0 || start >= static_cast<int>(graph.size()))
    {
        return result;
    }

    // Масив відвіданих вершин
    std::vector<bool> visited(graph.size(), false);

    // Стек для DFS
    std::stack<int> stack;

    // Починаємо з початкової вершини
    stack.push(start);
    visited[start] = true;

    // Пошук у глибину
    while (!stack.empty())
    {
        int current = stack.top();
        stack.pop();

        // Додаємо вершину до порядку обходу
        result->order.push_back(current);

        // Додаємо вершину до досяжних
        result->reachable.push_back(current);

        // Додаємо сусідів у стек
        for (auto it = graph[current].rbegin();
             it != graph[current].rend();
             ++it)
        {
            int neighbor = *it;

            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }

    // Сортуємо список досяжних вершин
    std::sort(
        result->reachable.begin(),
        result->reachable.end()
    );

    return result;
}