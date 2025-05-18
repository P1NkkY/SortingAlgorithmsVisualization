#include "SortingVisualization.h"

SortingVisualization::SortingVisualization(ISortingAlgorithm &sorter)
    : m_sorter(sorter) {
    m_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                    m_sorter.getName());
    initData(m_sorter.getCurrentState().size());

    // Connect signal and slot
    m_sorter.updateVisualization.connect(boost::bind(
        &SortingVisualization::Update, this, boost::placeholders::_1));
}

SortingVisualization::~SortingVisualization() {
    std::cout << "~SortingVisualization" << std::endl;
}

void SortingVisualization::Start() {
    m_th = std::thread([this]() {
        // run the program as long as the window is open
        while (m_window->isOpen() && !m_sorter.getSorted()) {
            // check all the window's events that were triggered since the last
            // iteration of the loop
            sf::Event event;
            while (m_window->pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }
        }
        std::cout << "End of the loop" << std::endl;
    });
    m_th.detach();

    m_sorter.sort();
}

void SortingVisualization::Update(const std::vector<int> &arr) {
    // clear the window with black color
    Clear();

    updateBars(arr);

    for (auto bar : bars) {
        m_window->draw(bar);
    }

    // end the current frame
    Display();

    sf::sleep(sf::milliseconds(10));
}

void SortingVisualization::Clear() {
    // clear the window with black color
    m_window->clear(sf::Color::Black);
}

void SortingVisualization::Display() {
    // end the current frame
    m_window->display();
}