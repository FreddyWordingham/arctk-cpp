/**
 *  @file   arctk/utl/stream.hpp
 *  @date   09/08/2018
 *  @author Freddy Wordingham
 *
 *  Collection of stream utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_STREAM_HPP
#define ARCTK_UTL_STREAM_HPP



//  == IMPORTS ==
//  -- Std --
#include <sstream>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {
        namespace stream //! stream namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Manipulation --
            template <typename T>
            inline void rewind(T& stream_);



            //  == FUNCTIONS ==
            //  -- Manipulation --
            /**
             *  Rewind a given stream.
             *  Clear the state of the stream.
             *  Place the get an put pointers to the start of the stream.
             *
             *  @tparam T   Type of stream to be rewound.
             *
             *  @param  stream_ Stream to be rewound.
             */
            template <typename T>
            inline void rewind(T& stream_)
            {
                stream_.clear();
                stream_.seekg(std::ios::beg);
                stream_.seekp(std::ios::beg);
            }



        } // namespace stream
    }     // namespace utl
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_UTL_STREAM_HPP
