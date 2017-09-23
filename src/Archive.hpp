#ifndef DEF_WP_ARCHIVE_HPP
#define DEF_WP_ARCHIVE_HPP
#include "File.hpp"
#include "StandardStream.hpp"
#include <fstream>
#include <map>

namespace wp
{
    /////////////////////////////////////////////////
        /// \brief Creates an archive.
    ///
    ///Used to create an archive of multiple files.
    ///
    ///\class Archive
    /////////////////////////////////////////////////
    class Archive
    {
        std::map<uint64_t, std::string> m_map;
    public:
        /////////////////////////////////////////////////
                /// \brief Adds a file to the archive.
        ///
        /// \param const& std::string : path to the file.
        /// \param uint64_t : id of the file.
        /// \return void
        ///
        /////////////////////////////////////////////////
        void addFile(std::string const&, uint64_t);
        /////////////////////////////////////////////////
                /// \brief Save the archive.
        ///
        /// \param const& std::string : path to the archive.
        /// \return bool : true if succeed.
        ///
        /////////////////////////////////////////////////
        bool saveAs(std::string const&);
    };
    /////////////////////////////////////////////////
        /// \brief Extracts an archive.
    ///
    ///Used to extract an archive of multiple files, created by Archive.
    ///
    ///\class Extractor
    /////////////////////////////////////////////////
    class Extractor
    {
        std::map<uint64_t, uint64_t> m_map;
        std::ifstream m_file;
    public:
        /////////////////////////////////////////////////
                /// \brief Opens an archive.
        ///
        ///Opens an archive and extract its header.
        ///
        /// \param const& std::string : path to the archive.
        /// \return bool : true if succeed.
        ///
        /////////////////////////////////////////////////
        bool open(std::string const&);
        /////////////////////////////////////////////////
                /// \brief Returns a stream to the file.
        ///
        ///The stream to the archive correspond to the desired id. Be careful ! Every time you call this function, the older given stream will change because it is the internal stream. Also, the given stream must **NOT** change !
        ///
        /// \param uint64_t : id of the file.
        /// \param uint64_t* : were the size of the file will be stored. (Optional)
        /// \return std::istream& : stream.
        ///
        /////////////////////////////////////////////////
        std::istream& getFile(uint64_t, uint64_t* = nullptr);
        /////////////////////////////////////////////////
                /// \brief Returns a stream to the file as a sf::InputStream.
        ///
        ///The stream to the archive correspond to the desired id. Be careful ! Every time you call this function, the older given stream will change because it is the internal stream. Also, the given stream must **NOT** change !
        ///
        /// \param uint64_t : id of the file.
        /// \return wp::StandardInputStream : stream.
        ///
        /////////////////////////////////////////////////
        StandardInputStream getFileAsSfStream(uint64_t);
    };
}

#endif // DEF_WP_ARCHIVE_HPP
