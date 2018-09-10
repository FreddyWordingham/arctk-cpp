/**
 *  @file   arctk/data/cube3.hpp
 *  @date   10/09/2018
 *  @author Freddy Wordingham
 *
 *  Three-dimensional data cube class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_CUBE3_HPP
#define ARCTK_DATA_CUBE3_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/data/cube.hpp>
#include <arctk/debug.hpp>
#include <arctk/index.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Three-dimensional data cube class.
         *
         *  @tparam T   Type binned.
         */
        template <typename T>
        class Cube<T, 3>
        {
            //  == FIELDS ==
          private:
            //  -- Resolution --
            const std::array<size_t, 3> _res;

            //  -- Data --
            std::vector<std::vector<std::vector<T>>> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cube(const std::array<size_t, 3>& res_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline std::vector<std::vector<T>>&       operator[](size_t index_) noexcept;
            inline const std::vector<std::vector<T>>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<size_t, 3> res() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        inline Cube<T, 3>::Cube(const std::array<size_t, 3>& res_) noexcept
          : _data(res_[index::dim::cartesian::X], std::vector<std::vector<T>>(res_[index::dim::cartesian::Y], std::vector<T>(res_[index::dim::cartesian::Z])))
        {
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }



        //  == OPERATORS ==
        //  -- Access --
        template <typename T>
        inline std::vector<std::vector<T>>& Cube<T, 3>::operator[](const size_t index_) noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }

        template <typename T>
        inline const std::vector<std::vector<T>>& Cube<T, 3>::operator[](const size_t index_) const noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T>
        inline const std::array<size_t, 3> Cube<T, 3>::res() const noexcept
        {
            return (_res);
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE3_HPP
