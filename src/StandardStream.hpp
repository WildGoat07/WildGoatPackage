#ifndef DEF_WP_STANDARD_STREAM_HPP
#define DEF_WP_STANDARD_STREAM_HPP
#include <SFML/System.hpp>

namespace wp
{
    /////////////////////////////////////////////////
        /// \brief Basic conversion of stream formats.
    ///
    ///Conversion from the standard stream to an SFML stream.
    ///
    ///\class StandardInputStream
    /////////////////////////////////////////////////
    class StandardInputStream : public sf::InputStream
    {
    protected:
        std::istream* m_stream;
        size_t m_streamSize;
        size_t m_offset;
    public:
        StandardInputStream();
        /////////////////////////////////////////////////
                /// \brief Constructor.
        ///
        /// \param std::istream& : standard stream to link.
        /// \param size_t : size of the stream.
        /// \param size_t : offset size of the stream, used for another beginning.
        /// \return void
        ///
        /////////////////////////////////////////////////
        StandardInputStream(std::istream&, size_t, size_t = 0);
        /////////////////////////////////////////////////
                /// \brief Sets the stream to link.
        ///
        /// \param std::istream& : standard stream to link.
        /// \param size_t : size of the stream.
        /// \param size_t : offset size of the stream, used for another beginning.
        /// \return void
        ///
        /////////////////////////////////////////////////
        void setStream(std::istream&, size_t, size_t = 0);
        /////////////////////////////////////////////////
                /// \brief Returns its stored stream.
        ///
        /// \return std::istream& : standard stored stream.
        ///
        /////////////////////////////////////////////////
        std::istream& getStream();
        virtual sf::Int64 read(void*, sf::Int64) override;
        virtual sf::Int64 seek(sf::Int64) override;
        virtual sf::Int64 tell() override;
        virtual sf::Int64 getSize() override;
    };
}


#endif // DEF_WP_STANDARD_STREAM_HPP
