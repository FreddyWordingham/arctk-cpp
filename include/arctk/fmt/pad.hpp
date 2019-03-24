//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --



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
            const int _width;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Pad(const int width_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline int width() const noexcept;
        };



    } // namespace fmt



    //  == OPERATORS ==
    //  -- Printing --
    template <typename T>
    constexpr inline T& operator<<(T& stream_, const fmt::Pad& val_) noexcept;



} // namespace arc
