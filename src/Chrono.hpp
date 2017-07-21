#ifndef CHRONO_HPP
#define CHRONO_HPP

#include <SFML/System.hpp>

namespace wp
{
    /** \brief Basic chronometer.
    *
    *   \class Chrono
    *
    *   Basic chronometer that can pause/stop/reset and assign a time preset.
     */
    class  Chrono
    {
    protected:
        mutable sf::Time m_time;
        mutable sf::Clock m_chrono;
        bool m_paused = false;
        void update() const;
    public:
        /** \brief Sets The current timer.
         *
         * \param sf::Time : the current time.
         * \return sf::Time : the time before calling this function.
         *
         */
        sf::Time setTime(sf::Time);
        /** \brief Pauses the chronometer.
         *
         * \return void
         *
         */
        void pause();
        /** \brief Plays the chronometer.
         *
         * \return void
         *
         */
        void play();
        /** \brief Stops the chronometer.
        *
        *   Stopping put the chronometer to 0 and pause it.
         *
         * \return sf::Time : time before stopping.
         *
         */
        sf::Time stop();
        /** \brief Returns the elapsed time.
         *
         * \return sf::Time : time elapsed.
         *
         */
        sf::Time getElapsedTime() const;
        /** \brief Restarts the chronometer.
         *
         * \return sf::Time : time before restarting.
         *
         */
        sf::Time restart();
        /** \brief If the chronometer is paused.
         *
         * \return bool : true if the chronometer is paused.
         *
         */
        bool isPaused() const;
    };

    inline sf::Time Chrono::setTime(sf::Time t)
    {
        sf::Time temp = getElapsedTime();
        m_time = t;
        return temp;
    }
    inline void Chrono::pause()
    {
        update();
        m_paused = true;
    }
    inline void Chrono::play()
    {
        update();
        m_paused = false;
    }
    inline sf::Time Chrono::stop()
    {
        pause();
        sf::Time temp = getElapsedTime();
        m_time = sf::Time::Zero;
        return temp;
    }
    inline sf::Time Chrono::getElapsedTime() const
    {
        update();
        return m_time;
    }
    inline sf::Time Chrono::restart()
    {
        play();
        sf::Time t = getElapsedTime();
        m_time = sf::Time::Zero;
        return t;
    }
    inline bool Chrono::isPaused() const
    {
        return m_paused;
    }
}
#endif // CHRONO_HPP
