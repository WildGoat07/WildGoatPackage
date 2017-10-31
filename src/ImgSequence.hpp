#ifndef DEF_WP_IMG_SEQUENCE_HPP
#define DEF_WP_IMG_SEQUENCE_HPP
#include <SFML/Graphics.hpp>
#include "File.hpp"
#include "AdvancedClock.hpp"
#include "Various.hpp"

namespace wp
{
    /////////////////////////////////////////////////
        /// \brief Class used to load a sequence of image as a short video.
    ///
    ///The sequence should be like : "xxxxx0000.png", ending with its number.
    ///\class ImgSequence
    /////////////////////////////////////////////////
    class ImgSequence
    {
        sf::Texture m_buffer;
        uint16_t m_fps;
        AdvancedClock m_clock;
        std::vector<shared_ptr<sf::Image> > m_imgs;
        std::vector<shared_ptr<sf::FileInputStream> > m_files;
        bool m_streamed;
        bool m_looped = false;
        bool m_finished = false;

    public:
        /////////////////////////////////////////////////
                /// \brief Constructor.
        ///
        ///
        /////////////////////////////////////////////////
        ImgSequence();
        /////////////////////////////////////////////////
                /// \brief Opens the sequence.
        ///The opened sequence will be streamed. It means the files shouldn't be deleted while the ImgSequence is reading.
        ///
        /// \param const& File : first file of the sequence.
        /// \param uint16_t : frames per second.
        /// \return bool : true if succeed.
        ///
        /////////////////////////////////////////////////
        bool open(File const&, uint16_t);
        /////////////////////////////////////////////////
                /// \brief Loads the sequence.
        ///The loaded sequence will be saved in the memory. It means it will take A LOT of memory scaling on the total size of the sequence, be careful. Should only be used for very short sequences of large images. Small images sequence or long ones should be opened with open().
        ///
        /// \param const& File : first file of the sequence.
        /// \param uint16_t : frames per second.
        /// \return bool : true if succeed.
        ///
        /////////////////////////////////////////////////
        bool load(File const&, uint16_t);
        /////////////////////////////////////////////////
                /// \brief Plays the sequence in the buffer.
        ///
        /// \return void
        ///
        /////////////////////////////////////////////////
        void play();
        /////////////////////////////////////////////////
                /// \brief Pauses the sequence in the buffer.
        ///
        /// \return void
        ///
        /////////////////////////////////////////////////
        void pause();
        /////////////////////////////////////////////////
                /// \brief Returns the actual time.
        ///
        /// \return sf::Time : actual time.
        ///
        /////////////////////////////////////////////////
        sf::Time getOffset() const;
        /////////////////////////////////////////////////
                /// \brief Sets the actual time.
        ///
        /// \param sf::Time : actual time.
        /// \return void
        ///
        /////////////////////////////////////////////////
        void setOffset(sf::Time);
        /////////////////////////////////////////////////
                /// \brief Sets the speed factor.
        ///
        ///The speed factor modifies the frames per seconds, a factor of 2 with 30 fps will result of a sequence based on 60 fps.
        ///
        /// \param float : speed factor.
        /// \return void
        ///
        /////////////////////////////////////////////////
        void setFactor(float);
        /////////////////////////////////////////////////
                /// \brief Returns the speed factor.
        ///
        /// \return float : speed factor.
        ///
        /////////////////////////////////////////////////
        float getFactor() const;
        /////////////////////////////////////////////////
                /// \brief Returns the buffer.
        ///
        /// \return sf::Texture const& : buffer.
        ///
        /////////////////////////////////////////////////
        sf::Texture const& getTexture() const;
        /////////////////////////////////////////////////
                /// \brief Updates the buffer.
        ///
        ///The buffer will be synchronized with the actual time, based on the frames per second.
        ///
        /// \return void
        ///
        /////////////////////////////////////////////////
        void update();
        /////////////////////////////////////////////////
                /// \brief Set the buffer smooth.
        ///
        /// \param bool : smooth.
        /// \return void
        ///
        /////////////////////////////////////////////////
        void setSmooth(bool);
        /////////////////////////////////////////////////
                /// \brief Returns true if the texture is smooth.
        ///
        /// \return bool : true if smooth.
        ///
        /////////////////////////////////////////////////
        bool isSmooth() const;
        /////////////////////////////////////////////////
                /// \brief Returns true when the sequence is finished.
        ///
        ///Will always return false if getLoop() is true.
        ///
        /// \return bool : finished stat.
        ///
        /////////////////////////////////////////////////
        bool isFinished() const;
        /////////////////////////////////////////////////
                /// \brief Sets the sequence looped.
        ///
        /// \param bool : looped.
        /// \return void
        ///
        /////////////////////////////////////////////////
        void setLoop(bool);
        /////////////////////////////////////////////////
                /// \brief Returns true if the sequence is looped.
        ///
        /// \return bool : looped.
        ///
        /////////////////////////////////////////////////
        bool getLoop() const;
    };
}

#endif // DEF_WP_IMG_SEQUENCE_HPP
