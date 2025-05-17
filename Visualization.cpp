#include "Visualization.h"

Visualization::Visualization(unsigned int width, unsigned int height, int _size,
                             std::vector<int> _vec)
    : m_size(_size), m_vec(_vec) {
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), "My window");
}

void Visualization::Start() {
    th = std::thread([this]() {
        // run the program as long as the window is open
        while (m_window->isOpen()) {
            // check all the window's events that were triggered since the last
            // iteration of the loop
            sf::Event event;
            while (m_window->pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            // sf::sleep(sf::milliseconds(3));
        }
    });
    th.detach();
}

void Visualization::Clear() {
    // clear the window with black color
    m_window->clear(sf::Color::Black);
}

void Visualization::Display() {
    // end the current frame
    m_window->display();
}

void Visualization::Update(const std::vector<int> &vec) {
    // clear the window with black color
    Clear();

    m_vec = vec;

    int width = 5;
    std::vector<sf::RectangleShape> rectangles;
    rectangles.resize(m_size);
    for (int jter = 0; jter < m_size; jter++) {
        sf::RectangleShape rect(sf::Vector2f(width, m_vec[jter] * 3));
        rect.setPosition(sf::Vector2f(jter * 5 + jter, 0));
        rectangles[jter] = rect;
    }

    for (auto rect : rectangles) {
        m_window->draw(rect);
    }

    // end the current frame
    Display();

    // sf::sleep(sf::seconds(2));
}