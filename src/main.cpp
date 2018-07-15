/**
 *  @file   main.cpp
 *  @date   15/05/2018
 *  @author Freddy Wordingham
 *
 *  Main source file of arctk.
 *  Lists all header files fo static-analysis.
 */



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/col.hpp>
#include <arctk/col/convert.hpp>
#include <arctk/col/map.hpp>
#include <arctk/config.hpp>
#include <arctk/consts.hpp>
#include <arctk/consts/math.hpp>
#include <arctk/consts/phys.hpp>
#include <arctk/data.hpp>
#include <arctk/data/histogram.hpp>
#include <arctk/data/histogram/average.hpp>
#include <arctk/data/histogram/average1.hpp>
#include <arctk/data/histogram/dynamic.hpp>
#include <arctk/data/histogram/dynamic1.hpp>
#include <arctk/data/histogram/fixed.hpp>
#include <arctk/data/histogram/fixed1.hpp>
#include <arctk/data/histogram/fixed2.hpp>
#include <arctk/data/histogram1.hpp>
#include <arctk/data/histogram2.hpp>
#include <arctk/data/image.hpp>
#include <arctk/data/image/greyscale.hpp>
#include <arctk/data/table.hpp>
#include <arctk/debug.hpp>
#include <arctk/debug/contract.hpp>
#include <arctk/debug/invariant.hpp>
#include <arctk/debug/location.hpp>
#include <arctk/exit.hpp>
#include <arctk/exit/error.hpp>
#include <arctk/exit/success.hpp>
#include <arctk/macro.hpp>
#include <arctk/macro/utility.hpp>
#include <arctk/math.hpp>
#include <arctk/math/compare.hpp>
#include <arctk/math/container.hpp>
#include <arctk/math/convert.hpp>
#include <arctk/math/mat.hpp>
#include <arctk/math/mat2.hpp>
#include <arctk/math/mat3.hpp>
#include <arctk/math/mat4.hpp>
#include <arctk/math/pow.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/math/vec2.hpp>
#include <arctk/math/vec3.hpp>
#include <arctk/math/vec4.hpp>
#include <arctk/phys.hpp>
#include <arctk/phys/particle.hpp>
#include <arctk/random.hpp>
#include <arctk/random/distribution.hpp>
#include <arctk/random/distribution/discrete.hpp>
#include <arctk/random/distribution/uniform.hpp>
#include <arctk/random/generator.hpp>
#include <arctk/random/generator/quality.hpp>
#include <arctk/settings.hpp>
#include <arctk/settings/format.hpp>
#include <arctk/str.hpp>
#include <arctk/str/parse.hpp>
#include <arctk/str/printable.hpp>
#include <arctk/sys.hpp>
#include <arctk/sys/args.hpp>
#include <arctk/term.hpp>
#include <arctk/term/ansi.hpp>
#include <arctk/utl.hpp>
#include <arctk/utl/properties.hpp>
#include <arctk/utl/search.hpp>
#include <arctk/utl/type.hpp>



//  == MAIN ==
//  -- Function --
/**
 *  Main function of Arctk.
 *  Serves only as a main entity.
 *
 *  @return Zero upon a successful 0run.
 */
int main(const int /*unused*/, char** /*unused*/)
{
    return (0);
}
