/**
 *  @file   arctk/dom/cell.hpp
 *  @date   07/09/2018
 *  @author Freddy Wordingham
 *
 *  Domain cell base class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_CELL_HPP
#define ARCTK_DOM_CELL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/geom.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Domain cell class.
         */
        class Cell : public geom::shape::Aabb
        {
            //  == FIELDS ==
          private:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cell(const vec3& min_, const vec3& max_) noexcept;
            inline Cell(const Cell&) = default; //!< Defaulted copy constructor.
            inline Cell(Cell&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Cell() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Cell& operator=(const Cell&) = default;     //!< Defaulted copy operator. @return Reference to copied object.
            inline Cell& operator=(Cell&&) noexcept = default; //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Cell::Cell(const vec3& min_, const vec3& max_) noexcept
          : _Aabb(min_, max_)
        {
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_CELL_HPP
