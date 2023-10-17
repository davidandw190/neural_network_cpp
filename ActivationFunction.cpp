//
// Created by davidandw190 on 10/17/23.
//

#include <algorithm>
#include <cmath>
//
#include "Headers/ActivationFunction.hpp"

float activation_function(bool derivative, float input) {
    if (!derivative) {
        if (input <= 0) {
            return std::pow(2, input - 1);
        } else {
            return 1 - std::pow(2, -1 - input);
        }
    } else {

        if (input <= 0) {
            // derivative = log(2) * 2^(input - 1)
            return std::log(2) * std::pow(2, input - 1);
        } else {
            // derivative = log(2) * 2^(-1 - input)
            return std::log(2) * std::pow(2, -1 - input);
        }
    }
 }
