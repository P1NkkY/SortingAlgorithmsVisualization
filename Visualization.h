#pragma once

#include "ISorting.h"
#include "SFML/Graphics.hpp"
#include <thread>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Visualization {
  public:
    explicit Visualization(unsigned int width, unsigned int height, int _size,
                           std::vector<int> _vec);

    void Update(const std::vector<int> &vec);

    void Start();

  private:
    void Clear();

    void Display();

  private:
    sf::RenderWindow *m_window;
    std::vector<sf::RectangleShape> m_rectangles;
    std::vector<int> m_vec;
    int m_size;
    std::thread th;
};