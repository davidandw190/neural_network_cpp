//
// Created by davidandw190 on 10/14/23.
//
#include <array>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <chrono>
#include <valarray>

#include "Headers/NNDrawer.h"
#include "Headers/GlobalConstants.h"

void draw_neural_network(sf::RenderWindow& i_window, const vector_2d& i_neural_network, const vector_3d& i_weights) {

    sf::CircleShape neuron_shape(NEURON_SHAPE_RADIUS);
    neuron_shape.setOutlineColor(sf::Color(255, 255, 255));
    neuron_shape.setOutlineThickness(-LINE_THICKNESS);

    for (unsigned char a = 0; a < i_neural_network.size(); a++) {

        unsigned short neuron_x = SCREEN_WIDTH * (1 + a) / (1 + i_neural_network.size());

        for (unsigned b = 0; b < i_neural_network[a].size(); b++) {

            //Rounding the value of the neuron to the nearest [DECIMAL_DIGITS] digits after the decimal point.
            float neuron_value = round(i_neural_network[a][b] * pow(10, DECIMAL_DIGITS)) / pow(10, DECIMAL_DIGITS);

            sf::VertexArray connection_shape(sf::Quads, 4);

            unsigned short neuron_y = SCREEN_HEIGHT * (1 + b) / (1 + i_neural_network[a].size());

            std::ostringstream neuron_text_stream;
            neuron_text_stream << std::fixed << std::setprecision(DECIMAL_DIGITS) << neuron_value;

            neuron_shape.setPosition(neuron_x - NEURON_SHAPE_RADIUS, neuron_y - NEURON_SHAPE_RADIUS);

            i_window.draw(neuron_shape);

            // Output neuron values in the console
            std::cout << "Neuron [" << a << "][" << b << "]: " << i_neural_network[a][b] << std::endl;
        }
    }
}
