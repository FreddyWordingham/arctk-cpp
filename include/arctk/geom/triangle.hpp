/**
 *  @file   arctk/geom/triangle.hpp
 *  @date   29/08/2018
 *  @author Freddy Wordingham
 *
 *  Geometric triangle class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_TRIANGLE_HPP
#define ARCTK_GEOM_TRIANGLE_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <optional>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Geometric triangle.
         */
        class Triangle
        {
            //  == FIELDS ==
          private:
            //  -- Positioning --
            const std::array<vec3, 3> _poss;  //!< Vertex positions.
            const std::array<vec3, 3> _norms; //!< Vertex normals.

            //  -- Properties --
            const vec3 _norm; //!< Normal of the triangle's plane.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept;

          private:
            //  -- Initialisation --
            inline vec3 init_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double area() const noexcept;
            inline double vol() const noexcept;

            //  -- Collision --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a triangle from three vertex positions and three corresponding vertex normals.
         *
         *  @param  poss_   Positions of the vertices.
         *  @param  norms_  Normals of the vertices.
         *
         *  @pre    norms_ vecs must be normalised.
         *  @post   _norm must be normalised.
         *  @post   _norm dot product with each norms_ vec must be non-negative.
         */
        inline Triangle::Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept
          : _poss(poss_)
          , _norms(norms_)
          , _norm(init_norm(poss_, norms_))
        {
            PRE(norms_[index::vertex::ALPHA].normalised());
            PRE(norms_[index::vertex::BETA].normalised());
            PRE(norms_[index::vertex::GAMMA].normalised());

            POST(_norm.normalised());
            POST((_norm * norms_[index::vertex::ALPHA]) >= 0.0);
            POST((_norm * norms_[index::vertex::BETA]) >= 0.0);
            POST((_norm * norms_[index::vertex::GAMMA]) >= 0.0);
        }


        //  -- Initialisation --
        inline vec3 Triangle::init_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) const noexcept
        {
            vec3 norm = ((poss_[index::vertex::BETA] - poss_[index::vertex::ALPHA]) ^ (poss_[index::vertex::GAMMA] - poss_[index::vertex::ALPHA])).normal();

            if ((norm * norms_[index::vertex::ALPHA]) < 0.0)
            {
                norm = -norm;
            }

            POST(_norm.normalised());
            POST((norm * norms_[index::vertex::ALPHA]) >= 0.0);
            POST((norm * norms_[index::vertex::BETA]) >= 0.0);
            POST((norm * norms_[index::vertex::GAMMA]) >= 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        inline double Triangle::area() const noexcept
        {
            return (math::geom::area(_poss));
        }

        inline double Triangle::vol() const noexcept
        {
            return (0.0);
        }



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_TRIANGLE_HPP
