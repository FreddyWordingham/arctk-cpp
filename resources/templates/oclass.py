#   == IMPORTS ==
import os
import sys


#   == FUNCTIONS ==
def create_file(path_):
    if os.path.isfile(path_):
        print("Error! File:", path_, "already exists.")
        exit()
    if not os.path.exists(os.path.dirname(path_)):
        os.makedirs(os.path.dirname(path_))
    file = open(path_, "w")
    return (file)


def indent(file, depth_, str_):
    for i in range(depth_):
        file.write(" ")
    file.write(str_)


#   == MAIN ==
#   -- Environment Variables --
try:
    ARCTK_DIR = os.environ["ARCTK_DIR"]
except KeyError:
    print("Please set the environment variable ARCTK_DIR")
    exit()


#   -- Paths --
path_list = sys.argv
path_list.pop(0)
for i in range(len(path_list)):
    path_list[i] = path_list[i].lower()

if path_list[0] == "arc":
    path_list.pop(0)

if len(path_list) < 2:
    print("Error! Not enough namespaces.")
    exit()


path = ""
for i in path_list:
    path += "/" + i

path_hpp = ARCTK_DIR + "/include/arctk" + path + ".hpp"
path_inl = ARCTK_DIR + "/include/arctk" + path + ".inl"
path_cpp = ARCTK_DIR + "/testing/unit" + path + ".cpp"


#   -- Names --
name_class = path_list[-1].title()


#   -- FILES --
file_hpp = create_file(path_hpp)
file_inl = create_file(path_inl)
file_cpp = create_file(path_cpp)


#   -- Namespace --
namespace_list = ["arc"]
for i in range(len(path_list)):
    if (i != (len(path_list) - 1)):
        namespace_list.append(path_list[i])


#   -- Header --
file_hpp.write("//  == GUARD ==\n")
file_hpp.write("#pragma once\n\n\n\n")
file_hpp.write("//  == IMPORTS ==\n")
file_hpp.write("//  -- Arc --\n\n\n\n")
file_hpp.write("//  == NAMESPACE ==\n")
for i in range(len(namespace_list)):
    indent(file_hpp, 4 * i, "namespace " + namespace_list[i] + "\n")
    indent(file_hpp, 4 * i, "{\n")
file_hpp.write("\n\n\n")
indent(file_hpp, 4 * len(namespace_list), "//  == CLASS ==\n")
indent(file_hpp, 4 * len(namespace_list), "class " + name_class + "\n")
indent(file_hpp, 4 * len(namespace_list), "{\n")
indent(file_hpp, 4 * (len(namespace_list) + 1), "//  == FIELDS ==\n")
indent(file_hpp, (4 * (len(namespace_list) + 1)) - 2, "private:\n\n\n")
indent(file_hpp, 4 * (len(namespace_list) + 1), "//  == INSTANTIATION ==\n")
indent(file_hpp, (4 * (len(namespace_list) + 1)) - 2, "public:\n")
indent(file_hpp, 4 * (len(namespace_list) + 1),
       "//  -- Constructors --\n\n\n")
indent(file_hpp, 4 * (len(namespace_list) + 1), "//  == OPERATORS ==\n")
indent(file_hpp, (4 * (len(namespace_list) + 1)) - 2, "public:\n\n\n")
indent(file_hpp, 4 * (len(namespace_list) + 1), "//  == METHODS ==\n")
indent(file_hpp, 4 * (len(namespace_list) + 1), "//  -- Getters --\n")
indent(file_hpp, (4 * (len(namespace_list) + 1)) - 2, "public:\n")
indent(file_hpp, 4 * len(namespace_list), "};\n\n\n\n")
for i in range(len(namespace_list) - 1, -1, -1):
    indent(file_hpp, 4 * i, "} // namespace " + namespace_list[i] + "\n")


#   -- Implementation --
file_inl.write("//  == GUARD ==\n")
file_inl.write("#pragma once\n\n\n\n")
file_inl.write("//  == DECLARATIONS ==\n")
file_inl.write("//  -- Arc --\n")
file_inl.write("#include <arctk" + path + ".hpp>\n\n\n\n")
file_inl.write("//  == NAMESPACE ==\n")
for i in range(len(namespace_list)):
    indent(file_inl, 4 * i, "namespace " + namespace_list[i] + "\n")
    indent(file_inl, 4 * i, "{\n")
file_inl.write("\n\n\n")
indent(file_inl, 4 * (len(namespace_list) + 1), "//  == FIELDS ==\n\n\n\n")
indent(file_inl, 4 * (len(namespace_list) + 1), "//  == INSTANTIATION ==\n")
indent(file_inl, 4 * (len(namespace_list) + 1),
       "//  -- Constructors --\n\n\n\n")
indent(file_inl, 4 * (len(namespace_list) + 1), "//  == OPERATORS ==\n\n\n\n")
indent(file_inl, 4 * (len(namespace_list) + 1), "//  == METHODS ==\n")
indent(file_inl, 4 * (len(namespace_list) + 1), "//  -- Getters --\n\n\n\n")
for i in range(len(namespace_list) - 1, -1, -1):
    indent(file_inl, 4 * i, "} // namespace " + namespace_list[i] + "\n")


#   -- Source --
file_cpp.write("//  == IMPORTS ==\n")
file_cpp.write("//  -- Arc --\n")
file_cpp.write("#include <arctk" + path + ".inl>\n")
file_cpp.write("//  -- Std --\n")
file_cpp.write("#include <cassert>\n\n\n\n")
file_cpp.write("//  == NAMESPACE ==\n")
file_cpp.write("namespace arc\n")
file_cpp.write("{\n")
file_cpp.write("    namespace test\n")
file_cpp.write("    {\n\n\n\n")
file_cpp.write("        //  == FUNCTION PROTOTYPES ==\n")
file_cpp.write("        //  -- Tests --\n\n\n\n")
file_cpp.write("    } // namespace test\n")
file_cpp.write("} // namespace arc\n\n\n\n")
file_cpp.write("//  == MAIN ==\n")
file_cpp.write("int main()\n")
file_cpp.write("{\n")
file_cpp.write("    return (0);\n")
file_cpp.write("}\n\n\n\n")
file_cpp.write("//  == NAMESPACE ==\n")
file_cpp.write("namespace arc\n")
file_cpp.write("{\n")
file_cpp.write("    namespace test\n")
file_cpp.write("    {\n\n\n\n")
file_cpp.write("        //  == FUNCTIONS ==\n")
file_cpp.write("        //  -- Tests --\n\n\n\n")
file_cpp.write("    } // namespace test\n")
file_cpp.write("} // namespace arc\n\n\n\n")
