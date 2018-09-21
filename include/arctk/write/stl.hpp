/**
 *  @file   arctk/write/stl.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Stl class writing operators and functions.
 */



//  == GUARD ==
#ifndef ARCTK_WRITE_STL_HPP
#define ARCTK_WRITE_STL_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace write //! write namespace
    {
        namespace stl //! standard template library namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Vector --
            template <typename T>
            inline std::ostream& vec(std::ostream& stream_, const std::vector<T>& vec_, const std::string& open_ = '{', const std::string& close_ = '}', const std::string& delim_ = ", ") noexcept;



            //  == FUNCTIONS ==
            //  -- Vector --
            template <typename T>
            inline std::ostream& vec(std::ostream& stream_, const std::vector<T>& vec_, const std::string& open_ = '{', const std::string& close_ = '}', const std::string& delim_ = ", ") noexcept
            {
                stream_ << open_ << vec_[0];
                for (size_t i = 1; i < vec_.size(); ++i)
                {
                    stream_ << delim_ << vec_[i];
                }
                stream_ << close_;

                return (stream_);
            }



        } // namespace stl
    }     // namespace write
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_WRITE_STL_HPP
