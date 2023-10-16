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

/**
 * @brief Draw the neural network including neurons, their values, and connections between them.
 *
 * @param window The SFML RenderWindow to draw on.
 * @param neural_network The 2D vector representing the neural network layers and neuron values.
 * @param weights The 3D vector representing the weights between neurons.
 */
void draw_neural_network(sf::RenderWindow& window, const vector_2d& neural_network, const vector_3d& weights) {

    // Compute the maximum and minimum neuron values for color scaling
    float max_neuron = std::max(abs(get_max_element(neural_network)), abs(get_min_element(neural_network)));
    float min_neuron = -max_neuron;

    // Circle shape to represent neurons
    sf::CircleShape neuron_shape(NEURON_SHAPE_RADIUS);
    neuron_shape.setOutlineColor(sf::Color(255, 255, 255));
    neuron_shape.setOutlineThickness(-LINE_THICKNESS);

    // Vertex array for connecting lines
    sf::VertexArray connection_shape(sf::Quads, 4);

    if (get_min_element(neural_network) >= 0) {
        min_neuron = 0;
    }

    for (unsigned char i = 0; i < neural_network.size(); i++) {

        unsigned short neuron_x = SCREEN_WIDTH * (1 + i) / (1 + neural_network.size());

        for (unsigned j = 0; j < neural_network[i].size(); j++) {

            // Rounding the value of the neuron to the nearest [DECIMAL_DIGITS] digits after the decimal point.
            float neuron_value = round(neural_network[i][j] * pow(10, DECIMAL_DIGITS)) / pow(10, DECIMAL_DIGITS);

            // Compute the color for the neuron based on its value
            unsigned char neuron_color = round(255 * (neural_network[i][j] - min_neuron) / (max_neuron - min_neuron));

            // Determine text color based on background color
            unsigned char text_color = 255 * (128 > neuron_color);

            unsigned short neuron_y = SCREEN_HEIGHT * (1 + j) / (1 + neural_network[i].size());

            // Create a stringstream to format the neuron value for display
            std::ostringstream neuron_text_stream;
            neuron_text_stream << std::fixed << std::setprecision(DECIMAL_DIGITS) << neuron_value;

            // Set the neuron color for rendering
            neuron_shape.setFillColor(sf::Color(neuron_color, neuron_color, neuron_color));

            // Set the position for the neuron
            neuron_shape.setPosition(neuron_x - NEURON_SHAPE_RADIUS, neuron_y - NEURON_SHAPE_RADIUS);

            // Check if there are connections to draw for this layer
            if ( i < neural_network.size() - 1) {
                float max_weight = std::max(abs(get_max_element(weights[i])), abs(get_min_element(weights[i])));
                float min_weight = -max_weight;

                unsigned bias_neurons = 0;

                if (i < neural_network.size() - 2) {
                    bias_neurons = BIAS_NEURONS[1 + i];
                }

                for (unsigned k=bias_neurons; k < neural_network[1 + i].size(); k++) {
                    if (0 <= weights[i][k - bias_neurons][j]) {
                        // Compute the connection opacity based on weight
                        unsigned char connection_opacity = std::round(255 * weights[i][k][j] / max_weight);

                        // Set connection color to green for positive weights
                        connection_shape[0].color = sf::Color(0, 255, 0, connection_opacity);
                        connection_shape[1].color = sf::Color(0, 255, 0, connection_opacity);
                        connection_shape[2].color = sf::Color(0, 255, 0, connection_opacity);
                        connection_shape[3].color = sf::Color(0, 255, 0, connection_opacity);
                    } else  {
                        // Compute the connection opacity based on weight
                        unsigned char connection_opacity = std::round(255 * weights[i][k - bias_neurons][j] / min_weight);

                        // Set connection color to red for negative weights
                        connection_shape[0].color = sf::Color(255, 0, 0, connection_opacity);
                        connection_shape[1].color = sf::Color(255, 0, 0, connection_opacity);
                        connection_shape[2].color = sf::Color(255, 0, 0, connection_opacity);
                        connection_shape[3].color = sf::Color(255, 0, 0, connection_opacity);
                    }

                    // Compute the positions for connection lines
                    unsigned short prev_neuron_x = SCREEN_WIDTH * (2 + i) / (1 + neural_network.size());
                    unsigned short prev_neuron_y = SCREEN_HEIGHT * (1 + k) / (1 + neural_network[1 + i].size());

                    connection_shape[0].position = sf::Vector2f(prev_neuron_x, prev_neuron_y - 0.5f * LINE_THICKNESS);
                    connection_shape[1].position = sf::Vector2f(neuron_x, neuron_y - 0.5f * LINE_THICKNESS);
                    connection_shape[2].position = sf::Vector2f(neuron_x, neuron_y + 0.5f * LINE_THICKNESS);
                    connection_shape[3].position = sf::Vector2f(prev_neuron_x, prev_neuron_y + 0.5f * LINE_THICKNESS);

                    // Draw the connection line
                    window.draw(connection_shape);
                }

            }

            // Draw the neuron shape
            window.draw(neuron_shape);

            // Output neuron values in the console
            std::cout << "Neuron [" << i << "][" << j << "]: " << neural_network[i][j] << std::endl;
        }
    }
}
