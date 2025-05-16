#pragma once
#include <iostream>
#include <vector>

class ISorting {
  public:
    explicit ISorting(std::vector<int> &data);

    virtual ~ISorting() = default;

    virtual void Calculate() = 0;

  protected:
    std::vector<int> m_data;
    int m_size;
};