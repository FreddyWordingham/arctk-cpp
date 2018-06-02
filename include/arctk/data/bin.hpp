/**
 *  @file   arctk/data/bin.hpp
 *  @date   02/06/2018
 *  @author Freddy Wordingham
 *
 *  Data binning base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_HPP
#define ARCTK_DATA_BIN_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         */
        template <typename T>
        class Bin
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::vector<double> _counts; //!< Hit count of each bin.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --

            //  == METHODS ==
          public:
            //  -- Getters --
            virtual inline double             min() const noexcept   = 0;
            virtual inline double             max() const noexcept   = 0;
            virtual inline double             width() const noexcept = 0;
            inline const std::vector<double>& counts() const noexcept;

            //  -- Collection --
        };



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the bin counts vector.
         *
         *  @return Bin counts vector.
         */
        inline const std::vector<double>& Bin::counts() const noexcept
        {
            return (_counts);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_HPP
