/**
 *  @file   arctk/sys/args.hpp
 *  @date   07/06/2018
 *  @author Freddy Wordingham
 *
 *  Program arguments class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_ARGS_HPP
#define ARCTK_SYS_ARGS_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <string>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace sys //! system namespace
    {



        //  == CLASS ==
        /**
         *  Initialise and store the command line arguments.
         *
         *  @tparam A   Types stored by the tuple.
         */
        template <typename... A>
        class Args
        {
            //  == FIELDS ==
          private:
            //  -- Information --
            const std::string _prog_name; //!< Name of the program.
            const std::string _call_str;  //!< Correct program call string.

            //  -- Arguments --
            std::tuple<A...> _argv; //!< Tuple of program arguments.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Args(const int argc_, const char** argv_, const std::string& call_str_) noexcept;



            //  == METHODS ==
          public:
            //  -- Getters --
            template <size_t I, typename T = typename std::tuple_element<I, std::tuple<A...>>::type>
            inline T get() noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        inline Args<A...>::Args(const int argc_, const char** argv_, const std::string& call_str_) noexcept
          : _prog_name(argv_[0])
          , _call_str(call_str_)
          , _element(init_elements(argc_, argv_))
        {
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename... A>
        template <size_t I, typename T>
        inline T Args<A...>::get() noexcept
        {
            return (std::get<I>(_argv));
        }



    } // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_ARGS_HPP
