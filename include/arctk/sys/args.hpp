/**
 *  @file   arctk/sys/args.hpp
 *  @date   04/07/2018
 *  @author Freddy Wordingham
 *
 *  Program arguments class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_ARGS_HPP
#define ARCTK_SYS_ARGS_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>
#include <tuple>



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
            //  == ASSERTIONS ==
            //  -- Size --
            static_assert(sizeof...(A) > 0);


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
            inline Args(int argc_, const char** argv_, const std::string& call_str_) noexcept;

          private:
            //  -- Initialisation --
            inline std::tuple<A...> init_argv(int argc_, const char** argv_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            template <size_t I, typename T = typename std::tuple_element<I, std::tuple<A...>>::type>
            inline T                       get() noexcept;
            inline const std::tuple<A...>& argv() const noexcept;
        };



    } // namespace sys
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/sys/args.inl>



//  == GUARD END ==
#endif // ARCTK_SYS_ARGS_HPP
