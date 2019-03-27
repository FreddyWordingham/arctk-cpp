//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace fmt
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



    } // namespace fmt



    //  == OPERATORS ==
    //  -- Printing --
    template <typename T>
    constexpr inline T& operator<<(T& stream_, const fmt::Precision& val_) noexcept;



} // namespace arc
