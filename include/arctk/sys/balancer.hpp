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
#include <thread>

//  -- Arctk --
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


        //  -- Setters --
        inline void Balancer::kill() noexcept
        {
            _finished = true;
        }


        //  -- Updating --
        inline bool Balancer::tick(const size_t thread_index_) noexcept
        {
            if (!_finished)
            {
                ++_counts[thread_index_];
            }

            return (!_finished);
        }

        inline bool Balancer::update() noexcept
        {
            while (!_finished)
            {
                unsigned long int total = 0;
                for (size_t i = 0; i < _counts.size(); ++i)
                {
                    total += _counts[i];
                }

                const double frac = static_cast<double>(total) / static_cast<double>(_target);

                if (frac >= 1.0)
                {
                    _finished = true;

                    std::cout << "Target reached: " << std::setw(12) << total << "/" << _target << '\n';

                    return (true);
                }

                const long int elapsed_time = (std::chrono::system_clock::now() - _start_time).count() / 1000000;
                //                std::cout << "\033[2J" << std::fixed << std::setw(6) << std::setprecision(2) << (frac * 100.0) << "%\t" << std::setw(12) << total << "/" << _target << "\tETC:\t"
                //                          << str::format::time(static_cast<long int>(elapsed_time / frac) - elapsed_time) << '\n';

                std::cout << "\033[2J"
                          << "Percent complete : " << (frac * 100.0) << "%\n"
                          << "Current/target   : " << total << "/" << _target << '\n'
                          << "Ave rate (/s)    : " << (static_cast<double>(total) / static_cast<double>(elapsed_time)) << '\n'
                          << "Estimated time   : " << str::format::time(static_cast<long int>(elapsed_time / frac) - elapsed_time) << '\n'
                          << '[' << str::format::bar(78, frac) << ']';

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

                    const double winner = _counts[i] / max;
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

                std::this_thread::sleep_for(std::chrono::milliseconds(_update_delta));
            }

            unsigned long int total = 0;
            for (size_t i = 0; i < _counts.size(); ++i)
            {
                total += _counts[i];
            }

            std::cout << "Target aborted: " << std::setw(12) << total << "/" << _target << '\n';

            return (false);
        }



    } // namespace sys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SYS_BALANCE_HPP
