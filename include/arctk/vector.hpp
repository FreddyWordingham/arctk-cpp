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
        inline Vector(size_t size_) noexcept;
        inline Vector(std::initializer_list<T> init_) noexcept;


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
        inline const T&              front() const noexcept;
        inline const T&              back() const noexcept;
        inline bool                  empty() const noexcept;
        inline size_t                size() const noexcept;
        inline size_t                capacity() const noexcept;

        //  -- Access --
        inline std::vector<T>& std() noexcept;
        inline T&              front() noexcept;
        inline T&              back() noexcept;

        //  -- Capacity --
        inline void reserve(size_t size_) noexcept;
        inline void shrink_to_fit() noexcept;

        //  -- Setters --
        inline void clear() noexcept;
        inline void push_back(const T& val_) noexcept;
        inline void push_back(T&& val_) noexcept;
        inline void pop_back() noexcept;
    };



    //  == INSTANTIATION --
    //  -- Constructors --
    inline Vector<T>::Vector(const size_t size_) noexcept
      : _std(size_)
    {
    }

    inline Vector<T>::Vector(std::initializer_list<T> init_) noexcept
      : _std(init_)
    {
    }



    //  == OPERATORS ==
    //  -- Getters --
    template <class T>
    inline const T& Vector<T>::operator[](const size_t index_) const noexcept
    {
        return (_std[index_]);
    }


    //  -- Access --
    template <class T>
    inline T& Vector<T>::operator[](const size_t index_) noexcept
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

    template <class T>
    inline const T& Vector<T>::front() const noexcept
    {
        return (_std.front());
    }

    template <class T>
    inline const T& Vector<T>::back() const noexcept
    {
        return (_std.back());
    }

    template <class T>
    inline bool Vector<T>::empty() const noexcept
    {
        return (_std.emprt());
    }

    template <class T>
    inline size_t Vector<T>::size() const noexcept
    {
        return (_std.size());
    }

    template <class T>
    inline size_t Vector<T>::capacity() const noexcept
    {
        return (_std.capacity());
    }


    //  -- Access --
    template <class T>
    inline std::vector<T>& Vector<T>::std() noexcept
    {
        return (_std);
    }

    template <class T>
    inline T& Vector<T>::front() noexcept
    {
        return (_std.front());
    }

    template <class T>
    inline T& Vector<T>::back() noexcept
    {
        return (_std.back());
    }


    //  -- Capacity --
    template <class T>
    inline void Vector<T>::reserve(const size_t size_) noexcept
    {
        _std.reserve(size_);
    }

    template <class T>
    inline void Vector<T>::shrink_to_fit() noexcept
    {
        _std.shrink_to_fit();
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

    template <class T>
    inline void Vector<T>::pop_back() noexcept
    {
        _std.pop_back();
    }


} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_VECTOR_HPP
