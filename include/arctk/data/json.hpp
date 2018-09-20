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
//  -- Arctk --
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
            nlohmann::json init_data(const std::string& t_serial) const;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        Json::Json(const std::string& name_, const std::string& serial_)
          : _name(name_)
          , _data(init_data(serial_))
        {
        }


        //  -- Initialisation --
        nlohmann::json Json::init_data(const std::string& serial_) const
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
            }

            return (data);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_JSON_HPP
