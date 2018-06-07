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
#include <tuple>
#include <vector>

//  -- Arctk --
#include <arctk/parse.hpp>



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

            //  -- Initialisation --
            inline std::tuple<A...> init_argv(const int argc_, const char** argv_) noexcept;
            template <typename T>
            inline void check_parsable(const std::string& str_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            template <size_t I, typename T = typename std::tuple_element<I, std::tuple<A...>>::type>
            inline T get() noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct the command line arguments object.
         *
         *  @tparam A   Types stored by the tuple.
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
         *  @tparam A   Types stored by the tuple.
         *
         *  @param  argc_   Argument count.
         *  @param  argv_   Argument values.
         *
         *  @pre    argc_ must be positive.
         */
        template <typename... A>
        inline std::tuple<A...> Args<A...>::init_argv(const int argc_, const char** argv_) noexcept
        {
            assert(argc_ > 0);

            const std::vector<std::string> argv(argv_ + 1, argv_ + argc_);

            if (argv.size() != sizeof...(A))
            {
                LOG << "Correct call: " << _prog_name << " " << _call_str;
                ERROR(42) << "Incorrect number of command line arguments.\n"
                          << "Expected " << sizeof...(A) << ", received " << argv.size() << ".";
            }

            size_t i = 0;
            ((check_parsable<A>(argv[i]), ++i), ...);

            return (parse::from_str<A...>(argv));
        }

        /**
         *  Check that a string is parsable into its required type.
         *  If it is not, report an error.
         *
         *  @tparam A   Types stored by the tuple.
         *
         *  @tparam T   Type to parse string into.
         *
         *  @param  str_    String to parse into value.
         */
        template <typename... A>
        template <typename T>
        inline void Args<A...>::check_parsable(const std::string& str_) noexcept
        {
            if (!parse::parsable_from_str<T>(str_))
            {
                LOG << "Correct call: " << _prog_name << " " << _call_str;
                ERROR(42) << "Argument string: '" << str_ << "' is not parsable as type: '" << typeid(T).name() << "'.";
            }
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Retrieve the value of a command line argument.
         *
         *  @tparam A   Types stored by the tuple.
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



    } // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_ARGS_HPP
