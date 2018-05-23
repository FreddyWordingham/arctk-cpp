/**
 *  @file   arctk/data/table.hpp
 *  @date   23/05/2018
 *  @author Freddy Wordingham
 *
 *  Data table class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_TABLE_HPP
#define ARCTK_DATA_TABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <sstream>
#include <string>
#include <tuple>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace data //! data namespace
    {



        template <int... Is>
        struct seq
        {
        };

        template <int N, int... Is>
        struct gen_seq : gen_seq<N - 1, N - 1, Is...>
        {
        };

        template <int... Is>
        struct gen_seq<0, Is...> : seq<Is...>
        {
        };

        template <typename T, typename F, int... Is>
        std::string str_for_each(T&& t, F f, const size_t i, seq<Is...>)
        {
            std::stringstream stream;

            auto l = {(stream << f(std::get<Is>(t), i), 0)...};

            return (stream.str());
        }

        template <typename... Ts, typename F>
        std::string str_for_each_in_tuple(std::tuple<Ts...>& t, F f, const size_t i)
        {
            std::stringstream stream;

            stream << str_for_each(t, f, i, gen_seq<sizeof...(Ts)>());

            return (stream.str());
        }


        struct print_row
        {
            size_t index{0};

            template <typename T>
            std::string operator()(const T& t, const size_t i)
            {
                std::stringstream stream;

                if (index != 0)
                {
                    stream << ',';
                }

                if (i < t.size())
                {
                    stream << t[i];
                }
                else
                {
                    stream << "*";
                }

                ++index;

                return (stream.str());
            }
        };



        //  == CLASS ==
        /**
         *  Data table class.
         *  Stores vectors of different types.
         */
        template <class... T>
        class Table
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::tuple<std::vector<T>...> _cols; //!< Data columns.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Table(const std::tuple<std::vector<T>...> cols_) noexcept;


            //  == METHODS ==
          public:
            //  -- Access --
            template <std::size_t I, class... Ts>
            inline auto& col() noexcept;

            inline size_t num_cols() noexcept
            {
                return (sizeof...(T));
            }


            inline std::string str() noexcept
            {
                std::stringstream stream;

                for (size_t i = 0; i < 5; ++i)
                {
                    stream << str_for_each_in_tuple(_cols, print_row(), i) << "\n";
                }

                return (stream.str());
            }
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <class... T>
        inline Table<T...>::Table(const std::tuple<std::vector<T>...> cols_) noexcept
          : _cols(cols_)
        {
        }



        //  == METHODS ==
        //  -- Access --
        template <class... T>
        template <std::size_t I, class... Ts>
        inline auto& Table<T...>::col() noexcept
        {
            return (std::get<I>(_cols));
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
