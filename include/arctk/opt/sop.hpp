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



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/phys/cell.hpp>
#include <arctk/phys/photon.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS PROTOTYPES ==
        class Photon;



    } // namespace phys
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {



        //  == CLASS PROTOTYPES ==
        class Photon;



        //  == CLASS ==
        /**
         *  Photon specific-optical-proeprties control class.
         */
        class Sop
        {
            //  == FIELDS ==
          protected:
            //  -- Optical Properties --
            const double _ref_index; //!< Refractive index.


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
            virtual double interact_dist(random::Generator* rng_, const phys::Cell* cell_) const
              noexcept = 0; //!< Get the distance until the next interaction event.  @param  rng_    Random number generator.    @param  cell_   Current domain cell.    @return Distance until the next interaction event.

            //  -- Interaction --
            virtual bool interact(random::Generator* rng_, phys::Photon* phot_, phys::Cell* cell_, double dist_) const
              noexcept = 0; //!< Perform an interaction event on the photon. @param  rng_    Random number generator.    @param  phot_   Photon to interact with.    @param  cell_   Current domain cell.    @param  dist_   Distance to the interaction event.
                            //!< @return False if the photon should be removed from the loop after interacting.
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a specific-optical-properties object with a given refractive index.
         *
         *  @param  ref_index_  Refractive index.
         *
         *  @pre    ref_index_ must be greater than, or equal to, unity.
         */
        inline Sop::Sop(const double ref_index_) noexcept
          : _ref_index(ref_index_)
        {
            assert(ref_index_ >= 1.0);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Sop::~Sop() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the refractive index of the specific-optical-property.
         *
         *  @return Refractive index of the specific-optical-property.
         */
        inline double Sop::ref_index() const noexcept
        {
            return (_ref_index);
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_HPP
