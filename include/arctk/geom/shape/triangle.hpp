/**
 *  @file   arctk/geom/shape/triangle.hpp
 *  @date   06/10/2018
 *  @author Freddy Wordingham
 *
 *  Geometric triangle shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_TRIANGLE_HPP
#define ARCTK_GEOM_SHAPE_TRIANGLE_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <optional>

//  -- Arctk --
#include <arctk/geom/shape.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {
        namespace shape //! shape namespace
        {



            //  == CLASS ==
            /**
             *  Geometric triangle shape.
             */
            class Triangle : public Shape
            {
                //  == FIELDS ==
              private:
                //  -- Vertices --
                const std::array<vec3, 3> _poss;  //!< Vertex positions.
                const std::array<vec3, 3> _norms; //!< Vertex normals.

                //  -- Normals --
                const vec3 _plane_norm; //!< Triangle plane normal.



                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept;


                //  == METHODS ==
              public:
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
             *
             *  @post   _norm must be normalised.
             */
            inline Triangle::Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept
              : _poss(poss_)
              , _norms(norms_)
              , _plane_norm(((poss_[index::vertex::BETA] - poss_[index::vertex::ALPHA]) ^ (poss_[index::vertex::GAMMA] - poss_[index::vertex::ALPHA])).normal())
            {
                PRE(norms_[index::vertex::ALPHA].normalised());
                PRE(norms_[index::vertex::BETA].normalised());
                PRE(norms_[index::vertex::GAMMA].normalised());

                POST(_plane_norm.normalised());
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_TRIANGLE_HPP
