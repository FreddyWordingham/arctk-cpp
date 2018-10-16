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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
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
            const double _ref_index;


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
            inline Sop& operator=(const Sop&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Sop& operator=(Sop&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double  ref_index() const noexcept;
            virtual double interact_dist(random::Generator* rng_, const phys::Cell* cell_) const noexcept = 0;

            //  -- Interaction --
            virtual bool interact(random::Generator* rng_, phys::Photon* phot_, phys::Cell* cell_, const double dist_) const noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Sop::Sop(const double ref_index_) noexcept
          : _ref_index(ref_index_)
        {
            PRE(ref_index_ >= 1.0);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Sop::~Sop() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        inline double Sop::ref_index() const noexcept
        {
            return (_ref_index);
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_SOP_HPP
