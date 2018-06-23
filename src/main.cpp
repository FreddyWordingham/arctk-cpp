/**
 *  @file   main.cpp
 *  @date   15/05/2018
 *  @author Freddy Wordingham
 *
 *  Main source file of arctk.
 *  Lists all header files fo static-analysis.
 */



//  == IMPORTS ==
#include <arctk/ansi.hpp>
#include <arctk/ansi/foreground.hpp>
#include <arctk/ansi/utl.hpp>
#include <arctk/col.hpp>
#include <arctk/col/conversion.hpp>
#include <arctk/col/map.hpp>
#include <arctk/config.hpp>
#include <arctk/constant.hpp>
#include <arctk/constant/math.hpp>
#include <arctk/constant/phys.hpp>
#include <arctk/data.hpp>
#include <arctk/data/bucket.hpp>
#include <arctk/data/bucket/fixed.hpp>
#include <arctk/data/image.hpp>
#include <arctk/data/image/greyscale.hpp>
#include <arctk/format.hpp>
#include <arctk/format/table.hpp>
#include <arctk/geom.hpp>
#include <arctk/geom/collision.hpp>
#include <arctk/geom/shape.hpp>
#include <arctk/geom/shape/plane.hpp>
#include <arctk/geom/shape/sphere.hpp>
#include <arctk/gui.hpp>
#include <arctk/gui/actor.hpp>
#include <arctk/gui/camera.hpp>
#include <arctk/gui/camera/birdseye.hpp>
#include <arctk/gui/camera/fly.hpp>
#include <arctk/gui/keybind.hpp>
#include <arctk/gui/keymap.hpp>
#include <arctk/gui/shader.hpp>
#include <arctk/gui/uniform.hpp>
#include <arctk/gui/window.hpp>
#include <arctk/log.hpp>
#include <arctk/log/output.hpp>
#include <arctk/log/output/error.hpp>
#include <arctk/log/output/message.hpp>
#include <arctk/log/output/progress.hpp>
#include <arctk/log/output/stopwatch.hpp>
#include <arctk/log/output/verbose.hpp>
#include <arctk/log/output/warning.hpp>
#include <arctk/log/term.hpp>
#include <arctk/math.hpp>
#include <arctk/math/comparison.hpp>
#include <arctk/math/container.hpp>
#include <arctk/math/conversion.hpp>
#include <arctk/math/power.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/math/vec2.hpp>
#include <arctk/math/vec3.hpp>
#include <arctk/math/vec4.hpp>
#include <arctk/parse.hpp>
#include <arctk/parse/string.hpp>
#include <arctk/phys.hpp>
#include <arctk/phys/particle.hpp>
#include <arctk/print.hpp>
#include <arctk/prop.hpp>
#include <arctk/prop/container.hpp>
#include <arctk/prop/multivec.hpp>
#include <arctk/rng.hpp>
#include <arctk/rng/distribution.hpp>
#include <arctk/rng/distribution/uniform.hpp>
#include <arctk/rng/generator.hpp>
#include <arctk/rng/generator/quality.hpp>
#include <arctk/search.hpp>
#include <arctk/search/container.hpp>
#include <arctk/str.hpp>
#include <arctk/str/convert.hpp>
#include <arctk/sys.hpp>
#include <arctk/sys/args.hpp>
#include <arctk/sys/file.hpp>
#include <arctk/sys/file/app.hpp>
#include <arctk/sys/file/in.hpp>
#include <arctk/sys/file/out.hpp>
#include <arctk/utl.hpp>
#include <arctk/utl/container.hpp>
#include <arctk/utl/multiarr.hpp>
#include <arctk/utl/multivec.hpp>
#include <arctk/utl/pair.hpp>
#include <arctk/utl/tuple.hpp>



//  == MAIN ==
//  -- Function --
/**
 *  Main function of Arctk.
 *  Serves only as a main entity.
 *
 *  @return Zero upon a successful run.
 */
int main(const int /*unused*/, char** /*unused*/)
{
    return (0);
}
