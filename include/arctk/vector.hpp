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
        //  -- Getters --
        inline const T& operator[](size_t index_) const noexcept;

        //  -- Access --
        inline T& operator[](size_t index_) noexcept;


        //  == METHODS ==
      public:
        //  -- Getters --
        inline const std::vector<T>& std() const noexcept;

        //  -- Access --
        inline std::vector<T>& std() noexcept;

        //  -- Setters --
        inline void clear() noexcept;
        inline void push_back(const T& val_) noexcept;
        inline void push_back(T&& val_) noexcept;
    };



    //  == INSTANTIATION --



    //  == OPERATORS ==
    //  -- Getters --
    inline const T& operator[](const size_t index_) const noexcept
    {
        return (_std[index_]);
    }


    //  -- Access --
    inline T& operator[](const size_t index_) noexcept
    {
        return (_std[index_]);
    }



    //  == METHODS ==
    //  -- Getters --
    template <class T>
    inline const std::vector<T>& Vector<T>::std() const noexcept
    {
        return (_std);
    }


    //  -- Access --
    template <class T>
    inline std::vector<T>& Vector<T>::std() noexcept
    {
        return (_std);
    }


    //  -- Setters --
    template <class T>
    inline void Vector<T>::clear() noexcept
    {
        _std.clear();
    }

    template <class T>
    inline void Vector<T>::push_back(const T& val_) noexcept
    {
        _std.push_back(val_);
    }

    template <class T>
    inline void Vector<T>::push_back(T&& val_) noexcept
    {
        _std.push_back(val_);
    }



} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_VECTOR_HPP
