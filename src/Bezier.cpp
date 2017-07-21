#include "Bezier.hpp"

using namespace wp;

Bezier::Line::Line()
{

}
Bezier::Line::Line(sf::Vector2f f, sf::Vector2f s)
{
    start = f;
    direction = s;
}
sf::Vector2f Bezier::getValue(double t) const
{
    if (m_checkpoints.size() < 2)
    {
        std::cerr << "error " << this << " : the curve has too few arguments\n";
        return sf::Vector2f();
    }
    sf::Vector2f p;

    std::vector<Line> lines;
    for (int i = 0;i<size()-1;i++)
        lines.push_back(Line(m_checkpoints[i], m_checkpoints[i+1]-m_checkpoints[i]));
    while (lines.size() > 1)
    {
        std::vector<Line> lines2;
        for (int i = 0;i<lines.size()-1;i++)
        {
            Line l;
            l.start = lines[i].start + t*lines[i].direction;
            l.direction = lines[i+1].start + t*lines[i+1].direction;
            l.direction -= l.start;
            lines2.push_back(l);
        }
        lines = lines2;
    }
    p = lines[0].start + t*lines[0].direction;

    return p;
}
Bezier::Line Bezier::getTangeant(double t) const
{
    if (m_checkpoints.size() < 2)
    {
        std::cerr << "error " << this << " : the curve has too few arguments\n";
        return Line();
    }
    sf::Vector2f p;

    std::vector<Line> lines;
    for (int i = 0;i<size()-1;i++)
        lines.push_back(Line(m_checkpoints[i], m_checkpoints[i+1]-m_checkpoints[i]));
    while (lines.size() > 1)
    {
        std::vector<Line> lines2;
        for (int i = 0;i<lines.size()-1;i++)
        {
            Line l;
            l.start = lines[i].start + t*lines[i].direction;
            l.direction = lines[i+1].start + t*lines[i+1].direction;
            l.direction -= l.start;
            lines2.push_back(l);
        }
        lines = lines2;
    }
    lines[0].start = lines[0].start + t*lines[0].direction;
    lines[0].direction = wp::Various::normalize(lines[0].direction);
    return lines[0];
}
long double Bezier::length(uint32_t precision) const
{
    long double l = 0;
    for (long double i = 0;i<precision;i++)
    {
        l += wp::Various::length(getValue(i/precision) - getValue((i+1)/precision));
    }
    return l;
}
