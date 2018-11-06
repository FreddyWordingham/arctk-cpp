/**
 *  @file   arctk/data/obj.hpp
 *  @date   06/12/2018
 *  @author Freddy Wordingham
 *
 *  Data object class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_OBJ_HPP
#define ARCTK_DATA_OBJ_HPP



//  == IMPORTS ==
//  -- Std --
#include <map>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data object class.
         */
        class Obj
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::map<std::string, std::string> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
        };



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/obj.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_OBJ_HPP
