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
        float m_factor = 1;
        virtual void update() const override;
    public:
        /** \brief Sets the time factor.
         *
         * \param float : time factor.
         * \return void
         *
         */
        void setFactor(float);
        /** \brief Returns the time factor.
         *
         * \return float : time factor.
         *
         */
        float getFactor() const;
    };
        inline void AdvancedClock::setFactor(float f)
        {
            update();
            m_factor = f;
        }
        inline float AdvancedClock::getFactor() const
        {
            return m_factor;
        }
}

#endif // DEF_ADVANCED_CLOCK_HPP
