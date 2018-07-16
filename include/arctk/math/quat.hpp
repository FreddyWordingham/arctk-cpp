/**
 *  @file   arctk/math/quat.hpp
 *  @date   16/06/2018
 *  @author Freddy Wordingham
 *
 *  Quaternion mathematical class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_QUAT_HPP
#define ARCTK_MATH_QUAT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Quaternion mathematical class.
         */
        class Quat : public str::Printable
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            double x; //!< Representation of rotation axis x-component.
            double y; //!< Representation of rotation axis y-component.
            double z; //!< Representation of rotation axis z-component.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == OPERATORS ==



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_QUAT_HPP
