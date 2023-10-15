//
// Created by davidandw190 on 10/15/23.
//

#include <algorithm>
#include <cfloat>
#include "Headers/GlobalConstants.hpp"
#include "Headers/MinElement.hpp"

float get_min_element(const vector_1d& vector) {
    return *std::min_element(vector.begin(), vector.end());
}

float get_min_element(const vector_2d& vector) {
    float output = FLT_MAX;

    for (const vector_1d& v : vector) {
        output = std::min(output, get_min_element(v));
    }

    return output;

}

float get_min_element(const vector_3d& vector) {
    float output = FLT_MAX;

    for (const vector_2d& v : vector) {
        output = std::min(output, get_min_element(v));
    }

    return output;

}