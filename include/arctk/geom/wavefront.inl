/**
 *  @file   arctk/geom/wavefront.inl
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Wavefront reader helper class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_WAVEFRONT_INL
#define ARCTK_GEOM_WAVEFRONT_INL



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Wavefront::Wavefront(const std::string& base_) noexcept
          : _base(base_)
          , _scale(1.0, 1.0, 1.0)
          , _rot(0.0, 0.0, 0.0)
          , _trans(0.0, 0.0, 0.0)
        {
            assert(!base_.empty());
        }



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_WAVEFRONT_INL
