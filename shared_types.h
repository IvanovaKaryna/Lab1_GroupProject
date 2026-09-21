#pragma once

#include <vector>
#include <memory>

struct InputData
{
    std::vector<std::vector<int>> adjacencyList;
    int startVertex;
};

struct Result
{
    std::vector<int> traversalOrder;
    std::vector<int> reachableVertices;
};