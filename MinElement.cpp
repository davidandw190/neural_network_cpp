//
// Created by davidandw190 on 10/15/23.
//

#include <algorithm>
#include <cfloat>
#include "Headers/GlobalConstants.hpp"
#include "Headers/MinElement.hpp"

/**
 * Find the minimum element in a one-dimensional vector.
 *
 * @param vector The input vector.
 * @return The minimum element in the vector.
 */
float get_min_element(const vector_1d& vector) {
    return *std::min_element(vector.begin(), vector.end());
}

/**
 * Find the minimum element in a two-dimensional vector.
 *
 * @param vector The input vector.
 * @return The minimum element in the vector.
 */
float get_min_element(const vector_2d& vector) {
    float output = FLT_MAX;

    for (const vector_1d& v : vector) {
        output = std::min(output, get_min_element(v));
    }

    return output;

}

/**
 * Find the minimum element in a three-dimensional vector.
 *
 * @param vector The input vector.
 * @return The minimum element in the vector.
 */
float get_min_element(const vector_3d& vector) {
    float output = FLT_MAX;

    for (const vector_2d& v : vector) {
        output = std::min(output, get_min_element(v));
    }

    return output;

}