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
#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>
#include <arctk/term.hpp>



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
            bool                                                     _updating;     //!< Updating status.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Balancer(const unsigned long int target_, const size_t num_threads_, const unsigned int update_delta_ = 1000) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline bool finished() const noexcept;

            //  -- Setters --
            inline void kill() noexcept;

            //  -- Updating --
            inline bool tick(size_t thread_index_) noexcept;
            inline bool update() noexcept;

          private:
            //  -- Printing --
            inline void print_info(const unsigned long int total_) const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a balancer to reach a given target with a given number of threads and update delta.
         *
         *  @param  target_         Target to reach.
         *  @param  num_threads_    Number of threads to track.
         *  @param  update_delta_   Update time delta in milliseconds.
         *
         *  @pre    target_ must be positive.
         *  @pre    num_threads_ must be positive.
         *  @pre    update_delta_ must be positive.
         */
        inline Balancer::Balancer(const unsigned long int target_, const size_t num_threads_, const unsigned int update_delta_) noexcept
          : _finished(false)
          , _target(target_)
          , _counts(num_threads_)
          , _update_delta(update_delta_)
          , _start_time(std::chrono::system_clock::now())
          , _updating(false)
        {
            PRE(target_ > 0);
            PRE(num_threads_ > 0);
            PRE(update_delta_ > 0);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Query if the balancer is finished with.
         *
         *  @return Finished status.
         */
        inline bool Balancer::finished() const noexcept
        {
            return (_finished);
        }


        //  -- Setters --
        /**
         *  Kill the balancer.
         *  Set finished status to true.
         *  Next (final) update loop will still occur.
         *
         *  @pre    _finished must be false.
         */
        inline void Balancer::kill() noexcept
        {
            PRE(!_finished);

            _finished = true;
        }


        //  -- Updating --
        /**
         *  Tick one thread of the balancer if the balancer is not finished.
         *
         *  @param  thread_index_   Index of the thread to tick.
         *
         *  @pre    thread_index_ must be less than the size of _counts.
         *
         *  @return Balancer finished status.
         */
        inline bool Balancer::tick(const size_t thread_index_) noexcept
        {
            PRE(thread_index_ < _counts.size());

            if (!_finished)
            {
                ++_counts[thread_index_];
            }

            return (!_finished);
        }

        /**
         *  Update the status of the balancer.
         *
         *
         *
         *  @return True if the balancer completed. False if the balancer was killed pre-maturely.
         */
        inline bool Balancer::update() noexcept
        {
            if (_updating)
            {
                std::cerr << "Unable to start update loop.\n"
                          << "Only one update loop may be active at once.\n";

                std::exit();
            }

            _updating = true;

            while (!_finished)
            {
                unsigned long int total = math::container::sum(_counts);
                if (total >= _target)
                {
                    _finished = true;

                    std::cout << "Target reached   : " << total << "/" << _target << '\n';
                    std::cout << "Time taken       : " << str::format::time((std::chrono::system_clock::now() - _start_time).count() / 1000000) << '\n';

                    _updating = false;

                    return (true);
                }

                print_info(total);

                std::this_thread::sleep_for(std::chrono::milliseconds(_update_delta));
            }

            std::cout << "Target aborted   : " << std::setw(12) << math::container::sum(_counts) << "/" << _target << '\n';

            _updating = false;

            return (false);
        }


        //  -- Printing --
        inline void Balancer::print_info(const unsigned long int total_) const noexcept
        {
            const double   frac         = static_cast<double>(total_) / static_cast<double>(_target);
            const long int elapsed_time = (std::chrono::system_clock::now() - _start_time).count() / 1000000;

            std::cout << "\033[2J" << '[' << str::format::bar(78, frac) << "]\n\n"
                      << "Percent complete : " << (frac * 100.0) << "%\n"
                      << "Current/target   : " << total_ << "/" << _target << '\n'
                      << "Ave rate (/s)    : " << (static_cast<double>(total_) / static_cast<double>(elapsed_time)) << '\n'
                      << "Elapsed time     : " << str::format::time(elapsed_time) << '\n'
                      << "Estimated time   : " << str::format::time(static_cast<long int>(elapsed_time / frac) - elapsed_time) << '\n';

            const double max = std::max(1.0, static_cast<double>(*std::max_element(_counts.begin(), _counts.end())));
            for (size_t i = 0; i < _counts.size(); ++i)
            {
                if ((i % 4) == 0)
                {
                    std::cout << '\n';
                }
                else
                {
                    std::cout << "    ";
                }

                const double winner = std::min(1.0, _counts[i] / max);
                std::cout << std::setw(4) << i << " [";

                if (winner > 0.9)
                {
                    std::cout << term::ansi::FG_GREEN;
                }
                else if (winner > 0.75)
                {
                    std::cout << term::ansi::FG_YELLOW;
                }
                else
                {
                    std::cout << term::ansi::FG_RED;
                }
                std::cout << str::format::bar(10, winner) << term::ansi::RESET << "]";
            }
            std::cout << '\n';
        }



    } // namespace sys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SYS_BALANCE_HPP
