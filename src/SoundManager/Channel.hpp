#ifndef DEF_WP_SND_CHANNEL_HPP
#define DEF_WP_SND_CHANNEL_HPP
#include "Module.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include <list>

namespace wp
{
    namespace snd
    {
        /////////////////////////////////////////////////
                /// \brief %Channel. Updates multiple sounds.
        ///
        ///Can link to multiple other modules to change their volume and pitch to all his children.
        /////////////////////////////////////////////////
        class Channel : public Module
        {
            Channel() {}
            std::list<shared_ptr<Module> > m_modules;
            bool _exist(shared_ptr<Module>);
        public:
            virtual void update() override;
            /////////////////////////////////////////////////
                        /// \brief Used to create a new instance of channel.
            ///
            /// \return shared_ptr<Channel> : the new channel.
            ///
            /////////////////////////////////////////////////
            static shared_ptr<Channel> create();
            /////////////////////////////////////////////////
                        /// \brief Removes a child from the channel.
            ///
            ///If the child does not exist in the channel, nothing is done and false is returned.
            /// \param shared_ptr<Module> : the child to add.
            /// \return bool : true if succeed.
            ///
            /////////////////////////////////////////////////
            bool erase(shared_ptr<Module>);
            /////////////////////////////////////////////////
                        /// \brief Adds a child to the channel.
            ///
            ///If the child already exists in the channel, nothing is done.
            /// \param shared_ptr<Module> : child to add.
            /// \return shared_ptr<Module> : the added child.
            ///
            /////////////////////////////////////////////////
            shared_ptr<Module> add(shared_ptr<Module>);
            /////////////////////////////////////////////////
                        /// \brief Creates a new instance of a channel as a child.
            ///
            /// \return shared_ptr<Channel> : the new channel.
            ///
            /////////////////////////////////////////////////
            shared_ptr<Channel> newChannel();
            /////////////////////////////////////////////////
                        /// \brief Creates a new instance of a Music as a child.
            ///
            /// \return shared_ptr<Music> : the new music.
            ///
            /////////////////////////////////////////////////
            shared_ptr<Music> newMusic();
            /////////////////////////////////////////////////
                        /// \brief Creates a new instance of a sound as a child.
            ///
            /// \return shared_ptr<Sound> : the new sound.
            ///
            /////////////////////////////////////////////////
            shared_ptr<Sound> newSound();
        };
    }
}

#endif // DEF_WP_SND_CHANNEL_HPP
