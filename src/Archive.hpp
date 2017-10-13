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
    class Extractor : public sf::InputStream, public sf::NonCopyable
    {
        std::map<uint64_t, uint64_t> m_map;
        std::ifstream m_file;
        sf::Uint64 m_offset;
        uint64_t m_selection;
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
                /// \brief Selects the file.
        ///
        ///The selected file will be the one read. Returns false if the id isn't found. In this case, the selected file won't change.
        ///
        /// \param uint64_t : id of the file.
        /// \return bool : true if succeed.
        ///
        /////////////////////////////////////////////////
        bool select(uint64_t);
        /////////////////////////////////////////////////
                /// \brief Returns the id of the selected file.
        ///
        /// \return uint64_t : id of the file.
        ///
        /////////////////////////////////////////////////
        uint64_t getSelectedFile() const;
        /////////////////////////////////////////////////
                /// \brief Returns the id of all the stored files.
        ///
        /// \return std::vector<uint64_t> : table of all the ids.
        ///
        /////////////////////////////////////////////////
        std::vector<uint64_t> getIds() const;
        virtual sf::Int64 read(void*, sf::Int64) override;
        virtual sf::Int64 seek(sf::Int64) override;
        virtual sf::Int64 tell() override;
        virtual sf::Int64 getSize() override;
    };
}

#endif // DEF_WP_ARCHIVE_HPP
