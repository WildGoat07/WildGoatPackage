#include "color.hpp"

using namespace wp;

CMYKColor::CMYKColor(HSLColor const& _c)
{
    *this = _c.asRGBColor();
}
CMYKColor::CMYKColor()
{
    c = 0;
    m = 0;
    y = 0;
    k = 0;
    a = 255;
}
CMYKColor::CMYKColor(sf::Color const& _c)
{
    c = 1 - wp::Various::percent(0, 255, _c.r);
    m = 1 - wp::Various::percent(0, 255, _c.g);
    y = 1 - wp::Various::percent(0, 255, _c.b);
    k = 1;
    k = std::min(std::min(c, m), y);
    if (k == 1)
    {
        c = 0;
        m = 0;
        y = 0;
    }
    else
    {
        c = (c - k) / (1 - k);
        m = (m - k) / (1 - k);
        y = (y - k) / (1 - k);
    }
}
CMYKColor::CMYKColor(CMYKColor const& _c)
{
    c = _c.c;
    m = _c.m;
    y = _c.y;
    k = _c.k;
    a = _c.a;
}
CMYKColor::CMYKColor(double _c, double _m, double _y, double _k, sf::Uint8 _a)
{
    c = _c;
    m = _m;
    y = _y;
    k = _k;
    a = _a;
}
sf::Color CMYKColor::asRGBColor() const
{
    if (c > 1)
        c = 1;
    if (c < 0)
        c = 0;
    if (m > 1)
        m = 1;
    if (m < 0)
        m = 0;
    if (y > 1)
        y = 1;
    if (y < 0)
        y = 0;
    if (k > 1)
        k = 1;
    if (k < 0)
        k = 0;
    sf::Color color;
    color.a = a;
    color.r = (1 - c) * 255 * (1 - k);
    color.g = (1 - m) * 255 * (1 - k);
    color.b = (1 - y) * 255 * (1 - k);
    return color;
}
HSLColor::HSLColor()
{

}
HSLColor::HSLColor(HSLColor const& c)
{
    hue = c.hue;
    saturation = c.saturation;
    lightness = c.lightness;
    alpha = c.alpha;
}
HSLColor::HSLColor(double h, double s, double l, sf::Uint8 a)
{
    hue = wp::Various::modulo(hue, 360);
    int frac = hue/360;
    hue -= frac*360;
    if (s > 1)
        s = 1;
    if (s < 0)
        s = 0;
    if (l > 1)
        l = 1;
    if (l < 0)
        l = 0;
    hue = h;
    saturation = s;
    lightness = l;
    alpha = a;
}
HSLColor::HSLColor(sf::Color const& c)
{
    hue = wp::Various::modulo(hue, 360);
    int frac = hue/360;
    hue -= frac*360;
    if (saturation > 1)
        saturation = 1;
    if (saturation < 0)
        saturation = 0;
    if (lightness > 1)
        lightness = 1;
    if (lightness < 0)
        lightness = 0;
    double r = c.r, g = c.g, b = c.b;
    double M, m, d;
    M = std::max(r, std::max(g, b));
    m = std::min(r, std::min(g, b));
    d = (M - m)/255.0;
    lightness = (M + m)/510.0;
    if (lightness == 0)
        saturation = 0;
    else
        saturation = d/(1 - std::abs(2*lightness - 1));
    if (g >= b)
    {
        hue = 180.0*std::acos((r - g/2 - b/2)/sqrt(r*r + g*g + b*b - r*g - r*b - g*b))/PI;
    }
    else
    {
        hue = 360.0 - 180.0*std::acos((r - g/2 - b/2)/sqrt(r*r + g*g + b*b - r*g - r*b - g*b))/PI;
    }
}
sf::Color HSLColor::asRGBColor() const
{
    hue = wp::Various::modulo(hue, 360);
    int frac = hue/360;
    hue -= frac*360;
    if (saturation > 1)
        saturation = 1;
    if (saturation < 0)
        saturation = 0;
    if (lightness > 1)
        lightness = 1;
    if (lightness < 0)
        lightness = 0;
    double r, g, b;
    double d = saturation*(1 - std::abs(2*lightness - 1));
    double m = 255*(lightness - d/2);
    double x = d*(1 - std::abs(wp::Various::modulo(hue/60.0, 2) - 1));
    if (hue < 60)
    {
        r = 255*d + m;
        g = 255*x + m;
        b = m;
    }
    else if (hue < 120)
    {
        r = 255*x + m;
        g = 255*d + m;
        b = m;
    }
    else if (hue < 180)
    {
        r = m;
        g = 255*d + m;
        b = 255*x + m;
    }
    else if (hue < 240)
    {
        r = m;
        g = 255*x + m;
        b = 255*d + m;
    }
    else if (hue < 300)
    {
        r = 255*x + m;
        g = m;
        b = 255*d + m;
    }
    else
    {
        r = 255*d + m;
        g = m;
        b = 255*x + m;
    }
    return sf::Color(r, g, b, alpha);
}
HSLColor::HSLColor(CMYKColor const& c)
{
    *this = c.asRGBColor();
}
