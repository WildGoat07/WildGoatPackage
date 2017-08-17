#ifndef DEF_WP_SPOT_HPP
#define DEF_WP_SPOT_HPP
#include "../Various.hpp"
#include "Wall.hpp"
#include "Light.hpp"

namespace wp
{
    namespace light
    {
        /////////////////////////////////////////////////
                /// \brief A spot light.
        ///
        ///A spot light is a basic light but light only in one direction.
        ///
        ///\class SpotLight
        /////////////////////////////////////////////////
        class SpotLight : public PointLight
        {
        protected:
            friend LightManager;
            float m_dirAngle;
            float m_openAngle;
            SpotLight();

        public:
            virtual void generate() override;
            /////////////////////////////////////////////////
                        /// \brief Sets its direction.
            ///
            /// \param float : angle of the direction.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setDirection(float);
            /////////////////////////////////////////////////
                        /// \brief Sets its angle.
            ///
            /// \param float : angle of the field of light.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setAngle(float);
            /////////////////////////////////////////////////
                        /// \brief Returns its direction.
            ///
            /// \return float : direction.
            ///
            /////////////////////////////////////////////////
            float getDirection() const;
            /////////////////////////////////////////////////
                        /// \brief Returns its angle.
            ///
            /// \return float : angle.
            ///
            /////////////////////////////////////////////////
            float getAngle() const;
        };
    }
}

#endif // DEF_WP_SPOT_HPP

