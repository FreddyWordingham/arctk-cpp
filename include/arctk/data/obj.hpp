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
#include <string>



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
            inline Obj(const std::string& serial_) noexcept;

          private:
            //  -- Initialisation --
            inline std::map<std::string, std::string> init_data(const std::string& serial_) const noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline const std::string& operator[](const std::string& key_) noexcept
            {
                return (_data[key_]);
            }
        };



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/obj.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_OBJ_HPP
