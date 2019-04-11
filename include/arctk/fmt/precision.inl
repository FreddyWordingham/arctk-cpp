//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/fmt/precision.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iomanip>
#include <ostream>



//  == NAMESPACE ==
namespace arc::fmt
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



} // namespace arc::fmt



//  == OPERATORS ==
//  -- Printing --
inline std::ostream& operator<<(std::ostream& stream_, const arc::fmt::Precision& prec_) noexcept
{
    stream_ << std::setprecision(prec_.precision());

    return (stream_);
}
