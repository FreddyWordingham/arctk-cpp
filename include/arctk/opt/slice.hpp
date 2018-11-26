/**
 *  @file   arctk/opt/slice.hpp
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Specific optical properties class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SLICE_HPP
#define ARCTK_OPT_SLICE_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {



        //  == CLASS ==
        /**
         *  Photon specific optical proeprties class.
         */
        class Slice
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Slice()             = default; //!< Defaulted constructor.
            inline Slice(const Slice&) = default; //!< Defaulted copy constructor.
            inline Slice(Slice&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Slice() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Slice& operator=(const Slice&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Slice& operator=(Slice&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual double ref_index() const noexcept = 0;
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/slice.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_SLICE_HPP
