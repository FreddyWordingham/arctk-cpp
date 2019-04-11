//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <iosfwd>



//  == NAMESPACE ==
namespace arc::fmt
{



    //  == CLASSES ==
    //  -- Precision --
    class Precision
    {
        //  == FIELDS ==
      private:
        //  -- Formatting --
        const int _precision;


        //  == INSTANTIATION ==
      public:
        //  -- Constructors --
        constexpr inline explicit Precision(int precision_) noexcept;


        //  == METHODS ==
      public:
        //  -- Getters --
        constexpr inline int precision() const noexcept;
    };



} // namespace arc::fmt



//  == OPERATORS ==
//  -- Printing --
inline std::ostream& operator<<(std::ostream& stream_, const arc::fmt::Precision& val_) noexcept;
