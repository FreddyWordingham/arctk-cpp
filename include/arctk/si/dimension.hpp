//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace si
    {



        //  == CLASSES ==
        //  -- Dimension --
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        class Dimension
        {
        };



    } // namespace si



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <int ML, int LL, int TL, int KL, int CL, int IL, int NL, int AL, int MR, int LR, int TR, int KR, int CR, int IR, int NR, int AR>
    constexpr inline si::Dimension<ML, LL, TL, KL, CL, IL, NL, AL> operator+(const si::Dimension<ML, LL, TL, KL, CL, IL, NL, AL>& lhs_, const si::Dimension<MR, LR, TR, KR, CR, IR, NR, AR>& rhs_) noexcept;
    template <int ML, int LL, int TL, int KL, int CL, int IL, int NL, int AL, int MR, int LR, int TR, int KR, int CR, int IR, int NR, int AR>
    constexpr inline si::Dimension<ML, LL, TL, KL, CL, IL, NL, AL> operator-(const si::Dimension<ML, LL, TL, KL, CL, IL, NL, AL>& lhs_, const si::Dimension<MR, LR, TR, KR, CR, IR, NR, AR>& rhs_) noexcept;
    template <int ML, int LL, int TL, int KL, int CL, int IL, int NL, int AL, int MR, int LR, int TR, int KR, int CR, int IR, int NR, int AR>
    constexpr inline si::Dimension<ML + MR, LL + LR, TL + TR, KL + KR, CL + CR, IL + IR, NL + NR, AL + AR> operator*(const si::Dimension<ML, LL, TL, KL, CL, IL, NL, AL>& lhs_, const si::Dimension<MR, LR, TR, KR, CR, IR, NR, AR>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator*(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, double rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator*(double lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int ML, int LL, int TL, int KL, int CL, int IL, int NL, int AL, int MR, int LR, int TR, int KR, int CR, int IR, int NR, int AR>
    constexpr inline si::Dimension<ML - MR, LL - LR, TL - TR, KL - KR, CL - CR, IL - IR, NL - NR, AL - AR> operator/(const si::Dimension<ML, LL, TL, KL, CL, IL, NL, AL>& lhs_, const si::Dimension<MR, LR, TR, KR, CR, IR, NR, AR>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A, typename S>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator/(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, double rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A, typename S>
    constexpr inline si::Dimension<-M, -L, -T, -K, -C, -I, -N, -A> operator/(double lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;



} // namespace arc
