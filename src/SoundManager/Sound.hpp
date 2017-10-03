#ifndef DEF_WP_SND_SOUND_HPP
#define DEF_WP_SND_SOUND_HPP
#include "Module.hpp"

namespace wp
{
    namespace snd
    {
        /////////////////////////////////////////////////
                /// \brief A sound module.
        ///A module containing a sf::Sound.
        ///\class Sound
        /////////////////////////////////////////////////
        class Sound : public Module
        {
            sf::Sound m_sound;
            Sound() {}
        public:
            virtual void update() override;
            /////////////////////////////////////////////////
                        /// \brief Creates a new instance.
            ///
            /// \return shared_ptr<Sound> : new sound.
            ///
            /////////////////////////////////////////////////
            static shared_ptr<Sound> create();
            /////////////////////////////////////////////////
                        /// \brief Returns its stored sf::Sound.
            ///
            /// \return sf::Sound& : internal sound.
            ///
            /////////////////////////////////////////////////
            sf::Sound& get();
        };
    }
}

#endif //DEF_WP_SND_SOUND_HPP


