#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/GlobalConstants.hpp"
#include "Headers/NNDrawer.hpp"
#include "Headers/TextDrawer.hpp"

int main() {
    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;
    std::mt19937_64 random_engine(std::chrono::system_clock::now().time_since_epoch().count());

    sf::RenderWindow window(
            sf::VideoMode(2 * SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT),
            "Neural networks",
            sf::Style::Close);

    vector_2d neural_network(2 + HIDDEN_NEURONS.size());
    vector_3d weights(neural_network.size() - 1);

    sf::Event event;

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

        // Draw the neural network and output neuron values
        draw_neural_network(window, neural_network, weights);

        // Display everything on the window
        window.display();
    }

    return 0;
}
