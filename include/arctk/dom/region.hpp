/**
 *  @file   arctk/dom/region.hpp
 *  @date   08/10/2018
 *  @author Freddy Wordingham
 *
 *  Domain region control class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_REGION_HPP
#define ARCTK_DOM_REGION_HPP



//  == BASE ==
#include <arctk/geom/shape/box.hpp>



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/dom/cell.hpp>
#include <arctk/math/vec.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Domain region cell.
         */
        class Region : public geom::shape::Box
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::array<size_t, 3>                      _res;       //!< Resolution of the domain cells.
            std::vector<std::vector<std::vector<dom::Cell>>> _cells;     //!< Three-dimensional vector of cells.
            const vec3                                       _cell_size; //!< Size of each domain cell.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Region(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept;

          private:
            //  -- Initialisation --
            inline std::vector<std::vector<std::vector<dom::Cell>>> init_cells(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<size_t, 3>&                            res() const noexcept;
            inline const std::vector<std::vector<std::vector<dom::Cell>>>& cells() const noexcept;
            inline const vec3&                                             cell_size() const noexcept;
            inline size_t                                                  num_cells() const noexcept;

            //  -- Retrieval --
            inline dom::Cell* cell(const vec3& pos_) noexcept;

            //  -- Saving --
            inline void save(const std::string& path_) const noexcept; // NOLINT
        };



    } // namespace dom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/region.inl>



//  == GUARD END ==
#endif // ARCTK_DOM_REGION_HPP
