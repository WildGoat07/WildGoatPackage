#ifndef DEF_COLOR_HPP
#define DEF_COLOR_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Various.hpp"


namespace wp
{
    class HSLColor;

    /** \brief Handles CMYKA format.
    *
    *   \class CMYKColor
    *
    *   Handles colors with the (cyan, magenta, yellow, key) components.
     */
    class CMYKColor
    {
    public:
        mutable double c;/**< the cyan component (0-1) */
        mutable double m;/**< the magenta component (0-1) */
        mutable double y;/**< the yellow component (0-1) */
        mutable double k;/**< the key component (0-1) */
        sf::Uint8 a;/**< the alpha channel (0-255) */
        /** \brief Basic constructor.
        *
        *   Creates a basic white color.
         *
         *
         */
        CMYKColor();
        /** \brief Constructor.
        *
        *   Constructs a CMYKColor from a sf::Color.
         *
         * \param sf::Color const& : the color to copy.
         *
         */
        CMYKColor(sf::Color const&);
        /** \brief Constructor.
        *
        *   Constructs a CMYKColor from a HSLColor.
         *
         * \param HSLColor const& : the color to copy.
         *
         */
        CMYKColor(HSLColor const&);
        /** \brief Copy constructor.
         *
         * \param CMYKColor const& : the color to copy.
         *
         */
        CMYKColor(CMYKColor const&);
        /** \brief Alternative constructor.
         *
         * \param double : cyan.
         * \param double : magenta.
         * \param double : yellow.
         * \param double : key.
         * \param sf::Uint8 : alpha.
         *
         */
        CMYKColor(double, double, double, double, sf::Uint8 = 255);
        /** \brief Converts the color to RBGA format.
         *
         * \return sf::Color : RGBA color.
         *
         */
        sf::Color asRGBColor() const;
        /** \brief Converts the color to HSLA format.
         *
         * \return HSLColor : HSLA color.
         *
         */
        HSLColor asHSLColor() const;
    };

    /** \brief Handles HSLA format.
    *
    *   \class HSLColor
    *
    *   Handles colors with the (hue, saturation, lightness) components.
     */
    class  HSLColor
    {
    public:
        mutable double hue = 0;/**< hue component (0-1) */
        mutable double saturation = 0;/**< saturation component (0-1) */
        mutable double lightness = 1;/**< lightness component (0-1) */
        sf::Uint8 alpha = 255;/**< alpha channel (0-255) */
        /** \brief Basic constructor.
        *
        *   Creates a basic white color.
         *
         *
         */
        HSLColor();
        /** \brief Copy constructor.
         *
         * \param HSLColor const& : color to copy.
         *
         */
        HSLColor(HSLColor const&);
        /** \brief Alternative constructor.
         *
         * \param double : hue.
         * \param double : saturation.
         * \param double : lightness.
         * \param sf::Uint8 : alpha.
         *
         */
        HSLColor(double, double, double, sf::Uint8 = 255);
        /** \brief Constructor.
        *
        *   Constructs a HSLColor from a sf::Color.
         *
         * \param sf::Color const& : the color to copy.
         *
         */
        HSLColor(sf::Color const&);
        /** \brief Converts the color to RBGA format.
         *
         * \return sf::Color : RGBA color.
         *
         */
        sf::Color asRGBColor() const;
        /** \brief Constructor.
        *
        *   Constructs a HSLColor from a CMYKColor.
         *
         * \param CMYKColor const& : the color to copy.
         *
         */
        HSLColor(CMYKColor const&);
        /** \brief Converts the color to CMYKA format.
         *
         * \return CMYKColor : CMYKA color.
         *
         */
        CMYKColor asCMYKColor() const;
    };
    inline HSLColor CMYKColor::asHSLColor() const
    {
        return HSLColor(asRGBColor());
    }
    inline CMYKColor HSLColor::asCMYKColor() const
    {
        return CMYKColor(asRGBColor());
    }
}


#endif // DEF_COLOR_HPP


