#   == IMPORTS ==
from args import get_namespace_list


#   == FUNCTIONS ==
#   -- Formatting --
def indent(level_):
    indentation = ""
    for i in range(level_):
        indentation += " "
    return (indentation)


def get_namespaces_open():
    namespace_list = get_namespace_list()
    opener = "namespace "
    for i in range(len(namespace_list) - 1):
        opener += namespace_list[i]
        opener += "::"
    opener += namespace_list[-1]
    opener += "\n{\n"
    return (opener)


def get_namespaces_close():
    namespace_list = get_namespace_list()
    closer = "} // namespace "
    for i in range(len(namespace_list) - 1):
        closer += namespace_list[i]
        closer += "::"
    closer += namespace_list[-1]
    closer += '\n'
    return (closer)


def get_namespace_indent():
    return (indent(4 * len(get_namespace_list())))
