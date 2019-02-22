//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include <arctk/type/traits.hpp>

//  -- Str --
#include <iosfwd>
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace format
    {



        //  == FUNCTIONS ==
        //  -- String --
        template <typename T, typename = std::enable_if_t<type::is_printable_v<T>>>
        inline std::string string(const T& var_) noexcept;



    } // namespace format
} // namespace arc
