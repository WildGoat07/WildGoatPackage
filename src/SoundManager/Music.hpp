#ifndef DEF_WP_SND_MUSIC_HPP
#define DEF_WP_SND_MUSIC_HPP
#include "Module.hpp"

namespace wp
{
    namespace snd
    {
        /////////////////////////////////////////////////
                /// \brief A music module.
        ///A module containing a sf::Music.
        ///\class Music
        /////////////////////////////////////////////////
        class Music : public Module
        {
            sf::Music m_music;
            Music() {}
        public:
            virtual void update() override;
            /////////////////////////////////////////////////
                        /// \brief Creates a new instance.
            ///
            /// \return shared_ptr<Music> : new music.
            ///
            /////////////////////////////////////////////////
            static shared_ptr<Music> create();
            /////////////////////////////////////////////////
                        /// \brief Returns its stored sf::Music.
            ///
            /// \return sf::Music& : internal music.
            ///
            /////////////////////////////////////////////////
            sf::Music& get();
        };
    }
}

#endif //DEF_WP_SND_MUSIC_HPP
