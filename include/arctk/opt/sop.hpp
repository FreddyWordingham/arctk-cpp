/**
 *  @file   arctk/opt/sop.hpp
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SOP_HPP
#define ARCTK_OPT_SOP_HPP



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        class Cell;
    }              // namespace dom
    namespace phys //! physics namespace
    {
        class Photon;
    }                // namespace phys
    namespace random //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {



        //  == CLASS ==
        /**
         *  Photon specific-optical-proeprties control class.
         */
        class Sop
        {
            //  == FIELDS ==
          protected:
            //  -- Optical Properties --
            const double _ref_index;        //!< Refractive index.
            const double _interaction_coef; //!< Interaction coefficient.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Sop(double ref_index_) noexcept;
            inline Sop(const Sop&) = default; //!< Defaulted copy constructor.
            inline Sop(Sop&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Sop() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Sop& operator=(const Sop&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Sop& operator=(Sop&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double  ref_index() const noexcept;
            virtual double interact_dist(random::Generator* rng_, const dom::Cell* cell_) const
              noexcept = 0; //!< Get the distance until the next interaction event.  @param  rng_    Random number generator.    @param  cell_   Current domain cell.    @return Distance until the next interaction event.

            //  -- Interaction --
            virtual bool interact(random::Generator* rng_, phys::Photon* phot_, dom::Cell* cell_, double dist_) const
              noexcept = 0; //!< Perform an interaction event on the photon. @param  rng_    Random number generator.    @param  phot_   Photon to interact with.    @param  cell_   Current domain cell.    @param  dist_   Distance to the interaction event.
                            //!< @return True if the photon's specific-optical-properties require updating after the interaction event.
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/sop.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_HPP
