/**
 *  @file   arctk/debug/invariant.hpp
 *  @date   03/07/2018
 *  @author Freddy Wordingham
 *
 *  Debug contract invariant class.
 */



//  == GUARD ==
#ifndef ARCTK_DEBUG_INVARIANT_HPP
#define ARCTK_DEBUG_INVARIANT_HPP



//  == IMPORTS ==
//  -- Std --
#include <functional>
#include <iostream>

//  -- Arctk --
#include <arctk/debug/location.hpp>
#include <arctk/exit.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace debug //! debugging namespace
    {



        //  == CLASS ==
        /**
         *  Invariant contract.
         *
         *  @tparam T   Resultant type of invariant expression.
         */
        template <typename T>
        class Invariant
        {
            //  == FIELDS ==
          private:
            //  -- Location --
            const std::string _file; //!< File name of the invocation location.
            const int         _line; //!< File line number of the invocation location.
            const std::string _func; //!< Function name of the invocation location.

            //  -- Expression --
            const std::string        _expr_str; //!< String form of the invariant expression.
            const std::function<T()> _expr;     //!< Expression to be tested for invariance.
            const T                  _expr_pre; //!< Result of invariant expression at construction time.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Invariant(const std::string& file_, int line_, const std::string& func_, const std::string& expr_str_, const std::function<T()>& expr_) noexcept;
            inline Invariant(const Invariant&) noexcept = default; //!< Defaulted copy constructor.
            inline Invariant(Invariant&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            inline ~Invariant() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Invariant& operator=(const Invariant&) noexcept = delete; //!< Defaulted copy operator. @return Reference to copied object.
            inline Invariant& operator=(Invariant&&) noexcept = delete;      //!< Defaulted move operator. @return Reference to moved object.
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an invariant test object.
         *
         *  @param  file_       File name of the invocation location.
         *  @param  line_       File line number of the invocation location.
         *  @param  func_       Function name of the invocation location.
         *  @param  expr_str_   String form of the invariant expression.
         *  @param  expr_       Expression to be tested for invariance.
         */
        template <typename T>
        inline Invariant<T>::Invariant(const std::string& file_, const int line_, const std::string& func_, const std::string& expr_str_, const std::function<T()>& expr_) noexcept
          : _file(file_)
          , _line(line_)
          , _func(func_)
          , _expr_str(expr_str_)
          , _expr(expr_)
          , _expr_pre(expr_())
        {
        }


        //  -- Destructors --
        /**
         *  Destruct the invariant object and check that the result of the invariant expression is equal to the value at construction.
         *  If the expression no longer equals its previous value then report an error and exit.
         */
        template <typename T>
        inline Invariant<T>::~Invariant() noexcept
        {
            if (_expr_pre != _expr())
            {
                std::cerr << "Invariance     : `" << _expr_str << "` failed.\n"
                          << "Located at     :\n"
                          << location::info(_file, _line, _func, 4) << '\n';

                std::exit(arc::exit::error::INVARIANT_FAILURE);
            }
        }



    } // namespace debug
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DEBUG_INVARIANT_HPP
