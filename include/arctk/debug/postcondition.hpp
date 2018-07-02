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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace debug //! debugging namespace
    {



        //  == CLASS ==
        /**
         *  Geometric shape.
         */
        class PostCondition
        {
            //  == FIELDS ==
          private:
            const std::string           _file;
            const long int              _line;
            const std::string           _func;
            const std::string           _expr_str;
            const std::function<bool()> _expr;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --

            //  -- Destructors --
        };



    } // namespace debug
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DEBUG_POSTCONDITION_HPP