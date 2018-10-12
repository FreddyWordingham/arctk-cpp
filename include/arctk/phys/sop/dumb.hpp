/**
 *  @file   arctk/phys/sop/dumb.hpp
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Dumb physical specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_SOP_DUMB_HPP
#define ARCTK_PHYS_SOP_DUMB_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/phys/cell.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/phys/sop.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Dumb specific-optical-proeprties control class.
         */
        class Dumb : public Sop
        {
            //  == FIELDS ==
          private:
            //  -- Properties --
            const double _dist;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Dumb(double dist_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double interact_dist(random::Generator* /*unused*/, const phys::Photon& /*unused*/, const phys::Cell& /*unused*/) const noexcept override;

            //  -- Interaction --
            inline bool interact(random::Generator* /*unused*/, phys::Photon* phot_, phys::Cell* /*unused*/, const double dist_) const noexcept override;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Dumb::Dumb(const double dist_) noexcept
          : _dist(dist_)
        {
            PRE(_dist > 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        inline double Dumb::interact_dist(const random::Generator* /*unused*/, const phys::Photon& /*unused*/, const phys::Cell& /*unused*/) const noexcept
        {
            return (_dist);
        }


        //  -- Interaction --
        inline bool Dumb::interact(const random::Generator* /*unused*/, const phys::Photon* phot_, const phys::Cell* /*unused*/, const double dist_) const noexcept
        {
            phot_->move(dist_);
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_SOP_DUMB_HPP
