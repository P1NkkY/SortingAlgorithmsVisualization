#include <iostream>

#include "SortingVisualization.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quich_sort.h"
#include "selection_sort.h"
#include "utils.h"

class SortVisualizer {
   public:
    SortVisualizer(sf::RenderWindow& window, const std::vector<int>& data)
        : window(window), data(data) {}

    // Обновляем внутренние данные для отрисовки
    void updateData(const std::vector<int>& newData) { data = newData; }

    // Отрисовываем текущее состояние массива
    void draw() {
        window.clear(sf::Color::Black);

        float barWidth = static_cast<float>(window.getSize().x) / data.size();
        for (size_t i = 0; i < data.size(); ++i) {
            float barHeight = static_cast<float>(data[i]) * 2.0f;
            sf::RectangleShape bar(sf::Vector2f(barWidth - 1, barHeight));
            bar.setPosition(static_cast<float>(i) * barWidth,
                            static_cast<float>(window.getSize().y) - barHeight);
            bar.setFillColor(sf::Color(100, 150, 255));
            window.draw(bar);
        }

        window.display();
        sf::sleep(sf::milliseconds(20));  // задержка для анимации
    }

   private:
    sf::RenderWindow& window;
    std::vector<int> data;
};

int main() {
    std::vector<int> arr = createArray();

    // Создаём окно SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualizer");
    window.setFramerateLimit(60);

    // Генерируем случайные данные (или задаём вручную)
    std::vector<int> data = {5, 3, 8, 1, 2, 7, 4, 6};

    // Инициализируем визуализатор
    SortVisualizer visualizer(window, data);

    // Создаём лямбду-визуализатор, которая обновляет данные и рисует
    auto visualize = [&](const std::vector<int>& currentData) {
        visualizer.updateData(currentData);
        visualizer.draw();

        // Обрабатываем события окна, чтобы оно не зависало
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
    };

    // Вызываем сортировку с визуализацией
    // можно также добавить компаратор, если нужен
    sorting::bubble_sort::sort(data, std::greater<int>(),
                               visualize);  // сортировка по возрастанию

    // Финальная отрисовка (уже отсортировано)
    visualizer.draw();

    // Ожидание закрытия окна
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
    }

    return 0;
}
