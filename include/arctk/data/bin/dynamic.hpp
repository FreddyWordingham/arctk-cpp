/**
 *  @file   arctk/data/bin/dynamic.hpp
 *  @date   06/06/2018
 *  @author Freddy Wordingham
 *
 *  Dynamic range data binning base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_DYNAMIC_HPP
#define ARCTK_DATA_BIN_DYNAMIC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/data/bin.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace bin //! binning namespace
        {



            //  == CLASS ==
            /**
             *  Dynamic range histogram class which bins values into a data vector.
             *  Expands to capture all collection values.
             *
             *  @tparam T   Type of value to be counted.
             */
            template <typename T>
            class Dynamic : public Bin<T>
            {
                //  == FIELDS ==
              private:
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Getters --



        } // namespace bin
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_DYNAMIC_HPP
