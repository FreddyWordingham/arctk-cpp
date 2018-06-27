/**
 *  @file   arctk/math/mat3.hpp
 *  @date   27/06/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical three by three matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT3_HPP
#define ARCTK_MATH_MAT3_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/math/mat.hpp>



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Thee by three mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         */
        template <typename T>
        class Mat<T, 3>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            Vec<T, 3> x{};
            Vec<T, 3> y{};
            Vec<T, 3> z{};


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
#endif // ARCTK_MATH_MAT3_HPP
