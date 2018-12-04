/**
 *  @file   arctk/phys/photon.hpp
 *  @date   17/10/2018
 *  @author Freddy Wordingham
 *
 *  Photon particle physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_PHOTON_INL
#define ARCTK_PHYS_PHOTON_INL



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/consts/math.hpp>
#include <arctk/consts/phys.hpp>
#include <arctk/math/compare.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double power_, const double wavelength_, const double time_, const std::string& cur_mat_id_, opt::Material* mat_) noexcept
          : _pos(pos_)
          , _dir(dir_)
          , _power(power_)
          , _wavelength(wavelength_)
          , _time(time_)
          , _weight(1.0)
          , _cur_mat_id(cur_mat_id_)
          , _mat(mat_)
        {
            assert(dir_.normalised());
            assert(wavelength_ > 0.0);
            assert(power_ > 0.0);
            assert(time_ >= 0.0);
            assert(!cur_mat_id_.empty());
            assert(mat_ != nullptr);

            _driver = _mat->driver(*this);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the position of the photon.
         *
         *  @return Position of the photon.
         */
        inline const vec3& Photon::pos() const noexcept
        {
            return (_pos);
        }

        /**
         *  Get the direction of the photon.
         *
         *  @return Direction of the photon.
         */
        inline const vec3& Photon::dir() const noexcept
        {
            return (_dir);
        }

        /**
         *  Get the power of the photon.
         *
         *  @return Power of the photon.
         */
        inline double Photon::power() const noexcept
        {
            return (_power);
        }

        /**
         *  Get the wavelength of the photon.
         *
         *  @return Wavelength of the photon.
         */
        inline double Photon::wavelength() const noexcept
        {
            return (_wavelength);
        }

        /**
         *  Get the time of the photon.
         *
         *  @return Time of the photon.
         */
        inline double Photon::time() const noexcept
        {
            return (_time);
        }

        /**
         *  Get the statistical weight of the photon.
         *
         *  @return Statistical weight of the photon.
         */
        inline double Photon::weight() const noexcept
        {
            return (_weight);
        }

        inline const std::string& Photon::cur_mat_id() const noexcept
        {
            return (_cur_mat_id);
        }

        inline const std::string& Photon::prev_mat_id() const noexcept
        {
            return (_prev_mat_id.top());
        }

        inline const std::string& Photon::next_mat_id(const std::string& body_mat_id_) const noexcept
        {
            return ((body_mat_id_ == _cur_mat_id) ? _prev_mat_id.top() : body_mat_id_);
        }


        //  -- Setters --
        inline void Photon::move(const double dist_) noexcept
        {
            assert(dist_ > 0.0);

            _pos += _dir * dist_;
        }

        inline void Photon::travel(const double dist_) noexcept
        {
            assert(dist_ > 0.0);

            _driver->travel(this, dist_);
        }

        inline void Photon::set_dir(const vec3& dir_) noexcept
        {
            assert(dir_.normalised());

            _dir = dir_;
        }

        inline void Photon::rotate(const double theta_, const double phi_) noexcept
        {
            assert(_dir.normalised());

            vec3 front = _dir;
            vec3 right = math::compare::equal(std::fabs(_dir.z), 1.0) ? (_dir ^ vec3(1.0, 0.0, 0.0)) : (_dir ^ vec3(0.0, 0.0, 1.0));
            right.normalise();

            _dir.rotate(right, theta_);
            _dir.rotate(front, phi_);

            _dir.normalise();

            assert(_dir.normalised());
        }


        //  -- Materials --
        inline void Photon::enter_mat(const std::string& mat_id_) noexcept
        {
            assert(!mat_id_.empty());
            assert(mat_id_ != _cur_mat_id);

            _prev_mat_id.push(_cur_mat_id);
            _cur_mat_id = mat_id_;
        }

        inline void Photon::exit_mat(const std::string& mat_id_) noexcept
        {
            assert(!mat_id_.empty());
            assert(mat_id_ == _cur_mat_id);
            assert(!_prev_mat_id.empty());

            _cur_mat_id = _prev_mat_id.top();
            _prev_mat_id.pop();
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PHOTON_INL
