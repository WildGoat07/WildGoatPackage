#ifndef DEF_VERTEX_ALLOCATOR_HPP
#define DEF_VERTEX_ALLOCATOR_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace wp
{
    /** \brief Allocates memory for VertexArray.
    *   \class VertexAllocator
     */

    class VertexAllocator : public sf::Drawable
    {
    public:
        /** \struct VertexSquare
        *   \brief Sprite from a VertexAllocator.
        */
        struct VertexSquare : public sf::Transformable
        {
            friend VertexAllocator;
        protected:
        VertexSquare(VertexAllocator*);
        public:
            const VertexAllocator* parent;/**< The parent's VertexAllocator. */
            sf::Vertex* array[4];/**< The vertices of the sprite. */
            /** \brief Synchronizes the transformations.
            *
            *   Updates the vertex to match the transformations applied.
             *
             * \return void
             *
             */
            void update();

            /** \brief Creates a square sprite.
            *
            *   Creates automatically a square sprite from the parameters.
             *
             * \param sf::FloatRect : The square at the provided sizes.
             * \param sf::FloatRect : The texture square (Optionnal).
             *
             *
             */
            void setSquare(sf::FloatRect, sf::FloatRect = sf::FloatRect());
        };
    private:
        sf::VertexArray m_array;
        sf::Texture* m_texture;
        unsigned int m_size;

        virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
    public:
        /** \brief Constructor.
         */
        VertexAllocator();
        /** \brief Constructor.
         *
         * \param unsigned int : size of the allocation in number of sprites.
         *
         */
        VertexAllocator(unsigned int);
        /** \brief Links a texture to the VertexAllocator.
         *
         * \param sf::Texture& : reference to the texture.
         *
         */
        void setTexture(sf::Texture&);
        /** \brief Returns the wanted sprite.
        *
        *   Returns the wanted sprite by giving his index.
         *
         * \param unsigned int : index of the sprite.
         *
         */
        VertexSquare operator[](unsigned int);
        /** \brief Changes the size of the allocation.
         *
         * \param unsigned int : new size.
         *
         */
        void setSize(unsigned int);
        /** \brief Clears the allocation.
         *
         *
         */
        void clear();
        /** \brief Returns the size of the allocation.
        *
        *   The size is in number of sprites.
        *
         * \return The size of the allocation.
         *
         */
        unsigned int size() const;
        /** \brief Allocates a new sprite.
        *
        *   Allocates a new square sprite.
        *
             * \param sf::FloatRect : The square at the provided sizes.
             * \param sf::FloatRect : The texture square (Optionnal).
         * \return VertexSquare : The created sprite.
         *
         */
        VertexSquare allocateNewVertex(sf::FloatRect = sf::FloatRect(), sf::FloatRect = sf::FloatRect());
    };
    inline void VertexAllocator::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.texture = m_texture;

        target.draw(m_array, states);
    }
    inline void VertexAllocator::setTexture(sf::Texture& t)
    {
        m_texture = &t;
    }
    inline void VertexAllocator::setSize(unsigned int s)
    {
        clear();
        m_array.resize(s*4);
        m_size = s;
    }
    inline void VertexAllocator::clear()
    {
        m_array.clear();
        m_size = 0;
    }
    inline unsigned int VertexAllocator::size() const
    {
        return m_size;
    }
}


#endif // DEF_VERTEX_ALLOCATOR_HPP
