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
         *  @tparam N   Dimensionality of the histogram.
         *  @tparam A   Types stored in data columns.
         */
        template <size_t N, typename... A>
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
