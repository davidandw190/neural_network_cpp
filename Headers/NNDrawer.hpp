//
// Created by davidandw190 on 10/14/23.
//

#pragma once

#include "GlobalConstants.hpp"

#ifndef NEURAL_NETWORK_CPP_NNDRAWER_H
#define NEURAL_NETWORK_CPP_NNDRAWER_H

/**
 * @brief Draw the neural network including neurons, their values, and connections between them.
 *
 * @param window The SFML RenderWindow to draw on.
 * @param neural_network The 2D vector representing the neural network layers and neuron values.
 * @param weights The 3D vector representing the weights between neurons.
 */
void draw_neural_network(sf::RenderWindow& i_window, const vector_2d& i_neural_network, const vector_3d& i_weights);


#endif //NEURAL_NETWORK_CPP_NNDRAWER_H
