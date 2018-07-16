/**
 *  @file   arctk/math/quat.hpp
 *  @date   16/06/2018
 *  @author Freddy Wordingham
 *
 *  Quaternion mathematical class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_QUAT_HPP
#define ARCTK_MATH_QUAT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/settings.hpp>
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Quaternion mathematical class.
         */
        class Quat : public str::Printable
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            double x; //!< Representation of rotation axis x-component.
            double y; //!< Representation of rotation axis y-component.
            double z; //!< Representation of rotation axis z-component.
            double w; //!< Representation of rotation angle.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Quat() noexcept;


            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
            //  -- Printing --
            inline std::string str() const noexcept override;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a unit quaternion.
         */
        constexpr inline Quat::Quat() noexcept
          : x(0.0)
          , y(0.0)
          , z(0.0)
          , w(1.0)
        {
        }



        //  == OPERATORS ==


        //  == METHODS ==
        //  -- Printing --
        /**
         *  Create a human readable string of the quat.
         *
         *  @return Human readable string of the quat.
         */
        inline std::string Quat::str() const noexcept
        {
            std::stringstream stream;

            stream << settings::format::VEC_START;

            stream << std::setw(settings::format::PRINT_WIDTH) << x;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << y;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << z;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << w;

            stream << settings::format::VEC_END;

            return (stream.str());
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_QUAT_HPP
