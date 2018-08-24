/**
 *  @file   arctk/sys/balancer.hpp
 *  @date   24/08/2018
 *  @author Freddy Wordingham
 *
 *  Thread balancer class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_BALANCE_HPP
#define ARCTK_SYS_BALANCE_HPP



//  == IMPORTS ==
//  -- Std --
#include <chrono>
#include <mutex>
#include <thread>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace sys //! system namespace
    {



        //  == CLASS ==
        /**
         *  Thread balancing class.
         */
        class Balancer
        {
            //  == FIELDS ==
          private:
            //  -- Counts --
            bool                           _finished; //!< False until balancer is finished with.
            const unsigned long int        _target;   //!< Target number of counts to achieve.
            std::vector<unsigned long int> _counts;   //!< Count of loops made by each thread.

            //  -- Timing --
            const unsigned int                                       _update_delta; //!< Minimum number of milliseconds required to pass before balancing.
            const std::chrono::time_point<std::chrono::system_clock> _start_time;   //!< Time of construction.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Balancer(const unsigned long int target_, const size_t num_threads_, const unsigned int update_delta_ = 1000) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline bool finished() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        inline Balancer::Balancer(const unsigned long int target_, const size_t num_threads_, const unsigned int update_delta_) noexcept
          : _finished(false)
          , _target(target_)
          , _counts(num_threads_)
          , _update_delta(update_delta_)
          , _start_time(std::chrono::system_clock::now())
        {
            PRE(target_ > 0);
            PRE(num_threads_ > 0);
            PRE(update_delta_ > 0);
        }



        //  == METHODS ==
        //  -- Getters --
        inline bool Balancer::finished() const noexcept
        {
            return (_finished);
        }



    } // namespace sys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SYS_BALANCE_HPP
