#ifndef DEF_VARIOUS_HPP
#define DEF_VARIOUS_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <windows.h>
#include <memory>
#include "Function.hpp"
#define PI 3.141592653589793
#define EXP 2.718281828459045


using std::shared_ptr;

namespace wp
{
    /** \brief Interface with various functions.
    *
    *   Interface containing various and useful functions and algorithms.
     */
    class Various
    {
    protected:
        Various() {}
    public:
        /** \brief Crypts a string.
        *
        *   Crypts a string with a key.
         *
         * \param const& std::string : the string to crypt.
         * \param std::string const& : the key (Optional).
         * \return std::string : the crypted string.
         *
         */
        static std::string crypt(std::string const&, std::string const& = "");
        /** \brief Uncrypts a string.
        *
        *   Uncrypts a string with a key.
         *
         * \param const& std::string : the string to uncrypt.
         * \param std::string const& : the key (Optional).
         * \return std::string : the uncrypted string.
         *
         */
        static std::string uncrypt(std::string const&, std::string const& = "");
        /** \brief Powerfully crypts a string
        *
        *   Crypts a string that can't be uncrypted.
         *
         * \param const& std::string : the string to crypt.
         * \param unsigned int : the length, must superior than the size of the string (Optionnal).
         * \return std::string : the crypted string.
         *
         */
        static std::string oneWayCrypt(std::string const&, unsigned int = 16);
        /** \brief Converts dec to hex
        *
        *   Converts a decimal number (as a string) to an hexadecimal number (as a string).
         *
         * \param const& std::string : decimal number.
         * \return std::string : hexadecimal number.
         *
         */
        static std::string decToHex(std::string const&);
        /** \brief Converts hex to dec
        *
        *   Converts an hexadecimal number (as a string) to a decimal number.
         *
         * \param const& std::string : hexadecimal number.
         * \return long long : decimal number.
         *
         */
        static long long  hexToDec(std::string const&);
        /** \brief Converts dec to hex
        *
        *   Converts a decimal number to an hexadecimal number (as a string).
         *
         * \param long long : decimal number.
         * \return std::string : hexadecimal number.
         *
         */
        static std::string decToHex(long long);
        /** \brief Converts a double to a string.
         *
         * \param long double : number to convert.
         * \return std::string : result.
         *
         */
        static std::string doubleToString(long double);
        /** \brief Converts an int to a string.
         *
         * \param long long : number to convert.
         * \return std::string : result.
         *
         */
        static std::string intToString(long long);
        /** \brief Converts a string to a number.
         *
         * \param const& std::string : number (as a string).
         * \return double : result.
         *
         */
        static long double stringToDouble(std::string const&);
        /** \brief Returns the angle of a vector.
        *
        *   Returns the angle of a vector in a direct 2D plan.
         *
         * \param const& sf::Vector2f : the vector.
         * \return double : the angle.
         *
         */
        static double getAngle(sf::Vector2f const&);
        /** \brief Returns the key name.
        *
        *   Returns the name equivalent of the specified mouse key.
         *
         * \param sf::Mouse::Button : the key.
         * \return std::string : the name.
         *
         */
        static std::string getMouseKey(sf::Mouse::Button);
        /** \brief Returns the key name.
        *
        *   Returns the name equivalent of the specified keyboard key.
         *
         * \param sf::Keyboard::Key : the key.
         * \return std::string : the name.
         *
         */
        static std::string getKeyboardKey(sf::Keyboard::Key);
        /** \brief Normalizes a vector.
         *
         * \param const& sf::Vector2f : the vector to normalize.
         * \return sf::Vector2f : result.
         *
         */
        static sf::Vector2f normalize(sf::Vector2f const&);
        /** \brief Returns the length of a vector.
         *
         * \param const& sf::Vector2f : the vector.
         * \return double : the length of the vector.
         *
         */
        static double length(sf::Vector2f const&);
        /** \brief Returns a percent.
        *
        *   Returns a percent of the value between the minimum and the maximum.
         *
         * \param double : the minimum.
         * \param double : the maximum.
         * \param double : the value.
         * \return double : the percent.
         *
         */
        static double percent(double, double, double);
        /** \brief Returns an interpolation of a percent.
        *
        *   Returns a linear interpolation of the percent between the minimum and the maximum with a specified degree.
         *
         * \param double : the minimum.
         * \param double : the maximum.
         * \param double : the percent.
         * \param double  : the degree (between 0 and 1) (Optional).
         * \return double : the result.
         *
         */
        static double linearInter(double, double, double, double = 0);
        /** \brief Returns an interpolation of a percent.
        *
        *   Returns a quadratic interpolation of the percent between the minimum and the maximum with a specified degree.
         *
         * \param double : the minimum.
         * \param double : the maximum.
         * \param double : the percent.
         * \param double  : the degree (superior than 1) (Optional).
         * \return double : the result.
         *
         */
        static double quadInter(double, double, double, double = 2);
        /** \brief Returns an interpolation of a percent.
        *
        *   Returns a reversed quadratic interpolation of the percent between the minimum and the maximum with a specified degree.
         *
         * \param double : the minimum.
         * \param double : the maximum.
         * \param double : the percent.
         * \param double  : the degree (superior than 1) (Optional).
         * \return double : the result.
         *
         */
        static double sqrtInter(double, double, double, double = 2);
        /** \brief Returns an interpolation of a percent.
        *
        *   Returns a gaussian-like interpolation of the percent between the minimum and the maximum with a specified degree.
         *
         * \param double : the minimum.
         * \param double : the maximum.
         * \param double : the percent.
         * \param double  : the degree (superior than 1) (Optional).
         * \return double : the result.
         *
         */
        static double gaussInter(double, double, double, double = 2);
        /** \brief Returns an interpolation of a percent.
        *
        *   Returns a reversed gaussian-like interpolation of the percent between the minimum and the maximum with a specified degree.
         *
         * \param double : the minimum.
         * \param double : the maximum.
         * \param double : the percent.
         * \param double  : the degree (superior than 1) (Optional).
         * \return double : the result.
         *
         */
        static double reverseGaussInter(double, double, double, double = 2);
        /** \brief Returns the modulo.
        *
        *   Returns the modulo between two double numbers.
         *
         * \param double : left number.
         * \param double : right number.
         * \return double : the modulo.
         *
         */
        static double modulo(double, double);
        /** \brief Returns a random number.
        *
        *   Returns a random number between the minimum and maximum. srand() required.
         *
         * \param double : the minimum (0 by default) (Optionnal).
         * \param double : the maximum (1 by default) (Optionnal).
         * \return double : a random number.
         *
         */
        static double randomDouble(double = 0, double = 1);
        /** \brief Loads an image from the RC file.
        *
        *   Returns an image extracted from the executable by the specified ID.
         *
         * \param std::string& const : the ID.
         * \return sf::Image : the image.
         *
         */
        static sf::Image loadImageFromResource(const std::string&);
        /** \brief Loads a font from the RC file.
        *
        *   Returns a font extracted from the executable by the specified ID.
         *
         * \param std::string& const : the ID.
         * \return sf::Font : the font.
         *
         */
        static sf::Font loadFontFromResource(const std::string&);
        /** \brief Loads a sound from the RC file.
        *
        *   Returns a sound buffer extracted from the executable by the specified ID.
         *
         * \param std::string& const : the ID.
         * \return sf::SoundBuffer : the sound.
         *
         */
        static sf::SoundBuffer loadSoundFromResource(const std::string&);
        /** \brief Loads a string from the RC file.
        *
        *   Returns a string extracted from the executable by the specified ID.
         *
         * \param std::string& const : the ID.
         * \return std::string : the string.
         *
         */
        static std::string loadStringFromResource(const std::string&);
        /** \brief Operates a point/shape collision
        *
        *   Returns true if the point is inside the shape.
         *
         * \param sf::Vector2f : the point to operate.
         * \param const& sf::ConvexShape : the shape.
         * \param sf::Vector2f : an infinite point (Optionnal).
         * \return bool : true if there is a collision.
         *
         */
        static bool shapeCollision(sf::Vector2f, sf::ConvexShape const&, sf::Vector2f = sf::Vector2f(-999999, 999999));
        /** \brief Operates a point/shape collision
        *
        *   Returns true if the point is inside the shape.
         *
         * \param sf::Vector2f : the point to operate.
         * \param const& std::vector<sf::Vector2f> : the shape.
         * \param sf::Vector2f : an infinite point (Optionnal).
         * \return bool : true if there is a collision.
         *
         */
        static bool shapeCollision(sf::Vector2f, std::vector<sf::Vector2f> const&, sf::Vector2f = sf::Vector2f(-999999, 999999));
        /** \brief Operates a segment collision
        *
        *   Returns true if the segments touch each other.
         *
         * \param sf::Vector2f : first point of the first segment.
         * \param sf::Vector2f : second point of the first segment.
         * \param sf::Vector2f : first point of the second segment.
         * \param sf::Vector2f : second point of the second segment.
         * \return bool : true if there is a collision.
         *
         */
        static bool segmentCollision(sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f);
        /** \brief Copies a string to the clipboard.
         *
         * \param std::string& const : the string to copy.
         * \return void
         *
         */
        static void copyToClipboard(const std::string&);
        /** \brief Returns the clipboard content.
         *
         * \return std::string : the clipboard content.
         *
         */
        static std::string getClipboardContent();
        /** \brief Truncates a number.
        *
        *   Truncates a number with a specified number of digits.
         *
         * \param double long : the number to truncate.
         * \param int : the number of digits (Optionnal).
         * \return long double : the result.
         *
         */
        static long double truncate(long double, int = 0);
        /** \brief Truncates a number upper.
        *
        *   Truncates a number upper with a specified number of digits.
         *
         * \param double long : the number to truncate.
         * \param int : the number of digits (Optionnal).
         * \return long double : the result.
         *
         */
        static long double truncateUp(long double, int = 0);
        /** \brief Rounds a number.
        *
        *   Rounds a number with a specified number of digits.
         *
         * \param double long : the number to round.
         * \param int : the number of digits (Optionnal).
         * \return long double : the result.
         *
         */
        static long double round(long double, int = 0);


    };
    static const sf::BlendMode BlendSubtract = sf::BlendMode(sf::BlendMode::OneMinusDstColor, sf::BlendMode::OneMinusSrcColor);/**< A subtract sf::BlendMode. */
    inline std::string Various::decToHex(std::string const& dec)
    {
        return decToHex(stringToDouble(dec));
    }
    inline long long Various::hexToDec(std::string const& hex)
    {
        std::stringstream ss;
        ss << hex;
        long long dec;
        ss >> std::hex >> dec;
        return dec;
    }
    inline std::string Various::decToHex(long long dec)
    {
        std::stringstream ss;
        ss << std::hex << dec;
        return ss.str();
    }
    inline std::string Various::doubleToString(long double nb)
    {
        std::stringstream ss;
        ss << nb;
        return ss.str();
    }
    inline std::string Various::intToString(long long nb)
    {
        std::stringstream ss;
        ss << nb;
        return ss.str();
    }
    inline long double Various::stringToDouble(std::string const& str)
    {
        std::stringstream ss;
        ss << str;
        double nb;
        ss >> nb;
        return nb;
    }
    inline sf::Vector2f Various::normalize(sf::Vector2f const& vec)
    {
        return sf::Vector2f(vec.x/length(vec), vec.y/length(vec));
    }
    inline double Various::length(sf::Vector2f const& vec)
    {
        return sqrt(vec.x*vec.x + vec.y*vec.y);
    }
    inline double Various::percent(double min, double max, double v)
    {
        return (v-min)/(max-min);
    }
    inline double Various::linearInter(double min, double max, double perc, double degre)
    {
        if (perc < degre/2)
            perc = 0;
        else if (perc > 1-degre/2)
            perc = 1;
        else
            perc = percent(degre/2, 1-degre/2, perc);
        return perc*(max-min) + min;
    }
    inline double Various::quadInter(double min, double max, double perc, double degre)
    {
        perc = pow(perc, degre);
        return perc*(max-min) + min;
    }
    inline double Various::sqrtInter(double min, double max, double perc, double degre)
    {
        perc = pow(perc, 1/degre);
        return perc*(max-min) + min;
    }
    inline double Various::gaussInter(double min, double max, double perc, double degre)
    {
        if (perc < 0.5)
            return quadInter(min, (max+min)/2, perc*2, degre);
        else
        {
            perc-= 0.5;
            perc = 0.5 - perc;
            return quadInter(max, (max+min)/2, perc*2, degre);
        }

    }
    inline double Various::reverseGaussInter(double min, double max, double perc, double degre)
    {
        if (perc < 0.5)
            return sqrtInter(min, (max+min)/2, perc*2, degre);
        else
        {
            perc-= 0.5;
            perc = 0.5 - perc;
            return sqrtInter(max, (max+min)/2, perc*2, degre);
        }

    }
    inline long double Various::truncate(long double val, int nb)
    {
        val *= pow(10, nb);
        val = (long long)val;
        val *= pow(10, -nb);
        return val;
    }
    inline long double Various::truncateUp(long double val, int nb)
    {
        long double val2 = val;
        val2 *= pow(10, nb);
        val2 = (long long)val2;
        val2 *= pow(10, -nb);
        if (val2 < val)
            val2 += pow(10, -nb);
        return val2;
    }
    inline long double Various::round(long double val, int nb)
    {
        val *= pow(10, nb);
        val = (long long)(val + 0.5);
        val *= pow(10, -nb);
        return val;
    }
}
sf::Vector2f operator/(sf::Vector2f, double);
sf::Vector2f operator*(double, sf::Vector2f);
sf::Vector2f operator*(sf::Vector2f, double);
sf::Vector2f operator*(sf::Vector2f, sf::Vector2f);

inline sf::Vector2f operator*(sf::Vector2f v1, sf::Vector2f v2)
{
    return sf::Vector2f(v1.x*v2.x, v1.y*v2.y);
}
inline sf::Vector2f operator*(sf::Vector2f v, double n)
{
    return sf::Vector2f(v.x*n, v.y*n);
}
inline sf::Vector2f operator*(double n, sf::Vector2f v)
{
    return v*n;
}
inline sf::Vector2f operator/(sf::Vector2f v, double n)
{
    return sf::Vector2f(v.x/n, v.y/n);
}

#endif // DEF_VARIOUS_HPP

