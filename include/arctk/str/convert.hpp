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
//  -- Std --
#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>

//  -- Arctk --
#include <arctk/settings.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {



        //  == FUNCTORS ==
        /**
         *  Functor used by to_string tuple method.
         *  Required while standard does not support template lambdas.
         *  Should be able to remove this in c++2a.
         */
        struct TupleToString
        {
            //  == FIELDS ==
          private:
            //  -- Stream --
            std::stringstream& _stream; //!< Stream to write to.

            //  -- Formatting --
            const char   _delim; //!< Delimiter character added between elements.
            const size_t _width; //!< Print width allocated to each element.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            /**
             *  Construct a TupleToString functor which will write to a given stream.
             *
             *  @param  stream_ Stream to write to.
             *  @param  width_  Print width allocated to each element.
             *  @param  delim_  Delimiter character added between elements.
             */
            TupleToString(std::stringstream& stream_, const char delim_, const size_t width_)
              : _stream(stream_)
              , _delim(delim_)
              , _width(width_)
            {
            }


            //  == OPERATORS ==
          public:
            //  -- Call --
            /**
             *  Write the element to _stream.
             *
             *  @param  val_    Value to write to the _stream.
             *  @param  i_      Index of element.
             */
            template <typename L>
            void operator()(const L& val_, const size_t i_, const size_t /*unused*/)
            {
                _stream << ((i_ == 0) ? ' ' : _delim) << std::setw(_width) << val_;
            }
        };



        //  == FUNCTION PROTOTYPES ==
        //  -- Conversion --
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline std::string to_string(const C& cont_, size_t width_ = settings::DEFAULT_PRINT_WIDTH, const std::string& pre_ = "{", const char delim_ = settings::DEFAULT_DELIM, const std::string& post_ = "}");
        template <typename A0, typename A1>
        inline std::string to_string(const std::pair<A0, A1>& pair_, size_t width_ = settings::DEFAULT_PRINT_WIDTH, const std::string& pre_ = "(", const char delim_ = settings::DEFAULT_DELIM, const std::string& post_ = ")");
        template <typename... A>
        inline std::string to_string(const std::tuple<A...>& tup_, size_t width_ = settings::DEFAULT_PRINT_WIDTH, const std::string& pre_ = "(", const char delim_ = settings::DEFAULT_DELIM, const std::string& post_ = ")");

        //  -- Time --
        inline std::string time(uint64_t us_) noexcept;



        //  == FUNCTIONS ==
        //  -- Conversion --
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
         *  @param  delim_  Delimiter character added between elements.
         *  @param  post_   String appended after the element data.
         *
         *  @return A human-readable string of the container.
         */
        template <typename C, typename T, typename I>
        inline std::string to_string(const C& cont_, const size_t width_, const std::string& pre_, const char delim_, const std::string& post_)
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
         *  @param  delim_  Delimiter character added between elements.
         *  @param  post_   String appended after the element data.
         *
         *  @return A human-readable string of the pair.
         */
        template <typename A0, typename A1>
        inline std::string to_string(const std::pair<A0, A1>& pair_, const size_t width_, const std::string& pre_, const char delim_, const std::string& post_)
        {
            std::stringstream stream;

            stream << pre_ << std::setw(width_) << std::get<0>(pair_) << delim_ << std::setw(width_) << std::get<1>(pair_) << post_;

            return (stream.str());
        }

        /**
         *  Form a tuple into a human-readable string.
         *  C++17 does not support template lambdas.
         *  Helper functor can be replaced with template lambda in C++2a.
         *
         *  @tparam A   Types stored by the tuple.
         *
         *  @param  tup_    Tuple to print.
         *  @param  width_  Print width allocated to each element.
         *  @param  pre_    String prepended before the element data.
         *  @param  delim_  Delimiter character added between elements.
         *  @param  post_   String appended after the element data.
         *
         *  @return A human-readable string of the tuple.
         */
        template <typename... A>
        inline std::string to_string(const std::tuple<A...>& tup_, const size_t width_, const std::string& pre_, const char delim_, const std::string& post_)
        {
            std::stringstream stream;

            stream << pre_;
            //            arc::utl::apply_with_index(tup_, [&stream, &delim_, width_]<typename L>(const L& val_, const size_t i, const size_t total) { stream << ((i == 0) ? "" : delim_) << std::setw(width_) << val_; });
            arc::utl::apply_with_index(tup_, TupleToString(stream, delim_, width_));
            stream << post_;

            return (stream.str());
        }


        //  -- Time --
        /**
         *  Convert the number of microseconds into a time string.
         *
         *  @param  us_ Number of microseconds.
         *
         *  @return String of the time.
         */
        inline std::string time(uint64_t us_) noexcept
        {
            const uint64_t hrs = us_ / 3600000000;
            us_ %= 3600000000;

            const uint64_t min = us_ / 60000000;
            us_ %= 60000000;

            const uint64_t sec = us_ / 1000000;
            us_ %= 1000000;

            const uint64_t ms = us_ / 1000;
            us_ %= 1000;

            return (std::to_string(hrs) + "hrs " + std::to_string(min) + "min " + std::to_string(sec) + "sec " + std::to_string(ms) + "ms " + std::to_string(us_) + "µs");
        }



    } // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_CONVERT_HPP
