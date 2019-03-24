//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/fmt/precision.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iomanip>



//  == NAMESPACE ==
namespace arc
{
    namespace fmt
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        constexpr inline Precision::Precision(const int prec_) noexcept
          : _prec{prec_}
        {
            assert(prec_ > 0);
        }



        //  == METHODS ==
        //  -- Getters --
        constexpr inline int Precision::prec() const noexcept
        {
            return (_prec);
        }



    } // namespace fmt



    //  == OPERATORS ==
    //  -- Printing --
    template <typename T>
    constexpr inline T& operator<<(T& stream_, const fmt::Precision& val_) noexcept
    {
        stream_ << std::setprecision(val_.prec());

        return (stream_);
    }



} // namespace arc
