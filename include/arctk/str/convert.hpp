/**
 *  @file   arctk/str/convert.hpp
 *  @date   27/05/2018
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
#include <sstream>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename I = typename C::const_iterator>
        inline std::string to_string(const C& cont_, const std::string& pre_ = "{", const std::string& delim_ = ", ", const std::string& app_ = "}") noexcept;
        template <typename A0, typename A1>
        inline std::string to_string(const std::pair<A0, A1>& pair_, const std::string& pre_ = "(", const std::string& delim_ = ", ", const std::string& app_ = ")") noexcept;
        template <typename... A>
        inline std::string to_string(const std::tuple<A...>& tup_, const std::string& pre_ = "(", const std::string& delim_ = ", ", const std::string& app_ = ")") noexcept;



        //  == FUNCTIONS ==
        template <typename C, typename I>
        inline std::string to_string(const C& cont_, const std::string& pre_, const std::string& delim_, const std::string& app_) noexcept
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
            stream << app_;

            return (stream.str());
        }

        template <typename A0, typename A1>
        inline std::string to_string(const std::pair<A0, A1>& pair_, const std::string& pre_, const std::string& delim_, const std::string& app_) noexcept
        {
            std::stringstream stream;

            stream << pre_;
            stream << std::get<0>(pair_) << delim_ << std::get<1>(pair_);
            stream << app_;

            return (stream.str());
        }

        template <typename... A>
        inline std::string to_string(const std::tuple<A...>& tup_, const std::string& pre_, const std::string& delim_, const std::string& app_) noexcept
        {
            std::stringstream stream;

            stream << pre_;
            arc::utl::apply_with_index(tup_, [&stream_]<typename L>(const L& val_, const size_t i, const size_t total) { stream_ << ((i == 0) ? "" : delim_) << val_; });
            stream << app_;

            return (stream.str());
        }



    } // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_CONVERT_HPP
