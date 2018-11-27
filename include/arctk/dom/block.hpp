/**
 *  @file   arctk/dom/block.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain discretisation block class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_BLOCK_HPP
#define ARCTK_DOM_BLOCK_HPP



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace tree //! tree namespace
    {



        //  == CLASS ==
        /**
         *  Domain discretisation block class.
         */
        class Block
        {
            //  == FIELDS ==
          protected:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            //     inline Node(const vec3& min_, const vec3& max_, size_t depth_) noexcept;
            //     inline Node(const Node&) noexcept = default; //!< Defaulted copy constructor.
            //     inline Node(Node&&) noexcept      = default; //!< Defaulted move constructor.

            //     //  -- Destructors --
            //     inline ~Node() noexcept override;


            //     //  == OPERATORS ==
            //   public:
            //     //  -- Assignment --
            //     inline Node& operator=(const Node&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            //     inline Node& operator=(Node&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace tree
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/block.inl>



//  == GUARD END ==
#endif // ARCTK_DOM_BLOCK_HPP
