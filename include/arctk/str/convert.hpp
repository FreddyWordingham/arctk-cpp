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
#include <iomanip>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>

#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline std::string to_string(const C& cont_, const size_t width_ = 0, const std::string& pre_ = "{", const std::string& delim_ = ", ", const std::string& post_ = "}");
        template <typename A0, typename A1>
        inline std::string to_string(const std::pair<A0, A1>& pair_, const size_t width_ = 0, const std::string& pre_ = "(", const std::string& delim_ = ", ", const std::string& post_ = ")");
        template <typename... A>
        inline std::string to_string(const std::tuple<A...>& tup_, const size_t width_ = 0, const std::string& pre_ = "(", const std::string& delim_ = ", ", const std::string& post_ = ")");



        //  == FUNCTIONS ==
        /**
         *  Form a container into a human-readable string.
         *
         *  @tparam C   Type of container to print.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *
         *  @param  cont_   Container to print.
         *  @param  width_  Print width allocated to each element.
         *  @param  pre_    String prepended before the element data.
         *  @param  delim_  Delimiter added between elements.
         *  @param  post_   String appended after the element data.
         *
         *  @return A human-readable string of the container.
         */
        template <typename C, typename T, typename I>
        inline std::string to_string(const C& cont_, const size_t width_, const std::string& pre_, const std::string& delim_, const std::string& post_)
        {
            std::stringstream stream;

            stream << pre_;
            if (!cont_.empty())
            {
                stream << std::setw(width_) << *std::begin(cont_);
                for (I it = std::next(std::begin(cont_)); it != std::end(cont_); std::advance(it, 1))
                {
                    stream << delim_ << std::setw(width_) << *it;
                }
            }
            stream << post_;

            return (stream.str());
        }

        /**
         *  Form a pair into a human-readable string.
         *
         *  @tparam A0  First type stored by pair.
         *  @tparam A1  Second type stored by pair.
         *
         *  @param  pair_   Pair to print.
         *  @param  width_  Print width allocated to each element.
         *  @param  pre_    String prepended before the element data.
         *  @param  delim_  Delimiter added between elements.
         *  @param  post_   String appended after the element data.
         *
         *  @return A human-readable string of the pair.
         */
        template <typename A0, typename A1>
        inline std::string to_string(const std::pair<A0, A1>& pair_, const size_t width_, const std::string& pre_, const std::string& delim_, const std::string& post_)
        {
            std::stringstream stream;

            stream << pre_ << std::setw(width_) << std::get<0>(pair_) << delim_ << std::setw(width_) << std::get<1>(pair_) << post_;

            return (stream.str());
        }

        template <typename... A>
        inline std::string to_string(const std::tuple<A...>& tup_, const size_t width_, const std::string& pre_, const std::string& delim_, const std::string& post_)
        {
            std::stringstream stream;

            stream << pre_;
            arc::utl::apply_with_index(tup_, [&stream, &delim_, width_]<typename L>(const L& val_, const size_t i, const size_t total) { stream << ((i == 0) ? "" : delim_) << std::setw(width_) << val_; });
            stream << post_;

            return (stream.str());
        }



    } // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_CONVERT_HPP
