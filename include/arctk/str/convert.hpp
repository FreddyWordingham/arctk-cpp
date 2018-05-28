/**
 *  @file   arctk/str/convert.hpp
 *  @date   28/05/2018
 *  @author Freddy Wordingham
 *
 *  Conversion to string functions.
 */



//  == GUARD ==
#ifndef ARCTK_STR_CONVERT_HPP
#define ARCTK_STR_CONVERT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <array>
#include <sstream>
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline std::string to_string(const C& cont_, const std::string& pre_ = "{", const std::string& delim_ = ", ", const std::string& post_ = "}");



        //  == FUNCTIONS ==
        template <typename C, typename T, typename I>
        inline std::string to_string(const C& cont_, const std::string& pre_, const std::string& delim_, const std::string& post_)
        {
            std::stringstream stream;

            stream << pre_;
            if (!cont_.empty())
            {
                stream << *std::begin(cont_);
                for (I it = std::next(std::begin(cont_)); it != std::end(cont_); std::advance(it, 1))
                {
                    stream << delim_ << *it;
                }
            }
            stream << post_;

            return (stream.str());
        }



    } // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_CONVERT_HPP
