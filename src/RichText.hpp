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
        public:
            std::string text;/**< the text of the part */
            sf::Color fillColor;/**< the fill color of the text */
            sf::Color outlineColor;/**< the outline color of the text */
            float outlineThickness;/**< the outline thickness of the text */
            sf::Uint32 style;/**< the optional style */
            /** \brief Constructor.
            *
            *   \param std::string const& : text
            *   \param sf::Color : color
            *   \param sf::Uint32 : style
             *
             */
            Part(std::string const& = std::string(), sf::Color = sf::Color::Black, sf::Uint32 = 0, sf::Color = sf::Color::Black, float = 0);
            /** \brief Updates the graphic text.
             *
             * \return void
             *
             */
        };
    private:
        std::vector<std::shared_ptr<sf::Text> > m_buffer;
        sf::Font const* m_font;
        std::vector<Part> m_parts;
        sf::Uint32 m_size;
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
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
    };
}

#endif // DEF_RICH_TEXT_HPP
