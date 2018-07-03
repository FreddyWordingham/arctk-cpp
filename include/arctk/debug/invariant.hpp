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



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



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
            const long int    _line; //!< File line number of the invocation location.
            const std::string _func; //!< Function name of the invocation location.

            //  -- Expression --
            const std::string        _expr_str; //!< String form of the invariant expression.
            const std::function<T()> _expr;     //!< Expression to be tested for invariance.
            const T                  _expr_pre; //!< Result of invariant expression at construction time.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            Invariant(const std::string& file_, const long int line_, const std::string& func_, const std::string& expr_str_, const std::function<T()>& expr_);

            //  -- Destructors --
            ~Invariant();
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
        Invariant<T>::Invariant(const std::string& file_, const long int line_, const std::string& func_, const std::string& expr_str_, const std::function<T()>& expr_)
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
        Invariant<T>::~Invariant()
        {
            if (_expr_pre != _expr())
            {
                std::cerr << "Invariance     : `" << _expr_str << "` failed.\n";
                std::cerr << "Located at     :\n" << location::info(_file, _line, _func, 4) << '\n';

                exit(arc::errno::INVARIANT_FAILURE);
            }
        }



    } // namespace debug
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DEBUG_INVARIANT_HPP