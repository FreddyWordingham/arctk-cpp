/**
 *  @file   arctk/dom/block.inl
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain discretisation block class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_BLOCK_INL
#define ARCTK_DOM_BLOCK_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Block::~Block() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        inline double Block::energy_density() const noexcept
        {
            return (_energy / _volume);
        }

        inline double Block::scatterivity() const noexcept
        {
            return (_scatter / _volume);
        }

        inline double Block::absorptivity() const noexcept
        {
            return (_energy / _volume);
        }

        inline double Block::emissivity() const noexcept
        {
            return (_energy / _volume);
        }



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_BLOCK_INL
