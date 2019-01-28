//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/si/dimension.hpp>



//  == NAMESPACE ==
namespace arc
{
    namespace si
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>::Dimension() noexcept
          : _mag{0.0}
        {
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>::Dimension(const double mag_) noexcept
          : _mag{mag_}
        {
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>::Dimension() noexcept
          : _mag{0.0}
        {
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>::Dimension(const double mag_) noexcept
          : _mag{mag_}
        {
        }



        //  == OPERATORS ==
        //  -- Conversion --
        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator double() const noexcept
        {
            return (_mag);
        }


        //  -- Assignment --
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator+=(const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
        {
            _mag += rhs_.mag();

            return (*this);
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator-=(const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
        {
            _mag -= rhs_.mag();

            return (*this);
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator*=(const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
        {
            _mag *= rhs_.mag();

            return (*this);
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator/=(const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
        {
            _mag /= rhs_.mag();

            return (*this);
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator+=(const Dimension& rhs_) noexcept
        {
            _mag += rhs_.mag();

            return (*this);
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator-=(const Dimension& rhs_) noexcept
        {
            _mag -= rhs_.mag();

            return (*this);
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator*=(const Dimension& rhs_) noexcept
        {
            _mag *= rhs_.mag();

            return (*this);
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator/=(const Dimension& rhs_) noexcept
        {
            _mag /= rhs_.mag();

            return (*this);
        }


        //  -- Increment / Decrement --
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator++() noexcept
        {
            ++_mag;

            return (*this);
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator--() noexcept
        {
            --_mag;

            return (*this);
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator++() noexcept
        {
            ++_mag;

            return (*this);
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator--() noexcept
        {
            --_mag;

            return (*this);
        }



        //  == METHODS ==
        //  -- Getters --
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline double Dimension<M, L, T, K, C, I, N, A>::mag() const noexcept
        {
            return (_mag);
        }

        constexpr inline double Dimension<0, 0, 0, 0, 0, 0, 0, 0>::mag() const noexcept
        {
            return (_mag);
        }



    } // namespace si



    //  == OPERATORS ==
    //  -- Increment / Decrement --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline const si::Dimension<M, L, T, K, C, I, N, A> operator++(si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const int) noexcept
    {
        si::Dimension<M, L, T, K, C, I, N, A> unit{lhs_.mag()};

        ++lhs_;

        return (unit);
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline const si::Dimension<M, L, T, K, C, I, N, A> operator--(si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const int) noexcept
    {
        si::Dimension<M, L, T, K, C, I, N, A> unit{lhs_.mag()};

        --lhs_;

        return (unit);
    }


    //  -- Arithmetic --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator+(const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{+rhs_.mag()});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator-(const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{-rhs_.mag()});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator+(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{lhs_.mag() + rhs_.mag()});
    }

    constexpr inline double operator+(const si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>& lhs_, const double rhs_) noexcept
    {
        return (si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>{lhs_.mag() + rhs_});
    }

    constexpr inline double operator+(const double lhs_, const si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>& rhs_) noexcept
    {
        return (si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>{lhs_ + rhs_.mag()});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator-(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{lhs_.mag() - rhs_.mag()});
    }

    constexpr inline double operator-(const si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>& lhs_, const double rhs_) noexcept
    {
        return (si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>{lhs_.mag() - rhs_});
    }

    constexpr inline double operator-(const double lhs_, const si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>& rhs_) noexcept
    {
        return (si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>{lhs_ - rhs_.mag()});
    }

    template <int ML, int LL, int TL, int KL, int CL, int IL, int NL, int AL, int MR, int LR, int TR, int KR, int CR, int IR, int NR, int AR>
    constexpr inline si::Dimension<ML + MR, LL + LR, TL + TR, KL + KR, CL + CR, IL + IR, NL + NR, AL + AR> operator*(const si::Dimension<ML, LL, TL, KL, CL, IL, NL, AL>& lhs_, const si::Dimension<MR, LR, TR, KR, CR, IR, NR, AR>& rhs_) noexcept
    {
        return (si::Dimension<ML + MR, LL + LR, TL + TR, KL + KR, CL + CR, IL + IR, NL + NR, AL + AR>{lhs_.mag() * rhs_.mag()});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator*(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const double rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{lhs_.mag() * rhs_});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator*(const double lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{lhs_ * rhs_.mag()});
    }

    template <int ML, int LL, int TL, int KL, int CL, int IL, int NL, int AL, int MR, int LR, int TR, int KR, int CR, int IR, int NR, int AR>
    constexpr inline si::Dimension<ML - MR, LL - LR, TL - TR, KL - KR, CL - CR, IL - IR, NL - NR, AL - AR> operator/(const si::Dimension<ML, LL, TL, KL, CL, IL, NL, AL>& lhs_, const si::Dimension<MR, LR, TR, KR, CR, IR, NR, AR>& rhs_) noexcept
    {
        return (si::Dimension<ML - MR, LL - LR, TL - TR, KL - KR, CL - CR, IL - IR, NL - NR, AL - AR>{lhs_.mag() / rhs_.mag()});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator/(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const double rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{lhs_.mag() / rhs_});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<-M, -L, -T, -K, -C, -I, -N, -A> operator/(const double lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<-M, -L, -T, -K, -C, -I, -N, -A>{lhs_ / rhs_.mag()});
    }


    //  -- Comparison --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator==(const Dimension<M, L, T, K, C, I, N, A>& lhs_, const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (std::abs(lhs_.mag() - rhs_.mag()) <= (std::abs(lhs_.mag()) < std::abs(rhs_.mag()) ? std::abs(rhs_.mag()) : std::abs(lhs_.mag())) * std::numeric_limits<Real>::epsilon());
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator!=(const Dimension<M, L, T, K, C, I, N, A>& lhs_, const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (!(lhs_ == rhs_));
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator<(const Dimension<M, L, T, K, C, I, N, A>& lhs_, const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (lhs_.mag() < rhs_.mag());
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator>(const Dimension<M, L, T, K, C, I, N, A>& lhs_, const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (lhs_.mag() > rhs_.mag());
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator<=(const Dimension<M, L, T, K, C, I, N, A>& lhs_, const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (lhs_.mag() <= rhs_.mag());
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator>=(const Dimension<M, L, T, K, C, I, N, A>& lhs_, const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (lhs_.mag() >= rhs_.mag());
    }



} // namespace arc
