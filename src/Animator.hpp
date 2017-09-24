#ifndef DEF_ANIMATOR_HPP
#define DEF_ANIMATOR_HPP
#include "Function.hpp"
#include "Bezier.hpp"
#include "Chrono.hpp"
#include "Various.hpp"

namespace wp
{
    /** \brief Class to handle animations.
    *
    *   \class Animator
    *
    *   Handles transformable animations like translation/rotation/scale.
     */
    class Animator
    {
    private:
        float m_startRotation;
        float m_finalRotation;
        sf::Vector2f m_startScale;
        sf::Vector2f m_finalScale;
        Bezier m_move;
        Function* m_functionRotation = nullptr;
        Function* m_functionScaleX = nullptr;
        Function* m_functionScaleY = nullptr;
        Function* m_functionMoveX = nullptr;
        Function* m_functionMoveY = nullptr;
        int m_mode = TICKS;
        Chrono m_clock;
        sf::Uint64 m_ticks = 0;
        sf::Time m_time;
        sf::Uint64 m_ticksMax;
        bool m_started = false;
        bool m_finish = false;
        bool m_looped = false;
    public:
        enum Filter
        {
            ROTATION = 1,/**< enable rotation */
            SCALE_X = 2, /**< enable scaling on x */
            SCALE_Y = 4, /**< enable scaling on y */
            SCALE = SCALE_X | SCALE_Y, /**< enable scaling */
            MOTION_X = 8,/**< enable translation on x */
            MOTION_Y = 16,/**< enable translation on y */
            MOTION = MOTION_X | MOTION_Y,/**< enable translation */
            ALL = ROTATION | SCALE | MOTION/**< enable all */
        };
        enum Mode
        {
            TICKS,/**< using ticks as measurement */
            TIME/**< using time as measurement */
        };
        /** \brief Sets the starting rotation.
         *
         * \param float : starting rotation.
         * \return void
         *
         */
        void setStartRotation(float);
        /** \brief Sets the final rotation.
         *
         * \param float : final rotation.
         * \return void
         *
         */
        void setFinalRotation(float);
        /** \brief Sets the starting scale.
         *
         * \param sf::Vector2f : starting scale.
         * \return void
         *
         */
        void setStartScale(sf::Vector2f);
        /** \brief Sets the final scale.
         *
         * \param sf::Vector2f : final scale.
         * \return void
         *
         */
        void setFinalScale(sf::Vector2f);
        /** \brief Sets the motion (translation).
         *
         * \param Bezier const& : line of motion.
         * \return void
         *
         */
        void setMotion(Bezier const&);
        /** \brief Sets a precise function for the animation.
        *
        *   Sets a precise function for the rotation/scaling/motion using the filter. The function should follow the properties : f(0) = 0 and f(1) = 1.
         *
         * \param Function* = pointer to the function.
         * \param Filter = filter (Optional).
         * \return void
         *
         */
        void setFunction(Function*, Filter = ALL);
        /** \brief Sets the duration of the whole animation.
        *
        *   This version is using ticks.
         *
         * \param sf::Uint64 : number of ticks.
         * \return void
         *
         */
        void setDuration(sf::Uint64);
        /** \brief Sets the duration of the whole animation.
        *
        *   This version is using the time.
         *
         * \param sf::Time : duration of the animation.
         * \return void
         *
         */
        void setDuration(sf::Time);
        /** \brief Sets the offset duration.
        *
        *   This version is using ticks.
         *
         * \param sf::Uint64 : current ticks.
         * \return void
         *
         */
        void setCurrentProgress(sf::Uint64);
        /** \brief Sets the offset duration.
        *
        *   This version is using the time.
         *
         * \param sf::Time : current time.
         * \return void
         *
         */
        void setCurrentProgress(sf::Time);

        /** \brief Returns the starting rotation.
         *
         * \return float : starting rotation.
         *
         */
        float getStartRotation() const;
        /** \brief Returns the final rotation.
         *
         * \return float : final rotation.
         *
         */
        float getFinalRotation() const;
        /** \brief Returns the starting scale.
         *
         * \return sf::Vector2f : starting scale.
         *
         */
        sf::Vector2f getStartScale() const;
        /** \brief Returns the final scale.
         *
         * \return sf::Vector2f : final scale.
         *
         */
        sf::Vector2f getFinalScale() const;
        /** \brief Returns the motion line.
         *
         * \return Bezier const& : motion line.
         *
         */
        Bezier const& getMotion() const;
        /** \brief Returns the mode of animation.
        *
        *   The mode can be TICKS or TIME.
         *
         * \return Mode : mode.
         *
         */
        Mode getMode() const;
        /** \brief Returns the duration in ticks.
         *
         * \return sf::Uint64 : number of ticks.
         *
         */
        sf::Uint64 getTicksDuration() const;
        /** \brief Returns the duration time.
         *
         * \return sf::Time : duration time.
         *
         */
        sf::Time getTimeDuration() const;
        /** \brief Returns the current time in ticks.
         *
         * \return sf::Uint64 : number of ticks.
         *
         */
        sf::Uint64 getCurrentTick() const;
        /** \brief Returns the current time.
         *
         * \return sf::Time : current time.
         *
         */
        sf::Time getCurrentTime() const;
        /** \brief Starts the animation.
        *
        *   The animation will start from the beginning when called by start() using the provided mode.
         *
         * \return void
         *
         */
        void start();
        /** \brief Pauses the animation.
         *
         * \return void
         *
         */
        void pause();
        /** \brief Plays the paused animation.
        *
        *   Do not call play() to start the animation. Use start() instead.
         *
         * \return void
         *
         */
        void play();
        /** \brief Updates() the animation.
        *
        *   Required to get the right transformation when using the ticks mode and operate an ending animation.
         *
         * \return void
         *
         */
        void update();
        /** \brief Returns true if paused.
         *
         * \return bool : true if paused.
         *
         */
        bool isPaused() const;
        /** \brief Returns true if finished.
        *
        *   Always returns false when the animation is looped using setLooped().
         *
         * \return bool : true if the animation is finished.
         *
         */
        bool isFinished() const;
        /** \brief Sets the animation looped.
        *
        *   When finished, the animation will restart.
         *
         * \param bool : loop state.
         * \return void
         *
         */
        void setLooped(bool);
        /** \brief Returns true if the animation is looped.
         *
         * \return bool : true if animation is looped.
         *
         */
        bool isLooped() const;
        /** \brief Returns the transformation.
        *
        *   Returns the processed transformations of the animation as a sf::Transformable.
         *
         * \return sf::Transformable : transformations of the animation.
         *
         */
        sf::Transformable getTransformable() const;
    };

    inline void Animator::setStartRotation(float r)
    {
        m_startRotation = r;
    }
    inline void Animator::setFinalRotation(float r)
    {
        m_finalRotation = r;
    }
    inline void Animator::setStartScale(sf::Vector2f v)
    {
        m_startScale = v;
    }
    inline void Animator::setFinalScale(sf::Vector2f v)
    {
        m_finalScale = v;
    }
    inline void Animator::setMotion(Bezier const& m)
    {
        m_move = m;
    }
    inline void Animator::setDuration(sf::Uint64 t)
    {
        m_ticksMax = t;
        m_mode = TICKS;
    }
    inline void Animator::setDuration(sf::Time t)
    {
        m_time = t;
        m_mode = TIME;
    }
    inline void Animator::setCurrentProgress(sf::Uint64 t)
    {
        m_ticks = t;
    }
    inline void Animator::setCurrentProgress(sf::Time t)
    {
        m_clock.setTime(t);
    }
    inline float Animator::getStartRotation() const
    {
        return m_startRotation;
    }
    inline float Animator::getFinalRotation() const
    {
        return m_finalRotation;
    }
    inline sf::Vector2f Animator::getStartScale() const
    {
        return m_startScale;
    }
    inline sf::Vector2f Animator::getFinalScale() const
    {
        return m_finalScale;
    }
    inline Bezier const& Animator::getMotion() const
    {
        return m_move;
    }
    inline Animator::Mode Animator::getMode() const
    {
        return static_cast<Mode>(m_mode);
    }
    inline sf::Uint64 Animator::getTicksDuration() const
    {
        return m_ticksMax;
    }
    inline sf::Time Animator::getTimeDuration() const
    {
        return m_time;
    }
    inline sf::Uint64 Animator::getCurrentTick() const
    {
        return m_ticks;
    }
    inline sf::Time Animator::getCurrentTime() const
    {
        return m_clock.getElapsedTime();
    }
    inline bool Animator::isPaused() const
    {
        return !m_started;
    }
    inline bool Animator::isFinished() const
    {
        return m_finish;
    }
    inline void Animator::setLooped(bool l)
    {
        m_looped = l;
    }
    inline bool Animator::isLooped() const
    {
        return m_looped;
    }
}

#endif // DEF_ANIMATOR_HPP
