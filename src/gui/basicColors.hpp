#ifndef DEF_WP_GUI_BASIC_COLORS_HPP
#define DEF_WP_GUI_BASIC_COLORS_HPP
#include "../Color.hpp"

namespace wp
{
    namespace gui
    {
        static const float hue = 220;
        static const float satur = 0.3;

        static const sf::Color background = wp::HSLColor(0, 0, 100.0/255);
        static const sf::Color altBackground = wp::HSLColor(0, 0, 85.0/255);
        static const sf::Color alt2Background = wp::HSLColor(0, 0, 25.0/255);
        static const sf::Color foreground = wp::HSLColor(0, 0, 170.0/255);
        static const sf::Color altForeground = wp::HSLColor(0, 0, 120.0/255);
        static const sf::Color border = wp::HSLColor(0, 0, 190.0/255);
        static const sf::Color altBorder = wp::HSLColor(0, 0, 20.0/255);
        static const sf::Color textColor = wp::HSLColor(0, 0, 210.0/255);
        static const sf::Color altTextColor = wp::HSLColor(0, 0, 30.0/255);
        static const sf::Color windowColor = wp::HSLColor(0, 0, 60.0/255);


        static const sf::Color background_c = wp::HSLColor(hue, satur, 100.0/255);
        static const sf::Color altBackground_c = wp::HSLColor(hue, satur, 85.0/255);
        static const sf::Color alt2Background_c = wp::HSLColor(hue, satur, 25.0/255);
        static const sf::Color foreground_c = wp::HSLColor(hue, satur, 170.0/255);
        static const sf::Color altForeground_c = wp::HSLColor(hue, satur, 120.0/255);
        static const sf::Color border_c = wp::HSLColor(hue, satur, 190.0/255);
        static const sf::Color altBorder_c = wp::HSLColor(hue, satur, 20.0/255);
        static const sf::Color textColor_c = wp::HSLColor(hue, satur, 210.0/255);
        static const sf::Color altTextColor_c = wp::HSLColor(hue, satur, 30.0/255);
        static const sf::Color windowColor_c = wp::HSLColor(hue, satur, 60.0/255);
    }
}

#endif // DEF_WP_GUI_BASIC_COLORS_HPP
