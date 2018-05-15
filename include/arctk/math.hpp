//  == GUARD ==
#ifndef ARCTK_MATH_HPP
#define ARCTK_MATH_HPP



//  == MODULE ==
#ifdef ARCTK_CORE_MOD



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Power --
        template <class T>
        inline T sq(T x_) noexcept;



        //  == FUNCTIONS ==
        //  -- Power --
        template <class T>
        inline T sq(const T x_) noexcept
        {
            return (x_ * x_);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_CORE_MOD



//  == GUARD END ==
#endif // ARCTK_MATH_HPP
