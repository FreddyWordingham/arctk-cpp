/**
 *  @file   arctk/data/obj.hpp
 *  @date   06/11/2018
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
            std::map<std::string, std::string> _data; //!< Map of key-value data strings.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Obj(const std::string& serial_) noexcept;

          private:
            //  -- Initialisation --
            inline std::map<std::string, std::string> init_data(const std::string& serial_) const noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline Obj operator[](const std::string& key_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Checking --
            inline bool exists(const std::string& key_) const noexcept;

            //  -- Parsing --
            template <typename T>
            inline T value(const std::string& key_) const noexcept;
            template <typename T>
            inline T value(const std::string& key_, const T& default_) const noexcept;
        };



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/obj.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_OBJ_HPP
