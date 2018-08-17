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
#include <include/arctk/col.hpp>
#include <include/arctk/col/convert.hpp>
#include <include/arctk/col/map.hpp>
#include <include/arctk/config.hpp>
#include <include/arctk/consts.hpp>
#include <include/arctk/consts/math.hpp>
#include <include/arctk/consts/phys.hpp>
#include <include/arctk/data.hpp>
#include <include/arctk/data/histogram.hpp>
#include <include/arctk/data/histogram/average.hpp>
#include <include/arctk/data/histogram/average1.hpp>
#include <include/arctk/data/histogram/dynamic.hpp>
#include <include/arctk/data/histogram/dynamic1.hpp>
#include <include/arctk/data/histogram/fixed.hpp>
#include <include/arctk/data/histogram/fixed1.hpp>
#include <include/arctk/data/histogram/fixed2.hpp>
#include <include/arctk/data/histogram1.hpp>
#include <include/arctk/data/histogram2.hpp>
#include <include/arctk/data/image.hpp>
#include <include/arctk/data/image/greyscale.hpp>
#include <include/arctk/data/table.hpp>
#include <include/arctk/debug.hpp>
#include <include/arctk/debug/contract.hpp>
#include <include/arctk/debug/invariant.hpp>
#include <include/arctk/debug/location.hpp>
#include <include/arctk/exit.hpp>
#include <include/arctk/exit/error.hpp>
#include <include/arctk/exit/success.hpp>
#include <include/arctk/geom.hpp>
#include <include/arctk/geom/shape.hpp>
#include <include/arctk/geom/shape/aabb.hpp>
#include <include/arctk/geom/shape/mesh.hpp>
#include <include/arctk/geom/shape/plane.hpp>
#include <include/arctk/geom/shape/sphere.hpp>
#include <include/arctk/geom/shape/triangle.hpp>
#include <include/arctk/gui.hpp>
#include <include/arctk/gui/actor.hpp>
#include <include/arctk/gui/camera.hpp>
#include <include/arctk/gui/camera/fly.hpp>
#include <include/arctk/gui/camera/orbit.hpp>
#include <include/arctk/gui/keybind.hpp>
#include <include/arctk/gui/keymap.hpp>
#include <include/arctk/gui/lens.hpp>
#include <include/arctk/gui/lens/orthographic.hpp>
#include <include/arctk/gui/lens/perspective.hpp>
#include <include/arctk/gui/point.hpp>
#include <include/arctk/gui/shader.hpp>
#include <include/arctk/gui/shader/ambient.hpp>
#include <include/arctk/gui/shader/diffuse.hpp>
#include <include/arctk/gui/shader/normal.hpp>
#include <include/arctk/gui/shader/ray.hpp>
#include <include/arctk/gui/shader/skybox.hpp>
#include <include/arctk/gui/shader/specular.hpp>
#include <include/arctk/gui/window.hpp>
#include <include/arctk/index.hpp>
#include <include/arctk/index/col.hpp>
#include <include/arctk/index/dim.hpp>
#include <include/arctk/index/vertex.hpp>
#include <include/arctk/macro.hpp>
#include <include/arctk/macro/utility.hpp>
#include <include/arctk/math.hpp>
#include <include/arctk/math/compare.hpp>
#include <include/arctk/math/container.hpp>
#include <include/arctk/math/convert.hpp>
#include <include/arctk/math/formula.hpp>
#include <include/arctk/math/formula/constant.hpp>
#include <include/arctk/math/formula/linear.hpp>
#include <include/arctk/math/formula/polynomial.hpp>
#include <include/arctk/math/geom.hpp>
#include <include/arctk/math/mat.hpp>
#include <include/arctk/math/mat2.hpp>
#include <include/arctk/math/mat3.hpp>
#include <include/arctk/math/mat4.hpp>
#include <include/arctk/math/pow.hpp>
#include <include/arctk/math/vec.hpp>
#include <include/arctk/math/vec2.hpp>
#include <include/arctk/math/vec3.hpp>
#include <include/arctk/math/vec4.hpp>
#include <include/arctk/phys.hpp>
#include <include/arctk/phys/material.hpp>
#include <include/arctk/phys/material/basic.hpp>
#include <include/arctk/phys/material/fluorescent.hpp>
#include <include/arctk/phys/optical.hpp>
#include <include/arctk/phys/particle.hpp>
#include <include/arctk/phys/particle/photon.hpp>
#include <include/arctk/random.hpp>
#include <include/arctk/random/distribution.hpp>
#include <include/arctk/random/distribution/col.hpp>
#include <include/arctk/random/distribution/constant.hpp>
#include <include/arctk/random/distribution/discrete.hpp>
#include <include/arctk/random/distribution/gaussian.hpp>
#include <include/arctk/random/distribution/henyey_greenstein.hpp>
#include <include/arctk/random/distribution/isotropic.hpp>
#include <include/arctk/random/distribution/linear.hpp>
#include <include/arctk/random/distribution/normal.hpp>
#include <include/arctk/random/distribution/uniform.hpp>
#include <include/arctk/random/generator.hpp>
#include <include/arctk/random/generator/quality.hpp>
#include <include/arctk/settings.hpp>
#include <include/arctk/settings/format.hpp>
#include <include/arctk/str.hpp>
#include <include/arctk/str/parse.hpp>
#include <include/arctk/str/printable.hpp>
#include <include/arctk/sys.hpp>
#include <include/arctk/sys/args.hpp>
#include <include/arctk/term.hpp>
#include <include/arctk/term/ansi.hpp>
#include <include/arctk/utl.hpp>
#include <include/arctk/utl/properties.hpp>
#include <include/arctk/utl/search.hpp>
#include <include/arctk/utl/stream.hpp>
#include <include/arctk/utl/type.hpp>



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
