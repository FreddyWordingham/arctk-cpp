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
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/exit.hpp>
#include <arctk/parse/read.hpp>



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



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct the command line arguments object.
         *
         *  @param  argc_       Argument count.
         *  @param  argv_       Argument values.
         *  @param  call_str_   Correct call string for the program.
         *
         *  @pre    argc_ must be positive.
         */
        template <typename... A>
        inline Args<A...>::Args(const int argc_, const char** argv_, const std::string& call_str_) noexcept
          : _prog_name(argv_[0])
          , _call_str(call_str_)
          , _argv(init_argv(argc_, argv_))
        {
            assert(argc_ > 0);
        }


        //  -- Initialisation --
        /**
         *  Initialise the tuple of argument values.
         *  Check that the required number of command line arguments are given, if not, report an error.
         *  Check that each string is parsable to it's required type.
         *
         *  @param  argc_   Argument count.
         *  @param  argv_   Argument values.
         *
         *  @pre    argc_ must be positive.
         *
         *  @return Initialised tuple of argument values.
         */
        template <typename... A>
        inline std::tuple<A...> Args<A...>::init_argv(const int argc_, const char** argv_) noexcept
        {
            assert(argc_ > 0);

            const std::vector<const char*> argv(argv_ + 1, argv_ + argc_);

            if (argv.size() != sizeof...(A))
            {
                std::cerr << "Incorrect number of command line arguments.\n"
                          << "Expected " << sizeof...(A) << ", received " << argv.size() << ".\n";
                std::cerr << "Correct call: " << _prog_name << " " << _call_str << '\n';

                std::exit(exit::error::INVALID_COMMAND_LINE_ARGUMENTS);
            }

            std::stringstream stream;
            stream << consts::format::OPENERS[consts::format::container::TUPLE] << argv[0];
            for (size_t i = 1; i < argv.size(); ++i)
            {
                stream << consts::format::DELIM << argv[i];
            }
            stream << consts::format::CLOSERS[consts::format::container::TUPLE];

            std::string str(stream.str());

            return (parse::read::string<std::tuple<A...>>(&str));
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Retrieve the value of a command line argument.
         *
         *  @tparam I   Index of the command line argument to retrieve.
         *  @tparam T   Type of Ith type of A.
         *
         *  @return Value of the command line argument.
         */
        template <typename... A>
        template <size_t I, typename T>
        inline T Args<A...>::get() noexcept
        {
            return (std::get<I>(_argv));
        }

        /**
         *  Get the tuple of parsed arguments.
         *
         *  @return Tuple of parsed arguments.
         */
        template <typename... A>
        inline const std::tuple<A...>& Args<A...>::argv() const noexcept
        {
            return (_argv);
        }



    } // namespace sys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SYS_ARGS_HPP
