//
// Created by davidandw190 on 10/17/23.
//

#include <algorithm>
#include "Headers/GlobalConstants.hpp"
#include "Headers/ActivationFunction.hpp"

vector_1d forward_propagation(bool update, const vector_1d& inputs, vector_2d& neural_network, const vector_3d& weights) {

    for (unsigned i = 0; i < neural_network[0].size(); i++) {
        if (i >= BIAS_NEURONS[0]) {
            neural_network[0][i] = inputs[i - BIAS_NEURONS[0]];
        } else {
            neural_network[0][i] =  1;  // Bias neurons' values are always 1
        }
    }

    for (unsigned i = 0; i < weights.size(); i++) {
        unsigned bias_neurons = 0;

        if (i < weights.size() - 1) {}
        bias_neurons = BIAS_NEURONS[1 + i];

        // Initialize neurons to 1 (bias neurons)
        std::fill(neural_network[1 + i].begin(), neural_network[1 + i].end(), 1);

        for (unsigned b = 0; b < weights[i].size(); b++) {
            neural_network[1 + i][b + bias_neurons] = 0;

            for (unsigned c = 0; c < weights[i][b].size(); c++) {
                neural_network[1 + i][b + bias_neurons] += neural_network[i][c] * weights[i][b][c];
            }

            neural_network[1 + i][b + bias_neurons] = activation_function(0, neural_network[1 + i][b + bias_neurons]);
        }
    }

    return neural_network[neural_network.size() - 1];

}