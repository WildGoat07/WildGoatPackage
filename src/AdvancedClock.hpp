#ifndef DEF_ADVANCED_CLOCK_HPP
#define DEF_ADVANCED_CLOCK_HPP
#include "Chrono.hpp"

namespace wp
{
    /** \brief A clock with a time factor.
    *
    *   The time factor multiplies the elapsed time. A factor of 2 will double the speed of the clock.
    *
    *   \class AdvancedClock
     */
    class AdvancedClock : public Chrono
    {
    private:
        double m_factor = 1;
        void update() const;
    public:
        /** \brief Sets the time factor.
         *
         * \param double : time factor.
         * \return void
         *
         */
        void setFactor(double);
        /** \brief Returns the time factor.
         *
         * \return double : time factor.
         *
         */
        double getFactor() const;
    };
        inline void AdvancedClock::setFactor(double f)
        {
            update();
            m_factor = f;
        }
        inline double AdvancedClock::getFactor() const
        {
            return m_factor;
        }
}

#endif // DEF_ADVANCED_CLOCK_HPP
