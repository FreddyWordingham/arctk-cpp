#   == IMPORTS ==
from file import get_contents, write_file
from env import ARCTK_DIR
from args import get_path, get_namespace_list, get_class_name
from format import indent, get_namespaces_open, get_namespaces_close, get_namespace_indent


#   == MAIN ==
#   -- Templates --
temp_head = get_contents(
    ARCTK_DIR + "/resources/templates/class/header.hpp.in")
temp_impl = get_contents(
    ARCTK_DIR + "/resources/templates/class/implementation.inl.in")
temp_test = get_contents(ARCTK_DIR + "/resources/templates/class/test.cpp.in")


#   -- Replacements --
temp_head = temp_head.replace("@NAMESPACES_OPEN@", get_namespaces_open())
temp_head = temp_head.replace("@CLASS_NAME@", get_class_name())
temp_head = temp_head.replace("@NAMESPACE_INDENT@", get_namespace_indent())
temp_head = temp_head.replace("@NAMESPACES_CLOSE@", get_namespaces_close())

temp_impl = temp_impl.replace("@HEADER_PATH@", get_path() + ".hpp")
temp_impl = temp_impl.replace("@NAMESPACES_OPEN@", get_namespaces_open())
temp_impl = temp_impl.replace("@NAMESPACE_INDENT@", get_namespace_indent())
temp_impl = temp_impl.replace("@NAMESPACES_CLOSE@", get_namespaces_close())

temp_test = temp_test.replace("@IMPLEMENTATION_PATH@", get_path() + ".inl")


#   -- Saving --
file_head = write_file(ARCTK_DIR + "/include/arctk/" +
                       get_path() + ".hpp", temp_head)
file_impl = write_file(ARCTK_DIR + "/include/arctk/" +
                       get_path() + ".inl", temp_impl)
file_test = write_file(ARCTK_DIR + "/testing/unit/" +
                       get_path() + ".cpp", temp_test)
