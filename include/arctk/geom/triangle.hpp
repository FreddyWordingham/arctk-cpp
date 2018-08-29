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
#include <optional>

//  -- Arctk --
#include <arctk/debug.hpp>
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


            //  == METHODS ==
          public:
            //  -- Getters --

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
         */
        inline Triangle::Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept
          : _poss(poss_)
          , _norms(norms_)
          , _norm(init_norm(pos_))
        {
            PRE(norm_[index::vertex::ALPHA].normalised());
            PRE(norm_[index::vertex::BETA].normalised());
            PRE(norm_[index::vertex::GAMMA].normalised());

            POST(_plane_norm.normalised());
        }



        //  == METHODS ==



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_TRIANGLE_HPP
