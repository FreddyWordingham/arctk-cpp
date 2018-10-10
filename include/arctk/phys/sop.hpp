/**
 *  @file   arctk/phys/sop.hpp
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Physical specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_SOP_HPP
#define ARCTK_PHYS_SOP_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/phys/cell.hpp>
#include <arctk/phys/photon.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Photon specific-optical-proeprties control class.
         */
        class Sop
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Sop(const Sop&) = default; //!< Defaulted copy constructor.
            inline Sop(Sop&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            inline ~Sop() noexcept override;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Sop& operator=(const Sop&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Sop& operator=(Sop&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual double interact_dist(random::Generator* rng_, const phys::Photon& phot_, const phys::Cell& cell_) const noexcept = 0;

            //  -- Interaction --
            virtual bool interact(random::Generator* rng_, phys::Photon* phot_, phys::Cell* cell_, const double dist_) const noexcept = 0;
        };



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_SOP_HPP
