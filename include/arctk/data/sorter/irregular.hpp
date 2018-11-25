/**
 *  @file   arctk/data/sorter/irregular.hpp
 *  @date   25/11/2018
 *  @author Freddy Wordingham
 *
 *  Irregular interval sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_IRREGULAR_HPP
#define ARCTK_DATA_SORTER_IRREGULAR_HPP



//  == BASE ==
#include <arctk/data/sorter.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace sorter //! sorting namespace
        {



            //  == CLASS ==
            /**
             *  Irregular interval sorting class.
             *
             *  @tparam T   Type sorted.
             */
            template <typename T>
            class Irregular : public Sorter<T>
            {
                //  == FIELDS ==
              protected:
                //  -- Bounds --
                std::vector<double> _bounds;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Irregular(const std::vector<double>& bounds_, const T& init_ = {}) noexcept;
                inline Irregular(const Irregular&) = default; //!< Defaulted copy constructor.
                inline Irregular(Irregular&&)      = default; //!< Defaulted move constructor.

                //  -- Destructors --
                inline ~Irregular() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Irregular& operator=(const Irregular&) noexcept = delete; //!< Defaulted copy operator. @return Reference to copied object.
                inline Irregular& operator=(Irregular&&) noexcept = delete;      //!< Defaulted move operator. @return Reference to moved object.
            };



        } // namespace sorter
    }     // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/sorter/irregular.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_IRREGULAR_HPP
