/**
 *  @file   arctk/scene/domain.hpp
 *  @date   08/10/2018
 *  @author Freddy Wordingham
 *
 *  Domain information class.
 */



//  == GUARD ==
#ifndef ARCTK_SCENE_DOMAIN_HPP
#define ARCTK_SCENE_DOMAIN_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>
#include <arctk/scene/cell.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace scene //! scene namespace
    {



        //  == CLASS ==
        /**
         *  Domain information cell.
         */
        class Domain : public geom::shape::Box
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::array<size_t, 3>                                  _res;
            std::vector<std::vector<std::vector<std::unique_ptr<Cell>>>> _cells; //!< Three-dimensional vector of cells.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --



    } // namespace scene
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SCENE_DOMAIN_HPP
