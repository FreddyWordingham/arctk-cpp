//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --



//  == NAMESPACE ==
namespace arc
{
    namespace si
    {



        //  == CLASS ==
        template <typename D>
        class Unit
        {
            //  == FIELDS ==
          private:
            //  -- Magnitude --
            double _mag;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --



            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline double mag() const noexcept;
        };



    } // namespace si
} // namespace arc
