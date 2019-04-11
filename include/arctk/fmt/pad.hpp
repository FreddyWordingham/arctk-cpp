//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <iosfwd>



//  == NAMESPACE ==
namespace arc::fmt
{



    //  == CLASSES ==
    //  -- Pad --
    class Pad
    {
        //  == FIELDS ==
      private:
        //  -- Formatting --
        const int  _width;
        const char _fill;


        //  == INSTANTIATION ==
      public:
        //  -- Constructors --
        constexpr inline explicit Pad(int width_, char fill_ = ' ') noexcept;


        //  == METHODS ==
      public:
        //  -- Getters --
        constexpr inline int  width() const noexcept;
        constexpr inline char fill() const noexcept;
    };



} // namespace arc::fmt



//  == OPERATORS ==
//  -- Printing --
inline std::ostream& operator<<(std::ostream& stream_, const arc::fmt::Pad& pad_) noexcept;
