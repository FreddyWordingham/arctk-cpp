/**
 *  @file   arctk/cont/vector.hpp
 *  @date   25/05/2018
 *  @author Freddy Wordingham
 *
 *  Printable base class.
 */



//  == GUARD ==
#ifndef ARCTK_OUT_PRINTABLE_HPP
#define ARCTK_OUT_PRINTABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace out //! output namespace
    {



        //  == CLASS ==
        /**
         */
        class Printable
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          public:
            //  -- Io --
            friend inline std::ostream& operator<<(std::ostream& stream_, const Printable& print_) noexcept;


            //  == METHODS ==
          public:
            //  -- Io --
            virtual inline std::string str() const noexcept = 0;
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == OPERATORS ==
        //  -- Io --
        inline std::ostream& operator<<(std::ostream& stream_, const Printable& print_) noexcept
        {
            stream_ << print_.str();

            return (stream_);
        }



        //  == METHODS ==


    } // namespace out
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_OUT_PRINTABLE_HPP
