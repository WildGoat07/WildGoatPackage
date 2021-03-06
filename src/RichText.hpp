#ifndef DEF_RICH_TEXT_HPP
#define DEF_RICH_TEXT_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

namespace wp
{
    /** \brief Creates rich text.
    *
    *   \class RichText
    *
    *   Creates rich text with dynamic properties.
     */
    class RichText : public sf::Drawable, public sf::Transformable
    {
    public:
        /** \brief Part of the main RichText.
        *
        *   \struct Part
        *
        *   Part with its own properties.
         */
        struct Part
        {
            friend RichText;
        private:
            bool m_return;
            int m_index;
        public:
            std::string text;/**< the text of the part */
            sf::Color fillColor;/**< the fill color of the text */
            sf::Color outlineColor;/**< the outline color of the text */
            float outlineThickness;/**< the outline thickness of the text */
            sf::Uint32 style;/**< the optional style */
            /** \brief Constructor.
            *
            *   \param std::string const& : text
            *   \param sf::Color : fill color
            *   \param sf::Uint32 : style
            *   \param sf::Color : outline color
            *   \param float : outline thickness
             *
             */
            Part(std::string const& = std::string(), sf::Color = sf::Color::Black, sf::Uint32 = 0, sf::Color = sf::Color::Black, float = 0);
        };
    private:
        std::vector<std::shared_ptr<sf::Text> > m_buffer;
        std::vector<int > m_indexs;
        sf::Font const* m_font;
        std::vector<Part> m_parts;
        sf::Uint32 m_size;
        float m_textWrapping = 0;
        int m_index = 0;

        virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
        bool nextValidChar(sf::Uint16&, std::string const&, sf::Uint16&, sf::Uint16&) const;
        void nextWord(std::string const&, int&) const;
    public:
        /** \brief Constructor.
         *
         *
         */
        RichText();
        /** \brief Adds a part to the text.
         *
         * \param const& Part : part to add.
         * \return void
         *
         */
        void addPart(Part const&);
        /** \brief clears the text.
        *
        *   Doesn't reset the font.
         *
         * \return void
         *
         */
        void clear();
        /** \brief Sets the font of the text.
         *
         * \param const& sf::Font : the font.
         * \return void
         *
         */
        void setFont(sf::Font const&);
        /** \brief Returns the used font.
         *
         * \return sf::Font const& : the used font.
         *
         */
        sf::Font const& getFont() const;
        /** \brief Sets the height of the text.
         *
         * \param sf::Uint32 : height of the text.
         * \return void
         *
         */
        void setSize(sf::Uint32);
        /** \brief Returns the height of the text.
         *
         * \return sf::Uint32 : height of the text.
         *
         */
        sf::Uint32 getSize() const;
        /** \brief Generates the text to display it.
         *
         * \return void
         *
         */
        void generate();
        /** \brief Returns the local bounding box.
         *
         * \return sf::FloatRect : bounding box.
         *
         */
        sf::FloatRect getLocalBounds() const;
        /** \brief Returns the global bounding box.
         *
         * \return sf::FloatRect : bounding box.
         *
         */
        sf::FloatRect getGlobalBounds() const;
        /** \brief Load from a %JSON string.
        *
        *   \param std::string const& : %JSON.
        *   \return bool : false if failed.
         *
         */
        bool loadJSON(std::string const&);
        /////////////////////////////////////////////////
                /// \brief Sets the maximal width.
        ///
        ///Over this width, the text will be cut, except for the words that are longer than the maximal width. Set at 0 to cancel it.
        ///
        /// \param float : maximal width.
        /// \return void
        ///
        /////////////////////////////////////////////////
        void setTextWrappingSize(float);
        /////////////////////////////////////////////////
                /// \brief Returns the maximal width.
        ///
        /// \return float : maximal width.
        ///
        /////////////////////////////////////////////////
        float getTextWrappingSize() const;
        /////////////////////////////////////////////////
                /// \brief Returns the index of the part on which the point given is on.
        ///
        ///The index of the part starts to 0. Every new part added increments the index. Returns -1 if the point isn't on any text. Useful to test if the point is on the text (not only its bounding box with getGlobalBounds() ).
        ///
        /// \param sf::Vector2f : point.
        /// \return int : index of the part.
        ///
        /////////////////////////////////////////////////
        int getPointedPart(sf::Vector2f) const;
    };

    inline void RichText::clear()
    {
        m_parts.clear();
        m_buffer.clear();
        m_index = 0;
    }
    inline void RichText::setFont(sf::Font const& f)
    {
        m_font = &f;
    }
    inline sf::Font const& RichText::getFont() const
    {
        return *m_font;
    }
    inline void RichText::setSize(sf::Uint32 s)
    {
        m_size = s;
    }
    inline sf::Uint32 RichText::getSize() const
    {
        return m_size;
    }
    inline sf::FloatRect RichText::getGlobalBounds() const
    {
        return getTransform().transformRect(getLocalBounds());
    }
}

#endif // DEF_RICH_TEXT_HPP
