/**
 *  @file   arctk/opt/mat.hpp
 *  @date   12/10/2018
 *  @author Freddy Wordingham
 *
 *  Optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MAT_HPP
#define ARCTK_OPT_MAT_HPP



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <memory>

//  -- Arctk --
#include <arctk/phys/photon.hpp>
#include <arctk/phys/sop.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {



        //  == CLASS ==
        /**
         *  An optical properties material capable of generating specific optical properties.
         */
        class Mat
        {
            //  == INSTANTIATION ==
          private:
            //  -- Bounds --
            const double _min; //!< Minimum valid wavelength of the material.
            const double _max; //!< Maximum valid wavelength of the material.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Mat(double min_, double max_) noexcept;
            inline Mat(const Mat&) = default; //!< Defaulted copy constructor.
            inline Mat(Mat&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Mat() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Mat& operator=(const Mat&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Mat& operator=(Mat&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double min() const noexcept;
            inline double max() const noexcept;

            //  -- Specific Optical Properties --
            virtual std::unique_ptr<Sop> gen(const Photon& phot_) const
              noexcept = 0; //!< Generate specific-optical-proeprties for    @param  phot_   Photon to generate specific-optical-properties for. @return Specific-optical-properties for the given photon.
        };



        //  == INSTANTIATION ==
        //  -- Destructors --
        /**
         *  Construct a material which can generate specific-optical-properties for given wavelength bounds.
         *
         *  @param  min_    Minimum wavelength bound.
         *  @param  max_    Maximum wavelength bound.
         *
         *  @pre    min_ must be less than, or equal to, max_.
         */
        inline Mat::Mat(const double min_, const double max_) noexcept
          : _min(min_)
          , _max(max_)
        {
            assert(min_ <= max_);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Mat::~Mat() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum wavelength bound of the material.
         *
         *  @return Minimum wavelength bound of the material.
         */
        inline double Mat::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum wavelength bound of the material.
         *
         *  @return Maximum wavelength bound of the material.
         */
        inline double Mat::max() const noexcept
        {
            return (_max);
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MAT_HPP
