
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "Headers/GlobalConstants.h"


int main() {


    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;
    std::mt19937_64 random_engine(std::chrono::system_clock::now().time_since_epoch().count());

    sf::RenderWindow window(
            sf::VideoMode(2 * SCREEN_RESIZE * SCREEN_WIDTH,SCREEN_RESIZE * SCREEN_HEIGHT),
            "Neural networks",
            sf::Style::Close);

    sf::Event event;

    sf::CircleShape neuron_shape(NEURON_SHAPE_RADIUS);
    neuron_shape.setFillColor(sf::Color::White);
    neuron_shape.setRadius(NEURON_SHAPE_RADIUS);
    neuron_shape.setPosition(100, 100);


    window.setView(sf::View(sf::FloatRect(0, 0, 2 * SCREEN_WIDTH, SCREEN_HEIGHT)));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the neuron
        window.draw(neuron_shape);

        // Display everything on the window
        window.display();
    }

    return 0;

}
