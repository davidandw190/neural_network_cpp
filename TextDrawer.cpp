#include <SFML/Graphics.hpp>
#include "Headers/TextDrawer.hpp"

void draw_text(bool horizontalCenter, bool vertical_center, short x, short y, const std::string& text, const sf::Color& color, sf::RenderWindow& window, const sf::Texture& font_texture) {
    short char_x = x;
    short char_y = y;

    unsigned char char_height = font_texture.getSize().y;
    unsigned char char_width = font_texture.getSize().x / 96;

    sf::Sprite char_sprite(font_texture);
    char_sprite.setColor(color);

    if (horizontalCenter) {
        char_x -= static_cast<short>(0.5f * char_width * text.substr(0, text.find_first_of('\n')).size());
    }

    if (vertical_center) {
        char_y -= static_cast<short>(0.5f * char_height * (1 + std::count(text.begin(), text.end(), '\n')));
    }

    for (std::string::const_iterator it = text.begin(); it != text.end(); it++) {
        if (*it == '\n') {
            if (horizontalCenter) {
                char_x = x - static_cast<short>(0.5f * char_width * text.substr(0, text.find_first_of('\n')).size());
            } else {
                char_x = x;
            }

            char_y += char_height;
            continue;
        }

        char_sprite.setPosition(char_x, char_y);
        char_sprite.setTextureRect(sf::IntRect(char_width * (*it - 32), 0, char_width, char_height));

        char_x += char_width;

        window.draw(char_sprite);
    }
}
