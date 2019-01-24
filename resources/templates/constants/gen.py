#   == IMPORTS ==
import sys
sys.path.append("..")
from format import indent, get_namespaces_open, get_namespaces_close, get_namespace_indent
from args import get_path, get_namespace_list, get_class_name
from env import ARCTK_DIR
from file import get_contents, write_file
xc


#   == MAIN ==
#   -- Templates --
temp_head = get_contents(
    ARCTK_DIR + "/resources/templates/constants/header.hpp.in")
temp_impl = get_contents(
    ARCTK_DIR + "/resources/templates/constants/implementation.inl.in")
temp_test = get_contents(
    ARCTK_DIR + "/resources/templates/constants/test.cpp.in")


#   -- Replacements --
temp_head = temp_head.replace("@NAMESPACES_OPEN@", get_namespaces_open())
temp_head = temp_head.replace("@NAMESPACE_INDENT@", get_namespace_indent())
temp_head = temp_head.replace("@NAMESPACES_CLOSE@", get_namespaces_close())

temp_impl = temp_impl.replace("@HEADER_PATH@", get_path() + ".hpp")

temp_test = temp_test.replace("@IMPLEMENTATION_PATH@", get_path() + ".inl")


#   -- Saving --
file_head = write_file(ARCTK_DIR + "/include/arctk/" +
                       get_path() + ".hpp", temp_head)
file_impl = write_file(ARCTK_DIR + "/include/arctk/" +
                       get_path() + ".inl", temp_impl)
file_test = write_file(ARCTK_DIR + "/testing/unit/" +
                       get_path() + ".cpp", temp_test)
