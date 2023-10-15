#include <SFML/Graphics.hpp>
#include "Headers/TextDrawer.hpp"

void draw_text(bool horizontal_center, bool vertical_center, short x, short y, const std::string& text, const sf::Color& color, sf::RenderWindow& window, const sf::Texture& font_texture) {
    auto char_x = static_cast<float>(x);
    auto char_y = static_cast<float>(y);

    unsigned char char_height = static_cast<unsigned char>(font_texture.getSize().y);
    unsigned char char_width = static_cast<unsigned char>(font_texture.getSize().x / 96);

    sf::Sprite char_sprite(font_texture);
    char_sprite.setColor(color);

    if (horizontal_center) {
        char_x -= 0.5f * char_width * static_cast<float>(text.substr(0, text.find_first_of('\n')).size()); // Cast to float
    }

    if (vertical_center) {
        char_y -= 0.5f * char_height * (1 + static_cast<float>(std::count(text.begin(), text.end(), '\n'))); // Cast to float
    }

    for (std::string::const_iterator it = text.begin(); it != text.end(); it++) {
        if (*it == '\n') {
            if (horizontal_center) {
                char_x = static_cast<float>(x) - 0.5f * char_width * static_cast<float>(text.substr(0, text.find_first_of('\n')).size()); // Cast to float
            } else {
                char_x = static_cast<float>(x);
            }

            char_y += static_cast<float>(char_height);
            continue;
        }

        char_sprite.setPosition(char_x, char_y);
        char_sprite.setTextureRect(sf::IntRect(char_width * (*it - 32), 0, char_width, char_height));

        char_x += static_cast<float>(char_width);

        window.draw(char_sprite);
    }
}
