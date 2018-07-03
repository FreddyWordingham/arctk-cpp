/**
 *  @file   arctk/debug/postcondition.hpp
 *  @date   03/07/2018
 *  @author Freddy Wordingham
 *
 *  Location postcondition debug class.
 */



//  == GUARD ==
#ifndef ARCTK_DEBUG_POSTCONDITION_HPP
#define ARCTK_DEBUG_POSTCONDITION_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <functional>
#include <iostream>

//  -- Arctk --
#include <arctk/debug/location.hpp>
#include <arctk/settings.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace debug //! debugging namespace
    {



        //  == CLASS ==
        /**
         *  Post-condition contract.
         */
        class PostCondition
        {
            //  == FIELDS ==
          private:
            //  -- Location --
            const std::string _file; //!< File name of the invocation location.
            const long int    _line; //!< File line number of the invocation location.
            const std::string _func; //!< Function name of the invocation location.

            //  -- Expression --
            const std::string           _expr_str; //!< String form of the invariant expression.
            const std::function<bool()> _expr;     //!< Expression to be tested at object destruction.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            PostCondition(const std::string& file_, const long int line_, const std::string& func_, const std::string& expr_str_, const std::function<bool()>& expr_);

            //  -- Destructors --
            ~PostCondition();
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an post-condition test object.
         *
         *  @param  file_       File name of the invocation location.
         *  @param  line_       File line number of the invocation location.
         *  @param  func_       Function name of the invocation location.
         *  @param  expr_str_   String form of the post-condition expression.
         *  @param  expr_       Expression to be tested at object destruction.
         */
        PostCondition::PostCondition(const std::string& file_, const long int line_, const std::string& func_, const std::string& expr_str_, const std::function<bool()>& expr_)
          : _file(file_)
          , _line(line_)
          , _func(func_)
          , _expr_str(expr_str_)
          , _expr(expr_)
        {
        }


        //  -- Destructors --
        /**
         *  Destruct the post-condition object and check that the result of the expression is true.
         */
        PostCondition::~PostCondition()
        {
            if (!_expr())
            {
                std::cerr << "Post-condition : `" << _expr_str << "` failed.\n";
                std::cerr << "Located at     :\n" << location::info(_file, _line, _func, 4) << '\n';

                exit(43);
            }
        }



    } // namespace debug
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DEBUG_POSTCONDITION_HPP