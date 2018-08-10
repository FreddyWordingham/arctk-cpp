/**
 *  @file   arctk/phys/material/simple.hpp
 *  @date   10/08/2018
 *  @author Freddy Wordingham
 *
 *  Simple material physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MATERIAL_SIMPLE_HPP
#define ARCTK_PHYS_MATERIAL_SIMPLE_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace material //! material namespace
        {



            //  == CLASS ==
            /**
             *  Simple material class.
             */
            class Simple : public Material
            {
                //  == FIELDS ==
              private:
                //  -- Interaction --
                const double _dist;

                //  -- Scattering --
                const double _g;



                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Simple(double dist_, double g_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Simple::Simple(const double dist_, const double g_) noexcept
              : _dist(dist_)
              , _g(g_)
            {
                PRE(dist > 0.0);
                PRE((g_ >= -1.0) && (g_ <= 1.0));
            }



            //  == METHODS ==



        } // namespace material
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_SIMPLE_HPP
