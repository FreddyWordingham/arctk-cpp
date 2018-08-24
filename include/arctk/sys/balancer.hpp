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
            std::vector<unsigned long int> _counts;   //!< Count of loops made by each thread.

            //  -- Timing --
            const unsigned int                                       _update_delta; //!< Minimum number of milliseconds required to pass before balancing.
            const std::chrono::time_point<std::chrono::system_clock> _start_time;   //!< Time of construction.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --

            //  -- Initialisation --


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --

        //  -- Initialisation --



        //  == METHODS ==



    } // namespace sys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SYS_BALANCE_HPP
