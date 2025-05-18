#pragma once
#include <iostream>
#include <vector>

#include "boost/signals2.hpp"

class ISortingAlgorithm {
  public:
    explicit ISortingAlgorithm(std::vector<int> &arr);

    virtual ~ISortingAlgorithm();

    // Основной метод сортировки
    virtual void sort() = 0;

    // Возвращает название алгоритма
    virtual std::string getName() const = 0;

    bool getSorted() const { return m_sorted; }

    // Возвращает текущий массив элементов
    std::vector<int> getCurrentState() const;

    // Сигнал для обновления визуализации массива
    boost::signals2::signal<void(const std::vector<int> &)> updateVisualization;

  protected:
    std::vector<int> m_arr; // Массив элементов
    int m_size;             // Размер массива
    bool m_sorted = false;  // Признак отсортирован ли массив
};