#include "SortingVisualization.h"

SortingVisualization::SortingVisualization(ISortingAlgorithm &sorter)
    : m_sorter(sorter) {
    m_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                    m_sorter.getName());
    init(m_sorter.getArray());

    // Connect signal and slot
    m_connection = m_sorter.updateVisualization.connect(boost::bind(
        &SortingVisualization::updateWindow, this, boost::placeholders::_1));
}

SortingVisualization::~SortingVisualization() {
    std::cout << "~SortingVisualization" << std::endl;
}

void SortingVisualization::start() {
    bool firstTime = true; // To display start array
    while (m_window->isOpen()) {
        sf::Event event;
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                onEventTypeClosed();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                onEventMouseButtonPressed(event);
            }
        }
        if (m_sorter.isRunning() || firstTime) {
            clear();
            draw();
            display();
            firstTime = false;
        }
    }
}

void SortingVisualization::updateWindow(const std::vector<int> &arr) {
    std::unique_lock<std::mutex> locker(m_locker);

    updateBars(arr);

    // sf::sleep(sf::milliseconds(3));
}

void SortingVisualization::clear() { m_window->clear(sf::Color::Black); }

void SortingVisualization::draw() {
    std::unique_lock<std::mutex> locker(m_locker);
    for (auto bar : bars) {
        m_window->draw(bar);
    }
}

void SortingVisualization::display() { m_window->display(); }

void SortingVisualization::onEventTypeClosed() {
    std::unique_lock<std::mutex> locker(m_locker);
    m_connection.disconnect(); // Disconnect form signals
    m_sorter.stop();
    m_window->close();
}

void SortingVisualization::onEventMouseButtonPressed(const sf::Event &event) {
    if (event.mouseButton.button == sf::Mouse::Left && !m_sorter.isRunning()) {
        m_sorter.start();
    }
}
