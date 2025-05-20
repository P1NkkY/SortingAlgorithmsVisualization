#pragma once

#include <iostream>
#include <numeric>
#include <random>

std::vector<int> createArray() {
    std::vector<int> res(100);
    std::iota(res.begin(), res.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(res.begin(), res.end(), g);

    return res;
}