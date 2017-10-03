#ifndef DEF_WP_SND_MODULE_HPP
#define DEF_WP_SND_MODULE_HPP
#include <SFML/Audio.hpp>
#include <memory>
#include "../Various.hpp"

namespace wp
{
    /////////////////////////////////////////////////
        /// \brief The sound manager namespace.
    ///
    ///Contains the classes required the use the sound manager.
    /// \namespace wp::snd
    ///
    /////////////////////////////////////////////////
    namespace snd
    {
        class Channel;
        /////////////////////////////////////////////////
                /// \brief Base class.
        ///
        ///\class Module
        /////////////////////////////////////////////////
        class Module : public std::enable_shared_from_this<Module>
        {
        protected:
            friend Channel;
            float m_pitch = 1;
            float m_volume = 1;
            Channel* m_parent = nullptr;

            Module() {}
        public:
            /////////////////////////////////////////////////
                        /// \brief Sets its volume.
            ///
            ///The volume is between 0-1.
            /// \param float : volume.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setVolume(float);
            /////////////////////////////////////////////////
                        /// \brief Sets its pitch.
            ///
            /// \param float : pitch.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setPitch(float);
            /////////////////////////////////////////////////
                        /// \brief Returns its own shared_ptr.
            ///
            /// \return shared_ptr<Module> : pointer to itself.
            ///
            /////////////////////////////////////////////////
            shared_ptr<Module> getPtr();
            /////////////////////////////////////////////////
                        /// \brief Returns its internal volume.
            ///
            /// \return float : volume.
            ///
            /////////////////////////////////////////////////
            float getVolume() const;
            /////////////////////////////////////////////////
                        /// \brief Returns its internal pitch.
            ///
            /// \return float : pitch.
            ///
            /////////////////////////////////////////////////
            float getPitch() const;
            /////////////////////////////////////////////////
                        /// \brief Returns the nominal output volume.
            ///
            ///The nominal output volume is also relative to all its parents.
            /// \return float : volume.
            ///
            /////////////////////////////////////////////////
            float getComputedVolume() const;
            /////////////////////////////////////////////////
                        /// \brief Returns the nominal output pitch.
            ///
            ///The nominal output pitch is also relative to all its parents.
            /// \return float : pitch.
            ///
            /////////////////////////////////////////////////
            float getComputedPitch() const;
            /////////////////////////////////////////////////
                        /// \brief Updates the volume and pitch of the Module.
            ///
            /// \return void
            ///
            /////////////////////////////////////////////////
            virtual void update() = 0;
            /////////////////////////////////////////////////
                        /// \brief Reset its parent, making it at the master level.
            ///
            /// \return void
            ///
            /////////////////////////////////////////////////
            void resetParent();
            /////////////////////////////////////////////////
                        /// \brief Change its parent.
            ///
            ///No need to remove the module from the old channel.
            /// \param shared_ptr<Channel> : the new parent.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setParent(shared_ptr<Channel>);
        };
    }
}

#endif //DEF_WP_SND_MODULE_HPP
