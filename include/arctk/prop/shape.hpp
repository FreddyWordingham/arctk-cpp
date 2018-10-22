/**
 *  @file   arctk/prop/shape.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of shape property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_SHAPE_HPP
#define ARCTK_PROP_SHAPE_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {
        namespace shape //! shape§ namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Shape --
            template <typename T>
            inline bool square(const std::vector<std::vector<T>>& vec_) noexcept;
            template <typename T>
            inline bool cube(const std::vector<std::vector<std::vector<T>>>& vec_) noexcept;



            //  == FUNCTIONS ==
            //  -- Shape --
            /**
             *  Determine if a given two-dimensional vector may be considered square.
             *  To be considered square, all sub-vectors must be of the same size.
             *
             *  @tparam T   Type stored by the vector.
             *
             *  @param  vec_    Vector to test.
             *
             *  @return True if the given vector can be considered square.
             */
            template <typename T>
            inline bool square(const std::vector<std::vector<T>>& vec_) noexcept
            {
                const size_t size = vec_.front().size();

                for (size_t i = 1; i < vec_.size(); ++i)
                {
                    if (vec_[i].size() != size)
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Determine if a given three-dimensional vector may be considered cube.
             *  To be considered cube, all sub-vectors must be of the same size and all sub-sub-vectors must be of the same size.
             *
             *  @tparam T   Type stored by the vector.
             *
             *  @param  vec_    Vector to test.
             *
             *  @return True if the given vector can be considered cube.
             */
            template <typename T>
            inline bool cube(const std::vector<std::vector<std::vector<T>>>& vec_) noexcept
            {
                const std::array<size_t, 2> size({{vec_.front().size(), vec_.front().front().size()}});

                for (size_t i = 0; i < vec_.size(); ++i)
                {
                    if (vec_[i].size() != size[0])
                    {
                        return (false);
                    }

                    for (size_t j = 0; j < vec_.size(); ++j)
                    {
                        if (vec_[i][j].size() != size[1])
                        {
                            return (false);
                        }
                    }
                }

                return (true);
            }



        } // namespace shape
    }     // namespace prop
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PROP_SHAPE_HPP
