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
#include <arctk/consts/format.hpp>
#include <arctk/consts/math.hpp>
#include <arctk/consts/num.hpp>
#include <arctk/consts/phys.hpp>
#include <arctk/data.hpp>
#include <arctk/data/cube.hpp>
#include <arctk/data/cube1.hpp>
#include <arctk/data/cube2.hpp>
#include <arctk/data/cube3.hpp>
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
#include <arctk/data/image/colour.hpp>
#include <arctk/data/image/greyscale.hpp>
#include <arctk/data/json.hpp>
#include <arctk/data/table.hpp>
#include <arctk/debug.hpp>
#include <arctk/debug/contract.hpp>
#include <arctk/debug/invariant.hpp>
#include <arctk/debug/location.hpp>
#include <arctk/equip.hpp>
#include <arctk/equip/entity.hpp>
#include <arctk/equip/entity/light.hpp>
#include <arctk/equip/entity/mirror.hpp>
#include <arctk/exit.hpp>
#include <arctk/exit/error.hpp>
#include <arctk/exit/success.hpp>
#include <arctk/geom.hpp>
#include <arctk/geom/collision.hpp>
#include <arctk/geom/shape.hpp>
#include <arctk/geom/shape/box.hpp>
#include <arctk/geom/shape/mesh.hpp>
#include <arctk/geom/shape/triangle.hpp>
#include <arctk/gui.hpp>
#include <arctk/gui/actor.hpp>
#include <arctk/gui/camera.hpp>
#include <arctk/gui/camera/fly.hpp>
#include <arctk/gui/camera/orbit.hpp>
#include <arctk/gui/keybind.hpp>
#include <arctk/gui/keymap.hpp>
#include <arctk/gui/lens.hpp>
#include <arctk/gui/lens/orthographic.hpp>
#include <arctk/gui/lens/perspective.hpp>
#include <arctk/gui/point.hpp>
#include <arctk/gui/shader.hpp>
#include <arctk/gui/shader/ambient.hpp>
#include <arctk/gui/shader/diffuse.hpp>
#include <arctk/gui/shader/normal.hpp>
#include <arctk/gui/shader/ray.hpp>
#include <arctk/gui/shader/skybox.hpp>
#include <arctk/gui/shader/specular.hpp>
#include <arctk/gui/window.hpp>
#include <arctk/index.hpp>
#include <arctk/index/col.hpp>
#include <arctk/index/dim.hpp>
#include <arctk/index/rotate.hpp>
#include <arctk/index/vertex.hpp>
#include <arctk/io.hpp>
#include <arctk/io/file.hpp>
#include <arctk/io/format.hpp>
#include <arctk/io/input.hpp>
#include <arctk/io/output.hpp>
#include <arctk/macro.hpp>
#include <arctk/macro/utility.hpp>
#include <arctk/math.hpp>
#include <arctk/math/compare.hpp>
#include <arctk/math/container.hpp>
#include <arctk/math/convert.hpp>
#include <arctk/math/formula.hpp>
#include <arctk/math/formula/constant.hpp>
#include <arctk/math/formula/linear.hpp>
#include <arctk/math/formula/polynomial.hpp>
#include <arctk/math/geom.hpp>
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
#include <arctk/phys/cell.hpp>
#include <arctk/phys/mat.hpp>
#include <arctk/phys/mat/dumb.hpp>
#include <arctk/phys/optics.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/phys/sop.hpp>
#include <arctk/phys/sop/dumb.hpp>
#include <arctk/random.hpp>
#include <arctk/random/distribution.hpp>
#include <arctk/random/distribution/constant.hpp>
#include <arctk/random/distribution/discrete.hpp>
#include <arctk/random/distribution/linear.hpp>
#include <arctk/random/generator.hpp>
#include <arctk/random/generator/quality.hpp>
#include <arctk/scene.hpp>
#include <arctk/scene/domain.hpp>
#include <arctk/sys.hpp>
#include <arctk/sys/args.hpp>
#include <arctk/sys/balancer.hpp>
#include <arctk/term.hpp>
#include <arctk/term/ansi.hpp>
#include <arctk/tree.hpp>
#include <arctk/tree/node.hpp>
#include <arctk/tree/node/branch.hpp>
#include <arctk/tree/node/leaf.hpp>
#include <arctk/tree/root.hpp>
#include <arctk/utl.hpp>
#include <arctk/utl/manip.hpp>
#include <arctk/utl/properties.hpp>
#include <arctk/utl/search.hpp>
#include <arctk/utl/stream.hpp>
#include <arctk/utl/tag.hpp>
#include <arctk/utl/type.hpp>



//  == MAIN ==
//  -- Function --
/**
 *  Main function of Arctk.
 *  Serves only as a main entity.
 *
 *  @return Zero upon a successful 0run.
 */
int main(const int /*unused*/, const char** /*unused*/)
{
    return (0);
}
