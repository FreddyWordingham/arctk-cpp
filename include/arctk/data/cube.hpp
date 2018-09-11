/**
 *  @file   arctk/data/cube.hpp
 *  @date   11/09/2018
 *  @author Freddy Wordingham
 *
 *  Data cube class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_CUBE_HPP
#define ARCTK_DATA_CUBE_HPP



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data cube class.
         *
         *  @tparam A   Types stored in data columns.
         *  @tparam N   Dimensionality of the histogram.
         */
        template <typename... A, size_t N>
        class Cube
        {
            //  == FIELDS ==
          private:
            //  -- Data --


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE_HPP
