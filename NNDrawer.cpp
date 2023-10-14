//
// Created by davidandw190 on 10/14/23.
//
#include <array>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Headers/NNDrawer.h"
#include "Headers/GlobalConstants.h"

void draw_neural_network(sf::RenderWindow& i_window, const std::vector<std::vector<float>>& i_neural_network) {
    sf::CircleShape neuron_shape(NEURON_SHAPE_RADIUS);

    for (unsigned char a = 0; a < i_neural_network.size(); a++) {
        for (unsigned b = 0; b < i_neural_network[a].size(); b++) {
            sf::CircleShape neuron_shape(NEURON_SHAPE_RADIUS);

            unsigned short neuron_x = SCREEN_WIDTH * (1 + a) / (1 + i_neural_network.size());
            unsigned short neuron_y = SCREEN_HEIGHT * (1 + b) / (1 + i_neural_network[a].size());

            neuron_shape.setPosition(neuron_x, neuron_y);

            i_window.draw(neuron_shape);

            // Output neuron values in the console
            std::cout << "Neuron [" << a << "][" << b << "]: " << i_neural_network[a][b] << std::endl;
        }
    }
}
