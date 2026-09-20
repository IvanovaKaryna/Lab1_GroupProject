#pragma once

#include <vector>
#include <utility>

struct InputData
{
    std::vector<std::vector<int>> graph;
    int startVertex;
};

struct Result
{
    std::vector<int> order;
    std::vector<int> reachable;
};