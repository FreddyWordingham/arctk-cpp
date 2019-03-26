//  == GUARD ==
#pragma once


//  == NAMESPACE ==
namespace arc
{
    namespace fmt
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



    } // namespace fmt



    //  == OPERATORS ==
    //  -- Printing --
    template <typename T>
    constexpr inline T& operator<<(T& stream_, const fmt::Pad& val_) noexcept;



} // namespace arc
