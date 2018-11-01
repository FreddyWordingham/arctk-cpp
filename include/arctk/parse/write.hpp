/**
 *  @file   arctk/parse/write.hpp
 *  @date   21/10/2018
 *  @author Freddy Wordingham
 *
 *  Write parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_PARSE_WRITE_HPP
#define ARCTK_PARSE_WRITE_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/multi/vector.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {
        namespace write //! writing namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Format --
            inline std::string timestamp(long int sec_) noexcept;
            inline std::string bar(unsigned int length_, double frac_, char fill_ = '|') noexcept;

            //  -- Table --
            template <typename T, typename... A>
            inline std::string csv(const std::vector<T>& vec_, const A&... vecs_, unsigned int width_ = 16) noexcept;

            //  -- Image --
            // template <typename T>
            // inline std::string ppm(const std::string& path_, const multi::vector<double, 2>& data_) noexcept;



        } // namespace write
    }     // namespace parse
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/parse/write.inl>



//  == GUARD END ==
#endif // ARCTK_PARSE_WRITE_HPP
