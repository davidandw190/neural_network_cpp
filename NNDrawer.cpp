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

#include "Headers/NNDrawer.hpp"
#include "Headers/GlobalConstants.hpp"
#include "Headers/MaxElement.hpp"
#include "Headers/MinElement.hpp"

void draw_neural_network(sf::RenderWindow& window, const vector_2d& neural_network, const vector_3d& weights) {

    float max_neuron = std::max(abs(get_max_element(neural_network)), abs(get_min_element(neural_network)));
    float min_neuron = -max_neuron;

    sf::CircleShape neuron_shape(NEURON_SHAPE_RADIUS);
    neuron_shape.setOutlineColor(sf::Color(255, 255, 255));
    neuron_shape.setOutlineThickness(-LINE_THICKNESS);

    sf::VertexArray connection_shape(sf::Quads, 4);

    for (unsigned char i = 0; i < neural_network.size(); i++) {

        unsigned short neuron_x = SCREEN_WIDTH * (1 + i) / (1 + neural_network.size());

        for (unsigned j = 0; j < neural_network[i].size(); j++) {

            //Rounding the value of the neuron to the nearest [DECIMAL_DIGITS] digits after the decimal point.
            float neuron_value = round(neural_network[i][j] * pow(10, DECIMAL_DIGITS)) / pow(10, DECIMAL_DIGITS);

            unsigned char neuron_color = round(255 * (neural_network[i][j] - min_neuron) / (max_neuron - min_neuron));
            unsigned char text_color = 255 * (128 > neuron_color);


            unsigned short neuron_y = SCREEN_HEIGHT * (1 + j) / (1 + neural_network[i].size());

            std::ostringstream neuron_text_stream;
            neuron_text_stream << std::fixed << std::setprecision(DECIMAL_DIGITS) << neuron_value;

            neuron_shape.setFillColor(sf::Color(neuron_color, neuron_color, neuron_color));

            neuron_shape.setPosition(neuron_x - NEURON_SHAPE_RADIUS, neuron_y - NEURON_SHAPE_RADIUS);


            if ( i < neural_network.size() - 1) {
                float max_weight = std::max(abs(get_max_element(weights[i])), abs(get_min_element(weights[i])));
                float min_weight = -max_weight;

                unsigned bias_neurons = 0;
            }

            window.draw(neuron_shape);

            // Output neuron values in the console
            std::cout << "Neuron [" << i << "][" << j << "]: " << neural_network[i][j] << std::endl;
        }
    }
}
