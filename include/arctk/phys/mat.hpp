/**
 *  @file   arctk/phys/mat.hpp
 *  @date   12/10/2018
 *  @author Freddy Wordingham
 *
 *  Physical optical-properties material class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MAT_HPP
#define ARCTK_PHYS_MAT_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>

//  -- Arctk --
#include <arctk/phys/photon.hpp>
#include <arctk/phys/sop.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  An optical properties material capable of generating specific optical properties.
         */
        class Mat
        {
            //  == FIELDS ==
          private:
            //  -- Optical Properties --


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Mat(const Mat&) = default; //!< Defaulted copy constructor.
            inline Mat(Mat&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Mat() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Mat& operator=(const Mat&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Mat& operator=(Mat&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Specific Optical Properties --
            virtual std::unique_ptr<Sop> gen(const Photon& phot_) const noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Mat::~Mat() noexcept = default;



        //  == METHODS ==
        //  -- Getters --



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MAT_HPP
