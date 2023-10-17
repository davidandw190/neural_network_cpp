//
// Created by davidandw190 on 10/14/23.
//

#ifndef NEURAL_NETWORK_CPP_TEXTDRAWER_HPP
#define NEURAL_NETWORK_CPP_TEXTDRAWER_HPP

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

void draw_text(bool i_horizontal_center, bool i_vertical_center, short i_x, short i_y, const std::string& i_text, const sf::Color& i_color, sf::RenderWindow& i_window, const sf::Texture& i_font_texture);

#endif //NEURAL_NETWORK_CPP_TEXTDRAWER_HPP