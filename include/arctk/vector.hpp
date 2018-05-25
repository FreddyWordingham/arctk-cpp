/**
 *  @file   arctk/vector.hpp
 *  @date   25/05/2018
 *  @author Freddy Wordingham
 *
 *  Std::vector encapsulation class.
 */



//  == GUARD ==
#ifndef ARCTK_VECTOR_HPP
#define ARCTK_VECTOR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arc namespace
{



    //  == CLASS ==
    /**
     */
    template <class T>
    class Vector
    {
        //  == FIELDS ==
      private:
        //  -- Encapsulation --
        std::vector<T> _std; //!< Encapsulated vector.


        //  == INSTANTIATION ==
      public:
        //  -- Constructors --


        //  == METHODS ==
      public:
    };



    //  == INSTANTIATION --



    //  == METHODS ==



} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_VECTOR_HPP
