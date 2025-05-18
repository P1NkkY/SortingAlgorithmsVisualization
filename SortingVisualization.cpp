#include "SortingVisualization.h"

SortingVisualization::SortingVisualization(ISortingAlgorithm &sorter)
    : m_sorter(sorter) {
    initData(m_sorter.getCurrentState().size());

    m_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                    m_sorter.getName());

    // Connect signal and slot
    m_sorter.updateVisualization.connect(boost::bind(
        &SortingVisualization::updateWindow, this, boost::placeholders::_1));
}

SortingVisualization::~SortingVisualization() {
    m_window->close();
    std::cout << "~SortingVisualization" << std::endl;
}

void SortingVisualization::start() {
    m_th = std::thread([this]() {
        while (m_window->isOpen()) {
            sf::Event event;
            while (m_window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }
        }
    });
    m_th.detach();

    m_sorter.sort();
}

void SortingVisualization::updateWindow(const std::vector<int> &arr) {
    clear();
    updateBars(arr);
    draw();
    display();

    sf::sleep(sf::milliseconds(10));
}

void SortingVisualization::clear() { m_window->clear(sf::Color::Black); }

void SortingVisualization::draw() {
    for (auto bar : bars) {
        m_window->draw(bar);
    }
}

void SortingVisualization::display() { m_window->display(); }
