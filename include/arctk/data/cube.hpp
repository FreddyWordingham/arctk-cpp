/**
 *  @file   arctk/data/cube.hpp
 *  @date   11/09/2018
 *  @author Freddy Wordingham
 *
 *  Data cube class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_CUBE_HPP
#define ARCTK_DATA_CUBE_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CONSTANTS ==
        //  -- Naming --
        template <typename T>
        const char* const VTK_TYPENAME = "UNKNOWN_TYPE"; //!< String denoting unknown data type used by the vtk file format.
        template <>
        const char* const VTK_TYPENAME<int> = "int"; //!< String denoting integer data type used by the vtk file format.
        template <>
        const char* const VTK_TYPENAME<char> = "char"; //!< String denoting character data type used by the vtk file format.
        template <>
        const char* const VTK_TYPENAME<float> = "float"; //!< String denoting floating point data type used by the vtk file format.
        template <>
        const char* const VTK_TYPENAME<double> = "double"; //!< String denoting double-precision floating point data type used by the vtk file format.



        //  == CLASS ==
        /**
         *  Data cube class.
         *
         *  @tparam N   Dimensionality of the histogram.
         *  @tparam A   Types stored in data columns.
         */
        template <size_t N, typename... A>
        class Cube
        {
        };



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE_HPP
