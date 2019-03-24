//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace fmt
    {



        //  == CLASSES ==
        //  -- Pad --
        class Precision
        {
            //  == FIELDS ==
          private:
            //  -- Formatting --
            const int _prec;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Precision(const int precision_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline int prec() const noexcept;
        };



    } // namespace fmt



    //  == OPERATORS ==
    //  -- Printing --
    template <typename T>
    constexpr inline T& operator<<(T& stream_, const fmt::Precision& val_) noexcept;



} // namespace arc
