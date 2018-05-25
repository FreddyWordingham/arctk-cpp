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


        //  == OPERATORS ==
      public:
        //  -- Access --
        inline T&       operator[](size_t index_) noexcept;
        inline const T& operator[](size_t index_) const noexcept;


        //  == METHODS ==
      public:
        //  -- Getters --
        inline std::vector<T>&       std() noexcept;
        inline const std::vector<T>& std() const noexcept;
    };



    //  == INSTANTIATION --



    //  == OPERATORS ==
    //  -- Access --
    inline T& operator[](const size_t index_) noexcept
    {
        return (_std[index_]);
    }

    inline const T& operator[](const size_t index_) const noexcept
    {
        return (_std[index_]);
    }



    //  == METHODS ==
    //  -- Getters --
    template <class T>
    inline std::vector<T>& Vector<T>::std() noexcept
    {
    }

    template <class T>
    inline const std::vector<T>& Vector<T>::std() const noexcept
    {
    }



} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_VECTOR_HPP
