/**
 *  @file   arctk/random/generator/dirty.inl
 *  @date   09/11/2018
 *  @author Freddy Wordingham
 *
 *  Pseudo random number generator class focused on quick-and-dirty production of random numbers.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_GENERATOR_DIRTY_INL
#define ARCTK_RANDOM_GENERATOR_DIRTY_INL



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace generator //! random number generator engine namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a dirty generator.
             */
            inline Dirty::Dirty() noexcept
              : _u(_seed)
            {
                gen_base();
                gen_base();
                gen_base();
            }



            //  == METHODS ==
            //  -- Generation --
            /**
             *  Generate a base value which can then be transformed into a double.
             *
             *  @return Random integral value.
             */
            inline uint64_t Dirty::gen_base() noexcept
            {
                _u = (static_cast<uint64_t>(1664525) * _u) + static_cast<uint64_t>(1013904223);

                return (_u);
            }

            /**
             *  Generate a floating point value between zero and unity.
             *
             *  @return Floating point value between zero and unity.
             */
            inline double Dirty::gen() noexcept
            {
                return (static_cast<double>(gen_base()) * (1.0 / static_cast<double>(std::numeric_limits<uint64_t>::max())));
            }



        } // namespace generator
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_GENERATOR_DIRTY_INL
