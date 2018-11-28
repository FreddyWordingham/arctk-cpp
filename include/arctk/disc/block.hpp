/**
 *  @file   arctk/dom/block.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain discretisation material block class.
 */



//  == GUARD ==
#ifndef ARCTK_DISC_BLOCK_HPP
#define ARCTK_DISC_BLOCK_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>
#include <unordered_map>

//  -- Arctk --
#include <arctk/dom/driver.hpp>
#include <arctk/dom/mat.hpp>
#include <arctk/geom/shape/box.hpp>
#include <arctk/math/vec.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        class Photon;
    } // namespace phys
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace disc //! discretisation namespace
    {



        //  == CLASS ==
        /**
         *  Domain discretisation material block class.
         */
        class Block : geom::shape::Box
        {
            //  == FIELDS ==
          protected:
            //  -- Materials --
            std::unordered_map<std::string, std::unique_ptr<Mat>> _mats;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Block(const vec3& min_, const vec3& max_, const std::string& aether_id_, const Mat& aether_) noexcept;
            inline Block(const Block&)     = default; //!< Defaulted copy constructor.
            inline Block(Block&&) noexcept = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Block() noexcept;

          private:
            //  -- Initialisation --
            inline std::unordered_map<std::string, std::unique_ptr<Mat>> init_mats(const std::string& aether_id_, const Mat& aether_) const noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Block& operator=(const Block&) = default;     //!< Defaulted copy operator. @return Reference to copied object.
            inline Block& operator=(Block&&) noexcept = default; //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const Mat* mat(const std::string& mat_id_) const noexcept;

            //  -- Setters --
            inline void add_mat(const std::string& mat_id_, const Mat& mat_) noexcept;
        };



    } // namespace disc
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/disc/block.inl>



//  == GUARD END ==
#endif // ARCTK_DISC_BLOCK_HPP
