/**
 *  @file   arctk/math/func.hpp
 *  @date   11/08/2018
 *  @author Freddy Wordingham
 *
 *  Math function class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_FUNC_HPP
#define ARCTK_MATH_FUNC_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Mathematical function class.
         *
         *  @tparam T   Type of func domain.
         *  @tparam S   Type returned from the func.
         */
        template <typename T, typename S>
        class Func
        {
            //  == OPERATORS ==
          public:
            //  -- Call --
            virtual S operator()(const T val_) noexcept = 0;
        };



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FUNC_HPP
