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
        constexpr inline Precision::Precision(const int precision_) noexcept
          : _precision{precision_}
        {
            assert(precision_ > 5);
        }



        //  == METHODS ==
        //  -- Getters --
        constexpr inline int Precision::precision() const noexcept
        {
            return (_precision);
        }



    } // namespace fmt



    //  == OPERATORS ==
    //  -- Printing --
    template <typename T>
    constexpr inline T& operator<<(T& stream_, const fmt::Precision& val_) noexcept
    {
        stream_ << std::setprecision(val_.precision());

        return (stream_);
    }



} // namespace arc
