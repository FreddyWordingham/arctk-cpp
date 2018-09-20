/**
 *  @file   arctk/data/json.hpp
 *  @date   20/09/2018
 *  @author Freddy Wordingham
 *
 *  Json data class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_JSON_HPP
#define ARCTK_DATA_JSON_HPP



//  == IMPORTS ==
//  -- Std --
#include <iostream>
#include <string>

//  -- Arctk --
#include <arctk/exit.hpp>
#include <arctk/lib/nlohmann.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Json parser and data class.
         */
        class Json
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::string    _name;
            const nlohmann::json _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Json(const std::string& name_, const std::string& serial_) noexcept;

          private:
            //  -- Initialisation --
            inline nlohmann::json init_data(const std::string& t_serial) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Json::Json(const std::string& name_, const std::string& serial_) noexcept
          : _name(name_)
          , _data(init_data(serial_))
        {
        }


        //  -- Initialisation --
        inline nlohmann::json Json::init_data(const std::string& serial_) const noexcept
        {
            nlohmann::json data;

            try
            {
                std::stringstream(serial_) >> data;
            }
            catch (...)
            {
                std::cerr << "Unable to construct data::Json object.\n"
                          << "Unable to parse serialised data of.";

                std::exit(exit::error::FAILED_PARSE);
            }

            return (data);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_JSON_HPP
