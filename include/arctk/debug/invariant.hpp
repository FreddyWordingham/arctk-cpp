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
#include <iostream>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace debug //! debugging namespace
    {



        //  == CLASS ==
        /**
         *  Invariant contract.
         */
        template <typename T>
        class Invariant
        {
            //  == FIELDS ==
          private:
            const std::string        _file;
            const long int           _line;
            const std::string        _func;
            const std::string        _expr_str;
            const std::function<T()> _expr;
            const T                  _expr_pre;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            Invariant(const std::string& file_, const long int line_, const std::string& func_, const std::string& expr_str_, const std::function<T()>& expr_);

            //  -- Destructors --
            ~Invariant();
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        Invariant::Invariant(const std::string& file_, const long int line_, const std::string& func_, const std::string& expr_str_, const std::function<bool()>& expr_)
          : _file(file_)
          , _line(line_)
          , _func(func_)
          , _expr_str(expr_str_)
          , _expr(expr_)
          , _expr_pre(expr())
        {
        }


        //  -- Destructors --
        Invariant::~Invariant()
        {
            if (_expr_pre != _expr())
            {
                std::cout << "Invariance     : `" << _expr_str << "` failed.\n";
                std::cout << "Located at     :\n" << location(_file, _line, _func, 4) << '\n';

                exit(43);
            }
        }



    } // namespace debug
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DEBUG_INVARIANT_HPP