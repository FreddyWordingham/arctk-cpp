/**
 *  @file   arctk/data/domain.hpp
 *  @date   12/09/2018
 *  @author Freddy Wordingham
 *
 *  Data packet domain class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_DOMAIN_HPP
#define ARCTK_DATA_DOMAIN_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/geom.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data packet domain class.
         */
        class Domain : public geom::shape::Aabb
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
        };



        //  == INSTANTIATION ==



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_DOMAIN_HPP
